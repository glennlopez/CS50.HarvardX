#include<stdio.h>
#include<cs50.h>

struct student{
    char *name;
    char gender;
};

int main(){
    
    struct student stu01; 
    
    stu01.name = "Glenn Lopez";
    
    printf("\n");
    return 0;
}