#include "get_next_line.h"
#include <stdio.h>

char    *split_new_line(char **backup) {
    char    *ptr;
    char    *tmp;
    char    *line;
 
    ptr = ft_strchr(*backup, '\n');    // newline 위치로 포인터 이동
    line = ft_substr(*backup, 0, ptr - *backup + 1);  // newline까지 복사해서 리턴할 내용
    tmp = *backup; // 원래 buf 값 free 해주기위함
    *backup = ft_substr(ptr + 1, 0, ft_strlen(ptr + 1));   // newline 다음 문자열들로 바꾸기
    free(tmp);
    return (line);
}

int    read_new_line(int fd, char **backup) {
    char    *buf;
    int     read_size;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_size = read(fd, buf, BUFFER_SIZE);
    while (read_size > 0) {
        buf[read_size] = '\0';
        *backup = ft_strjoin(*backup, buf);
        if (ft_strchr(buf, '\n')) {
            free(buf);
            return (1);
        }
        read_size = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    return (0);
}

char    *get_next_line(int fd) {
    static char *backup[OPEN_MAX];
    char        *line;

    if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);

    if (backup[fd] && ft_strchr(backup[fd], '\n'))
        return (split_new_line(&backup[fd]));

    char    *buf;
    int     read_size;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_size = read(fd, buf, BUFFER_SIZE);
    while (read_size > 0) {
        buf[read_size] = '\0';
        backup[fd] = ft_strjoin(backup[fd], buf);
        if (ft_strchr(buf, '\n')) {
            free(buf);
            return (split_new_line(&backup[fd]));
        }
        read_size = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    line = ft_substr(backup[fd], 0, ft_strlen(backup[fd]));
    free(backup[fd]);
    backup[fd] = NULL;
    return (line);
/*
    if (read_new_line(fd, &backup[fd]))
        return (split_new_line(&backup[fd]));
    else {
//        printf("GNL   backup[fd] : %s...\n", backup[fd]);
        line = ft_substr(backup[fd], 0, ft_strlen(backup[fd]));
        free(backup[fd]);
        backup[fd] = NULL;
        return (line);
    }
    */
}