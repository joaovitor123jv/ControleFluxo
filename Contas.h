void A_Pagar(int numerousuario)
{
	done=false;
	int operacao = 1;
	controle dinheiro;
	usuario cliente;
	do
	{
		CLEAR;
		Texto_001();
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
		done = EscreveValor('-', dinheiro.valor, numerousuario, operacao);
		CLEAR;
		printf("Dados escritos com Sucesso \n");
	}while(done == false);
}

void ContaPaga(int numerousuario)
{
	done=false;
	int operacao = 3;
	controle dinheiro;
	usuario cliente;
	do
	{
		CLEAR;
		Texto_002();
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

void Saldo(int numerousuario)
{
	done=false;
	int operacao = 4;
	controle dinheiro;
	usuario cliente;
	CLEAR;
	done = false;
	dinheiro.valor = 0;
	done = EscreveValor('+', dinheiro.valor, numerousuario, operacao);
	dinheiro = SALDO(numerousuario);
	Texto_003();
	printf("R$ %0.2f\n\n", dinheiro.saldo);
	ESPERA;
}