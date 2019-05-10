#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	//Creat a variable to store a random char selection between 32 and 127 on the ASCII table
	int lower = 32;  //Lower range of char options
	int upper = 127;  //Upper range of char options

	char randChar = (rand() % (upper - lower + 1)) + lower;

    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
	//Create a loop that will populate an array with letters - within range of 97 to 123 on the ASCII table
	int lower = 97;
	int upper = 123;
	int i;

	char* str = (char*) calloc(8, sizeof(char));  //Chose an array/string size of 8, because I like that number and it seems sufficient for moderating testing

	for (i = 0; i < 7; i++) {
		str[i] = (rand() % (upper - lower + 1)) + lower;
	}

    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
