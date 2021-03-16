#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair (const Pair<T1, T2> &copied){
        first = copied.first;
        second = copied.second;
    }
    Pair () {
    }
    Pair <T1, T2> operator= (const Pair<T1,T2> &copied) {
        first = copied.first;
        second = copied.second;
        return(*this);
    }
};

template<typename T>
void mySort(vector<T>& a) {
    for (int i = 0; i < a.size() -1; i++) {
        for (int j = 0; j < a.size()-i-1; j++) {
            if (a[j].first > a[j+1].first) {
                swap (a[j], a[j+1]);
            }
            if (a[j].first == a[j+1].first && a[j].second > a[j+1].second) {
                swap (a[j], a[j+1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}
