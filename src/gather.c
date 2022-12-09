#include <stdio.h>
#include <stdlib.h>
#include "include/function.h"
#include "include/define.h"
#include "include/struct.h"

static int count = 0;

/* メニュー表示 */
static void menue() {
    system("clear");
    puts("--- メニュー画面 ---");
    option options[] = {
      {"[1]アトリエに戻る", atelier}, {"[2]カゴ", atelier},
      {"[3]閉じる", gather}
    };
    int count = sizeof options / sizeof options[0];
    __menue(options, count);
}

/* フィールド画面 */
void field() {
  // 採取した回数を初期化
  count = 0;
  gather();
}

/* 採取画面 */
void gather() {

  system("clear");
  puts("--- 採取画面 ---");
  puts("[r]メニュー");

	char key;
  while(1) {
    key = getchar();
    switch(key){
      case '\n':
        if (count == MAX_COLLECT_COUNT) break;
        get_item_at_random();
        if (++count == MAX_COLLECT_COUNT) {
          puts("");
          printf("採取が完了しました");
        }
        break;
      case 'r':
        menue();
        break;
    }
  }
}
