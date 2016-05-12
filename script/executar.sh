echo
echo "Arquivo compilado, deseja executar ? "
echo
read VARIAVEL
if test "$VARIAVEL" = "s"
then
	./executavel
else
	echo "Compilação terminada"
fi
