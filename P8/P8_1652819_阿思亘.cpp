#include <iostream>
#include <vector>
#include <unordered_map>

struct Edge {
    char start;
    char end;
    int value;

    Edge(char start, char end, int value) : start(start), end(end), value(value) {}

    static bool isSmaller(Edge edge1, Edge edge2) {
        return edge1.value < edge2.value;
    }
};

class Network {
private:
    std::vector<Edge> edges;
    std::unordered_map<char, char> vertices;
public:
    void getEdges();
    void getVertices();
    void generateBST();
    void makeUnion(Edge edge);
    char findAncestor(char vert);
    void print();
};

void Network::getEdges() {
    std::cout << "请输入电网的边的数目：";
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        std::cout << "请输入两个顶点以及边:";
        char start;
        char end;
        int value;
        std::cin >> start >> end >> value;
        edges.emplace_back(Edge(start, end, value));
    }
    std::sort(edges.begin(), edges.end(), Edge::isSmaller);
}

void Network::getVertices() {
    int num;
    std::cout << "请输入顶点的个数:";
    std::cin >> num;
    std::cout << "请依次输入各点的名称:" << std::endl;
    for (int i = 0; i < num; i++) {
        char vert;
        std::cin >> vert;
        vertices[vert] = -1;
    }
}

void Network::generateBST() {
    for (auto &edge:edges) {
        if (findAncestor(edge.end) != findAncestor(edge.start)) {
            makeUnion(edge);
        }
        else
            edge.value = -1;
    }
    std::cout << "最小生成树已经生成！" << std::endl;
}

void Network::makeUnion(Edge edge) {
    vertices[findAncestor(edge.start)] = findAncestor(edge.end);
}

char Network::findAncestor(char vert) {
    if (vertices[vert] < 0) {
        return vert;
    }
    else {
        return findAncestor(vertices[vert]);
    }
}

void Network::print() {
    std::cout << "最小生成树的顶点以及边是:\n\n";
    for (auto &edge:edges) {
        if (edge.value != -1) {
            std::cout << edge.start << "-<" << edge.value << ">->" << edge.end << "    ";
        }
    }
}

int main() {

    Network network;

    std::cout << "**\t\t\t  电网造价模拟系统\t\t\t\t**\n"
              << "==========================================\n"
              << "**\t\t\tA --- 创建电网顶点\t\t\t**\n"
              << "**\t\t\tB --- 添加电网的边\t\t\t**\n"
              << "**\t\t\tC --- 构造最小生成树\t\t\t**\n"
              << "**\t\t\tD --- 显示最小生成树\t\t\t**\n"
              << "**\t\t\tE --- 退出程序\t\t\t\t**\n"
              << "==========================================\n";

    while (1) {

        char command = 'A';
        while (command != 'E') {
            std::cout << "\n请选择操作:";
            std::cin >> command;
            switch (command) {
                case 'A':
                    network.getVertices();
                    break;
                case 'B':
                    network.getEdges();
                    break;
                case 'C':
                    network.generateBST();
                    break;
                case 'D':
                    network.print();
                    break;
                case 'E':
                    std::cout << "已经成功退出!" << std::endl;
                    return 0;
                default:
                    std::cout << "输入错误！请输入有效的操作数!" << std::endl;
                    break;
            }
        }


    }

}

