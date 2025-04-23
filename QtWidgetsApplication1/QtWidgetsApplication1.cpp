#include "QtWidgetsApplication1.h"
#include<iostream>
#include <QFile>
#include <QTextStream>
#include "GcodeWriter.h"



QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton_Gcode, SIGNAL(clicked()), this, SLOT(on_pushButton_Gcode_clicked()));

}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::on_pushButton_Gcode_clicked()
{
    // Get the text from QLineEdit
   

   float H = ui.lineEdit_H->text().toFloat();
   float W = ui.lineEdit_W->text().toFloat();
   float F = ui.lineEdit_F->text().toFloat();
   int N = ui.lineEdit_N->text().toInt();
    

   GcodeWriter::writeGcodeFile(H,W,F,N);

    
}