Hello World
===========

Introduction
------------

This is a literate tutorial describing how to write a "hello world" program in C. This tutorial has been written in literate-markdown, a convention on how to use markdown to write literate programming documents.

For more information on how to get the literate-markdown interpreter and run this program through it to extract a C program that can be compiled, please visit [the literate-markdown project on GitHub][literate].
[literate]: https://github.com/MikeCoats/literate-markdown

Breaking the problem down
-------------------------

The most important part of the canonical "hello world" program is actually saying hello. In C this is accomplished by using the `printf()` function, as shown below:

###### Say hello
```c
    printf("Hello, world!\n");
```

By default, C has a very small collection of functions available to it and `printf()` isn't actually one of them. Instead, C comes with a standard library of functions split across many files, and it is up to the programmer to include the relevant section of the standard library. In the case of `printf()` we need to include the I/O section of the standard library; this can be seen below:

###### Include I/O library
```c
#include <stdio.h>
```

All programs on a PC must have what's known as an entry point. This is the place in the code that the operating system knows to kick off the program from. In C this point is known as `main()` and when fully expressed looks like this:

###### Start the program
```c
int main(int argc, char *argv[])
{
```

There are many other ways to write this initial entry point, but this way the most complete. It will also be the form that future tutorials are based upon, so it is worth learning now.

As the saying goes, "All good things must come to an end!", and so it is with out program. You could be mean and simply stop executing by crashing back to the operating system, but it's much nicer to shutdown cleanly and let the operating system know how you got on. For that reason, we return the 0 value to the operating system as it is, by convention, the way that a program signals that it was successful in doing whatever it was programmed to do.

###### End the program
```c
    return 0;
}
```

The final part of this is to put the parts together in the correct order.

Putting the parts together
--------------------------

C mandates that we do certain things in a certain order. We must include libraries before we call functions from them and we must start the program before we can make any of the function calls. Once everything's finished, we can finally exit the program and signal our success to the operating system. Those steps are outlined below:

- Include I/O library
- Start the program
- Say hello
- End the program
