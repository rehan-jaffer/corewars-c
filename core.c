#include "opcodes.h"
#include "malloc.h"
#include "stdint.h"

struct instr {
  uint32_t opcode;
  uint32_t op1;
  uint32_t op2;
};

int main(int argc, char *argv) {

   struct instr core[800]; // allocated on the stack, this should probably be on the heap
   struct instr *core_p = NULL;
   int i = 0;
   core_p = &core[0];

   /* Set up program here (I should write some sort of assembler for this */
   core[0].opcode = MOV;
   core[0].op1 = 2;
   core[0].op2 = 0;

   while(1) {

     for (i=0;i<799;i++) {
       switch ((*(core_p+i)).opcode) {
         case ADD:
         break;
         case MOV:
           printf("MOV %d, %d\n", (*(core_p+i)).op1, (*(core_p+i)).op2);
           *((core_p+i)+(*(core_p)).op1) = *((core_p+i)+(*(core_p)).op2);
         break;
         default:
           printf("Unrecognized 
         break;
       }
     }
  }

}
