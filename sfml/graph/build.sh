g++ -c main.cpp grid.cpp
g++ main.o grid.o -o result -lsfml-graphics -lsfml-window -lsfml-system
rm main.o grid.o
./result