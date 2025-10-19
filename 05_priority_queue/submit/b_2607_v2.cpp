#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 문제 풀이 시작 : 8 : 40
// 두 번째

// 같은 구성 : sring을 이루는 알파벳 기호가 갯수까지 같다. 
// 비슷한 구성 : 같은 구성 + string을 이루는 알파벳 기호가 
// 길이 - 1 : 비교 string에서 하나만 남기고
// 길이 : 비교 string에서 하나 남기고, 이 string에서도 하나 남길 경우
// 길이 + 1 : 이 string에서 하나 남길 때
void printVec(vector<int> &v){
    for (int i = 0; i < 26; i++){
        cout << (char)('A' + i) << v[i] << "\n";  
    }
}


bool compare(string &str1, string &str2){
    if(abs((int)(str1.length() - str2.length())) > 1){
        return false;
    }
    vector<int> v1(26);
    vector<int> v2(26);
    vector<int> v3(26);

    for(auto ch : str1){
        int idx = ch - 'A';
        v1[idx] += 1;
    }
    for(auto ch : str2){
        int idx = ch - 'A';
        v2[idx] += 1;
    }
    //printVec(v1);
    int diff1 = 0, diff2 = 0;

    for(int i = 0; i < 26; i++){
        v3[i] = v1[i] - v2[i];
        //cout << (char)('A' + i) << v3[i] << "\n"; 
        if(v3[i] == 0){
            continue;
        }
        if(v3[i] == 1){
            diff1++;
        }
        else if(v3[i] == -1){
            diff2++;
        }
        else{
            return false;
        }
    }

    // 차이가 전부 0 
    // 차이 1 하나
    // 차이 -1 하나

    if((diff1 == 0 && diff2 == 0) || (diff1 == 1 && diff2 == 0) || (diff1 == 0 && diff2 == 1) || (diff1 == 1 && diff2 == 1)){
        return true;
    }
    //cout << "false\n";
    return false;
    
}



// 첫 string ~ 끝까지 map에 넣기
// map 알파벳끼리 비교
int main(){
    int n;
    int count = 0;
    string str1;
    string str2;

    /*
    str1 = "DOG";
    str2 = "GOODY";

    
    if(compare(str1, str2)) {
        count++;
    }
    cout << count << "\n";
    */

    
    cin >> n;
    cin >> str1;
    for(int i = 0; i < n - 1 ; i++){
        cin >> str2;
        if(compare(str1, str2)) {
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}