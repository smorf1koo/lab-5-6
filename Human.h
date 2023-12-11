//
// Created by Admin on 02.12.2023.
//

#ifndef LAB_5_6_HUMAN_H
#define LAB_5_6_HUMAN_H
#include<iostream>

using namespace std;

class Human{
private:
    string name, race, country, gender;
//    bool gender;
    unsigned int age, iq;
public:
    Human();
    Human(string, string, string, unsigned int, string, unsigned int);
    Human(Human &);
    ~Human();


    void print_name(){ cout << "Name: " << name << '\n';}
    void print_race(){ cout << "Race: " << race << '\n';}
    void print_country(){ cout << "Country: " << country << '\n';}
    void print_gender(){ cout << "Gender: " << gender << '\n';}
    void print_age(){ cout << "Age: " << age << '\n';}
    void print_iq(){ cout << "Iq: " << iq << '\n';}

    [[nodiscard]] string get_race() const { return race;}
    [[nodiscard]] unsigned int get_iq() const{ return iq;}
    [[nodiscard]] unsigned int get_age() const{ return age;}
    [[nodiscard]] string get_country() const{ return country;}

    [[maybe_unused]]void change_name(string _name){name = _name;} // "vevve" -- > ""
    [[maybe_unused]]void change_gender(string _gender){gender = _gender;}
    [[maybe_unused]]void change_race(string _race){race = _race;}
    [[maybe_unused]]void change_age(unsigned int _age){age = _age;}
    [[maybe_unused]]void change_country(string _country){country = _country;}
    [[maybe_unused]]void change_iq(unsigned int _iq){iq = _iq;}

};
Human::Human(string _name, string _gender, string _race, unsigned int _age, string _country, unsigned int _iq)
        : name(_name), gender(_gender), race(_race), age(_age), country(_country), iq(_iq){

}

Human::Human(){
    name = "Gleb Petrov", gender = "male", race = "Rus", age = 10; country = "Russia", iq = 200;
}

Human::Human(Human &other){
    name = other.name;
    gender = other.gender;
    race = other.race;
    age = other.age;
    country = other.country;
    iq = other.iq;
}

Human::~Human(){
//    cout << "Destructor called\n";
}
#endif //LAB_5_6_HUMAN_H
