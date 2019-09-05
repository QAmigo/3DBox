#ifndef QAMIGOPLUGIN_3DBOX_H
#define QAMIGOPLUGIN_3DBOX_H

#include "tabplugininterface.h"
#include "glbox.h"

#include <QVBoxLayout>

class QAmigoPlugin_3DBox : public TabPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.UESTC.SongQiang.TabPluginInterface" FILE "3DBox.json")
    Q_INTERFACES(TabPluginInterface)
public:
    QAmigoPlugin_3DBox();
    QString getName() const override;

public:
    QLayout *getLayout() override;
    void onFrameUpdated(int id, QList<double> listValues) override;
    void setConnection(QIODevice *connection) override;

private:
    QVBoxLayout *layout;
    QIODevice *connection;
    GLBox *glBox;
};

#endif // QAMIGOPLUGIN_3DBOX_H
