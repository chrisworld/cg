//--
// nothing

#include <GL/freeglut.h> 
#include <stdlib.h> 


// render
void RenderSceneCB(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers(); 
}


//--
// main
int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  
  // modes
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

  // window options
  glutInitWindowSize(1024, 768);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Tutorial 01");

  // dono
  glutDisplayFunc(RenderSceneCB);

  // background
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

  // loop
  glutMainLoop();
}