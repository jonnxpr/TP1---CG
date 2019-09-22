#ifndef GLOBALVARIAVEIS_H_INCLUDED
#define GLOBALVARIAVEIS_H_INCLUDED
#include "bib.h"
/**************************************************************
                        VARIAVEIS GLOBAIS
**************************************************************/
//Objetos
HUD hud(1500, 955, 0, 0, 0);
Jogador player1;
Jogador player2;
Slider slider1;
Slider slider2;
Bola bola;
Jogo jogo(3);

//Texturas
GLuint texSliderPlayer1;
GLuint texSliderPlayer2;
GLuint texBola;
GLuint texBackground;
GLuint texSplashScreen;
GLuint texLogo;
//GLuint texMenuSinglePlayer;
GLuint texMenuMultiplayer;
GLuint texMenuOpcoes;
GLuint texMenuCreditos;
GLuint texTextPontos;
GLuint texTextSet;
GLuint texPonto0;
GLuint texPonto1;
GLuint texPonto2;
GLuint texPonto3;
GLuint texPonto4;
GLuint texPonto5;
GLuint texPonto6;
GLuint texPonto7;
GLuint texPonto8;
GLuint texPonto9;
GLuint texPonto10;
GLuint texPonto11;
GLuint texCoroa;
GLuint texVitoriaP1;
GLuint texVitoriaP2;
GLuint texOpcoes;
GLuint texCreditos;
GLuint texMatchPoint;

//variavel de controle do teclado
int keys[256];

//variavel de controle do pause
bool pause;

//variavel de controle do som
bool som;

//variaveis para controle do mapa escolhido e dos sliders
int sliderP1, sliderP2;
int mapa;
#endif // GLOBALVARIAVEIS_H_INCLUDED
