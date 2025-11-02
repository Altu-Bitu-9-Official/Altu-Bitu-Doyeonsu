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
void grab(string &s, int idx, int K){
    // 앞 집기
    int start = max(idx - K, 0);
    int end = min(idx + K, int(s.size()) - 1);
    
}


int main(){

    int N, K;
    string str;
    cin >> N >> K >> str;

    // 예시 input
    N = 20;
    K = 1;
    str = "HHPHPPHHPPHPPPHPHPHP";

    // 그리디 알고리즘 사용 방법:
    // 제일 앞사람부터 뒤로 갈수록 본인 앞 영역에 햄버거 있으면 집고, 없으면 뒤에꺼 집는다. 뒤에도 없으면 못집겠지.
    // 그리디 알고리즘을 사용해야 하는 이유
    return 0;
}