#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("input");
    std::stringstream input_stream;

    input_stream << file.rdbuf();

    std::string line;
    std::string number_string;
    std::vector<std::string> lines;
    int checksum = 0;

    while(std::getline(input_stream, line, '\n')) {
        std::stringstream line_stream(line);
        int min = 100000;
        int max = 0;

        while (std::getline(line_stream, number_string, '\t')) {
            int number = std::stoi(number_string);

            if (number < min) {
                min = number;
            }

            if (number > max) {
                max = number;
            }
        }

        int difference = max - min;
        checksum += difference;
    }

    std::cout << checksum << std::endl;

    return 0;
}