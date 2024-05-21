/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:03:21 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/05/17 11:07:51 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1000
#endif

size_t  ft_strlen(char *s);
char *ft_getline(char *laststr);
char *ft_strchr(char *s, int c);
char *ft_new_left_str(char *laststr);
char *ft_strjoin(char *laststr, char *buf);

#endif