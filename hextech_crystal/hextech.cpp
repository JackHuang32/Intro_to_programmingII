#include<iostream>
#include<cmath>
using namespace std;
class Function
{
    public:
    static Function *parse(stringstream &ss); // this has been implemented
    virtual Function *differential() = 0;
    virtual double eval(double) = 0;
};

class Constant : public Function
{
    private:
    double value;
	Constant(double n)
    {
        value = n;
    }
    public:
    
	static Constant *create(double n)
    {
        return new Constant(n);
    }
	Function *differential() override
    {
        return new Constant(0);
    }
	double eval(double num) override
    {
        return value;
    }
};

class Variable : public Function
{
    private:
    string var;
	public:
	Variable(string str)
    {
        var = str;
    }
    static Variable *create(string s)
    {
        return new Variable(s);
    }
	Function *differential() override
    {
        return Constant::create(1);
    }
	double eval(double n) override
    {
        return n;
    }
};

class Polynomial : public Function
{
    private:
    Function* base;
    Function* exp;
    Polynomial(Function* base_,Function*exp_):base{base_},exp{exp_}{}
	public:
	static Polynomial *create(Function * base_, Function *exp_)
    {
        return new Polynomial(base_,exp_);
    }
	Function *differential() override;
	double eval(double n) override
    {
        return pow(base->eval(n),(exp->eval(n)));
    }
    
};

class Arithmetic : public Function
{
    private:
    Function* F1;
    Function* F2;
    char op;
	Arithmetic(Function* F1_,char op_,Function* F2_):F1{F1_},F2{F2_},op{op_}{}
    public:
	static Arithmetic *create(Function *F1_, char op_, Function*F2_)
    {
        return new Arithmetic(F1_,op_,F2_);
    }
	Function *differential() override
    {
        if(op == '+'||op == '-')
        {
            return create(F1->differential(),op,F2->differential());
        }
        else if(op == '*')
        {
            Function* first = new Arithmetic(F1->differential(),'*',F2);
            Function* second = new Arithmetic(F1,'*',F2->differential());
            return new Arithmetic(first,'+',second);
        }
        else if(op == '/')
        {
            Function* first = new Arithmetic(F1->differential(),'*',F2);
            Function* second = new Arithmetic(F1,'*',F2->differential());
            Function* numer = new Arithmetic(first,'-',second);
            Function* denom = new Arithmetic(F2,'*',F2);
            return new Arithmetic(numer,'/',denom);
        }
    }
	double eval(double num) override
    {
        if(op == '+')
        {
            return F1->eval(num) + F2->eval(num);
        }
        if(op == '-')
        {
            return F1->eval(num) - F2->eval(num);
        }
        if(op == '*')
        {
            return F1->eval(num) * F2->eval(num);
        }
        if(op == '/')
        {
            return F1->eval(num) / F2->eval(num);
        }
    }
};

class Sin : public Function
{
    private:
    Function* arg;
    Sin(Function* arg_)
    {
        arg = arg_;
    }
	public:
	static Sin *create(Function *F)
    {
        return new Sin(F);
    }
	Function *differential() override;
	double eval(double num) override
    {
        return sin(arg->eval(num));
    }
};

class Cos : public Function
{
    private:
    Function* arg;
    Cos(Function* arg_)
    {
        arg = arg_;
    }
	public:
	static Cos *create(Function *F)
    {
        return new Cos(F);
    }
	Function *differential() override;
	double eval(double num) override
    {
        return cos(arg->eval(num));
    }
};
Function* Polynomial::differential()
{
    return Arithmetic::create(
                            exp,
                            '*',
                            Arithmetic::create(
                                new Polynomial(
                                    base,Constant::create(exp->eval(0)-1)
                                    ),
                                '*',
                                base->differential()
                                )  
                            );

}
Function* Sin::differential()
{
    return Arithmetic::create(
            Cos::create(arg),
            '*',
            arg->differential()
    );
}
Function* Cos::differential()
{
    return Arithmetic::create(
            Arithmetic::create(
                Sin::create(arg),
                '*',
                Constant::create(-1)
            ),
            '*',
            arg->differential()
    );
}
