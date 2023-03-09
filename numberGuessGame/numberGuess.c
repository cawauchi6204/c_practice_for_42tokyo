#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE 10

int main(void)
{
  srand(time(NULL));

  const int max_stage = 10;

  int ans = rand() % 1000;
  int no;

  int num[MAX_STAGE];
  int stage = 0;

  printf("0~999の整数を当てよう!\n\n");
  // ここは無限ループだけどbreak文があるからそれで抜けられる
  do
  {
    printf("残り%dいくつかな:", MAX_STAGE - stage);
    scanf("%d", &no);
    // ここではstageとnumどちらも値を変化させている
    // 自分だったら以下のように書く(こっちの方がわかりやすいと思うから)
    // stage++
    // num[stage] = no;
    num[stage++] = no;

    if (no > ans)
      printf("もっと小さいよ。\a\n");
    if (no < ans)
      printf("もっと大きいよ。\a\n");
  } while (no != ans && stage < MAX_STAGE);

  if (no != ans)
    printf("残念。正解は%dでした", ans);
  else
  {
    printf("正解です。\n");
    printf("%d回で当たりましたね。\n", stage);
  }

  puts("\n---入力履歴---");
  for (int i = 0; i < stage; i++)
  {
    // ここの2dとか4dは桁数で出力時に空白を入れて表示をしてくれる
    // REF: https://9cguide.appspot.com/05-04.html
    printf("%2d : %4d %4d\n", i + 1, num[i], num[i] - ans);
  }

  return 0;
}