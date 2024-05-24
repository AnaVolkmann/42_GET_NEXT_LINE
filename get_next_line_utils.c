/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:11:12 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/05/24 16:18:31 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}

char	*ft_strjoin(char *laststr, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!laststr)
	{
		laststr = (char *)malloc(1 * sizeof(char));
		laststr[0] = '\0';
	}
	if (!laststr || !buf)
		return (NULL);
	str = (char *)malloc(sizeof(*laststr)
			* (ft_strlen(laststr) + (ft_strlen(buf) + 1)));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (laststr)
		while (laststr[++i] != '\0')
			str[i] = laststr[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(laststr) + ft_strlen(buf)] = '\0';
	free(laststr);
	return (str);
}

/* @brief extrai a linha (terminando em quebra de linha e '\0' ou
so '\0')
  @param laststr o ponteiro para variavel estatica cumulativa de
execucoes anteriores da GNL
  @return a string com a linha completa terminando em uma quebra
de linha ('\n') + ('\0')*/
char	*ft_getline(char *laststr)
{
	int		i;
	char	*str;

	i = 0;
	if (!laststr)
		return (NULL);
	while (laststr[i] && laststr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (laststr[i] && laststr[i] != '\n')
	{
		str[i] = laststr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* @brief armazena na variavel estatica cumulariva a nova variavel
atualizada com o que resta da original, MENOS a linha extraida
 @param laststr ponteiro para a variavel estatica cumulariva de
outras execucoes da GNL
  @return a nova string atualizada com o que resta da static
   original, MENOS a linha extraida */
char	*ft_new_left_str(char *laststr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (laststr[i] && laststr[i] != '\n')
		i++;
	if (!laststr[i])
	{
		free(laststr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(laststr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (laststr[i])
		str[j++] = laststr[i++];
	str[j] = '\0';
	free(laststr);
	return (str);
}
