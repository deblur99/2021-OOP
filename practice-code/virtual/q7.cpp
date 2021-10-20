//
// Created by 한현민 on 2021-10-17.
//

#include <iostream>
#include <string>

using namespace std;

static int figure = 0;

class InkJetPrinter {
private:
    int availableInk;
public:
    InkJetPrinter(int availableInk) {
        this->availableInk = availableInk;
    }
    virtual void print() = 0;
    virtual void show() = 0;
};

class LaserPrinter {
private:
    int availableToner;
public:
    LaserPrinter(int availableToner) {
        this->availableToner = availableToner;
    }
    virtual void print() = 0;
    virtual void show() = 0;
};

class Printer : public InkJetPrinter, public LaserPrinter {
private:
    short type;
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
    int availableMaterial;
public:
    Printer(short type, string model, string manufacturer, int printedCount,
            int availableCount, int availableMaterial)
            : LaserPrinter(availableMaterial), InkJetPrinter(availableMaterial) {
        this->type = type, this->model = model; this->manufacturer = manufacturer;
        this->printedCount = printedCount; this->availableCount = availableCount;
        figure++;
    }

    ~Printer() { figure--; }

    void print() {
        int model, page;
        cout << "Choose printer (1: Inkjet, 2: Laser) and pages >>";
        cin >> model; cin >> page;

        cout << "Printing completed" << endl;

    }

    void show()
        cout << "Currently working " << figure << " printers are below" << endl;

        switch (type) {
            case 0:
                cout << "Inkjet : " << model << ", " << manufacturer <<", Remaining " << availableCount
                << " papers" << ", Remaining " << availableMaterial << " ink" << endl;
                break;

            case 1:
                cout << "Laser : " << model << ", " << manufacturer <<", Remaining " << availableCount
                << " papers" << ", Remaining " << availableMaterial << " paper" << endl;
                break;
        }
    }
};