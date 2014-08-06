#include <cstdio>
#include <vector>

void readIn(std::vector<char> &vect){
    char next = ' ';
    while(true)
    {
        next = getchar();
        if(next == '\n') break;
        vect.push_back(next);
    }
}
void printVect(std::vector<char> &vect){
    for(int i = 0; i < vect.size(); ++i)
    {
        if(i != vect.size() - 1)
            printf("%c", vect[i]);
        else
            printf("%c\n", vect[i]);
    }
}

int findBracket(std::vector<char> &vect, int dx, int start){
    int bracket_pos = -1;
    int lbrackets = 0;
    int rbrackets = 0;
    for(int i = start; i < vect.size(); ++i)
    {
        if(vect[i] == '(')
        {
            ++lbrackets;
        }
        if(vect[i] == ')')
        {
            ++rbrackets;
        }
        if(lbrackets == rbrackets + dx)
        {
            bracket_pos += i + 1;
            break;
        }
    }
    return bracket_pos;
}
int findFirstBracket(std::vector<char> &vect){
    return findBracket(vect, 1, 0);
}
int findLastBracket(std::vector<char> &vect){
    int start = findFirstBracket(vect);
    return findBracket(vect, 0, start);
}
int findOperator(std::vector<char> &vect, int bracket_pos1){
    return findBracket(vect, 0, bracket_pos1 + 1) + 1;
}

void reversePolish(std::vector<char> &vect){
    while(true){
        int bracket_pos1 = findFirstBracket(vect);
        if(bracket_pos1 == -1)
            return; // we are done


        int operator_pos = findOperator(vect, bracket_pos1);


        // delete operator
        char op = vect[operator_pos];
        int original_operator_pos = operator_pos;

        if(op == ')')
        {
            vect.erase(vect.begin() + original_operator_pos);
            //printf("brac1 = %i, op = %i\n", bracket_pos1, original_operator_pos);
            //printVect(vect);
            vect.erase(vect.begin() + bracket_pos1);
            //printf("brac1 = %i, op = %i\n", bracket_pos1,  original_operator_pos);
            //printVect(vect);
        }
        else
        {
            operator_pos = findOperator(vect, operator_pos);

            vect.insert(vect.begin() + operator_pos, 1, op);

            int bracket_pos2 = findLastBracket(vect);

            //printf("brac1 = %i, brac2 = %i, op = %i\n", bracket_pos1, bracket_pos2, original_operator_pos);
            //printVect(vect);
            vect.erase(vect.begin() + bracket_pos2);
            //printf("brac1 = %i, brac2 = %i, op = %i\n", bracket_pos1, bracket_pos2, original_operator_pos);
            //printVect(vect);
            vect.erase(vect.begin() + original_operator_pos);
            //printf("brac1 = %i, brac2 = %i, op = %i\n", bracket_pos1, bracket_pos2, original_operator_pos);
            //printVect(vect);
            vect.erase(vect.begin() + bracket_pos1);
            //printf("brac1 = %i, brac2 = %i, op = %i\n", bracket_pos1, bracket_pos2, original_operator_pos);
            //printVect(vect);
        }
    }

}
int main(){
    int no_of_cases;
    scanf("%i\n", &no_of_cases);
    for(int i = 0; i < no_of_cases; ++i)
    {
        std::vector<char> expr;
        readIn(expr);
        reversePolish(expr);
        printVect(expr);
    }
    return 0;
}
