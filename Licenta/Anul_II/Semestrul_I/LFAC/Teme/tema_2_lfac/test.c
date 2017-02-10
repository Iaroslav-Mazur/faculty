#include<string.h>
#include<stdlib.h>
#include<stdio.h>


struct variabila
{
	int valoare;
	char nume[50];
	int initializat;
};

struct variabila *variabile = NULL;
int numarVariabile = 0;
char *buffer = NULL;
int nrInstructiuni = 0;

void afisare_buffer()

{

	printf("%s", buffer);

	free(buffer);

	free(variabile);

}



int variabila_este_declarata(char *numeVar)

{

	int i;

	for (i = 0; i < numarVariabile; ++i)

	if (strcmp(numeVar, variabile[i].nume) == 0) return i;

	return -1;

}



void declarare_cu_initializare(char *numeVar, int val)

{

	variabile = (struct variabila *)realloc(variabile, (numarVariabile + 1) * sizeof(struct variabila));

	strcpy(variabile[numarVariabile].nume, numeVar);

	variabile[numarVariabile].valoare = val;

	variabile[numarVariabile++].initializat = 1;

}



void declarare_fara_initializare(char *numeVar)

{

	variabile = (struct variabila *)realloc(variabile, (numarVariabile + 1) * sizeof(struct variabila));

	strcpy(variabile[numarVariabile].nume, numeVar);

	variabile[numarVariabile++].initializat = 0;

}



void print(char *id)

{

	if (buffer == NULL)

	{

		buffer = (char *)malloc(2);//initializare buffer

		strcpy(buffer, "\0");

	}

	nrInstructiuni++;

	int poz = variabila_este_declarata(id);

	char numar[5],valoare[10];

	sprintf(numar,"%d",nrInstructiuni);

	sprintf(valoare,"%d",variabile[poz].valoare);

	char mesajInstructiune[10000] = "Instructiunea print numarul ";

	strcat(mesajInstructiune, numar);

	strcat(mesajInstructiune, ": ");

	strcat(mesajInstructiune, variabile[poz].nume);

	strcat(mesajInstructiune, " = ");

	strcat(mesajInstructiune, valoare);

	strcat(mesajInstructiune, ".\n\0");

	buffer = (char*)realloc(buffer, strlen(buffer)+strlen(mesajInstructiune)+1);

	strcat(buffer, mesajInstructiune);

}





int medie_aritmetica(int a, int b)

{

	return (a + b) / 2;

}



int oglindit(int x)

{

	int og = 0;

	while (x)

	{

		og = og * 10 + x % 10;

		x /= 10;

	}

	return og;

}



int palindrom(int x)

{

	int og = oglindit(x);

	if (x == og)

		return 1;

	else return 0;

}



int cifra_control(int x)

{

	return x % 9;

}



int maxim(int a, int b)

{

	if (a > b) return a;

	else return b;

}



int putere_a_lui_2(int x)

{

	return !(x & (x - 1));

}
