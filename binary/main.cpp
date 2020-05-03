#include <iostream>
#include "structs.hpp"
#include <cstring>
void clear();
int main()
{
    clear();
    FILE* f = fopen("data", "rb");
    if (!f)
    {
        f = fopen("data", "wb");
        fclose(f);
    }
    while (1)
    {
        std::cout << "enter an action that you want to perform\n"
                  << "1)add student\n"
                  << "2)change data\n"
                  << "3)delete data\n"
                  << "4)show best course\n"
                  << "5)show best students\n"
                  << "6)show groups without bad students\n"
                  << "7)show all students\n"
                  << "0)exit\n"
                  << ">> ";
        int choice;
        std::cin >> choice;
        void (*actions[])() = {add_student,
                               change_data,
                               delete_data,
                               show_best_course,
                               show_best_students,
                               show_good_groups,
                               show_all_students};
        if (choice == 0)
        {
            break;
        }
        clear();
        if (choice > sizeof(actions) / sizeof(actions[0]))
        {
            std::cout << "sorry, you made a mistake, try again\n";
            continue;
        }

        actions[choice - 1]();
    }
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}