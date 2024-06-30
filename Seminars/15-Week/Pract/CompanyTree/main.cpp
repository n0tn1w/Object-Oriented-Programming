#include "Manager.h"

int main() {

    Manager* ceo = new Manager{"CEO", "petyr", 10'000};
    
    Manager* manager1 = new Manager{"Manager1", "dobri", 5'000};
    Manager* manager2 = new Manager{"Manager2", "jivko", 5'200};

    Employee* empl1 = new Employee{"dani", 3'000};
    Employee* empl2 = new Employee{"vesko", 2'750};
    Employee* empl3 = new Employee{"simo", 2'500};

    manager1->addSubordinate(empl1);
    manager1->addSubordinate(empl2);
    manager2->addSubordinate(empl3);

    ceo->addSubordinate(manager1);
    ceo->addSubordinate(manager2);

    ceo->print();
}