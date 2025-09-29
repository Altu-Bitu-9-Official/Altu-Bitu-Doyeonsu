#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    set<string> ppl;

    string name, input;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> name >> input;
        if(input == "enter"){
            ppl.insert(name);
        }
        else{
            ppl.erase(name);
        }
    }
    for(auto iter = ppl.rbegin(); iter != ppl.rend(); iter++){
        cout << *iter << '\n';
    }




}