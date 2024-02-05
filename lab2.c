#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input(char **s, int *length) // char **
{ 
    printf("How many chars will you input: "); 
    scanf("%d", length);
    s = (char *) malloc(sizeof(char) * (*length) + 1); 
    
    int i = 0;
    printf("Input the chars one-by-one:\n"); 
    while (i < *length) {
        printf("char: ");
        scanf(" %c", &s[i]); // space ignores new lines (and leading whitespace)
        i++;
    } 
    s[*length] = '\0';

    for (int i = 0; i < *length; i++) {
        printf("%c", s[i]); 
    }
    
    free(s);
}

void print_str(char *s) 
{
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]); 
        i++;
    }
    printf("\n");
}

// Concatenating functions 
char* concat(char *s1, char *s2) 
{
    char *conc = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));

    for (int i = 0; i < strlen(s1); i++) {
        conc[i] = s1[i]; 
    }

    for (int i = 0; i < strlen(s2); i++) {
        conc[i + strlen(s1)] = s2[i]; 
    }

    conc[strlen(s1) + strlen(s2)] = '\0';

    return conc;
}


// Concatenating functions 
char* concat_point(char *s1, char *s2) 
{
    char *conc = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));

    for (int i = 0; i < strlen(s1) + strlen(s2); i++) {
        if (i < strlen(s1)) {
            *(conc + i) = *(s1 + i);
        } else {
            *(conc + i) = *(s2 + i - strlen(s2) - 1);
        }
    }

    conc[strlen(s1) + strlen(s2)] = '\0';
    return conc;
} // memcpy - take chunk of memory and copy to location 


// Comparing Strings 
// Return 1 if strings are equal, return 0 is strings are different 
int strcomp(const char* s1, const char* s2) 
{
    int l1 = strlen(s1);
    int l2 = strlen(s2); 

    if (l1 != l2) return 0; 

    for (int i = 0; i < l1; i++) {
        if (s1[i] != s2[i]) return 0;
    }

    return 1;

    // differences: be careful of comparing addresses 
    // comparing first element address (does not necessarily mean the rest of the string is right)
}

int str_comp(const char* s1, const char* s2) 
{
    if (s1[0]>s2[0]){
        return 1;
    }
    if (s1[0]<s2[0]){
        return -1;
    }
    return str_comp(s1+1,s2+1);
}

// Convert string to integer
int my_atoi(char *str)
{
    if (isdigit(*str)) {
        return *str - '0';
    } else {
        return -1;
    }
}


int main() 
{
    char *s;
    int length;
    // input(s, &length);

    char *s1 = "hello "; 
    char *s2 = "world"; 
    char *s3 = "hello ";

    char *conc = concat_point(s1, s2);
    
    print_str(conc); 
    free(conc);
    
    printf("%d", strcomp(s1, s3));

    printf("\n");
    char *s_c = "9";
    printf("%d", my_atoi(s_c));

    // NO MORE RUNNING GONNA KILL MY RAM!
}