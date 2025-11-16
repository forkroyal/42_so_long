#include <stdio.h>
int count_of(char **map, char what_to_find)
{
	int c_count = 0;
	int i = 0;
	while(map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			if (map[i][j] == what_to_find)
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

// int main()
// {
// 	char *hello[] = {"hello", "cousin", NULL};

// 	//printf("%c\n", hello[0][2]);
// 	printf("%i\n", count_of(hello, 'o'));
// }
