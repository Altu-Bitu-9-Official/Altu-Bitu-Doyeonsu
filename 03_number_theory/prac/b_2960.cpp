#include <iostream>
#include <vector>
using namespace std;

bool checkEnd(int count, int end){
    if(count == end){
        return true;
    }
    return false; 
}

int main(){
    int count = 0;

    static int N, K;
    cin >> N >> K;
    
    // TEST
    //N = 10, K = 7;
    
    // N = 5 일 때, v [0 1 2 3 4 5]
    // 삭제한 것을 true, 삭제 X를 false
    vector<bool> v(N + 1);

    // 0, 1은 true 처리
    v[0] = v[1] = true;

    // K일 때까지 삭제하기
    for(int i = 2; i <= N; i++){
        if(!v[i]){
            v[i] = true;
            count++;
            if(checkEnd(count, K)) {
                cout << i; 
                break;
            }
            for(int j = i * i; j <= N; j += i){
                if(!v[j]){
                    v[j] = true;
                    count++;
                    if(checkEnd(count, K)) {
                        cout << j; 
                    break;
                    }
                }
            }
        }
    }
    return 0;
}