#include <iostream>
#include <istream>

const long long int MOD = 100000007;
long long int TreeTax(int initTax,int slot1,int slot2,int K,long long int N){
    bool BaseCase = (N == 1);
    if(BaseCase){
        return initTax;
    }
    if(N <= 1+slot1+slot2){
        K = 0;
        if((slot2 != 0) && (N > 1+slot1))
        {
            return 2 * TreeTax(initTax, slot1, --slot2, 0, --N)% MOD;
        } else if(slot1 != 0)
        {
            return TreeTax(initTax, --slot1, 0, 0, --N)+1 % MOD;
        }
    }
    if(K != 0)
    {
        long long int total = 1;
        for(int i = 1; i <= K; ++i)
        {
            total *= (TreeTax(initTax, slot1, slot2, K, --N) % MOD);
        }

        return total % MOD;
    }
}
int main(){
    int no_of_tests;
    std::cin >> no_of_tests;
    for(int i = 0; i < no_of_tests; ++i)
    {
        int initTax, slot1, slot2, K;
        long long int N;
        std::cin >> initTax >> slot1 >> slot2 >> K >> N;
        std::cout << TreeTax(initTax, slot1, slot2, K, N) << std::endl;
    }
}
