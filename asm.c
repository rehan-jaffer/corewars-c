#include "stdint.h"
#include "string.h"
#include "unistd.h"
#include "stdio.h"

// smallest sample program to compile is the Imp
// consists of following single instruction: 
// MOV 0, 1
// should output following struct:
// instr (opcode: MOV op1: 0 op2: 1 op1_addr: DIRE op2_addr: DIRE)

int main(int argc, char *argv[]) {

  if (argc > 2 || argc < 2) {
    return 1; // "No arguments supplied (command requires a filename for input)"
  }

  int result;
  char *filename = argv[1];
  char *token;
  char *line;
  result = access(filename, F_OK);

  if (result != 0) {
    printf("Error reading file");
    return 1;
  }

  FILE * fp;
  size_t len;
  ssize_t read;
  fp = fopen(filename, "r");
  if (fp == NULL)
    return -1;

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s", line);
  }

  fclose(fp);

  // steps
  //   open file/check existence/permissions
  //   read line-by-line
  //   output structs denoting instruction codes


}
