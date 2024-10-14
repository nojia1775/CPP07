#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define IN 0
#define OUT 1

typedef struct s_args
{
	char	**content;
	int	size;
}	t_args;

typedef struct s_pipex
{
	int	argc;
	t_args	*cmd;
	char	**env;
	int	*fd;
	int	nbr_cmd;
}		t_pipex;

char	*ft_strdup(char *str)
{
	size_t	size;
	char	*result;
	int	i;

	size = strlen(str);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	pipex(t_pipex *global, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(global->fd[OUT], OUT);
		close(global->fd[IN]);
		execve(global->cmd[0].content[0], global->cmd[0].content, global->env);
	}
	else if (pid > 0)
	{
		dup2(global->fd[IN], IN);
		close(global->fd[OUT]);
		execve(global->cmd[0].content[0], global->cmd[0].content, global->env);
	}
}

int	size_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	***split_cmd(char **argv, int argc, int *nbr)
{
	int	i;
	t_args	*cmd;
	int	k;
	int	count;

	i = 0;
	while (argv[i])
	{
		if (!strcmp(argv[i++], ";"))
			(*nbr)++;
	}
	cmd = (t_args *)malloc(sizeof(t_args) * (*nbr + 1));
	if (!cmd)
		return (NULL);
	i = argc - 1;
	count = *nbr;
	while (i > 0)
	{
		if (!strcmp(argv[i], ";"))
		{
			argv[i] = NULL;
			cmd[count--].content = argv + 1 + i;
		}
		if (i == 1)
			cmd[count--].content = argv + i;
		i--;
	}
	return (cmd);
}

void	pipe_to_null(t_pipex *global)
{
	int	i;
	int	j;

	i = 0;
	while (i < global->nbr_cmd)
	{
		j = 0;
		while (global->cmd[i].content[j])
		{
			if (!strcmp(global->cmd[i].content[j], "|"))
				global->cmd[i].content[j] = NULL;
			j++;
		}
		
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	global;
	int	size;

	size = 0;
	if (!env[0])
		return (1);
	global.argc = argc;
	global.env = env;
	global.cmd = split_cmd(argv, argc, &size);
	if (!global.cmd)
		return (2);
	global.nbr_cmd = size + 1;
	return (0);
}