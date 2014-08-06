#include <cstdio>
#include <list>

void swap(long int &i, long int &j){
    int temp = i;
    i = j;
    j = temp;
}
void printlist(std::list<long int> &list_of_ints, long int length){
    for(long int i = 0; i < length-1; ++i)
    {
        printf("%i\n", list_of_ints.front());
        list_of_ints.pop_front();
    }
    printf("%i", list_of_ints.front());
}

int main(){
    long int no_of_ints;
    scanf("%i\n", &no_of_ints);
    std::list<long int> list_of_ints;
    long int newint;
    for(long int i = 0; i < no_of_ints; ++i)
    {
        if(i == no_of_ints-1)
            scanf("%i", &newint);
        else
            scanf("%i\n", &newint);
        list_of_ints.push_back(newint);
    }
    list_of_ints.sort();
    printlist(list_of_ints, no_of_ints);
}
