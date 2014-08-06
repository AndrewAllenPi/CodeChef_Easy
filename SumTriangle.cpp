#include<cstdio>
#include<vector>


int max(const int &a, const int &b){
    if(a > b)
        return a;
    else
        return b;
}
int max(std::vector<int> &vect){
    int ans(0);
    for(int i = 0; i < vect.size(); ++i)
    {
        if(vect[i] > ans)
            ans = vect[i];
    }
    return ans;
}
/*
void printVect(std::vector<int> &vect){
    for(int i = 0; i < vect.size() - 1; ++i)
    {
        printf("%i, ", vect[i]);
    }
    printf("%i\n", vect[vect.size() - 1]);
}
*/
void readIn(std::vector<int> &next_line){
    for(int i = 0; i < next_line.size()-1; ++i)
    {
        scanf("%i ", &next_line[i]);
    }
    scanf("%i", &next_line[next_line.size()-1]);
}

int sumTrees(int &no_of_lines){
    std::vector<int> runningTotal(no_of_lines, 0);
    for(int i = 1; i <= no_of_lines; ++i)
    {
        std::vector<int> next_line(i, 0);
        readIn(next_line); // scan in next line from console to the vector
        std::vector<int> clone = runningTotal;
        for(int j = 0; j < i; ++j)
        {
            if(j != 0)
            {
                clone[j] =
                max(runningTotal[j] + next_line[j], runningTotal[j - 1] + next_line[j]);
            }
            else
            {
                clone[j] =
                runningTotal[j] + next_line[j];
            }
        }
        runningTotal = clone;
    }
    return max(runningTotal);
}

int main(){
    int no_of_tests;
    scanf("%i\n", &no_of_tests);
    for(int i = 0; i < no_of_tests; ++i)
    {
        int no_of_lines;
        scanf("%i\n", &no_of_lines);
        printf("%i\n", sumTrees(no_of_lines));
    }
}
