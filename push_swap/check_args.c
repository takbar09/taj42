
#include <string.h>
#include "check_args.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int check_digits(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][0] == '-' || argv[i][0] == '+')
            j++;
        while (argv[i][j] != '\0')
        {
            if(!ft_isdigit(argv[i][j]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_in_range(int argc, char **argv)
{
    int i;
    int length;
    char *str;
    int negative_number;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
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

int check_duplicates(int argc, char **argv)
{
    int i;
    int j;
    i = 1;
    while (i < argc)
    {
        j = i+1;
        while (j < argc)
        {
            if (strcmp(argv[i], argv[j]) == 0)
                return (-1);
            j++;
        }       
        i++;
    }
    return (0);
}

int check_args(int argc, char **argv)
{
    if (check_digits(argc, argv) == -1)
        return (-1);
    if (check_in_range(argc, argv) == -1)
        return (-1);
    if (check_duplicates(argc, argv) == -1)
        return (-1);
    return (0);
}
