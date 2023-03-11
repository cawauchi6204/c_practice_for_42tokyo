#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));

  int a = 100 + rand() % 900;
  int b = 100 + rand() % 900;
  int c = 100 + rand() % 900;

  printf("%d + %d + %dはなんですか:", a, b, c);
  // clock()関数である。 初めに断っておくが、この関数は、「時刻」を扱う関数ではないし、 「実時間」を扱う関数でもない。「 CPU 時間」を扱う関数である。
  time_t start = time(NULL);

  while (1)
  {
    int x;
    scanf("%d", &x);
    if (x == a + b + c)
      break;
    printf("\a違いますよ!\n再入力してください:");
  }
  time_t end = time(NULL);
  double req_time = difftime(end, start);

  printf("%.1f秒かかりました。\n", req_time);

  if (req_time > 30.0)
    printf("時間がかかりすぎです。\n");
  else if (req_time > 17.0)
    printf("まあまあですね。\n");
  else
    printf("素早いですね。\n");

  return 0;
}