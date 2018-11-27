// Simple assembler for the Logisim tinyproc2, which was
// put together in CS120, Fall 2018
//
// The processor supports four instructions: add, subtract,
// multiply, and load immediate.
// Instruction formats are
//  DR (2 bits, destination register)
//  SR1 SR2 (2 bits each, source registers)
//  OpCode (00 - add, 01 - sub, 10 - mul, 11 - load immediate)
//
// On load immediate, the two source registers are treated
// as a 4-bit immediate value (sign extended to 8 bits)
//
// Here's some source code (on the right), and the op code
// that it translates to (on the left)
// 0f : ldi r0, 3
// 4b : ldi r1, 2
// 86 : mul r2, r0, r1
// ff : ldi r3, -1
// ac : add r2, r2, r3
//
// Run the assembler with "assembler yourfile.s"
// Any line that doesn't match the simple assembly language
// is ignored

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;  // C has a "FILE" type, used by the operating system
             // to give you access to files....
  char buffer[1024];
  int sr1, sr2, dr;
  int immediate;
  unsigned int opcode;

  if (argc != 2)
    {
      printf("Usage: %s filename.s\n", argv[0]);
      exit(1);
    }

  fp = fopen(argv[1], "r"); // File name is given on the command line

  // fgets is "file get string" -- it gets one line of input from the
  // file, and returns a pointer to memory location zero (null) when
  // we reach the end of the file.  This is where we get one line at
  // a time....
  while (fgets(buffer, 1023, fp) != NULL)
    {
      // sscanf is a standard C routine, that does pattern matching
      // on a string.  We compare the buffer to the sequence of letters
      // "add r%d, ..."
      // If the letters match up, scanf keeps going.
      // 
      // You remember in printf where we had "%d" to print out a 
      // number?  If scanf sees an integer in the input, it puts it
      // into the variable indicated -- so the first %d gets put into
      // variable dr, the second into sr1, and the third into sr2.
      //
      // The scanf function returns the number of things it matched --
      // if it returns three, we know that we found all of dr, sr1, sr2.
      //
      // IMPORTANT: note the ampersand (&) on dr.  This lets sscanf change
      // the value in dr.  It's a pointer.  We will talk about this in
      // class.  Because it's important.  Seriously, pay attention to this.
      if (sscanf(buffer, "add r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
	  // "<<" shifts bits.  If you've programmed in C++, sorry.  Life
	  // is going to be confusing.  C++ input and output is dumb.
	  // The single vertical bar (|) is logical or -- we or the bits
	  // together, to form the opcode.
	  opcode = dr << 6 | sr1 << 4 | sr2 << 2 | 0;
	  printf("%02x : %s", opcode, buffer);
	  // Continue will take you down to the bottom of the enclosing loop.
	  // Yes, it's a branch/jump instruction.  If we have matched the
	  // instruction on the input, no need to check other things that
	  // might match....
	  continue;
	}

      // INSERT CODE FOR sub HERE!
      // It should be painfully simple.  Look at how add and mul are
      // done.  The difference between them is the opcode.
      // Then, look at the sscanf call.  Once you've got an idea of
      // how the code works, it should take you two minutes to add
      // in the sub instruction....
	  
	if (sscanf(buffer, "sub r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
		opcode = dr << 6 | sr1 << 4 | sr2 << 2 | 1;
		printf("%02x : %s", opcode, buffer);
		continue;
	}

      if (sscanf(buffer, "mul r%d, r%d, r%d", &dr, &sr1, &sr2) == 3)
	{
	  opcode = dr << 6 | sr1 << 4 | sr2 << 2 | 2;
	  printf("%02x : %s", opcode, buffer);
	  continue;
	}
      if (sscanf(buffer, "ldi r%d, %d", &dr, &immediate) == 2)
	{
	  opcode = dr << 6 | ((immediate << 2) & 0x3c) | 3;
	  printf("%02x : %s", opcode, buffer);
	  continue;
	}
      // You could have some error checking here, or warn if
      // you saw something you didn't expect
      // printf("Unrecognized line.\n");
    }

  // We're done reading the input file..
  fclose(fp);
}
