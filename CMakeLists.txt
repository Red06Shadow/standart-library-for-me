cmake_minimum_required(VERSION 3.10)

option(USINGWCARACTER "Usa los caracteres wchar_t para las rutas de archivos" OFF)
option(TESTLIBME "Indica si libme esta en testeo o en compilacion libreria" OFF)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

if(TESTLIBME)
project(stdandart-library-for-me-test)
add_executable(stdandart-library-for-me-test 
${CMAKE_SOURCE_DIR}/main.cpp
${CMAKE_SOURCE_DIR}/lib/numbers.cpp
${CMAKE_SOURCE_DIR}/lib/converter.cpp
${CMAKE_SOURCE_DIR}/lib/exception.cpp
${CMAKE_SOURCE_DIR}/lib/url.cpp
${CMAKE_SOURCE_DIR}/lib/fstream.cpp
${CMAKE_SOURCE_DIR}/lib/directory.cpp
${CMAKE_SOURCE_DIR}/lib/time.cpp
${CMAKE_SOURCE_DIR}/lib/memory.cpp
${CMAKE_SOURCE_DIR}/lib/stringbuffer.cpp
${CMAKE_SOURCE_DIR}/lib/sstrings.cpp
${CMAKE_SOURCE_DIR}/lib/logs.cpp
)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Proyectos(Red06Shadow)/bin")
link_directories(${CMAKE_SOURCE_DIR}/libme/lib)
target_link_libraries(stdandart-library-for-me-test PRIVATE Pathcch ${CMAKE_SOURCE_DIR}/lib/wdebuger/libwdebuger.a)
else()
project(stdandart-library-for-me)
add_library(stdandart-library-for-me STATIC
${CMAKE_SOURCE_DIR}/lib/converter.cpp
${CMAKE_SOURCE_DIR}/lib/numbers.cpp
${CMAKE_SOURCE_DIR}/lib/exception.cpp
${CMAKE_SOURCE_DIR}/lib/url.cpp
${CMAKE_SOURCE_DIR}/lib/fstream.cpp
${CMAKE_SOURCE_DIR}/lib/directory.cpp
${CMAKE_SOURCE_DIR}/lib/time.cpp
${CMAKE_SOURCE_DIR}/lib/memory.cpp
${CMAKE_SOURCE_DIR}/lib/stringbuffer.cpp
${CMAKE_SOURCE_DIR}/lib/sstrings.cpp
${CMAKE_SOURCE_DIR}/lib/logs.cpp
)
# Configuración por configuración
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release)

# Para una biblioteca específica
set_target_properties(stdandart-library-for-me PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/debug
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release
)
link_directories(${CMAKE_SOURCE_DIR}/libme/lib)
target_link_libraries(stdandart-library-for-me PRIVATE Pathcch ${CMAKE_SOURCE_DIR}/lib/wdebuger/libwdebuger.a)

endif()

|





