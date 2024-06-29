#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using std::cout;
using std::endl;

struct Expr {
    int _val;

    Expr& operator+=(const Expr& other) {
        _val += other._val;
        return *this;
    }

    Expr& operator-=(const Expr& other) {
        _val -= other._val;
        return *this;
    }

    Expr& operator*=(const Expr& other) {
        _val *= other._val;
        return *this;
    }

    Expr& operator/=(const Expr& other) {
        _val /= other._val;
        return *this;
    }
};

class Command {
protected:
    Expr& _expr;
public:
    Command(Expr& expr) : _expr(expr) { } 

    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class Add : public Command {
    const Expr* _snapshot;
public:
    Add(Expr& expr, Expr* newExpr) : Command(expr) {
        _snapshot = newExpr;
    }

    void execute() override {
        _expr += *_snapshot;
    }

    void undo() override {
        if(_snapshot) {
            _expr -= *_snapshot;
        }
    }

};

class Mutiply : public Command {
    const Expr* _snapshot;
public:
    Mutiply(Expr& expr, Expr* newExpr) : Command(expr) {
        _snapshot = newExpr;
    }

    void execute() override {
        _expr *= *_snapshot;
    }
    
    void undo() override {
        if(_snapshot) {
            _expr /= *_snapshot;
        }
    }
};

class CommandFactory {
public:
    static Command* create(Expr& c, char op, int val) {
        if(op = '+') {
            return new Add(c, new Expr{val});
        } else if(op = '*') {
            return new Mutiply(c, new Expr{val});
        }
    }
};

class Container {

    std::queue<Command*> _toBeExecuted;
    std::stack<Command*> _alreadyExecuted;

public:

    void add(Command* cmd) {
        _toBeExecuted.push(cmd);
    }
    void execute() {
        Command* cmd =_toBeExecuted.front();
        cmd->execute();
        _toBeExecuted.pop();
        _alreadyExecuted.push(cmd);
    }

    void undo() {
        Command* cmd =_alreadyExecuted.top();
        cmd->undo();
        _alreadyExecuted.pop();
        delete cmd;
    }

	Container() = default;
	Container(const Container&) = delete;
	Container& operator=(const Container&) = delete;
    ~Container() {
        while (!_toBeExecuted.empty()) {
            delete _toBeExecuted.front();
            _toBeExecuted.pop();
        }
        while (!_alreadyExecuted.empty()) {
            delete _alreadyExecuted.top();
            _alreadyExecuted.pop();
        }
    }
};

int main() {
    Expr n{0};

    Container c;
    c.add(CommandFactory::create(n, '+', 3));
    c.add(CommandFactory::create(n, '*', 3));
    c.add(CommandFactory::create(n, '+', 10));
    c.add(CommandFactory::create(n, '*', 2));

    c.execute();
    cout << n._val << endl;
    c.execute();
    cout << n._val << endl;
    c.undo();
    cout << n._val << endl;
    c.execute();
    cout << n._val << endl;
    c.undo();
    cout << n._val << endl;
}