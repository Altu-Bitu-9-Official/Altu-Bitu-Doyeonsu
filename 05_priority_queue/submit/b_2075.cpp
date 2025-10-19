#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// head가 여러 개인 pq
// 포인터를 사용하기 위해 구조체를 만들거나, 배열 같이 일정하게 정해진 경우는 tuple 넘겨준다.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    
    cin >> N;
    vector<vector<int>> v(N, vector<int> (N));
    vector<int> counterV(N, N - 1);

    // val, row, col
    priority_queue<tuple<int, int, int>> pq;
    for(int i = 0; i < N * N; i++){
        int input;
        int row = i / N;
        int col = i % N;
        cin >> v[row][col];
    }

    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }*/

    // 마지막 열 전부 삽입
    for(int i = 0; i < N; i++){
        // pq
        pq.push(tuple(v[N-1][i], N-1, i));
        counterV[i]--;
    }

    // counter~ < 0이면 없음
    int cnt = 1;
    // 빌 때까지 
    // 최소 N번은 반복할 테니 걱정 X
    while(!pq.empty()){
        if(cnt == N){
            cout << get<0>(pq.top()) << "\n";
            break;
        }
        // 빼고 집어넣기 반복
        tuple<int, int, int>t = pq.top();
        //cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
        int col = get<2>(t);
        pq.pop();
        
        
        //cout << "push" << v[counterV[col]][col] << " " << counterV[col] << col << "\n";
        
        pq.push(tuple(v[counterV[col]][col], counterV[col], col));
        --counterV[col] ;
        cnt++;        
    }

    return 0;
}