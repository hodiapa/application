COLOR = True
CC = "gcc"
CPPC = "g++"
AR = "ar"
LINKER = "g++"
COMMON_CFLAGS = ["-Wall", "-std=gnu++0x",]
LDFLAGS = ["-Xlinker --start-group",]

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
	"defines" :
	[],
    },
}

APPLICATION_NAME = "app." + ACTIVE_CONFIGURATION
