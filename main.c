#include "monty.h"

/** 
 * main - an interpreter for Monty ByteCodes files.
 * @argc: arguments count
 * @argv: arguments vector
 * return: 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[256];
	char *token_list[2];
	int element, i = 1;
	long num;
	char *num_check;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
/*If you can’t malloc anymore, print the error message Error: malloc failed,
followed by a new line, and exit with status EXIT_FAILURE. You have to use
malloc and free and are not allowed to use any other function from man malloc
(realloc, calloc, …)*/

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
					num = strtol(token_list[1], num_check, 10);
					if (*num_check != '\0' && *num_check != '\n')
					{
						printf("L%d: usage: push integer", i);
						exit(EXIT_FAILURE);
					}
					element = num;
					push(element);
				}
				else
				{
					printf("L%d: usage: push integer", i);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(token_list[0], "pall") == 0)
			{
				pall();
			}
			else
			{
				printf("L%d: unknown instruction %s\n", i, token_list[0]);
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

}

/** 
 * pall - a function that displays the elements of the stack
 * Prototype: void pall();
 * return: void
 */

void pall(void)
{

}
