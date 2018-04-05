#include <stdio.h>
#include <cs50.h>
/*
    Video: https://edx-video.net/HARCS50X2016-V028700_DTH.mp4
    Notes: https://docs.cs50.net/2017/fall/notes/4/lecture4.html#memory
*/

int main(){

    // fixed string (Hello: ) - stack
    char *greet = "Why, hello there ";

    // user string (%name%) - stack
    char *uName = get_string("Name: ");

    // calculate length of uName and Greet
    int charCnt = 0;
    for(int i = 0; uName[i] != '\0'; i++){
        charCnt++;
    }

    for(int i = 0; greet[i] != '\0'; i++){
        charCnt++;
    }

    // memory alocation
    char *uNameGreet = malloc(charCnt * sizeof(char));

    //copy stack content to heap
    int CpyIndex = 0;
    for(int i = 0; greet[i] != '\0'; i++){
        uNameGreet[i] = greet[i];
        CpyIndex++;
    }
    for(int i = 0; uName[i] != '\0'; i++){
        uNameGreet[CpyIndex + i] = uName[i];
    }


    printf("uNameGreet: %s\n", uNameGreet);
    free(uNameGreet);



    printf("\n");
    return 0;
}