// hw18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Используя механизм шаблонного наследования создайте иерархию классов. Базовый класс под названием base имеет следующие переменные - члены:
// T1 value1 T2 value2.
// Потомок под названием child содержит дополнительные переменные - члены: T3 value3. T4 value4.
// Потомок под названием child2 добавляет такие переменные - члены : T5 value5. T6 value6.
// Каждый класс имеет необходимый набор конструкторов, деструкторов, функций - членов для работы со структурой класса.
// В main протестировать работу класса.

template <class T1, class T2>
class Base
{
protected:
    T1 value1;
    T2 value2;
public:
    Base()
    {
        value1 = 0;
        value2 = 0;
    }
    Base(T1 value1, T2 value2) : value1(value1), value2(value2) { }

    void Print()
    {
        cout << "value1 = " << value1 << endl << "value2 = " << value2 << endl;
    }
    ~Base() { }
};

template <class T1, class T2, class T3, class T4>
class Child : public Base <T1, T2 >
{
protected:
    T3 value3;
    T4 value4;
public:
    Child()
    {
        value3 = 0;
        value4 = 0;
    }
    Child(T1 value1, T2 value2, T3 value3, T4 value4) : Base(value1, value2), value3(value3), value4(value4) {}

    void Print()
    {
        Base<T1, T2>::Print();
        cout << "value3 = " << value3 << endl << "value4 = " << value4 << endl;
    }
    ~Child() { }
};

template <class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 : public Base <T1, T2 >, public Child < T1, T2, T3, T4>
{
protected:
    T5 value5;
    T6 value6;
public:
    Child2()
    {
        value5 = 0;
        value6 = 0;
    }
    Child2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) : Child(value1, value2, value3, value4), value5(value5), value6(value6) {}

    void Print()
    {
        Base<T1, T2>::Print();
        Child<T1, T2, T3, T4>::Print();
        cout << "Value5 = " << value5 << endl << "Value6 = " << value6 << endl;
    }
    ~Child2() { }
};


void main()
{
    setlocale(LC_ALL, "ru");

    Base <int, int> base(1, 2);
    base.Print();

    Child <int, int, int, int> child(1, 2, 3, 4);
    child.Print();

    Child2 <int, int, int, int, int, int> child2(1, 2, 3, 4, 5, 6);
    child2.Print();
}