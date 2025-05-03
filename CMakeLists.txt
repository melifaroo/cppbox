cmake_minimum_required(VERSION 3.10)

project(cppbox)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE) 
    if(DEFINED ENV{VCPKG_ROOT}) 
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    else() 
        set(VCPKG_ROOT "${CMAKE_BINARY_DIR}/vcpkg") 
        if(NOT EXISTS "${VCPKG_ROOT}") 
            message(STATUS "Cloning vcpkg into ${VCPKG_ROOT}") 
            execute_process( COMMAND git clone https://github.com/microsoft/vcpkg.git ${VCPKG_ROOT} RESULT_VARIABLE result ) 
            if(result) 
                message(FATAL_ERROR "Failed to clone vcpkg: ${result}") 
            endif() 
            if(WIN32) 
                execute_process( COMMAND ${VCPKG_ROOT}/bootstrap-vcpkg.bat WORKING_DIRECTORY ${VCPKG_ROOT} RESULT_VARIABLE result ) 
            else() 
                execute_process( COMMAND ${VCPKG_ROOT}/bootstrap-vcpkg.sh WORKING_DIRECTORY ${VCPKG_ROOT} RESULT_VARIABLE result ) 
            endif() 
            if(result) 
                message(FATAL_ERROR "Failed to bootstrap vcpkg: ${result}") 
            endif() 
        endif() 
        set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "") 
    endif() 
endif()

find_package(fmt CONFIG REQUIRED) 

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

# populate matplotlib repository
include(FetchContent)
FetchContent_Declare(
    matplotlib
    GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
    GIT_TAG        f23347fca25219d1c42cbb91608b5556814bf572
)
FetchContent_GetProperties(matplotlib)
if(NOT matplotlib_POPULATED)
    FetchContent_Populate(matplotlib)
endif()
include_directories(SYSTEM ${matplotlib_SOURCE_DIR})

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(cppbox ${SOURCES})

# link python and numpy

if(Python3_LIBRARY_RELEASE)
    set(Python3_LIBRARIES ${Python3_LIBRARY_RELEASE})
else()
    set(Python3_LIBRARIES ${Python3_LIBRARIES})
endif()

target_link_libraries(cppbox
    PRIVATE
        ${Python3_LIBRARIES}
        Python3::NumPy
)

target_link_libraries(cppbox PRIVATE fmt::fmt )

