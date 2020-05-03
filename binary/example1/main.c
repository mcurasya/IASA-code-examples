#include <stdio.h>
#include <string.h>

typedef struct
{
    char first_name[20];
    char last_name[20];
} record;

int main(int argc, char const *argv[])
{
    record rec;
    FILE *f = fopen("data.dat", "r+b");//open file
    if (!f) //check if file does not exists and if so create one
    {
        fclose(f);
        f = fopen("data.dat", "wb");
        fclose(f);
        f = fopen("data.dat", "r+b");
    }
    int i = 1;
    while (fread(&rec, sizeof(record), 1, f)) // read file struct by struct and print it out
    {
        printf("%d) %s %s\n", i++, rec.first_name, rec.last_name);
    }
    //ask for new record
    char new_first_name[20];
    char new_last_name[20];
    puts("enter new  name");
    scanf("%s%s", new_first_name, new_last_name);
    //create new record and copy data
    record new_rec; 
    strcpy(new_rec.first_name, new_first_name);
    strcpy(new_rec.last_name, new_last_name);
    fwrite(&new_rec, sizeof(record), 1, f);
    fclose(f);

    return 0;
}
