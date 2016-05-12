
void texto_salario()
{
	FILE *arquivo=fopen(CAMINHOSALARIO, "r");
	if(arquivo == NULL)
	{
		CLEAR;
		printf("\t*************ERRO************\a\a\a\n");
		printf(" Arquivo \"%s\" não encontrado \n", CAMINHOSALARIO);
		ESPERA;
	}
	zeratexto();
	linha = 0;
	do
	{
		fgets(texto[linha], 199, arquivo); // EVITA POSSÍVEIS ERROS DE ALOCAÇÃO DE MEMÓRIA INCORRETA
		texto[linha][strcspn(texto[linha], "\n")] = 0;
		printf("%s\n", texto[linha]);
		linha ++;
	}while(!feof(arquivo));
}
void Declara_Salario(int numerousuario) 
{
	done = false;
	int operacao =2;
	controle dinheiro;
	do
	{
		CLEAR;
		texto_salario();
		LIMPABUFFER;
		do
		{
			dinheiro.valor = getfloat();
			if(dinheiro.valor < 0)
			{
				printf("\nPor favor, Digite um número positivo\n");
				printf("O computador se preocupa com o sinal ;) \n");
				done = false;
			}
			else
			{
				done = true;
			}
		}while(done == false);
		done = false;
		done = EscreveValor('+', dinheiro.valor, numerousuario, operacao);
		CLEAR;
		printf("Dados escritos com Sucesso \n");
	}while(done == false);
}
