//
//  main.c
//  EncryptDecrypt
//
//  Created by Arman Tarkhanian on 7/17/14.
//  Copyright (c) 2014 Arman Tarkhanian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//void getString(char * a);

int main(int argc, const char * argv[])
{
    int answer;
    int character;
    char password[50];
    int passwordLetterSum=0;
    do
    {
        printf("Enter your choice:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n>");
        scanf("%d",&answer);
        if (answer == 1)
        {
            printf("What would you like the password to be (max 50)?\n>");
            scanf("%s",password);
            for(int i=0;i<(int)strlen(password);i++)
            {
                passwordLetterSum+=(int)password[i];
                if (passwordLetterSum>127)
                    passwordLetterSum=passwordLetterSum - (password[i]+1);
            }
            while(getchar()!='\n');
            printf("Enter your message that you want to encrypt.\nType return to end your message.\n");
            while((character=getchar())!='\n')
            {
                character = character + passwordLetterSum;
                printf("%lc",character);
            }
        }
        else if (answer == 2)
        {
            printf("What is the password?\n");
            scanf("%s",password);
            for(int i=0;i<(int)strlen(password);i++)
            {
                passwordLetterSum+=(int)password[i];
                if (passwordLetterSum>127)
                    passwordLetterSum=passwordLetterSum - (password[i]+1);
            }
            while(getchar()!='\n');
            printf("Enter your message that you want to decrypt.\nType return to end your message.\n");
            while((character=getchar())!='\n')
            {
                character = character - passwordLetterSum;
                printf("%lc",character);
            }
            
        }
        else{
            printf("Under construction");
        }
        printf("\n");
        printf("Type 1 to repeat and anything else to quit.\n");
        scanf("%d",&answer);
    }while (answer==1);
    return 0;
}
/*void getString(char * a)
 {
 while((*a++=getchar())!='\n');
 *(--a)='\0';
 }*/

