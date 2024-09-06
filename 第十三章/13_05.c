#include <stdio.h>
int main(int argc, char *argv[])
{
  int result = 0; 

  for (int i = 1; i < argc; i++)
		result += atoi(argv[i]);
  printf("Result: %d\n",result);
  return 0;
}
