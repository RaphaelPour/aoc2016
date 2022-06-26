#include <iostream>
#include <fstream>
#include <string>

const std::string INPUT_FILE = "input";
int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    int valid(0);
    while(std::getline(inputFile, input)){
        std::cout << input << std::endl;
        auto space1 = input.find(" ");
        auto space2 = input.find(" ", space1+1);

        auto aStr = input.substr(0,space1);
        auto a = std::stoi(aStr);

        auto bStr = input.substr(space1, space2 - space1);
        auto b = std::stoi(bStr);

        auto c = std::stoi(input.substr(space2, input.length() - space2));

        if(a+b > c)valid++;
    }
    std::cout << valid << std::endl;
}
