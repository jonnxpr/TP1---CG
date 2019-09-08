

void redimensionar(int width, int height){
 //  glutFullScreen();
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-HUD::getScreenSizeX, HUD::getScreenSizeX, -HUD::getScreenSizeY, HUD::getScreenSizeY, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
