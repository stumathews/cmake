add_library(MyLibrary mylibrary.c)
install (TARGETS MyLibrary DESTINATION bin)
install (FILES mylibrary.h DESTINATION include)
