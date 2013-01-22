#include <stdio.h>

#define MAX_BP 1000

int hamming(char *a, char *b) {
  int d = 0;
  int i;
  for (i=0; a[i] && a[i] != '\n'; i++){
    if (a[i] != b[i]) d++;
  }
  return d;
}

char* read_dna_line(char* str) {
  return fgets(str, MAX_BP, stdin);
}

int main() {
  char a[MAX_BP], b[MAX_BP];

  read_dna_line(a);
  read_dna_line(b);

  printf("%d\n", hamming(a, b));
}