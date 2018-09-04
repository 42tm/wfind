# wfind

wfind is a library providing the function to look for files
whose contents match the specified regular expression (regex).

The library is in `lib/`, and a simple program which has the same name that uses this library is `main.cpp`.

## Build

### Requirement

- C++ Version: C++ 17 (`__has_include`, `<filesystem>`)

- Tested compiler:

  - GNU C++ Compiler _5.3 or later_
  - MS Visual C++ Compiler _15.3 or later_

> Older versions of `g++` and other C++ compilers are yet to be tested, the build might fail.

> In MinGW-w64 g++ 8.1.0, due to a [bug](http://sourceforge.net/p/mingw-w64/bugs/737/), you can't compile `<filesystem>` library. It is recommended to use other version of MinGW-w64 (7.3.0) on Windows.

### Command

```bash
make
```

This will compile `main.cpp` and link `wfind.cpp`.

> By default, the GNU C++ Compiler is chosen to compile. To use specific compiler, see below.

#### GNU C++ Compiler

```bash
make gcc

make gcc-static # static linking
```

#### MS Visual C++ Compiler

```bash
make msvc

make msvc-static # static linking
```

### Clean

```bash
make clean
```

## Run

```bash
./wfind [regex] [directory]
```

- regex : The regular expression to be used to find in files
- directory : (Optional) Directory that contains the files to look up for

> If the directory is omitted, the location is set to current working directory.

## Install (GNU/Linux)

```bash
make install
```

## Example

(There are prepared files for this example in `example/`)

Run the following command:

```bash
./wfind '\bbooks\b' example/
```

You should see something like this as part of the output:

```bash
Looking up directory: "example/"
Regex: "\bbooks\b"
"example/file3"
"example/file1"
wfind: 2 file(s) found.
```

## License

This work is licensed under [The Unlicense](http://unlicense.org/), meaning it is dedicated to the Public Domain.
