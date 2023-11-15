#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <list>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)

const int COUNT_OF_STOPS = 5;
const int COUNT_OF_BUS = 4;
const int COUNT_OF_NAMES = 8;
const string NUMBERS[COUNT_OF_BUS]{"aa234a","o349oa","a235aa","a899ao"};
const string STOPS[COUNT_OF_STOPS]{ "Asd", "Wu32", "tr24", "sv28", "sdf" };
const string NAMES[COUNT_OF_NAMES]{
    "Vasia", "Oleg","Olga","Kirill","Misha","Anna","Polka","Ivan"
};


class Human {
    string name;
public:
    Human(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};

class PullHuman {
    vector<Human> humansPull;
public:
    PullHuman(int count) {
        for (int i = 0; i < count; i++) {
            humansPull.push_back(Human(NAMES[random(0, COUNT_OF_NAMES - 1)]));
        }
    }
    void showAll() {
        for (auto i : humansPull) {
            cout << i.getName() << " ";
        }
    }
};



class Bus {
private:
    string number;
    queue<Human> passangers;
    int revenue=0;
    int avgSpeed = 40;
    int placesCount;
    
    static int count;
public:
    Bus(int plCount) {
        this->placesCount = plCount;
        if (count >= COUNT_OF_BUS) throw "not enought bus in garage";
        number = NUMBERS[Bus::count++];
        cout << " created: " << showInfo()<<endl;

    }

    string showInfo() {
        return "number: " + number + " places: " + to_string(placesCount);
    }

};

int Bus::count = 0;

class Route {
private:
    list<BusStop> listBusStop;
    list<int> listDistanceOfStop;
    int countOfBusStop;
public:
    Route(int countOfBusStop) {
        this->countOfBusStop = countOfBusStop;

    }
};

class BusStop {
private:
    string nameStop;
    int distanceByNext=0;
    queue<Human> passangers;
    static int maxCountOfPeople;
    static int count;

public:
    BusStop() {
        if (count >= COUNT_OF_STOPS) throw "Not free places for bus stop";
        nameStop = STOPS[BusStop::count++];
        cout << "created bus stop: " << ShowInfo() << endl;
    }
    string ShowInfo() {
        return nameStop;
    }
};
int BusStop::count = 0;
int BusStop::maxCountOfPeople = 10;


int main()
{
    srand(time(NULL));
    try {
        Bus b1(20);
        Bus b2(10);
        Bus b3(30);
        Bus b4(10);
        Bus b5(25);
    }
    catch (const char* e) {
        cout << e << endl;
    }

    try {
        BusStop stop1;
        BusStop stop2;
        BusStop stop3;
        BusStop stop4;
        BusStop stop5;
        BusStop stop6;
    }
    catch (const char* e) {
        cout << e << endl;
    }
    PullHuman humans(100);
    //humans.showAll();


    
    
}

