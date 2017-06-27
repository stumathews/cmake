
if(BUILD_C_LIB)
	add_library(MyLibrary mylibrary.c)
endif(BUILD_C_LIB)

if(NOT BUILD_C_LIB)
	add_library(MyLibrary mylibrary.cpp)
endif(NOT BUILD_C_LIB)
install (TARGETS MyLibrary DESTINATION bin)
install (FILES mylibrary.h DESTINATION include)
