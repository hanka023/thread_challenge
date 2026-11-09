
#include "queen.h"


void solution_to_lst(t_data *data)
{

	t_list	*head;
	t_list	*lst;

	lst = new_list(data);
	add_back(&head, lst);	

	data -> lst = head;
}

t_list	*new_list(t_data *data)
{
	t_list	*lst;
	int i = 0;

	lst = malloc (sizeof (t_list));
	if (!lst)
		return (NULL);
	lst -> str = malloc (sizeof (int) * (data -> n));
	if (!lst -> str)
		return (NULL);
	while (i < (data -> n))
	{
		lst -> str[i] = data -> board[i];
		++i;
	}
	lst -> next = NULL;
	return (lst);
}

void	add_back(t_list **head, t_list *lst)
{
	t_list	*tmp;

	if (!head || !lst)
		return ;
	if (*head == NULL)
	{
		*head = lst;
		return ;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = lst;
}


void	print_list(t_list *lst, int len)
{
	int i = 0;
	
	while (lst != NULL)
	{
		i = 0;
		while (i < len)
		{
			
			printf(YELLOW"%d "RESET, lst -> str[i]);
			++i;
		}
		printf ("\n");
		lst = lst -> next;
		
	}
	return ;
}

void	free_list(t_list *lst)
{
	t_list	*free_list;

	while (lst != NULL)
	{
		free_list = (lst-> next);
		free (lst -> str);
		free(lst);
		lst = free_list;
	}
	return ;
}
