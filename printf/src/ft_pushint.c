/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:15:05 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_pushint(int i, t_node *stock)
{
	long long	n;

	n = i;
	if (n < 0)
	{
		stock = create_node('-', stock);
		n = -n;
	}
	if (n > 9)
	{
		stock = ft_pushint(n / 10, stock);
		stock = create_node(n % 10 + '0', stock);
	}
	else
		stock = create_node(n % 10 + '0', stock);
	return (stock);
}
