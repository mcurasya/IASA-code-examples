g++ -c main.cpp grid.cpp
g++ main.o grid.o -o app -lsfml-graphics -lsfml-window -lsfml-system
rm main.o grid.o
./app