#include <stdio.h>
int count_of(char **s, char c)
{
	int c_count = 0;
	int i = 0;
	while(s[i])
	{
		int j = 0;
		while(s[i][j])
		{
			if (s[i][j] == c)
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
