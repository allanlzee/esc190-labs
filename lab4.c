#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;

    if(str[i] == "-"){
        sign = -1;
        i++;
    }

    int result = 0;
    int passed_equal = 0; 

    for(int s = 0; s < strlen(str); s++) {
        if (passed_equal == 1) {
            // deal with decimal
            while((str[s + i] >= '0' && str[s + i] <= '9') || str[s+i] == '.') {
                if (str[s+i] != '.') {
                    result = result * 10 + (str[s + i] - '0');
                    //printf("%d\n", result);
                }
                i++;
            }
            printf("%f\n", result * sign);
            return result * sign; 
        }

        else if (str[s] == '=') {
            passed_equal = 1;
        }
    }
}

int sum(const char *filename) 
{
    float sum = 0.0; 
    char line[200]; 
    FILE *fp = fopen(filename, "r"); 

    while(fgets(line, sizeof(line), fp)) {
        sum += my_atoi(line);
        printf("%f\n", sum);
    }

    fclose(fp); 
    return sum;
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
    printf("%f", sum("lab4.txt"));
}