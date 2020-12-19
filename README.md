# Crosser API
This tutorial is written for version 1.2, but also applies to future versions.

When creating plugins for Crosser, make sure you have Crosser itself installed. Look at the readme on how to install:
[Crosser repository](https://github.com/Bloepiloepi/Crosser)

## Building the API
If you already have Crosser installed, you can skip this step because you have already done it (since Crosser needs the API to function).

- Make sure you have homebrew installed
- Make sure you have sfml and cmake installed using homebrew
```shell
brew install sfml
brew install cmake
```
- Clone this repository
- Cd to the project root
- Execute this command to build, replacing ```/path/to/target/folder``` with any folder you want to use:
```shell
cmake -S . -B /path/to/target/folder; cmake --build /path/to/target/folder --target install -- -j 3;
```

## Creating your project
Once you have built the API, you can create a project. I recommend doing this with CMake. If you use an IDE, you should choose to create a library, not an executable.

This should be your ```CMakeLists.txt``` approximately:
```cmake
cmake_minimum_required(VERSION 3.17) #CMake version
project(CrosserPlugin) #Name of your project, make sure to change all of them in this file if you rename it

include(GNUInstallDirs) #Needed to include the header files

set(CMAKE_CXX_STANDARD 17) #C++ version (needs to be 17 or higher)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED) #Searches for SFML
find_package(CrosserAPI REQUIRED) #Searches for CrosserAPI

add_library(CrosserPlugin SHARED library.cpp) #Add the source files for your plugin, make sure to add new files after "library.cpp"

target_link_libraries(CrosserPlugin PUBLIC CrosserAPI sfml-graphics sfml-window sfml-system) #Link CrosserAPI and SFML to your plugin
target_include_directories(CrosserPlugin PUBLIC "${CMAKE_INSTALL_FULL_INCLUDEDIR}/CrosserAPI") #Include CrosserAPI headers
```

## Start making the plugin
Your plugin should extend IPlugin and one of the files should have two methods for creating and destroying your plugin.

```library.hpp```, for example:
```c++
#include <iostream>

#include <IPlugin.hpp>

class HelloPlugin : public crs::IPlugin {
public:
	~HelloPlugin() noexcept override;

	void setup() override;

	void end() override;

	void onEvent(crs::Event* &event) override;
};

extern "C" [[maybe_unused]] crs::IPlugin* createPlugin();
extern "C" [[maybe_unused]] void destroyPlugin(const HelloPlugin* plugin);
```

And then, the code for your class, in ```library.cpp```:
```c++
#include "library.h"

#include <IPlugin.hpp>
#include <events.hpp>
#include <logger.hpp>

extern "C" [[maybe_unused]] crs::IPlugin* createPlugin() {
	return new HelloPlugin;
}

extern "C" [[maybe_unused]] void destroyPlugin(const HelloPlugin* plugin) {
	delete plugin;
}

HelloPlugin::~HelloPlugin() noexcept = default;

void HelloPlugin::setup() {
	Logger::info("Hello World from HelloPlugin!");
}

void HelloPlugin::end() {
	Logger::info("Bye bye from HelloPlugin!");
}

void HelloPlugin::onEvent(crs::Event *&event) {
	//Code to process event
}
```

Note that both the ```createPlugin()``` and ```destroyPlugin()``` **have** to be ```extern "C"```, otherwise the compiler will obfuscate their names and Crosser will not find them.

## Use the plugin
When running Crosser for the first time, it will create a plugin folder in the directory of the executable. In this folder you can put your dynamic library (in this case ```libCrosserPlugin.dylib``` on Mac, ```libCrosserPlugin.so``` on Linux and ```libCrosserPlugin.dll``` on Windows).

When you run Crosser with your library in the plugin folder, and you have done everything correctly, you should see a hello world message when starting up. Congratulations!