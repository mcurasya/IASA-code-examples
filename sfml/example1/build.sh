gcc -c main.cpp
g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system
rm main.o
./app