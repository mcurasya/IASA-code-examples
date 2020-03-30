gcc -c ext.c main.c 
gcc ext.o main.o -o result
rm main.o ext.o