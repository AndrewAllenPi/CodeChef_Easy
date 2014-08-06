#include <cstdio>

int main(){
    int no_of_games;
    scanf("%i\n", &no_of_games);
    int lead = 0;
    int winner;
    int score1(0), score2(0);
    for(int i = 0; i < no_of_games; ++i)
    {

        int next1, next2;

        if(i == no_of_games - 1)
            scanf("%i %i", &next1, &next2);
        else
            scanf("%i %i\n", &next1, &next2);

        score1 += next1;
        score2 += next2;
        if((score1 > score2) && (score1 - score2 > lead))
        {
            winner = 1;
            lead = score1 - score2;
        }
        else if((score2 > score1) && (score2 - score1 > lead))
        {
            winner = 2;
            lead = score2 - score1;
        }
    }
    printf("%i %i", winner, lead);
    return 0;
}
