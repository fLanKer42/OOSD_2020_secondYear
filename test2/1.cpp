#include <iostream>
#include <string>

using namespace std;

class publication {

    protected:
    float price;
    string title;

    public:

    virtual void getData() {
        cout << "Enter the title\n";
        cin >> title;
        cout << "Enter the price\n";
        cin >> price;
    }
    virtual void putData() {
        cout << "The name is: " << title << "\n";
        cout << "The price is: " << price << "\n";
    }
};

class tape : public publication {
    private:
    float playingTime;

    public:

    void getData() {
        cout << "Enter the tape title\n";
        cin >> title;
        cout << "Enter the price\n";
        cin >> price;
        cout << "Enter the playing time\n";
        cin >> playingTime;
    }

    void putData() {
        cout << "The name is: " << title << "\n";
        cout << "The price is: " << price << "\n";
        cout << "The playing time is: "<< playingTime << "\n";
    }
};

class book : public publication {
    private:
    int pageCount;

    public:

    void getData() {
        cout << "Enter the book title\n";
        cin >> title;
        cout << "Enter the price\n";
        cin >> price;
        cout << "Enter the page count\n";
        cin >> pageCount;
    }

    void putData() {
        cout << "The name is: " << title << "\n";
        cout << "The price is: " << price << "\n";
        cout << "The page count is: "<< pageCount << "\n";
    }
};

int main() {
    book drv1;
    tape drv2;
    publication* ptr1, *ptr2;
    ptr1 = &drv1;
    ptr2 = &drv2;
    ptr1->getData();
    ptr1->putData();
    ptr2->getData();
    ptr2->putData();
}
