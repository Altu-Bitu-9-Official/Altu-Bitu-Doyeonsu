#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



 //c_n = 2 (0~2) t_n = 2 -> 1 v_s = 3 
void turn_util(int& current_num, int slots, int turn_num){
    current_num = (current_num + turn_num) % slots;
}

bool check_duplicate(vector<char> &v){
    set<char> s;
    for(char ch : v){
        if(ch != '?'){
            // 없는 경우 set에 삽입
            if(s.find(ch) == s.end()){
                s.insert(ch);
            }
        
            else{
                return true;
            }
        }
        
    }
    return false;
}

void print_vector(vector<char> &v, int n){
    for(int i = n; i >= 0; i--){
        cout << v[i];
    }
    for(int i = v.size() - 1; i > n; i--){
        cout << v[i];
    }
    cout << "\n";
}

int main(){
    
    int slots, turn_num;
    int current_num = 0;
    cin >> slots >> turn_num;
    vector<char> v(slots, '?');

    while(turn_num--){
        int num;
        char ch;
        cin >> num >> ch;
        turn_util(current_num, slots, num);
        //error handling
        if(v[current_num] != '?'&&  v[current_num]!= ch){
            cout << '!' << '\n';
            return 0;
        }
        v[current_num] = ch;
    }
   
    
    if(check_duplicate(v)){
        cout << '!' << '\n';
    }
    else{
        print_vector(v, current_num);
        //cout << "okay";
    }
    
    return 0;
}