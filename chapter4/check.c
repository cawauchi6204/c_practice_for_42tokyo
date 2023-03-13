#include <string.h>
#include <ctype.h>

int check(const char s[])
{
  if (strlen(s) != 4)
    return 1;
  for (int i = 0; i < 4; i++)
  {
    // isdigitは10進数文字かを調べる
    if (!isdigit(s[i]))
      return 2;
    for (int j = 0; j < i; j++)
      if (s[i] == s[j])
        return 3;
  }

  return 0;
}