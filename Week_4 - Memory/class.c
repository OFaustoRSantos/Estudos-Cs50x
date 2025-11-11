#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void main(){
    int n = 50;
    int *p = &n; // Address of N, no matter what n is
    printf("%i, \n", n); // or use *p OBS.: *p is to found what is in the address in *p
    printf("%p \n", p); // or use &n. OBS.: Memory is dynamic so if you re-inicialize the code is possible to the address change
    // points cost more than int in memory space due to use more bits

    // How can I use pointer?
    string s = "HI!"; // every string have a \0 after the last caracter to show where it stop
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    // pointer just found 

    typedef struct{ // struct == what have in the new data type
        string name
        string number
    } person // name of data type

    // cs50 have a typedef char * string; a pointer that shows the first caracter point
    // [i] is just a way to be a better/frindly way to ask what have in the [pointer + i]. the last component of the array probably have a structure showing it, due to it the arrays need to have a fixed size
    // Using strcmp is a way to compare two strings
 
    int *x = malloc(3 * sizeof(int)); // sizeof is interessant function to allocate space
    // AMAZING! Is that what arrays are?
    //Example using a function.
    // After use memory in the x[0], x[1], x[2];
    free(x);
    // valgrind a way to check memory related mistakes. it's possible to have leaks in the program
}

int compare_string(){ // How I think compare strings work
    char *s = get_string("S:");
    char *t = get_string("S:");

    if(strlen(s) != strlen(t)){
    return 1;
    }
    for(int i = 0; i<s; i++){
	    if(*(s+i) != *(t+1)){
	        return 2;
	    }
    }
    return 0;
}

int copy_string(){
    char *s = get_string("original: ");
    // that's what strcpy do! 52-57.
    char *t = malloc(strlen(s) + 1); //alocate a space in the memory for the pointer insert data/information
    // if something got wrong you will see NULL

    for(int i=0; i <= strlen(s); i++){
        t[i] = t[i];
    }
    
    t[1] = toupper(t[1]);

    // You need to be careful because have the possibility to things go WRONG!, so be inteligent in if/else uses
    // after use it it's important to free the space
    
}

void get(int n){
    char s[n];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}

void filestructure(void){
    FILE *file = fopen("phonebook.csv", "a");
    if (!file)
    {
        return 1;
    }

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}