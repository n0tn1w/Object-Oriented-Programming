#include <iostream>
using std::cout;
using std::endl;

class BoolInterpret {
public:
    BoolInterpret() {
    };

    bool getCharAt(size_t idx) const {
        return _data[idx];
    }
    void setCharAt(char idx) {
        _data[idx - 'a'] = true;
    }
    void removeCharAt(char idx) {
        _data[idx - 'a'] = false;
    }
    size_t getCount() const {
        size_t cnt = 0;
        for(size_t i = 0; i < 26; i++) {
            if(_data[i])
                ++cnt;
        }
        return cnt;
    }
    void print() const {
        for(size_t i = 0; i < 26; i++) {
            if(_data[i])
                cout << (char)('a' + i);
        }
    }

private:
    bool _data[26] { false };
};

class Expr {
public:
    virtual Expr* clone() const = 0;
    virtual bool eval(const BoolInterpret&) const = 0;
    virtual ~Expr() = default;
    virtual void getVariable(BoolInterpret*) const = 0;
    virtual void print() const = 0;
};

class Var : public Expr {
public:

    Var(char ch) : _ch(ch) {}
    Expr* clone() const {
        return new Var(*this);
    }
    bool eval(const BoolInterpret& bi) const override {
        return bi.getCharAt(_ch - 'a');
    }
    void getVariable(BoolInterpret* bi) const override {
        bi->setCharAt(_ch);
    } 
    void print() const override {
        cout << _ch;
    }

private:
    char _ch;
};

class UnaryExpr : public Expr {
public:
    UnaryExpr(Expr* expr) : _expr(expr) { }
    void getVariable(BoolInterpret* bi) const override {
        _expr->getVariable(bi);
    } 
public:
    Expr* _expr = nullptr;
};

class Negate : public UnaryExpr {
public:
    Negate(Expr* expr) : UnaryExpr(expr) { }

    Expr* clone() const override{
        return new Negate(*this);
    }
    bool eval(const BoolInterpret& bi) const override{
        return ! (_expr->eval(bi));
    }
    void print() const override {
        cout << "( ! ";
        _expr->print();
        cout << ")";
    }

};

class BinaryExpr : public Expr {
public:

    BinaryExpr(Expr* left, Expr* right) : _left(left), _right(right) { }
    void getVariable(BoolInterpret* bi) const override {
        _left->getVariable(bi);
        _right->getVariable(bi);
    } 

protected:
    Expr* _left = nullptr;
    Expr* _right = nullptr;
};

class Conjunction : public BinaryExpr {
public:
    Conjunction(Expr* left, Expr* right) : BinaryExpr(left, right) { }
    Expr* clone() const {
        return new Conjunction(*this);
    }
    bool eval(const BoolInterpret& bi) const override {
        return _left->eval(bi) && _right->eval(bi);
    }
    void print() const override {
        cout << "( ";
        _left->print();
        cout << " & ";
        _right->print();
        cout << " )";
    }
};

class Disjunction : public BinaryExpr {
public:
    Disjunction(Expr* left, Expr* right) : BinaryExpr(left, right) { }
    Expr* clone() const {
        return new Disjunction(*this);
    }
    bool eval(const BoolInterpret& bi) const override {
        return _left->eval(bi) || _right->eval(bi);
    }
    void print() const override {
        cout << "( ";
        _left->print();
        cout << " | ";
        _right->print();
        cout << " )";
    }
};

bool isTautology(Expr* expr) {
    BoolInterpret* bi = new BoolInterpret();
    expr->getVariable(bi);

    size_t totalCnt = bi->getCount();
    size_t variations = ( 1 << totalCnt ) - 1;

    for(size_t i = 0; i < variations; i++) {
        size_t currVar = i;
        BoolInterpret biCpy = BoolInterpret(*bi);

        for(int k = 25; k >= 0; k--) {
            if(bi->getCharAt(k)) {
                if(currVar % 2 != 0) {
                    biCpy.removeCharAt('a'+ k);
                }
                currVar /= 2;
            }
        }

        if(!expr->eval(biCpy))
            return false;
    }
    return true;
}   

int main() {
    // (p&q)|t
    Expr* rel = new Disjunction(new Conjunction(new Var('p'), new Var('q')), new Var('t'));
    Expr* tau = new Disjunction(new Negate(new Var('p')), new Var('p'));
    BoolInterpret* let = new BoolInterpret();
    rel->getVariable(let);
    //let->print();
    //rel->print();

    cout << "Tau:" << isTautology(rel) << endl;


    BoolInterpret* tauLet = new BoolInterpret();
    tau->getVariable(tauLet);
    cout << "Tau:" << isTautology(tau) << endl;
}