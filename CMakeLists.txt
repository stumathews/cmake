cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
include(CheckFunctionExists)
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)
check_function_exists(printf HAVE_PRINTF)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file ( "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in" "${PROJECT_BINARY_DIR}/TutorialConfig.h" )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# Set some user definable options:
option(BUILD_C_LIB "use C library" ON)
option(USE_MYLIB "use my library functions" ON)
if(USE_MYLIB)
	# only include this directory if...
	include_directories("${PROJECT_SOURCE_DIR}/MyLibrary")
	# add subdirectory - will look for that dirs own CMakeLists.txt
	add_subdirectory(MyLibrary)
	# Set a variable...
	set (EXTRA_LIBS ${EXTRA_LIBS} MyLibrary)
endif(USE_MYLIB)
if(NOT BUILD_C_LIB)
add_executable(Tutorial main.cpp Person.cpp Person.h)
endif(NOT BUILD_C_LIB)
if(BUILD_C_LIB)
add_executable(Tutorial main.c)
endif(BUILD_C_LIB)
# Link in the libraries...
target_link_libraries(Tutorial ${EXTRA_LIBS})
# add the install targets, namely the Tutorial executable
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# Add tests for ctest
include(CTest)
#basic does-it-segfault test
add_test(TutorialRuns Tutorial "")
#basic output test with no params
add_test(TutorialConstructor Tutorial "")
set_tests_properties(TutorialConstructor PROPERTIES PASS_REGULAR_EXPRESSION "Default constructor called")


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)


