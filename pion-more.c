#include "pionmore.h"

int		**board_init(int **matrix)
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
	if (!(matrix = (int**)malloc(sizeof(int*) * 3)))
		return (NULL);
    while (i < 3)
    {
    	if (!(matrix[i] = (int*)malloc(sizeof(int) * 3)))
    		return (NULL);
        j = -1;
        while (++j < 3)
            matrix[i][j] = 0;
        i++;
    }
    return (matrix);
}

void	board_display(int **matrix, int tour)
{
	int i;
	int j;
	int display_number;
	
    i = 0;
    j = 0;
    display_number = 0;
    system("clear");
    ft_putstr_color(CGREEN, "  0|1|2\n", CEND);
    ft_putstr_color(CGREEN, " -------\n", CEND);
    while (i < 3)
    {
        ft_putstr_color(CGREEN, ft_itoa(display_number++), CEND);
        ft_putstr_color(CGREEN, "|", CEND);
        while (j < 3)
        {
            if (matrix[i][j] == 0)
            	ft_putstr_color(CGREEN, ".", CEND);
            else
            {
            	if (matrix[i][j] == 1)
            		ft_putstr_color(CYELL, "o", CEND);
            	else
            		ft_putstr_color(CRED, "x", CEND);
            }
            ft_putstr_color(CGREEN, "|", CEND);
            j++;
        }
        j = 0;
        ft_putchar('\n');
        i++;
    }
    ft_putstr_color(CGREEN, " -------\n", CEND);
    ft_putstr_color(CGREEN, (tour % 2 == 0) ? "p1 turn\n" : "p2 turn\n", CEND);
}

int 	parse_line(int **matrix, int s)
{
	if (matrix[0][0] == s && matrix[0][1] == s && matrix[0][2] == s)
		return (1);
	if (matrix[1][0] == s && matrix[1][1] == s && matrix[1][2] == s)
		return (1);
	if (matrix[2][0] == s && matrix[2][1] == s && matrix[2][2] == s)
		return (1);
	if (matrix[0][0] == s && matrix[1][0] == s && matrix[2][0] == s)
		return (1);
	if (matrix[0][1] == s && matrix[1][1] == s && matrix[2][1] == s)
		return (1);
	if (matrix[0][2] == s && matrix[1][2] == s && matrix[2][2] == s)
		return (1);
	if (matrix[0][0] == s && matrix[1][1] == s && matrix[2][2] == s)
		return (1);
	if (matrix[0][2] == s && matrix[1][1] == s && matrix[2][0] == s)
		return (1);

	return (0);
}
		
int		any_one_dot(int **matrix)
{
	int i;
	int j;
	int	x;

	i = -1;
	x = 0;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (matrix[i][j] == 0)
				x++;
	}
	return (x > 0 ? x : 0);
}

int		parse_enter(char *s)
{
	int c1;
	int c2;
	
	c1 = 0;
	c2 = 0;
	if (s[0] == '0' || s[0] == '1' || s[0] == '2')
		c1++;
	if (s[1] == '0' || s[1] == '1' || s[1] == '2')
		c2++;
	if (c1 > 0 && c2 > 0)
		return (1);
	ft_putstr_color(CRED, "nope!\n", CEND);
	return (0);
}

int		game_loop(int **matrix)
{
	int		tour;
	char	re[2] = {0};
	int		line;
	int		column;
	
	tour = 0;
	while (1)
	{
		tour++;
		board_display(matrix, tour);
    	while (1)
    	{
    		if (any_one_dot(matrix) == 0)
    			return (-1);
    		if (parse_line(matrix, tour % 2 == 0 ? 2 : 1) == 1)
    			return (tour % 2 == 0 ? 2 : 1);
    		ft_putstr("position ? ");
    		scanf("%s", re);
    		if (parse_enter(re) == 0)
    			continue ;
    		line = ft_atoi(re) / 10;
    		column = ft_atoi(re) % 10;
    		if (matrix[line][column] == 0)
    			matrix[line][column] = (tour % 2 == 0) ? 1 : 2;
    		else
				continue ;
    		break ;
    	}
	}
	return (-1);
}

int		main()
{
	int **matrix;
	int	win;
	
	matrix = NULL;
	matrix = board_init(matrix);
	win = game_loop(matrix);
	if (win == -1)
		ft_putstr_color(CGREEN, "equality\n", CEND);
	else if (win == 1)
		ft_putstr_color(CGREEN, "well play p2\n", CEND);
	else
		ft_putstr_color(CGREEN, "well play p1\n", CEND);
	return (0);
}