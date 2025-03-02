#include <stdio.h>

struct student {
    int id;
    char name[100];
    float gpa;
};

int main(void) {
    struct student s1, s2, s3;

    s1.id = 123;
    s2.id = 456;
    s3.id = 789;

    strcpy(s1.name, "John Smith");
    strcpy(s2.name, "Jane Doe");
    strcpy(s3.name, "Bob Johnson");

    s1.gpa = 3.5;
    s2.gpa = 3.7;
    s3.gpa = 4.0;

    printf("Student 1:\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);

    printf("Student 2:\n");
    printf("ID: %d\n", s2.id);
    printf("Name: %s\n", s2.name);
    printf("GPA: %.2f\n", s2.gpa);

    printf("Student 3:\n");
    printf("ID: %d\n", s3.id);
    printf("Name: %s\n", s3.name);
    printf("GPA: %.2f\n", s3.gpa);

    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
