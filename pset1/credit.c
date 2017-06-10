//test cards - https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
#include<stdio.h>
#include<cs50.h>

long long get_posLongLong(void);
int countDigits(long long param);

int main(){

    
    //int next = 100;
    //int x = 4324%(10 * next);
    //int y = x/(1 * next);
    //printf("%i\n", y);
    
    long long cc_number = get_posLongLong();
    int debug = countDigits(cc_number); //debug
    for(int i = 0; i < countDigits(cc_number); i++){
        printf("Credit Card(%i): %lld\n", debug, cc_number);  //debug
    }

    
    return 0;
}



//check get_long_long() for positive number
long long get_posLongLong(void){long long posInt = -9;
    do{
        printf("Number: ");
        posInt = get_long_long();
    //}while( (posInt <= 0) || (countDigits(posInt) < 12));
    }while(posInt <= 0);
    
    return posInt;
}

//check the number of digits in cc_number
int countDigits(long long param){
    if (param < 10) return 1;               // INVALID 
    if (param < 100) return 2;              // INVALID
    if (param < 1000) return 3;             // INVALID
    if (param < 10000) return 4;            // INVALID
    if (param < 100000) return 5;           // INVALID
    if (param < 1000000) return 6;          // INVALID
    if (param < 10000000) return 7;         // INVALID
    if (param < 100000000) return 8;        // INVALID
    if (param < 1000000000) return 9;       // INVALID
    if (param < 10000000000) return 10;     // INVALID
    if (param < 100000000000) return 11;    // Dankort (PBS)
    // minimum length on a cc is 12 digits
    if (param < 1000000000000) return 12;
    if (param < 10000000000000) return 13;
    if (param < 100000000000000) return 14;
    if (param < 1000000000000000) return 15;
    if (param < 10000000000000000) return 16;
    if (param < 100000000000000000) return 17;
    if (param < 1000000000000000000) return 18;
    // maxumum length on a cc & long long is 19 digits
    return 19;
}