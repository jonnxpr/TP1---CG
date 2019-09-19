#ifndef GLOBALVARIAVEIS_H_INCLUDED
#define GLOBALVARIAVEIS_H_INCLUDED
#include "bib.h"
/**************************************************************
                        VARIAVEIS GLOBAIS
**************************************************************/
//Objetos
HUD hud(1500, 955, 0, 0, 0);
Jogador player1, player2;
Bola bola;

//Texturas
GLuint texSliderPlayer1;
GLuint texSliderPlayer2;
GLuint texBola;
GLuint texBackground;
GLuint texLogo;
GLuint texMenuSinglePlayer;
GLuint texMenuMultiplayer;
GLuint texMenuOpcoes;
GLuint texMenuCreditos;

int incrementoX, incrementoY;
int incrementoX2, incrementoY2;
int posX, posY;
int posX2, posY2;
int posBolaX, posBolaY;
int velBolaX, velBolaY;
int flag;
int keys[256];
#endif // GLOBALVARIAVEIS_H_INCLUDED
