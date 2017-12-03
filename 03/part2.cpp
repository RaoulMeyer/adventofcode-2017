#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

std::map<std::string, int> map;

int get_value(int x, int y) {
    if (x == 0 && y == 0) {
        return 1;
    }

    int sum = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (map.find(std::to_string(i) + " " + std::to_string(j)) != map.end()) {
                sum += map[std::to_string(i) + " " + std::to_string(j)];
            }
        }
    }

    return sum;
}

int main() {
    std::ifstream file("input");
    std::stringstream input_stream;
    input_stream << file.rdbuf();

    int input = std::stoi(input_stream.str());
    int direction = 0;
    int x = 0;
    int y = 0;

    for (int pos = 1; pos <= 1000; pos++) {
        int value = get_value(x, y);
        map.insert(std::make_pair(std::to_string(x) + " " + std::to_string(y), value));

        if (value > input) {
            std::cout << value << std::endl;
            return 0;
        }

        int square_size = std::ceil(std::sqrt(pos));

        if (square_size % 2 == 0) {
            square_size++;
        }

        if (std::abs(x) + std::abs(y) == square_size - 1 && pos != square_size * square_size
                || pos == (square_size - 2) * (square_size - 2) + 1) {
            direction = (direction + 90) % 360;
        }

        switch (direction) {
            case 0:
                x++;
                break;
            case 90:
                y++;
                break;
            case 180:
                x--;
                break;
            case 270:
                y--;
                break;
        }
    }

    std::cout << "Not found!" << std::endl;

    return 0;
}