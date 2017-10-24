#include <iostream>
#include "LoopLinkList.h"

int main() {
    int M, N, S, K;
    std::cout << "Please input the number of the tourists: ";
    std::cin >> N;
    while (1) {
        std::cout << "Please input the starting position: ";
        std::cin >> S;
        if (S > N)
            std::cout << "Invalid position.\n";
        else
            break;
    }
    std::cout << "Please input the specified number of people are skipped: ";
    std::cin >> M;
    std::cout << "Please input the specified number of people left: ";
    std::cin >> K;

    auto circle = LoopLinkList<int>(N, S, M, K);
    circle.eliminateByGap();

}