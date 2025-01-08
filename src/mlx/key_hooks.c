/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: andmadri <andmadri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/08 20:38:21 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/09 14:33:16 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	rotate_vector(float *dir, float *t_x, float *t_y, double angle)
{
	*t_x = dir[X] * cos(angle) - dir[Y] * sin(angle);
	*t_y = dir[X] * sin(angle) + dir[Y] * cos(angle);
	*t_x /= sqrt(*t_x * *t_x + *t_y * *t_y);
	*t_y /= sqrt(*t_x * *t_x + *t_y * *t_y);
}

void	key_hook_strafe(t_data *data)
{
	float	temp_x;
	float	temp_y;
	double	angle;

	angle = -90 * RAD;
	rotate_vector(data->player.direct, &temp_x, &temp_y, angle);
	if (data->keys.strafe_left && is_not_wall(data, temp_x, temp_y, LEFT))
	{
		data->player.pos[X] += (temp_x * (STEP_SIZE + \
			(STEP_SIZE * data->keys.shift)));
		data->player.pos[Y] += (temp_y * (STEP_SIZE + \
			(STEP_SIZE * data->keys.shift)));
	}
	angle = 90 * RAD;
	rotate_vector(data->player.direct, &temp_x, &temp_y, angle);
	if (data->keys.strafe_right && is_not_wall(data, temp_x, temp_y, RIGHT))
	{
		data->player.pos[X] += (temp_x * (STEP_SIZE + \
			(STEP_SIZE * data->keys.shift)));
		data->player.pos[Y] += (temp_y * (STEP_SIZE + \
			(STEP_SIZE * data->keys.shift)));
	}
}

void	key_hook_move(t_data *data)
{
	t_keys	keys;

	keys = data->keys;
	if (keys.forward && is_not_wall(data, data->player.direct[X], \
		data->player.direct[Y], FORWARD))
	{
		data->player.pos[X] += (data->player.direct[X] * \
			(STEP_SIZE + (STEP_SIZE * data->keys.shift)));
		data->player.pos[Y] += (data->player.direct[Y] * \
			(STEP_SIZE + (STEP_SIZE * data->keys.shift)));
	}
	else if (keys.back && is_not_wall(data, -data->player.direct[X], \
		-data->player.direct[Y], BACKWARD))
	{
		data->player.pos[X] -= (data->player.direct[X] * \
			(STEP_SIZE + (STEP_SIZE * data->keys.shift)));
		data->player.pos[Y] -= (data->player.direct[Y] * \
			(STEP_SIZE + (STEP_SIZE * data->keys.shift)));
	}
}

static void	mouse_hook(t_data *data)
{
	int	x;
	int	y;

	data->keys.mouse_right = false;
	data->keys.mouse_left = false;
	mlx_mouse_get_pos(data->milx.mlx, data->milx.mlx_window, &x, &y);
	mlx_mouse_move(data->milx.mlx, data->milx.mlx_window, \
		data->milx.screen_x / 2, data->milx.screen_y / 2);
	data->keys.mouse_step = x - data->milx.screen_x / 2;
	if (data->keys.mouse_step > 0)
		data->keys.mouse_right = true;
	else if (data->keys.mouse_step < 0)
		data->keys.mouse_left = true;
	x = data->milx.screen_x / 2;
}

void	key_hook_turn(t_data *data)
{
	t_keys	keys;

	keys = data->keys;
	if (BONUS && keys.mouse)
		mouse_hook(data);
	if (keys.turn_left || keys.mouse_left)
		rotate_vector(data->player.direct, &data->player.direct[X], \
			&data->player.direct[Y], (-TURN_STEP + \
			(data->keys.mouse_step * 0.001) - \
			(TURN_STEP * data->keys.shift)));
	else if (keys.turn_right || keys.mouse_right)
		rotate_vector(data->player.direct, &data->player.direct[X], \
			&data->player.direct[Y], (TURN_STEP + \
			(data->keys.mouse_step * 0.001) + (TURN_STEP * \
			data->keys.shift)));
}
