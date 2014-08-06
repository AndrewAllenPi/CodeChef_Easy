 #include<cstdio>
 #include<vector>
 void extractAns(std::vector<int> digits){ for(int i = digits.size()-1; i > 0; --i) { printf("%i", digits[i]); } printf("%i\n", digits[0]); // Move to next line
 }


void multiply(std::vector<int> &init, int next){
    int temp = 0;
    int index = 0;
    while((index < init.size()) || (temp != 0))
    {
        int multiply_digit = init[index]*next + temp;
        init[index] = multiply_digit % 10;
        temp = multiply_digit/10;
        if((index == init.size()-1) && (temp != 0))
            {
                init.push_back(0);
            }
        ++index;
    }
}

void factorial(int input){ std::vector<int> here({1}); for(int i = 2; i <= input; ++i) { multiply(here, i); } extractAns(here); }

int main(){ int no_of_tests; scanf("%i", &no_of_tests); int input(0); for(int i = 0; i < no_of_tests; ++i) { scanf("%i", &input); factorial(input); } }
