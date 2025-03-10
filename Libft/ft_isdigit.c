/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:58:34 by azorlutu          #+#    #+#             */
/*   Updated: 2024/10/07 13:58:35 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
	{
		return (1);
	}
	return (0);
}
