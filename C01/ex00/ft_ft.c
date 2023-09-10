/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 12:37:16 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 16:51:21 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
//function that takes a pointer to int as a parameter
void	ft_ft(int* nbr)

{
	//dereference the pointer and set the value to 42
	*nbr = 42;
}

int main(void) 
{
	int num = 0; // Initialize an integer variable
	int* ptr = &num; // Create a pointer pointing to num
	
	printf("Before: %d\n", num);
	ft_ft(ptr); // Call the function to set the value to 42
	printf("After: %d\n", num);
	// At this point, num's value will be 42
    return 0;
}

    

