#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("0~9の整数を当てよう!\n\n");

  int ans = rand() % 10 + 1;
  int no;

  // ここは無限ループだけどbreak文があるからそれで抜けられる
  while (1)
  {
    printf("いくつかな:");
    scanf("%d", &no);

    if (no > ans)
      printf("もっと小さいよ。\a\n");
    if (no < ans)
      printf("もっと大きいよ。\a\n");
    if (no == ans)
      break;
  };
  printf("正解です。\n");

  return 0;
}