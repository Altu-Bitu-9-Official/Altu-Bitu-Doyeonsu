// b_11726 타일링
#include <iostream>
#include <vector>

using namespace std;
// 점화식
/*
f(n) = f(n-1) + f(n-2)  (n >= 3)
f(1) = 1
f(2) = 2
1 2 3 5 8 13 21 34 55

*/

int main(){
    int n;
    cin >> n;

    vector<int> v(n+1, 0);

    for(int i = 1; i <= n; i++){
        if(i == 1){v[i] = 1;}
        else if(i == 2){v[i] = 2;}
        else{
            v[i] = (v[i-1] + v[i-2]) % 10007;
        }
    }

    cout << v[n];
    return 0;
}