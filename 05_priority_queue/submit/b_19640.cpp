#include <iostream>
#include <queue>

using namespace std;

struct emp{
    int D;
    int H;
    int M;
};

struct cmp{
    bool operator()(const emp* e1, const emp* e2){
        bool val = true;
        if(e1->D != e2->D){    
            return e1->D < e2->D;
        }
        else if(e1->H != e2->H){
            return e1->H < e2->H;
        }
        else{
            return e1->M > e2->M;
        }

    }
};

void printpq(priority_queue<emp*, vector<emp*>,cmp> &pq, emp* dc){
    int cnt = 0;
    while(!pq.empty()){
        if(pq.top() == dc){
            cout << cnt;
            break;
        }
        cout << pq.top()->D << " " << pq.top()->H << " " << pq.top()->M << "\n";
        pq.pop(); 
        cnt++;
    }
}





void printVector(vector<vector<emp*>> &v){
    for(int i = 0; i < v.size(); i++){
        cout << i << "\n";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j]->D << " " << v[i][j]->H <<  " ";
        }
        cout << "\n";
    }
}

int main(){

    int N, M, K;
    cin >> N >> M >> K;
    // 다시 줄세우기
    priority_queue<emp*,vector<emp*>,cmp> pq;
    vector<vector<emp*>> v(M);
    vector<int> next_idx(M);

    
    int m = 0;
    
    emp* dc;
    // Vector에 집어넣기
    for(int i = 0; i < N; i++){
        if(m % M == 0){
            m = 0;
        }
        emp* e = new emp;
        e->M = m;
        cin >> e->D;
        cin >> e->H;

        if(i == K){
            dc = e;
            //cout << dc << "\n";
        }
        v[m].push_back(e);
        m++;
    }
    //printVector(v);
    // 앞에서부터 pq에 넣기
    // pq에서 pop할 때, M 보고 집어넣기
    for(int i = 0; i < M; i++){
        // 존재하면
        if(!v[i].empty()){
            pq.push(v[i][next_idx[i]++]);
        }
    }
    int cnt = 0;
    while(!pq.empty()){
        //cout << "GO " << pq.top() << "\n";
        emp* top = pq.top();
        if(top == dc){
            cout << cnt << "\n";
            break;
        }
        //cout << pq.top()->D << " " << pq.top()->H << " " << pq.top()->M << "\n";
        if(next_idx[top-> M] < v[top-> M].size()){
            int top_M = top->M;
            pq.pop();
            cnt++;
            pq.push(v[top_M][next_idx[top_M]++]);
            
        }
        else{
            pq.pop();
            cnt++;
        }
            
        
        
    }
    for(auto a : next_idx){
        //cout << a << " ";
    }
    
    return 0;
}

/*
for(int i = 0; i < N; i++){
        
        if(m % M == 0){
            m = 0;
        }
        emp* e = new emp;
        e->M = m;
        cin >> e->D;
        cin >> e->H;

        if(i == K){
            dc = e;
        }
        pq.push(e);
        m++;
    }
    printpq(pq, dc);
*/