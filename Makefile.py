CC = "gcc"
CPPC = "g++"
AR = "ar"
LINKER = "g++"
COMMON_CFLAGS = ["-O3", "-Wall", "-Wno-psabi", "-std=gnu++0x"]
LDFLAGS = ["-Xlinker", "--start-group"] #["-static"]

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

ACTIVE_MODULES = ["sample", "system"]
MODULES = {
  "sample" : {
      "directory" : "sample",
      "language" : "c++",
      "incpaths" : ["."],
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
