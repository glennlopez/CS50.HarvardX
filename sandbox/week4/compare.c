#include <stdio.h>
#include <cs50.h>

int stringCount(char *param);
bool compareString(char *param1, char *param2);

//simple function for comparing strings

int main(){

    string s = "Glenn";
    string t = "GleNn";

    //compare string size first
    if(stringCount(s) != stringCount(t)){
        printf("Does not match! \n");
        return 0;
    }

    //compare char if string size matches
    if(compareString(s, t) == 1){
        printf("Matches!\n");
    }
    else{
        printf("No Match!\n");
    }
    return 0;
}

//COMPARE CHAR
bool compareString(char *param1, char *param2){ bool result = 1;
    for(int i = 0, n = stringCount(param1); i < n; i++){
        if(param1[i] != param2[i]){
            result = 0;
        }
    }
    return result;
}


//COUNT STRING SIZE
int stringCount(char *param){   int i = 0;
    for(i = 0; param[i] != '\0'; i++);
    return i;
}