#include "monty.h"
monty_data_t data = {"\0", NULL, NULL};
/**
 * main - reads instruction from monty bytecode file.
 * @argc: arguments count.
 * @argv: arguments passed.
 * Return: 0 if success and EXIT_FAILURE if failed.
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	unsigned int line_number;

	line_number = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.file_ptr = fopen(argv[1], "r");
	if (data.file_ptr == NULL)
	{
		free_stack(&data.stack);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(data.buffer, BUFFER_MAX, data.file_ptr) != NULL)
	{
		handle_instructions(&data, line_number);
		line_number++;
	}
	fclose(data.file_ptr);
	free_stack(&data.stack);

	return (0);
}
/**
 * handle_instructions - this function manage instructions.
 * @buffer: is the line that has the struction.
 * @line_number: is the line number
 */
void handle_instructions(__attribute__((unused)) monty_data_t *d,
	       	unsigned int line_number)
{
	bool unknown = false;
	char *command;
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (data.buffer[0] == '\n' || data.buffer[0] == '\0')
        return;
	command = strtok(data.buffer, " \t\n");
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, command) == 0)
		{
			printf("%s\n", command);
			instructions[i].f(&data.stack, line_number);
			unknown = false;
			break;
		}
		else
		{
			unknown = true;
		}
		i++;
	}
	if (unknown)
	{
		free_stack(&data.stack);
		fclose(data.file_ptr);
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number,
				command);
		exit(EXIT_FAILURE);
	}
}
