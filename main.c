//Arquivo Principal
//Esse arquivo que vai ser a "raiz" do programa
//Ele vai conter a maioria dos textos, aqui só vamos basicamente organizar as funções
//e deixar o programa mais "linear", parte mais tranquila... de certa forma
int linha;
#include"Pre-Definicoes.h"
#include"arquivos.h"

void main()
{
	ACENTUACAO;
	int numerousuario;
	int escolha, i;
	usuario cliente;
	CLEAR;
	numerousuario = LOGIN();
	if(numerousuario== false)
	{
		CLEAR;
		printf("Fim do programa\n");
	}
	LIMPABUFFER;
	if(numerousuario>=true)
	{
		do
		{
			done = false;
			CLEAR;
			fflush(stdout);
			CLEAR;
			printf("\t***************Bem Vindo *******************\n");
			escolha = main_menu();
			switch(escolha)
			{
				case(0):
					CLEAR;
					printf("Programa Encerrado\n");
					done = true;
					break;
				case(1):
					A_Pagar(numerousuario);//Adiciona conta que a pessoa ainda precisa pagar
					done = false;
					ESPERA;
					break;
				case(2):
					CLEAR;
					Declara_Salario(numerousuario);// Adiciona Salario
					done = false;
					ESPERA;
					break;
				case(3):
					CLEAR;
					ContaPaga(numerousuario);//Adiciona conta que já foi paga
					done = false;
					ESPERA;
					break;
				case(4):
					CLEAR;
					Saldo(numerousuario);//Pra saber que viu o saldo
					done = false;
					break;
				default:
					Calc();
					printf(" Escolheu opção diferente do apresentado \n");
					printf(" Tente novamente\n");
					printf(" Para Sair, digite \"q\" aqui, para permanecer no programa, digite \"enter\" \n");
					LIMPABUFFER;
					scanf("%c", &global_decisao);
					if(global_decisao == 'q' || global_decisao =='Q')
					{
						done = true;
					}
					break;
			}
		}while(done == false);
		
	}
}
