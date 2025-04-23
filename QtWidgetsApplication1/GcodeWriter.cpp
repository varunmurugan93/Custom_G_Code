#include "GcodeWriter.h"
#include <QFile>
#include <QTextStream>
#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include<cmath>


static int count;


std::vector<std::vector<double>> readPaths(const std::string& filename) {
    std::vector<std::vector<double>> matrix;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> row;
        double value;
        while (ss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    return matrix;
}

std::vector<std::vector<int>> readIndices(const std::string& filename) {
    std::vector<std::vector<int>> matrix;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        double value;
        while (ss >> value) {
            row.push_back(value-1);
        }
        matrix.push_back(row);
    }

    return matrix;
}

void lineflushing(std::ofstream& f, std::ostringstream& line)
{
    line.str("");
}

void writeCount(std::ofstream& f, std::ostringstream& line)
{
    line << "N" << count;
}

void newline(std::ofstream& f, std::ostringstream& line)
{
    if (f.is_open()) {
        f << "\n";  // Write a newline
        lineflushing(f, line);
    }
    count += 2;
}

void writeLine(std::ofstream& f, std::ostringstream& line,
    double x, double y, double z,
    int& rotA, int& rotB, int& rotC,
    double& F
 )
{
    line<< " X" << std::fixed << std::setprecision(3) << x
        << " Y" << y
        << " Z" << z
        << " A" << std::setprecision(1) << rotA
        << " B" << rotB
        << " C" << rotC
        << " ELX" << std::setprecision(3) << 0.0
        << " F" << F;
    //f << line.str();
    
}

void writeRetraction(std::ofstream& f, std::ostringstream& line,
                    double x, double y, double z, 
                    int& rota, int& rotb, int& rotc,
                    double& E,
                    double& F
                    )
{
    writeLine(f, line, x, y, z+0.5, rota, rotb, rotc, F);
    line << " E=" << E - 0.2
        << "; Retract";
    f << line.str();
    newline(f, line);
    writeCount(f, line);
    writeLine(f, line, x, y, z + 10.5, rota, rotb, rotc, F);
    line <<"; Departure";
    f << line.str();
    newline(f, line);
    writeCount(f, line);
    writeLine(f, line, x, y, z + 10.5, rota, rotb, rotc, F);
    line << " E " << E - 0.5
        << "; Retract";

}

void writeEngage(std::ofstream& f, std::ostringstream& line,
    double x, double y, double z,
    int& rota, int& rotb, int& rotc,
    double& E,
    double& F
)
{
    
    writeLine(f, line, x, y, z + 10.5, rota, rotb, rotc, F);
    line << "; Apporach";
    f << line.str();
    newline(f, line);
    writeCount(f, line);
    writeLine(f, line, x, y, z, rota, rotb, rotc, F);
    line << " E "<<E+1.2
        << "; Engage";

}

void GcodeWriter::writeGcodeFile(float h, float w, float F, int Nl)
{   
    count = 34;
    std::cout << "Generating G-code with:\n"
        << "Height: " << h << ", "
        << "Width: " << w << ", "
        << "Speed: " << F << ", "
        << "Layers: " << Nl << ", "
        << std::endl;
    int rota = 0; int rotb = 0, rotc = 25, elx = 0; 
    double N1t = 1500, N2t1 = 800, N2t2 = 1500, N3t1 = 100, N3t2 = 1000, Np = 1348, ExN = 100;
    double purge = 3;
    double unRet = 1.2;
    double h1 = 1;
    h = h1 - 0.003;
    w = 6;
    Nl = 3;
    double A = w * h1;
    double FlMul = 1.6992728;
    
    std::string filenamePaths = "paths1.txt";
    std::vector<std::vector<double>> xyz = readPaths(filenamePaths);

    std::string filenameIndices = "indices1.txt";
    std::vector<std::vector<int>> indices = readIndices(filenameIndices);
    
    std::ifstream prefix("prefix_normal.mpf");           // Open source file
    std::ofstream destination("output.mpf");
    destination << prefix.rdbuf();
    prefix.close();
    destination.close();

    std::ofstream file("output.mpf", std::ios::app);//
    if (file.is_open()) {
        std::ostringstream line;
        writeCount(file, line);
        line<< " G17 G94 G90 CP";
        writeLine(file, line, xyz[0][0], xyz[0][1], h + 50, rota, rotb, rotc, N1t);
        
        line<< " E=" << 0.0
            << "; RAPID";
        file << line.str();        
        newline(file,line);
        
        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h + 50, rota, rotb, rotc, N1t);            
        file << line.str();
        newline(file, line);
         
        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h + 5, rota, rotb, rotc, N1t);         
        line<< "; Move to lowest height"; 
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h, rota, rotb, rotc, N1t);
        line <<" F"<<N3t1;
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h, rota, rotb, rotc, N1t);
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " SETAL(67017); Confirm Z-height is OK. Continue with OK and Cycle start on the MCP.";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " M0";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h+10, rota, rotb, rotc, N1t);
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " PRESETON(E,0)";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " G1 E=" << purge<<" F"<<ExN<<"; Purging";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " PRESETON(E,0)";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " G1 F"<<N3t1;
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        writeLine(file, line, xyz[0][0], xyz[0][1], h, rota, rotb, rotc, N1t);
        line << "E=" << unRet
            << ";Engage";
        file << line.str();
        newline(file, line);

        line << ";Start of toolpath";
        file << line.str();
        newline(file, line);

        double Eend = unRet;
        double Vol = 0;
        double v = 0;

         // ---------- Step 3: Write output.gcode ----------
        for (int k = 0; k < Nl; k++) {

            for (size_t i = 0; i < size(indices[0]); ++i) {
                 //outFile << "Path " << i + 1 << ":\n";
                 int start = indices[0][i];
                 int end = indices[1][i];
           
                 for (int j = start+1; j <=end; ++j) {
                     const auto& point = xyz[j];
                     writeCount(file, line);
                 
                     Vol = A*std::sqrt(std::pow(xyz[j][0] - xyz[j - 1][0], 2) + std::pow(xyz[j][1] - xyz[j - 1][1], 2))/1000;
                     v = Eend + Vol;
                     writeLine(file, line, point[0], point[1], h+(h1*k), rota, rotb, rotc, Np);
                     line << " E=" << v;
                     file << line.str();
                     newline(file, line);
                     Eend = v;
                 }

                 int ind = (i == size(indices[0]) - 1) ? 0 : (i + 1);

                 float mag = std::sqrt(std::pow(xyz[end][0] - xyz[indices[0][ind]][0], 2) + std::pow(xyz[end][1] - xyz[indices[0][ind]][1], 2));
                 if (mag>0)
                 {
                     writeCount(file, line);
                     writeRetraction(file, line, xyz[end][0], xyz[end][1], h + (h1 * k), rota, rotb, rotc, Eend, N2t2);
                     file << line.str();
                     newline(file, line);
                     Eend = Eend - 0.5;

                     if (k != Nl-1) {
                         writeCount(file, line);
                         writeEngage(file, line, xyz[indices[0][ind]][0], xyz[indices[0][ind]][1], h + (h1 * k), rota, rotb, rotc, Eend, N2t2);
                         file << line.str();
                         newline(file, line);
                         Eend = Eend + unRet;
                     }
                        

                 }
             
             
            }
  
        }

        writeCount(file, line);
        line << " STOPRE";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " PRESETON(E,0); Reset Axis Value";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " M375; Terminate gear pump pressure";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " M370; Heaters Off";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " M376; Printbed Off";
        file << line.str();
        newline(file, line);

        writeCount(file, line);
        line << " M2";
        file << line.str();
        newline(file, line);

        file.close();
    }
}