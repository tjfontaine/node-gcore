## node-gcore

A small module to induce core files from inside a node process.

The more memory the process is using, the longer this will take, and for
consistency reasons the method should be synchronous.

## Usage

 * `gcore(filename)`
     - Will ***SYNCHRONOUSLY*** produce a corefile wiht the name `filename`
     - Returns `true`/`false` if it was able create a core file

```javascript
var gcore = require('gcore').gcore;
var result = gcore("corefile");
```

## Caveats

 * Currently only for Linux based platforms, but trivial to add SmartOS and
 probably others.
