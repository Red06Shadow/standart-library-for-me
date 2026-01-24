cmake_minimum_required(VERSION 3.10)

option(USINGWCARACTER "Usa los caracteres wchar_t para las rutas de archivos" OFF)
option(TESTLIBME "Indica si libme esta en testeo o en compilacion libreria" ON)

set(CMAKE_CXX_STANDARD 17)
# Configuración por configuración
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_<CONFIG> ${CMAKE_SOURCE_DIR}/release)


include_directories(include)

if(TESTLIBME)
project(slfm-test)
add_executable(slfm-test 
${CMAKE_SOURCE_DIR}/main.cpp
${CMAKE_SOURCE_DIR}/lib/numbers.cpp
${CMAKE_SOURCE_DIR}/lib/converter.cpp
${CMAKE_SOURCE_DIR}/lib/exception.cpp
${CMAKE_SOURCE_DIR}/lib/url.cpp
${CMAKE_SOURCE_DIR}/lib/fstream.cpp
${CMAKE_SOURCE_DIR}/lib/files.cpp
${CMAKE_SOURCE_DIR}/lib/time.cpp
${CMAKE_SOURCE_DIR}/lib/memory.cpp
${CMAKE_SOURCE_DIR}/lib/stringbuffer.cpp
${CMAKE_SOURCE_DIR}/lib/sstrings.cpp
${CMAKE_SOURCE_DIR}/lib/terminal.cpp
${CMAKE_SOURCE_DIR}/lib/logs.cpp
)
link_directories(${CMAKE_SOURCE_DIR}/libme/lib)
target_link_libraries(slfm-test PRIVATE Pathcch ${CMAKE_SOURCE_DIR}/lib/wdebuger/libwdebuger.a)
else()
project(slfm)
add_library(slfm STATIC
${CMAKE_SOURCE_DIR}/lib/numbers.cpp
${CMAKE_SOURCE_DIR}/lib/converter.cpp
${CMAKE_SOURCE_DIR}/lib/exception.cpp
${CMAKE_SOURCE_DIR}/lib/url.cpp
${CMAKE_SOURCE_DIR}/lib/fstream.cpp
${CMAKE_SOURCE_DIR}/lib/files.cpp
${CMAKE_SOURCE_DIR}/lib/time.cpp
${CMAKE_SOURCE_DIR}/lib/memory.cpp
${CMAKE_SOURCE_DIR}/lib/stringbuffer.cpp
${CMAKE_SOURCE_DIR}/lib/sstrings.cpp
${CMAKE_SOURCE_DIR}/lib/terminal.cpp
${CMAKE_SOURCE_DIR}/lib/logs.cpp
)

link_directories(${CMAKE_SOURCE_DIR}/libme/lib)
target_link_libraries(slfm PRIVATE Pathcch ${CMAKE_SOURCE_DIR}/lib/wdebuger/libwdebuger.a)

endif()