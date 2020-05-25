gcc -c main.c ext1.c ext2.c
gcc main.o ext1.o ext2.o -o result
rm main.o ext1.o ext2.o