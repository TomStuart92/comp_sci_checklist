#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* max depth of val stack */
#define BUFSIZE 100 /* max size of getch buffer */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double values[MAXVAL];
char buf[BUFSIZE];
int bufposition = 0;

void push(double f) 
{
  if (sp < MAXVAL)
    values[sp++] = f;
  else
    printf("error: stack overflow");
}

double pop(void)
{
  if (sp > 0) {
    return values[--sp];
  } else 
    printf("error: stack empty");
    return 0.0;
}

int getop(char s[]) 
{
  int i, c;

  // skip whitespace
  while((s[0] = c = getch()) == ' ' || c =='\t')
    ;

  s[1] = '\0';

  // its not a number
  if (!isdigit(c) && c != '.')
    return c;
  
  // collect integer and fraction part of number
  i = 0;
  if(isdigit(c)) 
    while (isdigit(s[++i] = c = getch()))
      ;
  
  if(c == '.')
    while (isdigit(s[i++] = c = getch()))
      ;
  
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

int getch(void)
{
  return (bufposition > 0) ? buf[--bufposition] : getchar();
}

void ungetch(int c)
{
  if (bufposition >= BUFSIZE) 
    printf("error: too many chars to ungetch");
  else 
    buf[bufposition++] = c;
}


int main() 
{
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command\n");
        break;
    }
  }
  return 0;
}