#include <iostream>
using namespace std;

class Product {
    public:
        string title;
        double price;
        Product(string title, double price) {
            this->title = title;
            this->price = price;
        }
};

class InvoiceItemNode {
    public:
        int quantity;
        // オブジェクトはポインタを渡すため、ポインタ型になる
        Product* product;
        InvoiceItemNode* next;
        InvoiceItemNode(int quantity, Product* product) {
            this->quantity = quantity;
            this->product = product;
            this->next = NULL;
        }
        double getTotalPrice() {
            return this->product->price * this->quantity;
        }
};

class Invoice {
    public:
        string invoiceNumber;
        string invoiceDate;
        string company;
        string companyAddress;
        string billToName;
        string billToAddress;
        InvoiceItemNode* invoiceItemHeadNode;
        Invoice(string invoiceNumber, string invoiceDate, string company, string companyAddress, string billToName, string billToAddress) {
            this->invoiceNumber = invoiceNumber;
            this->invoiceDate = invoiceDate;
            this->company = company;
            this->companyAddress = companyAddress;
            this->billToName = billToName;
            this->billToAddress = billToAddress;
            this->invoiceItemHeadNode = NULL;
        }
        double amountDue(bool taxes) {
            // 連結リストに存在するデータを繰り返し実行して合計を計算
            InvoiceItemNode* currentNode = this->invoiceItemHeadNode;
            double sum = 0;
            while(currentNode != NULL) {
                sum += currentNode->getTotalPrice();
                currentNode = currentNode->next;
            }
            return (taxes == true) ? sum * 1.1 : sum;
        }
        void printBuyingItems() {
            InvoiceItemNode* currentNode = this->invoiceItemHeadNode;
            while(currentNode != NULL) {
                cout << "item :" << currentNode->product->title << ", price :" << to_string(currentNode->getTotalPrice()) << ", quantity:" << currentNode->quantity << endl;
                currentNode = currentNode->next;
            }
        }
        void printInvoice() {
            cout << "Invoice" << endl;
            cout << "No. : " + this->invoiceNumber << endl;
            cout << "INVOICE DATE : " + this->invoiceDate << endl;
            cout <<  "SHIP TO : " + this->company << endl;
            cout << "ADDRESS : " + this->companyAddress << endl;
            cout << "BILL TO : " + this->billToName << endl;
            cout << "ADDRESS : " + this->billToAddress << endl;
            this->printBuyingItems();
            cout << "SUBTOTAL : " + to_string(this->amountDue(false)) << endl;
            cout << "TAX : " + to_string(this->amountDue(true) - this->amountDue(false)) << endl;
            cout << "TOTAL : " + to_string(this->amountDue(true)) << endl;
        }
};

int main() {
    Product product1("shampoo", 10);
    Product product2("conditioner", 5);
    Product product3("tooth brush", 3);

    // Productのアドレスを渡すことでポインタ型のメンバ変数を初期化できる
    InvoiceItemNode* firstItem = new InvoiceItemNode(7, &product1);
    InvoiceItemNode* secondItem = new InvoiceItemNode(7, &product2);
    firstItem->next = secondItem;
    InvoiceItemNode* thirdItem = new InvoiceItemNode(10, &product3);
    secondItem->next = thirdItem;

    Invoice* invoice = new Invoice("UC1234567890", "2020/05/06", "Recursion", "Los Angles", "Steven", "Dallas");
    invoice->invoiceItemHeadNode = firstItem;

    invoice->printBuyingItems();
    invoice->printInvoice();

    return 0;
}