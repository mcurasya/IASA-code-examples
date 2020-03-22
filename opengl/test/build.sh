echo "compiling"
g++ -c main.cpp
echo "linking"
if [ "$(uname)" == "Darwin" ]; then
    g++ main.o -framework GLUT -framework OpenGL -Wno-deprecated -o result
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    g++ main.o -lglut -lGLU -lGL -lm -o result
fi 
echo "removing unneeded files"
rm main.o