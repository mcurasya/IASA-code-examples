clang++ -c main.cpp structs.cpp -Wno-c++11-extensions
clang++ main.o structs.o -o result
rm main.o structs.o
./result