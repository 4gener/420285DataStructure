#include <iostream>

class QueensTable {
private:
    int _n;
    int _answerNum = 0;
    bool **_table;

    bool isLegal(int x, int y);
    void printTable();
public:
    explicit QueensTable(int n);
    void putQueens(int n, int x = 0, int y = 0);

    ~QueensTable();
};


int main() {

    int n;
    std::cout << "Please input the amount of Queens: ";
    std::cin >> n;
    std::cout << std::endl;

    QueensTable table(n);

    table.putQueens(n);

}

void QueensTable::putQueens(int n, int x, int y) {
    if (n == 0) {
        _answerNum++;
        printTable();
        return;
    }

    for (int i = x; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            if (isLegal(i, j)) {
                _table[i][j] = true;
                this->putQueens(n - 1, i, j);
                _table[i][j] = false;
            }
        }
    }
}

void QueensTable::printTable() {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            std::cout << (_table[i][j] ? 'X' : '0') << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool QueensTable::isLegal(int x, int y) {
    for (int i = 0; i < _n; i++) {
        if (_table[x][i] || _table[i][y]) {
            return false;
        }
        if ((x + i < _n) && (y + i < _n)) {
            if (_table[x + i][y + i])
                return false;
        }
        if ((x - i >= 0) && (y - i >= 0)) {
            if (_table[x - i][y - i])
                return false;
        }
        if ((x + i < _n) && (y - i >= 0)) {
            if (_table[x + i][y - i])
                return false;
        }
        if ((x - i >= 0) && (y + i < _n)) {
            if (_table[x - i][y + i])
                return false;
        }
    }

    return true;
}

QueensTable::QueensTable(int n) {
    _n = n;

    _table = new bool *[n];
    for (int i = 0; i < n; i++)
        _table[i] = new bool[n];
}

QueensTable::~QueensTable() {
    delete[](_table);
    if (_answerNum) {
        std::cout << _answerNum << " answers in total";
    }
    else {
        std::cout << "No valid answers";
    }
}

