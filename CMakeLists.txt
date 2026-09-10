cmake_minimum_required(VERSION 3.20)


project(
    RakyatElectronicSystem
    VERSION 1.0
    LANGUAGES C CXX
)



set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



# Include header files

include_directories(

    include

)



# Source files


file(GLOB_RECURSE SOURCES

    "src/*.cpp"

)



add_executable(

    RakyatElectronicSystem

    ${SOURCES}

)


add_library(

    sqlite3

    external/sqlite/sqlite3.c

)


target_include_directories(

    sqlite3

    PUBLIC

    external/sqlite

)


target_link_libraries(

    RakyatElectronicSystem

    sqlite3

)