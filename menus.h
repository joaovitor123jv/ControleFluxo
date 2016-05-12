int main_menu()
{
	int escolha;
	linha=0;
	FILE *menu;
	menu = fopen(CAMINHO_MAIN_MENU, "r");
	if(menu == NULL)
	{
		CLEAR;
		printf("\n\t\t***ERRO***\n=>ARQUIVO DE MENU PRINCIPAL FALTANDO<=\a\n");
		return false;
	}
	do
	{
		fgets(texto[linha], 200, menu);
		texto[linha][strcspn(texto[linha], "\n")] = 0;
		printf("%s\n", texto[linha]);
		linha++;
	}while(!feof(menu));
	printf(" %d Opções\n", linha-2);
	printf("\n→");
	LIMPABUFFER;
	escolha = getint();
	return escolha;
}

void Texto_002()
{
	FILE *arquivo;
	linha =0;
	arquivo = fopen(CAMINHOTEXTO_002, "r");
	zeratexto();
	if(arquivo == NULL)	ERRO_Caminhotexto_002('\0');
	do
	{
		fgets(texto[linha], 199, arquivo); //EVITA OVERFLOW E POSSÍVEIS ERROS DE ALOCAÇÃO INCORRETA
		texto[linha][strcspn(texto[linha], "\n")] = 0;
		printf("%s\n", texto[linha]);
		linha ++;
	}while(!feof(arquivo));
}

void Texto_001()
{
	FILE *arquivo;
	linha =0;
	arquivo = fopen(CAMINHOTEXTO_001, "r");
	zeratexto();
	if(arquivo == NULL)	ERRO_Caminhotexto_001('\0');
	do
	{
		fgets(texto[linha], 199, arquivo); //EVITA OVERFLOW E POSSÍVEIS ERROS DE ALOCAÇÃO INCORRETA
		texto[linha][strcspn(texto[linha], "\n")] = 0;
		printf("%s\n", texto[linha]);
		linha ++;
	}while(!feof(arquivo));
}

void Texto_003()//SALDO
{
	FILE *arquivo;
	linha =0;
	arquivo = fopen(CAMINHOTEXTO_003, "r");
	zeratexto();
	if(arquivo == NULL)	ERRO_Caminhotexto_003('\0');
	do
	{
		fgets(texto[linha], 199, arquivo); //EVITA OVERFLOW E POSSÍVEIS ERROS DE ALOCAÇÃO INCORRETA
		texto[linha][strcspn(texto[linha], "\n")] = 0;
		printf("%s\n", texto[linha]);
		linha ++;
	}while(!feof(arquivo));
}