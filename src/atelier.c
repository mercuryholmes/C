#include <stdio.h>
#include <stdlib.h>
#include "include/function.h"
#include "include/struct.h"

/* メニュー表示 */
static void menue() {
  option options[] = {
    {"[1]採取", field}, {"[2]調合", synthesis}
  };
  int count = sizeof options / sizeof options[0];
  __menue(options, count);
}

/* 読み込み */
static void preload() {
  // todo ここでカゴを表示する関数を呼び出し
  // イベント関数などあれば作成する
}

/* アトリエ画面 */
void atelier(){
  system("clear"); 
  puts("--- アトリエ ---");
  preload();
  menue();
}
