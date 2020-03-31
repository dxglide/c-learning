#include <stdio.h>
#include <limits.h>
#include <float.h>
/* Main  :) */
int main()
{
  unsigned long long ullmax = ULLONG_MAX;
  long lmax = LONG_MAX;
  long double ldmax = LDBL_MAX;
  
  printf("The max value of an unsigned long long is %Lu.\n", ullmax);
  printf("The max value of a long is %ld.\n", lmax);
  printf("The max value of a long double is %Lf.\n", ldmax);
 
  return 0;
}



