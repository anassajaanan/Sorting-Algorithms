/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:49:24 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 10:49:24 by aajaanan         ###   ########.fr       */
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

void	bubble_sort(int A[], int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		flag = 0;
		while (j < size - 1 - i)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return ;
		i++;
	}
}
