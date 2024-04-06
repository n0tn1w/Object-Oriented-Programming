**1. Problem** <br>
Комплексни числа. Събиране(и скалар), изваждаен, умножение(и скалар), деление, оператори за вход и изход
<br>
***Hint:*** Easy task. Create operator += member function that returns a ref to the original object. Then create operator + as outside funciton. Ostream << and istream >> should be friends for good OOP practice. 
<br>
**2. Problem** <br>
Реализирайте клас Nvector, който ще се използва за работа с математически вектор. Предефинирайте оператори със следната функционалност:
Събиране на вектори.
Изваждане на вектори.
Умножение на вектор със скалар.
Проверка дали два вектора са успоредни.
Проверка дали два вектора са перпендикулярни.
Взимане на дължина на вектор.
Достъп до произволен елемент на вектор.
Вход и изход от потоци.
<br>
***Hint:***  Only hard part is to calculate if there are orthogonal. We need to vector multiply one with the other ( (1,2) . (3,-6) = 2*3 + 1*(-6)) if this equals to 0 that means they are orthogonal.
To check for parallelity you need to find the ratio between the elements in this case 2. (1, 2, 3), (2, 4, 6). Check if the doubles are equal smarter
