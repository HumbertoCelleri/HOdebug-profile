#include <stdlib.h>
#include <stdio.h>
#ifdef TRAPFPE
#include "fpe_x87_sse/fpe_x87_sse.h"
#endif

int main(int argc, char *argv[])
{
  /**
  * This program recibes via printf: 2 floats and makes the division
  *
  */

  float a, b, c, tmp;

#ifdef TRAPFPE
  set_fpe_x87_sse_();
#endif

  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = a / b;

  c = tmp;

  printf("c = %f \n", c);

  return(EXIT_SUCCESS);
}
