#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void make4digits(int x[])
{
  for (int i = 0; i < 4; i++)
  {
    int j, val;
    do
    {
      val = rand() % 10;
      for (j = 0; j < i; j++)
        if (val == x[j])
          break;
    } while (j < i);
    x[i] = val;
  }
}

int main(void)
{
  srand(time(NULL));
  int digits[4];
  make4digits(digits);
  for (int i = 0; i < 4; i++)
  {
    printf("%d", digits[i]);
  };

  return 0;
}