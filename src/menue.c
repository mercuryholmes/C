#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/function.h"

/* キーボード入力 */
void select_key(option* options, int count){
  while(1) {
    char key[10];
    fgets(key, 10, stdin);
    int i = atoi(key);
    // 入力チェック
    if (i < 1) continue;
    if (i > count) continue;
    // 選択した場合
    i--;
    options[i].action(&options[i]);
  }
}

/* メニューウィンドウの表示 */
void __menue(option* options, int count){

  for (int i=0;i<count; i++) {
    printf("%s\n", options[i].name);
  }

  select_key(options, count);
}
