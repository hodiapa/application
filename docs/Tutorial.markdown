A Tutorial:
===========

In this tutorial, I will show you how to implement a multi-threaded State Pattern using the code in this repository.

Getting Started:
----------------

I will use pmake to build the code, so I will start with the following Makefile.py file. From now on ROOT will denote
the root folder of the project. Please copy & paste the following code into ROOT/Makefile.py:

ROOT/Makefile.py:

    COLOR = True
    CC = "gcc"
    CPPC = "g++"
    AR = "ar"
    LINKER = "g++"
    COMMON_CFLAGS = ["-Wall", "-std=gnu++0x"]
    LDFLAGS = []
    
    LANGUAGE_SETTINGS = {  
        "c++" : { 
        "compiler" : CPPC,
        "headerext" : [".h"],
        "sourceext" : [".cpp"],
        },  
    }
    
    BUILD_DIR = "Build"
    
    ACTIVE_CONFIGURATION = "debug"
    CONFIGURATIONS = {
        "debug" : {
        "flags" : COMMON_CFLAGS + ["-g"],
        "buildsubdir" : "Debug",
        },
    }
    
    LIBRARY_PATHS = []
    LIBRARIES = ["pthread"]
    
    ACTIVE_MODULES = ["system", "myapp",]
    MODULES = {
      "system" : {
          "directory" : "system",
          "language" : "c++",
          "incpaths" : [],
          "defines" : [],
      },
      "myapp" : {
          "directory" : "myapp",
          "language" : "c++",
          "incpaths" : ["."],
          "defines" : [],
      },
    }
    
    APPLICATION_NAME = "app." + ACTIVE_CONFIGURATION

My module will be named 'myapp'. So let's start with a Hello World application to test our Makefile.py.
Create ROOT/myapp/main.cpp and copy & paste the following code into it:

    #include <iostream>
    
    using namespace std;
    
    int main(int argc, char *argv[]) {
        cout << "Hello World!" << endl;
    }

Go into ROOT folder and type:

    pmake

If you see app.debug inside ROOT, we are good.


Creating a Message:
-------------------

