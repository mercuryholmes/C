#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/function.h"

/* キーボード入力 */
void select_key(option* option, int count){
  while(1) {
    char key[10];
    fgets(key, 10, stdin);
    int i = atoi(key);
    // 入力チェック
    if (i < 1) continue;
    if (i > count) continue;
    // 選択した場合
    i--;
    option[i].action(&option[i]);
  }
}

/* メニューウィンドウの表示 */
void _menue(option* option, int count){

  for (int i=0;i<count; i++) {
    printf("%s\n", option[i].name);
  }

  select_key(option, count);
}
