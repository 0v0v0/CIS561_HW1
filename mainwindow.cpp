#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
#include "qcolor.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cam.eye_pos = glm::vec3(0, 0, 10);
    //ref = (0, 0, 0)
    cam.world_up = glm::vec3(0, 1, 0);
    cam.FOV = (45.0f/180.0f)*M_PI;
    cam.width = 400;
    cam.height = 400;
    cam.near_clip = 0.1f;
    cam.far_clip = 1000;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveImage()
{
    QImage image(cam.width,cam.height,QImage::Format_ARGB32);

    image.fill(Qt::GlobalColor::black);

    float width,height;

    width=cam.width;
    height=cam.height;

    //Loop all the pixels
    for(int i=0;i<cam.width;i++)
    {
        for(int j=0;j<cam.height;j++)
        {
            Ray pixel_ray;
            pixel_ray.origin=cam.eye_pos;
            //Shoot Rays
            pixel_ray.dir=glm::normalize(glm::vec3( (i - width/2)/width, (j-height/2)/height,-1));
            //Compute Color
            Color3f color=(pixel_ray.dir + glm::vec3(1,1,1)) * 0.5f;
            //Set Color
            image.setPixel(i,j,qRgb(color.x*255,color.y*255,color.z*255));
        }
    }
    //
    std::cout<<"Ready!";
    //save image
    image.save("test.png","PNG",-1);
}

void MainWindow::raycast()
{
    float pi=3.14159f;
    //Init objects
    ball.trans.pos=Vector3f(0,0,1);
    ball.trans.rot=Vector3f(0,0,45*pi/180.0f);
    ball.trans.rot=Vector3f(2,1,1);

    ball2.trans.pos=Vector3f(0,0,1);
    ball2.trans.rot=Vector3f(0,0,45*pi/180.0f);
    ball2.trans.rot=Vector3f(2,1,1);

    plane.trans.pos=Vector3f(0,-0.5,0);
    plane.trans.rot=Vector3f(90*pi/180.0f,0,0);
    plane.trans.scale=Vector3f(5,5,1);
    ball.trans.update_mat();
    plane.trans.update_mat();
    plane.update_vertex();

    scene.cam.push_back(cam);

    QImage image(cam.width,cam.height,QImage::Format_ARGB32);

    image.fill(Qt::GlobalColor::black);

    float width,height;

    width=cam.width;
    height=cam.height;

    //Loop all the pixels
    for(int i=0;i<cam.width;i++)
    {
        for(int j=0;j<cam.height;j++)
        {
            Ray pixel_ray;
            pixel_ray.origin=cam.eye_pos;
            //Shoot Rays
            pixel_ray.dir=glm::normalize(glm::vec3( (i - width/2)/width, (j-height/2)/height,-1));

            intersection intersect;
            Normal3f nor;

            float t=-10000;


//            if(ball.getIntersection(pixel_ray,&intersect))
//            {
//                t=intersect.t;
//                nor=intersect.nor;
//            }

//            //re-init rays
//            pixel_ray.origin=cam.eye_pos;
//            //Shoot Rays
//            pixel_ray.dir=glm::normalize(glm::vec3( (i - width/2)/width, (j-height/2)/height,-1));

//            if(ball2.getIntersection(pixel_ray,&intersect))
//            {
//                t=intersect.t;
//                nor=intersect.nor;
//            }


            //re-init rays
            pixel_ray.origin=cam.eye_pos;
            //Shoot Rays
            pixel_ray.dir=glm::normalize(glm::vec3( (i - width/2)/width, (j-height/2)/height,-1));

            if(plane.getIntersection(pixel_ray,&intersect))
            {
                if(intersect.t>t)
                {
                    t=intersect.t;
                    nor=intersect.nor;
                }
            }

            //Compute Color
            Color3f color=(nor+ glm::vec3(1,1,1)) * 0.5f;
            //Set Color
            image.setPixel(i,j,qRgb(color.x*255,color.y*255,color.z*255));
        }
    }
    //
    std::cout<<"Ready!";
    //save image
    image.save("raycast.png","PNG",-1);
}
