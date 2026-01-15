#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
공부 내용
string의 size()는 size_t return.
int 로 캐스팅해주자.
1. int (s.size())   ; 문자열 길이가 msb를 채울 정도로 길지 않다면 웬만해서는 괜찮다.
2. static_cast<int>(s.size())

*/

// 햄버거 있으면 집는 함수, 없으면 못 집음
// 
int grab(string &s, int K, int N){
    int cnt = 0;
    // 앞 집기
    
    // ds 는 string으로 계속 가져간다. (char 종류 : '0', 'H', 'P')
    // 집고 나서 0으로 char 바꿔주고
    // 집는 조건은 H 일 때만
    
    // string의 처음부터 끝까지
    for(int i = 0; i < N; i++){
        // P일 경우, 해당 char 의 +-K 를 앞에서부터 보면서 H 있을 때 집고 break
        if(s[i] == 'P'){
            //cout << i << "\n";
            int start = max(i - K, 0);
            int end = min(i + K, N - 1);

            for(int j = start; j <= end; j++){
                if(s[j] == 'H'){
                    s[j] = '0';
                    cnt++;
                    break;
                }
            }
        }
        
    }
    return cnt;
}


int main(){

    int N, K;
    string str;
    cin >> N >> K >> str;

    // 예시 input
    /*
    N = 20;
    K = 1;
    str = "HHPHPPHHPPHPPPHPHPHP";
    */

    // 그리디 알고리즘 사용 방법:
    // 제일 앞사람부터 뒤로 갈수록 본인 앞 영역에 햄버거 있으면 집고, 없으면 뒤에꺼 집는다. 뒤에도 없으면 못집겠지.
    // 그리디 알고리즘을 사용해야 하는 이유
    cout << grab(str, K, N) << "\n";
    
    return 0;
}