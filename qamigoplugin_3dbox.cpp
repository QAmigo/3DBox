#include "qamigoplugin_3dbox.h"

QAmigoPlugin_3DBox::QAmigoPlugin_3DBox() :
    layout(new QVBoxLayout()),
    glBox(new GLBox(this))
{
    layout->addWidget(glBox);
}

QString QAmigoPlugin_3DBox::getName() const
{
    return tr("3D Box");
}

QLayout *QAmigoPlugin_3DBox::getLayout()
{
    return layout;
}

void QAmigoPlugin_3DBox::onFrameUpdated(int id, QList<double> listValues)
{
    if (id == 0) {
        double x = listValues.at(0) / 32768 * 180;
        double y = listValues.at(1) / 32768 * 180;
        double z = listValues.at(2) / 32768 * 180;
        glBox->setRotation(x, y, z);
    }
}

void QAmigoPlugin_3DBox::setConnection(QIODevice *connection)
{
    this->connection = connection;
}
