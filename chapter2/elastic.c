#include <stdio.h>
#include <string.h>
#include <time.h>

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
  char name[] = "BohYoh Shibata";
  int name_len = strlen(name);

  while (1)
  {
    for (int i = 0; i < name_len; i++)
    {
      // printfは、整数や小数などのデータを文字列として整えて出力する関数です。 putcharは、1バイト文字の一文字を出力する関数です。
      putchar(name[i]);
      fflush(stdout);
      sleep(500);
    }
    for (int i = 0; i < name_len; i++)
    {
      printf("\b \b");
      fflush(stdout);
      sleep(500);
    }
  }

  return 0;
}