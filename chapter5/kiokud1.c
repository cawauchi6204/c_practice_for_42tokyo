#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE 10

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
  int success = 0;

  srand(time(NULL));

  printf("4桁の数値を記憶しよう!!\n");

  time_t start = time(NULL);

  for (int stage = 0; stage < MAX_STAGE; stage++)
  {
    int x;
    int no = rand() % 10000;

    printf("%d", no);
    fflush(stdout);
    sleep(500);

    printf("\r入力せよ");
    fflush(stdout);
    scanf("%d", &x);

    if (x != no)
      printf("間違いです。\n");
    else
    {
      printf("正解です。\n");
      success++;
    }
  }
  time_t end = time(NULL);

  printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
  printf("%.1f秒でした。\n", difftime(end, start));

  return 0;
}