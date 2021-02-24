/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:25:29 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 17:25:36 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANG_H
# define LANG_H
# include "../shell.h"
# include "../../../altlib/altlib.h"
# include "../../../includes/rt_event_loop.h"
# include "../../menu/include/rt_menu.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# define BUFF_SIZE 4096

enum						e_ins_type
{
	INS_TYPE_SHELL,
	INS_TYPE_LANG,
	__INS_TYPE_TOTAL,
};

enum						e_lang_cmds
{
	LANG_IF,
	LANG_END_IF,
	LANG_DO,
	LANG_END_DO,
	LANG_FN_TOTAL,
};

struct						s_do_cmd
{
	int		repetition;
	char	*source_to_repeat;
};

struct						s_if_cmd
{
	char	*condition;
	char	*body;
};

struct						s_else_cmd
{
	char	*body;
};

struct						s_else_if_cmd
{
	char	*condition;
	char	*body;
};

union						u_cmd
{
	struct s_do_cmd			do_cmd;
	struct s_if_cmd			if_cmd;
	struct s_else_cmd		else_cmd;
	struct s_else_if_cmd	else_if_cmd;
};

struct						s_shell_cmd
{
	char			*name;
	char			*args;
	int				cmd_valid;
};

struct						s_lang_cmd
{
	enum e_lang_cmds	type;
	void				(*fn_ptr)(t_list *, void *);
	union u_cmd			cmd;
};

union						u_div_cmd
{
	struct s_shell_cmd	shell_cmd;
	struct s_lang_cmd	lang_cmd;
};

typedef struct				s_ins
{
	enum e_ins_type	ins_type;
	union u_div_cmd	instruction_data;
}							t_ins;

int							get_next_line(const int fd, char **line);
void						instruction_get(char *src, t_ins *ins);
void						apply_lang_instructions(t_list *ins_list);
void						execute_instruction_list(t_list *ins_stack,
								t_object *object_list, t_rt_utils *utils);
int							get_line(int fd, char **line);
int							interpret_source(char *filename,
	t_object *object_list, t_rt_utils *utils);

#endif
