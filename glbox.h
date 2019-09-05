#ifndef GLBOX_H
#define GLBOX_H

#include <QBasicTimer>
#include <QGLWidget>

class GLBox : public QGLWidget
{
public:
    GLBox(QWidget *parent);

    void setRotation(double x, double y, double z);

    // QGLWidget interface
protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;

private:
    void draw();
    void normalizeAngle(int &angle);

private:
    int xRotation;
    int yRotation;
    int zRotation;
    QBasicTimer *timerUpdate;
};

#endif // GLBOX_H
