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
    std::string number;
    std::vector<std::string> lines;
    int checksum = 0;

    while(std::getline(input_stream, line, '\n')) {
        std::stringstream line_stream(line);
        std::vector<int> numbers;

        while (std::getline(line_stream, number, '\t')) {
            numbers.push_back(std::stoi(number));
        }

        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers.at(i) % numbers.at(j) == 0) {
                    checksum += numbers.at(i) / numbers.at(j);
                } else if (numbers.at(j) % numbers.at(i) == 0) {
                    checksum += numbers.at(j) / numbers.at(i);
                }
            }
        }
    }

    std::cout << checksum << std::endl;

    return 0;
}