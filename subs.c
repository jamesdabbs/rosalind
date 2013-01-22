#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE  1

#define MAX_BP 1000

char* read_dna_line(char* str) {
  return fgets(str, MAX_BP, stdin);
}

int main() {
  char haystack[MAX_BP], needle[MAX_BP];

  read_dna_line(haystack);
  read_dna_line(needle);

  // ?? Is there a better library function to do this?
  int i, j, matches;
  int l = strlen(needle) - 1;  // ?? Again, for the \n
  for (i=0; haystack[i] && haystack[i] != '\n'; i++) {
    matches = TRUE;
    for (j=0; j<l; j++) {
      if (haystack[i + j] != needle[j]) {
        matches = FALSE;
        break;
      }
    }
    if (matches) printf("%d ", i+1);
  }
  printf("\n");
}