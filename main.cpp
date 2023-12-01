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

void country_by_average_iq(const Human *humanArray, size_t size){
    // создадим матрицу 1 на size (здесь будем хранить множество названий стран)
    string countries[size];
    unsigned int count_countries = 0;
    // матрица 2 на m, где первая строка - сумма iq жителей конкретной страны, вторая строка - кол-во жителей конкретной страны
    unsigned int array[2][size];
    for (int i=0; i < size; i++){ //проходимся по массиву обьектов
        string object_country;
        object_country = humanArray[i].get_country();
        // пройдем по массиву countries, если страна уже дописана, то дополним столбец найденной старны в array
        bool flag=false; //допустим что страна не добавлена
        for (int j=0; j<size; j++){
            if (countries[j] == object_country){
                flag = true;
                array[0][j] += humanArray[i].get_iq();
                array[1][j] += 1;
                break;
            }
        }
        if (!flag){ //если страна не записана, то добавим ее и инициализируем столбец array
            countries[count_countries] = object_country;
            array[0][count_countries] = humanArray[i].get_iq();
            array[1][count_countries] = 1;
            count_countries++;
        }
    }
    // вывод
//    for (int i = 0; i < size; i++){
//        cout << countries[i] << ' ';
//    }
//    cout << '\n';
//    for (int i=0; i < 2; i++){
//        for (int j=0; j<count_countries; j++){
//            cout << array[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    //сортировка
    for (int i=0; i < count_countries-1; i++){
        for (int j=0; j < count_countries-i-1; j++){
            double average_iq1 = array[0][j+1]/double(array[1][j+1]), average_iq2 = array[0][j]/double(array[1][j]);
            if (average_iq1 > average_iq2){
                unsigned int temp1, temp2;
                string temp3;
                temp1 = array[0][j+1];
                temp2 = array[1][j+1];
                temp3 = countries[j+1];
                array[0][j+1] = array[0][j];
                array[1][j+1] = array[1][j];
                countries[j+1] = countries[j];
                array[0][j] = temp1;
                array[1][j] = temp2;
                countries[j] = temp3;
            }
        }
    }
    cout << "Counties by average iq (decreasing):\n";
    for (int i = 0; i < size; i++){
        cout << countries[i] << ' ';
    }
    cout << '\n';
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

    country_by_average_iq(humanArray, n);
    return 0;
}