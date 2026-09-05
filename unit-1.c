#include <stdio.h>

int count() {
  static int c = 0;
  c++;
  return c;
}

int main() {
  printf("value %d", count());
  printf("value %d", count());

  return 0;
}
