#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @err_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int err_code, ...)
{
	va_list ags;
	char *opc;
	int l_num;

	va_start(ags, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ags, char *));
			break;
		case 3:
			l_num = va_arg(ags, int);
			opc = va_arg(ags, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ags, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @err_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_error(int err_code, ...)
{
	va_list ags;
	char *opc;
	int l_num;

	va_start(ags, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ags, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ags, int));
			break;
		case 8:
			l_num = va_arg(ags, unsigned int);
			opc = va_arg(ags, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, opc);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ags, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @err_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int err_code, ...)
{
	va_list ags;
	int l_num;

	va_start(ags, err_code);
	l_num = va_arg(ags, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
