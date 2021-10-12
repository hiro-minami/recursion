#include <iostream>
#include <cmath>
using namespace std;

// ランダムに計算するクラス
class RandomHelper {
    public:
        static int getRandomInteger(int max) {
            return rand() % max;
        }
};

class BankAccount {
    public:
        string bankName;
        string ownerName;
        int savings;
        double interestPereDay = 0.010001;
        
        BankAccount(string bankName, string ownerName, int savings) {
            this->bankName = bankName;
            this->ownerName = ownerName;
            this->savings = savings;
        }

        string showInfo() {
            return "name: " + this->bankName + "\n" + "owner name: " + this->ownerName + "\n" + "bank account number: " + to_string(RandomHelper::getRandomInteger(pow(10,8)));
        }

        int depositMoney(int depositAmount) {
            this->savings += (this->savings <= 20000) ? depositAmount - 100 : depositAmount;
            return this->savings;
        }

        int withdrawMoney(int withdrawAmount) {
            double moneyYouCanTake = (withdrawAmount < this->savings*0.2) ? withdrawAmount : this->savings*0.2;
            this->savings -= moneyYouCanTake;
            return (int) moneyYouCanTake;
        }

        double pastime(int days) {
            return this->savings * pow(1 + this->interestPereDay, days);
        }
};

int main() {
    BankAccount user1("Chase", "Claire Simmmons", 30000);
    cout << user1.showInfo() << endl;
    cout << user1.withdrawMoney(1000) << endl;
    cout << user1.depositMoney(10000) << endl;
    cout << user1.pastime(200) << endl;

    BankAccount user2("Bank Of America", "Remy Clay", 10000);
    cout << user2.showInfo() << endl;
    cout << user2.withdrawMoney(5000) << endl;
    cout << user2.depositMoney(12000) << endl;
    cout << user2.pastime(500) << endl;

    return 0;
};