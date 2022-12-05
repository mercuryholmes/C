#include <stdio.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/function.h"

/* メニュー表示 */
static void menue(){
  option option[] = {
    {"[1]採取", collecting},
    {"[2]調合", synthesis}
  };
  int count = sizeof option / sizeof option[0];
  _menue(option, count);
}

/* アトリエ画面 */
void atelier(){
  system("clear"); 
  puts("--- アトリエ ---");
  menue();
}
