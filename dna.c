#include <stdio.h>

#define MAX_NT 1000

int main () {
  char input[MAX_NT];
  fgets(input, MAX_NT, stdin);

  char nts[4]    = {'A', 'C', 'G', 'T'};
  int  counts[4] = {  0,   0,   0,   0};

  int i,j;
  for (i=0; input[i] != 0; i++) {
    for (j=0; j<4; j++) {
      if (input[i] == nts[j]) {
        counts[j]++;
      }
    }
  }

  for (i=0; i<4; i++) { 
    fprintf(stdout, "%d ", counts[i]);
  }
  fprintf(stdout, "\n");
}