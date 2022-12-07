#pragma once
#include "include/struct.h"

/* interactive functions */
void select_key(option*, int);

/* UI functions */
void __menue(option*, int);
void atelier(void);
void synthesis(void);
void collecting(void);

/* database functions*/
int get_item_at_random(void);
