#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

// colors
#define RESET   "\033[0m"
#define RED		"\033[38;5;196m"
#define GREEN   "\033[38;5;47m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define PURPLE  "\033[38;5;99m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"
#define PINK    "\033[38;5;206m"
#define GRAY    "\033[38;5;242m"
#define L_BLUE  "\033[38;5;123m"


typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int 			i;
	int				n;
	int 			*board;
	pthread_mutex_t *mtx;
	pthread_mutex_t *board_mtx;
	int 			rows;
	t_list			*lst;
} t_data;


/* * * * * * * queen.c * * * * * * */

void 		print_solution(t_data *data);
int 		ft_abs(int n);
int 		is_safe(int row, int col, t_data *data);
void		solve(int col, int first, int n, t_data *data);

/* * * * * * * pthread.c * * * * * * */

void		my_pthreads_join(pthread_t *thread, int len);
void		print_routine(t_data *data, char *msg);
void		safe_print(t_data *data, char *msg);
void		*routine(void *arg);
pthread_t   *pthread_init(int len, t_data *data,pthread_mutex_t *mtx, pthread_mutex_t *board_mtx);
t_data 		*data_init(int n, pthread_mutex_t *mtx, pthread_mutex_t *board_mtx );
int 		solve_threads(int n);

/* * * * * * * time.c * * * * * * */

long long	get_time_in_ms(void);
void		ft_usleep(long long time_in_ms);

/* * * * * * * utils.c * * * * * * */

int	ft_atoi(const char *str);

/* * * * * * * * * * * * * * * * * * */