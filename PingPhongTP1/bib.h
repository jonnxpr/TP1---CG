#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#define SCREENSIZEX 800
#define SCREENSIZEY 800
#define SCREENINITPOSITIONX 0
#define SCRREENINITPOSITIONY 0


/**************************************************************
Biblioteca de Classes e Funções para o Game Ping Phong.
Versão: 1.0 Alpha

@author: Jonathan Douglas Diego Tavares
@Professor: Flávio Coutinho
**************************************************************/

using namespace std;

/**************************************************************
                Prototipos das Funcoes Globais
**************************************************************/
void inicializa();
void redimensionar(int width, int height);
void display();
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void atualizaCena(int periodo);
void mouse(int button, int state, int x, int y);
GLuint carregaTextura(const char* arquivo);


/**************************************************************
                        CLASS HUD
    Função: Responsavel por controlar a Interface do Usuário
**************************************************************/
class HUD{
public:
    enum Tela { SPLASHSCREEN = 0, MENU = 1, MENU_SELECIONA_FASE = 2, MENU_CREDITOS = 3, MENU_OPCOES = 4, JOGOFASE1 = 5,
    JOGOFASE2 = 6, JOGOFASE3 = 7, VITORIAJOGADOR1 = 8, VITORIAJOGADOR2 = 9, PAUSE = 10, GAMEOVER = 11};
    HUD(int screenSizeX, int screenSizeY, int screenInitPositionX, int screenInitPositionY, int telaAtual);
    void inicializaTexturas();
    void mudaTela(Tela novaTela);
    void showSplashScreen();
    void showMenu();
    void showMenuSelecionaFase();
    void showMenuCreditos();
    void showMenuOpcoes();
    void showJogoFase1();
    void showJogoFase2();
    void showJogoFase3();
    void showVitoriaJogador1();
    void showVitoriaJogador2();
    void showPause();
    void showGameOver();
    int getScreenSizeX();
    int getScreenSizeY();
    int getScreenInitPositionX();
    int getScreenInitPositionY();
    void setTelaAtual(int novaTela);
    int getTelaAtual();
    void escreveTexto(void * font, char *s, float x, float y, float z);
protected:

    int telaAtual;
    int screenSizeX, screenSizeY;
    int screenInitPositionX, screenInitPositionY;
};

/**************************************************************
                        CLASS Base
    Função: Classe de base para o Slider, Bola e outras coisas
**************************************************************/
class Base{
public:
    Base();
    Base(int x, int y, int altura, int largura, float velocidadeX, float velocidadeY);

    void setX(int x);
    void setY(int y);
    void setAltura(int altura);
    void setLargura(int largura);
    void setVelocidadeX(float velocidadeX);
    void setVelocidadeY(float velocidadeY);
    int getX();
    int getY();
    int getAltura();
    int getLargura();
    float getVelocidadeX();
    float getVelocidadeY();
    virtual void testaColisaoComParede() = 0;
    virtual void testaColisaoComObjeto(int xObj, int yObj, int larguraObj, int alturaObj) = 0;

protected:
    int x, y, altura, largura;
    float velocidadeX, velocidadeY;
};

/**************************************************************
                        CLASS Slider
    Função: Responsavel por controlar o slider no jogo
**************************************************************/
class Slider : public Base{
public:
    void testaColisaoComParede();
    void testaColisaoComObjeto(int xObj, int yObj, int larguraObj, int alturaObj);
protected:
};

/**************************************************************
                        CLASS JOGADOR
**************************************************************/
class Jogador{
public:
    Jogador(){
        name = "Padrão";
        points = 0;
        quantidadeDeDerrotas = 0;
        quantidadeDeVitorias = 0;
    }

    void setSlider(Slider slider);
    Slider getSlider();
    void setName(string name);
    string getName();
    int getPoints();
    void setQuantidadeDeVitorias(int quant);
    void setQuantidadeDeDerrotas(int quant);
    int getQuantidadeDeDerrotas();
    int getQuantidadeDeVitorias();

protected:
    string name;
    int points;
    int quantidadeDeVitorias;
    int quantidadeDeDerrotas;
    Slider slider;
};
/**************************************************************
                        CLASS Bola
    Função: Responsavel por controlar a bola no jogo
**************************************************************/
class Bola : public Base{
public:
    void testaColisaoComParede();
    void testaColisaoComObjeto(int xObj, int yObj, int larguraObj, int alturaObj);
protected:

};
/**************************************************************
                        CLASS SpecialItem
    Função: Classe de base para o Slider, Bola e outras coisas
**************************************************************/
class SpecialItem : Base{
public:

protected:
};


#endif // BIB_H_INCLUDED
