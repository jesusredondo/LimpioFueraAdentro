cmake_minimum_required(VERSION 3.10)
project(LimpioFueraAdentro C)

set(CMAKE_C_STANDARD 99)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(LimpioFueraAdentro main.c estructuras.h solucion.h solucion.c globales.h globales.c cargaguarda.c cargaguarda.h funciones.c funciones.h)

target_link_libraries(LimpioFueraAdentro m)