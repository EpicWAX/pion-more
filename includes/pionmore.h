#ifndef PIONMORE_H
# define PIONMORE_H

# include <stdio.h>
# include "libft.h"

# define PLAYER1    'x';
# define PLAYER2    'o';
# define DOT        '.';
# define P1         1;
# define P2         2;
# define NUL        0;

int		            **board_init(int **matrix);
void	            board_display(int **matrix);
int 	            parse_line(int **matrix, int s);
int		            any_one_dot(int **matrix);
int		            parse_enter(char *s);
int		            game_loop(int **matrix);

#endif