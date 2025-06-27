#include <bits/stdc++.h>
using namespace std;


#define ll long long
const int SIZE = 100;

signed main(void) {
    system("g++ gen.cpp -O2 -o gen.exe");
    system("g++ sol.cpp -O2 -o sol.exe");
    
    system("mkdir tests");
    for (int i = 1; i <= SIZE; ++i) {
        string num = to_string(i);
        string input = "tests/" + num + ".inp";
        string output = "tests/" + num + ".out";

        system(("gen.exe > " + input).c_str());
        system(("sol.exe < " + input + " > " + output).c_str());

        cout << "Da tao den test " << i << endl;
    }
    cout << "Hoan thanh";
    return 0;
}
