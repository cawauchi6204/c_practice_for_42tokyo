#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char temp[1024];

  printf("整数を入力せよ：");
  scanf("%s", temp);
  printf("%sと入力しましたね。\n", temp);

  return 0;
}