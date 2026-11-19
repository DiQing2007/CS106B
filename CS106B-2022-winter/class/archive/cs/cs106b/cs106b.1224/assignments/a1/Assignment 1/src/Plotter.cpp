#include "Plotter.h"
#include "strlib.h"
using namespace std;
void moveAbs(double &x, double &y, const Vector<string> &command, bool penIsDown, PenStyle info);
void moveRel(double &x, double &y, const Vector<string> &command, bool penIsDown, PenStyle info);
void penColor(string color, PenStyle &info);
void penWidth(double width, PenStyle &info);
void runPlotterScript(istream& input) {
    double x = 0;
    double y = 0;
    bool penIsDown = false;
    PenStyle info = {1.0, "black"};
    //enum class fName{
    //    penDown,
    //    penUp,
    //    moveAbs,
    //    moveRel,
    //    penColor,
    //    penWidth
    //
    //};

    for(string line; getline(input, line); ) {
        line = toLowerCase(line);
        Vector<string> command = stringSplit(line, " ");

        if(command[0] == "pendown") {
            penIsDown = true;
        }
        else if(command[0] == "penup") {
            penIsDown = false;
        }
        else if(command[0] == "moveabs") {
            moveAbs(x, y, command, penIsDown, info);
        }
        else if(command[0] == "moverel") {
            moveRel(x, y, command, penIsDown, info);
        }
        else if(command[0] == "pencolor") {
            penColor(command[1], info);
        }
        else if(command[0] == "penwidth") {
            penWidth(stringToReal(command[1]), info);
        }
        else {
            error("invaild commadn");
        }
    }
    return;
}

void moveAbs(double &x, double &y, const Vector<string> &command, bool penIsDown, PenStyle info) {
    double x1 = stringToReal(command[1]);
    double y1 = stringToReal(command[2]);
    if(penIsDown) {
    drawLine(x, y, x1, y1, info);
    }
    x = x1;
    y = y1;
    return;
}

void moveRel(double &x, double &y, const Vector<string> &command, bool penIsDown, PenStyle info) {
    double x1 = stringToReal(command[1]);
    double y1 = stringToReal(command[2]);
    if(penIsDown) {
    drawLine(x, y, x + x1, y + y1, info);
    }
    x += x1;
    y += y1;
    return;
}

void penColor(string color, PenStyle &info) {
    info.color = color;
    return;
}

void penWidth(double width, PenStyle &info) {
    info.width = width;
    return;
}