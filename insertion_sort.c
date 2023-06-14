/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:54:10 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 11:54:10 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	insertion_sort(int A[], int size)
{
	int	i;
	int	k;

	k = 0;
	while (k < size - 1)
	{
		i = k + 1;
		while (i > 0 && A[i] < A[i - 1])
		{
			swap(&A[i], &A[i - 1]);
			i--;
		}
		k++;
	}
}
