/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:43:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/02 14:18:18 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strreald(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL || *s1 == '\0')
		new = ft_strdup(s2);
	else if ((new = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	else
		ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}

char	*ft_strreal(char *s1, char *s2)
{
	char	*new;

	new = NULL;
	// printf("B adresse s1     %p  \n", s1);
	// printf("B adresse s2     %p  \n", s2);
	// printf("B adresse new    %p  \n\n", new);
	if (s1 == NULL || *s1 == '\0')
		new = ft_strdup(s2);
	else if ((new = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	free(s1);
	// printf("A adresse s1     %p  \n", s1);
	// printf("A adresse s2     %p  \n", s2);
	// printf("A adresse new    %p  \n-\n", new);
	return (new);
}
