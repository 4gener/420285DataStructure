#include <iostream>
#include "LoopLinkList.h"

int main() {
    int M, N, S, K;
    std::cout << "请输入游客数量：";
    std::cin >> N;
    while (1) {
        std::cout << "请输入起点位置：";
        std::cin >> S;
        if (S > N)
            std::cout << "非法位置\n";
        else
            break;
    }
    std::cout << "请输入死亡数字M：";
    std::cin >> M;
    std::cout << "请输入剩余的生者人数K：";
    std::cin >> K;

    auto circle = LoopLinkList<int>(N, S, M, K);
    circle.eliminateByGap();

}