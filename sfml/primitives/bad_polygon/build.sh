g++ -c main.cpp
g++ main.o -o result -lsfml-graphics -lsfml-window -lsfml-system
rm main.o
./result