#include "glbox.h"

#include <QTimerEvent>

GLBox::GLBox(QWidget *parent) :
    QGLWidget (QGLFormat(QGL::SampleBuffers), parent),
    xRotation(0),
    yRotation(0),
    zRotation(0),
    timerUpdate(new QBasicTimer())
{
    timerUpdate->start(33, this);
}

void GLBox::setRotation(double x, double y, double z)
{
    xRotation = static_cast<int>(x * 16);
    yRotation = static_cast<int>(y * 16);
    zRotation = static_cast<int>(z * 16);
}

void GLBox::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = {0, 0, 10, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GLBox::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void GLBox::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRotation / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRotation / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRotation / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void GLBox::draw()
{
    qglColor(Qt::red);
    glBegin(GL_QUADS);
        glNormal3f(0,0,-1);
        glVertex3f(-1,-1,0);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);

    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,-1,0.707);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(1,0, 0.707);
        glVertex3f(1,-1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(0,1,0.707);
        glVertex3f(1,1,0);
        glVertex3f(-1,1,0);
        glVertex3f(0,0,1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
        glNormal3f(-1,0,0.707);
        glVertex3f(-1,1,0);
        glVertex3f(-1,-1,0);
        glVertex3f(0,0,1.2);
        glEnd();
}

void GLBox::timerEvent(QTimerEvent *event)
{
    if (timerUpdate->timerId() == event->timerId()) {
        updateGL();
    } else
        QObject::timerEvent(event);
}
