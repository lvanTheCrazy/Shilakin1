#include <check_idiot.h>
using namespace std;

string ITC::check_idiot(vector<string> a, string name_element){

    cout << name_element << "(";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i+1 < a.size()) cout << "/";
    }
    cout << ")\n";
    //перечисляем подходящие значения


    string temp;                      //ввод пользователя
    bool idiot = true;                //по умолчанию пользователь идиот
    cin >> temp;

    for (size_t i = 0; i < a.size() && idiot; i++){
        if (temp == a[i]) idiot = false; //если ответ пользователя совпадает с желаемым, он не идиот
    }

    if(idiot){
        cout << "ERROR: wrong value!\n";
        return ITC::check_idiot(a, name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return temp; //верни значение пользователя
    }
}

double ITC::check_idiot(string name_element){
    double input;
    bool valid= false;
    do
    {
        cout << "Enter a number of " << name_element << endl;
        cin >> input;
        if (cin.good()){
            valid = true;
        }
        else{

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: wrong value! Please re-enter." << endl;
        }
    } while (!valid);

    return input;

}

bool ITC::check_ans(std::string q){
    bool tans = false;
    std::string ans = ITC::check_idiot(ITC::yes, q);
    for (size_t i = 0; i < ITC::yes.size(); i) {
        if (ITC::yes[i] == ans) tans = true;
        i+=2; //каждый четный элемент это правда
    }
    return tans;
}

int ITC::menu(){
    vector<string> q = {"1-add pipe","2-add station","3-see all","4-edit pipe","5-edit station","6-save","7-load","0-exit"};

    cout << "options: ";
    for (auto t: q){
        cout << t << ", ";
    }
    cout << endl;
    return check_idiot("choose option");
}


//int ITC::max_row(std::string link){
//    using namespace std;
//    ifstream fin(link);

//    if(fin.is_open()){
//        int num_rows = 0;

//        string trash;
//        while (getline(fin, trash)) num_rows++;
//        fin.close();

//        return num_rows;
//    }
//    else {
//        cout << "ERROR: invalid file name!\n";
//        return 0;
//    }
//}


