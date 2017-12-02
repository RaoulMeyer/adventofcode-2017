#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>

std::string read_input() {
    std::ifstream t("input");
    std::stringstream buffer;
    buffer << t.rdbuf();

    return buffer.str();
}

int main() {
    std::string input = read_input();

    const std::vector<char> chars(input.begin(), input.end());

    int sum = 0;
    for (int i = 0; i < chars.size(); i++) {
        if (chars.at((i + chars.size() / 2) % chars.size()) == chars.at(i)) {
            sum += chars.at(i) - '0';
        }
    }

    std::cout << sum << std::endl;

    return 0;
}