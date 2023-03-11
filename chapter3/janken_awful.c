#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));

  int rock = 0;
  int scissors = 1;
  int paper = 2;

  while (1)
  {
    // コンピューターの手を事前に決めておく
    int comp_hand = rand() % 3;
    printf("%d", comp_hand);

    printf("どの手を出しますか？ [0]グー [1] チョキ [2] パー : \n");
    int player_hand;
    scanf("%d", &player_hand);
    printf("あなた: %d コンピューター: %d", player_hand, comp_hand);

    int result = (player_hand - comp_hand) % 3;
    if (result == 0)
      printf("引き分けです\n");
    if (result == 1)
    {
      printf("あなたの負けです");
      break;
    }
    if (result == 2)
    {
      printf("あなたの勝ちです");
      break;
    }
  }

  return 0;
}