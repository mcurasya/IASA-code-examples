if [ "$(uname)" == "Darwin" ]; then
    g++ main.cpp -framework GLUT -framework OpenGL -Wno-deprecated -o result
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    g++ main.cpp -lglut -lGLU -lGL -lm -o result
fi 