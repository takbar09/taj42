/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 15:50:45 by takbar        #+#    #+#                 */
/*   Updated: 2023/06/23 16:49:33 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "commands.h"
#include "init_stack.h"
#include "check_args.h"

static struct stack a;
static struct stack b;

/*
static  char    **ft_mem_free(char **res)
{
    int i;

    i = 0;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
    return (NULL);
}*/

static  int ft_count_word(char const *s, char c)
{
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while (s[i])
    {
        if (s[i] == c)
        i++;
        else
        {
            cnt++;
            while (s[i] && s[i] != c)
            i++;
        }
    }
    return (cnt);
}

/*

static  char    *ft_word_make(char *word, char const *s, int k, int word_len)
{
    int i;

    i = 0;
    while (word_len > 0)
    {
        word[i] = s[k - word_len];
        i++;
        word_len--;
    }
    word [i] = '\0';
    return (word);
}

static  char    **ft_split2(char **res, char const *s, char c, int num_word)
{
    int i;
    int k;
    int word_len;

    i = 0;
    k = 0;
    word_len = 0;
    while (s[k] && i < num_word)
    {
        while (s[k] && s[k] == c)
            k++;
        while (s[k] && s[k] != c)
        {
            k++;
            word_len++;
        }
        res[i] = (char *) malloc(sizeof(char) * (word_len + 1));
        if (!(res[i]))
            return (NULL);
        ft_word_make(res[i], s, k, word_len);
        word_len = 0;
        i++;
    }
    res[i] = 0;
    return (res);
}

char    **ft_split(const char *s, char c)
{
    int     num_word;
    char    **res;

    if (s == 0)
        return (NULL);
    num_word = ft_count_word(s, c);
    res = (char **) malloc(sizeof(char *) * (num_word + 1));
    if (!(res))
        return (NULL);
    if (!ft_split2(res, s, c, num_word))
    {
        ft_mem_free(res);
        return (NULL);
    }
    return (res);
} */

void push_min_to_stack_b(void)
{
    int smallest_index;

    smallest_index = stack_smallest_index(&a);
    
    while(smallest_index != 0)
    {       
        if (smallest_index < a.count/2)
            rotate_ab(&a, 'a');
        else
            reverse_rotate_ab(&a, 'a');    
        smallest_index = stack_smallest_index(&a);
    }
    push_ab(&a, &b, 'b');
}

void push_max_to_end(void)
{
    int largest_index;

    largest_index = stack_largest_index(&a);

    if (largest_index == 0)
        rotate_ab(&a, 'a');
    if (largest_index == 1)
        reverse_rotate_ab(&a, 'a');
}

void simple_sort(void)
{
    if (is_stack_sorted(&a))
        return;

    while (a.count > 3)
        push_min_to_stack_b();

    if (a.count == 3)
        push_max_to_end();
        
    if (a.count == 3 || a.count == 2)
        if (a.stack_arr[0] > a.stack_arr[1])
            swap_ab(&a, 'a');

    while (b.count > 0)
        push_ab(&a, &b,'a');
}

int radix_sort(void)
{
    int bit;
    int i;

    bit = 0;
    while (bit < 32)
    {
        i = 0;
        while (i < a.size)
        {
            if (is_stack_sorted(&a))
                break;
            if (a.stack_arr[0] & (1<<bit))
                rotate_ab(&a, 'a');
            else
                push_ab(&a, &b, 'b');
            i++;
        }
        
        while(b.count > 0)
            push_ab(&a, &b, 'a');;
        bit++;
    }
    return (0);
}

int push_swap(int arg_count, char **args)
{
    if (!args)
        return (-1);
    if (check_args(arg_count, args) == -1)
        return (-1);
    if (init_stacks(arg_count, args, &a, &b) == -1)
        return (-1);
    print_stacks(&a, &b);
    if (a.size <= 5)
        simple_sort();
    if (a.size > 5)
        radix_sort();
   // print_stacks(&a, &b);
    free(a.stack_arr);
    free(b.stack_arr);
    return (0);
}

int	main(int argc, char **argv)
{
    int return_value;
    char **args;
    int arg_count;

    if (argc == 1)
        return (0);
    if (argc == 2)
    {
        arg_count = ft_count_word(argv[1], ' ');
        args = ft_split(argv[1], ' ');
    }
    if (argc > 2)
    {
        arg_count = argc -1;
        args = argv+1;
    }
    return_value = push_swap(arg_count, args);
    if (return_value == -1)
        printf ("Error\n");
    return (return_value);
}
