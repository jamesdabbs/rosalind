#include <stdio.h>
#include <string.h>

// ?? this extra sizing is sloppy. Do a read without \n.
#define NAME_LENGTH 15   // for \n\0
#define MAX_BP      1100 // for \n's in lines
#define MAX_ENTRIES 10

typedef struct {
  char name[NAME_LENGTH];
  char code[MAX_BP];
  double gc_content;
} FASTA;

void set_gc_content(FASTA* dna) {
  // ?? Better idiom for setting (*dna).attr?
  int gcs = 0;
  int tot = 0;
  char *s = (*dna).code;
  while (*s) {
    if (*s != '\n') tot++;
    if (*s == 'G' || *s == 'C') gcs++;
    s++;
  }
  (*dna).gc_content = (100.0 * gcs) / tot;
}

int main () {
  char buffer[MAX_BP], *p;
  FASTA winner = { "", "", 0.0 };
  FASTA candidate = { "", "", 0.0 };

  do {
    fgets(buffer, MAX_BP, stdin);
    if (buffer[0] == '>') {
      // Check the current candidate
      set_gc_content(&candidate);
      if (candidate.gc_content > winner.gc_content) winner = candidate;

      // Initialize the new candidate
      candidate = (FASTA) { "", "", 0.0 };
      strncpy(candidate.name, buffer+1, NAME_LENGTH);
    } else {
      strcat(candidate.code, buffer);
    }
  } while (!feof(stdin));

  set_gc_content(&candidate);
  if (candidate.gc_content > winner.gc_content) winner = candidate;

  printf("%s%lf%%\n", winner.name, winner.gc_content);
}