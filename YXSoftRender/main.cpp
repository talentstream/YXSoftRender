#include "YXSoftRender.h"
#include<QtWidgets>
#include <QtWidgets/QApplication>

#include"Renderer.h"
#include"RenderThread.h"
#include"Configuration.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YXSoftRender w;
    w.show();

    RenderThread* rt = new RenderThread(&a);
    rt->Run();

    return a.exec();
}
