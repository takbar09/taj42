/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultimate_ft.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <takbar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 13:28:33 by takbar        #+#    #+#                 */
/*   Updated: 2022/08/23 13:43:58 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void	ft_ultimate_ft(int *********nbr)

{
	*********nbr = 42;
}

int main(void)
{
	int mynum;

	mynum = 0;

	int* ptr;
	int** ptr1;
	int*** ptr2;
	int**** ptr3;
	int***** ptr4;
	int****** ptr5;
	int******* ptr6;
	int******** ptr7;
	int********* ptr8;

	ptr = &mynum;
	ptr1 = &ptr;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;

	printf("Before: %d\n", mynum);

	ft_ultimate_ft(ptr8);

	printf("After: %d\n", mynum);

	return 0;
}

