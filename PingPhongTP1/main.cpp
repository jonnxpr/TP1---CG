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
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitWindowSize(HUD::getScreenSizeX, HUD::getScreenSizeY);
    glutInitWindowPosition(HUD::getScreenInitPositionX, HUD::getScreenInitPositionY);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutCreateWindow("TP1 - Ping Phong - Copyright Tavares Games");

    glutReshapeFunc(redimensionar);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
