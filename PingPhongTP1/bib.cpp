#include "bib.h"
#include "globalVariaveis.h"

using namespace std;

/**************************************************************
                OUTRAS FUNCOES GLOBAIS (IMPLEMENTACAO)
**************************************************************/
void HitBox(int x, int y, int largura, int altura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(-largura+x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(1, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0, 1);  glVertex3f(-largura+x, altura+y, 0);
    glEnd();
}

void HitBox2(int x, int y, int largura, int altura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(1, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0, 1);  glVertex3f(x, altura+y, 0);
    glEnd();
}

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

void HUD::escreveTexto(void * font, char *s, float x, float y, float z) {
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void HUD::mudaTela(Tela novaTela){
    this->telaAtual = novaTela;
}

void HUD::showSplashScreen(){
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texSplashScreen);

    HitBox2(300,100, 800, 800);

    glDisable(GL_TEXTURE_2D);
}

void HUD::showMenu(){
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texLogo);

    HitBox2(400,500, 799, 368);

    glBindTexture(GL_TEXTURE_2D, texMenuSinglePlayer);

    HitBox2(400,400, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuMultiplayer);

    HitBox2(400,300, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuOpcoes);

    HitBox2(400,200, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuCreditos);

    HitBox2(400,100, 621, 92);


    glDisable(GL_TEXTURE_2D);
}

void HUD::showMenuSelecionaFase()
{

}

void HUD::showMenuCreditos()
{

}

void HUD::showMenuOpcoes()
{

}

void HUD::showJogoFase1(){
    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texBackground);

    HitBox2(0, 0, 1500, 955);

    glBindTexture(GL_TEXTURE_2D, texSliderPlayer1);

    HitBox2(slider1.getX(),slider1.getY(),33,127);
    //cout << player1.getSlider().getX() << " " << player1.getSlider().getY() << endl;
    glBindTexture(GL_TEXTURE_2D, texSliderPlayer2);

    HitBox2(slider2.getX(), slider2.getY(), 33, 127);
    //cout << player2.getSlider().getX() << " " << player2.getSlider().getY() << endl;
    glBindTexture(GL_TEXTURE_2D,texBola);

    HitBox2(bola.getX(),bola.getY(),45, 43);

    glDisable(GL_TEXTURE_2D);
}

void HUD::showJogoFase2()
{

}

void HUD::showJogoFase3()
{

}

void HUD::showVitoriaJogador1()
{

}

void HUD::showVitoriaJogador2()
{

}

void HUD::showPause()
{

}

void HUD::showGameOver()
{

}

void HUD::setTelaAtual(int novaTela){
    this->telaAtual = novaTela;
}

void HUD::inicializaTexturas()
{
    texSliderPlayer1 = carregaTextura("sliderVermelho.png");
    texSliderPlayer2 = carregaTextura("sliderVerde.png");
    texBola = carregaTextura("tennisBall1.png");
    texBackground = carregaTextura("quadraTenis.png");
    texLogo = carregaTextura("logo.png");
    texMenuSinglePlayer = carregaTextura("menuSinglePlayer.png");
    texMenuMultiplayer = carregaTextura("menuMultiplayer.png");
    texMenuOpcoes = carregaTextura("menuOpcoes.png");
    texMenuCreditos = carregaTextura("menuCreditos.png");
    texSplashScreen = carregaTextura("splashScreen.png");
}

/**************************************************************
                CLASS JOGADOR (IMPLEMENTACAO)
**************************************************************/

void Jogador::setSlider(Slider slider){
    this->slider = slider;
}

Slider Jogador::getSlider(){
    return this->slider;
}

void Jogador::setName(string name){
    this->name = name;
}

string Jogador::getName(){
    return this->name;
}

int Jogador::getPoints(){
    return this->points;
}

void Jogador::setQuantidadeDeVitorias(int quant){
    this->quantidadeDeVitorias = quant;
}

void Jogador::setQuantidadeDeDerrotas(int quant){
    this->quantidadeDeDerrotas = quant;
}

int Jogador::getQuantidadeDeDerrotas(){
    return this->quantidadeDeDerrotas;
}

int Jogador::getQuantidadeDeVitorias(){
    return this->quantidadeDeVitorias;
}


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

Base::Base()
{

}

void Base::setX(int x){
    this->x = x;
}

void Base::setY(int y){
    this->y = y;
}

void Base::setAltura(int altura){
    this->altura = altura;
}

void Base::setLargura(int largura){
    this->largura = largura;
}

void Base::setVelocidadeX(float velocidadeX){
    this->velocidadeX = velocidadeX;
}

void Base::setVelocidadeY(float velocidadeY){
    this->velocidadeY = velocidadeY;
}

int Base::getX(){
    return this->x;
}

int Base::getY(){
    //cout << this->y << "\n";
    return this->y;
}

int Base::getAltura(){
    return this->altura;
}

int Base::getLargura(){
    return this->largura;
}

float Base::getVelocidadeX(){
    return this->velocidadeX;
}

float Base::getVelocidadeY(){
    return this->velocidadeY;
}

/**************************************************************
                CLASS SLIDER (IMPLEMENTACAO)
**************************************************************/
void Slider::testaColisaoComParede(){
    if (getY() <= 130){
        setVelocidadeY(11);
    } else if (getY() + getAltura() >= hud.getScreenSizeY()-200){
        setVelocidadeY(-11);
    }
}

void Slider::testaColisaoComObjeto(int xObj, int yObj, int larguraObj, int alturaObj){
    if ( (this->x + getLargura() > xObj ) &&
        ( this->x < xObj + larguraObj ) &&
        ( this->y + getAltura() > yObj ) &&
        ( this->y < yObj + alturaObj ) )
        {
            cout << "<< colisão slider \n";
        }
}

/**************************************************************
                CLASS BOLA (IMPLEMENTACAO)
**************************************************************/
void Bola::testaColisaoComParede(){
    if (getX() <= 40 || getX() >= hud.getScreenSizeX()-50){
        //setVelocidadeX(-getVelocidadeX());
        setVelocidadeX(0);
        setVelocidadeY(0);
        setX(750);
        setY(450);
        cout << "passei aqui 1" << endl;
    }

    if (getY() <= 93 || getY() >= hud.getScreenSizeY()-133){
        setVelocidadeY(-getVelocidadeY());
        cout << "passei aqui 2" << endl;
    }

}

void Bola::testaColisaoComObjeto(int xObj, int yObj, int larguraObj, int alturaObj){
    if ( (getX() + getLargura() >= xObj ) &&
        ( getX() <= xObj + larguraObj ) &&
        ( getY() + getAltura()  >= yObj ) &&
        ( getY() <= yObj + alturaObj ) )
        {
            //cout << "xBola = " << getX() << " yBola = " << getY() << endl;
            //cout << "xSlider = " << xObj << " ySlider = " << yObj << endl;
            //cout << "<< colisão bola com slider \n";
            cout << "foi aqui" << endl;
            setVelocidadeX(-getVelocidadeX());
            setVelocidadeY(-getVelocidadeY());
        }
}


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

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (hud.getTelaAtual() == hud.MENU){
            if ( (x >= 400 && x <= 400+621) && (y >= 400 && y <= 400 + 92) ){
                hud.setTelaAtual(hud.JOGOFASE1);
            }
        }
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

	}
}

void redimensionar(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, hud.getScreenSizeX(), 0, hud.getScreenSizeY() , -1, 1);
    //glOrtho(-2, 2, -2, 2, -1.0, 1.0);
    float razaoAspectoJanela = ((float)width)/height;
    //cout << hud.getScreenSizeX() << " " << hud.getScreenSizeY() << endl;
    float razaoAspectoMundo = ((float) hud.getScreenSizeX())/hud.getScreenSizeY();
    // se a janela está menos larga
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

    hud.inicializaTexturas();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    hud.setTelaAtual(hud.SPLASHSCREEN);

    player1.setName("Player 1");
    player2.setName("Player 2");

    bola.setAltura(50);
    bola.setLargura(50);
    bola.setX(750);
    bola.setY(450);
    bola.setVelocidadeX(0);
    bola.setVelocidadeY(0);

    slider1.setAltura(33);
    slider1.setLargura(127);
    slider1.setX(100);
    slider1.setY(400);
    slider1.setVelocidadeX(0);
    slider1.setVelocidadeY(10);

    slider2.setAltura(33);
    slider2.setLargura(127);
    slider2.setX(1380);
    slider2.setY(400);
    slider2.setVelocidadeX(0);
    slider2.setVelocidadeY(10);

    bola.setVelocidadeX(0);
    bola.setVelocidadeY(0);
    bola.setX(750);
    bola.setY(450);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);

    switch(hud.getTelaAtual()){
    case 0:
        hud.showSplashScreen();
        break;
    case 1:
        hud.showMenu();
        break;
    case 2:
        hud.showMenuSelecionaFase();
        break;
    case 3:
        hud.showMenuCreditos();
        break;
    case 4:
        hud.showMenuOpcoes();
        break;
    case 5:
        hud.showJogoFase1();
        break;
    case 6:
        hud.showJogoFase2();
        break;
    case 7:
        hud.showJogoFase3();
        break;
    case 8:
        hud.showVitoriaJogador1();
        break;
    case 9:
        hud.showVitoriaJogador2();
        break;
    case 10:
        hud.showPause();
        break;
    case 11:
        hud.showGameOver();
        break;
    default:
        break;
    }

    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'c':
        system("cls");
        break;
    case 'r':
        if (hud.getTelaAtual() == hud.JOGOFASE1 || hud.getTelaAtual() == hud.JOGOFASE2 ||
            hud.getTelaAtual() == hud.JOGOFASE3){
                bola.setX(750);
                bola.setY(450);
        }
        break;
    case 32:
        if (hud.getTelaAtual() == hud.SPLASHSCREEN){
            hud.setTelaAtual(hud.MENU);
        } else if (hud.getTelaAtual() == hud.JOGOFASE1 || hud.getTelaAtual() == hud.JOGOFASE2 ||
                   hud.getTelaAtual() == hud.JOGOFASE3){
                    bola.setVelocidadeX(rand() % 2 == 0 ? -5 : 5);
                    bola.setVelocidadeY(rand() % 2 == 0 ? -5 : 5);
                   }

        break;
    case 'w':
        if (hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider1.getY() + slider1.getAltura() >= hud.getScreenSizeY()){
                slider1.setVelocidadeY(0);
            } else {
                slider1.setVelocidadeY(10);
            }
            keys['w'] = 1;
        }

        break;
    case 's':
        if (hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider1.getY() <= 0){
                slider1.setVelocidadeY(10);
            } else {
                slider1.setVelocidadeY(-10);
            }bola.setVelocidadeY(-bola.getVelocidadeY());
            keys['s'] = 1;
        }

        break;
    case 'y':
        if (hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider2.getY() + slider2.getAltura() >= hud.getScreenSizeY()){
                slider2.setVelocidadeY(0);
            } else {
                slider2.setVelocidadeY(10);
            }
            keys['y'] = 1;
        }

        break;
    case 'h':
        if (hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider2.getY() <= 0){
                slider2.setVelocidadeY(0);
            } else {
                slider2.setVelocidadeY(-10);
            }
            keys['h'] = 1;
        }

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
        if (slider1.getY() + slider1.getAltura() >= hud.getScreenSizeY()){
            slider1.setVelocidadeY(0);
        } else {
            slider1.setVelocidadeY(10);
        }
        keys['w'] = 0;
        break;
    case 's':
        if (slider1.getY() <= 0){
            slider1.setVelocidadeY(0);
        } else {
            slider1.setVelocidadeY(-10);
        }
        keys['s'] = 0;
        break;
    case 'y':
        if (slider2.getY() + slider2.getAltura() >= hud.getScreenSizeY()){
            slider2.setVelocidadeY(0);
        } else {
            slider2.setVelocidadeY(10);
        }
        keys['y'] = 0;
        break;
    case 'h':
        if (slider2.getY() <= 0){
            slider2.setVelocidadeY(0);
        } else {
            slider2.setVelocidadeY(-10);
        }
        keys['h'] = 0;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void atualizaCena(int periodo){
    if (keys['w'] != 0 || keys['s'] != 0){
        //cout << player1.getSlider().getY() + player1.getSlider().getVelocidadeY();
        slider1.setY(slider1.getY() + slider1.getVelocidadeY());
    }

    if (keys['y'] != 0 || keys['h'] != 0){
        slider2.setY(slider2.getY() + slider2.getVelocidadeY());
    }

    /*
    if (bola.getX() <= 70 || bola.getX() >= hud.getScreenSizeX()-50){
        bola.setVelocidadeX(-bola.getVelocidadeX());
    }

    if (bola.getY() <= 93 || bola.getY() >= hud.getScreenSizeY()-133){
        bola.setVelocidadeY(-bola.getVelocidadeY());
    }*/

    bola.testaColisaoComParede();
    slider1.testaColisaoComParede();
    slider2.testaColisaoComParede();
    bola.testaColisaoComObjeto(slider1.getX(), slider1.getY(), slider1.getAltura(), slider1.getLargura());
    bola.testaColisaoComObjeto(slider2.getX(), slider2.getY(), slider2.getAltura(), slider2.getLargura());

    bola.setX(bola.getX() + bola.getVelocidadeX());
    bola.setY(bola.getY() + bola.getVelocidadeY());

    glutPostRedisplay();

    glutTimerFunc(1000.0/60.0, atualizaCena, 0);
}
