

namespace structs{

struct student{
	char last_name[15];
	short marks[10];
};

struct faculty {
    char name[10];
    int course;
};

struct record {
	faculty fac;
	student stud;
};

}


//finished
