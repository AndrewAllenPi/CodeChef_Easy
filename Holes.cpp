#include <cstdio>

int main(){
    int no_of_tests;
    scanf("%i\n", &no_of_tests);
    for(int i = 0; i < no_of_tests; ++i)
    {
        int counter = 0;
        char letters[100];
        int index = 0;
        while(true)
        {
            scanf("%c", &letters[index]);
            if(letters[index] == '\n') break;
            ++index;
        }
        for(int j = 0; j < index; ++j)
        {
            char next = letters[j];
            if(next == 'A' || next == 'D' || next == 'O' || next == 'P' || next == 'Q' || next == 'R') ++counter;
            if(next == 'B') counter += 2;
        }
        printf("%i\n", counter);
    }
}

