#include <iostream>
#include <vector>
#define NINE_IDX 6
#define THREE_IDX 2
using namespace std;

void print_pair(vector<pair<int, int>> &p){
    for(auto c : p){     
        cout << c.first << " " << c.second;
        cout << "\n";
    }
}
void print_vec(vector<vector<int>> &v){
    for(auto c : v){
        for(auto e : c){
            cout << e << " ";
        }
        cout << "\n";
    }
}


// idx 왼쪽 돌릴지 부호 체크 (0도 para 가능)
bool check_change_left(vector<vector<int>> &v, vector<pair<int, int>> &p, int idx){
    // 0은 없음
    if(idx != 0){
        // 현 idx 9시랑 왼쪽 3시 다를 때 true
        if(v[idx][p[idx].second] != v[idx - 1][p[idx - 1].first]){
            return true;
        }
    }
    return false;
}
// idx 오른쪽 돌릴지 부호 체크 (마지막도 para 가능)
bool check_change_right(vector<vector<int>> &v, vector<pair<int, int>> &p, int idx){
    // 0은 없음
    if(idx != v.size() - 1){
        // 현 idx 3시랑 오른쪽 9시 다를 때 true
        if(v[idx][p[idx].first] != v[idx + 1][p[idx + 1].second]){
            return true;
        }
    }
    return false;
}



void change_dir(vector<pair<int, int>> &p, int idx, int dir){
    if(dir == 1){
        p[idx].first =  (p[idx].first == 0 ? 7 : p[idx].first - 1);
        p[idx].second = (p[idx].second == 0? 7 : p[idx].second - 1);
    }
    else if(dir == -1){
        //cout << p[idx].first << "d\n";
        p[idx].first =  (p[idx].first == 7 ? 0 : p[idx].first + 1);
        p[idx].second = (p[idx].second == 7 ? 0 : p[idx].second + 1);
    
    }
}

int left_idx(int i){
    if(i == 0) return 7;
    return --i;
}

int right_idx(int i){
    if(i == 7) return 0;
    return ++i;
}

// idx 를 dir로 항상 돌리고, 양 옆도 돌린다. 
void turn(vector<vector<int>> &v, int idx, int dir, vector<pair<int, int>> &p){
    // 1 : 시계  (포인터를 -1)
    // -1 : 반시계 (포인터를 +1)
    vector<int> lefts;
    vector<int> rights; 
   
   
    // 왼쪽 전파
    if(idx != 0){
        for(int i = idx; i > 0; i--){
            if(check_change_left(v, p, i)){
                //cout << i << "left \n";
                //dir = -dir;
                lefts.push_back(i - 1);
                //change_dir(p, i - 1, -dir);
            }
            else{
                break;
            }
        }
    }
    // 오른쪽 전파
    if(idx != v.size() - 1){
        for(int i = idx ; i < v.size(); i++){
            if(check_change_right(v, p, i) ){
                
                //dir = -dir;
                //cout << i << "right" << -dir <<"\n";
                rights.push_back(i + 1);
                //cout << "rights " << i + 1<< "\n";
            }
            else{
                break;
            }
        }
    }
    
    // 3시, 9시 포인터 바꿔주기
    change_dir(p, idx, dir);
    int curr_dir = -dir;
    //print_pair(p);
    for(auto l : lefts){
        //cout << l << "\n
        change_dir(p, l, curr_dir);
        curr_dir = -curr_dir;
    }
    curr_dir = -dir;
    for(auto r : rights){
        
        change_dir(p, r, curr_dir);
        curr_dir = -curr_dir;
    }
}



int main(){
    // 일단은, 
    // 톱니가 닿는 부분 3시, 9시
    // 맨 앞은 3시
    // 맨 뒤는 9시

    // 회전은 1칸만 된다. 

    // 회전 조건이 맞으면, (톱니 닿는 부분이 다른 극) => 회전하는 index 고르기
    // 반대 방향으로 돌아감 => 방향에 따라 돌리는 함수 만들기

    // 자료 구조는 vector + 원형 벡터로 한다. 

    int T; 
    cin >> T;
    // 원형 벡터의 모음
    vector<vector<int>> v(T);

    // 원형 벡터의 3시, 9시
    vector<pair<int, int>> three_nine(T);

    for(int i = 0; i < T; i++){
        vector<int> c(8);
        string str;
        cin >> str;
        
        for(int j = 0; j < 8; j++){
            c[j] = (int)str[j] - '0'; 
            //cout << (int)str[j] - '0';
        }
        v[i] = c;
        three_nine[i].first = 2;
        three_nine[i].second = 6;
        //cout << "\n";
    }

    //print_vec(v);
    int K;
    cin >> K;
    vector<pair<int, int>> turns(K);
    for(int i = 0; i < K; i++){
        cin >> turns[i].first;
        cin >> turns[i].second;
        //cout << K << "- K\n";
        //cout << turns[i].first - 1 << "\n";
        turn(v, turns[i].first - 1, turns[i].second, three_nine);
        //print_pair(three_nine);
        //cout << "\n";
    }
    //print_pair(three_nine);

    int cnt = 0; 
    for(int i = 0; i < v.size(); i++){
        int zero_idx = (three_nine[i].first + 6) % 8;

        //int zero_idx = left_idx(left_idx(three_nine[i].first));
        //cout << zero_idx << " " << v[i][zero_idx] << "\n";
        if (v[i][zero_idx] == 1){
            cnt++;
        }
    }

    //print_pair(three_nine);
    cout << cnt << "\n";

    return 0;
}