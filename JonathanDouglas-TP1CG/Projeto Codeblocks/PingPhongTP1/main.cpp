/****************************************************************************
*                              PING PHONG V.01                              *
* --------------------------------------------------------------------------*
* @AUTHOR: Jonathan Douglas Diego Tavares                                   *
* @TEACHER: Flávio Coutinho                                                 *
* @ENGINE: OpenGL + Glut + Glew + SOIL                                      *
* @LINGUAGEM: C++                                                           *
* @DATE: 07 de Setembro de 2019                                             *
****************************************************************************/

#include "bib.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitContextVersion(2, 1);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1500, 955);
    glutInitWindowPosition(0, 0);


    glutCreateWindow("TP1 - Ping Phong - Copyright Tavares Games");

    inicializa();

    glutReshapeFunc(redimensionar);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(1000.0/60.0, atualizaCena, 0);
    //glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
