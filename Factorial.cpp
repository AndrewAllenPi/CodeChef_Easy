#include <cstdio>

void factorialZeros(int input){
    int countZ(0);
    int div = 5;
    int quot;
    while(div <= input)
    {
        quot = input/div;
        countZ += quot;
        div *= 5;
    }
    printf("%i\n", countZ);
}

int main(){
    int no_of_tests;
    scanf("%i", &no_of_tests);
    int input(0);
    for(int i = 0; i < no_of_tests; ++i)
    {
        scanf("%i", &input);
        factorialZeros(input);
    }
}
