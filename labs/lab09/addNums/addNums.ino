//* Prompt the user to type in two numbers
//* Print out the sum of those two numbers, and the sum of all the numbers between
//them (inclusive).
//For example, if the user types 7 and 14, your program should print “21”,
//and then the sum of 7+8+9+10+11+12+13+14

void setup()
{
  Serial.begin(9600);

  Serial.println("input two integers");
}

void loop()
{
  while (Serial.available() > 0)
  {
    int num1 = Serial.parseInt();

    int num2 = Serial.parseInt();
    
    if (Serial.read() == '\n')
    {
      Serial.print("sum: ");
      Serial.println(num1 + num2);

      int sum = 0;

      for (int i = min(num1, num2); i <= max(num1, num2); ++i)
      {
        sum += i;
      }

      Serial.print("sum of all numbers in range: ");
      Serial.println(sum);
    }
  }
}
