
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


#define ESCAPE 27
int texture[13];
//pid_t pid = fork();
int window;
int textura_fundo = 0;
int clique1 = 0;
float angulo_mirax = 0;
float angulo_miray = 0;
GLfloat tempo = 0;
GLfloat tempo1 = 0;

int LoadGLTextures() // Load Bitmaps And Convert To Textures
{

    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
        (
        "img/fundo1.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[0] == 0)
        return 0;

    texture[1] = SOIL_load_OGL_texture
        (
        "img/fundo2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[1] == 0)
        return 0;

    texture[2] = SOIL_load_OGL_texture
        (
        "img/fundo3.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[2] == 0)
        return 0;

    texture[3] = SOIL_load_OGL_texture
        (
        "img/fundo4.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[3] == 0)
        return 0;

    texture[4] = SOIL_load_OGL_texture
        (
        "img/fundo5.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[4] == 0)
        return 0;

    texture[5] = SOIL_load_OGL_texture
        (
        "img/fundo6.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[5] == 0)
        return 0;

    texture[6] = SOIL_load_OGL_texture
        (
        "img/fundo7.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[6] == 0)
        return 0;

    texture[7] = SOIL_load_OGL_texture
        (
        "img/samara.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[7] == 0)
        return 0;

    texture[8] = SOIL_load_OGL_texture
        (
        "img/exorcist.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[8] == 0)
        return 0;

    texture[9] = SOIL_load_OGL_texture
        (
        "img/penny.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[9] == 0)
        return 0;

    texture[10] = SOIL_load_OGL_texture
        (
        "img/samuel2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[10] == 0)
        return 0;

    texture[11] = SOIL_load_OGL_texture
        (
        "img/pressstart.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[11] == 0)
        return 0;

    texture[12] = SOIL_load_OGL_texture
        (
        "img/preto.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[12] == 0)
        return 0;

    texture[13] = SOIL_load_OGL_texture
        (
        "img/testepenny.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[13] == 0)
        return 0;


    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBindTexture(GL_TEXTURE_2D, texture[13]);


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
    glOrtho(-10,10,-((GLfloat)Width/(GLfloat)Height) * 10,((GLfloat)Width/(GLfloat)Height) * 10, 0, 10);
    //gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.01f,100.0f);
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
    //gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glOrtho(-10,10,-((GLfloat)Width/(GLfloat)Height) * 10,((GLfloat)Width/(GLfloat)Height) * 10, 0, 10);
    glMatrixMode(GL_MODELVIEW);
}

void drawFundo(int num)
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[num]);   // choose the texture to use.
    glTranslatef(0.0f,0.0f,-10.0f);              // move 5 units into the screen.

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

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  10.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  10.0f,  1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -1.0f);    // Top Right Of The Texture and Quad

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, -10.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f, -10.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  1.0f);    // Bottom Right Of The Texture and Quad

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f, -10.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  10.0f,  1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f, -10.0f,  1.0f);    // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  10.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -1.0f); // Top Left Of The Texture and Quad

    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void drawStart()
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[11]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,11.0f,-10.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Bottom Left Of The Texture and Quad

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);    // Bottom Right Of The Texture and Quad

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Top Left Of The Texture and Quad

    glEnd();
      glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawPreto()
{

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[12]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,11.0f,-10.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Bottom Left Of The Texture and Quad

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);    // Bottom Right Of The Texture and Quad

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Top Left Of The Texture and Quad

    glEnd();
      glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawPennyInicial()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[13]);   // choose the texture to use.
    glPushMatrix();
    glTranslatef(0.0f,-6.0f,0.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -2.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f,  3.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 2.0f,  3.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 2.0f, -2.0f, -1.0f);    // Bottom Left Of The Texture and Quad

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);    // Bottom Right Of The Texture and Quad

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);    // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Top Left Of The Texture and Quad

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawEspelho(int num)
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture[num]);   // choose the texture to use.
    glTranslatef(0.0f,0.0f,-10.0f);              // move 5 units into the screen.

    glBegin(GL_QUADS);

    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, -7.0f,  1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 7.0f, -7.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 7.0f,  7.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f,  7.0f,  1.0f); // Top Left Of The Texture and Quad

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.0f, -5.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.0f,  5.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 5.0f,  5.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 5.0f, -5.0f, -1.0f);    // Bottom Left Of The Texture and Quad

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f,  7.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f,  7.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 7.0f,  7.0f,  1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 7.0f,  7.0f, -1.0f);    // Top Right Of The Texture and Quad

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.0f, -7.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 7.0f, -7.0f, -1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 7.0f, -7.0f,  1.0f);    // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.0f, -7.0f,  1.0f);    // Bottom Right Of The Texture and Quad

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 5.0f, -5.0f, -1.0f);    // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 5.0f,  5.0f, -1.0f);    // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 5.0f,  5.0f,  1.0f);    // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 5.0f, -5.0f,  1.0f);    // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, -5.0f, -1.0f); // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.0f, -5.0f,  1.0f); // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.0f,  5.0f,  1.0f); // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f,  5.0f, -1.0f); // Top Left Of The Texture and Quad

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void desenhaBoneco(){
    //drawCircle(3.0,3.0,6.0);
}

void animacaoTelaInicial(){
  if(clique1 == 0){

    tempo1 = tempo1 + 1;
    glPushMatrix();
    drawFundo(2);
    glPopMatrix();
    if(tempo1 > 50.0 && tempo1 < 100.0){
      drawStart();
    }else if(tempo1 > 100.0 && tempo1 < 200.0){
      drawPreto();
    }else if(tempo1 > 200.0 && tempo1 < 300.0){
      drawStart();
    }else if(tempo1 > 300.0 && tempo1 < 400.0){
      drawPreto();
    }else if(tempo1 > 400 && tempo1 < 500.0){
      drawStart();
    }else if(tempo1 > 500 && tempo1 < 600.0){
      drawPreto();
    }else if(tempo1 > 600 && tempo1 < 610.0){
      drawPennyInicial();
    }else if(tempo1 > 625.0){
      tempo1 = 0;
    }
  }

}

void animacaoEspelhos(){
  if(clique1 == 1){
    tempo = tempo + 1;

    if(tempo > 0.0 && tempo < 100.0){
      glPushMatrix();
      drawEspelho(7);
      glPopMatrix();
    }
    else if(tempo > 100.0 && tempo < 200.0){
      glPushMatrix();
      drawEspelho(8);
      glPopMatrix();
    }
    else if(tempo > 200.0 && tempo < 300.0){
      glPushMatrix();
      drawEspelho(9);
      glPopMatrix();
    }
    else if(tempo > 300.0 && tempo < 400.0){
      glPushMatrix();
      drawEspelho(10);
      glPopMatrix();
    }
  }
}

void DrawGLScene()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); // Clear The Screen And The Depth Buffer

    glPushMatrix(); //  Salva a matriz corrente
    animacaoTelaInicial();
    glPopMatrix();  //  Desempilha a matriz corrente

    glPushMatrix();
    animacaoEspelhos();
    glPopMatrix();

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
    glutMainLoop();
    return 1;
}
