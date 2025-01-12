all: a1test a1

Category.o: Category.h Category.cc
	g++ -c Category.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc

Camper.o: Date.h Camper.h Camper.cc
	g++ -c Camper.cc

Campsite.o: defs.h Category.h Camper.h Campsite.h Campsite.cc
	g++ -c Campsite.cc

Campground.o: defs.h Campsite.h Category.h Campground.h Campground.cc
	g++ -c Campground.cc

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc

testMain.o: testMain.cc Category.h Tester.h Date.h Camper.h Campsite.h Campground.h
	g++ -c testMain.cc

main.o: main.cc Category.h Date.h Camper.h Campsite.h Campground.h
	g++ -c main.cc

a1test: Tester.o Campground.o Campsite.o Camper.o Date.o Category.o testMain.o
	g++ -o a1test testMain.o Tester.o Campground.o Campsite.o Camper.o Date.o Category.o

a1: Campground.o Campsite.o Camper.o Date.o Category.o main.o
	g++ -o a1 main.o Campground.o Campsite.o Camper.o Date.o Category.o

clean:
	rm -f *.o a1test
	rm -f *.o a1