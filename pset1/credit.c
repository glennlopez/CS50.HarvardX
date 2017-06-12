//test cards - https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
#include<stdio.h>
#include<cs50.h>

//prototypes
long long get_posLongLong(void);
int countDigits(long long param);
void checkType(int param[], int);




int main(){

    
    long long cc_number = get_posLongLong();
    int digitCount = countDigits(cc_number);
    int ccNum[digitCount];
    
    
    //store each card digit inside array ccNum[...]
    unsigned long long nextCardDigit = 1;
    for(int i = 0; i < countDigits(cc_number); i++){
        ccNum[i] = ((cc_number%(10 * nextCardDigit))/(1 * nextCardDigit));
        nextCardDigit *= 10;    //iterate through the next digit
    }
    
    checkType(ccNum, digitCount);
    
    return 0;
}





//check get_long_long() for positive number
long long get_posLongLong(void){long long posInt = -9;
    do{
        printf("Number: ");
        posInt = get_long_long();
    //}while( (posInt <= 0) || (countDigits(posInt) < 12)); //min valid cc_number is 12
    }while(posInt <= 0);
    
    return posInt;
}


//check the type of cc used
void checkType(int ccNum[], int digitCount){
    
    int checksum = -9999;
    int sumOfProduct = 0; //sum of digits multiplied by 2
    int sumOfdigits = 0; //sum of digits NOT multiplied by 2
    int n = 0;

    //CHECKSUM ROUTINE 
    for(int i = 0; i < (digitCount/2); i++){
        if((ccNum[1 + n] * 2) >= 10){
            sumOfProduct += ((ccNum[1 + n] * 2)%10);
            sumOfProduct += ((ccNum[1 + n] * 2)/10);
        }
        else{
            sumOfProduct += (ccNum[1 + n] * 2);
        }
        n += 2;
    }

    int adjust = 0;
    if(digitCount % 2){
        adjust = 1;
    }    

    n = 0;
    for(int i = 0; i < (digitCount/2) + adjust; i++){
        sumOfdigits += (ccNum[n]);
        n += 2;
    }
    
    // CARD TYPE CHECK
    checksum = (sumOfProduct + sumOfdigits) % 10;
    if(checksum == 0){
        //VISA - 13 and 16 digits (4)
        if( (digitCount == 13) || (digitCount == 16) ){
            if(ccNum[digitCount-1] == 4){
                printf("VISA\n");
            }    
        }//END VISA CHECK
        
        //MASTERCARD - 16 digits (51,52,53,54,55)
        if(digitCount == 16){
            if(ccNum[digitCount-1] == 5){
                if( (ccNum[digitCount-2] >= 1) || (ccNum[digitCount-2] <= 5) ){
                    printf("MASTERCARD\n");
                }
            }
            
        }//END MASTERCARD CHECK
        
        //AMEX - 15 digits (34,37)
        if(digitCount == 15){
            if(ccNum[digitCount-1] == 3){
                if( (ccNum[digitCount-2] == 4) || (ccNum[digitCount-2] == 7) ){
                    printf("AMEX\n");
                }
            }
        } //END AMEX CHECK

    }
    else{
        printf("INVALID\n");
    }
}



//check the number of digits in cc_number
int countDigits(long long param){
    if (param < 10) return 1;               
    if (param < 100) return 2;             
    if (param < 1000) return 3;            
    if (param < 10000) return 4;           
    if (param < 100000) return 5;          
    if (param < 1000000) return 6;         
    if (param < 10000000) return 7;        
    if (param < 100000000) return 8;       
    if (param < 1000000000) return 9;      
    if (param < 10000000000) return 10;    
    if (param < 100000000000) return 11;    
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