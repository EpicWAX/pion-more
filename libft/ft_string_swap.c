/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 08:18:45 by qhusler           #+#    #+#             */
/*   Updated: 2016/06/02 05:17:46 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_string_swap(char **s1, char **s2)
{
	char *s;

	s = *s1;
	*s1 = *s2;
	*s2 = s;
}
