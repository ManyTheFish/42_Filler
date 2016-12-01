/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:52:11 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/01 13:20:54 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			loop_hook(t_env *env)
{
	t_params	*params;
	int			to_play[2];

	to_play[0] = 2;
	to_play[1] = 8;
	params = NULL;
	// to_play = (int*)malloc(sizeof(int) * 2);
	// /* Parser */
	ft_putendl_fd("Pouet 1", 2);
	if (!(params = parser()))
	{
		ft_putendl_fd("In return", 2);
		return (0);
	}
	//  AI 
	// if (ai_dv(params, to_play))
	// 	play(to_play[0], to_play[1]);
	draw_game_board(env->win_img, params);
//	sleep(1);
	ft_putendl_fd("Pouet 2", 2);
	play(2, 8);
//	play(to_play[0], to_play[1]);
	return (0);
}
