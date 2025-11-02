#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// 문제 풀이 시작 : 7 : 10
// 

// 같은 구성 : sring을 이루는 알파벳 기호가 갯수까지 같다. 
// 비슷한 구성 : 같은 구성 + string을 이루는 알파벳 기호가 
// 길이 - 1 : 비교 string에서 하나만 남기고
// 길이 : 비교 string에서 하나 남기고, 이 string에서도 하나 남길 경우
// 길이 + 1 : 이 string에서 하나 남길 때

void printMap(map<char, int> &m){
    for(auto k : m){
        cout << "key: " << k.first;
        cout << " val: " << k.second << "\n";
    }
}
void mapify(map<char, int> &m, string &str){
    for(auto ch : str){
        if(m.find(ch) != m.end()){
            m[ch] += 1;
        }   
        else{
            m[ch] = 1;
        }
    }
    //printMap(m);
}



bool compareMaps(map<char, int> &m1, map<char, int> &m2){
    // m1 개수 >= m2 개수
    int diff1 = 0;
    int diff2 = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++){
        if (m1[ch] != m2[ch]){
            if (m1[ch] == m2[ch] + 1)diff1++;
            else if(m2[ch] == m1[ch] + 1)diff2++;
            else return false;
        } 
    }
        
    if(diff1 == 0 || diff2 == 0){
        return true;
    }
    return false;
}



void compare(string &str1, string &str2, int &n){
    map<char, int> m1;
    map<char, int> m2;

    mapify(m1, str1);
    mapify(m2, str2);
    if (str1.size() == str2.size()){
        n += compareMaps(m1, m2);
        if(compareMaps)cout << "같은\n";
    }
    else if(str1.size() + 1 == str2.size()){
        n += compareMaps(m2, m1);
        if(compareMaps)cout << "str2 하나 더\n";
    }
    else if(str1.size() - 1 == str2.size()){
        n +=compareMaps(m1, m2);
        if(compareMaps)cout << "str1 하나 더\n";
    }
    
}



// 첫 string ~ 끝까지 map에 넣기
// map 알파벳끼리 비교
int main(){
    int n;
    int count = 0;
    string str1;
    string str2;

    str1 = "DOG";
    str2 = "GOOD";
    map<char, int> m1;
    map<char, int> m2;
    mapify(m1, str1);
    mapify(m2, str2);

    compare(str1, str2, count);
    cout << count << "\n";

    /*
    cin >> n;
    cin >> str1;
    for(int i = 0; i < n - 1 ; i++){
        cin >> str2;

    }
        */


    return 0;
}