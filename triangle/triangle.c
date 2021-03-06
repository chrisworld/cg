// --
// make a simple triangle

//#include "MicroGlut.h"
//#include "GL_utilities.h"

#include <GL/freeglut.h> 
#include <stdlib.h> 

void init(void);
void display(void);


// Globals
// Data would normally be read from files
GLfloat vertices[] = {-0.5f,-0.5f,0.0f, -0.5f,0.5f,0.0f, 0.5f,-0.5f,0.0f };

// vertex array object
unsigned int vertexArrayObjID;


// --
// init
void init(void)
{
  // vertex buffer object, used for uploading vertex data
  unsigned int vertexBufferObjID;

  // Reference to shader program:
  GLuint program;

  // GL inits
  glClearColor(0.2,0.2,0.5,0);
  glEnable(GL_DEPTH_TEST);

  // Load and compile shader
  program = loadShaders("minimal.vert", "minimal.frag"); // In our GL_utilities
  glUseProgram(program);

  // Allocate and activate Vertex Array Object
  glGenVertexArrays(1, &vertexArrayObjID);
  glBindVertexArray(vertexArrayObjID);

  // Allocate Vertex Buffer Objects
  glGenBuffers(1, &vertexBufferObjID);

  // VBO for vertex data
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID);
  glBufferData(GL_ARRAY_BUFFER, 9*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(glGetAttribLocation(program, "in_Position"), 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(glGetAttribLocation(program, "in_Position"));
}


// --
// display
void display(void)
{
  // clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Draw the triangle

  glBindVertexArray(vertexArrayObjID);// Select VAO
  glDrawArrays(GL_TRIANGLES, 0, 3);// draw object
  glFlush();
}


//--
// main
int main(int argc, const char *argv[])
{
  glutInit();
  glutCreateWindow ("GL3 white triangle example");
  glutDisplayFunc(display);
  init ();
  glutMainLoop();
}