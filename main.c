/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:50:44 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/15 11:34:43 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(int ac, char **av)
{
	t_wlf wlf;

	ft_init_env(&wlf);
	ft_init_window(wlf);
	return (0);
}
