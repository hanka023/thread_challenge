

#include "queen.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < time_in_ms)
		usleep(100);
}
