#include <string.h>
#include <stdio.h>

typedef struct student3 {
    char name[10]; 
    int age; 
} student3; 

// cannot create functions within struct
void change_name(student3 *s, char name[]) 
{
    for (int i = 0; i < sizeof(s->name); i++) {
        s->name[i] = '\0';
    }

    int min = sizeof((char *)s->name) < sizeof((char *)name) ? sizeof((char *)s->name) : sizeof((char *)name);
    for (int i = 0; i < min; i++){
        s->name[i] = name[i];
    }
}
