/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:23:27 by brjorgen          #+#    #+#             */
/*   Updated: 2020/12/18 17:41:18 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lang.h"
#include <fcntl.h>

void		execute_instruction_list(t_list *list, t_object *obj_list,
	t_rt_utils *utils)
{
	char	*tmp;
	t_ins	*ins;
	t_list	*traveller;

	traveller = list;
	ft_putendl("STARTING LIST EXECUTION...\nlist contents:");
	while (traveller)
	{
		ft_putendl(((t_ins *)traveller->data)->instruction_data.shell_cmd.name);
		ft_putendl(((t_ins *)traveller->data)->instruction_data.shell_cmd.args);
		traveller = traveller->next;
	}
	traveller = list;
	while (traveller)
	{
		ins = ((t_ins *)traveller->data);
		tmp = ft_itoa(ins->instruction_data.shell_cmd.cmd_valid);
		ft_putstr("function n ");
		ft_putendl(tmp);
		free(tmp);
		builtin_caller(ins->instruction_data.shell_cmd.cmd_valid,
			obj_list, ins->instruction_data.shell_cmd.args, utils);
		traveller = traveller->next;
	}
	ft_putendl("LIST EXECUTION TERMINATED.");
}

int			open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Failed to open file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void		instruction_get(char *src, t_ins *ins)
{
	char	*current;
	int		cmd_valid;

	if (src == NULL)
		exit(EXIT_FAILURE);
	current = ft_strnext(src, true);
	cmd_valid = ft_bin_search_str((char **)ret_builtin_names(), current,
		BUILTIN_TOTAL);
	if (cmd_valid != -1 && current != NULL)
	{
		ins->ins_type = INS_TYPE_SHELL;
		ins->instruction_data.shell_cmd.name = ft_strdup(current);
		ins->instruction_data.shell_cmd.args =
			ft_strdup(src + ft_strlen(current) + 1);
		ins->instruction_data.shell_cmd.cmd_valid = cmd_valid;
		return ;
	}
	else
	{
		ft_putstr(src);
		ft_putstr(" : no such cmd.\n");
		exit(EXIT_FAILURE);
	}
}

static bool	clear_list(t_list *head)
{
	t_ins	*ins;
	t_list	*traveller;
	t_list	*prev_traveller;

	if (!head)
		return (false);
	traveller = head;
	prev_traveller = head;
	while (traveller != NULL)
	{
		prev_traveller = traveller;
		traveller = traveller->next;
		ins = prev_traveller->data;
		free(ins->instruction_data.shell_cmd.name);
		free(ins->instruction_data.shell_cmd.args);
		free(ins->instruction_data.lang_cmd.cmd.do_cmd.source_to_repeat);
		if (ins->instruction_data.lang_cmd.cmd.if_cmd.body)
			free(ins->instruction_data.lang_cmd.cmd.if_cmd.body);
		if (ins->instruction_data.lang_cmd.cmd.else_if_cmd.body)
			free(ins->instruction_data.lang_cmd.cmd.else_if_cmd.body);
	}
	return (true);
}

int			interpret_source(char *filename, t_object *object_list,
	t_rt_utils *utils)
{
	t_ins	ins;
	t_list	*instruction_list_head;
	int		fd;
	char	*source_line;

	if (fd_check_param(filename, ".rt") == false)
		exit(EXIT_FAILURE);
	ft_bzero(&ins, sizeof(t_ins));
	fd = open_file(filename);
	get_next_line(fd, &source_line);
	instruction_get(source_line, &ins);
	free(source_line);
	instruction_list_head = list_init_list(&ins, sizeof(ins));
	while ((get_next_line(fd, &source_line)))
	{
		instruction_get(source_line, &ins);
		list_add_end(instruction_list_head, list_init_list(&ins, sizeof(ins)));
		free(source_line);
	}
	execute_instruction_list(instruction_list_head, object_list, utils);
	clear_list(instruction_list_head);
	list_delete_list(instruction_list_head);
	close(fd);
	return (0);
}
