#include "queen.h"

void	my_pthreads_join(pthread_t *thread,int len)
{
	int	i;

	i = 0;
	while (i < len)
	{

		pthread_join(thread[i], NULL);
		++i;
	}
	return ;
}


void	print_routine(t_data *data, char *msg)
{
	pthread_mutex_lock(data -> mtx);
	printf(ORANGE "msg[%s]	 i[%d]\n" RESET, msg, data -> i);
	pthread_mutex_unlock(data -> mtx);
}

void	safe_print(t_data *data, char *msg)
{
	pthread_mutex_lock(data -> mtx);
	printf(YELLOW "msg[%s]	 i[%d]\n" RESET, msg, data -> i);
	pthread_mutex_unlock(data -> mtx);
}

void	*routine(void *arg)
{
	t_data *data;
	//int first = 0;
	
	data = (t_data *)arg;
	printf (BLUE"vlakno[%d]\n"RESET, data ->i);
	solve(0, 0, data -> n, data);
	printf (BLUE"poc radku [%d]  vlakno[%d]\n"RESET, data ->rows, data -> i);
	free(data -> board);
	return (NULL);
}

pthread_t	*pthread_init(int len, t_data *data, pthread_mutex_t *mtx, pthread_mutex_t *board_mtx)
{
	pthread_t	*threads;
	int			i;

	i = 0;
	threads = malloc(sizeof (pthread_t) * len);
	if (!threads)
		return (NULL);
	while (i < len)
	{
		data[i].i = i;
		data[i].n = len;
		data[i].mtx = mtx;
		data[i].board_mtx = board_mtx;
		data[i].board = malloc (sizeof (int) * len);
		if (!data -> board)
			return (NULL);
		data[i].rows = 0;
		pthread_create(&threads[i], NULL, &routine, (void*) &data[i]);
		ft_usleep(1);
		++i;
	}
	return (threads);
}

t_data *data_init(int n, pthread_mutex_t *mtx, pthread_mutex_t *board_mtx)
{
	t_data *data;
	int i;

	i = 0;
	data = malloc (sizeof(t_data) * n);
	if (!data)
		return NULL;
	while (i < n)
	{
		data -> i = 0;
		data -> n = 0;
		data -> mtx = mtx;
		data -> board_mtx = board_mtx;
		data -> board = NULL;
		data -> rows = 0;
		++i;
	}
	return (data);
}



int solve_threads(int n)
{
	pthread_t	*threads;
	pthread_mutex_t *mtx;
	pthread_mutex_t *board_mtx;
	t_data *data;

	mtx = malloc (sizeof(pthread_mutex_t));
	board_mtx = malloc (sizeof(pthread_mutex_t));
	if (!mtx || !board_mtx)
		return (0);
	pthread_mutex_init(mtx, NULL);
	data = data_init(n, mtx, board_mtx);
	threads = pthread_init(n, data, mtx, board_mtx);
	my_pthreads_join(threads, n);
	free(threads);
	pthread_mutex_destroy(mtx);
	pthread_mutex_destroy(board_mtx);
	free(mtx);
	free(board_mtx);

	free(data);
	return (0);
}


