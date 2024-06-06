#include "fibonachi.h"

Fibonachi::Fibonachi()
{

}

void Fibonachi::calc(int order)
{
    int firstNumber = 0;
    int secondnumber = 1;
    int current = 2;
    int result = 0;
    while(current<order)
    {
        result+=firstNumber+secondnumber;
        firstNumber=secondnumber;
        secondnumber=result;
        current++;
    }
}
