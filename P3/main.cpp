#include <iostream>
#include <fstream>
#include <stack>

void readMap(char map[][7]);
void printMap(char map[][7]);
void onSuccess(char map[][7]);
void customMap(char map[][7]);

bool dfs(char map[][7], int posX, int posY, std::stack<std::pair<int, int>> &route, bool &isSolvable);

int main() {
    char map[7][7];
    bool toDefault;
    bool isSolvable = false;
    std::stack<std::pair<int, int>> route;

    std::cout << "The map info is contained in 'map.txt'" << std::endl
              << "Press 1 to use this map, 0 to custom one: ";
    std::cin >> toDefault;

    if (toDefault)
        readMap(map);
    else
        customMap(map);

    std::cout << "The map is:" << std::endl;
    printMap(map);

    if (map[0][0] == '0')
        isSolvable = dfs(map, 0, 0, route, isSolvable);

    if (!isSolvable)
        std::cout << "Sorry, this is a dead maze.";

    return 0;
}

bool dfs(char map[][7], int posX, int posY, std::stack<std::pair<int, int>> &route, bool &isSolvable) {
    route.push(std::make_pair(posX, posY));
    map[posX][posY] = 'X';

    if (posX == 6 && posY == 6) {
        onSuccess(map);
        isSolvable = true;
    }

    if (map[posX][posY + 1] == '0')
        dfs(map, posX, posY + 1, route, isSolvable);
    if (map[posX][posY - 1] == '0')
        dfs(map, posX, posY - 1, route, isSolvable);
    if (map[posX + 1][posY] == '0')
        dfs(map, posX + 1, posY, route, isSolvable);
    if (map[posX - 1][posY] == '0')
        dfs(map, posX - 1, posY, route, isSolvable);

    route.pop();
    map[posX][posY] = '0';

    return isSolvable;
}

void readMap(char map[][7]) {
    std::fstream is("../map.txt");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            is >> map[i][j];
        }
        is.ignore(1);
    }
}

void printMap(char map[][7]) {
    std::cout << ' ';
    for (int i = 0; i < 7; i++) {
        std::cout << '\t' << i;
    }
    std::cout << std::endl;

    for (int i = 0; i < 7; i++) {
        std::cout << i;
        for (int j = 0; j < 7; j++) {
            std::cout << '\t' << map[i][j];
        }
        std::cout << std::endl;
    }
}

void onSuccess(char map[][7]) {
    std::cout << "The route is:" << std::endl;
    printMap(map);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (map[i][j] == 'X') {
                std::cout << " <" << i << ", " << j << "> ";
                if (i != 6 || j != 6)
                    std::cout << " --> ";
            }
        }
    }
    std::cout << std::endl;
}

void customMap(char map[][7]) {
    std::cout << "Please input a map of 7X7 using the format as follows:" << std::endl
              << "00#####\n"
              << "#0#000#\n"
              << "#0#0###\n"
              << "#000#0#\n"
              << "#0#000#\n"
              << "#0#0#0#\n"
              << "#####00\n" << std::endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            std::cin >> map[i][j];
        }
        std::cin.ignore(1);
    }
}
