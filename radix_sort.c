/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:08:21 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 14:08:21 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int				val;
	struct s_node	*next;
};

int	get_max(int A[], int n)
{
	int	i;
	int	max;

	i = 1;
	max = A[0];
	while (i < n)
	{
		if (A[i] > max)
			max = A[i];
		i++;
	}
	return (max);
}

void	insert(struct s_node **p, int val)
{
	struct s_node	*q;
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->val = val;
	new->next = NULL;
	if (*p == NULL)
		*p = new;
	else
	{
		q = *p;
		while (q->next)
			q = q->next;
		q->next = new;
	}
}

int	delete(struct s_node **first)
{
	int				val;
	struct s_node	*q;

	q = *first;
	*first = (*first)->next;
	val = q->val;
	free(q);
	return (val);
}

struct s_node	**create_bins(void)
{
	struct s_node	**bins;
	int				i;

	bins = (struct s_node **)malloc(sizeof(struct s_node *) * 10);
	i = 0;
	while (i < 10)
		bins[i++] = NULL;
	return (bins);
}

void	radix_sort(int A[], int n)
{
	int				i;
	int				j;
	int				k;
	int				max;
	struct s_node	**bins;

	max = get_max(A, n);
	bins = create_bins();
	k = 1;
	while (max / k > 0)
	{
		i = -1;
		while (++i < n)
			insert(&bins[(A[i] / k) % 10], A[i]);
		i = 0;
		j = 0;
		while (i < 10)
		{
			while (bins[i] != NULL)
				A[j++] = delete(&bins[i]);
			i++;
		}
		k *= 10;
	}
	free(bins);
}
