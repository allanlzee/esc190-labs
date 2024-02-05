#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "student1.h"
#include "student2.h"

void set_int1(int x) 
{
    x = 42; 
}

void set_int2(int *p_x) 
{
    *p_x = 42; 
}

void print_info(student1 s) 
{
    printf("%s\n", s.name); 
    printf("%s\n", s.student_number); 
    printf("%d\n", s.year); 
    printf("\n");
}

void print_info_2(student2 s) 
{
    printf("%s\n", s.name); 
    printf("%s\n", s.student_number); 
    printf("%d\n", s.year); 
    printf("\n");
}

void set_default_name(student1 *p_s) 
{
    strcpy(p_s->name, "Default Student"); 
    // & to pointer = pointer to a pointer
    p_s->year = 0; // same as (*personPtr).age
}

void set_default_name_wrong(student1 s)
{
    strcpy(s.name, "Default"); // locally defined
}

void create_block1(student1 **p_p_s, int n_students) 
{
    // pointer to the pointer of p_p_s
    // dereference pointer to its address (one level) to set its value 
    *p_p_s = (student1 *)malloc(sizeof(student1) * n_students);
    // malloc(): creates memory, returns address 
}

void set_name(student1 *s, char *s_name) 
{
    // dereference s, set its value to s_name
    strcpy(s->name, s_name);
}


void destroy_block1(student1 **p_p_s) 
{
    // pointer to the pointer of p_p_s
    // dereference one level (to pointer of p_p_s, free the address which is allocated)
    free(*p_p_s);
}

void create_block2(student2 **p_p_s, int num_students) 
{
    char *s = "0";
    strcpy((*p_p_s)->name, s);
    strcpy((*p_p_s)->student_number, s);
}


int main() 
{
    int x = 1; 
    set_int1(x); 
    printf("%d\n", x); // no effect, local variable 

    set_int2(&x);
    printf("%d\n\n", x); // effect, passing address, modifying value at address 

    student1 s; 
    strcpy(s.name, "Allan"); // need to copy into address
    strcpy(s.student_number, "1010147538"); // need to copy into address

    int year = 2024;
    s.year = year; // passing in a variable into s.year 
    print_info(s); 

    set_default_name(&s); 
    print_info(s);

    set_default_name_wrong(s); 
    print_info(s);

    student1 *s2; 
    printf("%d\n", s2);
    // pass in address of s2 to create block
    create_block1(&s2, 5); 
    printf("%d\n\n", s2); 
    // free memory at s2
    free(s2); 

    char *s_name = "Changed Allan"; 
    set_name(&s, s_name);
    print_info(s);

    student1 *s3 = (student1 *)malloc(sizeof(student1) * 2); 
    destroy_block1(&s3); // pass in address of the pointer to s3, deref one level 

    student2 **jomi; 
    
    create_block2(jomi, 0); 
    printf("Hello");
    print_info_2(**jomi);
    
}