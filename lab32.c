#include <stdio.h> 
#include "student1.h"
#include "student2.h"
#include <string.h> 
#include <stdlib.h>


void create_block2(student2 **p_p_s, int num_students) 
{
    *p_p_s = (student2 *)malloc((num_students) * sizeof(student2));

    for (int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }
}

void print_info_2(student2 s) 
{
    printf("%s\n", s.name); 
    printf("%s\n", s.student_number); 
    printf("%d\n", s.year); 
    printf("\n");
}

void set_name2(student2 *s, char *s_name) 
{
    (*s).name = (char *)malloc((sizeof(s_name) / sizeof(s_name[0])) * sizeof(char) + 1);
    strcpy(s->name, s_name);
}

void destroy_block2(student2 **s) 
{
    free((*s)->name); 
    // free((*s)->student_number);

    free(*s);
}

void pass_student1(student1 s) 
{
    strcpy(s.name, "Hello"); // local variable s
}

void pass_student2(student2 **s) 
{
    strcpy((*s)->name, "Jomi");
}

void print_file(const char *filename, int N) 
{
    char line[200];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
    fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
    //(including ’\0’) into line.
    }
    fclose(fp);
}

float average_integers(const char *filename) 
{
    float average = 0.0;
    int nums = 0;
    char line[200];
    FILE *fp = fopen(filename, "r");
    while(fgets(line, sizeof(line), fp)) {
        average += (int) atoi(line);
        printf("%d\n", (int) atoi(line));
        nums++; 
    }
    fclose(fp);

    return average / (nums);
}


int main() 
{
    student2 *jomi; 
    create_block2(&jomi, 3);

    print_info_2(jomi[0]);

    char *name = "Joseph"; 
    set_name2(&(jomi[0]), name);

    print_info_2(jomi[0]);

    free(jomi->name);
    free(jomi);
    
    student1 allan; 
    strcpy(allan.name, "Allan");
    printf("%s\n", allan.name);

    pass_student1(allan);
    printf("%s\n\n", allan.name);

    printf("%f", average_integers("average.txt"));

}