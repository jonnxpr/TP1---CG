*******************************************
				TP1 - CG
	Aluno: Jonathan Douglas Diego Tavares
	Matrícula: 201622040228
	Professor: Flávio Coutinho
*******************************************

*******************************************
				Arquivos
*******************************************
Este diretório contém os seguintes arquivos:

-> 1 diretório contendo o arquivo executável
-> 1 diretório contendo o projeto feito no Codeblocks
   devidamente configurado
-> 1 diretório contendo as screenshots tiradas
   do jogo em execução

*******************************************
       Instruções de compilação
*******************************************
Este projeto foi desenvolvido utilizando as
bibliotecas freeglut, SOIL e SDL. 

A IDE utilizada foi o Codeblocks versão 17.12 para Windows.

Os passos para a compilação do código são os seguintes:

1- É necessário ter instalado em sua máquina a IDE Codeblocks.
2- Abra o diretório do projeto do Codeblocks e abra o projeto.
3- Para compilar e executar o jogo basta apertar F9.
4- É importante que você mantenha a estrutura dos diretórios
   e não altere elas de forma alguma.

*******************************************
			  Lógica do jogo
*******************************************
O jogador que primeiro completar 2 sets de
11 pontos vence, admitindo que o jogo está 
configurado para trabalhar com 3 sets.

Em caso de Match Point de ambos os jogadores
são zerados os pontos e é feita uma disputa
de melhor de 2 para ver quem vence o set.

É possível alterar via código a quantidade
de sets caso seja desejado. Basta alterar
o parâmetro de instanciação da variável
global "jogo" para o valor desejado.
*******************************************
				COMANDOS
*******************************************

Tecla q -> Solicita a saída do jogo (foi necessário
substituir a tecla ESC, pois esta estava com bug)

Tecla r -> Estando na tela de jogo, reinicia o jogo

Tecla x -> Estando na tela de jogo, pausa o jogo atual
		   e retorna para a tela de Menu
		   
		   Estando na tela de saída do jogo, retorna
		   para a tela de Menu

Tecla espaço -> Estando na tela inicial, vai para a tela
				de Menu
				
				Estando em qualquer tela de jogo, inicia
				o movimento da bola a cada ponto
				
				Estando na tela de opções ou de créditos
				retorna para a tela de Menu
				
				Estando na tela de saída, fecha o jogo
				
Tecla h -> Estando na tela de opções altera o sprite do
           slider do Player 1.
		   
Tecla j -> Estando na tela de opções altera o sprite do
           slider do Player 2.
		   
Tecla g -> Ativa e desativa o som durante o jogo

Tecla p -> Estando na tela de jogo pausa e despausa o jogo

Tecla k -> Altera o mapa da fase (existem 4 fases distintas)

Tecla w, o -> Controlam o movimento para cima do slider do
			  Player 1 e 2, respectivamente

Tecla s, l -> Controlam o movimento para baixo do slider do
              Player 1 e 2, respectivamente
