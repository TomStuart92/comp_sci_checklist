#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define BOX_SIZE 3
#define UNASSIGNED 0

bool is_target_in_row(int grid[BOARD_SIZE][BOARD_SIZE], int row, int target);
bool is_target_in_column(int grid[BOARD_SIZE][BOARD_SIZE], int column, int target);
bool is_target_in_box(int grid[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column, int target);
bool is_valid_entry(int grid[BOARD_SIZE][BOARD_SIZE], int row, int column, int entry);
bool find_next_incomplete(int grid[BOARD_SIZE][BOARD_SIZE], int *row, int*column);
void print_grid(int grid[BOARD_SIZE][BOARD_SIZE]);
bool solve(int grid[BOARD_SIZE][BOARD_SIZE]);

bool is_target_in_row(int grid[BOARD_SIZE][BOARD_SIZE], int row, int target)
{
  for(int column = 0; column < BOARD_SIZE; column++) {
    if(grid[row][column] == target) 
      return true;
  }
  return false;
} 

bool is_target_in_column(int grid[BOARD_SIZE][BOARD_SIZE], int column, int target)
{
  for(int row = 0; row < BOARD_SIZE; row++) {
    if(grid[row][column] == target) 
      return true;
  }
  return false;
}

bool is_target_in_box(int grid[BOARD_SIZE][BOARD_SIZE], int start_row, int start_column, int target)
{
  for (int row = 0; row < BOX_SIZE; row++) {
    for (int column = 0; column < BOX_SIZE; column++) {
      if (grid[row + start_row][column + start_column] == target)
        return true;
    }
  }
  return false;
}

bool is_valid_entry(int grid[BOARD_SIZE][BOARD_SIZE], int row, int column, int entry)
{
  return !is_target_in_row(grid, row, entry) 
    && !is_target_in_column(grid, column, entry) 
    && !is_target_in_box(grid, row - (row % BOX_SIZE), column - (column % BOX_SIZE), entry);
}

bool find_next_incomplete(int grid[BOARD_SIZE][BOARD_SIZE], int *row, int*column)
{
  for(*row = 0; *row < BOARD_SIZE; (*row)++) {
    for(*column = 0; *column < BOARD_SIZE; (*column)++) {
      if(grid[*row][*column] == UNASSIGNED)
        return true;
    }
  }
  return false;
}

bool solve(int grid[BOARD_SIZE][BOARD_SIZE])
{
  int row = 0;
  int column = 0;

  if(!find_next_incomplete(grid, &row, &column))
    return true;

  for(int number = 1; number <= BOARD_SIZE; number++) {
    if(is_valid_entry(grid, row, column, number)) {
      grid[row][column] = number;

      // try to solve with this configuration.
      if (solve(grid)) {
        return true;
      }

      // reset trial
      grid[row][column] = UNASSIGNED;
    }
  }
  return false;
}


void print_grid(int grid[BOARD_SIZE][BOARD_SIZE]) 
{
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int column = 0; column < BOARD_SIZE; column++) {
			printf("%2d", grid[row][column]);
		}
		printf("\n");
	}
}

int main() {
	int grid[BOARD_SIZE][BOARD_SIZE] = {
    {0,0,0, 0,0,3, 2,9,0},
    {0,8,6, 5,0,0, 0,0,0},
    {0,2,0, 0,0,1, 0,0,0},
    {0,0,3, 7,0,5, 1,0,0},
    {9,0,0, 0,0,0, 0,0,8},
    {0,0,2, 9,0,8, 3,0,0},
    {0,0,0, 4,0,0, 0,8,0},
    {0,4,7, 1,0,0, 0,0,0}
  };
	
  printf("\nUnsolved Sudoku:\n");
  print_grid(grid);

	if (solve(grid)) {
    printf("\nSolved Sudoku:\n");
		print_grid(grid);
	} else {
		printf("\nNo Solution Found\n");
	}
	
	return 0;
}