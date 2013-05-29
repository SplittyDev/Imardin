#ifndef __IMARDIN_OPCODES_H
#define __IMARDIN_OPCODES_H

// Stack Operations
#define PUSH		0x01 // Push
#define POP			0x02 // Pop

// Store Operations
#define STORE		0x03 // Store

// Load Operations
#define LOAD		0x04 // Load
#define LD_B		0x05 // Load byte
#define LD_W		0x06 // Load word
#define LD_D		0x07 // Load dword
#define LD_Q		0x08 // Load qword

// Branch Operations
#define JEQ			0x09 // Jump if equal
#define JNE			0x0A // Jump if not equal
#define JGT			0x0B // Jump if greater than
#define JGE			0x0C // Jump if greater than or equal
#define JLT			0x0D // Jump if lower than
#define JLE			0x0E // Jump if lower than or equal
#define JZ			0x0F // Jump if zero
#define JNZ			0x10 // Jump if not zero
#define JSR			0x11 //
#define JMP			0x12 // Jump
#define RET			0x13 // Return

// Mathematic Operations
#define ADD			0x14 // Add
#define FADD		0x15 // Add float
#define SUB			0x16 // Substract
#define FSUB		0x17 // Substract float
#define MUL			0x18 // Multiply
#define FMUL		0x19 // Multiply float
#define DIV			0x1A // Divide
#define FDIV		0x1B // Divide float
#define MOD			0x1C // Modulo
#define SIN			0x1D // Sine
#define ASIN		0x1E // Asine
#define COS			0x1F // Cosine
#define ACOS		0x20 // Acosine
#define TAN			0x21 // Tangential
#define ATAN		0x22 // Atangential

// Bitwise Operations
#define AND			0x23 // Bitwise and
#define OR			0x24 // Bitwise or
#define XOR			0x25 // Bitwise xor
#define SHL			0x26 // Bitwise shift left
#define SHR			0x27 // Bitwise shift right
#define ROL			0x28 // Bitwise rotation left, unimplemented
#define ROR			0x29 // Bitwise rotation right, unimplemented
#define NOT			0x2A // Bitwise not

// Imardin Operations
#define SYSF		0x4A // System function
#define BREAK		0x4B // Break at pos
#define HALT		0x4C // Halt
#define KENNETH		0x4D // Fuck up the virtual memory

#endif