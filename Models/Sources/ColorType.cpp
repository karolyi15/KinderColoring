//
// Created by gunther on 22/11/20.
//

#include "../Headers/ColorType.h"


char * ColorType::getHexColor(Color color) {

    switch (color) {

        case Color::DEFAULT:
            return "#f2f2f2";

        case Color::AMBER:
            return "#FFBF00";

        case Color::BRICK_RED:
            return "#CB4154";

        case Color::BLUE:
            return "#124a68";

        case Color::BROWN:
            return "#A52A2A";

        case Color::DARK_CYAN:
            return "#008B8B";

        case Color::GREEN:
            return "#066425";

        case Color::ORANGE:
            return "#ec7b0a";

        case Color::PURPLE:
            return "#9f08ba";

        case Color::RASPBERRY:
            return "#E30B5C";

        case Color::RED:
            return "#cd2121";

        case Color::YELLOW:
            return "#f4b22d";

    }
}

Color ColorType::getPosition(int position) {

    switch (position) {
        case 0:
            return Color::AMBER;
        case 1:
            return Color::BRICK_RED;
        case 2:
            return Color::BLUE;
        case 3:
            return Color::BROWN;
        case 4:
            return Color::DARK_CYAN;
        case 5:
            return Color::GREEN;
        case 6:
            return Color::ORANGE;
        case 7:
            return Color::PURPLE;
        case 8:
            return Color::RASPBERRY;
        case 9:
            return Color::RED;
        case 10:
            return Color::YELLOW;
    }
}