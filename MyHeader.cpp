#include "MyHeader.h"

MyButton::MyButton(QWidget *parent): QPushButton(parent)
{

}
MyButton::~MyButton(){

}

void MyButton::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::RightButton){
        emit rightClick();
    }
    QPushButton::mousePressEvent(e);
}
