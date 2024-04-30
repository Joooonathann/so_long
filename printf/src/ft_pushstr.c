/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:18:40 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_pushstr(char *str, t_node *stock)
{
	if (!str)
	{
		stock = ft_pushstr("(null)", stock);
		return (stock);
	}
	while (*str)
	{
		stock = create_node(*str, stock);
		str++;
	}
	return (stock);
}
