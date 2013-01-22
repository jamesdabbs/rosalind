#include <stdio.h>

#define MAX_NT 1000

int main () {
  char buffer[MAX_NT];
  fgets(buffer, MAX_NT, stdin);

  int i;
  for (i=0; buffer[i] != 0; i++) {
    if (buffer[i] == 'T') {
      buffer[i] = 'U';
    }
  }

  fprintf(stdout, "%s\n", buffer);
}