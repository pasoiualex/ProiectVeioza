#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaJos(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaSpate1(void);
void CALLBACK MutaFata1(void);
void CALLBACK MutaSpate2(void);
void CALLBACK MutaFata2(void);
void CALLBACK rot_z_up(AUX_EVENTREC* event);
void CALLBACK rot_z_down(AUX_EVENTREC* event);

static GLfloat x = 0, y = 0, z = 0;
static int alfa = 0,beta=0;
GLUquadricObj* qobj;

void myinit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// coeficientii de reflexie pentru reflexia ambientala 
	// si cea difuza sunt cei impliciti
	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.5, 0.5, 1.0 };
	/*  rflectanta speculara si exponentul de reflexie speculara
	nu sunt la valorile implicite (0.0)   */
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	// valori implicite pentru intensitatea sursei LIGHT0
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	/*  pozitia sursei nu are valori implicite */
	GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };

	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING); // activare iluminare
	glEnable(GL_LIGHT0);	// activare sursa 0

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}


void CALLBACK MutaStanga(void)
{
	x = x - 10;
}

void CALLBACK MutaDreapta(void)
{
	x = x + 10;
}


void CALLBACK MutaJos(void)
{
	y = y - 10;
}

void CALLBACK MutaSus(void)
{

	y = y + 10;
}
void CALLBACK MutaSpate1(void)
{

	beta = beta - 5;
}
void CALLBACK MutaFata1(void)
{

	beta = beta + 5;
}
void CALLBACK MutaSpate2(void)
{

	z = z - 5;
}
	void CALLBACK MutaFata2(void)
	{

		z = z + 5;
	}

void CALLBACK rot_z_up(AUX_EVENTREC* event)
{
	alfa = (alfa+5)%360;
}

void CALLBACK rot_z_down(AUX_EVENTREC* event)
{
	alfa = (alfa - 5) % 360;
}

void CALLBACK display(void)
{
	
	GLfloat mat_diffuse1[] = { 0.658824, 0.658824, 0.658824, 0.0 };
	GLfloat mat_diffuse2[] = { 0.0, 1.0, 0.0, 0.0 };
	GLfloat mat_diffuse3[] = { 0.6,  0.8, 0.196078, 0.0 };
	GLfloat mat_diffuse4[] = { 0.6, 0.4, 0.12, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	qobj = gluNewQuadric();

	glRotatef(5, 1, 0, 0);
	glRotated(20, 0, 1, 0);
	
	//masa
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glTranslatef(0, -107.5, 0);
	auxSolidBox(250, 15, 100);
	glPopMatrix();

	//picior masa fata stanga
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glTranslatef(-110, -150, 42);
	auxSolidBox(15, 80, 15);
	glPopMatrix();

	//picior masa spate stanga
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glTranslatef(-110, -150, -42);
	auxSolidBox(15, 80, 15);
	glPopMatrix();

	//picior masa fata dreapta
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glTranslatef(110, -150, 42);
	auxSolidBox(15, 80, 15);
	glPopMatrix();

	//picior masa spate dreapta
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glTranslatef(110, -150, -42);
	auxSolidBox(15, 80, 15);
	glPopMatrix();

	
	glTranslatef(0, 0, z);
	glRotatef(beta, 0, 0, 0);
	glRotatef((GLfloat)alfa, 1, 1, 1);

	//CILINDRU DIN CERCURI -  primitive

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	glTranslatef(x, y, z);
	glTranslatef(0, 0, 0);
	glRotatef( - 120, 1, 1, 1);
	//glColor3f(0.6, 0.1961, 0.8);
	gluCylinder(qobj, 58, 30, 90, 60, 20);
	glPopMatrix();

	//PICIOR
	glPushMatrix();
	glTranslatef(x, y, z);
	//glRotatef(0, 1, 1, 1);
	glTranslatef(0, 70, 0);
	glScalef(1, 1, 1);
	//glColor3f(0.64, 0.16, 0.16);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);

	auxSolidCylinder(3, 85);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glTranslatef(x, y - 50, z);
	auxSolidBox(15, 80, 15);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glTranslatef(x-0.3, y - 100, z);
	glRotatef(-90, 1, 0, 0);
	auxSolidCone(30, 20);
	glPopMatrix();


	

	
	auxSwapBuffers();
}




void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-160.0, 160.0, 160.0 * (GLfloat)h / (GLfloat)w,
			-160.0 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
	else
		glOrtho(-160.0 * (GLfloat)w / (GLfloat)h,
			160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{

	auxInitDisplayMode(AUX_DOUBLE | AUX_RGB);
	auxInitPosition(350, 5, 1200, 1000);
	auxInitWindow("Veioza");
	myinit();
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxKeyFunc(AUX_UP, MutaSus);
	auxKeyFunc(AUX_s, MutaSpate1);
	auxKeyFunc(AUX_w, MutaFata1);
	auxKeyFunc(AUX_d, MutaFata2);
	auxKeyFunc(AUX_e, MutaSpate2);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}