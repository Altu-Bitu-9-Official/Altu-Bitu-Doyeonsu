#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main(){
    string n1, n2;
    //deque<int> d;
    
    cin >> n1;
    cin >> n2;

    // n1 = "45";
    // n2 = "17";

    int len = max(n1.size(), n2.size());
    vector<int> v(len + 1);
    
    // 0...2
    for(int i = 0; i < len ; i++){
        // n1의 자리수
        int n1_digit =  n1.size() - i - 1;
        // n2의 자리수
        int n2_digit = n2.size() - i - 1;
        // v의 자리수
        int v_digit = len - i;
        int n1_value = 0, n2_value = 0;
        if(i < n1.size()){
            n1_value = n1[n1_digit] - '0';
        }
        if(i < n2.size()){
            n2_value = n2[n2_digit] - '0';
        }

        // cout << "자릿수" << i << "\n";
        // cout << (n1_value) << "\n";
        // cout << (n2_value) << "\n";
        // cout << (v[v_digit]) << "\n\n";
        int sum = n1_value + n2_value + (v[v_digit]);
        if(sum < 10){
            v[v_digit] = sum; 
        }
        else{
            v[v_digit] = sum - 10;
            v[v_digit - 1] += 1;
        }
        //cout << (v[v_digit]) << "\n\n";
    }
    //cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        //cout << v[i] ;
        if(i == 0 && v[i] == 0){
            continue;
        }
        else{
            cout << v[i];
        }
    }
    cout << "\n";    
    return 0;
}