#include <iostream>
#include <fstream>
#include <string>
#include <map>

const std::string INPUT_FILE = "input";

bool is_valid(int x, int y, std::map<std::string, int> keypad) {
    auto key = std::to_string(x) + std::string(",") + std::to_string(y);
    return keypad.find(key) != keypad.end();
}

int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    /*
     *  x   x   3,0 x   x   
     *  x   1,1 2,1 3,1 x   
     *  0,2 1,2 2,2 3,2 4,2 
     *  x   1,3 2,3 3,3 x   
     *  x   x   2,4 x   x   
     */
    std::map<std::string, int> keypad {
        {"2,0", 1},
        {"1,1", 2},{"2,1", 3},{"3,1", 4},
        {"0,2", 5},{"1,2", 6},{"2,2", 7},{"3,2", 8}, {"4,2", 9},
        {"1,3", 0xA},{"2,3", 0xB},{"3,3", 0xC},
        {"2,4", 0xD}
    };

    int x(0),y(2);
    while (std::getline(inputFile, input)){
        for (auto &ch : input ) {
            switch(ch){
                case 'U': if(is_valid(x,y-1,keypad)) y--; break;
                case 'D': if(is_valid(x,y+1,keypad)) y++; break;
                case 'L': if(is_valid(x-1,y,keypad)) x--; break;
                case 'R': if(is_valid(x+1,y,keypad)) x++; break;
            }
            // auto key = std::to_string(x) + std::string(",") + std::to_string(y);
            // std::cout << key << std::endl;
        }
        auto key = std::to_string(x) + std::string(",") + std::to_string(y);
        // std::cout << key << std::endl;
        std::cout << std::hex << keypad.at(key);
    }
    std::cout << std::endl;
}
