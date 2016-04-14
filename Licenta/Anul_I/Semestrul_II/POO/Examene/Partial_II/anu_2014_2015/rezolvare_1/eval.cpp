#include "eval.h"
#include <string>
#include <iostream>

bool Eval::Validate(){
    string::iterator it;

    switch (this->expr.length()) {
        case 0 :
            return true;
            break;

        case 1 :
            if( this->expr[0] >= '0' && this->expr[0] <= '9' ){
                return true;
            }else{
                return false;
            }
            break;

        case 2:
            return false;
            break;

        default:
            if (this->expr.length() % 2 == 0){
                return false;
            }

            it = this->expr.begin();
            while(it != this->expr.end()){
                char first = (char)(*it);
                char second;
                it++;
                if(it != this->expr.end()){
                    second = (char)(*it);
                    it++;
                }else{
                    int nr = first - '0';
                    if (nr < 0 || nr > 9){
                        return false;
                    }else{
                        return true;
                    }
                }
                int nr = first - '0';
                if (nr < 0 || nr > 9){
                    return false;
                }else{
                    return true;
                }

                if(second != '-' || second != '+'){
                    return false;
                }
            }

            return true;
            break;
    }
    return true;
}

Eval::Eval(){
    this->expr = string("");
}

Eval::Eval(const char *expre){
    this->expr = string(expre);
    if(!this->Validate()){
        std::cout << "Expresia< "<< this->expr <<" nu este valida " << std::endl;
        this->expr = string("");
    }
}

Eval::Eval(Eval &evl){
    this->expr = evl.GetExpression();
}

string Eval::GetExpression(){
    return this->expr;
}

bool Eval::SetExpression(const char *expre){
    this->expr = string(expre);
    if(!this->Validate()){
        std::cout << "Expresia< "<< this->expr <<" nu este valida " << std::endl;
        this->expr = string("");
        return false;
    }
    return true;
}

int Eval::GetOperatorCount(const char my_operator){
    string::iterator it;
    int count = 0;
    for(it = this->expr.begin(); it != this->expr.end(); it++){
        if( my_operator == (char)(*it) ){
            count++;
        }
    }
    return count;
}

string Eval::GetOperatorsList(){
    string::iterator it;
    string list("");

    if( this->GetOperatorCount('-') > 0) 
        list = list + string("-");

    if( this->GetOperatorCount('+') > 0) 
        list = list + string("+");

    return list;
}

int Eval::Evaluate(){
    int rezult = 0;
    int semn = 1;
    string::iterator it;

    for(it = this->expr.begin(); it != this->expr.end(); it++){
        char c = (char)(*it);
        switch (c) {
            case '-':
                semn = -1; 
                break;

            case '+':
                semn = 1; 
                break;
            default:
                int numar = c - '0';
                rezult += semn * numar;
                break;
        }
    }
    return rezult;
}


