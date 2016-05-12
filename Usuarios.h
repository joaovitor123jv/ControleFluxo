// Esse arquivo contem as funções que mexem com o usuario, cria usuário, exclui, checa se tem nome único.....
//
//Esse arquivo, mexe com arquivos, vai perceber o "FILE* arquivo", isso é um ponteiro que aponta pra arquivo
//é bem fácil de entender, sem drama
//kkkk
//
//
int login(char nomeusuario[100]) //Retorna número do usuário >= 1, se não der certo, retorna false(0)
{
	int encontrou;
	usuario novo;
	strcpy(novo.nomeusuario, nomeusuario);
	usuario antigo;
	arquivo checa;
	checa.usuarios = fopen(CAMINHOUSUARIO, "r");
	checa.senhas = fopen(CAMINHOSENHA, "r");
	if(checa.usuarios == NULL || checa.senhas == NULL)
	{
		CLEAR;
		printf("\t\tERRO\n\n\a");
		if(checa.usuarios == NULL) printf("Arquivo %s faltando \a\n", CAMINHOUSUARIO);
		if(checa.senhas == NULL) printf("Arquivo %s faltando \n", CAMINHOSENHA);
		printf("Seu programa será encerrado\n");
		printf("Crie um novo usuário, ou volte às configurações padrão\n\n");
		ESPERA;
		return false;
	}
	else
	{
		// CRIAR FUNÇÃO PARA CHECAR NOME DE USUARIO E SENHAS
		do
		{
			fscanf(checa.usuarios, "%d- %s %d-%d-%d\n", &antigo.numerousuario, antigo.nomeusuario, &antigo.data.dia, &antigo.data.mes, &antigo.data.ano);
			if(strcmp(antigo.nomeusuario, novo.nomeusuario) == 0)
			{
				CLEAR;
				novo.numerousuario = antigo.numerousuario;
				encontrou = true;
				break;
			}
		}while(!feof(checa.usuarios));
		
		CLEAR;
		printf("Digite sua senha\n");
		LIMPABUFFER;
		scanf("%s", novo.senha);
		CLEAR;
		
		if(encontrou == true)
		{
			encontrou = false;
			do
			{
				fscanf(checa.senhas, "%d- %s\n", &antigo.numerousuario, antigo.senha);
				if((antigo.numerousuario == novo.numerousuario)&&(strcmp(antigo.senha, novo.senha)==0)) encontrou = true;
			}while(!feof(checa.senhas));
			
			if(encontrou==true)
			{
				CLEAR;
				printf("Usuário encontrado e autorizado, com senha");
				printf("novo.numerousuario == %d", novo.numerousuario);
				return novo.numerousuario;
			}
			else
			{
				CLEAR;
				return false;
			}
		}
		else
		{
			CLEAR;
			return false;
		}
	}
	return false;
}


short ChecaUnicoUsuarioNome(usuario novo)
{
	usuario teste;
	arquivo Usuario;
	Usuario.usuarios = fopen(CAMINHOUSUARIO, "r");
	if(Usuario.usuarios == NULL) return true;
	else
	{
		do
		{
			fscanf(Usuario.usuarios, "%d- %s %d-%d-%d\n", &teste.numerousuario, teste.nomeusuario,  &teste.data.dia, &teste.data.mes, &teste.data.ano);
			if(strcmp(teste.nomeusuario, novo.nomeusuario)==0) return false;
		}while(!feof(Usuario.usuarios));
	}
	return true;
}

int EscreveUsuario(usuario novo)
{
	arquivo ARQUIVO;
	usuario teste;
	tempo hoje = data(); // <<<<=== FUNÇÂO PRA PEGAR TEMPO DO SISTEMA OPERACIONAL
	short i = false;
	ARQUIVO.usuarios = fopen(CAMINHOUSUARIO, "r");
	ARQUIVO.senhas = fopen(CAMINHOSENHA, "r");
	if(ARQUIVO.usuarios== NULL && (ARQUIVO.senhas==NULL))//Abre o arquivo de usuarios
	{
		system("mkdir despesas");
		printf("\nArquivos não existem, criando\n");
		ARQUIVO.usuarios = fopen(CAMINHOUSUARIO, "w+t");
		ARQUIVO.senhas = fopen(CAMINHOSENHA, "w+t");
		i = true;
	}
	else
	{
		fclose(ARQUIVO.usuarios);
		fclose(ARQUIVO.senhas);
		ARQUIVO.usuarios = fopen(CAMINHOUSUARIO, "r+t");
		ARQUIVO.senhas = fopen(CAMINHOSENHA, "r+t");
	}
	printf(" Arquivos criados \n"); 
	if(i==true)
	{
		printf(" Entrou no IF \n");
		fprintf(ARQUIVO.usuarios, "1- %s %d-%d-%d\n", novo.nomeusuario, hoje.dia, hoje.mes, hoje.ano);
		fprintf(ARQUIVO.senhas, "1- %s\n", novo.senha);
		fclose(ARQUIVO.usuarios);
		fclose(ARQUIVO.senhas);
		return 1;
	}
	else
	{
		do
		{
			fscanf(ARQUIVO.usuarios, "%d- %s %d-%d-%d\n", &teste.numerousuario, teste.nome, &teste.data.dia, &teste.data.mes, &teste.data.ano );
		}while(!feof(ARQUIVO.usuarios));
		
		do
		{
			fscanf(ARQUIVO.senhas, "%d- %s\n", &teste.numerousuario, teste.senha);
		}while(!feof(ARQUIVO.senhas));
		// FUNÇÃO PRA PEGAR TEMPO JÁ FEITA, VER ACIMA
		fprintf(ARQUIVO.usuarios, "%d- %s %d-%d-%d\n", (teste.numerousuario+1), novo.nomeusuario, hoje.dia, hoje.mes, hoje.ano);
		fprintf(ARQUIVO.senhas, "%d- %s\n",(teste.numerousuario+1), novo.senha);
		fclose(ARQUIVO.senhas);
		fclose(ARQUIVO.usuarios);
		return (teste.numerousuario+1);
	}
}


short CriaUsuario()
{
	usuario novo;
	controle geral;
	short done_aux = false;
	do
	{
		do
		{
			CLEAR;
			printf("Digite o nome do usuário que deseja criar (Não pode conter espaços em branco, será o nome que irá utilizar para acessar o programa) \n");
			printf("\t*Diferencia maiúsculas de minúsculas\n\n→");
			LIMPABUFFER;
			scanf("%s", novo.nomeusuario);
			CLEAR;
			printf("Nome digitado -> %s \n\n", novo.nomeusuario);
			if(novo.nomeusuario[0] == '0' && novo.nomeusuario[1]=='\0')
			{
				CLEAR;
				printf("Nome de usuário deve ser diferente de \"0\", para previnir erros\n");
				ESPERA;
				CLEAR;
				LIMPABUFFER;
				done = false;
			}
			if((novo.nomeusuario[0] == 'q'||novo.nomeusuario[0]=='Q') && novo.nomeusuario[1]=='\0')
			{
				CLEAR;
				printf("Nome de usuário deve ser diferente de \"%c\", para previnir erros\n", novo.nomeusuario[0]);
				ESPERA;
				CLEAR;
				LIMPABUFFER;
				done = false;
			}
			else
			{
				printf("Tem certeza desse nome ? (S/N) ");
				LIMPABUFFER;
				scanf("%c",&geral.decisao);
				(geral.decisao=='S'||geral.decisao=='s')? (done = true) : (done = false);
				if(done == false)
				{
					CLEAR;
					printf("Deseja tentar novamente ? (S/N) \n");
					LIMPABUFFER;
					scanf("%c", &geral.decisao);
					(geral.decisao=='S'||geral.decisao=='s')? (done = false) : (done = true);
				}
			}
		}while(done==false);
		done_aux = ChecaUnicoUsuarioNome(novo);
		if(done_aux == false)
		{
			CLEAR;
			printf("Nome de usuário já utilizado\n");
			printf("Por favor, tente novamente\n");
			ESPERA;
			CLEAR;
		}
	}while(done_aux==false);
	done_aux=false;
	do
	{
		CLEAR;
		printf("Digite sua nova senha (diferencia maiúsculas de minúsculas, não aceita espaços em branco)\n\n→");
		LIMPABUFFER;
		scanf("%s", novo.senha);
		CLEAR;
		printf("Por favor, confirme sua senha (Digite Novamente)\n\n→");
		LIMPABUFFER;
		scanf("%s", novo.confirmasenha);
		if(strcmp(novo.senha, novo.confirmasenha)==0) done = true;
		else
		{
			CLEAR;
			printf("Senhas não correspondem, deseja tentar novamente ? (S/N) \n\n→");
			LIMPABUFFER;
			scanf("%c",&geral.decisao);
			if(geral.decisao=='S'||geral.decisao=='s') done = false;
			else return false;
		}
	}while(done==false);
	CLEAR;
	printf(" Criando usuário\n");
	return EscreveUsuario(novo);
}

int LOGIN()
{
	CLEAR;
	usuario entrada;
	do
	{
		CLEAR;
		printf("\t**************Bem-vindo***********\n\n");
		printf("Para criar seu usuário, digite \"0\"\t\t");
		printf("Para sair, digite \"q\" \n");
		printf("Digite seu nome de usuário\n\n→");
		LIMPABUFFER;
		scanf("%s", entrada.nomeusuario);
		if(entrada.nomeusuario[0] == '0' && entrada.nomeusuario[1] == '\0')
		{
			if(CriaUsuario()>=true)
			{
				CLEAR;
				printf("Usuário Criado com Sucesso \n");
				ESPERA;
				printf("************Bem-Vindo \n"); 
				done = true;
			}
			else
			{
				CLEAR;
				printf("Usuário não foi criado, verifique suas permissões de acesso \n");
				printf("\n\nVoltando para a tela inicial\n");
				done = false;
			}
		}
		if((entrada.nomeusuario[0] =='q' || entrada.nomeusuario[0] =='Q')&&entrada.nomeusuario[1] == '\0')
		{
			CLEAR;
			printf("Programa Encerrado\n");
			done = -1;
			ESPERA;
			CLEAR;
			return false;
		}
		else // COMEÇO DO PROGRAMA, MANDA INFORMAÇÕES DE LOGIN PRA FUNÇÃO LOGIN
		{
			if(entrada.nomeusuario[0] == '0' && entrada.nomeusuario[1] == '\0')
			{
				CLEAR;
				printf("Usuário criado, voltando para a seleção\n");
				done = false;
			}
			else
			{
				CLEAR;
				done = login(entrada.nomeusuario);
				if(done>=true)
				{
					return done;
				}
				else
				{
					CLEAR;
					printf("Falha de login\n");
					printf("Verifique seu nome de usuario e sua senha, e tente novamente\n");
					done = false;
					ESPERA;
				}
			}
		}
	}while(done <= false);
	done = false;
	return done;
	
}
