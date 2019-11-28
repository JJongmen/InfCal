#include <stdio.h>
#include <string.h>

int main(void){

        char str[] = "11 222 33 444 + - * ";
		

        char *ptr;
		char *one;
		char *two;
        int tmp;



        printf("함수 호출 전의 스트링 : %s\n" , str) ;



        //ptr = strtok(str, ",");

        //printf("%s\n" , ptr);



        ptr = strtok(str, " ");
		two = ptr;



        while(ptr != NULL ){



                printf( "%s\n" , ptr);
				one = two;
				two = ptr;
                ptr = strtok(NULL, " ");
				
				if (*ptr == '+'||*ptr == '-'||*ptr =='*') printf("one: %s ,two: %s, ptr = %s\n",one,two,ptr);

				
        }
		// 11 222 33 444 + - *
		// 11 222 (33 444 +) - *
        //printf("함수 호출 후의 스트링 : %s\n" , str);
        
        return 0;

}



