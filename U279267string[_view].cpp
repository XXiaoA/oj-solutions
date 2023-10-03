#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void read(string &name, string &value) {
    char c;
    while (cin >> c && c != '(')
        name.push_back(c);
    while (cin >> c && c != ')')
        value.push_back(c);
    while (cin >> c && c != ';') {
    }
}

int main() {
    ios::sync_with_stdio(false);
    unsigned n, ans = 0;
    unordered_map<string, string> strs;
    cin >> n;
    while (n--) {
        string type, name, value;
        cin >> type;
        read(name, value);
        if (value[0] == '"')
            strs[name] = value.substr(1, value.size() - 2);
        else
            strs[name] = strs[value];
        // cout << type << " " << name << " " << value << endl;
        if (type == "string") {
            ans += strs[name].size();
        }
    }
    cout << ans << endl;

    return 0;
}
