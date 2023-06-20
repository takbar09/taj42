
#include <string.h>
#include "check_args.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int check_digits(int arg_count, char **args)
{
    int i;
    int j;

    i = 0;
    while (i < arg_count)
    {
        j = 0;
        if (args[i][0] == '-' || args[i][0] == '+')
            j++;
        while (args[i][j] != '\0')
        {
            if(!ft_isdigit(args[i][j]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_in_range(int arg_count, char **args)
{
    int i;
    int length;
    char *str;
    int negative_number;

    i = 0;
    while (i < arg_count)
    {
        str = args[i];
        negative_number = 0;
        if (str[0] == '-')
            negative_number = 1;

        if (str[0] == '-' || str[0] == '+')
            str++;
        length = strlen(str);
        if (length > 10)
            return (-1);
        
        if (length == 10)
        {
            if (negative_number && strcmp(str, "2147483648") > 0)
                return (-1);
            else if (strcmp(str, "2147483647") > 0)
                return (-1);
        }
        i++;
    }
    return (0);
}

int check_duplicates(int arg_count, char **args)
{
    int i;
    int j;
    i = 0;
    while (i < arg_count)
    {
        j = i+1;
        while (j < arg_count)
        {
            if (strcmp(args[i], args[j]) == 0)
                return (-1);
            j++;
        }       
        i++;
    }
    return (0);
}

int check_args(int arg_count, char **args)
{
    if (check_digits(arg_count, args) == -1)
        return (-1);
        
    if (check_in_range(arg_count, args) == -1)
        return (-1);
    if (check_duplicates(arg_count, args) == -1)
        return (-1);
    return (0);
}
