cmake_minimum_required (VERSION 3.12)

# Use Microsoft VCPKG to manage all our dependencies
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project (ArgentumOnline)

# Allow third-party CMake scripts to find modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules)

# Version of C++ standard to use.
set(CMAKE_CXX_STANDARD 20)

# out-of-source build directory
set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/build)

# Add compiler/linker flags depending of what compiler we're using
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")

    string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wconversion -pedantic -ggdb -fstack-protector -D_GLIBCXX_DEBUG")

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-local-typedefs")
        string(APPEND CMAKE_EXE_LINKER_FLAGS " -ggdb -fstack-protector")
        
        # Flag -rdynamic does not exist in MSYS2 nor in MINGW
        if(NOT MSYS AND NOT MINGW)
            string(APPEND CMAKE_CXX_FLAGS " -rdynamic")
            string(APPEND CMAKE_EXE_LINKER_FLAGS " -rdynamic")
        endif()
        
    endif()
    
    # Generates debug symbols for gdb or valgrynd to use
    string(APPEND CMAKE_CXX_FLAGS_DEBUG " -g")

elseif (MSVC)

    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        string(APPEND CMAKE_CXX_FLAGS " /W4")
    endif()

endif()

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