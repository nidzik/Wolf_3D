/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <nidzik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:50:44 by nidzik            #+#    #+#             */
/*   Updated: 2015/05/17 16:53:12 by nidzik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(int ac, char **av)
{
	t_wlf wlf;

	(void)ac;
	(void)av;
	ft_init_env(&wlf);
	wlf = ft_init_window(wlf);
	return (0);
}
