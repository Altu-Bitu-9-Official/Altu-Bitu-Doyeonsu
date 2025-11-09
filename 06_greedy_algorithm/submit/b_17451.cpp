// 평행 우주
#include <iostream>
#include <vector>

// 뒤에서부터 같거나 크게 배수가 되도록 올리기

using namespace std;

// num 이상이고 factor의 배수여야 함
long larger_or_same_multiple(int factor, long num){
    // 리턴 표현 방법

    // 200 300
    if(num <= factor){
        return factor; 
    }

    // 1200 200
    else if(num % factor == 0){
        return num;
    }
    
    // 1100 300
    return factor * (num / factor + 1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long min_vel = 1l;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // 감소 표현
    for(int i = n - 1; i >= 0; i--){
        min_vel = larger_or_same_multiple(v[i], min_vel);
        //min_vel = larger_or_same_multiple(v[i], min_vel);
        //cout << i << " " << min_vel << "\n";
    }

    cout << min_vel << "\n";
    return 0;
}