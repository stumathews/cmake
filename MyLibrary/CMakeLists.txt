add_library(MyLibrary mylibrary.cpp)
install (TARGETS MyLibrary DESTINATION bin)
install (FILES mylibrary.h DESTINATION include)
