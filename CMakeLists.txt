cmake_minimum_required(VERSION 3.30)

project(data-science-base-c)

################## Set Variables ##################
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
###################################################

################## Create Library ##################
file(GLOB LIB_SOURCES ${ROOT_DIR}/src/*.c)
file(GLOB LIB_HEADERS ${ROOT_DIR}/include/*.h)
set(LIB_NAME data-science-base)
add_library(${LIB_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(${LIB_NAME} PUBLIC ${ROOT_DIR}/include)
####################################################