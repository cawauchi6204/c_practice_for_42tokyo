#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));

  const int max_stage = 10;
  int remain = max_stage;

  int ans = rand() % 1000;
  int no;

  printf("0~999の整数を当てよう!\n\n");
  // ここは無限ループだけどbreak文があるからそれで抜けられる
  do
  {
    printf("いくつかな:");
    scanf("%d", &no);
    remain--;

    if (no > ans)
      printf("もっと小さいよ。\a\n");
    if (no < ans)
      printf("もっと大きいよ。\a\n");
  } while (no != ans && remain > 0);

  if (no != ans)
    printf("残念。正解は%dでした", ans);
  else
  {
    printf("正解です。\n");
    printf("%d回で当たりましたね。\n", max_stage - remain);
  }

  return 0;
}