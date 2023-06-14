/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:18:48 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 12:18:48 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_max(int A[], int size)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < size)
	{
		if (A[i] > max)
			max = A[i];
		i++;
	}
	return (max);
}

int	*create_hash_table(int A[], int size, int ht_size)
{
	int	i;
	int	*ht;

	i = 0;
	ht = (int *)malloc(sizeof(int) * ht_size);
	while (i < ht_size)
	{
		ht[i] = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		ht[A[i]]++;
		i++;
	}
	return (ht);
}

void	count_sort(int A[], int size)
{
	int	i;
	int	j;
	int	max;
	int	*hash_table;

	i = 0;
	j = 0;
	max = get_max(A, size);
	hash_table = create_hash_table(A, size, max + 1);
	while (i <= max)
	{
		if (hash_table[i] != 0)
		{
			A[j++] = i;
			hash_table[i]--;
		}
		else
			i++;
	}
	free(hash_table);
}
