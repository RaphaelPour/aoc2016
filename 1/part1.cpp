#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>

const std::string INPUT_FILE = "input";
const std::string WHITESPACES = " \n\r\t";
const std::string LEFT = "L";
const std::string RIGHT = "R";

class Orientation {
    public:

    enum Directions{ NORTH, EAST, SOUTH, WEST, COUNT_OF_ELEMENTS};
    int direction = 0;
    Orientation& operator++(int){
        direction++;
        if(direction >= COUNT_OF_ELEMENTS){
            direction = 0;
        }
        return *this;
    }

    Orientation& operator--(int){
        direction--;
        if(direction < 0){
            direction = COUNT_OF_ELEMENTS - 1;
        }
        return *this;
    }

    std::string to_string(Orientation self) {
        static const std::vector<std::string>lookup = {"N","E","S","W"};
        return lookup[self.direction];
    }
};

int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    int x,y = 0;
    Orientation orientation;
    while(std::getline(inputFile, input, ',')){
        size_t start = input.find_first_not_of(WHITESPACES);
        size_t end = input.find_last_not_of(WHITESPACES);
        input = input.substr(start, end - start + 1);
        std::string direction = input.substr(0,1);
        int count = std::stoi(input.substr(1, std::string::npos));

        if(direction == RIGHT){
            orientation++;
        } else {
            orientation--;
        }

        switch(orientation.direction) {
            case Orientation::NORTH: y += count; break;
            case Orientation::SOUTH: y -= count; break;
            case Orientation::EAST: x += count; break;
            case Orientation::WEST: x -= count; break;
            default:
                std::cout << orientation.direction << std::endl;
                return 1;
        }
    }
    std::cout << (std::abs(x)+std::abs(y)) << std::endl;
    inputFile.close();
    return 0;
}
