#pragma once
#include "include/struct.h"

/* interactive functions */
void select_key(option*, int);

/* UI functions */
void __menue(option*, int);
void atelier(void);
void field(void);
void collecting(void);
void synthesis(void);

/* database functions*/
int get_item_at_random(void);
