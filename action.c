/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:35:19 by sisen             #+#    #+#             */
/*   Updated: 2023/10/01 23:06:55 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->l_mutex);
	pthread_mutex_lock(philo->r_mutex);
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
	{
		printf("%ld %d has taken a fork\n", philo->start_time, philo->philo_id);
		printf("%ld %d has taken a fork\n", philo->start_time, philo->philo_id);
	}
	pthread_mutex_unlock(philo->lock);
}

void	ft_think(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is thinking\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
}

void	ft_sleep(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is sleeping\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
	ft_usleep(philo, philo->t_sleep);
}

void	eat(t_philo *philo)
{
	gettime(philo);
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
		printf("%ld %d is eating\n", philo->start_time, philo->philo_id);
	pthread_mutex_unlock(philo->lock);
	philo->hm_eat++;
	ft_usleep(philo, philo->t_eat);
	philo->death = philo->start_time + philo->t_die;
	pthread_mutex_unlock(philo->l_mutex);
	pthread_mutex_unlock(philo->r_mutex);
}
