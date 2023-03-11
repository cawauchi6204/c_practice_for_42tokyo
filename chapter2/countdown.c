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
  for (int i = 10; i > 0; i--)
  {
    printf("\r%2d", i);
    fflush(stdout);
    sleep(1000);
  }
  printf("\rFIRE!!\a\n");
  // clock関数はプログラム開始からの経過時間を求める関数
  printf("プログラム開始から%.1f秒経過しました。\n", (double)clock() / CLOCKS_PER_SEC);

  return 0;
}