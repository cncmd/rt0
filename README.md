# rt0
A minimal C runtime for Linux i386 &amp; x86_64

## Features
* Implemented in just 98 SLOC of C89-ish code.
* Just 2 lines of GCC inline ASM for i386, or,
* Just 6 lines GCC inline ASM for x86_64 (because the SysV x86_64 ABI is register-based vs. the stack-based SysV i386 ABI)
* Small runtime providing just `argc`, `argv`, `envp`, `__environ`, `_exit`, and `syscall0/1/2/3/4/5/6`
* Small binary sizes vs. other libc's

| Binary      | Arch   | Size | Purpose                  | Compile Args                          | Source |
-------------:|:-------|-----:|:-------------------------|:--------------------------------------|:--------
| librt0.a    | i386   | 5048 | Startup code+syscall     | -Os -s -nostdlib -fomit-frame-pointer | Author |
| librt0.a    | x86_64 | 6724 | Startup code+syscall     | -Os -s -nostdlib -fomit-frame-pointer | Author |
| t/hello.exe | i386   | 1648 | Hello World\n            | -Os -s -nostdlib -fomit-frame-pointer | Author |
| t/hello.exe | x86_64 | 1752 | Hello World\n            | -Os -s -nostdlib -fomit-frame-pointer | Author |
| hello.exe   | i386   | 5532 | Hello World\n with glibc | -Os -s -fomit-frame-pointer           | Author |
| hello.exe   | x86_64 | 6240 | Hello World\n with glibc | -Os -s -fomit-frame-pointer           | Author |

See the [musl libc comparison][0] to see how other libc's fair.

## Building
Try:
* `make`
* `make librt0`
* `make install`
* `make test`
* `make runtest`

## Usage
Include `rt0/rt0.h` for `__environ`, `_exit`
Include `rt0/syscall.h` for `SYS_*`, `syscall0/1/2/3/4/5/6`
Define `main` as `int main( int, char**, char** )`
Compile your code with `-nostdlib`, e.g., `cc -c prog.c -nostdlib -o prog.o`
Link with librt0, e.g., `cc prog.o -nostdlib -lrt0 -o prog`


[0]: http://www.etalabs.net/compare_libcs.html
