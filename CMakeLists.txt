cmake_minimum_required (VERSION 3.20)

project (ArgentumOnline)

# Using CONFIGURE_DEPENDS, whenever the glob's value changes, 
# CMake will re-run and update the build with the new/removed files.
file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS "source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_mixer)

if (UNIX)
	target_link_libraries(${PROJECT_NAME} PRIVATE X11 Xext)
endif()

add_custom_target(
    ArgentumOnline_Assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/Resources
    DEPENDS ${PROJECT_NAME}
)