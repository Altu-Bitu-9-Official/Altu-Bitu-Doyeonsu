#include <iostream>
#include <string>
#include <stack>

using namespace std;




int main(){
    string line;
    
    while(getline(cin, line)){
        if(line == "."){
            break;
        }
        //cout << line << "\n";
        bool balance = true;
        stack<char> s;
        for(char c : line){
            if(c == '(' || c == '['){
                s.push(c);
            }
            else if (c == ')'){
                if((!s.empty() && s.top() == '(')){
                    s.pop();
                }
                else{
                    balance = false;
                    break;
                }
            }
            else if(c == ']'){
                if((!s.empty() && s.top() == '[')){
                    s.pop();
                    
                }
                else{
                    balance = false;
                    break;
                }
            }
        }

        if(!s.empty()){
            balance = false;
        }

        if(balance){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    
    return 0;
}