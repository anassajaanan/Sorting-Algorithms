/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:48:31 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 14:48:31 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	merge(int A[], int l, int mid, int h)
{
	int	i;
	int	j;
	int	k;
	int	*arr;

	k = 0;
	i = l;
	j = mid + 1;
	arr = (int *)malloc(sizeof(int) * (h - l + 1));
	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			arr[k++] = A[i++];
		else
			arr[k++] = A[j++];
	}
	while (i <= mid)
		arr[k++] = A[i++];
	while (j <= h)
		arr[k++] = A[j++];
	i = l;
	k = 0;
	while (i <= h)
		A[i++] = arr[k++];
	free(arr);
}

void	merge_sort(int A[], int low, int high)
{
	int	mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}
