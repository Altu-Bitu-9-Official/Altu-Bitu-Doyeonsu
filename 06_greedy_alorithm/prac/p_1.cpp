#include <string>
#include <vector>
#include <iostream>

using namespace std;

void borrow(vector<int> &stds, int i){
    // 없는 학생일 경우.
    if(stds[i] == 0){
        // 맨 앞은 다음이 2개면 빌려오기
        if(i ==0 && stds[i+1] == 2){
            stds[i] = 1;
            stds[i+1]--;
        }
        // 그 외에 맨 뒤가 아니라면 앞에서 먼저 빌리고
        // 뒤에서 빌리기
        else if(i != stds.size() - 1){
            if(stds[i - 1] == 2){
                stds[i] = 1;
                stds[i-1]--;
            }
            else if(stds[i + 1] == 2){
                stds[i] = 1;
                stds[i+1]--;
            }
        }
        // 맨 뒤는 앞에서만 빌릴 수 있음
        else if(i == stds.size() - 1){
            if(stds[i - 1] == 2){
                stds[i] = 1;
                stds[i-1]--;
            }
        }
    }
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 학생 수 n
    // lost
    // reserve
    // reserve에서 lost 

    // ㅣ r
    // X  X  => 1
    // X  O  => 2
    // O  X  => 0
    // O  O  => 1

    // 기본적으로 1개씩 있음
    vector<int> stds(n, 1);

    for(auto l : lost){
        stds[l-1]--;
    }

    for(auto r : reserve){
        stds[r-1]++;
    }
    // 0개 있는 학생 중 앞뒤에 2개 사람 있으면 빌려오면 된다.
    // 2개 사람 옆에 
    // 0 2 0 2 0
    // 0 2 0 1 2
    //    2 0 0
    //    2 0 1
    //    2 0 2

    // 가장 앞이 먼저 빌리고 나머지가 빌리기
    for(int i = 0; i < n; i++){
        borrow(stds, i);
    }

    for(int i = 0; i < n; i++){
        if(stds[i] > 0) answer++;
    }
    
    return answer;
}

int main(){
    vector<int> v1 = {2, 4};
    vector<int> v2 = {1, 3, 5};
    cout << solution(5, v1, v2) << "\n";
}