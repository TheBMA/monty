#include "monty.h"

/**
 * main - an interpreter for Monty ByteCodes files.
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[256];
	char *token_list[2];
	int element, i = 1;
	long num;
	char *num_check = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		token_list[0] = strtok(line, " \n");

		if (token_list[0] != NULL)
		{
			if (strcmp(token_list[0], "push") == 0)
			{
				token_list[1] = strtok(NULL, " \n");
				if (token_list[1] != NULL)
				{
					num = strtol(token_list[1], &num_check, 10);
					if (*num_check != '\0' && *num_check != '\n')
					{
						fprintf(stderr, "L%d: usage: push integer\n", i);
						exit(EXIT_FAILURE);
					}
					element = num;
					push(element);
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", i);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(token_list[0], "pall") == 0)
			{
				pall();
			}
			else if (strcmp(token_list[0], "nop") == 0)
			{
				;
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", i, token_list[0]);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}

	fclose(file);
	return (0);
}

/**
 * push - a function that inserts an element into the stack
 * Prototype: void push(int element);
 * @element: integer to add to the stack
 * return: void
 */

void push(int element)
{
	stack_t *pointer = (stack_t *)malloc(sizeof(stack_t));

	if (pointer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (temp == NULL)
		{
			pointer->n = element;
			pointer->prev = NULL;
			pointer->next = NULL;
		}
		else
		{
			pointer->n = element;
			pointer->prev = NULL;
			pointer->next = temp;
		}
		temp = pointer;
	}
}

/**
 * pall - a function that displays the elements of the stack
 * Prototype: void pall();
 * return: void
 */

void pall(void)
{
	stack_t *pointer = temp;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}
