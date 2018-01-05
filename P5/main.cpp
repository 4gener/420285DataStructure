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
                  << "单词\"" << word.first << "\"出现了" << word.second.size() << "次" << std::endl
                  << "位置是：" << std::endl;

        int rowNum = 1;
        std::vector<int> colNumAll;

        for (auto &pos:word.second) {
            if (rowNum != pos.first && colNumAll.size() != 0) {
                std::cout << colNumAll.size() << "次在第" << rowNum << "排: ";
                for (auto &colNum:colNumAll) {
                    std::cout << colNum << " ";
                }
                std::cout << std::endl;
                colNumAll.clear();
            }
            rowNum = pos.first;
            colNumAll.push_back(pos.second);
        }

        std::cout << colNumAll.size() << "次在第" << rowNum << "排: ";
        for (auto &colNum:colNumAll) {
            std::cout << colNum << " ";
        }
        std::cout << std::endl;

    }
}

int main() {
    std::cout << "请输入文件名(\".txt\" 排除在外): ";
    std::string fileName;
    std::cin >> fileName;
    std::map<std::string, std::vector<std::pair<int, int> >> infoMap;

    std::ifstream infile;
    infile.open("../" + fileName + ".txt");

    readFile(infile, infoMap);
    infile.close();

    printCount(infoMap);
}