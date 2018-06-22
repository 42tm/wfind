wfind
=====
Look for files whose contents match the specified regular expression (regex).

## Build
```bash
make
```

## Run
```bash
./wfind [regex] [directory]
```

- regex     : The regular expression to be used to find in files
- directory : (Optional) Directory that contains the files to look up for
> If the directory is omitted, the location is set to current working directory.

## Example
(There are prepared files for this example in `example/`)

Run the following command:
```bash
./wfind '\bbooks\b' example/
```

You should see something like this as the output:
```bash
Looking up directory: "example/"
Regex: "\bbooks\b"
"example/file3"
"example/file1"
2 file(s) found. 
```
