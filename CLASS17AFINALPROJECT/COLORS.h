#ifndef COLORS_H
#define COLORS_H

#include <map>
#include <string>
#include <iostream>

struct ColorMap {
    std::map<int, std::string> colorMap;

    ColorMap() {
        colorMap[1] = "Red";
        colorMap[2] = "Blue";
        colorMap[3] = "Green";
        colorMap[4] = "Yellow";
        colorMap[5] = "Purple";
        colorMap[6] = "Orange";
        colorMap[7] = "Pink";
        colorMap[8] = "Cyan";
        colorMap[9] = "Magenta";
        colorMap[10] = "Brown";
    }

    std::string getColor(int number) {
        auto it = colorMap.find(number);
        if (it != colorMap.end()) {
            return it->second;
        } else {
            return "Unknown";
        }
    }
};

#endif // COLORS_H

