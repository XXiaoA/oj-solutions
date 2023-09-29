#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 孩子：父亲
unordered_map<string, string> fa;

string find_f(const string &x) {
    return x == fa[x] ? x : fa[x] = find_f(fa[x]);
}

int main() {
    char operater;
    string father, children;
    while (cin >> operater && operater != '$') {
        switch (operater) {
        case '#':
            cin >> father;
            // 注意初始化
            if (fa[father].empty())
                fa[father] = father;
            break;
        case '+':
            cin >> children;
            fa[children] = father;
            break;
        case '?':
            cin >> children;
            cout << children << " " << find_f(children) << endl;
            break;
        }
    }

    return 0;
}
