#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

const int DECK_SIZE = 52;
const int CARDS_PER_PLAYER = 13;
const char* suits[] = { "Черви", "Бубны", "Крести", "Пики" };
const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз" };

struct Card {
    const char* rank;
    const char* suit;
};

void printHand(const vector<Card>& hand, int playerNumber) {
    cout << "Игрок " << playerNumber + 1 << ":\n";
    for (const auto& card : hand) {
        cout << card.rank << " " << card.suit << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(nullptr));

    // Создание колоды
    vector<Card> deck;
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck.push_back({ ranks[rank], suits[suit] });
        }
    }

    // Перемешивание колоды
    random_shuffle(deck.begin(), deck.end());

    // Раздача карт 4 игрокам
    vector<vector<Card>> hands(4, vector<Card>(CARDS_PER_PLAYER));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < CARDS_PER_PLAYER; ++j) {
            hands[i][j] = deck[i * CARDS_PER_PLAYER + j];
        }
    }

    // Вывод карт игроков
    for (int i = 0; i < 4; ++i) {
        printHand(hands[i], i);
    }

    return 0;
}
