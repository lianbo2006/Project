#include <stdio.h>
int main(int argc, char const *argv[]) {
  int i;
  for ( i = 0; i <= 5; i++) {
    if(i%2) putchar('<');
    else continue;
    putchar('>');
  }
  putchar('#');
  return 0;
}
