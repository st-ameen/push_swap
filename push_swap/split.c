#include "push_swap.h"

static int	count_words(char *s, char sep)
{
	int		c;
	bool	inside_word;

	c = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == sep && *s)
			++s;
		while (*s != sep && *s)
		{
			if (!inside_word)
			{
				++c;
				inside_word = true;
			}
			++s;
		}
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
	if (NULL == next_str)
		return (NULL);
	while ((s[cursor] != sep) && s[cursor])
		next_str[i++] = s[cursor++];
	next_str[i] = '\0';
	return (next_str);
}
char **ft_split(char *s, char sep)
{
    int w_c;
    int i;
    char **vector;

    i = 0;
    w_c = count_words(s , sep);
        if (!w_c)
            exit(1);
    vector = malloc(sizeof(char *) * (size_t)(w_c + 2));
    if (!vector)
        return NULL;
    while (w_c-- >= 0)
    {
        if (i == 0)
        {
            vector[i] = malloc(sizeof(char));
            if (!vector[i])
            {
                free(vector);
                return NULL;
            }
            vector[i++][0] = '\0';
            continue;
        }
        vector[i++] = get_next_word(s, sep);
    }
    vector[i] = NULL;
    return vector;
}