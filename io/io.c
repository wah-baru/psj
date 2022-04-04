#include <stdio.h>

#define MAX_SIZE 255

void main()
{
	FILE * fileinput;
	char buff[MAX_SIZE];
	if ((fileinput = fopen("input.txt", "r")) == NULL)
	{
		fprintf(stderr, "Tidak bisa membuka input.txt");
		exit(0);
	}

	while (!feof(fileinput))
	{
		fscanf(fileinput, "%s", &buff);
		if (strcmp(buff, "10") == 0)
		{
			fscanf(fileinput, "%s", &buff);
			printf("Nama: %s\n", buff);
		}

		if (strcmp(buff, "20") == 0)
		{
			fscanf(fileinput, "%s", &buff);
			printf("Kota: %s\n", buff);
		}

		if (strcmp(buff, "30") == 0)
		{
			fscanf(fileinput, "%s", &buff);
			printf("Provinsi: %s\n", buff);
		}

		if (strcmp(buff, "40") == 0)
		{
			fscanf(fileinput, "%s", &buff);
			printf("Negara: %s\n", buff);
		}
	}

	fclose(fileinput);
}
