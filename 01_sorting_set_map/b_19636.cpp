/*
W        I         B       A
체중 += 일일섭 - (일일기 + 일일활) = 일일섭 - (일일소)
W0        I0      I0      0

           I               A
----------------------------------------------
W0 += d * (I - (I0 + A))    I0

I_daily = I0
C_daily = B_daily + A_daily
if (abs(I_daily - C_daily) > T){B_daily += (I_daily - C_daily) / 2}
----------------------------------------------

if |일일섭 - 일일소| : 일일기 += (일일섭 - 일일소) / 2
입력
W0(체) I0(전일일섭) T(역치)    -- 전일일기 = I0, A0 = 0
D(기간) I(일일섭) A(일일활)

출력 
(일일기 고려 X)
체 일일기
(일일기 고려)
( 체 일일기 YOYO/NO   )            or   (DangerDiet)


*/

#include <iostream>
#include <vector>

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
    int W0, I0, T, D, I, A;
    int W_final = 0;
    // W0(체) I0(전일일섭) T(역치) 
    cin >> W0;
    cin >> I0;
    cin >> T;

    //D(기간) I(일일섭) A(일일활)
    cin >> D ;
    cin >> I ;
    cin >> A ;


    W_final += W0 + D * (I - (I0 + A));
    if(W_final <= 0){
        cout << "Danger Diet" << "\n";
    }
    else{
        cout << W_final << " " << I0 << "\n";
    }
    

    int I_daily;
    int B_daily;
    int A_daily;
    int C_daily;

    int I_sum = 0;
    int C_sum = 0;

    for(int i = 0; i <= D; i++){
        if (i == 0){
            I_daily = I0;
            A_daily = 0;
            B_daily = I0;
        }
        else{
            I_daily = I;
            A_daily = A;
        }
        C_daily = B_daily + A_daily;
        if (abs(I_daily - C_daily) > T){
            B_daily += divide(I_daily - C_daily, 2);
        }
        if(B_daily <= 0){
            cout << "Danger Diet";
            return 0;
        }
        I_sum += I_daily;
        C_sum += C_daily;
        // cout << i << "\n";
        // cout << "I_d" << I_daily << "\n";
        // cout << "A_d" << A_daily << "\n";
        // cout << "B_d" << B_daily << "\n";
        // cout << "C_d" << C_daily << "\n\n";
    }

    
    W_final = W0 + I_sum - C_sum;
    //cout << "I_sum" << I_sum << "\n";
    //cout << "C_sum" << C_sum << "\n";
    if(W_final <= 0){
        cout << "Danger Diet";
        return 0;
    }
    cout << W_final << " " << B_daily << " ";
    
    if(I0 - (B_daily) > 0){
        //cout << I0 << B_daily  << "\n";
        cout << "YOYO";
    }
    else{
        cout << "NO";
    }

    return 0;
}