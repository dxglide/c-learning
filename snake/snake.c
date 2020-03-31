#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define N 20
#define M 40

#define BCHAR '*'

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

 for(i=0; i<M+1; i++) 
 {
   printf("border sim: %c", BCHAR);

 }

 printf("border sim: %c", BCHAR);

 printf("\n");
 return 0;

}



