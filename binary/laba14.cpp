#include <iostream>
#include "structs.hpp"

using namespace std;
using namespace structs;

void add_record();
void show_records();
void change_record();
void delete_record();
void best_faculty();
void best_student();
void good_groups();

int main(int argc, const char **argv)
{
    short pick;
    while (true)
    {
        cout << "1 - add record\n"
             << "2 - show all records\n"
             << "3 - change record\n"
             << "4 - delete record\n"
             << "5 - show best faculty\n"
             << "6 - show best student\n"
             << "7 - show groups without bad students\n"
             << "8 - exit\n"
             << ">> ";
        cin >> pick;
        switch (pick)
        {
        case 1:
            add_record();
            break;
        case 2:
            show_records();
            break;
        case 3:
        change_record();
            break;
        case 4:
        delete_record();
            break;
        case 5:
        best_faculty();
            break;
        case 6:
        best_student();
            break;
        case 7:
        good_groups();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}

void add_record()
{
    cout << "input last name->";
    char* name = (char*)calloc(15, sizeof(char));
    scanf("%s", name);
}

void show_records() {

}
