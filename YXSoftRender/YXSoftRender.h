#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_YXSoftRender.h"
#include"Renderer.h"

class YXSoftRender : public QMainWindow
{
    Q_OBJECT

public:
    YXSoftRender(QWidget *parent = nullptr);
    ~YXSoftRender();

private:
    Ui::YXSoftRenderClass ui;
};
