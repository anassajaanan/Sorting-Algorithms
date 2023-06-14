/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:00:24 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 11:00:24 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort(int A[], int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		k = i;
		j = i + 1;
		while (j < size)
		{
			if (A[j] < A[k])
				k = j;
			j++;
		}
		swap(&A[k], &A[i]);
		i++;
	}
}
