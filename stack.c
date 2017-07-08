#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct stack {
	int last;
	int *piece[];
};

void push(int value, struct stack *s)
{
	if (s->last == MAX_SIZE) {
		printf("Stack overflow");
		
		free(s);
		exit(1);
	}

	s->piece[s->last++] = value;
}

int pop(struct stack *s)
{
	if (s->last == 0) {
		printf("Stack is empty");
		return NULL;
	}
	
	s->last--;
	int res = s->piece[s->last];
	
	return res;
}

void print_stack(struct stack *s)
{
	int i = 0;
	while (i < s->last) {
		printf("%d element: %d\n", i, s->piece[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	struct stack *s = malloc(sizeof(struct stack));
	s->last = 0;
	push(34, s);
	push(67, s);

	print_stack(s);

	int l = pop(s);
	printf("last: %d, must be 67\n", l);
	print_stack(s);
		
	free(s);
	
	return 0;
}
