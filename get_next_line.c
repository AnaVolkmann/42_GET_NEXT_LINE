/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavolkmann <anavolkmann@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:46:55 by anavolkmann       #+#    #+#             */
/*   Updated: 2024/05/21 21:14:12 by anavolkmann      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static variables: persistência se refere à característica de um estado que sobrevive ao processo 
que o criou. Sem essa capacidade, o estado só existiria na RAM, e seria perdido quando a RAM parasse.*/

/* @brief Pega o fd aberto e salva em uma variável "buf" o que foi lido a partir dele.
depois junta-se à variável estática cumulativa para a persistência das informações.
 @param fd pointer para a variável estática cumulativa de execuções anteriores 
  @return o novo valor da variavel estatica com buffer combinado para a persistence da info*/
char	*ft_read_left_str(int fd, char *laststr)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(laststr, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		laststr = ft_strjoin(laststr, buf);
	}
	free(buf);
	return (laststr)
}
/* @brief Esta função pega um descritor de arquivo aberto e retorna sua próxima linha.
Esta função possui comportamento indefinido ao ler um arquivo binário.
 @param fd Um descritor de arquivo
  @return uma string com a linha lida até `\n`
Se ocorrer um erro ou não houver mais nada para ler, retorna NULL.*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*laststr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	laststr = ft_read_to_left_str(fd, laststr);
	if (!laststr)
		return (NULL);
	line = ft_getline(laststr);
	laststr = ft_new_left_str(laststr);
	return (line);
}