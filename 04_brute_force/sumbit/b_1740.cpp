#include <iostream>
#include <vector>
using namespace std;

// 문풀 : 12 : 45
// 풀완 : 1 : 35

// {0, 1, 2, 3, ...}
// 3^n + 3^(n-1) + .. + 1 = (3^(n+1) - 1 ) / 2 
// (0, 0, 1), (0, 1, 0), (0, 1, 1), (1, 0, 0)... 
//  

long long power(int a){
    long long mul = 1ll;
    for(int i = 0; i < a ; i++){
        mul *= 3;
    }
    return mul;
}

void bit_mask(vector<int> &v, long long a){
    // bit 자릿수에 맞게 3의 power해서 더하기
    long long sum = 0;
    long long bit_masker = 1ll;
    for(int i = 0; bit_masker <= a; i++){
        if(a & bit_masker == 1){
            v[i] = 1;
            sum += power(i);
        }
        else{
            v[i] = 0;
        }
        //cout << v[i] << " " << sum << "\n";
        a >>= 1;
        //cout << bit_masker << " ";
    }
    cout << sum << "\n";
}

int main(){
    long long n = 1;
    int MAX = 60; 
    long long MAX_N = 500000000000;
    
    vector<int> v(MAX);
    //cout << power(3);
    // 18 = 10010
    // 19 = 10011
    // 4 = 100
    cin >> n;
    bit_mask(v, n);
 
    // for(int i = 0; i < MAX; i++){
    //     n *= 3;  
    // }
    // cout << (3 * n - 1) / 2 << "\n";
    // for(int i = 10; i < 1000000; i++){
    //     long long n = 1;
    //     cout << i;
    //     for(int j = 0; j < i; j++){
    //         n *= 3;  
    //     }
        
    //     if((3 * n - 1) / 2 > MAX_N){
    //         cout << " false\n";
    //         return 1;
    //     }
    //     cout << "true\n";
    // }
    return 0;
}