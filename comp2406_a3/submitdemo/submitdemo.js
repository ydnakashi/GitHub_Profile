// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2024 Anil Somayaji
//
// submitdemo.js
// for COMP 2406 (Fall 2024), Carleton University
// 
// Initial version: November 6, 2024
//
// run with the following command:
//    deno run --allow-net --allow-read --allow-write submitdemo.js
//

import { DB } from "https://deno.land/x/sqlite/mod.ts";

const status_NOT_FOUND = 404;
const status_OK = 200;
const status_INTERNAL_SERVER_ERROR = 500;
const status_NOT_IMPLEMENTED = 501;
const status_BAD_REQUEST = 400;
const status_CONFLICT = 409;
const appTitle = "COMP 2406 Submissions Demo";
const dbFile = "submissions.db";
// const table = "tutorial7new";
const table = "assignment3";
const filePrefix = "comp2406-assign3";
const submissionName = "COMP 2406 2024F Assignment 3";
const expectedQuestionList = "1,2,3,4,5";

const db = new DB(dbFile);

db.execute(`
  CREATE TABLE IF NOT EXISTS ${table} (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    studentID INTEGER UNIQUE,
    section TEXT,
    name TEXT,
    q1 TEXT,
    q2 TEXT,
    q3 TEXT,
    q4 TEXT,
    q5 TEXT
  )
`);


function addSubmissionDB(db, table, r) {
    return db.query(`INSERT INTO ${table} ` +
                    "(studentID, section, name, q1, q2, q3, q4, q5) " +
                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
                    [r.studentID, r.section, r.name, 
                     r["1"], r["2"], r["3"], r["4"], r["5"]]);
}

function getAllSubmissionsDB(db, table) {
    var state = [];
    const query =
          db.prepareQuery(
              "SELECT id, studentID, section, name, q1, q2, q3, q4, q5 FROM " +
                  table + " ORDER BY name ASC LIMIT 50");

    for (const [id, studentID, section, name, q1, q2, q3, q4, q5]
         of query.iter()) {
        state.push({id, studentID, section, name, q1, q2, q3, q4, q5});
    }

    query.finalize();
    
    return state;
}

function analyzeSubmissionsDB(db, table) {
    var analysis = {};

    analysis.count = db.query("SELECT COUNT(*) FROM " + table);
    analysis.studentIDList =
        db.query("SELECT DISTINCT studentID FROM " + table);
    analysis.emptyAnswers = db.query(`
        SELECT 
            COUNT(*) FILTER (WHERE TRIM(q1) = '') AS empty_q1,
            COUNT(*) FILTER (WHERE TRIM(q2) = '') AS empty_q2,
            COUNT(*) FILTER (WHERE TRIM(q3) = '') AS empty_q3,
            COUNT(*) FILTER (WHERE TRIM(q4) = '') AS empty_q4,
            COUNT(*) FILTER (WHERE TRIM(q5) = '') AS empty_q5
        FROM ${table};
    `)
    
    return analysis;
}


function MIMEtype(filename) {

    const MIME_TYPES = {
        'css': 'text/css',
        'gif': 'image/gif',
        'htm': 'text/html',
        'html': 'text/html',
        'ico': 'image/x-icon',
        'jpeg': 'image/jpeg',
        'jpg': 'image/jpeg',
        'js': 'text/javascript',
        'json': 'application/json',
        'pdf': 'application/pdf',
        'png': 'image/png',
        'txt': 'text/text'
    };

    var extension = "";
    
    if (filename) {
        extension = filename.slice(filename.lastIndexOf('.')+1).toLowerCase();
    }

    return MIME_TYPES[extension] || "application/octet-stream";
};


function template_header(title) {
    const fullTitle = appTitle + ": " + title;
    
    return `<!DOCTYPE html>
<html>
  <head>
    <title>${fullTitle}</title>
    <link rel="stylesheet" href="/style.css">
  </head>
`
}

function template_notFound(path) {
    return template_header("Page not found") +
        `<body>
<h1>Page not found</h1>

<p>Sorry, the requested page was not found.</p>
</body>
</html>
`
}


function template_addRecord(obj) {
    return template_header("Submission just added") +
        `<body>
  <body>
    <h1>Submission just added</h1>
    <p>Student ID: ${obj.studentID}</p>
    <p>Name: ${obj.name}</p>
    <p>Q1: ${obj.q1}</p>
    <p>Q2: ${obj.q2}</p>
    <p>Q3: ${obj.q3}</p>
    <p>Q4: ${obj.q4}</p>
    <p>Q5: ${obj.q5}</p>
    <form method="get" action="/">
      <button type="submit">Home</button>
    </form>
  </body>
</html>
`
}


function listSubmissions() {
    var state = getAllSubmissionsDB(db, table);
    
    var response = { contentType: "application/JSON",
                     status: status_OK,
                     contents: JSON.stringify(state),
                   };

    return response;
}


async function routeGet(req) {
    const path = new URL(req.url).pathname;
    if (path === "/list") {
        return listSubmissions();
    } else if (path === "/analyze") {
        return await showAnalysis();
    }  else {
        return null;
    }
}

async function showAnalysis() {
    var analysis = analyzeSubmissionsDB(db, table);
    var studentIDList =
        '<li>' + analysis.studentIDList.join('</li> <li>') + '</li>';
    
    var analysisBody = `  <body>
  <body>
    <h1>Submissions analysis</h1>
    <p># Records: ${analysis.count}</p>
    <p># Empty Answers for Q1: ${analysis.emptyAnswers[0][0]}</p>
    <p># Empty Answers for Q2: ${analysis.emptyAnswers[0][1]}</p>
    <p># Empty Answers for Q3: ${analysis.emptyAnswers[0][2]}</p>
    <p># Empty Answers for Q4: ${analysis.emptyAnswers[0][3]}</p>
    <p># Empty Answers for Q5: ${analysis.emptyAnswers[0][4]}</p>

    <p>Student IDs:
      <ol>
       ${studentIDList}
      </ol>
    </p>

    <form method="get" action="/">
      <button type="submit">Home</button>
    </form>
  </body>
</html>`

    var contents =
        template_header("Submission analysis") + analysisBody;

    var response = { contentType: "text/html",
                     status: status_OK,
                     contents: contents,
                   };
    
    return response;
}

function checkSubmission(obj) {
    const fnPattern = filePrefix + "-[a-zA-Z0-9]+\.txt";
    const fnRexp = new RegExp(fnPattern);

    var lines = obj.content;
    var questionList = [];
    var questionString;
    var lastQuestion = null;
    var q = {};
    
    if (!fnRexp.test(obj.fn)) {
        console.log("status", "ERROR " + obj.fn +
                  " doesn't follow the pattern " + fnRexp);
        return false;
    }

    if (obj.fn === filePrefix + "-template.txt") {
        console.log("status", "ERROR " + obj.fn +
                  " has the default name, please change template to your mycarletonone username");
        return false;
    }

    if (obj.encoding !== "UNIX") {
        console.log("status", "ERROR " + obj.fn +
                  " is not a UNIX textfile, it is a "
                  + obj.encoding + " file.");
        return false;
    }
    
    if (submissionName !== lines[0]) {
        console.log("status", "ERROR " + obj.fn +
                  " doesn't start with \"" + submissionName + "\"");
        return false;
    }
    
    try {
        q.name = lines[1].match(/^Name:(.+)/m)[1].trim();
        q.studentID = lines[2].match(/^Student ID:(.+)/m)[1].trim();
        q.section = lines[3].match(/^Section:(.+)/m)[1].trim();
    } catch (error) {
        console.log("status", "ERROR " + obj.fn +
                  " has bad Name or Student ID field or Section");
        return false;
    }
    
    var questionRE = /^([0-9a-g]+)\.(.*)/;
    
    for (var i = 4; i < lines.length; i++) {
        if (typeof(lines[i]) === 'string') {
            lines[i] = lines[i].replace('\r','');
        }
        
        let m = lines[i].match(questionRE);
        if (m) {
            questionList.push(m[1]);
            q[m[1]] = m[2];
            lastQuestion = m[1];
        } else {
            if (lastQuestion !== null) {
                if ((q[lastQuestion] === '') || (q[lastQuestion] === ' ')) {
                    q[lastQuestion] = lines[i];
                } else {
                    q[lastQuestion] = q[lastQuestion] + "\n" + lines[i];
                }
            }
        }
    }

    console.log(JSON.stringify(q, null, '   '));

    questionString = questionList.toString();
    if (questionString !== expectedQuestionList) {
        console.log("status", "ERROR expected questions " +
                  expectedQuestionList + " but got questions " +
                  questionString);
        return false;
    } else {
        console.log("status", "PASSED " +
                  obj.fn + ": " + q.name + " (" + q.studentID + ")");
    }
    return q;
}

async function addSubmission(req) {
    var response, result;
    const submission = await req.json();
    const validation = checkSubmission(submission);

    if (!validation) {
        response = {
            contentType: "text/plain",
            status: status_BAD_REQUEST,
            contents: "Bad Request"
        };
        return response;
    }

    try {
        result = addSubmissionDB(db, table, validation);        
    } catch (error) {
        response = {
            contentType: "text/plain",
            status: status_CONFLICT,
            contents: "Student ID has already submitted"
        };
        return response;
    }
    
    if (result) {
        response = {
            contentType: "text/plain",
            status: status_OK,
            contents: "Got the data",
        };
    } else {
        response = {
            contentType: "text/plain",
            status: status_INTERNAL_SERVER_ERROR,
            contents: "Internal server error"
        };
    }

    return response;
}

async function routePost(req) {
    const path = new URL(req.url).pathname;    

    if (path === "/uploadSubmission") {
        return await addSubmission(req);
    } else {
        return null;
    }
}


async function route(req) {

    if (req.method === "GET") {
        return await routeGet(req);
    } else if (req.method === "POST") {
        return await routePost(req);
    } else {
        return {
            contents: "Method not implemented.",
            status: status_NOT_IMPLEMENTED,
            contentType: "text/plain"
        };
    }
}


async function fileData(path) {
    var contents, status, contentType;
    
    try {
        contents = await Deno.readFile("./static" + path);
        status = status_OK;
        contentType = MIMEtype(path);
    } catch (e) {
        contents = template_notFound(path);
        status = status_NOT_FOUND;
        contentType = "text/html";
    }
    
    return { contents, status, contentType };
}


async function handler(req) {

    var origpath = new URL(req.url).pathname;
    var path = origpath;
    var r =  await route(req);
    
    if (!r) {
        if (path === "/") {
            path = "/index.html";
        }
        r = await fileData(path);
    }

    console.log(`${r.status} ${req.method} ${r.contentType} ${origpath}`); 

    return new Response(r.contents,
                        {status: r.status,
                         headers: {
                             "content-type": r.contentType,
                         }});
}


const ac = new AbortController();

const server = Deno.serve(
    {
        signal: ac.signal,
        port: 8000,
        hostname: "0.0.0.0"
    },
    handler);

Deno.addSignalListener("SIGINT", () => {
    console.log("SIGINT received, terminating...");
    ac.abort();
});

server.finished.then(() => {
    console.log("Server terminating, closing database.")
    db.close();
});
