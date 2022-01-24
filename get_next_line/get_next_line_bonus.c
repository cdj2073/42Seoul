#include "get_next_line_bonus.h"

t_list  *find_list(t_list **head, int fd) {
    t_list  *curr;
    t_list  *new;

	curr = *head;
	while (curr && curr->fd != fd)
		curr = curr->next;
	if (!curr) {
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		new->fd = fd;
		new->data = NULL;
		new->next = *head;
		*head = new;
		return (new);
	}
	return (curr);


	/*
    if (*head == NULL) {
        *head = (t_list *)malloc(sizeof(t_list));
        (*head)->next = NULL;
    }
    curr = *head;
    while (curr->next != NULL) {
        if (curr->next->fd == fd)
            return (curr->next);
        curr = curr->next;
    }
    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new->fd = fd;
    new->data = NULL;
    new->next = NULL;
    curr->next = new;
    return (new);
	*/
}

void    free_lst(t_list **head, t_list *lst) {
    t_list  *tmp;

    tmp = *head;
	if (lst == *head)
		*head = (*head)->next;
	else
	{
		while (tmp->next && tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	/*
    while (prev->nex){
        if (prev->next == lst)
            break;
        prev = prev->next;
    }
    prev->next = lst->next;
	*/
    free(lst->data);
    free(lst);
}

char    *split_new_line(t_list *lst) {
    char    *ptr;
    char    *tmp;
    char    *line;
 
    ptr = ft_strchr(lst->data, '\n');
    line = ft_substr(lst->data, 0, ptr - lst->data + 1);
    tmp = lst->data;
    lst->data = ft_substr(ptr + 1, 0, ft_strlen(ptr + 1));
 //   if (!lst->data)
 //       free_lst(&head, lst);
//	else
		free(tmp);
    return (line);
}

int    read_new_line(int fd, t_list *buf_list) {
    int     read_size;
    char    *buf;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_size = read(fd, buf, BUFFER_SIZE);
    while (read_size > 0)
	{
        buf[read_size] = '\0';
        buf_list->data = ft_strjoin(buf_list->data, buf);
        if (ft_strchr(buf, '\n'))
		{
            free(buf);
            return (1);
        }
        read_size = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    return (0);
}

char    *get_next_line(int fd) {
    static t_list   *head;
    t_list          *buf_list;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf_list = find_list(&head, fd);
    if (!buf_list)
        return (NULL);
    if (buf_list->data && ft_strchr(buf_list->data, '\n'))
        return (split_new_line(buf_list));
    if (read_new_line(fd, buf_list))
        return (split_new_line(buf_list));
    else
	{
        line = ft_substr(buf_list->data, 0, ft_strlen(buf_list->data));
        free_lst(&head, buf_list);
        return (line);
    }
}
