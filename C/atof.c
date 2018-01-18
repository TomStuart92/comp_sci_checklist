#include <ctype.h>

/* atof: coverts string s to double */

double atof(char s[])
{
  double val, power;
  int i, sign;

  // skip white space 
  for(i=0; isspace(s[i]); i++)
    ;

  // set sign and increment
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == 'i')
    i++;

  // increment for values > 0
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  // increment for decimals
  if(s[i] == '.')
    i++;
  for(power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] = '0');
    power *= 10.0;
  }
  
  return sign * val / power;
}