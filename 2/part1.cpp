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

    int x,y = 0;
    while (std::getline(inputFile, input)){
        for (auto &ch : input ) {
            /*
             * 0,0 1,0 2,0    1 2 3
             * 0,1 1,1 2,1 => 4 5 6  (x+1) + 3(y)
             * 0,2 1,2 2,2    7 8 9
             */
            switch(ch){
                case 'U': y = std::max(0, y-1); break;
                case 'D': y = std::min(2, y+1); break;
                case 'L': x = std::max(0, x-1); break;
                case 'R': x = std::min(2, x+1); break;
            }
        }
        std::cout << (x+1 + 3*y);
    }
    std::cout << std::endl;
}
