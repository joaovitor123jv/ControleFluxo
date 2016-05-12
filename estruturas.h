//Esse arquivo contém as estruturas do programa todo, recomendo deixar ele aberdo de lado, pra checar sempre
//o nome das estruturas, evita problemas, principalmente quando está mexendo com usuários
typedef struct Tempo
{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
}tempo;

typedef struct Usuario
{
	char nome[100];
	char nomeusuario[100];
	char senha[100];
	char confirmasenha[100];
	int numerousuario;
	int operacao_do_dia;
	int operacao;
	tempo data;
}usuario;

typedef struct Arquivo
{
	FILE* usuarios;
	FILE* senhas;
	FILE* dados;
}arquivo;

typedef struct Controle
{
	char sinal;
	float valor;
	float saldo;
	char decisao;
	char operacao[100];
}controle;

char global_decisao;
// int global_escolha;
short done;

//ERRO NA FUNÇÃO (main_menu())
//
char texto[10][200];
