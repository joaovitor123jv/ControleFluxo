# ControleFluxo
Programa escrito em C para um melhor gerenciamento de entrada e saída de dinheiro.
Aborda de forma generalizada as necessidades de gerenciamento de cada pessoa, não especifica, no momento, com o que o usuário gastou ou recebeu seu dinheiro, tendo assim somente 3 operações básicas: Entrada de dinheiro "recebimento de Salario", saída de dinheiro "Contas a pagar" (debita automaticamente do salário atual) e entrada de dinheiro extra "Contas Pagas"(Aumenta, do montante atual, o valor recebido, assumindo então, que o usuário recebeu dinheiro de outra forma, que não seja o Salário).

O Programa também contém funções que possibilitam ver  quantidade atual de dinheiro, sendo representado com um (-), quando usuário está dem déficit, ou seja, se o usuário estiver com falta de dinheiro, no momento.
Exemplo:
    R$ -350.00  (Significa que o usuário está devendo 350.00 reais pra alguém)
    R$ 350.00 (Significa que, com as contas atuais pagas, o usuário possui 350.00 reais livres, disponíveis para uso)

Compilação:
  Para compilar o projeto, é necessário ter em mente que:
    → O projeto original contava com 2 pastas extra, que, infelizmente não consegui colocar aqui
    → É necessário que tenha, ao menos um compilador "C" instalado em sua máquina, tal como gcc
    → O comando "make all", foi testado somente em sistemas GNU/Linux, ou seja, não há garantias que funcione em Windows, MacOSX, BSD, ou qualquer outro Sistema Operacional.
    → É recomendado que execute os comandos como não-root, para evitar qualquer erro em seu sistema
    → Esse projeto disponibiliza um Makefile SIMPLES, ou seja, não irá tratar quaisquer dependências
    
  OK, vamos à compilação:
    → Abra seu terminal, ou emulador de terminal favorito (No caso de Windows*, execute o comando "cmd" pra abrir um prompt de comandos)
    → Com o terminal/cmd aberto navegue até a pasta onde se encontram os arquivos do projeto
    → Em sistemas *nix 
      → Para compilar digite "make all"
      → Nesse momento o código será compilado, e será gerado um arquivo executavel (Para executar esse arquivo, digite "./executavel")
    → Em sistemas Windows*
      → Digite no prompt de comando "gcc -o executavel.exe main.c"
      → Nesse momento o arquivo será compilado e será gerado um arquivo executavel
      → Para executar o programa, basta clicar duas vezes sobre o arquivo "executavel.exe" que surgir em sua pasta
    

*Esse Programa é um projeto, e não vem com absolutamente nenhuma garantia, ou seja, não me responsabilizo por possíveis danos
*O Programa em si, ainda, é aquela tela preta, não se assuste. É bem intuitivo, basta lembrar que, para obter resultados, é necessário digitar "Enter", para que o valor que você escreveu, seja lido.
*Caso encontre algum erro, por favor mande um e-mail para "jv.joaovitoras@gmail.com" para que eu possa ficar ciente, e possívelmente, resolvê-lo, não tenha medo, críticas são construtivas ^^.
→*E isso é tudo pessoal !!!
