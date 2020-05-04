#include <stdlib.h>
void clear() //OS dependable so use ifdef to find out it
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}