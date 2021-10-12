#include <iostream>
#include <cmath>
using namespace std;

class Animal {
    public:
        string name;
        string species;
        string description;
        double weightKg;
        double heightM;
        bool isPredator;
        double speedKph;
        string urlPic;
        string registerDate;
        double activityMultiplier = 1.2;
        Animal(string name, string species, string description, double weightKg, double heightM, bool isPredator, double speedKph, string urlPic, string registerDate) {
            this->name = name;
            this->species = species;
            this->description = description;
            this->weightKg = weightKg;
            this->heightM = heightM;
            this->isPredator = isPredator;
            this->speedKph = speedKph;
            this->urlPic = urlPic;
            this->registerDate = registerDate;
        }
        string getStateString() {
            return "name: " + this->name + " species: " + this->species + " description: " + this->description + " weightKg: " + to_string(this->weightKg) + " heightM: " + to_string(this->heightM) + " isPredeter: " + to_string(this->isPredator) + " speedKph: " + to_string(this->speedKph) + " urlPic: " + this->urlPic + " registerDate: " + this->registerDate;
        }
        double getBmi() {
            return this->weightKg / (this->heightM * this->heightM);
        }
        double getDailyCalories() {
            return (70 * pow(this->weightKg, 0.75) * this->activityMultiplier);
        }
        bool isDangerous() {
            return this->isPredator || this->heightM > 1.7 || this->speedKph >= 35;
        }
        bool isFaster(Animal animal) {
            return this->speedKph > animal.speedKph;
        }
};

int main() {
    Animal rabbit("rabbit", "leporidae", "Rabbits are small mammals in the family Leporidae of the order Lagomorpha (along with the hare and the pika).", 10, 0.3, false, 20, "img1", "2020/5/25");
    cout << rabbit.isDangerous() << endl;
    cout << rabbit.getStateString() << endl;
    cout << rabbit.getDailyCalories() << endl;

    Animal elephant("elephant", "Elephantidae", "Elephants are mammals of the family Elephantidae and the largest existing land animals.", 300, 3, false, 5, "img2", "2020/5/26");
    cout << elephant.isDangerous() << endl;
    cout << elephant.getBmi() << endl;
    cout << elephant.getDailyCalories() << endl;
    cout << elephant.isFaster(rabbit) << endl;
    return 0;
}
