/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# define SZ sizeof
# define DATA content
# define DATA_SIZE content_size

# include <unistd.h>

typedef	struct	s_queue
{
	t_list		*first;
	t_list		*last;
}				t_queue;

typedef	struct	s_anthill
{
	int				ants;
	int				n;
	t_list			**adj_list;
	t_list			*node_list;
	t_list			*start;
	t_list			*end;
	char			**node_names;
	t_queue			*tagged;
	t_queue			*path;
	t_queue			*q;
	t_list			*temp;
	t_list			*adj;
	int				start_id;
}				t_anthill;

void			pr_free_char_arr(char **to_free, int len);
int				valid_last_line(int x);
void			free_content(void *p, size_t useless);
void			get_path(t_anthill *anthill);
void			breadth_first_search(t_anthill *anthill);
void			move_ants(t_anthill *anthill);
int				ft_isspace(int c);
int				ft_atoi_lem_in(const char *str);
void			check_int_parsing(char *s);
void			error();
void			*pr_malloc(size_t n);
void			pr_free(void *p);
int				anthill_printing(int fd, char **t, int print);
void			free_list(t_list *l);
int				i_in_list(t_list *t, char *s);
int				int_i_in_list(t_list *t, int n);
void			ft_list_push_back(t_list **l, void *content, int content_size);
int				parse_edges(t_anthill *anthill, char **t);
void			parse_nodes(t_anthill *anthill, char **t);
void			init_adj_list(t_anthill *anthill);
void			print_adj_list(t_anthill *anthill);
t_queue			*new_queue();
void			enqueue(t_queue *queue, void *content, int content_size);
t_list			*dequeue(t_queue *queue);
void			free_queue(t_queue *q);
void			reverse_queue(t_queue *q);
void			skip_comments(char **t);
#endif
