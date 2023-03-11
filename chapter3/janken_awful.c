#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  char *hd[] = {"グー", "チョキ", "パー"};

  srand(time(NULL));

  while (1)
  {
    // コンピューターの手を事前に決めておく
    int comp_hand = rand() % 3;
    printf("%d", comp_hand);

    printf("どの手を出しますか？ [0] %s [1] %s [2] %s : \n", hd[0], hd[1], hd[2]);
    int player_hand;
    scanf("%d", &player_hand);
    printf("あなた: %s コンピューター: %s\n", hd[player_hand], hd[comp_hand]);

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