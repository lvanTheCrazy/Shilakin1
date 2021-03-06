#pragma once

#include <check_idiot.h>



class ITC::pipe
{
    //friend std::ostream& operator<<(std::ostream&, const ITC::pipe&); //взял из своего старого проекта, откуда брал тогда не помню
    //переопределяем оператор вывода, позволив ему общаться со всеми частями нашей структуры
private:
    static int sId;
    int id;

public:
    double length;
    int diameter;
    bool under_repair = false;

    int get_id() const; //узнал проблему почему нельзя вывести значение в оператор здесь https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
    static int get_max_id();
    static void kill_sId();
    void set();

    pipe();
    pipe(bool);
    pipe(std::ifstream&);
    ~pipe();
};


std::ostream& operator<<(std::ostream&, const ITC::pipe&);
//по какой-то причине комплилятор отказывает в использовании этого оператора, если он friend внутри struct и сам struct в namespace('ошибка: undefined reference to `ITC::operator<<(std::ostream&, ITC::pipe const&)')
std::ofstream& operator<<(std::ofstream&, const ITC::pipe&);
