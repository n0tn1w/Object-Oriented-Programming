# Обект, който се държи като функция

Искаме клас, който се държи като функция. 
- да приема стойност/или не
- да има return type
- да има контекст за фунцкита във самия клас, това са допълнителни член-данни в класа, които позволяват правилната работа на ф-цията

*Пр:*

```c++
class FunctionWithContext {

private:

    int a;
    int b;
    int c;

public:

    int operator()(int val) {
        return (a * b * c) / val;
    }

};
```

Тук *a*, *b*, *c* са част от контекста на класа.

## Критерий 

Искаме клас, който подържа както function pointer-и така и класове, които се държат като функции.

Трябва ни клас
- който кара обектите които го използват да имат имплементиран:
 
```c++
void operator()(int val) const;
```
- който подържа различни типове

## Решение

Този проблем се решава с ___темплейтен клас___.

```c++
template <class T>
class Function {

public:

    Function(const T& data) {
        _data = data;
    }

    void operator()(int val) {
        _data(val);
    }

private:

    T _data;

};
```

## Използване на класа

Може да го използваме клас ___Function___ с:

1. Класове:

```c++
struct Example {

    void operator()(int val) {
        cout << "Example " << val << endl;
    }
};
```

```c++
Function<Example> f1{Example()};
```

2. Function pointer-и:

```c++
void func(int val) {
    cout << "Func " << val << endl;
}
```

```c++
Function<void(*)(int)> f2{func};
```

3. Lambda функции:

```c++
Function<void(*)(int)> f3{[](int x){ cout << "Lambda " << x << endl;}};
```

<hr>
__НЕ__ можем да използваме клас ___Function___ с класове(функции), които нямат предефиниран този оператор:

```c++
void operator()(int val) const;
``` 

*Пр:*
```c++
struct WrongExample {
    void operator()(int val, int n) {
        cout << "Not reached" << endl;
    }
};
```

```c++
Function<WrongExample> f4{WrongExample()};
f4();
```
<span style="color: red;"><strong>COMPILE TIME ERROR!</span>