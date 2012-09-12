A Tutorial:

In this tutorial, I will show you how to implement a multi-threaded State Pattern using the code in this repository.

I will use pmake to build the code, so I will start with the following Makefile.py file. From now on <ROOT> will denote
the root folder of the project. Please copy & paste the following code into <ROOT>/Makefile.py:

COLOR = True

CC = "gcc"
CPPC = "g++"
AR = "ar"
LINKER = "g++"
COMMON_CFLAGS = ["-Wall",]
LDFLAGS = []

LANGUAGE_SETTINGS = { 
    "c" : { 
    "compiler" : CC, 
    "headerext" : [".h"],
    "sourceext" : [".c"],
    },  
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
    "release" : {
    "flags" : COMMON_CFLAGS,
    "buildsubdir" : "Release",
    },
}

LIBRARY_PATHS = []
LIBRARIES = ["pthread"]

ACTIVE_MODULES = ["system",]
MODULES = {
  "system" : {
      "directory" : "system",
      "language" : "c++",
      "incpaths" : [],
      "defines" : [],
  },
}

APPLICATION_NAME = "app." + ACTIVE_CONFIGURATION
