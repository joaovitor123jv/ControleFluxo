//Esse arquivo contém as diretivas de compilação
//Ele faz seu compilador reconhecer se é Windows, ou Linux, ajustando o código do programa
//Também define os "falsos" booleanos "true" e "false", que facilitam o entendimento do código
//


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#ifdef __WIN32
	#define LIMPABUFFER fflush(stdin);
	#define ESPERA system("pause");
	#define CLEAR system("cls");
		#define CAMINHOUSUARIO "despesas\\usuarios.txt"
		#define CAMINHOSENHA "despesas\\senhas.txt"
		#define CAMINHODADOS "despesas\\dados.txt"
		// ENDEREÇOS DE MENU
			#define CAMINHO_MAIN_MENU "despesas\\menu_principal.txt"
			#define CAMINHOSALARIO "despesas\\salario.txt"
			#define CAMINHOTEXTO_001 "despesas\\texto_001.txt"
			#define CAMINHOTEXTO_002 "despesas\\contapaga.txt"
			#define CAMINHOTEXTO_003 "despesas\\saldo.txt"

		//FIM  ENDEREÇOS MENU
		#define EXCLUIARQUIVODATA system("del .data.txt");
		#include<locale.h>
		#define ACENTUACAO setlocale(LC_ALL, " ");
#elif __linux
	#define LIMPABUFFER __fpurge(stdin);
	#define ESPERA __fpurge(stdin); printf("\nDigite \"enter\" para continuar\n"); getchar();
	#define CLEAR system("clear");
		#define CAMINHOUSUARIO "despesas/usuarios.txt"
		#define CAMINHOSENHA "despesas/senhas.txt"
		#define CAMINHODADOS "despesas/dados.txt"
		#define EXCLUIARQUIVODATA system("rm .data.txt");
		#define ACENTUACAO printf("Linux não precisa :P\n");
		// ENDEREÇOS DE MENU
			#define CAMINHO_MAIN_MENU "despesas/menu_principal.txt"
			#define CAMINHOTEXTO_001 "despesas/texto_001.txt"
			#define CAMINHOSALARIO "despesas/salario.txt"
			#define CAMINHOTEXTO_002 "despesas/contapaga.txt"
			#define CAMINHOTEXTO_003 "despesas/saldo.txt"
		//FIM ENDEREÇOS MENU
#endif
