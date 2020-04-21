clang++ -c main.cpp
clang++ main.o -lsfml-system -lsfml-window -lsfml-graphics -o result
rm main.o