#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string str;
    cin >> N;
    cin >> str;

    int cnt = 0;
    for(auto ch : str){
        if(ch == '1'){
            cnt++;
        }
    }   
    cout << cnt << "\n";
    
}