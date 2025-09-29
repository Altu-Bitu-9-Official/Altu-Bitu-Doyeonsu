#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, x;
    string cmd;
    deque<int> d;

    cin >> n;

    while(n--){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> x;
            d.push_front(x);
        }
        else if(cmd == "push_back"){
            cin >> x;
            d.push_back(x);
        }
        else if(cmd == "pop_front"){
            if(!d.empty()){
                x = d.front();
                cout << x << "\n";
                d.pop_front();
            }
            else{
                cout << "-1\n";
            }
        }else if(cmd == "pop_back"){
            if(!d.empty()){
                x = d.back();
                cout << x << "\n";
                d.pop_back();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(cmd == "size"){
            cout << d.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << d.empty() << "\n";
        }
        else if(cmd == "front"){
            if(!d.empty()){
                cout << d.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
        else if(cmd == "back"){
            if(!d.empty()){
                cout << d.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }
}