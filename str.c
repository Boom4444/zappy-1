/*
** str.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jul 10 15:46:40 2013 ivan ignatiev
** Last update Thu Jul 11 19:36:18 2013 ivan ignatiev
*/

#include        "main.h"
#include        "error.h"
#include        "str.h"

char            *stralloccat(char *dest, char *src)
{
    int         use;
    int         len;
    char        *dest_new;

    len = dest == NULL ? 0 : strlen(dest);
    use = len;
    len += (src == NULL ? 0 : strlen(src)) + 1;
    if ((dest_new = (char*)realloc(dest, sizeof(char) * len)) != NULL)
    {
        if (!use)
        {
            *dest_new = 0;
            strcpy(dest_new, src);
        }
        else
            strcat(dest_new, src);
        return (dest_new);
    }
    error_show("stralloccat", "realloc", "Unable to allocate memory");
    return (NULL);
}

char            *getnextline(char *str)
{
    int         linelen;
    char        *eol;
    char        *line;

    if (str == NULL)
        return (NULL);
    eol = strchr(str, '\n');
    linelen = (eol - str) + 1;
    if (linelen > 1
            && (line = (char*)calloc(linelen, sizeof(char))) != NULL)
    {
        strncpy(line, str, linelen - 1);
        strcpy(str, eol + 1);
        return (line);
    }
    return (NULL);
}


