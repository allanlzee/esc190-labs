#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //int* a = 1000;
    //*a = 7;
    double sum = 0.0; 
    char line[200];
    
    FILE *fp = fopen("a.txt", "r");
    if(!fp){
        printf("error");
    }
    while(fgets(line, sizeof(line), fp)) {
        sum += atoi(line);
        //printf("%f\n", sum);
    }

}