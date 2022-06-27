#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

const std::string INPUT_FILE = "input";

class Cache {
    public:
    int valid = 0;
    std::vector<int> edges;
    void operator<<(int x) {
        edges.push_back(x);
        if(edges.size() == 3) {
            if (edges[0] + edges[1] > edges[2] && 
               edges[1] + edges[2] > edges[0] &&
               edges[2] + edges[0] > edges[1]) {
                 valid++;
               }
            edges.clear();
        }
    }
};

int main() {
    std::string input;
    std::ifstream inputFile(INPUT_FILE);

    if(!inputFile.is_open()) {
        std::cout << "error opening file 'input'" << std::endl;
        return 1;
    }

    Cache cache1,cache2,cache3;
    auto const triangleRegex = std::regex("^\\s*(\\d+)\\s*(\\d+)\\s*(\\d+)\\s*$");
    std::smatch match;
    while(std::getline(inputFile, input)){
        if(!std::regex_match(input, match, triangleRegex)) {
            std::cout << "input doesn't match: '" << input.c_str() << "'" << std::endl;
            return 1;
        }

        cache1 << std::stoi(match[1].str());
        cache2 << std::stoi(match[2].str());
        cache3 << std::stoi(match[3].str());

    }

    std::cout << (cache1.valid + cache2.valid + cache3.valid) << std::endl;
}
