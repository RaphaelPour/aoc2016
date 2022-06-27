#include <iostream>
#include <fstream>
#include <string>
#include <regex>

const std::string INPUT_FILE = "input";
int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    auto const triangleRegex = std::regex("^\\s*(\\d+)\\s*(\\d+)\\s*(\\d+)\\s*$");
    std::smatch match;

    int valid(0);
    while(std::getline(inputFile, input)){
        if(!std::regex_match(input, match, triangleRegex)) {
            std::cout << "input doesn't match: '" << input.c_str() << "'" << std::endl;
            return 1;
        }

        auto a = std::stoi(match[1].str());
        auto b = std::stoi(match[2].str());
        auto c = std::stoi(match[3].str());

        if(a+b > c && a+c > b && c+b > a)valid++;
    }

    std::cout << "too high: 1361" << std::endl;
    std::cout << valid << std::endl;
}
