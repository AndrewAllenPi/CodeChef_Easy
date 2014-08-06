#include <iostream>
#include <cstdio>

const int SIZE = 1024;
int main(){
    int no_of_tests(0), k(0);
    scanf("%i %i", &no_of_tests, &k);
    int counter(0);
    int next(0);
    for(int i = 0; i < no_of_tests; ++i)
    {
        scanf("%i", &next);
        if(next % k==0) ++counter;
    }
    printf("%d", counter);
}
