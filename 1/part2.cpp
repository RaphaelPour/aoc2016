#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <map>

const std::string INPUT_FILE("input");
const std::string WHITESPACES(" \n\r\t");
const std::string LEFT("L");
const std::string RIGHT("R");

class Turtle {

    public:

    enum Directions{ NORTH, EAST, SOUTH, WEST, COUNT_OF_ELEMENTS};
    int direction, x, y = 0;
    Turtle& operator++(int){
        direction++;
        if(direction >= COUNT_OF_ELEMENTS){
            direction = 0;
        }
        return *this;
    }

    Turtle& operator--(int){
        direction--;
        if(direction < 0){
            direction = COUNT_OF_ELEMENTS - 1;
        }
        return *this;
    }

    void turn(std::string turn, int steps) {
        (turn == RIGHT) ? this->operator++(0) : this->operator--(0);

        switch(direction) {
            case NORTH: y += count; break;
            case SOUTH: y -= count; break;
            case EAST: x += count; break;
            case WEST: x -= count; break;
        }
    }

    std::string to_string(Turtle self) {
        static const std::vector<std::string>lookup = {"N","E","S","W"};
        return lookup[self.direction];
    }
};

std::string to_key(int x, int y) {
    return std::string("") + std::to_string(x) + "_" + std::to_string(y);
}

template<typename K, typename V>
void dump_map(std::map<K, V> m) {
    for(auto pair: m) {
        std::cout << pair.first << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    bool done;
    int x,y,oldX,oldY = 0;
    Turtle turtle;
    std::map<std::string, bool> positions;
    // positions.insert( std::pair<std::string, bool>(to_key(x,y),true));
    while(!done && std::getline(inputFile, input, ',')){
        size_t start = input.find_first_not_of(WHITESPACES);
        size_t end = input.find_last_not_of(WHITESPACES);
        input = input.substr(start, end - start + 1);
        std::string direction = input.substr(0,1);
        int count = std::stoi(input.substr(1, std::string::npos));

        turtle.turn(direction, count);
    
        /* add all positions between start and end to the map */
        if(oldX != x){
            auto sign = (x-oldX) < 0 ? -1 : 1;
            for(int itX = oldX; !done && itX < x; itX += sign){
                auto key = to_key(itX,y);
                if(positions.find(key) != positions.end()){
                    std::cout << (std::abs(itX)+std::abs(y)) << std::endl;
                    done = true;
                    break;
                }
                positions.insert( std::pair<std::string, bool>(key,true));
            }

        } else {
            auto sign = (y-oldY) < 0 ? -1 : 1;
            for(int itY = oldY; !done && itY < y; itY += sign) {
                auto key = to_key(x,itY);
                if(positions.find(key) != positions.end()){
                    std::cout << (std::abs(x)+std::abs(itY)) << std::endl;
                    done = true;
                    break;
                }
                positions.insert( std::pair<std::string, bool>(key,true));
            }
        }

        oldX = x;
        oldY = y;
    }
    inputFile.close();
    return 0;
}
