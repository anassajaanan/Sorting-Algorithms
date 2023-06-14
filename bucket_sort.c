/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:55:04 by aajaanan          #+#    #+#             */
/*   Updated: 2023/06/14 13:55:04 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	insert(struct s_node **p, int data)
{
	struct s_node	*q;
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->val = data;
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
	int				data;
	struct s_node	*q;

	q = *first;
	*first = (*first)->next;
	data = q->val;
	free(q);
	return (data);
}

void	bucket_sort(int A[], int n)
{
	int				i;
	int				j;
	int				max;
	struct s_node	**bins;

	max = get_max(A, n);
	bins = (struct s_node **)malloc(sizeof(struct s_node *) * (max + 1));
	i = 0;
	while (i <= max)
		bins[i++] = NULL;
	i = 0;
	while (i < n)
		insert(&bins[A[i++]], A[i]);
	i = 0;
	j = 0;
	while (i <= max)
	{
		while (bins[i] != NULL)
			A[j++] = delete(&bins[i]);
		i++;
	}
	free(bins);
}
