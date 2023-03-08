#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));
  printf("0~999の整数を当てよう!\n\n");

  int ans = rand() % 1000;
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