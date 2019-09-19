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

void HUD::showSplashScreen()
{

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

void HUD::showMenuSelecionaSlider()
{

}

void HUD::showJogoFase1()
{

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

void HUD::showGameOver()
{

}

void HUD::setTelaAtual(int novaTela){
    this->telaAtual = novaTela;
}

void HUD::desenha(int x, int y, GLuint imagem)
{

}

void HUD::inicializaTexturas()
{
    texSliderPlayer1 = carregaTextura("sliderVermelho.png");
    texSliderPlayer2 = carregaTextura("sliderVerde.png");
    texBola = carregaTextura("bola.png");
    texBackground = carregaTextura("quadraTenis.png");
    texLogo = carregaTextura("logo.png");
    texMenuSinglePlayer = carregaTextura("menuSinglePlayer.png");
    texMenuMultiplayer = carregaTextura("menuMultiplayer.png");
    texMenuOpcoes = carregaTextura("menuOpcoes.png");
    texMenuCreditos = carregaTextura("menuCreditos.png");
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
    return this->y;
}

int Base::getAltura(){
    return this->altura;
}

int Base::getLargura(){
    return this->largura;
}

int Base::getSIZE_X(){
    return this->SIZE_X;
}

int Base::getSIZE_Y(){
    return this->SIZE_Y;
}

float Base::getVelocidadeX(){
    return this->velocidadeX;
}

float Base::getVelocidadeY(){
    return this->velocidadeY;
}

void Base::testaColisaoComParede(HUD& hud){

}

void Base::testaColisaoComObjeto(){
    if ( (this->x + SIZE_X > getX() ) &&
        ( this->x < getX() + getSIZE_X() ) &&
        ( this->y + this->SIZE_Y > getY() ) &&
        ( this->y < getY() + getSIZE_Y() ) )
        {

        }
}

void Base::setImagem(GLuint imagem){
    //cout << ">" << imagem << endl;
    this->imagem = imagem;
    //cout << ">>" << imagem << endl;
    //cout << ">>>" << this->imagem << endl;
}

GLuint Base::getImagem(){
    return this->imagem;
}


/**************************************************************
                CLASS SLIDER (IMPLEMENTACAO)
**************************************************************/
Slider::Slider()
{
}

void Slider::testaColisaoComParede(HUD& hud){
}

void Slider::testaColisaoComObjeto(){
    if ( (this->x + SIZE_X > getX() ) &&
        ( this->x < getX() + getSIZE_X() ) &&
        ( this->y + this->SIZE_Y > getY() ) &&
        ( this->y < getY() + getSIZE_Y() ) )
        {

        }
}

/**************************************************************
                CLASS BOLA (IMPLEMENTACAO)
**************************************************************/
void Bola::testaColisaoComParede(HUD& hud){
}

void Bola::testaColisaoComObjeto(){
    if ( (this->x + SIZE_X > getX() ) &&
        ( this->x < getX() + getSIZE_X() ) &&
        ( this->y + this->SIZE_Y > getY() ) &&
        ( this->y < getY() + getSIZE_Y() ) )
        {

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
        if (hud.telaAtual == hud.MENU){
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

    hud.inicializaTexturas();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    hud.setTelaAtual(hud.MENU);

    incrementoX = 100;
    incrementoY = 100;
    posX = 100;
    posY = 100;

    incrementoX2 = 100;
    incrementoY2 = 100;
    posX2 = 1380;
    posY2 = 100;

    velBolaX = 10;
    velBolaY = 10;
    posBolaX = 750;
    posBolaY = 477;

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);
    int telaAtual = hud.getTelaAtual();

    switch(hud.getTelaAtual()){
    case 1:
        hud.showMenu();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        // Habilita o uso de texturas
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, texBackground);

        HitBox2(0, 0, 1500, 955);

        glBindTexture(GL_TEXTURE_2D, texSliderPlayer1);
        // Começa a usar a textura que criamos

        HitBox2(posX,posY,33,127);

        glBindTexture(GL_TEXTURE_2D, texSliderPlayer2);

        HitBox2(posX2, posY2, 33, 127);

        glBindTexture(GL_TEXTURE_2D,texBola);

        HitBox2(posBolaX,posBolaY,45, 43);

        glDisable(GL_TEXTURE_2D);
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
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

    if (posBolaX <= 140 || posBolaX >= hud.getScreenSizeX()-145){
        velBolaX = -velBolaX;
    }

    if (posBolaY <= 93 || posBolaY >= hud.getScreenSizeY()-133){
        velBolaY = -velBolaY;
    }

    posBolaX = posBolaX + velBolaX;
    posBolaY = posBolaY + velBolaY;




    glutPostRedisplay();

    glutTimerFunc(1000.0/60.0, atualizaCena, 0);
}
