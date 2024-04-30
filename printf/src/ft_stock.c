/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:48:58 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/30 10:35:42 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_node	*ft_stock(const char *format, va_list args)
{
	t_node	*stock;

	stock = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			stock = ft_flags(*format, stock, args);
		}
		else
			stock = create_node(*format, stock);
		format++;
	}
	return (stock);
}
