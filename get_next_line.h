/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro < treis-ro@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:02:40 by treis-ro          #+#    #+#             */
/*   Updated: 2024/02/01 12:10:39 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char    *get_next_line(int fd);
int     gnl_strlen(char *str);
char    *gnl_strjoin(char *s1, char *s2);
void    gnl_update(char *str);
#endif
