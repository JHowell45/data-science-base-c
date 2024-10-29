cmake_minimum_required(VERSION 3.30)

project(data-science-base-c)

####################################################################################
# Set Variables:
####################################################################################
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

####################################################################################
# Install OpenBLAS:
####################################################################################
set(BLA_VENDER OpenBLAS)
find_package(BLAS REQUIRED)

####################################################################################
# Create Library:
####################################################################################
file(GLOB LIB_SOURCES ${ROOT_DIR}/src/*.c)
file(GLOB LIB_HEADERS ${ROOT_DIR}/include/*.h)
set(LIB_NAME data-science-base)
add_library(${LIB_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(${LIB_NAME} PUBLIC ${ROOT_DIR}/include)
if(BLAS_FOUND)
    message("OpenBLAS found.")
    include_directories(${BLAS_INCLUDE_DIRS})
    target_link_libraries(${LIB_NAME} ${BLAS_LIBRARIES})
endif(BLAS_FOUND)

####################################################################################
# Install Test Framework:
####################################################################################
include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        860062d51b2e8a75d150337b63ca2a472840d13c # v2.6.0
)
if (WIN32)
    add_definitions(-DUNITY_SUPPORT_64)
endif (WIN32)
add_definitions(-DUNITY_INCLUDE_DOUBLE)
FetchContent_MakeAvailable(unity)
include(CTest)

####################################################################################
# Add Vector Tests:
####################################################################################
set(VECTOR_INSERT vector_insert)
add_executable(${VECTOR_INSERT}_test tests/vectors/${VECTOR_INSERT}.c)
target_link_libraries(${VECTOR_INSERT}_test ${LIB_NAME} unity)
add_test(${VECTOR_INSERT}_test ${VECTOR_INSERT}_test)

set(VECTOR_INSERT vector_scalar_multiplication)
add_executable(${VECTOR_INSERT}_test tests/vectors/${VECTOR_INSERT}.c)
target_link_libraries(${VECTOR_INSERT}_test ${LIB_NAME} unity)
add_test(${VECTOR_INSERT}_test ${VECTOR_INSERT}_test)

set(VECTOR_DOT_PRODUCT vector_dot_product)
add_executable(${VECTOR_DOT_PRODUCT}_test tests/vectors/${VECTOR_DOT_PRODUCT}.c)
target_link_libraries(${VECTOR_DOT_PRODUCT}_test ${LIB_NAME} unity)
add_test(${VECTOR_DOT_PRODUCT}_test ${VECTOR_DOT_PRODUCT}_test)