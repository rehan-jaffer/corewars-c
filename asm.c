#include "stdint.h"
#include "string.h"

// smallest sample program to compile is the Imp
// consists of following single instruction: 
// MOV 0, 1
// should output following struct:
// instr (opcode: MOV op1: 0 op2: 1 op1_addr: DIRE op2_addr: DIRE)

int main(int argc, char *argv[]) {

  if (argc > 1 || argc < 1) {
    return 1; // "No arguments supplied (command requires a filename for input)"
  }

  // steps
  //   open file/check existence/permissions
  //   read line-by-line
  //   output structs denoting instruction codes


}
