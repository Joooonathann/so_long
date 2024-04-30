/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:36:17 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_convert_ptr(unsigned long long n, t_node *stock)
{
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		stock = ft_convert_ptr(n / 16, stock);
	c = hex[n % 16];
	return (create_node(c, stock));
}
