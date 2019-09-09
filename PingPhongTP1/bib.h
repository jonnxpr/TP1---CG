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
GLuint carregaTextura(string filename);
void escreveTexto(void * font, char *s, float x, float y, float z);

/**************************************************************
                        CLASS JOGADOR
**************************************************************/
class Jogador{
public:
    Jogador(){
        points = 0;
        quantidadeDeDerrotas = 0;
        quantidadeDeVitorias = 0;
    }
protected:
    string name;
    int points;
    int quantidadeDeVitorias;
    int quantidadeDeDerrotas;
};

/**************************************************************
                        CLASS HUD
    Função: Responsavel por controlar a Interface do Usuário
**************************************************************/
class HUD{
public:
    enum Tela { SPLASHSCREEN = 0, MENU = 1, JOGO = 2, VITORIAJOGADOR1 = 3, VITORIAJOGADOR2 = 4, GAMEOVER = 5};
    HUD(int screenSizeX, int screenSizeY, int screenInitPositionX, int screenInitPositionY, int telaAtual);
    void mudaTela(Tela novaTela);
    void showBackground();
    int getScreenSizeX();
    int getScreenSizeY();
    int getScreenInitPositionX();
    int getScreenInitPositionY();
    void setTelaAtual(int novaTela);
    int getTelaAtual();

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
    int getSIZE_X();
    int getSIZE_Y();
    float getVelocidadeX();
    float getVelocidadeY();
    void desenha();
    virtual void testaColisaoComParede(HUD &hud) = 0;
    virtual void testaColisaoComObjeto() = 0;

protected:
    int x, y, altura, largura, SIZE_X, SIZE_Y;
    float velocidadeX, velocidadeY;
    GLuint imagem;
};

/**************************************************************
                        CLASS Slider
    Função: Responsavel por controlar o slider no jogo
**************************************************************/
class Slider : public Base{
public:

protected:
};
/**************************************************************
                        CLASS Bola
    Função: Responsavel por controlar a bola no jogo
**************************************************************/
class Bola{
public:

protected:
};
/**************************************************************
                        CLASS SpecialItem
    Função: Classe de base para o Slider, Bola e outras coisas
**************************************************************/
class SpecialItem{
public:

protected:
};


#endif // BIB_H_INCLUDED
