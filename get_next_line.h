/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboncine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:53:10 by aboncine          #+#    #+#             */
/*   Updated: 2022/10/25 13:27:39 by aboncine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_rev(const char *s);
char	*ft_strjoin_rev(char *s1, char *s2);
void	*my_malloc(int size);
char	*taglia(char *s);
char	*scrivi(int x, char *s);
void	*my_free(char *s);
char	*splitjoin(char *s1, char *s2, char *p);
char	*ft_leggi(int fd, int *i);

#endif
