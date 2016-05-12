tempo data()
{
	tempo hoje;
	FILE* datadeacesso;
	CLEAR;
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	char lixo[3];
	short lixox;
	char meschar[3];
	time( &rawtime );

	info = localtime( &rawtime );
	datadeacesso = fopen(".data.txt", "w+t");
	fprintf(datadeacesso, "%s", asctime(info));
	fclose(datadeacesso);
	datadeacesso = fopen(".data.txt", "r");
	LIMPABUFFER; //Limpa Buffer
	fscanf(datadeacesso, "%s %s %d %d:%d:%d %d", lixo, meschar, &hoje.dia, &hoje.hora, &hoje.minuto, &lixox, &hoje.ano);
	fclose(datadeacesso);
	if(strcmp(meschar, "Jan")==0)
	{
		hoje.mes = 1;
	}
	if(strcmp(meschar, "Feb")==0)
	{
		hoje.mes = 2;
	}
	if(strcmp(meschar, "Mar")==0)
	{
		hoje.mes = 3;
	}
	if(strcmp(meschar,"Apr")==0)
	{
		hoje.mes = 4;
	}
	if(strcmp(meschar ,"May")==0)
	{
		hoje.mes = 5;
	}
	if(strcmp(meschar,"Jun")==0)
	{
		hoje.mes = 6;
	}
	if(strcmp(meschar,"Jul")== 0)
	{
		hoje.mes = 7;
	}
	if(strcmp(meschar ,"Aug")==0)
	{
		hoje.mes == 8;
	}
	if(strcmp(meschar,"Sep")==0)
	{
		hoje.mes = 9;
	}
	if(strcmp(meschar, "Oct")==0)
	{
		hoje.mes = 10;
	}
	if(strcmp(meschar ,"Nov")==0)
	{
		hoje.mes = 11;
	}
	if(strcmp(meschar, "Dec")== 0)
	{
		hoje.mes = 12;
	}
	if(hoje.mes!= 1&&hoje.mes!= 2&&hoje.mes!= 3&&hoje.mes!= 4&&hoje.mes!= 5&&hoje.mes!= 6&&hoje.mes!= 7&&hoje.mes!= 8&&hoje.mes!= 9&&hoje.mes!= 10&&hoje.mes!= 11&&hoje.mes!= 12)
	{
		system("clear");
		printf("ERRO\n");
		printf("Mês não encontrado no Database\n");
	}
	EXCLUIARQUIVODATA;
	CLEAR;
	return hoje;
}