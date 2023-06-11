#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int swap_ab(struct stack *s, char c);
int push_ab(struct stack *a, struct stack *b, char c);
int rotate_ab(struct stack *s, char c);
int reverse_rotate_ab(struct stack *s, char c);

#endif