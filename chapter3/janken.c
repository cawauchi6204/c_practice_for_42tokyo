#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
  int draw;
  int lose;
  int win;
} Score;

char *hd[] = {"グー", "チョキ", "パー"};

void initialize(Score *s)
{
  // なんやこの書き方は
  // ポインタから取ってくるとこういう書き方する？
  s->win = s->lose = s->draw = 0;

  // srandをここで書く意味はある？
  // あーinitializeだからか
  srand(time(NULL));

  printf("じゃんけんゲーム開始!!\n");
}

void janken(int *h_hand, int *c_hand)
{
  *c_hand = rand() % 3;

  do
  {
    printf("\nじゃんけんポン....");
    for (int i = 0; i < 3; i++)
      printf("(%d)%s", i, hd[i]);
    printf(":");
    // ここでh_handのポインタを取ってきているからこれでいいのか
    // ここでメモリを渡している
    scanf("%d", h_hand);
  } while (!(*h_hand >= 0 && *h_hand <= 2));
}

// resultはただのint型
// *sはscoreで*sで受け取ることでメモリにアクセスできる
void update_score(Score *s, int result)
{
  switch (result)
  {
  // そのままメモリで値を加算している？
  case 0:
    s->draw++;
    break;
  case 1:
    s->lose++;
    break;
  case 2:
    s->win++;
    break;
  }
}

void disp_result(int result)
{
  switch (result)
  {
  case 0:
    puts("引き分けです。");
    break;
  case 1:
    puts("あなたの負けです。");
    break;
  case 2:
    puts("あなたの勝ちです");
    break;
  }
}

int confirm_retry(void)
{
  int x;

  printf("もう一度しますか.....(0)いいえ (1)はい:");
  scanf("%d", &x);

  return x;
}

int main(void)
{
  Score score;

  initialize(&score);

  int retry;

  do
  {
    int human;
    int comp;

    // ここでhumanとcompのメモリに値を入れている
    janken(&human, &comp);

    printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);
    int judge = (human - comp + 3) % 3;

    update_score(&score, judge);

    disp_result(judge);

    retry = confirm_retry();
    // はいを選んだら1が返されるので
  } while (retry == 1);

  printf("%d勝%d敗%d分けでした。\n", score.win, score.lose, score.draw);

  return 0;
}
