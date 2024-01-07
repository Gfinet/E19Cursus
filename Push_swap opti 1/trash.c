// int main(int argc, char **argv)
// {
//	 if (argc < 2)
//		 return (0);
//	 if (!check_input(&argv[1]))
//		 return (0);
//	 if (!push_swap(&argv[1]))
//		 return (0);
//	 return (0);
// }



// void	move_faster_node(t_nlst_head *a, t_nlst_head *b, int val, int a_b)
// {
// 	int		flag;
// 	int		flag2;
// 	int		closer;

// 	ft_printf(" v = %i ", val);
// 	closer = get_closer(a, b->first->content);
// 	flag = (nlst_get_place(b, val) < ft_nlstsize(b) / 2);
// 	flag2 = (nlst_get_place(a, closer) < ft_nlstsize(a) / 2);
// 	while ((b->first && b->first->content != val) || a->first->content != closer)
// 	{
// 		if (flag && flag2)
// 			rotate(a, b, 2);
// 		else if (!flag && !flag2)
// 			reverse_rotate(a, b, 2);
// 		else if (flag && !flag2)
// 			rotate(b, 0, a_b);
// 		else if (!flag && flag2)
// 			reverse_rotate(b, 0, a_b);
// 		sleep(1);
// 		ft_printf("yo %i ", b->first->content);
// 	}
// 	push(b, a, a_b);
// }


// void ps_sort(t_nlst_head *a, t_nlst_head *b)
// {
// 	int size;

// 	if (check_only_need_rot(a, 0))
// 		rot_to_first(a, nlst_get_low_big(a, 0), ft_nlstsize(a), 0);
// 	else if (check_swap(a, 0))
// 		swap(a, 0, 0);
// 	if (!check_heap(&a->first, 0))
// 	{
// 		size = ft_nlstsize(a);
// 		while (ft_nlstsize(a) > 3)
// 		{
// 			if (!nlst_is_need_val(a, a->first->content))
// 				push(a, b, 0);
// 			else
// 				rotate(a, 0, 0);
// 		}
// 		ft_putstr_fd("sep fini ", 1);
// 		sort_3(a, 0);
// 		if (size <= 9 && size > 3)
// 		{
// 			sort_9(a, b, 0);
// 		}
// 	}
// }

// void ps_sort(t_nlst **a, t_nlst **b)
// {
// 	int	size;
// 	size = ft_nlstsize(*a);
// 	if (check_only_need_rot(a, 0))
// 		rot_to_first(a, ft_nlstsize(*a), 0);
// 	else if (check_swap(a, 0))
// 		swap(a, 0);
	
// 	if (!check_heap(a, 0))
// 		sort_n(a, b, size, 0);
// }

/*
static int	sort_9(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	//int i;
	int j;
	// int tic_tac;

	// tic_tac = 0;
	j = 0;
	ft_printf("\n");
	while (ft_nlstsize(a) < 9)
	{
		move_faster_node(a, b, find_less_move(a, b), !a_b);
		// i = 0;
		// while (i < 2)
		// {
		// 	// ft_printf("i-j a b closer\n%i-%i %i %i %i\n\n", i, j,a->first->content, b->first->content, get_closer(a, get_fval(b)));
		// 	if (get_closer(a, get_fval(b)) == get_fval(a) || 
		// 	get_closer(a, get_fval(b)) == get_closer(a, get_fval(a)))
		// 	{
		// 		push(b, a, !a_b);
		// 		i++;
		// 	}
		// 	else
		// 		reverse_rotate(a, 0, 0);
		// 	// if ((j == 0 && i == 2) || (j == 1 && i == 2))
		// 	// 	reverse_rotate(a, 0, a_b);
		sleep(1);
		// }
		ft_printf("j = %i", j);
		j++;
	}
	return (1);
}
*/


// static int	sort_9(t_nlst_head *a, t_nlst_head *b, int a_b)
// {
// 	int j;

// 	j = 0;
// 	ft_printf("\n");
// 	while (ft_nlstsize(a) < 9)
// 	{
// 		move_faster_node(a, b, find_less_move(a, b), !a_b);
// 		sleep(1);
// 		ft_printf("j = %i", j);
// 		j++;
// 	}
// 	return (1);
// }

// static t_nlst	**sort_n(t_nlst_head *a,t_nlst_head *b , int n, int a_b)
// {
// 	if (n < 2)
// 		return (0);
// 	if (n == 2)
// 		swap(a, 0, a_b);
// 	else
// 	{
// 		rot_to_first(a, nlst_get_low_big(a, a_b), n, a_b);
// 		if (!check_heap(&a->first, a_b))
// 		{
// 			rot_to_first(a, nlst_get_low_big(a, a_b), n, a_b);
// 			push(a, b, a_b);
// 			sort_n(a, b, n - 1, a_b);
// 			push(b, a, !a_b);
// 		}
// 	}
// 	return (&a->first);
// }


// void ps_sort(t_nlst_head *a, t_nlst_head *b)
// {
// 	int size;

// 	if (check_only_need_rot(a, 0))
// 		rot_to_first(a, a->lower, ft_nlstsize(a), 0);
// 	if (!check_heap(&a->first, 0))
// 	{
// 		size = ft_nlstsize(a);
// 		opti_push(a, b, 0);
// 	}
// }

// int nlst_get_median(t_nlst_head *a, int nb_elem)
// {
// 	int lower;
// 	int bigger;
// 	t_nlst *p;
// 	t_nlst *p2;

// 	p = a->first;
// 	nb_elem -= (nb_elem %2 == 0);
// 	while (p)
// 	{
// 		bigger = 0;
// 		lower = 0;
// 		p2 = a->first;
// 		while (p2)
// 		{
// 			bigger += (p->content < p2->content);
// 			lower += (p->content > p2->content);
// 			if (bigger == lower && bigger == nb_elem / 2)
// 				return (p->content);
// 			p2 = p2->next;
// 		}
// 	p = p->next;
// 	}
// 	return (0);
// }

// int nlst_is_need_val(t_nlst_head *a, int x)
// {
// 	if (x == a->lower || x == a->bigger || x == a->median)
// 		return (1);
// 	else
// 		return (0);
// }

// int get_closer(t_nlst_head *a, int b)
// {
// 	int l;
// 	int bi;
// 	int m;

// 	l = b - a->lower;
// 	m = b - a->median;
// 	bi = a->bigger - b;
// 	if (m < 0)
// 		m *= -1;
// 	if (l <= m && m < bi)
// 		return (a->lower);
// 	if (m <= l && m < bi)
// 		return (a->median);
// 	if (bi < m && bi <= l)
// 		return (a->bigger);
// 	if (l == m)
// 		return (a->lower);
// 	if (m == bi)
// 		return (a->bigger);
// 	return (0);
// }

void opti_push(t_nlst_head *a, t_nlst_head *b, int a_b)
{
	int	best_node;

	while (ft_nlstsize(a) > 3)
			push(a,b, a_b);
	sort_3(a, 0);
	best_node = find_less_move(b, a);
	while (best_node != 0)
	{
		move_faster_node(b, a, best_node, a_b);
		best_node = find_less_move(b, a);
	}
	// while(ft_nlstsize(b) != 0)
	// 	push(b, a, !a_b);
	rot_to_first(a, a->lower, ft_nlstsize(a), 0);
}