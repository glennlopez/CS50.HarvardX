//https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
#include <stdio.h>
#include <cs50.h>

//FIXME: fwrite doesnt write to the txt file Read more into how fwrite works
/*

#include<stdio.h>

int main () {
   FILE *fp;
   char str[] = "This is tutorialspoint.com";

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);
  
   return(0);
}

*/

int main(){

    char *FIXED = "testing...";

    FILE *fp;
    char *buffer;
    size_t sz;

    fp = fopen("log_fwrite.txt", "w");
    buffer = malloc( (sizeof(char) * 50) + 1 );

    for(int i = 0; FIXED[i] != '\0'; i++){
        buffer[i] = FIXED[i];
    }

    sz = fwrite(buffer, sizeof(char), 50, fp);

    printf("\n");
    return 0;
}