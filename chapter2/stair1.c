#include <stdio.h>

int main(void)
{
  int x;

  printf("段数：");
  scanf("%d", &x);

  for (int i = 1; i <= x; i++)
  {
    // for (int j = 1; j < i; j++)
    //   putchar(' ');
    // printf("%d\n", i % 10);
    printf("%*d\n", i, i % 10);
  }

  return 0;
}