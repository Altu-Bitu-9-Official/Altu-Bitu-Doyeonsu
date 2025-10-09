#include <iostream>
#include <vector>
// 문풀 : 12 : 20
// 풀완 : 12 : 45
using namespace std;

// X 보다 크면
// 반으로 자르고
// 방금 자른 반 빼고 합이 목표와 같거나 크면 버리기

// 32 
// 16 16
// 16 8 
// 16 4 4
// 16 4 2 2
// 16 4 2 1 

// 남은 막대 합
int sum(vector<int> &v){
    int sum = 0;
    for(auto e : v){
        sum += e;
    }
    return sum;
}

void print_arr(vector<int> &v){
    for(auto e : v){
        cout << e << " ";
    }
    cout << "\n";
}

int divide(int X){
    const int LEN_64 = 64;
    vector<int> v;
    v.push_back(LEN_64);
    while(sum(v) != X){
        int end = v[v.size() - 1];
        v.pop_back();
        v.push_back(end / 2);
        v.push_back(end / 2);
        if(sum(v) - v.back() >= X ){
            v.pop_back();
        }
    }
    return v.size();
}
int main(){
    int X;
    cin >> X;
    
    cout << divide(X) << "\n";

    
    return 0;
}