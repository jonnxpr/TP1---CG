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

void tocar_musica(char const nome[40], int loop){
    Mix_Chunk *som = NULL;
    int canal;
    int canal_audio=2;
    int taxa_audio = 22050;
    Uint16 formato_audio = AUDIO_S16SYS;
    int audio_buffers = 4096;
    if(Mix_OpenAudio(taxa_audio, formato_audio, canal_audio, audio_buffers) != 0)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }
    som = Mix_LoadWAV(nome);
    if(som == NULL)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }
    Mix_HaltChannel(-1);
    canal = Mix_PlayChannel( -1, som, loop);
    if(canal == -1)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }
}

void parar_musica()
{
    Mix_HaltChannel(-1);
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

    //glBindTexture(GL_TEXTURE_2D, texMenuSinglePlayer);

    //HitBox2(400,400, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuMultiplayer);

    HitBox2(400,400, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuOpcoes);

    HitBox2(400,300, 621, 92);

    glBindTexture(GL_TEXTURE_2D, texMenuCreditos);

    HitBox2(400,200, 621, 92);


    glDisable(GL_TEXTURE_2D);
}

void HUD::showMenuCreditos(){
    //cout << "menu creditos\n";
}

void HUD::showMenuOpcoes(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texOpcoes);

    HitBox2(300,100, 800, 800);

    glDisable(GL_TEXTURE_2D);
    //cout << "menu opcoes\n";
}

void HUD::showJogoFase1(){
    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texBackground);

    HitBox2(0, 0, 1500, 955);

    glBindTexture(GL_TEXTURE_2D, texSliderPlayer1);

    HitBox2(slider1.getX(),slider1.getY(),33,127);

    glBindTexture(GL_TEXTURE_2D, texSliderPlayer2);

    HitBox2(slider2.getX(), slider2.getY(), 33, 127);

    glBindTexture(GL_TEXTURE_2D,texBola);

    HitBox2(bola.getX(),bola.getY(),45, 43);

    glBindTexture(GL_TEXTURE_2D, texTextPontos);

    HitBox2(100, 850, 300, 100);

    glBindTexture(GL_TEXTURE_2D, texTextPontos);

    HitBox2(1050, 850, 300, 100);

    glBindTexture(GL_TEXTURE_2D, texTextSet);

    HitBox2(525, 870, 300, 100);

    switch(jogo.getPlayer1Points()){
    case 0:
        glBindTexture(GL_TEXTURE_2D, texPonto0);
        HitBox2(330, 875, 50, 50);
        break;
    case 1:
        glBindTexture(GL_TEXTURE_2D, texPonto1);
        HitBox2(330, 875, 50, 50);
        break;
    case 2:
        glBindTexture(GL_TEXTURE_2D, texPonto2);
        HitBox2(330, 875, 50, 50);
        break;
    case 3:
        glBindTexture(GL_TEXTURE_2D, texPonto3);
        HitBox2(330, 875, 50, 50);
        break;
    case 4:
        glBindTexture(GL_TEXTURE_2D, texPonto4);
        HitBox2(330, 875, 50, 50);
        break;
    case 5:
        glBindTexture(GL_TEXTURE_2D, texPonto5);
        HitBox2(330, 875, 50, 50);
        break;
    case 6:
        glBindTexture(GL_TEXTURE_2D, texPonto6);
        HitBox2(330, 875, 50, 50);
        break;
    case 7:
        glBindTexture(GL_TEXTURE_2D, texPonto7);
        HitBox2(330, 875, 50, 50);
        break;
    case 8:
        glBindTexture(GL_TEXTURE_2D, texPonto8);
        HitBox2(330, 875, 50, 50);
        break;
    case 9:
        glBindTexture(GL_TEXTURE_2D, texPonto9);
        HitBox2(330, 875, 50, 50);
        break;
    case 10:
        glBindTexture(GL_TEXTURE_2D, texPonto10);
        HitBox2(330, 875, 50, 50);
        break;
    case 11:
        glBindTexture(GL_TEXTURE_2D, texPonto11);
        HitBox2(330, 875, 50, 50);
        break;
    default:
        break;
    }

    switch(jogo.getPlayer2Points()){
    case 0:
        glBindTexture(GL_TEXTURE_2D, texPonto0);
        HitBox2(1280, 875, 50, 50);
        break;
    case 1:
        glBindTexture(GL_TEXTURE_2D, texPonto1);
        HitBox2(1280, 875, 50, 50);
        break;
    case 2:
        glBindTexture(GL_TEXTURE_2D, texPonto2);
        HitBox2(1280, 875, 50, 50);
        break;
    case 3:
        glBindTexture(GL_TEXTURE_2D, texPonto3);
        HitBox2(1280, 875, 50, 50);
        break;
    case 4:
        glBindTexture(GL_TEXTURE_2D, texPonto4);
        HitBox2(1280, 875, 50, 50);
        break;
    case 5:
        glBindTexture(GL_TEXTURE_2D, texPonto5);
        HitBox2(1280, 875, 50, 50);
        break;
    case 6:
        glBindTexture(GL_TEXTURE_2D, texPonto6);
        HitBox2(1280, 875, 50, 50);
        break;
    case 7:
        glBindTexture(GL_TEXTURE_2D, texPonto7);
        HitBox2(1280, 875, 50, 50);
        break;
    case 8:
        glBindTexture(GL_TEXTURE_2D, texPonto8);
        HitBox2(1280, 875, 50, 50);
        break;
    case 9:
        glBindTexture(GL_TEXTURE_2D, texPonto9);
        HitBox2(1280, 875, 50, 50);
        break;
    case 10:
        glBindTexture(GL_TEXTURE_2D, texPonto10);
        HitBox2(1280, 875, 50, 50);
        break;
    case 11:
        glBindTexture(GL_TEXTURE_2D, texPonto11);
        HitBox2(1280, 875, 50, 50);
        break;
    default:
        break;
    }

    switch(jogo.getSetAtual()){
    case 1:
        glBindTexture(GL_TEXTURE_2D, texPonto1);
        HitBox2(725, 900, 50, 50);
        break;
    case 2:
        glBindTexture(GL_TEXTURE_2D, texPonto2);
        HitBox2(725, 900, 50, 50);
        break;
    case 3:
        glBindTexture(GL_TEXTURE_2D, texPonto3);
        HitBox2(725, 900, 50, 50);
        break;
    default:
        break;
    }

    if(jogo.isPlayer1Ganhando() == 0){
        glBindTexture(GL_TEXTURE_2D, texCoroa);
        HitBox2(50,900, 100, 55);
    } else if (jogo.isPlayer1Ganhando() == 1) {
        glBindTexture(GL_TEXTURE_2D, texCoroa);
        HitBox2(1000,900, 100, 55);
    }

    if (jogo.getPlayer1Points() == 10){

    } else if (jogo.getPlayer2Points() == 10){

    }

    glDisable(GL_TEXTURE_2D);
}

void HUD::showJogoFase2()
{

}

void HUD::showJogoFase3()
{

}

void HUD::showJogoFase4()
{

}

void HUD::showVitoriaJogador1(){
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texVitoriaP1);

    HitBox2(400,200, 700, 700);
}

void HUD::showVitoriaJogador2(){
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texVitoriaP2);

    HitBox2(400,200, 700, 700);
}

void HUD::showPause()
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
    //texMenuSinglePlayer = carregaTextura("menuSinglePlayer.png");
    texMenuMultiplayer = carregaTextura("menuMultiplayer.png");
    texMenuOpcoes = carregaTextura("menuOpcoes.png");
    texMenuCreditos = carregaTextura("menuCreditos.png");
    texSplashScreen = carregaTextura("splashScreen.png");
    texTextPontos = carregaTextura("textPontos.png");
    texTextSet = carregaTextura("textSet.png");
    texPonto0 = carregaTextura("ponto0.png");
    texPonto1 = carregaTextura("ponto1.png");
    texPonto2 = carregaTextura("ponto2.png");
    texPonto3 = carregaTextura("ponto3.png");
    texPonto4 = carregaTextura("ponto4.png");
    texPonto5 = carregaTextura("ponto5.png");
    texPonto6 = carregaTextura("ponto6.png");
    texPonto7 = carregaTextura("ponto7.png");
    texPonto8 = carregaTextura("ponto8.png");
    texPonto9 = carregaTextura("ponto9.png");
    texPonto10 = carregaTextura("ponto10.png");
    texPonto11 = carregaTextura("ponto11.png");
    texCoroa = carregaTextura("coroa.png");
    texVitoriaP1 = carregaTextura("player1Win.png");
    texVitoriaP2 = carregaTextura("player2Win.png");
    texOpcoes = carregaTextura("opcoes.png");
}

/**************************************************************
                CLASS JOGADOR (IMPLEMENTACAO)
**************************************************************/
void Jogador::setName(string name){
    this->name = name;
}

string Jogador::getName(){
    return this->name;
}

void Jogador::setPoints(int points){
    this->points = points;
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
                CLASS JOGO (IMPLEMENTACAO)
**************************************************************/
Jogo::Jogo(int maxSets){
    this->maxSets = maxSets % 2 == 0 ? 3 : maxSets;
    this->player1Points = player1.getPoints();
    this->player2Points = player2.getPoints();
    this->setAtual = 1;
    this->setsPlayer1 = 0;
    this->setsPlayer2 = 0;
    this->tie = false;
}

void Jogo::setPlayer1Points(int points){
    this->player1Points = points;
}

void Jogo::setPlayer2Points(int points){
    this->player2Points = points;
}

void Jogo::setSetAtual(int setAtual){
    this->setAtual = setAtual;
}

void Jogo::setMaxSets(int maxSets){
    this->maxSets = maxSets;
}

void Jogo::setSetsPlayer1(int sets){
    this->setsPlayer1 = sets;
}

void Jogo::setSetsPlayer2(int sets){
    this->setsPlayer2 = sets;
}

void Jogo::setTiePointsP1(int tiePoint){
    this->tiePointsP1 = tiePoint;
}

void Jogo::setTiePointsP2(int tiePoint){
    this->tiePointsP2 = tiePoint;
}

void Jogo::setTie(bool tie){
    this->tie = tie;
}

void Jogo::setGameWasTied(bool value){
    this->gameWasTied = value;
}

int Jogo::getPlayer1Points(){
    return this->player1Points;
}

int Jogo::getPlayer2Points(){
    return this->player2Points;
}

int Jogo::getSetAtual(){
    return this->setAtual;
}

int Jogo::getMaxSets(){
    return this->maxSets;
}

int Jogo::getSetsPlayer1(){
    return this->setsPlayer1;
}

int Jogo::getSetsPlayer2(){
    return this->setsPlayer2;
}

int Jogo::getTiePointsP1(){
    return this->tiePointsP1;
}

int Jogo::getTiePointsP2(){
    return this->tiePointsP2;
}

bool Jogo::getTie(){
    return this->tie;
}

bool Jogo::getGameWasTied(){
    return this->gameWasTied;
}


void Jogo::verificaSet(){
    isGameTied();

    if (getTie()){
        player1.setPoints(0);
        setPlayer1Points(player1.getPoints());
        player2.setPoints(0);
        setPlayer2Points(player2.getPoints());
        setTie(false);
        setGameWasTied(true);
    }

    if (jogo.getPlayer1Points() == 2 && getGameWasTied() == true){
        setSetsPlayer1(getSetsPlayer1() + 1);

        player1.setPoints(0);
        setPlayer1Points(player1.getPoints());
        player2.setPoints(0);
        setPlayer2Points(player2.getPoints());
        setSetAtual(getSetAtual() + 1);
        setGameWasTied(false);
    }

    if (jogo.getPlayer2Points() == 2 && getGameWasTied() == true){
        setSetsPlayer2(getSetsPlayer2() + 1);

        player1.setPoints(0);
        setPlayer1Points(player1.getPoints());
        player2.setPoints(0);
        setPlayer2Points(player2.getPoints());
        setSetAtual(getSetAtual() + 1);
        setGameWasTied(false);
    }

    int limite = (maxSets / 2) + 1;

    if (getSetsPlayer1() == limite){
        reiniciaJogo();
        hud.setTelaAtual(hud.VITORIAJOGADOR1);
    }

    if (getSetsPlayer2() == limite){
        reiniciaJogo();
        hud.setTelaAtual(hud.VITORIAJOGADOR2);
    }

    if (getPlayer1Points() == 11 && getPlayer2Points() != 11){
        setSetsPlayer1(getSetsPlayer1() + 1);

        player1.setPoints(0);
        setPlayer1Points(player1.getPoints());
        player2.setPoints(0);
        setPlayer2Points(player2.getPoints());
        setSetAtual(getSetAtual() + 1);
    }

    if (getPlayer2Points() == 11 && getPlayer1Points() != 11){
        setSetsPlayer2(getSetsPlayer2() + 1);

        player1.setPoints(0);
        setPlayer1Points(player1.getPoints());
        player2.setPoints(0);
        setPlayer2Points(player2.getPoints());
        setSetAtual(getSetAtual() + 1);
    }
}

int Jogo::isPlayer1Ganhando(){
    if (getSetsPlayer1() > getSetsPlayer2()){
        return 0;
    } else if (getSetsPlayer1() < getSetsPlayer2()){
        return 1;
    }

    return -1;
}

void Jogo::isGameTied(){
    if(getPlayer1Points() == 10 && getPlayer2Points() == 10){
        tie = true;
    }
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
        setVelocidadeY(5);
    } else if (getY() + getAltura() >= hud.getScreenSizeY()-200){
        setVelocidadeY(-5);
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
    if (getX() <= 40){
        //setVelocidadeX(-getVelocidadeX());
        setVelocidadeX(0);
        setVelocidadeY(0);
        setX(750);
        setY(450);
        player2.setPoints(player2.getPoints()+1);
        jogo.setPlayer2Points(player2.getPoints());
        tocar_musica("big_explosion.ogg", 0);
        //cout << "passei aqui 1" << endl;
    }

    if (getX() >= hud.getScreenSizeX()-50){
        setVelocidadeX(0);
        setVelocidadeY(0);
        setX(750);
        setY(450);
        player1.setPoints(player1.getPoints()+1);
        jogo.setPlayer1Points(player1.getPoints());
        tocar_musica("big_explosion.ogg", 0);
    }

    if (getY() <= 93 || getY() >= hud.getScreenSizeY()-133){
        setVelocidadeY(-getVelocidadeY());
        tocar_musica("boom.wav",-1);
        //cout << "passei aqui 2" << endl;
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
            //cout << "foi aqui" << endl;
            setVelocidadeX(-getVelocidadeX());
            tocar_musica("boom.wav",-1);
            //setVelocidadeY(-getVelocidadeY());
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
            if ( (x >= 426 && x <= 876) && (y >= 387 && y <= 420) ){
                hud.setTelaAtual(hud.JOGOFASE1);
            } else if ( (x >= 578 && x <= 733) && (y >= 467 && y <= 497) ){
                hud.setTelaAtual(hud.MENU_OPCOES);
            } else if ( (x >= 548 && x <= 754) && (y >= 542 && y <= 572)){
                hud.setTelaAtual(hud.MENU_CREDITOS);
            }
        }

        if (hud.getTelaAtual() == hud.MENU_OPCOES){
            cout.flush();
            cout << "x = " << x << " y = " << y << endl;
            if ( (x >= 358 && x <= 455) && (y >= 152 && y <= 175) ){

            } else if ( (x >= 578 && x <= 733) && (y >= 467 && y <= 497) ){

            } else if ( (x >= 548 && x <= 754) && (y >= 542 && y <= 572)){

            } else if ( (x >= 548 && x <= 754) && (y >= 542 && y <= 572)){

            } else if ( (x >= 548 && x <= 754) && (y >= 542 && y <= 572)){
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

    tocar_musica("introSound.ogg", -1);

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
        hud.showMenuCreditos();
        break;
    case 3:
        hud.showMenuOpcoes();
        break;
    case 4:
        hud.showJogoFase1();
        break;
    case 5:
        hud.showJogoFase2();
        break;
    case 6:
        hud.showJogoFase3();
        break;
    case 7:
        hud.showJogoFase4();
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
        reiniciaJogo();
        break;
    case 32:
        if (hud.getTelaAtual() == hud.SPLASHSCREEN){
            hud.setTelaAtual(hud.MENU);
            parar_musica();
        } else if (hud.getTelaAtual() == hud.JOGOFASE1 || hud.getTelaAtual() == hud.JOGOFASE2 ||
            hud.getTelaAtual() == hud.JOGOFASE3){
            bola.setVelocidadeX(10);
            bola.setVelocidadeY(rand() % 2 == 0 ? -10 : 10);
        } else if (hud.getTelaAtual() == hud.VITORIAJOGADOR1 || hud.getTelaAtual() == hud.VITORIAJOGADOR2){
            hud.setTelaAtual(hud.MENU);
        } else if (hud.getTelaAtual() == hud.MENU_OPCOES || hud.getTelaAtual() == hud.MENU_CREDITOS){
            hud.setTelaAtual(hud.MENU);
        }
        break;
    case 'w':
        if (hud.getTelaAtual() == 4 || hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider1.getY() + slider1.getAltura() >= hud.getScreenSizeY()){
                slider1.setVelocidadeY(0);
            } else {
                slider1.setVelocidadeY(10);
            }
            keys['w'] = 1;
        }
        break;
    case 's':
        if (hud.getTelaAtual() == 4 || hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider1.getY() <= 0){
                slider1.setVelocidadeY(10);
            } else {
                slider1.setVelocidadeY(-10);
            }
            keys['s'] = 1;
        }

        break;
    case 'o':
        if (hud.getTelaAtual() == 4 || hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider2.getY() + slider2.getAltura() >= hud.getScreenSizeY()){
                slider2.setVelocidadeY(0);
            } else {
                slider2.setVelocidadeY(10);
            }
            keys['o'] = 1;
        }

        break;
    case 'l':
        if (hud.getTelaAtual() == 4 || hud.getTelaAtual() == 5 || hud.getTelaAtual() == 6 || hud.getTelaAtual() == 7){
            if (slider2.getY() <= 0){
                slider2.setVelocidadeY(0);
            } else {
                slider2.setVelocidadeY(-10);
            }
            keys['l'] = 1;
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
    case 'o':
        if (slider2.getY() + slider2.getAltura() >= hud.getScreenSizeY()){
            slider2.setVelocidadeY(0);
        } else {
            slider2.setVelocidadeY(10);
        }
        keys['o'] = 0;
        break;
    case 'l':
        if (slider2.getY() <= 0){
            slider2.setVelocidadeY(0);
        } else {
            slider2.setVelocidadeY(-10);
        }
        keys['l'] = 0;
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

    if (keys['o'] != 0 || keys['l'] != 0){
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

    bola.setVelocidadeX(bola.getVelocidadeX() + 0.0001);
    bola.setVelocidadeY(bola.getVelocidadeY() + 0.0001);
    bola.setX(bola.getX() + bola.getVelocidadeX());
    bola.setY(bola.getY() + bola.getVelocidadeY());

    jogo.verificaSet();

    glutPostRedisplay();

    glutTimerFunc(1000.0/60.0, atualizaCena, 0);
}

void reiniciaJogo(){

    if (hud.getTelaAtual() == hud.JOGOFASE1 || hud.getTelaAtual() == hud.JOGOFASE2 ||
        hud.getTelaAtual() == hud.JOGOFASE3){

        bola.setX(750);
        bola.setY(450);
        bola.setVelocidadeX(0);
        bola.setVelocidadeY(0);
        player1.setPoints(0);
        player2.setPoints(0);
        jogo.setPlayer1Points(player1.getPoints());
        jogo.setPlayer2Points(player2.getPoints());
        jogo.setSetAtual(1);
        jogo.setSetsPlayer1(0);
        jogo.setSetsPlayer2(0);
    }
}
