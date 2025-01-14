const appTitle = "COMP 2406 Authorization Demo";

export function header(title) {
    const fullTitle = appTitle + ": " + title;
    
    return `<!DOCTYPE html>
<html>
  <head>
    <title>${fullTitle}</title>
    <link rel="stylesheet" href="/style.css">
  </head>
`
}

export function notFound(path) {
    return header("Page not found") +
        `<body>
<h1>Page not found</h1>

<p>Sorry, the requested page was not found.</p>
</body>
</html>
`
}
