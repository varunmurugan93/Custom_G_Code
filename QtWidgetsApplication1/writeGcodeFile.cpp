#include "GcodeWriter.h"
#include <QFile>
#include <QTextStream>

void GcodeWriter::writeGcodeFile()
{
    QFile file("output.gcode");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "Hello";
        file.close();
    }
}