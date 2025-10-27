#include <iostream>
#include <vector>

using namespace std;

// 디버깅용 출력
void print_v(vector<pair<int, int>> &v){
    for(auto pair: v){
        cout << pair.first << " " << pair.second << "\n";
    }
}
// check pairs
bool check_pairs(vector<pair<int, int>> &meetings, pair<int, int> new_p){
    for(auto pair: meetings){
        if ((new_p.second <= pair.first) && (new_p.first >= pair.second)){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
// 0~ i-1까지 처리 후, 
// i번째를 넣었을 때와 넣지 않았을 때 중 meeting이 더 큰 값 구하기
int fill_v(vector<pair<int, int>> &v, vector<pair<int, int>> &meeting, int i, int max){
    int yes, no;
    // i 넣을 수 있을때
    if(check_pairs(meeting, v[i])){
        meeting.push_back(v[i]);
        //print_v(meeting);
        // 넣고, i+1번째 이후부터 다시 계산
        
        // 마지막 아닐 때
        if (i != v.size() - 1){
            yes = fill_v(v, meeting, i + 1, 1);
        }
        else{
            yes = 1;
        }
    } 
    else{
        // 마지막 아닐 때
        if (i != v.size() - 1){
            no = fill_v(v, meeting, i + 1, 0);

        } 
        else{
            no = 0;
        }
    }

    if(yes < no && check_pairs(meeting, v[i])){
        cout << "meeting에 v[i] 안 넣음" ;
        meeting.pop_back();
        print_v(meeting);
        return max + no;
    }
    cout << "meeting에 v[i] 넣음" ;
    print_v(meeting);
    return max + yes;
}



int main(){ 
    int N;

    // 입력
    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++){
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        v[i] = p;
    }

    vector<pair<int, int>> meeting;
    //print_v(meeting);
    int n = fill_v(v, meeting, 0, 0);

    cout << n;

    return 0;
}



//print_v(v);