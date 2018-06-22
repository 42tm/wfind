wfind
===
Search content in files recursively using regex

## Build
```bash
make
```

## Run
```bash
./wfind [regex] (directory)
```

- regex     : regex used to find in files
- directory : (Optional) look up location
> If the directory is omitted, the location is set to current working directory.

## Example
(There are prepared example files in `example/`)

Run the following command:
```bash
./wfind '\bbooks\b' example/
```
You should see the output similar to below:
```bash
$ ./wfind '\bbooks\b' example/
Cwd: "example/"
Keyword: "\bbooks\b"
"example/file1"
"example/file3"
2 file(s) found
$ 
```
