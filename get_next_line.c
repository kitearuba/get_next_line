/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:06:06 by chrrodri          #+#    #+#             */
/*   Updated: 2024/08/21 20:34:52 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_storage(char *storage)
{
    if (storage)
        free(storage);
    return (NULL);
}

static char	*join_storage(char **storage, char *buffer)
{
    char	*temp;

    if (!*storage)
        *storage = ft_strdup(buffer);
    else
    {
        temp = ft_strjoin(*storage, buffer);
        free(*storage);
        *storage = temp;
    }
    return (*storage);
}

static ssize_t	read_fd(int fd, char **storage)
{
    char	*buffer;
    ssize_t	bytes_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (-1);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        if (!join_storage(storage, buffer))
            break ;
        if (ft_strchr(buffer, '\n'))
            break ;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    if (bytes_read < 0)
        return (-1);
    return (bytes_read);
}

static char	*extract_line(char **storage)
{
    char	*newline_pos;
    char	*line;
    char	*temp_storage;
    size_t	len;

    if (!*storage)
        return (NULL);
    newline_pos = ft_strchr(*storage, '\n');
    if (newline_pos)
    {
        len = newline_pos - *storage + 1;
        line = (char *)malloc((len + 1) * sizeof(char));
        if (!line)
            return (free_storage(*storage));
        ft_strappend(line, *storage, NULL, len + 1);
        temp_storage = ft_strdup(newline_pos + 1);
        *storage = free_storage(*storage);
        *storage = temp_storage;
        if (*storage && **storage == '\0')
            *storage = free_storage(*storage);
        return (line);
    }
    line = ft_strdup(*storage);
    *storage = free_storage(*storage);
    return (line);
}

char	*get_next_line(int fd)
{
    static char	*storage;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (read_fd(fd, &storage) < 0)
        return (free_storage(storage));
    return (extract_line(&storage));
}
