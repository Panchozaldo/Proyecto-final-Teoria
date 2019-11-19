//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//**************Practica11 *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
//Variables de dibujo y manipulacion
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotBraIzq = 0, rotRodDer = 0, rotBraDer = 0;
float giroMonito = 0;

#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotBraIzq;
	float rotRodDer;
	float rotBraDer;
	float rotInc;
	float rotInc2;
	float rotInc3;
	float rotInc4;
	float giroMonito;
	float giroMonitoInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };
bool g_fanimacion = false;
bool g_fanimacion2 = false;
bool g_fanimacion3 = false;
float x = 0;
float y = 0;
float i = 0;
float velocidad = 1.0;
float angulo = 45.0;
float gravedad = 9.81;
float movx = 0;
float movy = 0;
float movx2 = 0;
float movy2 = 0;
float movx3 = 0;
float movy3 = 0;
float movx4 = 0;
float movy4 = 0;
float giro = 0;
float giro2 = 0;
float giro3 = 0;
float v1 = 0;
float v2 = 0;
float undi = 0;
bool anima1 = false;
bool anima12 = false;
bool anima2 = false;
bool anima22 = false;
bool anima3 = false;
bool anima32 = false;
bool anima4 = false;
bool anima42 = false;
bool anima5 = false;
bool anima52 = false;
bool anima6 = false;
bool anima62 = false;
bool anima7 = false;
bool anima72 = false;
CTexture cuerda;
CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture luffy;
CTexture locker;

//NEW///////////////////////////7
CTexture mar;
CTexture pisoazul;
CTexture sillon;
CTexture ventana;
CTexture barra;
CTexture mantel;
CTexture pisom;
CTexture pisod;
CTexture sillas;
CTexture suny1;
CTexture suny2;
CTexture suny3;
CTexture suny4;
CTexture formaica;
CTexture techo;
CTexture metal;
CTexture extrac;
CTexture cajonera;
CTexture ala;
CTexture esponja;
CTexture cobre;
CTexture luz;
CTexture maderacol;
CTexture facha;
CTexture madene;
CTexture madebla;
CTexture puerta;
CTexture puerta2;
CTexture caoba;
CTexture agua;
CTexture recompensa;
CTexture escudo;
CTexture acero;

//NEW///////////////////////////7
CTexture textSky;


//***ROSE****
//CFiguras fig1;
//CFiguras fig5;
CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras sila;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;
CFiguras bola;
//*****ROSE*****

CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras laptop;
CFiguras sillo;
CFiguras basesi;
CFiguras cajon;
CFiguras lampa;
CFiguras bases;
CFiguras bara;
CFiguras alacena;
CFiguras patam;
CFiguras fachada;

float abrirPuerta = 0;
//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito


void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame[FrameIndex].rotRodDer = rotRodDer;
	KeyFrame[FrameIndex].giroMonito = giroMonito;
	KeyFrame[FrameIndex].rotBraIzq = rotBraIzq;
	KeyFrame[FrameIndex].rotBraDer = rotBraDer;

	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;
	rotBraIzq = KeyFrame[0].rotBraIzq;
	rotRodDer = KeyFrame[0].rotRodDer;
	rotBraDer = KeyFrame[0].rotBraDer;
	giroMonito = KeyFrame[0].giroMonito;

}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame[playIndex].rotInc2 = (KeyFrame[playIndex + 1].rotBraIzq - KeyFrame[playIndex].rotBraIzq) / i_max_steps;
	KeyFrame[playIndex].rotInc3 = (KeyFrame[playIndex + 1].rotBraDer - KeyFrame[playIndex].rotBraDer) / i_max_steps;
	KeyFrame[playIndex].rotInc4 = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;

}

//
//void ciudad ()
//{
//
//		glPushMatrix(); //Camino1
//			glTranslatef(23.5,0.0,0.0);
//			glScalef(40,0.1,7);
//			glDisable(GL_LIGHTING);
//			fig3.prisma2(text4.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//		glPushMatrix(); //Camino2
//			glTranslatef(-23.5,0.0,0.0);
//			glScalef(40,0.1,7);
//			glDisable(GL_LIGHTING);
//			fig3.prisma2(text4.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//		glPushMatrix(); //Pasto
//			glTranslatef(0.0,0.0,-4.0);
//			glScalef(87,0.1,1);
//			glDisable(GL_LIGHTING);
//			fig4.prisma2(text5.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//		glPushMatrix(); //Pasto
//			glTranslatef(0.0,0.0,4.0);
//			glScalef(87,0.1,1);
//			glDisable(GL_LIGHTING);
//			fig4.prisma2(text5.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//		glPushMatrix(); //Casa01
//			glTranslatef(0.0,3.0,7.0);
//			glRotatef(90,1,0,0);
//			glRotatef(180,0,0,1);
//			glScalef(6,5.0,6);
//			glDisable(GL_LIGHTING);
//			fig5.prisma2(text6.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//		glPushMatrix(); //Casa01
//			glTranslatef(0.0,3.0,-7.0);
//			glRotatef(90,1,0,0);
//			//glRotatef(180,0,0,1);
//			glScalef(6,5.0,6);
//			glDisable(GL_LIGHTING);
//			fig5.prisma2(text6.GLindex, 0);
//			glEnable(GL_LIGHTING);
//		glPopMatrix();
//
//}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, text2.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-45 + rotBraDer, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45 + rotBraIzq, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodDer, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}



//NEW CASA//////////////////////////////////////

void cosineta(void)
{
	glPushMatrix();

	glTranslatef(0, 15, 0);
	bases.prisma31(33, 10, 96, madebla.GLindex);
	glTranslatef(0, 30, -38);
	bases.prisma(27, 10, 20, madebla.GLindex);
	glTranslatef(0, 17.5, 0);
	bases.prisma(26, 10, 20, madebla.GLindex);
	glTranslatef(0, 0, 30);
	bases.prisma(26, 10, 40, extrac.GLindex);
	glTranslatef(0, 0, 38);
	bases.prisma31(26, 10, 36.5, madebla.GLindex);
	glTranslatef(0, -22, 17.75);
	bases.prisma31(20, 10, 1, madebla.GLindex);
	glTranslatef(0, -9, -18.25);
	bases.cilindro(2.5, 13, 30, suny2.GLindex);
	glTranslatef(0, 0, -18);
	bases.cilindro(2.5, 15, 30, suny3.GLindex);
	glTranslatef(0, 1, -18);
	glRotatef(90, 0, 1, 0);
	bases.cilindro(5, 5, 30, suny4.GLindex);
	glPopMatrix();
}


void mesa(void) {
	//mesa	
		//tabla
	glPushMatrix();
	cono.cilindro(5, 23, 30, maderacol.GLindex);
	glTranslatef(0, 23, 0);
	tablaMesa.prisma(1, 20, 30, mantel.GLindex);
	glTranslatef(0, -2, -15);
	tablaMesa.prisma(5, 20, 0.5, mantel.GLindex);
	glTranslatef(0, 0, 30);
	tablaMesa.prisma(5, 20, 0.5, mantel.GLindex);
	glTranslatef(10, 0, -15);
	tablaMesa.prisma(5, 0.5, 30, mantel.GLindex);
	glTranslatef(-20, 0, 0);
	tablaMesa.prisma(5, 0.5, 30, mantel.GLindex);


	glPopMatrix();

	return;
}

void silla(void) {
	glPushMatrix();
	sila.cilindro(1, 15, 20, maderacol.GLindex);
	glTranslatef(0, 15, 0);
	sila.prisma(1, 5, 5, sillas.GLindex);
	glTranslatef(-2, 8, 0);
	sila.prisma(15, 1, 5, sillas.GLindex);

	glPopMatrix();

	return;
}

void venta() {
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	basesi.prisma(0.1, 8, 8, ventana.GLindex);

	glPopMatrix();

	return;
}

void barras(void) {
	glPushMatrix();
	bara.prisma(5, 10, 60, barra.GLindex);
	glTranslatef(0, 12.5, 0);
	bara.prisma31(20, 10, 60, caoba.GLindex);
	glTranslatef(0, 15, 0);
	bara.prisma31(10, 14, 60, barra.GLindex);
	glTranslatef(0, 6, 20);
	bara.prisma(2, 10, 10, madene.GLindex);
	glTranslatef(-11, -35, -48);
	bara.cilindro(0.5, 30, 30, metal.GLindex);
	glTranslatef(0, 30, 0);
	glRotatef(90, 1, 0, 0);
	bara.cilindro(1, 55, 30, esponja.GLindex);
	glTranslatef(0, 55, 30);
	glRotatef(-90, 1, 0, 0);
	bara.cilindro(0.5, 30, 30, metal.GLindex);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7.5, -1, -29);
	bara.cilindro(0.5, 5, 30, metal.GLindex);
	glTranslatef(0, 0, 58);
	bara.cilindro(0.5, 5, 30, metal.GLindex);
	glTranslatef(0, 5, -58);
	glRotatef(90, 1, 0, 0);
	bara.cilindro(1, 58, 30, metal.GLindex);

	glPopMatrix();
}
void camas(void) {
	glPushMatrix();
	bara.cilindro(0.5,25,20, cuerda.GLindex);
	glTranslatef(0,0,0);
	glRotatef(165,1,0,0);
	bara.cilindro(0.5,20,20, cuerda.GLindex);
	glRotatef(35, 1, 0, 0);
	bara.cilindro(0.5, 20, 20, cuerda.GLindex);
	glRotatef(-200,1,0,0);
	glTranslatef(-30,0,0);
	bara.cilindro(0.5, 25, 20, cuerda.GLindex);
	glTranslatef(0, 0, 0);
	glRotatef(165, 1, 0, 0);
	bara.cilindro(0.5, 20, 20, cuerda.GLindex);
	glRotatef(35, 1, 0, 0);
	bara.cilindro(0.5, 20, 20, cuerda.GLindex);
	glRotatef(-200,1,0,0);
	glTranslatef(15,-25,0);
	bases.prisma(10,30,20, formaica.GLindex);

}

void locke(void) {
	glPushMatrix();
	bara.prisma(60, 30, 9.5, pisoazul.GLindex);
	glTranslatef(0, 0, -5.05);
	bara.prisma(60, 30, 0.5, locker.GLindex);
}

void tatami(void) {
	glPushMatrix();
	bara.prisma(10, 10, 20, formaica.GLindex);
	glTranslatef(0, 10, 0);
	bara.prisma(10, 30, 20, formaica.GLindex);
	glTranslatef(-20, -14.5, 0);
	bara.prisma(0.5,5,20, pisoazul.GLindex);
	glTranslatef(37,0,0);
	bara.prisma(0.5, 5, 20, pisoazul.GLindex);
	glTranslatef(3,3,-10);
	glRotatef(90,1,0,0);
	bara.cilindro(2.5,20,30, pisoazul.GLindex);
	glTranslatef(-43,0,0);
	bara.cilindro(2.5, 20, 30, pisoazul.GLindex);
	glRotatef(-90,1,0,0);

}
void alace(void) {
	glPushMatrix();
	alacena.prisma(3, 10, 50, metal.GLindex);
	glTranslatef(0, 6.5, 0);
	bara.prisma31(10, 9, 60, formaica.GLindex);
	glTranslatef(-5, 4, 0);
	bara.prisma(2, 2, 60, formaica.GLindex);
	glTranslatef(0, -8, 0);
	bara.prisma(2, 2, 60, formaica.GLindex);
	glTranslatef(0, 4, 0);
	bara.prisma(2, 2, 60, formaica.GLindex);
	glTranslatef(0, 0, -29.5);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(6, 2, 1, formaica.GLindex);
	glTranslatef(0, 2, -55.5);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, 3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, -4, 0);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);
	glTranslatef(0, 0, -3);
	bara.prisma(2, 2, 2, madene.GLindex);

	glPopMatrix();
}
void casa(void) {
	//*****casa*****
	glPushMatrix(); //Creamos paredes
	glTranslatef(150, 20, 20);
	fig1.prisma3(80.0, 1.0, 100.0, formaica.GLindex);
	glTranslatef(-20, 0, 50);
	fig1.prisma(80.0, 40.0, 2.0, metal.GLindex);
	glTranslatef(-50, 0, 0);
	fig1.prisma3(80.0, 60.0, 2.0, facha.GLindex);
	glTranslatef(-30, 0, -50);
	fig1.prisma3(80.0, 0.0, 100.0, facha.GLindex);
	glTranslatef(30, -40, 0);
	pisoCasa.prisma3(1.0, 60.0, 100.0, pisom.GLindex);
	glTranslatef(50, 0, 0);
	pisoCasa.prisma3(1.0, 40.0, 100.0, pisod.GLindex);
	glTranslatef(-30, 80, 0);
	techoCasa.prisma3(1, 100, 100, techo.GLindex);
	glTranslatef(60, -40, 0);
	fig1.prisma3(80, 20, 100, facha.GLindex);
	glTranslatef(10, -20, -50);
	glRotatef(90, 1, 0, 0);
	fig2.cilindro(20, 100, 100, facha.GLindex);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(10, 30, 50);
	fig3.prisma3(60, 20, 100, facha.GLindex);
	glTranslatef(-141, -10, 0);
	fig3.prisma3(80.0, 20, 100, facha.GLindex);
	glTranslatef(20, 0, -50);
	fig1.prisma3(80, 40, 1, facha.GLindex);
	glTranslatef(30, -10, 0);
	fig1.prisma(60, 20, 1, puerta.GLindex);
	glTranslatef(0, 40, 0);
	fig1.prisma(20, 20, 1, facha.GLindex);
	glTranslatef(50, -30, 0);
	fachada.prisma3(80, 80, 1, facha.GLindex);

	glPopMatrix();
	glPushMatrix();
	//patio
	glTranslatef(130, -22, -50);
	glRotatef(270, 0, 1, 0);
	pisoCasa.prisma(1, 500, 500, mar.GLindex);
	glPopMatrix();
	return;
}

void casa2(void) {
	//*****casa*****
	glPushMatrix(); //Creamos paredes
	glTranslatef(150, 0, 20);
	fig1.prisma3(70.0, 1.0, 100.0, pisom.GLindex);
	glTranslatef(0,40,0);
	fig2.prisma(10,1,100, madebla.GLindex);
	glTranslatef(-50, -40, 50);
	fig1.prisma3(70.0, 100.0, 2.0, pisom.GLindex);
	glTranslatef(0,40,0);
	fig2.prisma(10,100,2.0, madebla.GLindex);
	glTranslatef(-50, -40, -50);
	fig1.prisma3(70.0, 1.0, 100.0, pisom.GLindex);
	glTranslatef(0, 40, 0);
	fig2.prisma(10, 1, 100, madebla.GLindex);
	glTranslatef(20, -75, 0);
	pisoCasa.prisma3(1.0, 40.0, 100.0, pisoazul.GLindex);
	glTranslatef(50, 0, 0);
	glRotatef(90,0,1,0);
	pisoCasa. prisma3(1.0, 100.0, 60.0, pisom.GLindex);
	glTranslatef(0,80,0);
	techoCasa.prisma3(1, 100, 60, pisom.GLindex);
	glRotatef(-90,0,1,0);
	glTranslatef(-50, 0, 0);
	techoCasa.prisma3(1, 40, 100, techo.GLindex);
	glTranslatef(100.5, -40, 0);
	fig1.prisma3(80, 40, 100, facha.GLindex);
	glTranslatef(-131, 0, 0);
	fig3.prisma3(80.0, 20, 100, facha.GLindex);
	glTranslatef(60, -5, -49.5);
	fig1.prisma3(70, 100, 1, pisom.GLindex);
	glTranslatef(0,40,0);
	fig1.prisma(10,100,0.5, madebla.GLindex);
	glTranslatef(10, -35, -0.5);
	fig1.prisma3(80, 160, 0.5, facha.GLindex);
	
	glPopMatrix();
}

void sillones(void) {
	glPushMatrix();
	cubo.prisma(5, 10, 50, maderacol.GLindex);
	glTranslatef(0, 7.5, 0);
	cubo.prisma31(10, 10, 50, sillon.GLindex);
	glTranslatef(-3.75, 10, 0);
	cubo.prisma31(10, 2.5, 50, sillon.GLindex);
	glTranslatef(5, 0, -22.5);
	cubo.prisma(10, 7.5, 5, sillon.GLindex);
	glTranslatef(0, 0, 45);
	cubo.prisma(10, 7.5, 5, sillon.GLindex);
	glPopMatrix();
	return;
}
void baril(void) {
	glPushMatrix();
	cubo.cilindro(5, 40, 50, facha.GLindex);
	glTranslatef(0, 30, 0);
	cubo.cilindro(5.05, 2.5, 50, suny4.GLindex);
	glTranslatef(0, -20, 0);
	cubo.cilindro(5.05, 2.5, 50, suny4.GLindex);
	glPopMatrix();
	return;
}
//****ROSE****
void lamparas(void)
{


	glPushMatrix();
	lampa.cilindro(2.5, 5, 40, luz.GLindex);
	glTranslatef(0, -5, 0);
	lampa.cilindro(2.5, 5, 40, cobre.GLindex);
	glTranslatef(0, -0.4, 0);
	glRotatef(90, 0, 0, 1);
	lampa.cilindro(0.5, 6, 40, cobre.GLindex);
	glTranslatef(-0.5, 5, 0);
	lampa.cilindro(3, 1, 30, cobre.GLindex);
	glPopMatrix();


}


void tarja(void)
{
	glPushMatrix();
	bases.prisma31(5, 10, 60, madene.GLindex);
	glTranslatef(0, 7.5, 0);
	bases.prisma31(10, 10, 60, acero.GLindex);
	glTranslatef(3.75, 10, 0);
	bases.prisma31(10, 2.5, 60, acero.GLindex);
	glTranslatef(-7.5, 0, 0);
	bases.prisma31(10, 2.5, 60, acero.GLindex);
	glTranslatef(3.75, 0, -20);
	bases.prisma31(10, 5, 10, agua.GLindex);
	glTranslatef(0, 0, -7.5);
	bases.prisma(10, 5, 5, acero.GLindex);
	glTranslatef(0, 0, 22.5);
	bases.prisma31(10, 5, 10, agua.GLindex);
	glTranslatef(0, 0, -7.5);
	bases.prisma(10, 5, 5, acero.GLindex);
	glTranslatef(0, 0, 27.5);
	bases.prisma(10, 5, 30, acero.GLindex);

	glPopMatrix();
}

void tocador(void) {
	glPushMatrix();
	cubo.prisma(15, 10, 10, cajonera.GLindex);
	glTranslatef(0, 8.5, 0);
	cubo.prisma(2, 10, 10, madene.GLindex);
	glTranslatef(0, 4, 0);
	cubo.prisma(6, 10, 10, cajonera.GLindex);
	glTranslatef(4.5, -21, 4);
	cubo.prisma(2, 2, 2, cajonera.GLindex);
	glTranslatef(-9, 0, 0);
	cubo.prisma(2, 2, 2, cajonera.GLindex);
	glTranslatef(0, 0, -8);
	cubo.prisma(2, 2, 2, cajonera.GLindex);
	glTranslatef(9, 0, 0);
	cubo.prisma(2, 2, 2, cajonera.GLindex);

	glPopMatrix();
	return;
}
//END CASA////////////////////////////////////





GLuint createDL()
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL, GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		//ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);


	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	mar.LoadTGA("mar.tga");
	mar.BuildGLTexture();
	mar.ReleaseImage();

	acero.LoadTGA("acero.tga");
	acero.BuildGLTexture();
	acero.ReleaseImage();

	locker.LoadTGA("locker.tga");
	locker.BuildGLTexture();
	locker.ReleaseImage();

	cuerda.LoadTGA("cuerda.tga");
	cuerda.BuildGLTexture();
	cuerda.ReleaseImage();

	luffy.LoadTGA("luffy.tga");
	luffy.BuildGLTexture();
	luffy.ReleaseImage();

	recompensa.LoadTGA("recompesa.tga");
	recompensa.BuildGLTexture();
	recompensa.ReleaseImage();

	escudo.LoadTGA("escudo.tga");
	escudo.BuildGLTexture();
	escudo.ReleaseImage();

	madebla.LoadTGA("madebla.tga");
	madebla.BuildGLTexture();
	madebla.ReleaseImage();

	puerta.LoadTGA("puerta.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	puerta2.LoadTGA("puerta2.tga");
	puerta2.BuildGLTexture();
	puerta2.ReleaseImage();

	agua.LoadTGA("agua.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();


	pisoazul.LoadTGA("pisoazul.tga");
	pisoazul.BuildGLTexture();
	pisoazul.ReleaseImage();

	ventana.LoadTGA("vantana.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	facha.LoadTGA("fachada.tga");
	facha.BuildGLTexture();
	facha.ReleaseImage();

	barra.LoadTGA("bara.tga");
	barra.BuildGLTexture();
	barra.ReleaseImage();

	madene.LoadTGA("maden.tga");
	madene.BuildGLTexture();
	madene.ReleaseImage();

	mantel.LoadTGA("mantel.tga");
	mantel.BuildGLTexture();
	mantel.ReleaseImage();

	pisom.LoadTGA("pisom.tga");
	pisom.BuildGLTexture();
	pisom.ReleaseImage();

	pisod.LoadTGA("pisod.tga");
	pisod.BuildGLTexture();
	pisod.ReleaseImage();

	sillas.LoadTGA("sillas.tga");
	sillas.BuildGLTexture();
	sillas.ReleaseImage();

	sillon.LoadTGA("sillon.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	suny1.LoadTGA("suny1.tga");
	suny1.BuildGLTexture();
	suny1.ReleaseImage();

	suny2.LoadTGA("suny2.tga");
	suny2.BuildGLTexture();
	suny2.ReleaseImage();

	suny3.LoadTGA("suny3.tga");
	suny3.BuildGLTexture();
	suny3.ReleaseImage();

	suny4.LoadTGA("suny4.tga");
	suny4.BuildGLTexture();
	suny4.ReleaseImage();

	formaica.LoadTGA("formaica.tga");
	formaica.BuildGLTexture();
	formaica.ReleaseImage();

	maderacol.LoadTGA("maderacolum.tga");
	maderacol.BuildGLTexture();
	maderacol.ReleaseImage();

	techo.LoadTGA("techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	metal.LoadTGA("metal.tga");
	metal.BuildGLTexture();
	metal.ReleaseImage();

	caoba.LoadTGA("caoba.tga");
	caoba.BuildGLTexture();
	caoba.ReleaseImage();

	extrac.LoadTGA("extrac.tga");
	extrac.BuildGLTexture();
	extrac.ReleaseImage();

	cajonera.LoadTGA("cajonera.tga");
	cajonera.BuildGLTexture();
	cajonera.ReleaseImage();

	ala.LoadTGA("ala.tga");
	ala.BuildGLTexture();
	ala.ReleaseImage();

	esponja.LoadTGA("esponja.tga");
	esponja.BuildGLTexture();
	esponja.ReleaseImage();

	cobre.LoadTGA("cobre.tga");
	cobre.BuildGLTexture();
	cobre.ReleaseImage();

	luz.LoadTGA("luz.tga");
	luz.BuildGLTexture();
	luz.ReleaseImage();

	textSky.LoadBMP("Casa/blue-sky-texture.bmp");
	textSky.BuildGLTexture();
	textSky.ReleaseImage();
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i < MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].posY = 0;
		KeyFrame[i].posZ = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].rotRodIzq = 0;
		KeyFrame[i].rotRodDer = 0;
		KeyFrame[i].rotBraIzq = 0;
		KeyFrame[i].rotBraDer = 0;
		KeyFrame[i].rotInc = 0;
		KeyFrame[i].rotInc2 = 0;
		KeyFrame[i].rotInc3 = 0;
		KeyFrame[i].rotInc4 = 0;
		KeyFrame[i].giroMonito = 0;
		KeyFrame[i].giroMonitoInc = 0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();


	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//CASA///////////////////
	//¨****casa*****
	glPushMatrix();
	glScalef(1.0, 0.5, 1.0);
	glTranslatef(30, 3, -40);
	glRotatef(180, 0, 1, 0);
	glDisable(GL_LIGHTING);
	glScalef(0.3, 0.3, 0.3);
	casa();
	
	glPushMatrix();
	glPushMatrix();
	glTranslatef(56, -18, 0);
	sillones();
	glTranslatef(56, 40, 0);
	lamparas();
	glTranslatef(0, 0, 30);
	lamparas();
	glTranslatef(42, 0, 14);
	glRotatef(90, 0, 1, 0);
	lamparas();
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(51, 30, -15);
	venta();
	glTranslatef(0, 0, 30);
	venta();
	glTranslatef(0, 0, 30);
	venta();
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(61, -10, 31);
	tocador();
	glTranslatef(37, -10, 29);
	cajon.cilindro(10, 79, 30, maderacol.GLindex);
	glTranslatef(0, 40, 0);
	patam.cilindro(12, 2, 30, caoba.GLindex);
	glTranslatef(0, -4, 0);
	patam.cilindro(10.5, 2, 30, caoba.GLindex);
	glTranslatef(0, -4, 0);
	patam.cilindro(10.5, 2, 30, caoba.GLindex);
	glTranslatef(-20, 8, 8);
	patam.prisma(79, 2, 2, maderacol.GLindex);
	glTranslatef(-5, -37, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(0, 8, 0);
	patam.prisma(2, 8, 2, maderacol.GLindex);
	glTranslatef(-5, -35, 0);
	patam.prisma(79, 2, 2, maderacol.GLindex);
	glTranslatef(-10.5, -10, 0.95);
	patam.prisma(60, 15, 0.05, puerta2.GLindex);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(73, movy3 - 18, 65);
	glRotatef(-100, 0, 1, 0);
	bara.cilindro(3, 15, 300, luffy.GLindex);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(90, -20, 30);
	mesa();
	glTranslatef(-10, 0, 10);
	silla();
	glTranslatef(0, 0, -10);
	silla();
	glTranslatef(0, 0, -10);
	silla();
	glTranslatef(10, 0, -10);
	glRotatef(270 + giro2, 0, 1, 0);//////////animacio1
	silla();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(100, -20, 20);
	glRotatef(180, 0, 1, 0);
	silla();
	glTranslatef(0, 0, -10);
	silla();
	glTranslatef(0, 0, -10);
	silla();
	glTranslatef(10, 0, -5);
	glRotatef(-90, 0, 1, 0);
	silla();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(115, -17, 40);
	barras();
	glTranslatef(0, 65, 0);
	alace();
	glTranslatef(10.2, -65, 0);
	tarja();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(20, 0, -20);
	cosineta();
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(70, 5 + y, -x);
	bola.esfera(3, 30, 30, luz.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(81 + movx, 6, 16 + movy);
	glRotatef(giro3, v1, 0, v2);
	bola.esfera(2, 30, 30, madene.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(110 + movx2, 15 + movy2 + undi, 30);
	glRotatef(giro, 0, 0, 1);
	bases.cono(6, 2, 30, cobre.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,95.25,0);
		casa2();
		glPushMatrix();
			glTranslatef(85, 20, 45);
			camas();
			glTranslatef(15,0,0);
			camas();
			glTranslatef(15, 50, -30);
			camas();
			glTranslatef(15, 0, 0);
			camas();
			glTranslatef(15, 50, -30);
			camas();
			glTranslatef(15, 0, 0);
			camas();
			glTranslatef(10,-10,-10);
			bara.cilindro(0.5,40,30, cuerda.GLindex);
			glTranslatef(0, 10, 0);
			glRotatef(90,0,0,1);
			bara.cilindro(0.5,10,30, cuerda.GLindex);
			glTranslatef(5, 0, 0);
			bara.cilindro(0.5, 10, 30, cuerda.GLindex);
			glTranslatef(5,0, 0);
			bara.cilindro(0.5, 10, 30, cuerda.GLindex);
			glTranslatef(5,0, 0);
			bara.cilindro(0.5, 10, 30, cuerda.GLindex);
			glTranslatef(5,0, 0);
			bara.cilindro(0.5, 10, 30, cuerda.GLindex);
			glTranslatef(5, 0, 0);
			bara.cilindro(0.5, 10, 30, cuerda.GLindex);

			glRotatef(-90,0,0,1);
			glTranslatef(-10, -35, 0);
			bara.cilindro(0.5, 40, 30, cuerda.GLindex);

			glTranslatef(10,35,90);
			locke();
			glTranslatef(63,-30,4);
			baril();
			glTranslatef(123,-35,63);
			baril();
			glTranslatef(3, 5, -33);
			tatami();
			glTranslatef(46.5,27,30);
			fig1.prisma(60,0.05,20, puerta2.GLindex);
			glTranslatef(-98.95, 0, 0);
			fig1.prisma(60, 0.05, 20, puerta2.GLindex);
			glTranslatef(90,30,19);
			bara.prisma(20,20,0.5, recompensa.GLindex);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glTranslatef(-35, 0, 0);
			bara.prisma(20, 20, 0.5, escudo.GLindex);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
	glPopMatrix();
	
	glEnable(GL_LIGHTING);
	glPopMatrix();



	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Proyecto Final");
	pintaTexto(-11, 8.5, -14, (void *)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;

	//Movimiento del monito
	if (g_fanimacion)
	{
		if (i < 2) {
			i += 0.1;

			x = (velocidad*0.1* i*cos(angulo)) - (0.5*(gravedad *(i*i)));
			y = (velocidad*0.1* i*sin(angulo)) - (0.5*(gravedad *(i*i)));
		}
		else {
			g_fanimacion = false;
			g_fanimacion2 = true;
		}
	}
	if (g_fanimacion2) {
		if (i >= 0) {
			i = i - 0.1;
			y = (velocidad*0.1* i*sin(angulo)) - (0.5*(gravedad *(i*i)));
		}
		else {
			g_fanimacion2 = false;
			g_fanimacion3 = true;
		}
	}
	if (g_fanimacion3) {
		if (x < 0) {
			i = i + 0.1;
			x = x + i;
		}
		else {
			g_fanimacion3 = false;
			g_fanimacion = true;
		}
	}
	if (anima1) {
		if (movx < 17) {
			movx = movx + 0.1;
			giro3 -= 5;
			v2 = 1;
			v1 = 0;

		}
		else {
			anima1 = false;
			anima12 = true;
		}
	}
	if (anima12) {
		if (movy < 28) {
			movy = movy + 0.1;
			giro3 += 5;
			v2 = 0;
			v1 = 1;
		}
		else
		{
			anima12 = false;
			anima2 = true;
		}
	}
	if (anima2) {
		if (movx > 0) {
			movy = movy - 0.1;
			movx = movx - 0.06;
			giro3 -= 10;
			v2 = 1;
			v1 = 1;
		}
		else
		{
			anima2 = false;
			anima1 = true;
		}
	}
	if (anima22) {
		if (movy > 0) {

			movy = movy - 0.1;
		}
		else {
			anima22 = false;
			anima1 = true;
		}
	}
	if (anima3) {
		if (movx2 < 10) {
			movx2 = movx2 + 0.1;

		}
		else {
			anima3 = false;
			anima32 = true;
		}
	}
	if (anima32) {
		if (movy2 < 20) {
			movy2 = movy2 + 0.1;
		}
		else
		{
			anima32 = false;
			anima4 = true;
			giro = 180;
			undi = 6;
		}
	}
	if (anima4) {
		if (movx2 > 0) {
			movx2 = movx2 - 0.1;
		}
		else
		{
			anima4 = false;
			anima42 = true;
		}
	}
	if (anima42) {
		if (movy2 > 0) {

			movy2 = movy2 - 0.1;
		}
		else {

			giro = 0;
			undi = 0;
			anima42 = false;
			anima3 = true;
		}
	}
	if (anima5) {
		if (movy3 < 50) {
			movy3 = movy3 + 0.1;
		}
		else
		{
			anima5 = false;
			anima52 = true;
		}
	}
	if (anima52) {
		if (movy3 > 0) {

			movy3 = movy3 - 0.1;
		}
		else {

			anima52 = false;
			anima5 = true;
		}

	}
	if (anima6) {
		giro2 = giro2 + 5;
		anima7 = false;

	}
	if (anima62) {
		anima6 = false;
	}
	if (anima7) {
		anima62 = false;
		anima6 = true;
	}


	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 'v':
	case 'V':
		anima5 = true;
		break;

	case 'b':
	case 'B':
		anima1 = true;

		break;

	case ' ':
		g_fanimacion = true;
		break;

	case 'C':
	case 'c':
		anima3 = true;
		break;


	case 'N':
		anima6 = true;
		break;

	case 'n':
		anima62 = true;
		anima7 = true;
		break;




	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex > 1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


void menu(int id)
{

}



int main(int argc, char** argv)   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 11"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion Monito", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();          // 

	return 0;
}