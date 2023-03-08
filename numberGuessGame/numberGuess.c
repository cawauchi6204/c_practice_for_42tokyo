#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("0~9の整数を当てよう!\n\n");

  int ans = rand() % 10 + 1;
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