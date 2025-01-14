// Don't change the package name below nor the name of this file.
package main

// The assignment is to implement a small simulation of a key-value-store (kvs)
// web server using goroutines. There are three kinds of goroutines, each with
// their own waitgroups (defined below).
// 1. Servers. There is exactly one of these: gateway.
// 2. Users.
// 3. Handlers. One of these is assigned to each user when they "log in".

// We explain what these all do by describing how user requests are handled.
// When a user goroutine starts up, it sends the gateway a channel and its
// user name. The gateway then starts a handler (stub below) for it. The
// user henceforth communicates only with the handler.

// Communication with the handler involves three operations: get the value
// for a key, set a key to have a value, and quit. The quit operation causes the
// handler to exit. The kvs operations must be protected with a lock.

// The kvs operations are provided, as are stubs for all the main functions and
// some skeletons showing how to build and run users. Other code is provided too.
// Be sure to look over the *entire* file before you start.

// In addition to doing the operations correctly, your program must also shut down
// gracefully. All goroutines must terminate before the main program does. There
// should be no error messages about e.g. deadlock.

// Don't underestimate this assignment. There's not much code to write, and you
// don't need to know much Go to write it. However, debugging concurrent
// programs can be a nightmare if you're not careful. If you do run into
// trouble, the best way of debugging this kind of program is logging. This file
// provides a function "log" which writes strings and other objects to the file
// "log.txt" as well as to the console.

// For ease of programming we use global variables for the wait groups, kvs, and
// some of the channels.

// Here's what you need from Go.
// - loops, if-then-else (and/or switch)
// - waitgroup operations .Done, .Add, .Wait; note that Done should be
// 	 should be in a `defer`, e.g. putting `defer wg.Done()` at the beginning
//   of the function, and Add should go right before a goroutine is launched.
// - channel send, receive and select

import (
	"fmt"
	"os"
	"sync"
)

// Pile of globals. You'll need them all. Don't add any.
var kvs map[string]string
var kvsLock = makeChan("kvsLock", 1)
var gatewayChan = makeChan("gatewayChan", 0)
var gatewayQuitChan = makeChan("gatewayQuitChan", 0)
var userWg sync.WaitGroup
var serverWg sync.WaitGroup
var handlerWg sync.WaitGroup

// The basic unit of communication. Except for kvsLock, all the channels use
// packets. There's nothing magic about what's in this definition. It's just a
// data structure that has enough fields to accommodate the needs of this
// assignment.
type packet struct {
	user    string
	channel chan packet
	cmd     string
	arg0    string
	arg1    string
	result  string
}

// Associates a name with every channel. For debugging.
var channelNames = make(map[chan packet]string)

func channelName(c chan packet) string {
	return channelNames[c]
}

// Create a channel and give it a name.
func makeChan(name string, size int) chan packet {
	c := make(chan packet, size)
	channelNames[c] = name
	return c
}

func packetString(p packet) string {
	return fmt.Sprintf("user=%s cmd=%s arg0=%s arg1=%s result=%s channel=%s", p.user, p.cmd, p.arg0, p.arg1, p.result, channelName(p.channel))
}

// Set up users with handlers.
func gateway() {
	defer serverWg.Done()
	for {
		// TODO
		select {
		case loginReq := <-gatewayChan:
			// start a new handler for the user
			handlerWg.Add(1)
			go handler(loginReq.user, loginReq.channel)
		case <-gatewayQuitChan:
			// exit the gateway loop
			handlerWg.Wait()
			return
		}
	}
}

// Used in main.
func systemInit() {
	kvs = make(map[string]string)
	logInit()
	serverWg.Add(1)
	kvsLock <- packet{}
	go gateway()
}

// Get the value for the key, locking the kvs.
func kvsGet(key string) string {
	// TODO
	lockPacket := <-kvsLock
	log("Lock acquired by kvsGet")
	value := kvs[key]
	kvsLock <- lockPacket
	log("Lock put back by kvsGet")
	return value
}

// Set the value for the key, locking the kvs.
func kvsSet(key string, value string) {
	// TODO
	lockPacket := <-kvsLock
	log("Lock acquired by kvsSet")
	kvs[key] = value
	kvsLock <- lockPacket
	log("Lock put back by kvsSet")
}

// Get a string version of the kvs, locking it.
func kvsString() string {
	// TODO: ADD LOCKING
	lockPacket := <-kvsLock
	log("Lock acquired by kvsString")
	out := "kvs contents:\n"
	for key, value := range kvs {
		out = fmt.Sprintf("%s    key: %s, value: %s\n", out, key, value)
	}
	kvsLock <- lockPacket
	log("Lock put back by kvsString")
	return out
}

// Print the kvs, locking it.
func kvsPrint() {
	print(kvsString())
}

// Receive kvs requests (set or get) from the given user and send
// back the answer. In the set case, there is no information to pass,
// but a response is still expected.
func handler(user string, userChan chan packet) {
	defer handlerWg.Done()
	for {
		// TODO
		select {
		case req := <-userChan:
			switch req.cmd {
			case "get":
				req.result = kvsGet(req.arg0)
				userChan <- req
			case "set":
				kvsSet(req.arg0, req.arg1)
				req.result = req.arg0 + ":" + req.arg1 + "Key-Val set complete."
				userChan <- req
			case "quit":
				return
			}
		}
	}
}

// send a get command to a handler
func get(user string, handlerChan chan packet, key string) string {
	// TODO
	req := packet{user: user, cmd: "get", channel: handlerChan, arg0: key}
	handlerChan <- req
	logSend(handlerChan, user, req)
	response := <-handlerChan
	logReceive(handlerChan, user, response)
	return response.result
}

// send a set command to a handler
func set(user string, handlerChan chan packet, key, value string) {
	// TODO
	req := packet{user: user, cmd: "set", channel: handlerChan, arg0: key, arg1: value}
	handlerChan <- req
	logSend(handlerChan, user, req)
	response := <-handlerChan
	logReceive(handlerChan, user, response)
}

// A user goroutine. It should 1) "log in", i.e. communicate with gateway
// to create a handler and get its channel, 2) execute actions with user
// and the handler channel as arguments, and 3) send a quit command to
// the handler.
func user(user string, actions func(string, chan packet)) {
	defer userWg.Done()
	// TODO
	// Two lines commented out to avoid compiler errors.
	myChan := makeChan("user-"+user+"-chan", 0)
	loginRequest := packet{user: user, channel: myChan}
	gatewayChan <- loginRequest
	actions(user, myChan)
	myChan <- packet{cmd: "quit"}
}

//////////////
// Logging  //
//////////////

const logFile string = "log.txt"

func log(args ...any) {
	entry := ""
	for i, arg := range args {
		if i == 0 {
			entry = fmt.Sprintf("%v", arg)
		} else {
			entry = fmt.Sprintf("%s %v", entry, arg)
		}
	}
	entry = entry + "\n"
	file, err := os.OpenFile(logFile, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Printf("Error opening file %s: %v\n", logFile, err)
		return
	}
	defer file.Close()
	_, err = file.WriteString(entry)
	if err != nil {
		fmt.Printf("Error opening file %s: %v\n", logFile, err)
		return
	}
	print(entry)
}

func logInit() {
	os.Remove(logFile)
}

func logSend(c chan packet, sender string, msg packet) {
	log("msg sent by " + sender + " to " + channelName(c) + ": " + packetString(msg))
}

func logReceive(c chan packet, recipient string, msg packet) {
	log("msg delivered to " + recipient + " from " + channelName(c) + ": " + packetString(msg))
}

// This must be the last function in the file.
// The example goroutines are quite minimal. You'll need a bit more in them
// to test your program.
func main() {
	systemInit()
	userWg.Add(1)
	go user("Bingo", func(user string, c chan packet) {
		// operations go here
		set(user, c, "a", "1")
		log("Bingo get result 0: ", get(user, c, "a"))
		set(user, c, "ab", "10")
		set(user, c, "a", "3")
		log("Bingo get result 1: ", get(user, c, "a"))
	})
	userWg.Add(1)
	go user("Bonzo", func(user string, c chan packet) {
		set(user, c, "b", "2")
		log("Bonzo get result 0: ", get(user, c, "a"))
		set(user, c, "ba", "4")
		log("Bonzo get result 1: ", get(user, c, "ba"))
	})
	userWg.Add(1)
	go user("Bongo", func(user string, c chan packet) {
		set(user, c, "c", "3")
		log("Bongo get result 0: ", get(user, c, "a"))
		set(user, c, "c", "bazola")
		log("Bongo get result 1: ", get(user, c, "ba"))
	})
	userWg.Wait()
	log(kvsString())
	gatewayQuitChan <- packet{}
	logSend(gatewayQuitChan, "main", packet{})
	serverWg.Wait()
}

// DO NOT PUT ANYTHING AFTER main. THE AUTOGRADER WILL REMOVE IT.
