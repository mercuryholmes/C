#pragma once

struct  OPTION{
  char name[100];
  void (*action)(); //struct OPTIONS* self
};
typedef struct OPTION option;
