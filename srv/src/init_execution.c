#include "server.h"

s_execution *add_execution_list(s_execution *list, char *buffer)
{
    s_execution        *new = NULL;
    s_execution        *tmp = NULL;

    if ((new = malloc(sizeof(s_execution))) == NULL)
        return (NULL);
    new->cmd = strdup(buffer);
    new->time = get_time_micro();
    new->next = NULL;
    if (list == NULL)
        return (new);
    else {
        tmp = list;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
        return (list);
    }
}

s_execution *pop_element_execution(s_execution *list, char *buffer)
{
    (void)list;
    (void)buffer;
    return (NULL);
}

void print_execution(s_execution *list)
{
    s_execution *tmp = list;
    
    if (tmp == NULL)
        return;
    while (tmp) {
        printf("command = %s\n", tmp->cmd);
        tmp = tmp->next;
    }
}