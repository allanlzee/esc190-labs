#include <string.h>
#include <stdio.h>

typedef struct student3 {
    char name[10]; 
    int age; 
} student3; 

// cannot create functions within struct
void change_name(student3 *s, char name[]) 
{
    int min = sizeof(s->name) < sizeof(name) ? sizeof(s->name) : sizeof(name);
    printf("%d", min);
    for (int i = 0; i < min - 1; i++){
        s->name[i] = name[i];
    }

    // deal with leftover chars
    for (int i = min; i < strlen(s->name); i++) {
        s->name[i] = '\0';
    }

    s->name[min - 1] = '\0';
}
