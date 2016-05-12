//Arquivo que escreve os dados obtidos pelas outras funções no arquivo "dados.txt", dentro da pasta "despesas"

int EscreveValor(char sinal, float valor, int numerousuario, int operacao)
{
	arquivo usuarios;
	int operacao_do_dia = 0;
	char lixo;
	tempo antes;
	usuario atual;
	tempo hoje = data();
	controle dinheiro;
	usuarios.dados = fopen(CAMINHODADOS, "r");
	if(usuarios.dados == NULL)
	{
		usuarios.dados = fopen(CAMINHODADOS, "w");
		fprintf(usuarios.dados, "%d- 1- 2- (%c)%f %d/%d/%d\n", numerousuario, sinal, valor, hoje.dia, hoje.mes, hoje.ano);
		fclose(usuarios.dados);
		if(sinal == '-')
		{
			dinheiro.saldo = dinheiro.valor*(-1);
		}
		return true;
	}
	else
	{
		fclose(usuarios.dados);
		usuarios.dados = fopen(CAMINHODADOS, "r+");
		do
		{
			fscanf(usuarios.dados, "%d- %d- %d- (%c)%f %d/%d/%d\n", &atual.numerousuario, &atual.operacao_do_dia, &atual.operacao, &lixo, &dinheiro.valor, &antes.dia, &antes.mes, &antes.ano);
			if(atual.numerousuario == numerousuario)
			{
				if(antes.dia == hoje.dia && antes.mes == hoje.mes && antes.ano == hoje.ano)
				{
					operacao_do_dia = atual.operacao_do_dia;
				}
			}
		}while(!feof(usuarios.dados));
		fprintf(usuarios.dados, "%d- %d- %d- (%c)%f %d/%d/%d\n", numerousuario, operacao_do_dia+1, operacao, sinal, valor, hoje.dia, hoje.mes, hoje.ano);
		fclose(usuarios.dados);
		return true;
	}
}

controle SALDO(int numerousuario)
{
	arquivo usuarios;
	tempo antes;
	usuario atual;
	controle dinheiro;
	dinheiro.saldo = 0;
	dinheiro.valor = 0;
	usuarios.dados = fopen(CAMINHODADOS, "r");
	if(usuarios.dados == NULL)
	{
		printf("\n*************ERRO*************\n\a\a\a");
		printf("Arquivo %s não encontrado \n",CAMINHODADOS);
		dinheiro.saldo = false;
		ESPERA;
		return dinheiro;
	}
	else
	{
		do
		{
			fscanf(usuarios.dados, "%d- %d- %d- (%c)%f %d/%d/%d\n", &atual.numerousuario, &atual.operacao_do_dia, &atual.operacao, &dinheiro.sinal, &dinheiro.valor, &antes.dia, &antes.mes, &antes.ano);
			if(atual.numerousuario == numerousuario)
			{
				if(dinheiro.sinal=='-')
				{
					dinheiro.valor = dinheiro.valor*(-1);
				}
				dinheiro.saldo += dinheiro.valor;
			}
		}while(!feof(usuarios.dados));
		fclose(usuarios.dados);
		return dinheiro;
	}
}
