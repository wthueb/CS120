// CS120 Lab 10.  Here's some C code -- run it, make sure
// it produces the result you expect.
// Then....  convert this to MIPS, and run it in the simulator
// Single step through, to make sure it works like you
// expect
#include <stdio.h>

int f2(int x)
{
  return x + x;
  // Double the value, return in v0
}

int f1(int a, int b)
{
  return f2(a + b);
  // In MIPS, you'll save RA, then

  // get the values for A and B from the stack, add them,
  // and then store that value on the stack

  // call f2

  // After you're done, pop the argument off the stack,
  // then restore RA,
  // and return....
}

int main()
{
  // First thing in a function: store RA on the stack

  printf("Result is %d\n", f1(3, 4));
  // In your MIPS code, all you need to do is push
  // 3 and 4 onto the stack,
  // and then call f1.
  // Single step with the simulator, to see what happens.
  // When you're back in main, check the contents
  // of register v0, and make sure it's right.
  //
  // After you return, pop 3 and 4 off the stack (move
  // the stack pointer), restore $ra, and then return.
  //
  // This should do (3+4)*2
  // Yes, there are easier ways to do this.  The goal of
  // this assignment is to really nail down the use of
  // the stack.
}
