#include <iostream>
#include <deque>

using namespace std;
int main(){
    int n;
    deque<int> d;
    cin >> n;

    for (int i = n; i > 0; i--){
        d.push_front(i);
    }

    while(d.size() > 1){
        d.pop_front();
        int x = d.front();
        d.pop_front();
        d.push_back(x);
    }

    cout << d.front();
}