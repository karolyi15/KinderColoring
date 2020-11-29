//
// Created by gunther on 22/11/20.
//

#include "../Headers/ColorType.h"


char * ColorType::getHexColor(Color color) {

    switch (color) {

        case Color::DEFAULT:
            return "#f2f2f2";

        case Color::AMBER:
            return "#FFF700";

        case Color::BRICK_RED:
            return "#FFB6C1";

        case Color::BLUE:
            return "#124A68";

        case Color::BROWN:
            return "#6E4A14";

        case Color::DARK_CYAN:
            return "#008B8B";

        case Color::GREEN:
            return "#04D90B";

        case Color::ORANGE:
            return "#EC730A";

        case Color::PURPLE:
            return "#7B1FA2";

        case Color::RASPBERRY:
            return "#DD9D00";

        case Color::RED:
            return "#DB0909";

        case Color::DARK_GREEN:
            return "#276E01";

    }
}

Color ColorType::getPosition(int position) {

    switch (position) {
        case 0:
            return Color::AMBER;
        case 1:
            return Color::BRICK_RED;
        case 2:
            return Color::DARK_CYAN;
        case 3:
            return Color::BROWN;
        case 4:
            return Color::GREEN;
        case 5:
            return Color::BLUE;
        case 6:
            return Color::ORANGE;
        case 7:
            return Color::PURPLE;
        case 8:
            return Color::RASPBERRY;
        case 9:
            return Color::RED;
        case 10:
            return Color::DARK_GREEN;
    }
}