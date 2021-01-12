#include "painter.h"
#include <iostream>



void PainterOfConsole::drawDelimeter(const std::string& text) const {

    const int outputWidth = 80;

    auto length = text.length() < outputWidth ? (outputWidth - text.length())/2 : 0;
    std::string filler(length, '-');
    std::cout << filler << text << filler << std::endl;
}

void PainterOfConsole::drawText(const std::string& text) const {
    std::cout << text << std::endl;
}

void PainterOfConsole::drawPoint(const Point& location_) const {
    std::cout << "primitive \"Point\" at: (" << location_.x_coord << ", "
        << location_.y_coord << ")" << std::endl;
}

void PainterOfConsole::drawLine(const Point& location_, const Point& end_) const {
    std::cout << "primitive \"line\" at: (" << location_.x_coord << ", " << location_.y_coord
        << ") with end: (" << end_.y_coord << ", " << end_.x_coord << ")" << std::endl;
}

void PainterOfConsole::drawCircle(const Point& location_, const int& radius_) const {
    std::cout << "primitive \"circle\" at: (" << location_.x_coord << ", "
        << location_.y_coord << ") with radius: " << radius_ << std::endl;
}
