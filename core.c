#include "opcodes.h"
#include "malloc.h"
#include "stdint.h"
#include "stdbool.h"

struct instr {
  uint32_t opcode;
  uint32_t op1;
  uint32_t op2;
  uint32_t op1_addr_mode;
  uint32_t op2_addr_mode;
};

int main(int argc, char *argv) {

   struct instr core[800]; // allocated on the stack, this should probably be on the heap
   struct instr *core_p = NULL;
   int i = 0;
   core_p = &core[0];

   /* Set up program here (I should write some sort of assembler for this */
   core[0].opcode = MOV;
   core[0].op1 = 0;
   core[0].op2 = 1;
   core[0].op1_addr_mode = DIRE;
   core[0].op2_addr_mode = DIRE;

   uint16_t op1_addr = 0; // holds the address of the target during execution, this is mutable
   uint16_t op2_addr = 0; // holds the address of the target during execution, this is mutable

   /*
     Addressing modes:
       IMMI - Immediate - the number is the operand
       RELA - Relative - Add this number to the current address location
       INDI - Indirect - Retrieve the location to use as the operand from the offset specified
       DIRE - Direct - Retrieve the location to use as the operand from the location specified (absolute)
   */

   #define PTR_CURRENT (*(core_p+i))

   bool running = true;

   while(running) {

     for (i=0;i<799;i++) {
       // resolve locations
       switch(PTR_CURRENT.op1_addr_mode) {
         case IMMI:
           op1_addr = PTR_CURRENT.op1;
         break;
         case RELA:
           op1_addr = i+PTR_CURRENT.op1;
         break;
         case DIRE:
           op1_addr = (*(core_p+(PTR_CURRENT.op1+i))).op1;
         break;
         case INDI:
           op1_addr = (*(core_p+(PTR_CURRENT.op1))).op1;
         break;
         case PRED:
         break;
       }

       switch(PTR_CURRENT.op2) {
         case IMMI:
           op2_addr = PTR_CURRENT.op2;
         break;
         case RELA:
           op2_addr = i+PTR_CURRENT.op2;
         break;
         case DIRE:
           op2_addr = (*(core_p+(PTR_CURRENT.op2+i))).op2;
         break;
         case INDI:
           op2_addr = (*(core_p+(PTR_CURRENT.op2))).op2;
         break;
       }

       switch ((*(core_p+i)).opcode) {
         default:
           printf("Unrecognized opcode\r\n");
         break;
         case ADD:
         break;
         case MOV:
           printf("MOV %d, %d\r\n", (*(core_p+i)).op1, (*(core_p+i)).op2);
           *((core_p+i)+(*(core_p)).op2) = *((core_p+i)+(*(core_p)).op1);
         break;
       }
     }

     // running = NULL; // reset/quit after one cycle
  }

}
