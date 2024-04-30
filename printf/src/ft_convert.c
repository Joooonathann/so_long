/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:05:58 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_convert(unsigned int n, t_node *stock, t_type t_type)
{
	int		c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		stock = ft_convert(n / 16, stock, t_type);
	c = hex[n % 16];
	if (c >= 'a' && c <= 'z' && t_type == hexa_max)
		c -= 32;
	return (create_node(c, stock));
}
