int getint()
{
	int inteiro, lixo;
	short doneint=false;;
	do
	{
		if(scanf("%d", &inteiro)<=0)
		{
			printf("Desculpe, mas, você deve digitar um número inteiro\n");
			printf("Isso é, número sem vírgula, negativo ou positivo\n\n");
			printf("→");
			while(fgetc(stdin)!='\n');
			continue;
			doneint = false;
		}
		else
		{
			doneint = true;
		}
	}while(doneint==false);
	return inteiro;
}

float getfloat()
{
	float flutuante;
	short local_done=false;
	do
	{
		LIMPABUFFER;
		if(scanf("%f", &flutuante)<=0)
		{
			printf(" Desculpe, mas, você deve digitar um número\n");
			printf(" Esse número pode ser real, mas deve ser separado por vírgula\n");
			printf(" Exemplo: R$ 420.33 (quatrocentos e vinte reais, e trinta e três centavos)\n");
			printf(" Preste atenção ↑ no ponto, utilizado no lugar da vírgula\n");
			printf(" Tente novamente\n\n");
			local_done = false;
			while(fgetc(stdin)!='\n');
			continue;
		}
		else
		{
			local_done = true;
		}
	}while(local_done==false);

	return flutuante;
}

void ERRO_Caminhotexto_001(char tipoerro)
{
	if(tipoerro == '\0')
	{
		CLEAR;
		printf("\t******ERRO********\n\a\a\a");
		printf("Arquivo de texto não encontrado %s \n", CAMINHOTEXTO_001);
		ESPERA;
	}
}

void ERRO_Caminhotexto_002(char tipoerro)
{
	if(tipoerro == '\0')
	{
		CLEAR;
		printf("\t******ERRO********\n\a\a\a");
		printf("Arquivo de texto não encontrado %s \n", CAMINHOTEXTO_002);
		ESPERA;
	}
}

void ERRO_Caminhotexto_003(char tipoerro)
{
	if(tipoerro == '\0')
	{
		CLEAR;
		printf("\t******ERRO********\n\a\a\a");
		printf("Arquivo de texto não encontrado %s \n", CAMINHOTEXTO_003);
		ESPERA;
	}
}

void zeratexto()
{
	int da=0, ad=0;

	for(da=0 ; da<9 ; da++)
	{
		for(ad=0 ; ad<199; ad++)
		{
//			printf(" ESPERA \n");
		//	ESPERA;
			texto[da][ad] = '\0';
//			printf(" ESPERA 2 \n");
		//	ESPERA;
		}
	}
}
