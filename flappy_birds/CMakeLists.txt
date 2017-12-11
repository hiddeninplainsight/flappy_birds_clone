# Add an executable, the first parameter is the executables name,
# the rest of the parameters specify the sourcefiles to compile into
# the executable.
add_executable(flappy-birds
	flappy_bird.cpp
	main.cpp
	pipes.cpp
	)

# As the executable uses the 'sdl-cpp' library tell CMake to link it into the
# flappy-birds executable.
target_link_libraries(flappy-birds
	sdl-cpp
	)

# The images required by the executable need to be copied to the output (binary)
# directory. The following lines search for '.png' files in the source directory
# and copy them to the output directory.
file(GLOB png_files "${flappy-birds-project_SOURCE_DIR}/flappy_birds/*.png")
foreach(png_file ${png_files})
	file(COPY "${png_file}" DESTINATION "${flappy-birds-project_BINARY_DIR}/flappy_birds")
endforeach()

# Copy the SDL2 dlls to the output directory
copy_sdl2_windows_dlls("${flappy-birds-project_BINARY_DIR}/flappy_birds")

# Note
# ----
# "${flappy-birds-project_SOURCE_DIR}" will be set to the source directory where
# the CMakeLists.txt containing the project(flappy-birds-project) is located
#
# "${flappy-birds-project_BINARY_DIR}" will be set to the output directory for
# executables and libraries defined in CMakeLists.txt containing the
# project(flappy-birds-project) definition
#
# As the flappy-birds executable is defined in a subdirectory called 'flappy_birds'
# the additional '/flappy_birds' is required to make sure the files are taken from
# the correct source location and copied to the correct destination location.
