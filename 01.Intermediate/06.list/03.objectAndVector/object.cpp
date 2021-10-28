#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
    public:
        string species;
        double weightKg;
        double heightM;
        bool predator;

        Animal(string species, double weightKg, double heightM, bool predator) {
            this->species = species;
            this->weightKg = weightKg;
            this->heightM = heightM;
            this->predator = predator;
        }

        void domesticate() {
            this->predator = false;
        }
};

void printAnimal(Animal animal) {
    cout << "The animal species is: " + animal.species + ". It's weight is: " + to_string(animal.weightKg) + "kg and its height is: " + to_string(animal.heightM) + "m. " + ((animal.predator) ? "It is a predator!" : "It is a peaceful animal.") << endl;
}

class Hunter {
    public:
        string name;
        double weightKg;
        double heightM;
        double strength;
        double cageCubicMeters;

        Hunter(string name, double weightKg, double heightM, double strength, double cageCubicMeters) {
            this->name = name;
            this->weightKg = weightKg;
            this->heightM = heightM;
            this->strength = strength;
            this->cageCubicMeters = cageCubicMeters;
        }
        bool canCaptureAnimal(Animal animal) {
            return this->strengthKg() > animal.weightKg && this->cageCubicMeters > animal.heightM && !animal.predator;
        }
        bool attemptToDomesticate(Animal animal) {
            /// ハンターが動物の体重より2倍以上重ければ、その動物を飼い慣らすことができます。
            if(this->weightKg <= animal.weightKg * 2) return false;
            animal.domesticate();
            return true;
        }
        double strengthKg() {
            return this->strength * this->strength;
        }
};

void printAnimal(Animal animal){
    cout << "The animal species is: " + animal.species + ". It's weight is: " + to_string(animal.weightKg) + "kg and its height is: " + to_string(animal.heightM) + "m. " + ((animal.predator) ? "It is a predator!" : "It is a peaceful animal.") << endl;
}

void printHunter(Hunter hunter){
    cout << "The hunter's name is: " + hunter.name + ". This hunter can carry: " + to_string(hunter.strengthKg()) + "kg and has a cage " + to_string(hunter.cageCubicMeters) + " cubic meters wide" << endl;
}

string canHunterCaptureAnimalString(Hunter hunter, Animal animal){
    return string("Can ") + hunter.name + " capture " + animal.species + "? The answer is..." + (hunter.canCaptureAnimal(animal) ? "Yes" : "No");
}

string canHunterDominateAnimalString(Hunter hunter, Animal animal){
    return string("Will ") + hunter.name + " be able to domesticate the " + animal.species + "? The answer is..." + (hunter.attemptToDomesticate(animal) ? "Yes" : "No");
}

int main() {

    Animal tiger1("Tiger", 290, 2.6, true);
    Animal bear1("Bear", 250, 2.8, true);
    Animal snake1("Snake", 250, 12.8, true);
    Animal dog1("Dog", 90, 1.2, false);
    Animal cat1("Cat", 40, 0.5, false);
    Animal cow1("Cow", 1134, 1.5, false);
    Animal fox("Fox", 5, 0.7, false);

    printAnimal(tiger1);
    printAnimal(bear1);
    printAnimal(cat1);

    printAnimal(fox);

    cout << "Time to tame the tiger..." << endl;
    // tigerの状態を捕食者から変えてみましょう。
    tiger1.domesticate();
    printAnimal(tiger1);

        // hunternatorは強いハンターです。
    Hunter hunternator ("Hunternator", 30, 124.73, 1.85, 15, 3);
    Hunter hunterChild ("Hunter Child Of The Small Giants", 10, 50, 1.2, 0.6, 1);

    // 他のハンターを作成してみましょう。
    printHunter(hunternator);
    printHunter(hunterChild);
}