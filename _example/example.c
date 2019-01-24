#include "../core/kstroke.h"
#include <stdio.h>

int cb(uint8_t key, bool state)
{
  printf("state %c %d\n", key, state);
}

int main()
{
  setbuf(stdout, NULL);
  kstroke_listen(&cb);
}