#include <time.h>
#include <stdio.h>

int sleep(unsigned long x)
{
  clock_t c1 = clock(), c2;

  do
  {
    if ((c2 = clock()) == (clock_t)-1)
      return 0;
  } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

  return 1;
}

int main(void)
{
  printf("ABCDEFG");

  for (int i = 0; i < 7; i++)
  {
    sleep(1000);
    // 後ろから1文字ずつ削除する
    // 1. \bでカーソルを一文字後退させる
    // 2. ''文字で選択されている文字を空にする
    // 3. \bでカーソルを一文字後退させる
    printf("\b \b");
    fflush(stdout);  // バッファを吐き出すらしい
  }

  return 0;
}