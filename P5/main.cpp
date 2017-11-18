#include <iostream>
#include <fstream>
#include <map>
#include <vector>

void readFile(std::ifstream &infile, std::map<std::string, std::vector<std::pair<int, int> >> &infoMap) {
    for (int row = 1;; row++) {
        for (int col = 1;; col++) {
            std::string temp;
            infile >> temp;
            for (unsigned int i = 0; i < temp.length(); ++i) {
                temp[i] = std::tolower(temp[i]);
            }

            if (infoMap.find(temp) == infoMap.end()) {
                infoMap[temp] = std::vector<std::pair<int, int> >();
            }
            infoMap[temp].push_back(std::make_pair(row, col));

            char sep = infile.get();
            if (sep == '\n') break;
            else if (sep == EOF) return;
        }
    }
}

void printCount(std::map<std::string, std::vector<std::pair<int, int> >> &infoMap) {
    for (auto &word:infoMap) {
        std::cout << std::endl
                  << "The word \"" << word.first << "\" appeared for " << word.second.size() << " times." << std::endl
                  << "The locations are:" << std::endl;

        int rowNum = 1;
        std::vector<int> colNumAll;

        for (auto &pos:word.second) {
            if (rowNum != pos.first && colNumAll.size() != 0) {
                std::cout << colNumAll.size() << " times for row No." << rowNum << ": ";
                for (auto &colNum:colNumAll) {
                    std::cout << colNum << " ";
                }
                std::cout << std::endl;
                colNumAll.clear();
            }
            rowNum = pos.first;
            colNumAll.push_back(pos.second);
        }

        std::cout << colNumAll.size() << " times for row No." << rowNum << ": ";
        for (auto &colNum:colNumAll) {
            std::cout << colNum << " ";
        }
        std::cout << std::endl;

    }
}

int main() {
    std::cout << "Please input the file's name (\".txt\" excluded): ";
    std::string fileName;
    std::cin >> fileName;
    std::map<std::string, std::vector<std::pair<int, int> >> infoMap;

    std::ifstream infile;
    infile.open("../" + fileName + ".txt");

    readFile(infile, infoMap);
    infile.close();

    printCount(infoMap);
}