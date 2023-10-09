/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:36:15 by sisen             #+#    #+#             */
/*   Updated: 2023/09/29 20:36:18 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo)
{
	if (philo->philo_count == 1)
	{
		gettime(philo);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->philo_id);
		printf("%ld %d is died\n", philo->t_die, philo->philo_id);
	}
	else
	{
		while (1)
		{
			take_fork(philo);
			eat(philo);
			if (philo->hm_eat == philo->max_eat_count)
				break ;
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	pthread_mutex_lock(philo->lock);
	*philo->is_full += 1;
	if (*philo->is_full == philo->philo_count)
		*philo->ph_dead = 1;
	pthread_mutex_unlock(philo->lock);
	return ;
}

void	create_thread(t_philo *philo, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_create(&philo[i].thread, NULL, (void *)philo_life, &philo[i]);
		pthread_detach(philo[i].thread);
		i += 2;
	}
	usleep(600);
	i = 1;
	while (i < philo_count)
	{
		pthread_create(&philo[i].thread, NULL, (void *)philo_life, &philo[i]);
		pthread_detach(philo[i].thread);
		i += 2;
	}
}
