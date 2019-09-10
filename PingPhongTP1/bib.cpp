#include "bib.h"
#include "globalVariaveis.h"

using namespace std;

/**************************************************************
                CLASS HUD (IMPLEMENTACAO)
**************************************************************/
HUD::HUD(int screenSizeX, int screenSizeY, int screenInitPositionX, int screenInitPositionY, int telaAtual){
        this->screenSizeX = screenSizeX;
        this->screenSizeY = screenSizeY;
        this->screenInitPositionX = screenInitPositionX;
        this->screenInitPositionY = screenInitPositionY;
}

int HUD::getScreenInitPositionX(){
    return this->screenInitPositionX;
}

int HUD::getScreenInitPositionY(){
    return this->screenInitPositionY;
}

int HUD::getScreenSizeX(){
    return this->screenSizeX;
}

int HUD::getScreenSizeY(){
    return this->screenSizeY;
}

int HUD::getTelaAtual(){
    return this->telaAtual;
}


/**************************************************************
                CLASS JOGADOR (IMPLEMENTACAO)
**************************************************************/

/**************************************************************
                CLASS BASE (IMPLEMENTACAO)
**************************************************************/

Base::Base(int x, int y, int altura, int largura, float velocidadeX, float velocidadeY){
        x = x;
        y = y;
        altura = altura;
        largura = largura;
        velocidadeX = velocidadeX;
        velocidadeY = velocidadeY;
}
/**************************************************************
                CLASS SLIDER (IMPLEMENTACAO)
**************************************************************/

/**************************************************************
                CLASS BOLA (IMPLEMENTACAO)
**************************************************************/


/******************************************************************
                IMPLEMENTACAOO DAS FUNCOES GLOBAIS
******************************************************************/

GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        cout <<"Erro do SOIL: " << SOIL_last_result() << endl;
    }

    return idTextura;
}

void escreveTexto(void * font, char *s, float x, float y, float z) {
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void HitBox(int x, int y, int altura, int largura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(-largura+x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(1, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0, 1);  glVertex3f(-largura+x, altura+y, 0);
    glEnd();
}

void HitBox2(int x, int y, int altura, int largura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(1, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0, 1);  glVertex3f(x, altura+y, 0);
    glEnd();
}

void redimensionar(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, hud.getScreenSizeX(), 0, hud.getScreenSizeY() , -1, 1);
    //glOrtho(-2, 2, -2, 2, -1.0, 1.0);
    float razaoAspectoJanela = ((float)width)/height;
    cout << hud.getScreenSizeX() << " " << hud.getScreenSizeY() << endl;
    float razaoAspectoMundo = ((float) hud.getScreenSizeX())/hud.getScreenSizeY();
    // se a janela está menos larga do que o mundo (16:9)...
    if (razaoAspectoJanela < razaoAspectoMundo) {
        // vamos colocar barras verticais (acima e abaixo)
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    // se a janela está mais larga (achatada) do que o mundo (16:9)...
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        // vamos colocar barras horizontais (esquerda e direita)
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inicializa(){
    glClearColor(1, 1, 1, 0);

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaMario = carregaTextura("sliderVermelho.png");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    incrementoX = 100;
    incrementoY = 100;
    posX = 100;
    posY = 100;

    incrementoX2 = 100;
    incrementoY2 = 100;
    posX2 = 700;
    posY2 = 100;

    flag = 0;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);

    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaMario);
    // Começa a usar a textura que criamos


    //if(flag == 0){
      //  posY = posY + incrementoY;
    //} else {
     //   posX = posX + incrementoX;
    //}
    if (keys['w'] != 0){
        posY = posY + incrementoY;
    }
    if (keys['s'] != 0){
        posY = posY + incrementoY;
    }

    if (keys['a'] != 0){
        posX = posX + incrementoX;
    }

    if (keys['d'] != 0){
        posX2 = posX2 + incrementoX2;
    }

    if (keys['y'] != 0){
        posY2 = posY2 + incrementoY2;
    }
    if (keys['h'] != 0){
        posY2 = posY2 + incrementoY2;
    }

    if (keys['j'] != 0){
        posX2 = posX2 + incrementoX2;
    }

    if (keys['g'] != 0){
        posX2 = posX2 + incrementoX2;
    }

    HitBox2(posX,posY,127,33);
    HitBox2(posX2, posY2, 127, 33);

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'w':
        if (posY + 127 >= hud.getScreenSizeY()){
            incrementoY = 0;
        } else {
            incrementoY = 10;
        }
        keys['w'] = 1;
        flag = 0;
        break;
    case 's':
        if (posY <= 0){
            incrementoY = 0;
        } else {
            incrementoY = -10;
        }
        keys['s'] = 1;
        flag = 0;
        break;
    case 'y':
        if (posY2 + 127 >= hud.getScreenSizeY()){
            incrementoY2 = 0;
        } else {
            incrementoY2 = 10;
        }
        keys['y'] = 1;
        flag = 0;
        break;
    case 'h':
        if (posY2 <= 0){
            incrementoY2 = 0;
        } else {
            incrementoY2 = -10;
        }
        keys['h'] = 1;
        flag = 0;
        break;
    default:
        break;

    }

    glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'w':
        if (posY + 127 >= hud.getScreenSizeY()){
            incrementoY = 0;
        } else {
            incrementoY = 10;
        }
        keys['w'] = 0;
        flag = 0;
        break;
    case 's':
        if (posY <= 0){
            incrementoY = 0;
        } else {
            incrementoY = -10;
        }
        keys['s'] = 0;
        flag = 0;
        break;
    case 'y':
        if (posY2 + 127 >= hud.getScreenSizeY()){
            incrementoY2 = 0;
        } else {
            incrementoY2 = 10;
        }
        keys['y'] = 0;
        flag = 0;
        break;
    case 'h':
        if (posY2 <= 0){
            incrementoY2 = 0;
        } else {
            incrementoY2 = -10;
        }
        keys['h'] = 0;
        flag = 0;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void atualizaCena(int periodo){
    glutPostRedisplay();
}
