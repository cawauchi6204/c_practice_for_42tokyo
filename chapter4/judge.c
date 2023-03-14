// constを使うことで変数を読み取り専用にすることができます。
// また、ポインタ変数に使うことでアドレスを書き換え不能にしたり、アドレス先の値を書き換え不能にできます。
void judge(const char s[], const int no[], int *hit, int *blow)
{
  *hit = *blow = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (s[i] == '0' + no[j])
      {
        if (i == j)
          (*hit)++;
        else
          (*blow)++;
      }
    }
  }
}