int check_borders(char **s)
{
	int i = 0;
	int firstline;
	int lastline;
	int fistcol;
	int lastcol;

	int j = 0;

	while (s[i][j])
	{
		if (s[i][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1' || s[i][xmax] != '1')
			return (0);
		i++;
		// letzte libe fehlt

}

// eventuell int check_borders(char **map, int xmax, int xmin)
