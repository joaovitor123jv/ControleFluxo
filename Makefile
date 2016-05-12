#Compilador
CC = gcc

#Linkers

#Flags
PASSO1 = -c
PASSO2 = -o

#Nome do executavel
EXECUTAVEL = executavel


#Arquivo(s) a ser compilados
ARQ = main.c
OBJ = main.o


#Script a ser executado
EXECUCAO = sh
SCRIPT = script/executar.sh

make teste:
	clear
	$(CC) $(PASSO1) $(ARQ)
	$(CC) $(PASSO2) $(EXECUTAVEL) $(OBJ)
	chmod +x $(SCRIPT)
	$(EXECUCAO) $(SCRIPT)
#	echo "Programa Compilado, deseja executar ? (S/N)"
#	read VARIAVEL
#	if test "$(VARIAVEL)" = "s" || test "$(VARIAVEL)" = "S" then
#		./$(EXECUTAVEL)
#	else
#		clear
#		echo "Programa instalado com sucesso"
#	fi

make uninstall:
	clear
	rm $(OBJ)
	rm despesas/usuarios.txt
	rm despesas/senhas.txt
	rm despesas/dados.txt
	rm $(EXECUTAVEL)
