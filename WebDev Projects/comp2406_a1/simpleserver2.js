// run with the following command:
//    deno run --allow-net --allow-read simpleserver2.js
//

import { contentType } from "jsr:@std/media-types";

const status_NOT_FOUND = 404;
const status_OK = 200;
const status_METHOD_NOT_IMPLEMENTED = 501;

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
    return `<!DOCTYPE html>
<html>
  <head>
    <title>${title}</title>
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

function template_methodNotImplemented(path) {
    return template_header("Page not found") +
    `<body>
        <h1>Method not implemented</h1>
    
        <p>Sorry, the requested page was not implemented</p>
    </body>
    </html>
    `
}

async function routeOther(req) {
    const path = new URL(req.url).pathname;
    
    var contents, status, contentType; 
    contents = template_methodNotImplemented(path);
    status = status_METHOD_NOT_IMPLEMENTED;
    contentType = "text/html";
    
    return { contents, status, contentType };
}

async function route(req) {
    var path = new URL(req.url).pathname;
    if (req.method === "GET") {   
        if (path === "/") {
            path = "/index.html";
        }
        return await fileData(path);
    } else {
        return await routeOther(req);
    }
}

async function fileData(path) {
    var contents, status, content_type;
    
    try {
        contents = await Deno.readFile("./www" + path);
        status = status_OK;
        // contentType = MIMEtype(path);
        content_type = await contentType(path);
    } catch (e) {
        // contents = template_notFound(path);
        contents = await Deno.readFile("./www/pageNotFound.html");
        status = status_NOT_FOUND;
        content_type = "text/html";
    }
    
    return { contents, status, content_type };
}

async function handler(req) {

    var origpath = new URL(req.url).pathname;
    var r = await route(req);

    console.log(`${r.status} ${req.method} ${r.contentType} ${origpath}`); 

    return new Response(r.contents,
                        {status: r.status,
                         headers: {
                             "content-type": r.contentType,
                         }});
}

Deno.serve(handler);
