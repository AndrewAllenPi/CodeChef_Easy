#include <cstdio>

int main(){
    int withdraw;
    float balance;
    scanf("%i %f", &withdraw, &balance);
    if((withdraw %5 == 0) && (balance-withdraw-0.5>0)){
        balance-=(withdraw+0.5);
        printf("%.2f", balance);
    } else
        printf("%.2f", balance);
}
