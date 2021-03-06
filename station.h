#pragma once

#include <check_idiot.h>

class ITC::station
{
private:
    static int sId;

    int id;
public:
    std::string name;
    int quantity;
    int quantity_in_work;
    double efficiency;

    int get_id() const;

    static int get_max_id();
    static void kill_sId();
    void set();


    station();
    station(bool);
    station(std::ifstream&);
    ~station();
};

std::ostream& operator<<(std::ostream&, const ITC::station&);
//аналогично pipe
std::ofstream& operator<<(std::ofstream&, const ITC::station&);
std::ifstream& operator>>(std::ifstream&, ITC::station&);

