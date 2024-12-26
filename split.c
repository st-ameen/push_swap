#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

static int	count_words(char *s, char sep)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || !s[i + 1]))
			c++;
		i++;
	}
	return (c);
}

static char	*get_next_word(char *s, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == sep)
		cursor++;
	while ((s[cursor + len] != sep) && s[cursor + len])
		len++;
	next_str = malloc(len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((s[cursor] != sep) && s[cursor])
		next_str[i++] = s[cursor++];
	next_str[i] = '\0';
	return (next_str);
}
char	**ft_split(char *s, char sep)
{
	int		w_c;
	int		i;
	char	**strs;

	i = 0;
	w_c = count_words(s, sep);
	if (!w_c)
		exit(1);
	strs = malloc(sizeof(char *) * (size_t)(w_c + 2));
	if (!strs)
		return (NULL);
	while (w_c-- >= 0)
	{
		if (i == 0)
		{
			strs[i] = malloc(sizeof(char));
			if (!strs[i])
			{
				free(strs);
				return (NULL);
			}
			strs[i++][0] = '\0';
			w_c--;
		}
		strs[i++] = get_next_word(s, sep);
	}
	strs[i] = NULL;
	return (strs);
}
