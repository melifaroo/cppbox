cmake_minimum_required(VERSION 3.10)

project(cppbox)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим зависимости
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

target_link_libraries(cppbox PRIVATE ${Python3_LIBRARIES} Python3::NumPy )
target_link_libraries(cppbox PRIVATE fmt::fmt )

