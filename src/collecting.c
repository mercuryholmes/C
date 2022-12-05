#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/function.h"

/* メニュー表示 */
static void menue(){
  option option[] = {
    {"[1]アトリエに戻る", atelier}
  };
  int count = sizeof option / sizeof option[0];
  _menue(option, count);
}

/* 採取画面 */
void collecting(){
  system("clear");
  puts("--- 採取画面 ---");
  while(getchar() == '\n'){
    // todo
    menue();
  }
}
