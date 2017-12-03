#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

int main() {
    std::ifstream file("input");
    std::stringstream input_stream;
    input_stream << file.rdbuf();

    int input = std::stoi(input_stream.str());

    int square_size = std::ceil(std::sqrt(input));

    if (square_size % 2 == 0) {
        square_size++;
    }

    int distance_to_row = square_size / 2;
    int distance_from_start = (input - 1) % (square_size - 1);
    int distance_in_row = std::abs(square_size / 2 - distance_from_start);
    int total_distance = distance_to_row + distance_in_row;

    std::cout << total_distance << std::endl;

    return 0;
}