cmake_minimum_required(VERSION 3.3)
#cmake_minimum_required(VERSION 3.13)
project(Progetto)

set(Boost_DEBUG ON)
set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Progetto main.cpp PointND.cpp PointND.h Kmeans.cpp Kmeans.h CSVReader.cpp CSVReader.h Timer.cpp Timer.h CSVReader.cpp CSVReader.h Kmeans.cpp Kmeans.h PointND.cpp PointND.h Timer.cpp Timer.h)


#per la parte parallela
#cmake_minimum_required(VERSION 3.3)
#project(openmp-hello-world)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 11)

# try also to compile and execute without: -fopenmp
# in Linux just use -fopenmp, without -lomp and -Xpreprocessor

set(SOURCE_FILES main.cpp)
#add_executable(openmp-hello-world ${SOURCE_FILES})