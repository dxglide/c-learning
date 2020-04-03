#include <stdio.h>
#include <time.h>
#include <math.h>
//Linux Libraries
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>



#define N 20
#define M 60

#define CCHAR '@'
#define BCHAR '*'
#define SCHAR ' '

// set cursor position  by current terminal window from upper left conner
//
//Linux Functions - These functions emulate some functions from the windows only conio header file
//Code: http://ubuntuforums.org/showthread.php?t=549023


void gotoxy(int x,int y)
{
   printf("%c[%d;%df",0x1B,y,x);
}


//http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
int kbhit(void)
	{
	  struct termios oldt, newt;
	  int ch;
	  int oldf;

	  tcgetattr(STDIN_FILENO, &oldt);
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON | ECHO);
	  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	  ch = getchar();

	  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	  fcntl(STDIN_FILENO, F_SETFL, oldf);

	  if(ch != EOF)
	  {
		ungetc(ch, stdin);
		return 1;
	  }

	  return 0;
}


char getch()
{
   char c;
   system("stty raw");
   c= getchar();
   system("stty sane");
   printf("%c",c);
   return(c);
}

void clrscr()
{
	system("clear");
	return;
}


char waitForAnyKey(void)
{
	int pressed;

	while(!kbhit());

	pressed = getch();
	//pressed = tolower(pressed);
	return((char)pressed);
}


int main()
{
 char pressed;
 printf("Press any key ... \n");
 
 do
 { 
     pressed = waitForAnyKey();
     pressed = tolower(pressed);
 } while (!(pressed == 'y' || pressed == 'n'));

 if (pressed == 'y')
 {
    clrscr(); //clear the console
    exit(1);
 }

 //gotoxy(1,2);

 printf("\n");
 return 0;

}

/*

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

*/


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
