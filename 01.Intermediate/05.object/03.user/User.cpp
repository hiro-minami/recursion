#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

// パスワードのハッシュ関数
class HelperFunction {
    public:
        static string hashPassword(string password){
        int hash = 0;
        for (int i = 0; i < password.length(); i++) {
            char character = password[i];
            hash = ((hash << 5)-hash)+character;
            hash = hash & hash;
        }
        return to_string(abs(hash));
    }
};


class User {
    public:
        string userName;
        string firstName;
        string lastName;
        string email;
        string passwordHashed;
        int birthMonth;
        int birthYear;
        string biographyDescription;
        string favoriteHikingLocation;

        User(string userName, string firstName, string lastName, string email, string password, int birthMonth, int birthYear, string biographyDescription, string favoriteHikingLocation) {
            this->userName = userName;
            this->firstName = firstName;
            this->lastName = lastName;
            this->email = email;
            this->passwordHashed = HelperFunction::hashPassword(password);
            this->birthMonth = birthMonth;
            this->birthYear = birthYear;
            this->biographyDescription = biographyDescription;
            this->favoriteHikingLocation = favoriteHikingLocation;
        }

        string getFullName() {
            return this->firstName + " " + this->lastName;
        }

        int getAge() {
            time_t t = time(nullptr);
            const tm* localTime = localtime(&t);
            return localTime->tm_year - this->birthYear;
        }

        int birthdayCalculator() {
            time_t t = time(nullptr);
            const tm* localTime = localtime(&t);
            int culc = localTime->tm_mon - this->birthYear;
            return (culc > 0) ? culc : culc + 12;           
        }

        string showProfile() {
            return this->userName + "\n" + to_string(this->getAge()) + " years old\n" + this->biographyDescription + "\nfavorite place to hike: " + this->favoriteHikingLocation;
        }

        bool confirmPassword(string passwordString) {
            return this->passwordHashed == HelperFunction::hashPassword(passwordString);
        }
};

int main() {
    User claire("claireS", "Claire", "Simmons", "clairesimmons@gmail.com", "lmnlmn", 9, 2007, "Passionate gamer. Evil internet aficionado. Student. Friendly tv specialist. Introvert.", "Hollywood Sign Hike");
    cout << claire.getFullName() << endl;
    cout << claire.getAge() << endl;
    cout << claire.birthdayCalculator() << endl;
    cout << claire.showProfile() << endl;
    cout << claire.confirmPassword("lmnlmn") << endl;
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
    int culc = localTime->tm_year;
    cout << culc << endl;
    return 0;
}