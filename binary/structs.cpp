#include "structs.hpp"
#include <iostream>
#include <cstring>
using namespace std;
void change_name();
void change_group_name();
void change_course_year();
void change_faculty_name();
void delete_name();
void delete_group_name();
void delete_course_year();
void delete_faculty_name();
void delete_everyting();

void add_student()
{
    char facname[20];
    short year;
    char groupname[20];
    char student_first_name[20];
    char student_last_name[20];
    short marks[5];

    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    cout << "enter faculty name >> ";
    cin >> facname;
    cout << "enter course year >> ";
    cin >> year;
    cout << "enter name of the group >> ";
    cin >> groupname;
    cout << "enter name of the student >> ";
    cin >> student_first_name >> student_last_name;
    cout << "enter 5 marks of a student\n";
    for (size_t i = 0; i < 5; i++)
    {
        cout << ">> ";
        cin >> marks[i];
    }
    faculty fac;                                     //it should not be here but still
    while (fread(&curr_fac, sizeof(curr_fac), 1, f)) //go through faculties
    {
        if (!strcmp(facname, curr_fac.name))
        {
            for (size_t i = 0; i < 10; i++) //through courses
            {
                if (curr_fac.courses[i].year == year)
                {
                    for (size_t j = 0; j < 20; j++) //through groups
                    {
                        if (!strcmp(groupname, curr_fac.courses[i].groups[j].name))
                        {
                            for (size_t k = 0; k < 30; k++) //find empty place for student
                            {
                                if (!strcmp(student_first_name, curr_fac.courses[i].groups[j].students[k].first_name) and !strcmp(student_last_name, curr_fac.courses[i].groups[j].students[k].last_name))
                                {
                                    cout << "sorry, such student already exists";
                                    fclose(f);
                                    return;
                                }
                                if (!strlen(curr_fac.courses[i].groups[j].students[k].first_name))
                                {
                                    strcpy(curr_fac.courses[i].groups[j].students[k].first_name, student_first_name);
                                    strcpy(curr_fac.courses[i].groups[j].students[k].last_name, student_last_name);
                                    for (int g = 0; g < 5; g++)
                                    {
                                        curr_fac.courses[i].groups[j].students[k].marks[g] = marks[g];
                                    }
                                    goto write;
                                }
                            }
                        }
                        if (!strlen(curr_fac.courses[i].groups[j].name))
                        {
                            strcpy(curr_fac.courses[i].groups[j].name, groupname);
                            strcpy(curr_fac.courses[i].groups[j].students[0].first_name, student_first_name);
                            strcpy(curr_fac.courses[i].groups[j].students[0].last_name, student_last_name);
                            for (int g = 0; g < 5; g++)
                            {
                                curr_fac.courses[i].groups[j].students[0].marks[g] = marks[g];
                            }
                            goto write;
                        }
                    }
                }
                if (curr_fac.courses[i].year == 0)
                {
                    curr_fac.courses[i].year = year;
                    strcpy(curr_fac.courses[i].groups[0].name, groupname);
                    strcpy(curr_fac.courses[i].groups[0].students[0].first_name, student_first_name);
                    strcpy(curr_fac.courses[i].groups[0].students[0].last_name, student_last_name);
                    for (int g = 0; g < 5; g++)
                    {
                        curr_fac.courses[i].groups[0].students[0].marks[g] = marks[g];
                    }
                    goto write;
                }
            }
        }
    }
    strcpy(fac.name, facname);
    fac.courses[0].year = year;
    strcpy(fac.courses[0].groups[0].name, groupname);
    strcpy(fac.courses[0].groups[0].students[0].first_name, student_first_name);
    strcpy(fac.courses[0].groups[0].students[0].last_name, student_last_name);
    for (int g = 0; g < 5; g++)
    {
        fac.courses[0].groups[0].students[0].marks[g] = marks[g];
    }
    fwrite(&fac, sizeof(fac), 1, f);
    fclose(f);
    cout << "student was added! \n";
    return;
write:
    fseek(f, -sizeof(curr_fac), SEEK_CUR);
    fwrite(&curr_fac, sizeof(curr_fac), 1, f);
    fclose(f);
    cout << "student was added! \n";
}

void change_data()
{
again:
    int choice;
    void (*choices[])() = {change_name,
                           change_group_name,
                           change_course_year,
                           change_faculty_name};
    cout << "all students:\n";
    show_all_students();
    cout << "enter your choice:\n"
         << "1)change student name\n"
         << "2)change group name\n"
         << "3)change course year\n"
         << "4)change faculty name\n"
         << "0)go back"
         << ">> ";
    cin >> choice;
    if (choice == 0)
    {
        return;
    }
    if (choice > sizeof(choices) / sizeof(choices[0]))
    {
        cout << "sorry, try again";
        goto again;
    }
    choices[choice - 1]();
}
void delete_data()
{
again:
    int choice;
    void (*choices[])() = {delete_name,
                           delete_group_name,
                           delete_course_year,
                           delete_faculty_name,
                           delete_everyting};
    cout << "all students:\n";
    show_all_students();
    cout << "enter your choice:\n"
         << "1)delete student name\n"
         << "2)delete group name\n"
         << "3)delete course year\n"
         << "4)delete faculty name\n"
         << "5)delete everything\n"
         << "0)go back"
         << ">> ";
    cin >> choice;
    if (choice == 0)
    {
        return;
    }
    if (choice > sizeof(choices) / sizeof(choices[0]))
    {
        cout << "sorry, try again";
        goto again;
    }
    choices[choice - 1]();
}
void show_best_course()
{
    FILE *f = fopen("data", "rb");
    faculty curr_fac;
    faculty best_fac;
    int best_fac_score;
    course best_course;
    int best_course_score;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        int faculty_good_students = 0;
        for (size_t i = 0; i < 10; i++)
        {
            if (curr_fac.courses[i].year == 0)
            {
                continue;
            }
            int course_good_students = 0;
            for (size_t j = 0; j < 20; j++)
            {
                if (!strlen(curr_fac.courses[i].groups[j].name))
                {
                    continue;
                }
                for (size_t k = 0; k < 30; k++)
                {
                    if (!strlen(curr_fac.courses[i].groups[j].students[k].first_name))
                    {
                        continue;
                    }
                    int good = 1;
                    for (size_t g = 0; g < 5; g++)
                    {
                        if (curr_fac.courses[i].groups[j].students[k].marks[g] < 5)
                        {
                            good = 0;
                        }
                    }
                    if (good)
                    {
                        course_good_students++;
                        faculty_good_students++;
                    }
                }
            }
            if (course_good_students > best_course_score)
            {
                best_course_score = course_good_students;
                best_course = curr_fac.courses[i];
            }
        }
        if (faculty_good_students > best_fac_score)
        {
            best_fac = curr_fac;
            best_fac_score = faculty_good_students;
        }
    }
    cout << "best faculty -> " << best_fac.name << endl;
    cout << "best course -> " << best_course.year << endl;
    fclose(f);
}
void show_best_students()
{
    FILE *f = fopen("data", "rb");
    cout << "best students are:\n";
    faculty curr_fac;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        cout << curr_fac.name << endl;
        for (size_t i = 0; i < 10; i++)
        {
            if (curr_fac.courses[i].year == 0)
            {
                continue;
            }
            cout << "\t"
                 << "year " << curr_fac.courses[i].year << endl;
            for (size_t j = 0; j < 20; j++)
            {
                if (!strlen(curr_fac.courses[i].groups[j].name))
                {
                    continue;
                }
                cout << "\t\t"
                     << "group " << curr_fac.courses[i].groups[j].name << endl;
                for (size_t k = 0; k < 30; k++)
                {
                    if (!strlen(curr_fac.courses[i].groups[j].students[k].first_name))
                    {
                        continue;
                    }
                    int is_good = 1;
                    for (size_t g = 0; g < 5; g++)
                    {
                        if (curr_fac.courses[i].groups[j].students[k].marks[g] < 5)
                        {
                            is_good = 0;
                        }
                    }
                    if (is_good)
                    {
                        cout << "\t\t\t" << curr_fac.courses[i].groups[j].students[k].first_name
                             << " "
                             << curr_fac.courses[i].groups[j].students[k].last_name << endl;
                    }
                }
            }
        }
    }
    fclose(f);
}
void show_good_groups()
{
    FILE *f = fopen("data", "rb");
    cout << "all students are:\n";
    faculty curr_fac;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        cout << curr_fac.name << endl;
        for (size_t i = 0; i < 10; i++)
        {
            if (curr_fac.courses[i].year == 0)
                continue;
            cout << "\t"
                 << "year " << curr_fac.courses[i].year << endl;
            for (size_t j = 0; j < 20; j++)
            {
                if (!strlen(curr_fac.courses[i].groups[j].name))
                    continue;
                int good = 1;
                for (size_t k = 0; k < 30; k++)
                {
                    if (!strlen(curr_fac.courses[i].groups[j].students[k].first_name))
                        continue;
                    for (size_t g = 0; g < 5; g++)
                    {
                        if (curr_fac.courses[i].groups[j].students[k].marks[g] < 3)
                        {
                            good = 0;
                            break;
                        }
                    }
                }
                if (good)
                {
                    cout << "\t\t"
                         << "group " << curr_fac.courses[i].groups[j].name << endl;
                }
            }
        }
    }
    fclose(f);
}

void show_all_students()
{
    FILE *f = fopen("data", "rb");
    cout << "all students are:\n";
    faculty curr_fac;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        cout << curr_fac.name << endl;
        for (size_t i = 0; i < 10; i++)
        {
            if (curr_fac.courses[i].year == 0)
            {
                continue;
            }
            cout << "\t"
                 << "year " << curr_fac.courses[i].year << endl;
            for (size_t j = 0; j < 20; j++)
            {
                if (!strlen(curr_fac.courses[i].groups[j].name))
                {
                    continue;
                }
                cout << "\t\t"
                     << "group " << curr_fac.courses[i].groups[j].name << endl;
                for (size_t k = 0; k < 30; k++)
                {
                    if (!strlen(curr_fac.courses[i].groups[j].students[k].first_name))
                    {
                        continue;
                    }

                    cout << "\t\t\t" << curr_fac.courses[i].groups[j].students[k].first_name
                         << " "
                         << curr_fac.courses[i].groups[j].students[k].last_name << endl;
                }
            }
        }
    }
}

void change_name()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char groupname[20];
    char newname[20];
    char old_first_name[20];
    char old_last_name[20];
    char new_first_name[20];
    char new_last_name[20];
    char facname[20];
    cout << "enter name of the faculty >> ";
    cin >> facname;
    cout << "enter group of a student that you want to change >> ";
    cin >> groupname;
    cout << "enter a student name >> ";
    cin >> old_first_name >> old_last_name;
    cout << "enter a new student name >> ";
    cin >> new_first_name >> new_last_name;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(facname, curr_fac.name))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == 0)
                {
                    continue;
                }
                for (size_t j = 0; j < 20; j++)
                {
                    if (!strcmp(groupname, curr_fac.courses[i].groups[j].name))
                    {
                        for (size_t k = 0; k < 30; k++)
                        {
                            if (!strcmp(curr_fac.courses[i].groups[j].students[k].first_name, old_first_name) and !strcmp(curr_fac.courses[i].groups[j].students[k].last_name, old_last_name))
                            {
                                strcpy(curr_fac.courses[i].groups[j].students[k].first_name, new_first_name);
                                strcpy(curr_fac.courses[i].groups[j].students[k].last_name, new_last_name);
                                fseek(f, -sizeof(curr_fac), SEEK_CUR);
                                fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                                fclose(f);
                                cout << "name changed\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "sorry, couldn`t find fuch student\n";
    fclose(f);
}

void change_group_name()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char oldname[20];
    char newname[20];
    char facname[20];
    cout << "enter name of the faculty >> ";
    cin >> facname;
    cout << "enter name that you want to change >> ";
    cin >> oldname;
    cout << "enter a new group name";
    cin >> newname;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(facname, curr_fac.name))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == 0)
                {
                    continue;
                }
                for (size_t j = 0; j < 20; j++)
                {
                    if (!strcmp(curr_fac.courses[i].groups[j].name, oldname))
                    {
                        strcpy(curr_fac.courses[i].groups[j].name, newname);
                        fseek(f, -sizeof(curr_fac), SEEK_CUR);
                        fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                        fclose(f);
                        return;
                    }
                }
            }
        }
    }
    cout << "sorry couldnt find such group\n";
    fclose(f);
}

void change_course_year()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    short old_course;
    short new_course;
    char facname[20];
    cout << "enter name of the faculty >> ";
    cin >> facname;
    cout << "enter course you want to change >>";
    cin >> old_course;
    cout << "enter course you want to change to >>";
    cin >> new_course;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(facname, curr_fac.name))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == 0)
                {
                    continue;
                }
                if (curr_fac.courses[i].year == old_course)
                {
                    curr_fac.courses[i].year = new_course;
                    fseek(f, -sizeof(curr_fac), SEEK_CUR);
                    fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                    fclose(f);
                    return;
                }
            }
        }
    }
    cout << "sorry, couldn`t find such course\n";
    fclose(f);
}

void change_faculty_name()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char facname[20];
    char new_facname[20];
    cout << "enter name of the faculty >> ";
    cin >> facname;
    cout << "enter new name of the faculty >> ";
    cin >> new_facname;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(facname, curr_fac.name))
        {
            strcpy(curr_fac.name, new_facname);
            fseek(f, -sizeof(curr_fac), SEEK_CUR);
            fwrite(&curr_fac, sizeof(curr_fac), 1, f);
            fclose(f);
            cout << "name changed\n";
            return;
        }
    }
    cout << "sorry, couldn`t find such faculty\n";
    fclose(f);
}
//TODO delete name
void delete_name()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char facname[20];
    char groupname[20];
    char first_name[20];
    char last_name[20];
    short year;
    cout << "enter faculty >> ";
    cin >> facname;
    cout << "enter course >> ";
    cin >> year;
    cout << "enter group >> ";
    cin >> groupname;
    cout << "enter student you want to delete >> ";
    cin >> first_name >> last_name;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(curr_fac.name, facname))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == year)
                {
                    for (size_t j = 0; j < 20; j++)
                    {
                        if (!strcmp(curr_fac.courses[i].groups[j].name, groupname))
                        {
                            for (size_t k = 0; k < 30; k++)
                            {
                                if (!strcmp(curr_fac.courses[i].groups[j].students[k].first_name, first_name) and !strcmp(curr_fac.courses[i].groups[j].students[k].last_name, last_name))
                                {
                                    curr_fac.courses[i].groups[j].students[k] = student();
                                    fseek(f, -sizeof(curr_fac), SEEK_CUR);
                                    fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                                    fclose(f);
                                    cout << "student deleted\n";
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void delete_group_name()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char facname[20];
    char groupname[20];
    short year;
    cout << "enter faculty >> ";
    cin >> facname;
    cout << "enter course >> ";
    cin >> year;
    cout << "enter group you want to delete >> ";
    cin >> groupname;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(curr_fac.name, facname))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == year)
                {
                    for (size_t j = 0; j < 20; j++)
                    {
                        if (!strcmp(curr_fac.courses[i].groups[j].name, groupname))
                        {
                            curr_fac.courses[i].groups[j] = group();
                            fseek(f, -sizeof(curr_fac), SEEK_CUR);
                            fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                            fclose(f);
                            cout << "group deleted\n";
                            return;
                        }
                    }
                }
            }
        }
    }
}
void delete_course_year()
{
    faculty curr_fac;
    FILE *f = fopen("data", "r+b");
    char facname[20];
    short year;
    cout << "enter faculty >> ";
    cin >> facname;
    cout << "enter course you want to delete >> ";
    cin >> year;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(curr_fac.name, facname))
        {
            for (size_t i = 0; i < 10; i++)
            {
                if (curr_fac.courses[i].year == year)
                {
                    curr_fac.courses[i] = course();
                    fseek(f, -sizeof(curr_fac), SEEK_CUR);
                    fwrite(&curr_fac, sizeof(curr_fac), 1, f);
                    fclose(f);
                    cout << "course deleted\n";
                    return;
                }
            }
        }
    }
}
void delete_faculty_name()
{
    FILE *tempf = fopen("temp", "wb");
    FILE *f = fopen("data", "rb");
    faculty curr_fac;
    char facname[20];
    cout << "enter the faculty that you want to delete >> ";
    cin >> facname;
    while (fread(&curr_fac, sizeof(curr_fac), 1, f))
    {
        if (!strcmp(curr_fac.name, facname))
        {
            continue;
        }
        fwrite(&curr_fac, sizeof(curr_fac), 1, tempf);
    }
    fclose(f);
    fclose(tempf);
    remove("data");
    rename("temp", "data");
}
void delete_everyting()
{
    remove("data");
    FILE *f = fopen("data", "wb");
    fclose(f);
}