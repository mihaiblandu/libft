/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:36:12 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/09 05:29:05 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>


void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_slice(const void *array, size_t start, size_t len, size_t elem_size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar(char c);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);
int     ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
float	ft_nanf(const char *tagp);
double	ft_pow(double base, int exp);

//
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);

// Map/Hash Map
# define MAP_SIZE 100

typedef struct s_map_entry
{
	char				*key;
	void				*value;
	struct s_map_entry	*next;
}	t_map_entry;

typedef struct s_map
{
	t_map_entry	*buckets[MAP_SIZE];
	int			size;
}	t_map;

t_map	*map_create(void);
void	map_put(t_map *map, const char *key, void *value);
void	*map_get(t_map *map, const char *key);
int		map_contains(t_map *map, const char *key);
void	map_remove(t_map *map, const char *key);
void	map_clear(t_map *map);
void	map_free(t_map *map);
int		map_size(t_map *map);

#endif

