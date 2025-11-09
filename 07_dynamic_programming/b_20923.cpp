#include <iostream>
#include <queue>

using namespace std;

void print_dg(deque<int> &do_deq, deque<int> &su_deq, deque<int> &do_ground, deque<int> &su_ground){
    //int max_deq = max(do_deq.size(), max(su_deq.size(), (do_ground.size(), su_ground.size())));
    for(auto c : do_deq){
        cout << c << " ";
    }
    cout << "\n";
    for(auto c : do_ground){
        cout << c << " ";
    }
    cout << "\n";
    for(auto c : su_ground){
        cout << c << " ";
    }
    cout << "\n";
    for(auto c : su_deq){
        cout << c << " ";
    }
    cout << "\n";
}

// 카드 내려놓기
void card_to_ground(int order, deque<int> &do_deq, deque<int> &su_deq, deque<int> &do_ground, deque<int> &su_ground){
    // 순서인 사람이 카드 내려 놓기
        if(order == 0){
            do_ground.push_back(do_deq.back());
            do_deq.pop_back();
        }
        else{
            su_ground.push_back(su_deq.back());
            su_deq.pop_back();
        }
}

// 그라운드 확인 결과 승부 확인 + 카드 가져가기
int check_winner(deque<int> &do_deq, deque<int> &su_deq, deque<int> &do_ground, deque<int> &su_ground){
    if((!do_ground.empty() && do_ground.back() == 5) || (!su_ground.empty() && su_ground.back() == 5)){
        // 상대방 카드 가져가기 :그라운드 제일 아래에서 빼서 덱 앞에서부터 넣기
        for(auto su : su_ground){
            do_deq.push_front(su);
            su_ground.pop_front();
        }
        // 자기 카드 가져가기
        for(auto do_card : do_ground){
            do_deq.push_front(do_card);
            do_ground.pop_front();
        }
        return 0;
    }

    else if(!do_ground.empty() && !su_ground.empty() && (do_ground.back() + su_ground.back() == 5)){
        // 상대방 카드 가져가기 :그라운드 제일 아래에서 빼서 덱 앞에서부터 넣기
        for(auto do_card : do_ground){
            su_deq.push_front(do_card);
            do_ground.pop_front();
        }
        // 자기 카드 가져가기
        for(auto su_card : su_ground){
            su_deq.push_front(su_card);
            su_ground.pop_front();
        }

        return 1;
    }
    return -1;
}

// 자료 구조 : 덱을 사용해야 앞뒤로 넣는 것이 편할 듯하다!
int main(){

    int N, M;
    cin >> N >> M;

    deque<int> do_deq; // 아래 ... 위
    deque<int> su_deq; // 아래 ... 위

    deque<int> do_ground; // 아래 ... 위
    deque<int> su_ground; // 아래 ... 위
    
    // 덱 배치
    for(int i = 0; i < N; i++){
        int d, s;
        cin >> d >> s;
        do_deq.push_back(d); // 아래 ... 위
        su_deq.push_back(s); // 아래 ... 위
    }
    //print_dg(do_deq, su_deq, do_ground, su_ground);
    int order = 0; // 0 : do, 1 : su


    // 게임 여러 번 시작 
    // 각 회차마다 승자를 정하고, 그라운드에 있는 카드 덱으로 옮기기
    while(M--){
        //cout << M << "회차\n";
        // 일단 deq에 카드 있다고 가정
        // 순서인 사람이 카드 내려 놓기
        card_to_ground(order, do_deq, su_deq, do_ground, su_ground);
        //print_dg(do_deq, su_deq, do_ground, su_ground);
        order = 1 - order;
        if(do_deq.empty()){cout << "su"; return 0;}
        else if(su_deq.empty()){cout << "do"; return 0;}
        check_winner(do_deq, su_deq, do_ground, su_ground);
    }
    if(do_deq.size() > su_deq.size()){cout << "do\n";}
    else if(do_deq.size() < su_deq.size()){cout << "su\n";}
    else{cout << "dosu\n";}

    return 0;
}