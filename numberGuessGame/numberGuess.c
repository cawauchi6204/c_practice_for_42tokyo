#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));
  printf("0~999の整数を当てよう!\n\n");

  int ans = rand() % 1000;
  int no;

  do
  {
    printf("いくつかな:");
    scanf("%d", &no);

    if (no > ans)
      printf("もっと小さいよ。\a\n");
    if (no < ans)
      printf("もっと大きいよ。\a\n");
  } while (no != ans);
  printf("正解です。\n");

  return 0;
}