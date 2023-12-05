#include <iostream>
#include "Human.h"

using namespace std;

double average_iq_by_race(const Human *humanArray, size_t size, const string& target){
    unsigned int count_users = 0, count_iq = 0;
    for (int i=0; i < size; i++){
        if (humanArray[i].get_race() == target){
            count_users++;
            count_iq += humanArray[i].get_iq();
        }
    }
    if (count_users == 0) return -1.0;
    else {
        double average = count_iq / double(count_users);
        return average;
    }
}

double average_age_by_iq (const Human *humanArray, size_t size, const unsigned int n) {
    unsigned int count_users = 0, count_age = 0;
    for (int i = 0; i < size; i++) {
        if (humanArray[i].get_iq() > n) {
            count_users++;
            count_age += humanArray[i].get_age();
        }
    }
    if (count_users == 0) return -1;
    else {
        double average_age;
        average_age = count_age/double(count_users);
        return average_age;
    }
}

struct countries_data{
    string name;
    unsigned int count_people{};
    unsigned int total_iq{};
    double average_iq{};

};

void countries_by_average_iq(const Human *humanArray, size_t size){
    unsigned int count_countries = 1;
    countries_data array[size];
    if (size == 0){
        cerr << "Массив пустой\n";
        exit(1);
    }
    array[0] = {humanArray[0].get_country(), 1, humanArray[0].get_iq(), double(humanArray[0].get_iq())};
    for (int i=1; i < size; i++){
        bool flag = true;
        for (int j=0; j < count_countries; j++){
            if (array[j].name == humanArray[i].get_country()){
                flag = false;
                array[j].count_people++;
                array[j].total_iq += humanArray[i].get_iq();
                array[j].average_iq = array[j].total_iq/double(array[j].count_people);
                break;
            }
        }
        if (flag){ // добавим нашу структуру
            array[count_countries] = {humanArray[i].get_country(), 1, humanArray[i].get_iq(), double(humanArray[i].get_iq())};
            count_countries++;
        }
    }

    // сортировка
    for (int i=0; i < count_countries - 1; i++){
        for (int j=0; j < count_countries - i - 1; j++){
            if (array[i].average_iq < array[i+1].average_iq) {
                countries_data temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    //адекватный выовод
    cout << "Counties by average iq (decreasing):\n";
    for (int i = 0; i < count_countries; i++){
        cout << array[i].name << " ";
    }
    cout << "\n";
}

int main(){
    const size_t n = 10;
    Human humanArray[n] = {
            Human("Ivanov_Ivan_Pavlovich", "male", "europoid", 17, "Russia", 105),
            Human("Ivanova_Olga_Petrovna", "female", "ethiopian", 35, "Germany", 200),
            Human("Sidorov_Artem_Stanislavovich", "male", "mongoloid", 45, "China", 63),
            Human("Kozlov_Vladimir_Aleksandrovich", "male", "americanoid", 67, "USA", 21),
            Human("Vasnetsova_Anna_Grigoryevna", "female", "ethiopian", 91, "Canada", 174),
            Human("Kovalenko_Ekaterina_Sergeevna", "female", "americanoid", 50, "China", 195),
            Human("Aleksandrov_Aleksandr_Aleksandrovich", "male", "europoid", 15, "Russia", 40),
            Human("Sokolova_Tatyana_Nikolaevna", "female", "ethiopian", 62, "USA", 205),
            Human("Nikolaev_Kolya_Victorovich", "male", "mongoloid", 71, "Russia", 15),
            Human("Andreev_Andrey_Andreevich", "male", "mongoloid", 30, "USA", 123)
    };
//    for(size_t i = 0; i < n; i++){
//        cout << "Human " << i+1 << '\n';
//
//        string name, race, country, gender;
//        unsigned int age, iq;
//        cout << "Enter name, gender, race, age, country, iq\n";
//        cin >> name >> gender >> race >> age >> country >> iq;
//
//        humanArray[i] = Human(name,gender, race, age, country, iq);
//    }


    string target_race;
    cout << "Enter target_race\n";
    cin >> target_race;
    cout <<"Average iq race {" << target_race << "} - " << average_iq_by_race(humanArray, n, target_race) << "\n";

    unsigned int target_iq;
    cout << "Enter target_iq\n";
    cin >> target_iq;
    cout <<"Average age people with iq > {" << target_iq << "} - " << average_age_by_iq(humanArray, n, target_iq) << "\n";

    countries_by_average_iq(humanArray, n);
    return 0;
}