#ifndef _EVAL_H_
#define _EVAL_H_
#include "abstracteval.h"
#include <string>
using namespace std;

// class Eval: public AbstractEval {
class Eval {
    private:
        string expr;
        string operators;
    public:
        Eval();
        Eval(const char *expre);
        Eval(Eval &evl); // Constructor de copiere
        bool Validate();
        string GetExpression();
        bool SetExpression(const char *expre);
        int GetOperatorCount(char my_operator);
        string GetOperatorsList();
        int Evaluate();
};
#endif
