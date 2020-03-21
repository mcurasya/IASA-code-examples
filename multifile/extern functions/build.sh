gcc -c main.c dependency1.c dependency2.c
gcc main.o dependency1.o dependency2.o -o result
rm main.o dependency1.o dependency2.o
