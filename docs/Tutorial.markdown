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
    LDFLAGS = ["-Xlinker --start-group"]
    
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

        return 0;
    }

Go into ROOT folder and type:

    pmake

If you see app.debug inside ROOT, we are good.


Creating a Message:
-------------------

To create a Message, we use the macro MESSAGE(), which is defined in
system/system.h:

    #include "system/system.h"
    #include <iostream>
    using namespace std;

    MESSAGE(MyMessage, 1) {

    };
    
    int main(int argc, char *argv[]) {
        Message *m = new MyMessage();
        cout << "Message priority: " << m->getPriority() << endl;
        delete m;

        return 0;
    }

The ouput should be:

    Message priority: 1

If you need to extend a Message class, you need to do as follows:

    #include "system/system.h"
    #include <iostream>
    using namespace std;

    MESSAGE(MyMessage, 1) {
    public:
        virtual void foo() { cout << "foo()" << endl; }
    };

    SUB_MESSAGE(MySubMessage, MyMessage, 2) {

    };
    
    int main(int argc, char *argv[]) {
        MySubMessage *m = new MySubMessage();
        cout << "Message priority: " << m->getPriority() << endl;
        m->foo();
        delete m;

        return 0;
    }
 
The output should be:

    Message priority: 2
    foo()


Creating a State:
-----------------

Now, let's create a State object that takes action upon receiving a
Message.

    #include "system/system.h"
    #include <iostream>
    using namespace std;

    MESSAGE(MyMessage, 1) {

    };

    STATE(MyState) {
    public:
        MyState() { }
        void handleMyMessage(Message *m) {
            cout << "handleMyMessage()" << endl; 
        }
    };
    
We create our MyState class, we also created the handler function
MyState::handleMyMessage(). However, we have to link MyMessage to this
function. We do this in the constructor of MyState:

    #include "system/system.h"
    #include <iostream>
    using namespace std;

    MESSAGE(MyMessage, 1) {

    };

    STATE(MyState) {
    public:
        MyState() {
            LINK(MyMessage, MyState::handleMyMessage);
        }
        void handleMyMessage(Message *m) {
            cout << "handleMyMessage()" << endl; 
        }
    };
    
Now our state class is ready.

    int main(int argc, char *argv[]) {
        Message *m = new MyMessage();
        MyState state;
        state.handle(m);
        delete m;

        return 0;
    }

Don't panic! It will not compile. It is because you are not allowed to
call State::handle() directly. For this example to work, we have to introduce another class: StateMachine. So, here is the code change needed:

    int main(int argc, char *argv[]) {
        StateMachine<DispatchModeSync> fsm(new MyState);
        Message *m = new MyMessage();
        fsm.handle(m);

        return 0;
    }
    
We created a StateMachine object and set its initial state as MyState.
We removed 'delete m;' because it is already done StateMachine. We will
come to what 'DispatchModeSync' means later.

Switching State:
----------------

To switch to another state we use State::changeState(), as shown below:

    #include "system/system.h"
    #include <iostream>
    using namespace std;

    MESSAGE(MyMessage, 1) {

    };

    STATE(MyState) {
    public:
        MyState() {
            LINK(MyMessage, MyState::handleMyMessage);
        }
        void handleMyMessage(Message *m) {
            changeState(new MyNewState);
        }
    };

    STATE(MyNewState) {
    public:
        MyNewState() { }
    };

changeState() first deletes the current state, and then sets the new
state as the current state.

Routing Messages:
-----------------

