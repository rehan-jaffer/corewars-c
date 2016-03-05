// These are based on the spec shown here http://vyznev.net/corewar/guide.html#start_instr
#define DAT 0x10 // data (kills the process)
#define MOV 0x11 // move (copies data from one memory location to another)
#define ADD 0x12 // add (adds one number to another)
#define SUB 0x13 // substract (subtracts one number from another)
#define MUL 0x14 // multiply (multiplies one number by another)
#define DIV 0x15 // divide (divides one number by another)
#define MOD 0x16 // modulus (divides one number by another and gives thes result)
#define JMP 0x17 // jump (continues execution from another address)
#define JMZ 0x18 // jump if zero (tests a number and jumps if it isn't zero)
#define JMN 0x19 // jump if not zero
#define DJN 0x20 // decrement and jump if not zero
#define SPL 0x21 // split (starts a second process at another address)
#define CMP 0x22 // compare (same as SEQ)
#define SEQ 0x23 // skip if equal
#define SNE 0x24 // skip if not equal
#define SLT 0x25 // skip if lower than
#define LDP 0x26 // load from p-space (loads a number from private storage space)
#define STP 0x27 // save to p-space (saves a number to private storage space)
#define NOP 0x28 // no operation ( do nothing )
// addressing modes
#define IMMI 0x29 // immediate
#define DIRE 0x30 // direct
#define INDI 0x31 // indirect
#define PRED 0x32 // predecrement
#define RELA 0x33 // relative
