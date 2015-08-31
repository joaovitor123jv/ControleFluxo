#include<stdio.h>
//Esse arquivo foi feito para rodar em S.O. baseados em UNIX
int main()
{
	char nomeusuario[30];
	printf("\n\nOlá, seja bem-vindo, Esse é um programa projetado para Facilitar seu dia\n");
	printf("\t Por favor, digite seu nome de usuario abaixo\n Caso seja sua primeira vez usando esse programa no computador, digite \"0\"\n\n\n");
	scanf("%s",nomeusuario);
	printf("\n\n%s\n\n",nomeusuario);
	sleep(5);
	if(nomeusuario=="0")
	{
		system("clear");
		printf("Entrou no IF");
		system("./novousuario");
		return 0;
	}
	printf("Teste de Commit no Git");
	printf("\a\a");
	return 0;
}

