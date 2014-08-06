#include <cstdio>
#include <vector>

void printVect(std::vector<int> &vect){
    for(int i = 0; i < vect.size(); ++i)
    {
        if(i != vect.size() - 1)
            printf("%i", vect[i]);
        else
            printf("%i\n", vect[i]);
    }
}
void readIn(std::vector<int> &vect){
    for(int i = 0; i < vect.size(); ++i)
    {
        int next;
        if(i == vect.size() - 1)
            scanf("%i", &next);
        else
            scanf("%i ", &next);

        vect[i] = next;
    }
}
/* TOO SLOW
void isAmbiguous(std::vector<int> &vect){
    std::vector<int> inverse(vect.size());
    for(int i = 0; i < vect.size(); ++i)
    {
        for(int j = 0; j < vect.size(); ++j)
        {
            if(vect[j] == i + 1)
                inverse[i] = j + 1;
        }
    }

    if(inverse == vect)
        printf("ambiguous\n");
    else
        printf("not ambiguous\n");
}
*/
void isAmbiguous(std::vector<int> &vect){
    std::vector<int> inverse(vect.size());
    for(int i = 0; i < vect.size(); ++i)
    {
        inverse[vect[i] - 1] = i + 1;
    }

    if(inverse == vect)
        printf("ambiguous\n");
    else
        printf("not ambiguous\n");
}
int main(){
    //std::vector<int> testamg = {1, 5, 3, 4, 6, 2};
    //isAmbiguous(testamg);
    while(true)
    {
        int length;
        scanf("%i", &length);
        if(length == 0)
        {
            break;
        }
        scanf("\n");

        std::vector<int> test(length, 0);

        readIn(test);
        isAmbiguous(test);
    }
    return 0;
}
