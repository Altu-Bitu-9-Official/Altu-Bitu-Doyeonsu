#include <iostream>
using namespace std;

int divide(int x, int y){
    if (x >= 0){
        return x / y; 
    }
    else{
        return (x - 1) / y;
    }
}
int main(){
    int l = 0;
    cout << divide(-5, 2);
    return 0;
}