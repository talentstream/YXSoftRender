#include "YXSoftRender.h"
#include<QtWidgets>
#include <QtWidgets/QApplication>

#include"Renderer.h"
#include"Configuration.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YXSoftRender w;
    w.show();

    Renderer renderer = Renderer();
    renderer.Render();
    renderer.Display();

    return a.exec();
}
