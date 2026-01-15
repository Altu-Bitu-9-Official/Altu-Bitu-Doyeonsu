#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000000


void primes(vector<bool> &arr){
    for(int i = 2; i * i <= MAX; i++){
        if(arr[i]){
            for(long long j = 1LL * i * i; j <= MAX; j += i){
                arr[j] = false;
            }
        }
    }
}

void check_sum(int n, vector<bool> &primes){
    for(int i = 2; i <= n / 2 ; i++){
        if(primes[i]){
            if(primes[n - i]){
                cout << n << " = " << i << " + " << n-i << "\n"; 
                return; 
            }
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 에라토스테네스의 체로 미리 소수 다 적어두기
    vector<bool> v(MAX + 1, true);
    v[0] = v[1] = false;
    primes(v);


    int n;
    while(cin >> n && n != 0){
        check_sum(n, v);
    } 

    return 0;
}