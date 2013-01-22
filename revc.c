#include <stdio.h>

#define MAX_BP 1000

char compliment(char in) {
  switch (in) {
    case 'A':
      return 'T';
    case 'C':
      return 'G';
    case 'G':
      return 'C';
    case 'T':
      return 'A';
  }
}

int main () {
  char buffer[MAX_BP];
  fgets(buffer, MAX_BP, stdin);

  char *p = buffer;
  // Advance to the end of the string
  while (*p) p++;
  while (p >= buffer) {
    putchar(compliment(*p));
    p--;
  }
}