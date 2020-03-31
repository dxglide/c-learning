#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define N 20 
#define M 60

#define CCHAR '@'
#define BCHAR '*'
#define SCHAR ' '

/*
void printAscii()
{
  unsigned char count;
    for(count=32; count< 255; count+=1)
    {
        printf("  %3d - %c",count,count);
        if(count % 6==0)
            printf("\n");
    }
    printf("\n");

}
*/
int main()
{
 int i,j; 
 for(i=0; i<=M+1; i++){
   if (i==0){
     printf("%c", CCHAR);
   } else if (i==M+1) {
     printf("%c", CCHAR);
   } else {
      printf("%c", BCHAR);
   }
 }
 
 printf("\n");
 
 for(i=0; i<N; i++){
    printf("%c", BCHAR);
    for(j=1; j<=M+1 ; j++) {
      if (j==M+1) {
        printf("%c\n", BCHAR);
      } else {
        printf("%c", SCHAR); 
      }  
    }
 } 
   
// printf("\n");

 for(i=0; i<=M+1; i++){
   if (i==0){
     printf("%c", CCHAR);
   } else if (i==M+1) {
     printf("%c", CCHAR);
   } else {
      printf("%c", BCHAR);
   }
 }


 printf("\n");
 return 0;

}



