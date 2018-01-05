#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int> > weights;
    int count, weight, sum;

    std::cout << "请输入木材的数量：";
    std::cin >> count;
    std::cout << "请依次输入每块木料的长度：";

    for (int i = 0; i < count; i++) {
        std::cin >> weight;
        weights.push(weight);
    }


    while (1) {
        int num1 = weights.top();
        weights.pop();

        if (weights.empty())
            break;

        int num2 = weights.top();
        weights.pop();

        sum += num1;
        sum += num2;

        weights.push(num1 + num2);
    }

    std::cout << "最低消费是：" << sum;

    return 0;
}