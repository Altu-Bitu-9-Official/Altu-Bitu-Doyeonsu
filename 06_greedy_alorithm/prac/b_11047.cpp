#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    int counts = 0;
    

    cin >> N >> K;
    vector<int> v(N);

    for(int i = 0 ; i < N; i++){
        cin >> v[i];
    }
    // 입력 받기

    /*
    N = 10;
    K = 4200;

    vector<int> v = {
        1,
        5, 
        10, 
        50,
        100,
        500,
        1000,
        5000,
        10000,
        50000
    };
    */


    int largest_unit = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > K){
            largest_unit = i - 1;
            break;
        }
        if(i == v.size() - 1){
            largest_unit = i;
        }
    }
    
    for(int i = largest_unit; i >= 0; i--){
        // 단위 v[i] 몇 개 필요한지
        int num = (int) (K / v[i]);
        //cout << "단위, 개수: " << v[i] << ", " << num << "\n";
        
        // 남은 금액
        K -= v[i] * num;
        //cout << "잔액: " << K << "\n\n";

        counts += num;
        if(K == 0) break;
    }
    cout << counts << "\n";
    return 0;
}