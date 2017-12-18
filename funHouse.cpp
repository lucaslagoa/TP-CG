
#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>  // Header File For The OpenGL32 Library
#include <GL/glu.h> // Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "SOIL.h"
#include <SFML/Audio.hpp>

sf::Music music;

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=4;
GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0}; //Black Color
GLfloat qaGreen[] = {1.0, 0.0, 0.0, 1.0}; //Green Color
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; //White Color
GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0}; //Red Color

    // Set lighting intensity and color
GLfloat qaAmbientLight[]    = {0.5, 0.5, 0.5, 1.0};
GLfloat qaDiffuseLight[]    = {5, 5, 5, 1.0};
GLfloat qaSpecularLight[]    = {5.0, 5.0, 5.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
    // Light source position
GLfloat qaLightPosition[]    = {0, 0, 2, 1};
GLfloat qaLightDirection[]    = {0, 1, 0, 0};
GLfloat dirVector0[]={ 0.0, 1.0, 0.0, 0.0};

int texture[27];
//pid_t pid = fork();
int window;
int textura_fundo = 0;
int clique1 = 0;
float angulo_mirax = 0;
float angulo_miray = 0;
float tempo = 0;
float tempo1 = 0;

void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     // Set lighting intensity and color
       glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    ////////////////////////////////////////////////


     glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);// set cutoff angle
     glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0);
     glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1); // set focusing strength


}

int LoadGLTextures() // Load Bitmaps And Convert To Textures
{

    texture[0] = SOIL_load_OGL_texture
        (
        "img/fundo3.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[0] == 0)
        return 0;

    texture[1] = SOIL_load_OGL_texture
        (
        "img/samuel2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[1] == 0)
        return 0;

    texture[2] = SOIL_load_OGL_texture
        (
        "img/pressstart.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[2] == 0)
        return 0;

    texture[3] = SOIL_load_OGL_texture
        (
        "img/preto.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[3] == 0)
        return 0;

    texture[4] = SOIL_load_OGL_texture
        (
        "img/testepenny.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[4] == 0)
        return 0;

    texture[5] = SOIL_load_OGL_texture
        (
        "img/frame-01.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[5] == 0)
        return 0;

    texture[6] = SOIL_load_OGL_texture
        (
        "img/frame-02.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[6] == 0)
        return 0;

    texture[7] = SOIL_load_OGL_texture
        (
        "img/frame-03.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[7] == 0)
        return 0;

    texture[8] = SOIL_load_OGL_texture
        (
        "img/frame-04.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[8] == 0)
        return 0;

    texture[9] = SOIL_load_OGL_texture
        (
        "img/frame-05.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

        if(texture[9] == 0)
            return 0;

  texture[10] = SOIL_load_OGL_texture
      (
      "img/frame-06.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[10] == 0)
      return 0;

  texture[11] = SOIL_load_OGL_texture
      (
      "img/penny1.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[11] == 0)
      return 0;

  texture[12] = SOIL_load_OGL_texture
      (
      "img/penny2.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[12] == 0)
      return 0;

  texture[13] = SOIL_load_OGL_texture
      (
      "img/penny3.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[13] == 0)
      return 0;

  texture[14] = SOIL_load_OGL_texture
      (
      "img/penny4.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[14] == 0)
      return 0;

  texture[15] = SOIL_load_OGL_texture
      (
      "img/penny5.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[15] == 0)
      return 0;

  texture[16] = SOIL_load_OGL_texture
      (
      "img/penny6.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[16] == 0)
      return 0;

  texture[17] = SOIL_load_OGL_texture
      (
      "img/slender1.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[17] == 0)
      return 0;


  texture[18] = SOIL_load_OGL_texture
      (
      "img/slender2.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[18] == 0)
      return 0;

  texture[19] = SOIL_load_OGL_texture
      (
      "img/slender3.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[19] == 0)
      return 0;

  texture[20] = SOIL_load_OGL_texture
      (
      "img/slender4.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[20] == 0)
      return 0;

  texture[21] = SOIL_load_OGL_texture
      (
      "img/slender5.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[21] == 0)
      return 0;

  texture[22] = SOIL_load_OGL_texture
      (
      "img/slender6.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[22] == 0)
      return 0;

  texture[23] = SOIL_load_OGL_texture
      (
      "img/slender7.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[23] == 0)
      return 0;

  texture[24] = SOIL_load_OGL_texture
      (
      "img/slender8.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[24] == 0)
      return 0;

  texture[25] = SOIL_load_OGL_texture
      (
      "img/zzz.jpg",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[25] == 0)
      return 0;

  texture[26] = SOIL_load_OGL_texture
      (
      "img/periodo.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[26] == 0)
      return 0;

  texture[27] = SOIL_load_OGL_texture
      (
      "img/selvagem.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );

  if(texture[26] == 0)
      return 0;

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    return 1;                                        // Return Success
}


void InitGL(int Width, int Height)          // We call this right after our OpenGL window is created.
{
    LoadGLTextures();               // Load The Texture(s)
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // This Will Clear The Background Color To Black
    glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);             // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);            // Enables Depth Testing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10,10,-((GLfloat)Width/(GLfloat)Height) * 10,((GLfloat)Width/(GLfloat)Height) * 10, 0, 100);
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.01f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
    if (Height==0)        // Prevent A Divide By Zero If The Window Is Too Small
       Height=1;

    glViewport(0, 0, Width, Height);    // Reset The Current Viewport And Perspective Transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    //glOrtho(-10,10,-((GLfloat)Width/(GLfloat)Height) * 10,((GLfloat)Width/(GLfloat)Height) * 10, 0, 10);
    glMatrixMode(GL_MODELVIEW);
}

void drawCircle( float x , float y , float raio , int num_lines,float r,float g,float b ) {
   float angulo = 0;
   glColor3f(r,g,b);
   glBegin ( GL_POLYGON );
    for (int i = 0; i < num_lines ;i++) {
       angulo = i * 2 * M_PI /num_lines ;
        glVertex2f (x + (cos (angulo) * raio) , (y + sin ( angulo ) * raio) );
      } glEnd ();

}

void desenhaCabeca( float x , float y , float raio , int num_lines, float r,float g, float b ){

  float angulo = 0;
  glColor3f(r , g, b );
  glBegin ( GL_POLYGON );
  for (int i = 0; i < num_lines ;i++) {
      angulo = i * 2 * M_PI /num_lines ;
      glVertex2f (x + (cos (angulo) * raio) , (y + sin ( angulo ) * raio) );
  }
  glEnd ();
}
void desenhaCorpo(){
  glBegin(GL_LINE_LOOP);
  glVertex2f(-0.5f, 0.5f);  // Top Left
  glVertex2f( 0.5f, 0.5f); // Top Right    // Top Right
  glVertex2f( 0.5f,-0.5f); // Bottom Right
  glVertex2f(-0.5f,-0.5f);    // Bottom Left
  glEnd();
}
void desenhaCadeira(){
  glBegin(GL_QUADS);
  glVertex2f(-0.5f, 0.5f);  // Top Left
  glVertex2f( 0.5f, 0.5f); // Top Right    // Top Right
  glVertex2f( 0.5f,-0.5f); // Bottom Right
  glVertex2f(-0.5f,-0.5f);    // Bottom Left
  glEnd();
}

void desenhaBraco(){
  glBegin(GL_QUADS);
  glVertex2f(-0.5f, 0.5f);  // Top Left
  glVertex2f( 0.5f, 0.5f); // Top Right    // Top Right
  glVertex2f( 0.5f,-0.5f); // Bottom Right
  glVertex2f(-0.5f,-0.5f);    // Bottom Left
  glEnd();
}
void desenhaBracoPersonagem(){
  glBegin(GL_QUADS);
  glVertex2f(-0.05f, 0.05f);  // Top Left
  glVertex2f( 0.05f, 0.05f); // Top Right    // Top Right
  glVertex2f( 0.05f,-0.05f); // Bottom Right
  glVertex2f(-0.05f,-0.05f);    // Bottom Left
  glEnd();

}

void desenhaPersonagens(float x,float z,float r, float g,float b,float levanta,float levanta2,float levanta3){

  glTranslatef(0.0f+x,-2.3f,z);
  glColor3f(1.0 , 0.0, 0.0 );
  desenhaCadeira();
  glTranslatef(0.0f+(x/2),0.75f,z);
  desenhaCabeca(0,-0.5,0.4,100,r,g,b);
  glTranslatef(0.0f+(x/2),-2.05f,z);
  glColor3f(r,g,b);
  desenhaCorpo();

  //desenhar os braços
  glPushMatrix();
    glTranslatef(0.8f+(x/2),0.0f,z);
    drawCircle(0,-0.5,0.1,100,r,g,b); //desenha o ombro do boneco
    glTranslatef(0.0f,levanta,0.0f);
      glPushMatrix();
        //glRotatef(30.0,0.0,0.0,-1.0);
        glScalef(1.0f,10.0f,0.0f);
        glColor3f(r,g,b);
        desenhaBracoPersonagem();
      glPopMatrix();
    glTranslatef(-1.60f,levanta2,0.0f);
    drawCircle(0,-0.5,0.1,100,r,g,b); //desenha o ombro do boneco
    glTranslatef(0.0f,levanta3,0.0f);
    glPushMatrix();
        //glRotatef(30.0,0.0,0.0,-1.0);
        glScalef(1.0f,10.0f,0.0f);
        glColor3f(r,g,b);
        desenhaBracoPersonagem();
      glPopMatrix();


  glPopMatrix();

  glTranslatef(-1.5f+(x/2),-2.0f,z);
  glColor3f(128.0f , 128.0f, 128.0f ); //deixa azul, mas ao fim vou colocar um cinza
  desenhaBraco(); //só que aqui vai ser o braço da cadeira*/

  glTranslatef(3.0f,0.0f,0.0f);
  glColor3f(128.0f , 128.0f, 128.0f ); //deixa azul, mas ao fim vou colocar um cinza
  desenhaBraco(); //só que aqui vai ser o braço da cadeira*/
}
void funhouse(){
	//initSong("Data/Songs/tema0.mp3", "repeatoff");
  //initSong("tema0.mp3", "repeatoff");
	glLoadIdentity();				// Reset The View
  glTranslatef(0.0f,0.0f,-6.0f);
	glPushMatrix();
	glScalef(1.2f,1.5f,1.0f);
	glPushMatrix();
  desenhaPersonagens(0,-6,1.0,1.0,1.0,-1.1,1.1,-1.1);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(2,-6,51.0,0.0,51.0,-1.1,1.1,-1.1);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(4,-6,0.0,1.0,0.0,-1.1,1.1,-1.1);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(-2,-6,0.0,0.0,1.0,-1.1,1.1,-1.1);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(-4,-6,1.0,1.0,0.0,-1.1,1.1,-1.1);
	glPopMatrix();
	glPopMatrix();


}

void funhouse2(){
	//initSong("Data/Songs/tema0.mp3", "repeatoff");
  //initSong("tema0.mp3", "repeatoff");
	glLoadIdentity();				// Reset The View
  glTranslatef(0.0f,0.0f,-6.0f);
	glPushMatrix();
	glScalef(1.2f,1.5f,1.0f);
	glPushMatrix();
  desenhaPersonagens(0,-6,1.0,1.0,1.0,0,0,0);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(2,-6,51.0,0.0,51.0,0,0,0);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(4,-6,0.0,1.0,0.0,0,0,0);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(-2,-6,0.0,0.0,1.0,0,0,0);
	glPopMatrix();
	glPushMatrix();
	desenhaPersonagens(-4,-6,1.0,1.0,0.0,0,0,0);
	glPopMatrix();
	glPopMatrix();


}
void desenhaPoltronaVazia(float x){
    glLoadIdentity();				// Reset The View
    glTranslatef(0.0f,0.0f,-6.0f);
	  glPushMatrix();
	  glScalef(1.2f,1.5f,1.0f);
	  glPushMatrix();
    glTranslatef(0.0f+x,-2.3f,-6);
    glColor3f(1.0 , 0.0, 0.0 );
    desenhaCadeira();
    glTranslatef(0.0f+(x/2),0.75f,-6);
    glTranslatef(0.0f+(x/2),-2.05f,-6);
    glTranslatef(-1.5f+(x/2),-2.0f,-6);
    glColor3f(128.0f , 128.0f, 128.0f ); //deixa azul, mas ao fim vou colocar um cinza
    desenhaBraco(); //só que aqui vai ser o braço da cadeira*/
    glTranslatef(3.0f,0.0f,0.0f);
    glColor3f(128.0f , 128.0f, 128.0f ); //deixa azul, mas ao fim vou colocar um cinza
    desenhaBraco(); //só que aqui vai ser o braço da cadeira*/
    glPopMatrix();
}
void drawFundo(int num)
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[num]);   // choose the texture to use.
    glTranslatef(0.0f,0.0f,-30.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f, -1.0f);    // Bottom Left Of The Texture and Quad


    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void drawStart()
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[2]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,11.0f,-30.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.0f, -1.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 3.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 3.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.0f,  1.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-3.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-3.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 3.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 3.0f, -1.0f, -1.0f);    // Bottom Left Of The Texture and Quad

    glEnd();
      glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawPreto()
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[3]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,11.0f,-30.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -2.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 4.0f, -2.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 4.0f,  2.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f,  2.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.0f, -2.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.0f,  2.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 4.0f,  2.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 4.0f, -2.0f, -1.0f);    // Bottom Left Of The Texture and Quad



    glEnd();
      glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawPennyInicial()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[4]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,-6.0f,-25.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -2.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 2.0f, -2.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 2.0f,  2.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f,  2.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -2.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f,  2.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 2.0f,  2.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 2.0f, -2.0f, -1.0f);    // Bottom Left Of The Texture and Quad


    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawEspelho(int num)
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[num]);   // choose the texture to use.
    glTranslatef(0.0f,0.0f,-30.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -5.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -5.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  5.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  5.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -5.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  5.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  5.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -5.0f, -1.0f);    // Bottom Left Of The Texture and Quad


    glEnd();
    glDisable(GL_TEXTURE_2D);
}


void drawZZZ(float x)
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[25]);   // choose the texture to use.
    glTranslatef(x,-8.0f,-30.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -2.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 2.0f, -2.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 2.0f,  2.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f,  2.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -2.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f,  2.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 2.0f,  2.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 2.0f, -2.0f, -1.0f);    // Bottom Left Of The Texture and Quad


    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void animacaoTelaInicial(){
    tempo1 = tempo1 + 1;
    glPushMatrix();
    drawFundo(0);
    glPopMatrix();
    if(tempo1 > 50.0 && tempo1 < 100.0){
      drawStart();
    }else if(tempo1 > 150.0 && tempo1 < 200.0){
      drawPreto();
    }else if(tempo1 > 200.0 && tempo1 < 250.0){
      drawStart();
    }else if(tempo1 > 250.0 && tempo1 < 300.0){
      drawPreto();
    }else if(tempo1 > 300.0 && tempo1 < 350.0){
      drawStart();
    }else if(tempo1 > 350.0 && tempo1 < 400.0){
      drawPreto();
    }else if(tempo1 > 400.0 && tempo1 < 450.0){
      drawPennyInicial();
    }else if(tempo1 > 450.0){
      tempo1 = 0;
    }
}

int animacaoEspelhos(){

  glTranslatef(0.0f,5.0f,0.0f);

    if(tempo < 460){
      glEnable(GL_LIGHTING);
      glPushMatrix();
      funhouse();
      glPopMatrix();
      
    }

    tempo = tempo + 1;
    if(tempo > 0.0 && tempo < 30.0){
	  // Loading sound
	  music.stop();
      if (!music.openFromFile("sound/som_da_ilha.ogg"))
		return -1; // error
	  music.play();
	  music.setVolume(40);			
		
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(5);
      drawZZZ(-15.0);
      glPopMatrix();
    }
    else if(tempo > 30.0 && tempo < 60.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(6);
      drawZZZ(-13.0);
      glPopMatrix();
    }
    else if(tempo > 60.0 && tempo < 80.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(7);
      drawZZZ(-10.0);
      glPopMatrix();
    }
    else if(tempo > 80.0 && tempo < 100.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(8);
      drawZZZ(-8.0);
      glPopMatrix();
    }
    else if(tempo > 100.0 && tempo < 120.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(9);
      drawZZZ(-6.0);
      glPopMatrix();
    }
    else if(tempo > 120.0 && tempo < 140.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(10);
      drawZZZ(-4.0);
      glPopMatrix();
    }
    else if(tempo > 140.0 && tempo < 160.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(11);
      drawZZZ(-2.0);
      glPopMatrix();
    }
    else if(tempo > 160.0 && tempo < 180.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(12);
      drawZZZ(0.0);
      glPopMatrix();
    }
    else if(tempo > 180.0 && tempo < 200.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(13);
      drawZZZ(2.0);
      glPopMatrix();
    }
    else if(tempo > 200.0 && tempo < 220.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(14);
      drawZZZ(4.0);
      glPopMatrix();
    }
    else if(tempo > 220.0 && tempo < 240.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(15);
      drawZZZ(6.0);
      glPopMatrix();
    }
    else if(tempo > 240.0 && tempo < 260.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(16);
      drawZZZ(8.0);
      glPopMatrix();
    }
    else if(tempo > 260.0 && tempo < 280.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(17);
      drawZZZ(10.0);
      glPopMatrix();
    }
    else if(tempo > 280.0 && tempo < 300.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(18);
      drawZZZ(12.0);
      glPopMatrix();
    }
    else if(tempo > 300.0 && tempo < 320.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(19);
      drawZZZ(14.0);
      glPopMatrix();
    }
    else if(tempo > 320.0 && tempo < 340.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(20);
      drawZZZ(16.0);
      glPopMatrix();
    }
    else if(tempo > 340.0 && tempo < 360.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(21);
      drawZZZ(18.0);
      glPopMatrix();
    }
    else if(tempo > 360.0 && tempo < 380.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(22);
      drawZZZ(20.0);
      glPopMatrix();
    }
    else if(tempo > 380.0 && tempo < 400.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(23);
      drawZZZ(22.0);
      glPopMatrix();
    }
    else if(tempo > 400.0 && tempo < 420.0){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(24);
      drawZZZ(24.0);
      glPopMatrix();
    }
    else if(tempo > 420.0 && tempo < 460.0){		
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(26);
      drawZZZ(26.0);
      glPopMatrix();
    }
    else if(tempo > 460.0 && tempo < 540.0){
	  music.stop();
      if (!music.openFromFile("sound/gritos.ogg"))
		return -1; // error
	  music.play();
	  music.setVolume(60);	
		
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(1);
      funhouse2();
      glPopMatrix();     
    }
    else if(tempo > 540 && tempo < 620){
      glDisable(GL_LIGHTING);
      glPushMatrix();
      drawEspelho(27);
      desenhaPoltronaVazia(0);
      desenhaPoltronaVazia(2);
      desenhaPoltronaVazia(4);
      desenhaPoltronaVazia(-2);
      desenhaPoltronaVazia(-4);
      glPopMatrix();
    }
    else if(tempo > 620.0){
      tempo = 0;
    }

	return 0;
}

void DrawGLScene()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); // Clear The Screen And The Depth Buffer
  if(clique1 == 0){
    glPushMatrix(); //  Salva a matriz corrente
    animacaoTelaInicial();
    glPopMatrix();  //  Desempilha a matriz corrente
} else{
  //boneco liga luz desenha tela desliga a luz
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaWhite);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaWhite);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    initLighting();
  //  glEnable(GL_LIGHTING);
    animacaoEspelhos();
    glPopMatrix();
}
    glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyboardCB( unsigned char key, int x, int y )
{
    switch (key){
        case 13: // ESC
            clique1 = 1;
  }
  // glutPostRedisplay();
}


void MouseClique(int button, int state, int xcoord, int ycoord)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        clique1 = 1;

    }

}

void MouseMove(int xcoord, int ycoord)
{
  angulo_mirax = GLfloat(xcoord);
  angulo_miray = GLfloat(ycoord);

  // glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(850,850);
    glutInitWindowPosition(0, 0);
    window = glutCreateWindow("FunHouse");

    glutSetCursor(GLUT_CURSOR_DESTROY);

    glutDisplayFunc(&DrawGLScene);
    glutIdleFunc(&DrawGLScene);
    glutReshapeFunc(&ReSizeGLScene);
    glutPassiveMotionFunc(MouseMove);
    glutKeyboardFunc(keyboardCB);
    glutMouseFunc(MouseClique);
    InitGL(500, 500);
    
    // Loading sound
	//sf::Music music;
	if (!music.openFromFile("sound/merchant__welcome!.wav"))
		return -1; // error
	music.play();
	music.setVolume(40);
    
    glutMainLoop();
    return 1;
}
