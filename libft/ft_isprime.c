/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:02:30 by qhusler           #+#    #+#             */
/*   Updated: 2016/03/26 19:27:40 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int n)
{
	int i;

	i = 2;
	while (i != n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
