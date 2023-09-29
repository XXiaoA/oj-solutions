#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;

list<string> playing, waiting;
unordered_map<string, bool> is_playing, is_waiting;
// 用于 leave 操作, 不然会报 TLE
unordered_map<string, list<string>::iterator> waiting_pos;
string name;

void print(const list<string> &queue) {
    for (const auto &user : queue) {
        cout << user << " ";
    }
    cout << endl;
}

void start() {
    if (waiting.empty() && playing.empty()) {
        cout << "Error" << endl;
    } else if (waiting.empty() && !playing.empty()) {
        print(playing);
    } else {
        // 注意 size 不要在循环里用，因为存在 pop 操作
        unsigned size;
        if (!playing.empty()) {
            size = playing.size();
            for (int i = 0; i < size; i++) {
                name = playing.front();
                is_playing[name] = false;
                is_waiting[name] = true;
                playing.pop_front();
                waiting.push_back(name);
                waiting_pos[name] = --waiting.end();
            }
        }
        size = waiting.size();
        // 以防 waiting 人数为 1
        for (int i = 0; i < 2 && i < size; i++) {
            name = waiting.front();
            is_waiting[name] = false;
            is_playing[name] = true;
            waiting.pop_front();
            waiting_pos.erase(name);
            playing.push_back(name);
            cout << name;
            cout << (i == 1 || i == size - 1 ? "\n" : " ");
        }
    }
}

void arrive() {
    cin >> name;
    if (is_waiting[name] || is_playing[name])
        cout << "Error" << endl;
    else {
        is_waiting[name] = true;
        waiting.push_back(name);
        waiting_pos[name] = --waiting.end();
        cout << "OK" << endl;
    }
}

void leave() {
    cin >> name;
    if (is_waiting[name] && !is_playing[name]) {
        is_waiting[name] = false;
        waiting.erase(waiting_pos[name]);
        waiting_pos.erase(name);
        cout << "OK" << endl;
    } else
        cout << "Error" << endl;
}

int main() {
    int n;
    string operate;
    cin >> n;
    while (n--) {
        cin >> operate;
        if (operate == "start")
            start();
        else if (operate == "arrive")
            arrive();
        else if (operate == "leave")
            leave();
        else {
            print(playing);
            print(waiting);
        }
    }

    return 0;
}
