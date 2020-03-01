# Project: AirCraft
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = acllib.o main.o
LINKOBJ  = acllib.o main.o
LIBS     = -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib32" -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32" -static-libgcc -mwindows  "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libwinmm.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libmsimg32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libkernel32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libuser32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libgdi32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libole32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/liboleaut32.a" "../../../../../Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32/libuuid.a" -m32
INCS     = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = AirCraft.exe
CXXFLAGS = $(CXXINCS) -m32
CFLAGS   = $(INCS) -m32
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

acllib.o: acllib.c
	$(CC) -c acllib.c -o acllib.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

