/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:23:06 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/05/25 22:19:36 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_left_str(int fd, char *laststr)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(laststr, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(laststr);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		laststr = ft_strjoin(laststr, buffer);
	}
	free(buffer);
	return (laststr);
}

static char	*ft_getline(char *laststr)
{
	char	*line;
	int		len;
	int		i;

	if (!*laststr)
		return (NULL);
	len = 0;
	while (laststr[len] && laststr[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (laststr[i] && laststr[i] != '\n')
	{
		line[i] = laststr[i];
		i++;
	}
	if (laststr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_new_left_str(char *laststr)
{
	char	*str;
	int		len;
	int		i;

	if (!*laststr)
	{
		free(laststr);
		return (NULL);
	}
	len = 0;
	while (laststr[len] && laststr[len] != '\n')
		len++;
	str = malloc(sizeof(char) * (ft_strlen(laststr) - len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (laststr[len])
		str[i++] = laststr[++len];
	str[i] = '\0';
	free(laststr);
	return (str);
}

/* @brief A macro MAX_FDS define o número máximo de fd's que a função
pode manipular simultaneamente. com um array estático 
laststr[MAX_FDS] para controlar as strings restantes
para cada fd. Cada elemento corresponde a um fd  diferente, 
GNL gerencia vários arquivos abertos ao mesmo tempo.
 @param MAX_FDS array estático, contém ponteiros para
o restante do buffer que ainda não foi processado para cada fd.*/
char	*get_next_line(int fd)
{
	static char	*laststr[10];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	laststr[fd] = ft_read_left_str(fd, laststr[fd]);
	if (!laststr[fd])
		return (NULL);
	line = ft_getline(laststr[fd]);
	laststr[fd] = ft_new_left_str(laststr[fd]);
	free(laststr[fd]);
	return (line);
}
/*  #include <stdio.h>

int	main(void)
{
	int		fd;
    int		fd1;
    int		fd2;
	char	*str;

	fd = open("texto.txt", O_RDONLY);
    fd1 = open("texto2.txt", O_RDONLY);
    fd2 = open("texto3.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (0);
	}
	str = get_next_line(fd);
	printf("line 1 -> %s\n", str);
	free(str);
    str = get_next_line(fd1);
    printf("line 2 -> %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("line 3 -> %s\n", str);
	free(str);
	return (0);
} */

/* void handle_file(const char *filename, int line_number) 
{
    int fd;

	fd = open(filename, O_RDONLY);
    if (fd == -1) 
	{
        printf("Error opening %s\n", filename);
        return;
    }

    char *str = get_next_line(fd);
    if (str) 
	{
        printf("line %d -> %s\n", line_number, str);
		free(str);
    }
	else 
	{
        printf("Error reading line %d from %s\n", line_number, filename);
    }

    close(fd);
}

int main(void)
{
	handle_file("texto.txt", 1);
	handle_file("texto2.txt", 1);
	handle_file("texto3.txt", 1);

	return (0);
} */