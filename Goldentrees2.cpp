#include <iostream>
#include <istream>
#include <deque>
#include <cstdio>

const long long int MOD = 100000007;
void nextQueue(std::deque<long long int> &);
long long int TreeTax(int initTax,int slot1,int slot2,int K,long long int N){
    if(N <= 1+slot1)
    {
        return initTax+N-1;
    }
    if(N <= 1+slot1+slot2)
    {
        long long int tax(initTax+slot1);
        for(int i = 1; i <= (N-1-slot1); ++i)
        {
            tax *= 2;
            tax %= MOD;
        }
        return tax;
    }
    std::deque<long long int> runningSequence(K, 0);
    for(int i = 0; i < K; ++i)
    {
        runningSequence[i] = TreeTax(initTax, slot1, slot2, K, 1+slot1+slot2-i);
    }
    N-=1+slot1+slot2;
    for(int i = 0; i < N; ++i)
    {
        nextQueue(runningSequence);
    }
    return runningSequence[0] % MOD;
}
void nextQueue(std::deque<long long int> & vect){
    long long int nextElem(1);
    for(int i = 0; i < vect.size(); ++i)
    {
        nextElem *= vect[i];
        nextElem %= MOD;
    }
    vect.pop_back();
    vect.push_front(nextElem);
}
int main(){
    int no_of_tests(0);
    scanf("%i", &no_of_tests);
    for(int i = 0; i < no_of_tests; ++i)
    {
        int initTax(0), slot1(0), slot2(0), K(0);
        long long int N(0);
        scanf("%i", &initTax);
        scanf("%i", &slot1);
        scanf("%i", &slot2);
        scanf("%i", &K);
        scanf("%i", &N);
        printf("%d", TreeTax(initTax, slot1, slot2, K, N));
    }
}
