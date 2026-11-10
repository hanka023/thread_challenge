#include "queen.h"


int board_size;   
 
void print_solution(t_data *data)
{
    int i;
    pthread_mutex_lock(data -> mtx);
	//printf(BLUE"[%d]\n"RESET, data -> i);
    for (i = 0; i < board_size; i++)
    {
        fprintf(stdout, YELLOW"%d"RESET, data -> board[i]);
        if (i < board_size - 1)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
	pthread_mutex_unlock(data -> mtx);
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return n;
}

int is_safe(int row, int col, t_data *data)
{
	
	for (int i = 0; i < col; i++)
	{
		if (data -> board[i] == row) 
			return 0;
		
		if (ft_abs(data -> board[i] - row) == ft_abs(i - col))
			return 0;
	}
	return 1;
}

void solve(int col, int first, int n, t_data *data)
{
	int row;
	if (col == board_size)
	{
		//print_solution(data);
		
		++(data -> rows);
		return ;
	}
	if (col == 0)
	{
		(row = data -> i);
	}
	else
		row = 0;
	while (row < board_size)
	{
		if (is_safe(row, col, data))
		{
			data -> board[col] = row;
			solve(col + 1, first, n, data);
		}
		if (col == 0)
			return;
		row++;
	}
}


int main(int ac, char **av)
{

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	long long start = get_time_in_ms();
	int n = ft_atoi(av[1]);
	int rows;
	if (n <= 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	board_size = n; 

	
	rows = solve_threads(n);
	printf ("- - - - - - \n");
	
	
	long long end = get_time_in_ms();
	long long time = end - start;
	printf (GREEN"time[%lld]		rows[%d]\n"RESET,time, rows);
	return 0;
}