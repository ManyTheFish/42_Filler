#ifndef FILLER_H
# define FILLER_H
# define BUFFSIZE 8
# define FD 0
# define PLAYER_NAME "[players/dv.filler]"


# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# include "./libft.h"
# include "./mlxlibft.h"
# include "./get_next_line.h"
/*
@name: t_params
@brief: struct returned by parser and passed as parameter to AI
@attr:
	@name: game_board
	@type: char**
	@brief: map of the game,
	each line finish by '\0'
	the last line is a null pointer
@attr:
	@name: game_piece
	@type: char**
	@brief: piece to place on the game_board,
	each line finish by '\0'
	the last line is a null pointer
@attr:
	@name: coord
	@brief: struct wich contain coord of game_piece
*/

typedef struct	s_params
{
	char		player[2];
	int			count_line;
	char		**game_board;
	char		**game_piece;
	char		**game_piece_min;
	t_coord		board_size;
	t_coord		piece_size;
	t_coord		piece_size_min;
	t_coord		piece_orig;
}				t_params;

typedef struct	s_env
{
	t_mlx_env		*mlx;
	t_mlx_image_8u	*win_img;
	t_params		*params;
}				t_env;

/*
 *	GUI
 */

int			start_gui(void);
int			loop_hook(t_env *env);
int			expose(t_env *env);
t_roi		*draw_game_rack(
				t_mlx_image_8u *dst,
				const t_pixel_8u pixel,
				const int rack_width,
				const int rack_height
			);
void		draw_game_board(t_mlx_image_8u *dst,
				const t_params *params);

/*
 *	PARSER
 */

char		**ft_matrixnew(const size_t y, const size_t x);
void		ft_matrixdel(char **map);
t_params	*parser(t_params *params);
void		ft_get_piece(char *line, t_params *params);
void		play(int x, int y); //where do u want play the next piece

/*
 *	AI
 */
int			ai_launch(t_params *params, t_coord *to_play);

#endif
