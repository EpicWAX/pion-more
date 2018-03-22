/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 10:28:19 by qhusler           #+#    #+#             */
/*   Updated: 2016/06/17 19:28:01 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int k;

	i = 0;
	k = ft_strlen(str) - 1;
	while (i < k)
	{
		ft_swap_char(str + i, str + k);
		i++;
		k--;
	}
	return (str);
}
