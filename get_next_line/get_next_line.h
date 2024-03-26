#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000000
typedef struct s_list
{
    char *str_b;
    struct s_list *next;
}   t_list;

void append(t_list **list, char *buff);
void creat_list(t_list **list, int fd);
char *get_next_line(int fd);
char *get_line(t_list * list);
void polish_list(t_list **list);
t_list	*find_last_node(t_list *list);
int f_newline(t_list *list);
void copy_str(t_list *list, char *str);
int len_to_newline(t_list *list);
void dealloc(t_list **list, t_list *cn, char *buff);

#endif
#endif
