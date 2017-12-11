# The root level CMakeLists.txt must start with the following two lines.
# You should substitue your own project name
cmake_minimum_required(VERSION 3.5)
project(flappy-birds-project)

# Sets the C++ version we're going to use (VisualStudio will probably ignore this
# but it makes your code compile on different platforms)
set(CMAKE_CXX_STANDARD 14)

# Tell CMake to look for further CMakeLists.txt files in the following subdirectories.
# The first is the sdl_cpp wrapper library, the second is the target project.
add_subdirectory(sdl_cpp_wrapper)
add_subdirectory(flappy_birds)
