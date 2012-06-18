CC = "gcc"
CPPC = "g++"
AR = "ar"
LINKER = "g++"
COMMON_CFLAGS = ["-O3", "-Wall", "-Wno-psabi", "-std=gnu++0x"]
LDFLAGS = ["-static", "-Xlinker", "--start-group"]

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
LIBRARIES = []

ACTIVE_MODULES = ["main", "system"]
MODULES = {
  "main" : {
      "directory" : ".",
      "language" : "c++",
      "incpaths" : [],
      "defines" : [],
  },
  "system" : {
      "directory" : "system",
      "language" : "c++",
      "incpaths" : [],
      "defines" : [],
  },
}

APPLICATION_NAME = "app." + ACTIVE_CONFIGURATION
