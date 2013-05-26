#ifndef __IMARDIN_OPCODES_H
#define __IMARDIN_OPCODES_H

// Stack Operations
#define PUSH		0x01 // Push
#define POP			0x02 // Pop
#define SSS			0x03 // unimplemented
#define LSS			0x04 // unimplemented
#define SSP			0x05 // unimplemented
#define LSP			0x06 // unimplemented
#define STORE		0x07 // Store
#define LOAD		0x08 // Load

// Branch Operations
#define BEQ			0x09 // Branch if equal
#define BNE			0x0A // Branch if not equal
#define BGT			0x0B // Branch if greater than
#define BLT			0x0C // Branch if lower than
#define BZ			0x0D // Branch if zero
#define BNZ			0x0E // Branch if not zero
#define BRA			0x0F // Branch
#define BSR			0x10 // unimplemented

// Mathematic Operations
#define ADD			0x11 // Add
#define FADD		0x12 // Add float
#define SUB			0x13 // Substract
#define FSUB		0x14 // Substract float
#define MUL			0x15 // Multiply
#define FMUL		0x16 // Multiply float
#define DIV			0x17 // Divide
#define FDIV		0x18 // Divide float

// Imardin Operations
#define SYSF		0x19 // System function

// Logic Operations
#define AND			0x1A // Logic and
#define OR			0x1B // Logic or
#define XOR			0x1C // Logic xor
#define SHL			0x1D // Logic shift left
#define SHR			0x1E // Logic shift right
#define ROL			0x1F // unimplemented
#define ROR			0x20 // unimplemented

#define RET			0x21 // Return

#endif
