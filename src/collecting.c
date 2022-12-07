#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/function.h"

#define MAX_COLLECT 5

/* メニュー表示 */
static void menue() {
    system("clear");
    puts("--- メニュー画面 ---");
    option options[] = {
    {"[1]アトリエに戻る", atelier},
    {"[2]カゴ", atelier},
    {"[3]閉じる", collecting},
    };
    int count = sizeof options / sizeof options[0];
    __menue(options, count);
}

/* 採取画面 */
void collecting() {
  system("clear");
  puts("--- 採取画面 ---");
  puts("[r]メニュー");

  static int count = 0;
	char key;

  while(1) {
    key = getchar();
    switch(key){
      case '\n':
        if (count == MAX_COLLECT) break;
        get_item_at_random();
        count++;
        if (count == MAX_COLLECT) printf("採取が完了しました");
        break;
      case 'r':
        menue();
        break;
    }
  }
}
