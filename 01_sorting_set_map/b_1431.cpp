#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
// 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
// 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
int sumString(const string& str){
    int sum  = 0;
    for(char c : str){
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}


bool comp(const string& s1, const string& s2){
    if(s1.length() != s2.length()){
        return (s1.length() < s2.length());
    }
    if(sumString(s1) != sumString(s2)){
        return (sumString(s1) < sumString(s2));
    }
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            return (s1[i] < s2[i]);
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<string> arr(n); 
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }
    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n"; 
    }
    return 0;
}