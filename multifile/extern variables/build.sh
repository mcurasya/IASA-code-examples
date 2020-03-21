gcc -c main.c dependency.c
gcc main.o dependency.o -o result
rm main.o dependency.o