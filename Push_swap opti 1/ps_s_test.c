#include "push_swap.h"


void ps_sort(t_nlst **a, t_nlst **b)
{
	int i;
	int size;

	i = 0;
	size = ft_nlstsize(*a);
	if (check_only_swap(a, ft_nlstsize(*a), 0))
		swap(a, 0);
	
	while(i < size / 2)
	{
		push(a, b, 0);
		i++;
	}
	ft_printf("\nfin de decoupe");
	if (!check_heap(a, 0))
		{ft_printf("\n-- sorting a --\n");sort_n(a, b, ft_nlstsize(*a), 0);}

	if (!check_heap(b, 1))
		{ft_printf("\n-- sorting b --\n");sort_n(b, a, ft_nlstsize(*b), 1);}
	ft_printf("\n-- end --\n");
	while (*b)
	{
		if ((*b)->content < (*a)->content)
			push(b, a, 1);
		else
			rotate(a, 0);
	}
	rot_to_first(a,ft_nlstsize(*a), 0);
}



void ps_sort(t_nlst **a, t_nlst **b)
{
	int median;
	int i;
	int size;

	i = 0;
	size = ft_nlstsize(*a);
	if (check_only_swap(a, ft_nlstsize(*a), 0))
		swap(a, 0);
	median = nlst_get_median(a, ft_nlstsize(*a));
	
	while(i < size / 2)
	{
		if ((*a)->content < median)
		{
			push(a, b, 0);
			i++;
		}
		else
			rotate(a, 0);
	}
	ft_printf("\nfin de decoupe\n");
	if (!check_heap(a, 0))
		{ft_printf("\n-- sorting a --\n");sort_n(a, b, ft_nlstsize(*a), 0);}

	if (!check_heap(b, 1))
		{ft_printf("\n-- sorting b --\n");sort_n(b, a, ft_nlstsize(*b), 1);}
	ft_printf("\n-- end --\n");
	while (*b)
		push(b, a, 1);
}

void ps_sort(t_nlst **a, t_nlst **b) // bad opti
{
	int	size_a;
	int size_b;
	int nb_elem;
	
	nb_elem = ft_nlstsize(*a);
	while (ft_nlstsize(*a) > nb_elem / 2)
		push(a, b, 0);
	size_b = ft_nlstsize(*b);
	if (check_only_swap(b, size_b, 1))
		swap(b, 1);
	else if (!check_heap(b, 1))
		sort_n(b, a, size_b, 1);
	
	size_a = ft_nlstsize(*a);
	if (check_only_swap(a, size_a, 0))
		swap(a, 0);
	else if (!check_heap(a, 0))
		sort_n(a, b, size_a, 0);
	while (ft_nlstsize(*b) > 0)
		if ((*b)->content > (*a)->content)
			rotate(a, 0);
		else
			push(b, a, 1);
	rot_to_first(a, 0);
}