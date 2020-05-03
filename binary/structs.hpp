#ifndef __STRUCTS__
#define __STRUCTS__
typedef struct
{
    char first_name[20] = {0};
    char last_name[20] = {0};
    short marks[5] = {0};
} student;

typedef struct
{
    char name[20] = {0};
    student students[30];
} group;

typedef struct
{
    short year = 0;
    group groups[20];

} course;

typedef struct
{
    char name[20] = {0};
    course courses[10];
} faculty;

void add_student();
void change_data();
void delete_data();
void show_best_course();
void show_best_students();
void show_good_groups();
void show_all_students();
#endif