//
// Created by gunther on 22/11/20.
//

#ifndef KINDERCOLORING_COLORTYPE_H
#define KINDERCOLORING_COLORTYPE_H

enum class Color{

    DEFAULT,
    AMBER,
    BRICK_RED,
    BLUE,
    BROWN,
    DARK_CYAN,
    GREEN,
    ORANGE,
    PURPLE,
    RASPBERRY,
    RED,
    YELLOW,
};

class ColorType {

public:

    static char* getHexColor(Color color);
    static Color getPosition(int position);
};


#endif //KINDERCOLORING_COLORTYPE_H
