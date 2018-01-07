#include <cs50.h>
#include <stdio.h>

bool isMatching(char[], char[]);


int main(){

    string a = "rofl";

    char key[5];

    key[0] = '@'; key[1] = '\0';
    for(int i = 0; key[0] != '{'; i++){
        key[0] += 1;

        key[1] = '@'; key[2] = '\0';
        for(int j = 0; key[1] != '{'; j++){
            key[1] += 1;

            key[2] = '@'; key[3] = '\0';
            for(int k = 0; key[2] != '{'; k++){
                key[2] += 1;

                key[3] = '@'; key[4] = '\0';
                for(int k = 0; key[3] != '{'; k++){
                    printf("%s\n", key);

                    if( isMatching(a, key) ){
                        printf("Match! \n");
                        return 0;
                    }


                    key[3] += 1;
                }
            }
        }
    }

    return 0;
}



bool isMatching(char inputHash[], char generatedHash[]){

    //count character length
    unsigned int inputLen = 0;
    for(int i = 0; inputHash[i] != '\0'; i++){
        inputLen++;
    }
    unsigned int generatedLen = 0;
    for(int i = 0; generatedHash[i] != '\0'; i++){
        generatedLen++;
    }

    //check string length for missmatch
    if( !(inputLen == generatedLen) ){
        return false;
    }

    //check char for missmatch
    for(int i = 0; i < inputLen; i++){
        if(inputHash[i] != generatedHash[i]){
            return false;
        }
    }

    //return true if everything is the same
    return true;
}