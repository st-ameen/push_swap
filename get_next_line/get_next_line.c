#include "get_next_line.h"

void polish_list(t_list **list)
{
    t_list *ln;
    t_list *cn;
    int i, j;
    char *buff;

    buff = malloc(BUFFER_SIZE + 1);
    cn = malloc(sizeof(t_list));
    if (NULL == buff || NULL == cn)
        return;
    ln = find_last_node(*list);
    i = 0 , j = 0;
    
    while (ln->str_b[i] != '\0' && ln->str_b[i] != '\n')
        i++;
    while (ln->str_b[i] != '\0' && ln->str_b[++i])
        buff[j++] = ln->str_b[i];
    buff[j] = '\0';
    cn->str_b = buff;
    cn->next = NULL;
    dealloc(list, cn, buff);
}

char *get_line(t_list * list)
{
    int len;
    char *next_str;

    if (NULL == list)
        return NULL;
    
    len = len_to_newline(list);
    next_str = malloc(len + 1);
    if (NULL == next_str)
        return NULL;
    copy_str(list, next_str);
    return next_str;
}

void append(t_list **list, char *buff)
{
    t_list *nn; //new node
    t_list *ln; //last node

    ln = find_last_node(*list);
    nn = malloc(sizeof(t_list));
    if (NULL == nn)
        return;
    if (NULL == ln)
        *list = nn;
    else
        ln->next = nn;
    nn->str_b = buff;
    nn->next = NULL;
}

void creat_list(t_list **list, int fd)
{
    int i; //char read
    char *buff;
    while (!f_newline(*list))
    {
        buff = malloc(BUFFER_SIZE + 1);
        if (NULL == buff)
            return;
        i = read(fd, buff, BUFFER_SIZE);
        if (!i)
        {
            free(buff);
            return;
        }
        buff[i] = '\0';
        append(list, buff);
    }
}

char *get_next_line(int fd)
{
    static t_list *list = NULL;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return NULL;
    creat_list(&list, fd);
    if (list == NULL)
        return NULL;
    next_line = get_line(list);
    polish_list(&list);
    return (next_line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while ((line = get_next_line(fd1)))
		printf("line %d: %s\n", i++, line);
    
    i = 1;
    while ((line = get_next_line(fd2)))
		printf("line %d: %s\n", i++, line);
	
    i = 1;
    while ((line = get_next_line(fd3)))
		printf("line %d: %s\n", i++, line);
    return (0);
}