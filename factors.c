#include <stdio.h>
#include <stdlib.h>

/**
 * prime_factorization - on numbers read from a file.
 *
 * @filename: A string representing the name of the file to read numbers from.
 */

void prime_factorization(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Could not open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	char line[120];

	while (fgets(line, sizeof(line), file) != NULL)
	{
		long long n = atoll(line); /* Use atoll for long long */

		for (long long p = 2; p < n; p++)
		{
			if (n % p == 0)
			{
				long long q = n / p;

				printf("%lld = %lld * %lld\n", n, q, p);
				break;
			}
		}
	}

	fclose(file);
}

/**
 * main - entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	prime_factorization(argv[1]);

	return (0);
}
