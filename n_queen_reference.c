//https://github.com/tdanielsousa/42_school_new_exams_2026/tree/main/Rank_3/level2/n_queens


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define L_BLUE  "\033[38;5;123m"
#define RESET   "\033[0m"

int *board;         // board[col] = row position of queen in column col
int board_size;     // size of the board (n)

int pocet;

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

// Print the current solution
void print_solution(void)
{
    int i;
    
    for (i = 0; i < board_size; i++)
    {
        // Print row position of queen in column i
        fprintf(stdout, "%d", board[i]);
        
        // Add space between numbers, except after the last one
        if (i < board_size - 1)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}

// replacement abs() function as the original function is not allowed
int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return n;
}

// Check if placing a queen at (row, col) is safe
int is_safe(int row, int col)
{
	// Check all previously placed queens (columns 0 to col-1)
	// i: column iterator
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row) // check if queens are in the same row
			return 0;
		
		// Check diagonal attacks
        // If the difference in rows equals difference in columns,
        // they're on the same diagonal
		if (ft_abs(board[i] - row) == ft_abs(i - col))
			return 0;
	}
	return 1;
}

void solve(int col)
{
	// base case check: if we've placed queens in all columns
	if (col == board_size)
	{
	//	print_solution();
		++pocet;
		return ;
	}
	// Try placing queen in each row of current column
	for (int row = 0; row < board_size; row++)
	{
		// Try placing queen in each row of current column
		if (is_safe(row, col))
		{
			// Place queen at this position
			board[col] = row;
			// Recursively solve for next column
			solve(col + 1);
			// Backtrack (remove queen) - implicit since we overwrite
            // board[col] in next iteration or when function returns
		}
	}
}

int main(int ac, char **av)
{
	// handle incorrect argc
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	long long start = get_time_in_ms();
	int n = atoi(av[1]);
	// handle invalid inputs: negative numbers, unsolvable sizes
	if (n <= 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	board_size = n; // set global variable
	board = malloc(sizeof(int) * board_size);
	if (!board)
		return 1;
	// Start solving from column 0
	pocet = 0;
	solve(0);
	free(board);
	long long end = get_time_in_ms();
	long long time = end - start;
	printf (L_BLUE"time[%lld]		rows[%d]	\n" RESET, time, pocet);
	return 0;
}