#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 디버깅용 출력
void print_v(vector<pair<int, int>> &v){
    for(auto pair: v){
        cout << pair.first << " " << pair.second << "\n";
    }
}

int main(){ 
    int N;

    // 입력
    cin >> N;
    // 시작, 끝
    vector<pair<int, int>> v(N);

    for(int i = 0; i < N; i++){
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        v[i] = p;
    }

   

    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    vector<int> select;
    select.push_back(0);
    int cnt = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i].first >= v[select.back()].second){
            select.push_back(i);
            cnt++;
        }
    }
   
    // 가장 빨리 끝나는 회의 담기
    // pq에서 하나씩 꺼내서 start값이 그 전 회의 끝나는 시간보다 같거나 크면 add
    
    //vector<pair<int, int>> selected_meetings;
    /*
    for(auto a : select){
        cout << a << " ";
    }*/

    
    cout << cnt;
    return 0;
}



/*

selected_meetings.push_back(v[pq.top().second]);
    pq.pop();
    count++;
    while(!pq.empty()){
        pair<int, int> meeting = pq.top();
        // 꺼낸 해당 index의 시작 
        if(!selected_meetings.empty() && v[meeting.second].first >= selected_meetings.back().second){
            selected_meetings.push_back(v[meeting.second]);
            count++;
        }  
        pq.pop();
    }
 // 끝, 인덱스
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    

*/