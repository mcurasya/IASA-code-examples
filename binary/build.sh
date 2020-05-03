clang++ -c main.cpp structs.cpp clear.cpp -Wno-c++11-extensions
clang++ main.o structs.o clear.o -o result
rm main.o structs.o clear.o
./result