#include <iostream>
#include <set>
#include <string>

using namespace std;




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;

    set<string> my_string;
    //cout << str;
    
    for(int i = 0; i < str.length(); i++){
        for(int j = 1; j < str.length() - i + 1; j++){
            //cout << str.substr(i, j) << "\n";
            my_string.insert(str.substr(i, j));  
        }
    }
    cout << my_string.size();
    return 0;
}