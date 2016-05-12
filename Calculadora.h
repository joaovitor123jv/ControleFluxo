//Arquivo com Calculadora
float fat(a)// usa recursividade
{
	if(a==0) return 1;
	else return a*fat(a-1);
}

int pot(a, b)
{
	if(b==0)
	{
		return 1;
	}
	else return a*pot(a,b-1);
}

void Calc()
{
	float a, b;
	char operador;
	printf(" Ordem correta: Número(enter), operador(enter), número(enter) \nou simplesmente número(enter), operador(enter)\n\nOperadores aceitos (!, +, -, *, /, ^)\n ");
//	printf(" \n");
	a = getfloat();
	LIMPABUFFER;
	scanf("%c", &operador);
	if(operador == '+')
	{
		b = getfloat();
		printf("\n%f\n", a+b);
	}
	if(operador == '-')
	{
		b=getfloat();
		printf("\n%f\n", a-b);
	}
	if(operador == '*')
	{
		b = getfloat();
		printf("\n%f\n", a*b);
	}
	if(operador == '/')
	{
		b = getfloat();
		printf("\n%f\n", a-b);
	}
	if(operador == '!')
	{
		printf("\n %f\n",fat((int)a));
	}
	if(operador == '^')
	{
		b = getint();
		printf("\n %f\n", pot((int)a, b));
	}
}
