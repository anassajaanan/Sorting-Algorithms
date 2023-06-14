/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:44:48 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 15:44:48 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int A[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	j = low;
	i = low - 1;
	pivot = A[high];
	while (j < high)
	{
		if (A[j] <= pivot)
			swap(&A[++i], &A[j]);
		j++;
	}
	swap(&A[++i], &A[high]);
	return (i);
}

void	quick_sort(int A[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(A, low, high);
		quick_sort(A, low, pi - 1);
		quick_sort(A, pi + 1, high);
	}
}
