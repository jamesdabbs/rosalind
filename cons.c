#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_BP 1000

char* read_dna_line(char* str) {
  return fgets(str, MAX_BP, stdin);
}

int main() {
  char chars[4] = { 'A', 'C', 'G', 'T' };
  char line[MAX_BP];
  int i,j;

  // Alloc the array
  read_dna_line(line);
  int l = strlen(line) - 1;
  int *m = calloc(4*l, sizeof(int));

  // Read each line
  do {
    for (i=0; i<l; i++) {
      for (j=0; j<4; j++) {
        if (line[i] == chars[j]) {
          m[i + j*l]++;
          break;
        }
      }
    }
  } while (read_dna_line(line) != NULL);

  // Print the consensus
  for (i=0; i<l; i++) {
    int best = 0;
    int ind  = 0;
    for (j=0; j<4; j++) {
      if (m[i + j*l] > best) {
        best = m[i + j*l];
        ind = j;
      }
    }
    putchar(chars[ind]);
  }
  putchar('\n');

  // Print the matrix
  for (j=0; j<4; j++) {
    printf("%c:", chars[j]);
    for (i=0; i<l; i++) {
      printf(" %d", m[i + j*l]);
    }
    putchar('\n');
  }

}