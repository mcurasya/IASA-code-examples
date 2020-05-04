#include <iostream>
#include "structs.hpp"
#include <cstring>
extern void clear();
int main()
{
    clear();
    //============== check if file exists =========
    FILE *f = fopen("data", "rb");
    if (!f)
    {
        f = fopen("data", "wb");
        fclose(f);
    }
    //=============================================
    while (1) //start main cycle
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
                  << ">> "; //ask a user
        int choice;
        std::cin >> choice; //get user`s choice
        void (*actions[])() = {add_student,
                               change_data,
                               delete_data,
                               show_best_course,
                               show_best_students,
                               show_good_groups,
                               show_all_students}; //array of function pointers, easier to add one more function
        clear();
        if (choice == 0) //close program if choice is 0
        {
            break;
        }
        if (choice > sizeof(actions) / sizeof(actions[0]) or choice < 0) //check if out of array bounds
        {
            std::cout << "sorry, you made a mistake, try again\n";
            continue;
        }

        actions[choice - 1](); //choose an action
    }
}
