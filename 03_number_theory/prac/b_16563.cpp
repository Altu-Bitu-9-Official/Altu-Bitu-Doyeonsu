#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void printArr(vector<bool> &primeDivisorArr){
    for(int i = 0; i < primeDivisorArr.size(); i++){
        if(primeDivisorArr[i]){ 
             cout << i << " ";
        }
        //cout << primeDivisorArr[i] << " ";
    }
}

//4
// 0 1 2 3 4  
// f f t f f 
void printDivisors(vector<bool> &primeDivisorArr, int element){
    int num = element;
    for(int i = 2; i <= element; i++){
        while(primeDivisorArr[i] && num % i == 0){ 
             cout << i << " ";
             num /= i;
        }
        //cout << primeDivisorArr[i] << " ";
    }
}

void isPrimeDivisor(vector<bool> &primeDivisorArr, int element){
    for(int i = 2; i <= sqrt(element) ; i++){
        // 소수 
        if(primeDivisorArr[i]){
            // 소수 중 Divisor 아닌 것 false 처리
            if(element % i != 0){
                primeDivisorArr[i] = false;
            }
            for(int j = i * i; j <= element; j += i){
                primeDivisorArr[j] = false;
            }
        }
        
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, element;
    cin >> N;
 
    while(N--){
        cin >> element;
        // v = 5 면 {0, 1, 2, 3, 4, 5}  arr
        // index와 숫자 일치
        vector<bool> primeDivisorArr(element + 1, true);
        primeDivisorArr[0] = primeDivisorArr[1] = false;
        
        
        // vector에서 자기보다 작고, 약수인 소수 true 처리됨
        isPrimeDivisor(primeDivisorArr, element);
        //printArr(primeDivisorArr);
        //cout << "\n";
        // true 처리된 것들 횟수만큼 출력
        printDivisors(primeDivisorArr, element);
        cout << "\n";

    }

    return 0;
}