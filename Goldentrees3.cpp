#include <cstdio>


typedef long long int lln;
const lln MOD = 100000007;
const int SIZE = 1000;


int scan(){
    int ans = 0;
    int check = 0;
    char buffer[SIZE];
    while((check = fread(buffer, sizeof(char), SIZE, stdin)) > 0)
    {
       while('0' <= digit && digit <= '9')

    }

}

int main(){
    int no_of_tests(0);
    scanf("%i", &no_of_tests);
    for(int i = 0; i < no_of_tests; ++i)
    {
        int initTax(0), slot1(0), slot2(0), K(0);
        lln N(0);

        initTax = scan();
        slot1 = scan();
        slot2 = scan();
        K = scan();
        N = scan();
        printf("%d", TreeTax(initTax, slot1, slot2, K, N));
    }
}
