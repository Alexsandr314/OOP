#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXHORSES = 5;
const float FINISH = 10.0; // Дистанция в форлонгах

class track;

class horse {
protected:
    int number;
    float distance;
    track* ptrTrack;
public:
    horse(int n, track* pt) : number(n), distance(0.0), ptrTrack(pt) {}
    virtual void horse_tick() {
        distance += (rand() % 100) / 1000.0;
    }
    float getDistance() const { return distance; }
    int getNumber() const { return number; }
    virtual ~horse() {}
};

class comhorse : public horse {
public:
    comhorse(int n, track* pt) : horse(n, pt) {}
    void horse_tick() override;
};

class track {
private:
    horse* hArray[MAXHORSES];
    int total_horses;
public:
    track() : total_horses(0) {
        srand(time(0));
    }
    void add_horse(horse* h) {
        if (total_horses < MAXHORSES) hArray[total_horses++] = h;
    }
    void run_one_tick() {
        for (int i = 0; i < total_horses; i++) hArray[i]->horse_tick();
    }
    bool all_finished() const {
        for (int i = 0; i < total_horses; i++) {
            if (hArray[i]->getDistance() < FINISH) return false;
        }
        return true;
    }
    void display() const {
        for (int i = 0; i < total_horses; i++) {
            cout << "Лошадь " << hArray[i]->getNumber() << ": " << hArray[i]->getDistance() << " форлонгов\n";
        }
        cout << endl;
    }
    horse* get_horse(int i) const { return hArray[i]; }
    int get_total_horses() const { return total_horses; }
    ~track() {
        for (int i = 0; i < total_horses; i++) delete hArray[i];
    }
};

void comhorse::horse_tick() {
    float max_distance = 0.0;
    int leader = -1;
    for (int i = 0; i < ptrTrack->get_total_horses(); i++) {
        float dist = ptrTrack->get_horse(i)->getDistance();
        if (dist > max_distance) {
            max_distance = dist;
            leader = i;
        }
    }
    if (leader == number - 1 && distance >= FINISH / 2) {
        bool close = false;
        for (int i = 0; i < ptrTrack->get_total_horses(); i++) {
            if (i != number - 1 && max_distance - ptrTrack->get_horse(i)->getDistance() < 0.1) {
                close = true;
                break;
            }
        }
        if (close) {
            distance += (rand() % 100) / 500.0; // Ускорение
        }
        else {
            distance += (rand() % 100) / 1000.0;
        }
    }
    else {
        distance += (rand() % 100) / 1000.0;
    }
}

int main() {
    track t;
    for (int i = 0; i < MAXHORSES; i++) {
        if (rand() % 2) {
            t.add_horse(new comhorse(i + 1, &t));
        }
        else {
            t.add_horse(new horse(i + 1, &t));
        }
    }

    while (!t.all_finished()) {
        t.run_one_tick();
        t.display();
    }

    cout << "Гонка завершена!\n";
    return 0;
}