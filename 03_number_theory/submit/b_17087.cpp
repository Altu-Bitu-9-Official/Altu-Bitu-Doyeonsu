#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N, S;
    int loc;
    cin >> N;
    cin >> S;

    vector<int> v;

    while(N--){
        cin >> loc;
        v.push_back(abs(S - loc));
        //cout << abs(S - loc) << " ";
    }
    
    int vector_gcd = gcd(v[0], v[1]);

    for(int i = 1; i < v.size(); i++){
        vector_gcd = gcd(vector_gcd, v[i]);
    }
    cout << vector_gcd << "\n";
    return 0;
}