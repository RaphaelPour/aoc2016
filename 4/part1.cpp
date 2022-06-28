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

    int sum = 0;
    while(std::getline(inputFile, input)){
        size_t end = 0;
        size_t checksumStart = input.find("[");
        size_t checksumEnd = input.find("]");
        std::string checksum = input.substr(checksumStart+1, checksumEnd - checksumStart - 1);

        size_t sessionIDStart = input.rfind("-");
        size_t sessionIDEnd = checksumStart;
        int sessionID = std::stoi(input.substr(sessionIDStart + 1, sessionIDEnd - sessionIDStart - 1));
        
        size_t pos = 0;
        bool valid = true;
        while((size_t start = input.find_first_not_of("-",end)) != sessionIDStart){
            size_t next = input.find("-", start+1);
            bool found = false
            for(; pos < checksum.size(); pos++ {
                if(input.substr(start, next - start).find(checksum[pos]) != std::string::npos){
                    found = true
                }
            }
            if(!found){
                valid = false;
                break;
            }
        }

        if(valid) {
            sum += sessionID;
        }
    }

    std::cout << sum << std::endl;
}
