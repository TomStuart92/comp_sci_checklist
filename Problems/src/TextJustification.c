#include <limits.h>
#include <stdio.h>

#define INFINITY INT_MAX

void justify_text(int word_lengths[], int number_of_words, int max_width);
int print_solution(int parent_pointers[], int limit);

void justify_text(int word_lengths[], int number_of_words, int max_width)
{
    int extra_spaces[number_of_words+1][number_of_words+1];  
    int line_costs[number_of_words+1][number_of_words+1];
    int total_costs[number_of_words+1];
    int parent_pointers[number_of_words+1];
 
    int i, j;
 
    // calculate extra spaces in a single line.  The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= number_of_words; i++)
    {
        extra_spaces[i][i] = max_width - word_lengths[i-1];
        for (j = i+1; j <= number_of_words; j++)
            extra_spaces[i][j] = extra_spaces[i][j-1] - word_lengths[j-1] - 1;
    }
 
    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= number_of_words; i++)
    {
        for (j = i; j <= number_of_words; j++)
        {
            if (extra_spaces[i][j] < 0)
                line_costs[i][j] = INFINITY;
            else if (j == number_of_words && extra_spaces[i][j] >= 0)
                line_costs[i][j] = 0;
            else
                line_costs[i][j] = extra_spaces[i][j] * extra_spaces[i][j];
        }
    }
 
    // Calculate minimum cost and find minimum cost arrangement.
    //  The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    total_costs[0] = 0;
    for (j = 1; j <= number_of_words; j++)
    {
        total_costs[j] = INFINITY;
        for (i = 1; i <= j; i++)
        {
            if (total_costs[i-1] != INFINITY && line_costs[i][j] != INFINITY && (total_costs[i-1] + line_costs[i][j] < total_costs[j]))
            {
                total_costs[j] = total_costs[i-1] + line_costs[i][j];
                parent_pointers[j] = i;
            }
        }
    }
 
    print_solution(parent_pointers, number_of_words);
}


int print_solution(int parent_pointers[], int number_of_words) 
{
  int line_number;
  if(parent_pointers[number_of_words] == 1)
    line_number = 1;
  else 
    line_number = print_solution(parent_pointers, parent_pointers[number_of_words] - 1) + 1;
  printf("Line Number %d: Word %d to %d \n", line_number, parent_pointers[number_of_words], number_of_words );
  return line_number;
}

int main()
{
    int word_lengths[] = {5, 3, 5, 8, 4, 4, 7};
    int number_of_words = sizeof(word_lengths)/sizeof(word_lengths[0]);
    int max_width = 15;
    justify_text(word_lengths, number_of_words, max_width);
    return 0;
}
