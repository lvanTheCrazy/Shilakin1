#include <pipe.h>
using namespace ITC;
using namespace std;

int pipe::sId = 0;

pipe::pipe():id(sId++){
    length = 100;
    diameter = 1400; //mm
}


pipe::pipe(bool change):pipe::pipe(){
    if (!change) return;
    else {
        length=check_idiot("length");
        diameter=check_idiot("diameter");
        under_repair = ITC::check_ans("under repair?");
        return;
    }
}

pipe::pipe(std::ifstream& ifs):id(sId++){
    using namespace std;
    string str;


    getline(ifs, str, '|');//взяли id

    getline(ifs, str, '|');
    length=stod(str);

    getline(ifs, str, '|');
    diameter=stoi(str);

    getline(ifs, str, '|');
    under_repair=str=="1";

    return;
}


void pipe::set(){
    length=check_idiot("length");
    diameter=check_idiot("diameter");

    under_repair = ITC::check_ans("under repair?");

    return;
}


int pipe::get_id() const{
    return id;
}

int pipe::get_max_id(){
    return pipe::sId;
}

void pipe::kill_sId(){
    pipe::sId = 0;
    return;
}

pipe::~pipe(){
    //std::cout<<"pipe id"<<id<<" is destructured"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const pipe& mypipe){
    os << "\npipe id" << mypipe.get_id()
       << "\n"<<(mypipe.under_repair ? "is":"is not")
       << " under repair\nlength:\t\t" << mypipe.length
       << "\ndiameter:\t"<< mypipe.diameter << "\n\n";

    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const pipe& mypipe){
    string ans = "P"
                + to_string(mypipe.get_id())+"|"
                +to_string(mypipe.length)+"|"
                +to_string(mypipe.diameter)+"|"
                +(mypipe.under_repair? '1':'0')+"|\n";

    if(mypipe.get_id()==mypipe.get_max_id()-1){
        ans = ans+"end";
    }

    ofs << ans;
    return ofs;
}
