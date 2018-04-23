#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "globalincludes.h"
#include "ray.h"
#include "camera.h"
#include "scene.h"
#include "shape.h"
#include "sphere.h"
#include "squareplane.h"
#include "intersection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Vars
    camera cam;
    Scene scene;
    sphere ball,ball2;
    SquarePlane plane;
    primitive objects;

    void saveImage();
    void raycast();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
