#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student3.h"

float my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;

    if(str[i] == '-'){
        sign = -1;
        i++;
    }

    int result = 0;
    int passed_equal = 0; 
    int passedDot = 0;
    int divider = 1;
    for(int s = 0; s < strlen(str); s++) {
        if (passed_equal == 1) {
            // deal with decimal
            while((str[s + i] >= '0' && str[s + i] <= '9') || str[s+i] == '.') {
                if (passedDot == 1){
                    divider *= 10;
                }
                if (str[s+i] != '.') {
                    result = result * 10 + (str[s + i] - '0');
                    //printf("%d\n", result);
                }
                else{passedDot=1;}
                i++;
                
            }
            printf("%d\n", result * sign);
            return (float)(result * sign)/(float)divider; 
        }

        else if (str[s] == '=') {
            passed_equal = 1;
        }
    }
}

float sum(const char *filename) 
{
    double sum = 0.0; 
    char line[200]; 
    FILE *fp = fopen(filename, "r"); 

    while(fgets(line, sizeof(line), fp)) {
        sum += my_atoi(line);
        printf("%f\n", sum);
    }

    fclose(fp); 
    return sum;
}

// Question 3 
void change_name1_wrong(student3 s) 
{
    // s acts like a local variable, it is lost after the function ends
    s.name[0] = 'b'; 
}

void change_name1_right_a(student3 *p_s)
{
    // passes a pointer for student3 into the function
    // correctly dereferences the pointer to the student, assigns it the char array 
    // modifies addresses, NOT local variables 
    p_s->name[0] = 'b';
}

void change_name1_right_b(student3 *p_s) 
{
    // same idea as above
    strcpy(p_s->name, "b");
}


int main() 
{
    /*
    char *a = (char *)malloc(10); 
    printf("Value: %c\n", a[5000000]);
    free(a);
    */

    /*
    char *p = (char *)malloc(10); 
    printf("%s\n", p); // no null, will keep printing (unless one of the chars is randomly \0)
    free(p);
    */

    // seg fault: access area of memory it was not supposed to access 
    //printf("%f", sum("lab4.txt"));

    student3 *quinn;
    change_name1_right_a(quinn);
    printf("%c\n", quinn->name[0]);

    char name[5] = "Allan"; 
    student3 *allan; 
    change_name(allan, name);
    printf("%s", allan->name);
}