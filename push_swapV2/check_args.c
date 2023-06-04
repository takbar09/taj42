/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:49:20 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/04 18:53:20 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "check_args.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int check_digits(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while (argv[i][j] != '\0')
        {
            if(!isdigit(argv[i][j]))
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

    negative_number = 0;
    if (str[0] == '-')
        negative_number = 1;
    i = 1;
    while (i < argc)
    {
        str = argv[i];
        if (str[0] == '-' || str[0] == '+')
            str++;
        length = strlen(str);
        if (length > 10)
            return (-1);
        if (length == 10)
            if (negative_number && strcmp(str, "2147483648") > 0)
                return (-1);
            else if (strcmp(str, "2147483647") > 0)
                return (-1);
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
