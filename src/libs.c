#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int get_random(int min, int max) {
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int generate_random(int min, int max) {
    sleep(1);
    srand((unsigned int)time(NULL));
    return get_random(min, max);
}
