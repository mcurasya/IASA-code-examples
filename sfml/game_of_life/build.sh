g++ -c main.cpp grid.cpp
g++ main.o grid.o -lsfml-system -lsfml-window -lsfml-graphics -o result
rm *.o
./result