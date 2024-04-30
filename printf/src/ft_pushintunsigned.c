/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushintunsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:11:53 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_pushintunsigned(unsigned int i, t_node *stock)
{
	if (i > 9)
	{
		stock = ft_pushintunsigned(i / 10, stock);
		stock = create_node(i % 10 + '0', stock);
	}
	else
		stock = create_node(i % 10 + '0', stock);
	return (stock);
}
