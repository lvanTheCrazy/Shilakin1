#include <station.h>
using namespace ITC;

int station::sId = 0;
int station::quantity = 0;
int station::quantity_in_work = 0;

station::station():id(sId++){
    name="basic_station_"+std::to_string(id);
    efficiency =  78.22;
    quantity++;
    return;
}

station::station(bool change):station::station(){
    if (!change) return;
    else {
        std::cout << "name station(no whitespaces)\n";

        std::string temp;
        std::cin>>temp;

        name = temp;

        efficiency = check_idiot("efficiency");

        if (ITC::check_ans("if this station in work?")) {
            quantity_in_work++;
            me_in_work = true;
        }
    }
    return;
}

station::station(std::ifstream& ifs):id(sId++){
    using namespace std;
    string str;

    quantity++;

    getline(ifs, str, '|');//взяли id

    getline(ifs, name, '|');

    getline(ifs, str, '|');
    efficiency=stod(str);

    getline(ifs, str, '|');
    if (str == ITC::yes[0]) {
        me_in_work=true;
        quantity_in_work++;
    }
    else me_in_work=false;

    return;
}


int station::get_id() const{
    return id;
}

int station::get_max_id(){
    return station::sId;
}

void station::kill_sId(){
    station::sId = 0;
    station::quantity=0;
    station::quantity_in_work=0;
    return;
}


void station::set(){
    std::cout << "name station(no whitespaces)\n";

    std::string temp;
    std::cin>>temp;

    name = temp;

    efficiency = check_idiot("efficiency");
    bool tbool = ITC::check_ans("if this station in work?");
    if (tbool && !me_in_work) {
        quantity_in_work++;
        me_in_work = true;
    } else if (!tbool && me_in_work) {
        quantity_in_work--;
        me_in_work = false;
    }
    return;
}

void station::on(){
    if (!me_in_work) {
        quantity_in_work++;
        me_in_work = true;
    }
    std::cout << "station id" << id <<" is on now!\n";
    return;
}

void station::off(){
    if (me_in_work) {
        quantity_in_work--;
        me_in_work = false;
    }
    std::cout << "station id" << id <<" is off now!\n";
    return;
}



station::~station(){
    //std::cout<<"station id"<<id<<" is destructured"<<std::endl;
}


std::ostream& operator<<(std::ostream& os, const station& my_st){

    std::string temp = "is";
    if (!my_st.me_in_work) temp = "not";
    os << "\nstation id" << my_st.get_id() << " 'called "+ my_st.name
       << "\n"+temp+" in work\nefficiency score:\t" << my_st.efficiency
       << "\nall stations count:\t" << my_st.quantity
       << "\nstations in work:\t"<< my_st.quantity_in_work << "\n\n";
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const station& my_st){
    using namespace std;
    string a = ITC::yes[1]; //n
    if (my_st.me_in_work) a = ITC::yes[0];
    string ans = "S"+to_string(my_st.get_id())+"|"+my_st.name+"|"
            +to_string(my_st.efficiency)+"|"+a+"|\n";
    ofs << ans;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, ITC::station& my_st){
    using namespace std;
    string str;

    getline(ifs, str, '|');//взяли id первого

    getline(ifs, my_st.name, '|');//дали имя

    getline(ifs, str, '|');
    my_st.efficiency=stod(str);

    getline(ifs, str, '|');
    if (str == ITC::yes[0]) {
        my_st.on();
    } else {
        my_st.off();
    }

    //getline(ifs, str);
    return ifs;
}
