#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int> > weights;
    int count, weight, sum;

    std::cout << "Please input the number of wood pieces: ";
    std::cin >> count;
    std::cout << "Please input the length of each wood piece one by one: ";

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

    std::cout << "The lowest cost is: " << sum;

    return 0;
}