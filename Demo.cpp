#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Player {
private:
    string name;
    int* score; // pointer to score

public:
    Player(string playerName) {
        name = playerName;
        score = new int(0); // dynamically allocate score
    }

    ~Player() {
        delete score; // free memory
    }

    void addScore(int points) {
        *score += points;
    }

    void showScore() const {
        cout << name << "'s current score: " << *score << endl;
    }

    string getName() const {
        return name;
    }

    int getScore() const {
        return *score;
    }
};

void askQuestion(Player &player, const string &question, const string &answer) {
    string userAnswer;
    cout << question << " ";
    cin >> userAnswer;

    if (userAnswer == answer) {
        cout << "✅ Correct!" << endl;
        player.addScore(10);
    } else {
        cout << "❌ Wrong. The answer was: " << answer << endl;
    }

    player.showScore();
}

int main() {
    cout << "🎮 Welcome to the C++ Console Quiz!\nWhat's your name? ";
    string name;
    cin >> name;

    Player player(name);

    askQuestion(player, "What is 5 * 5?", "25");
    askQuestion(player, "What programming language are we using?", "C++");

    // Lambda function for bonus question
    auto bonusRound = [&player]() {
        cout << "\n🎁 Bonus Round: Double or Nothing!" << endl;
        string confirm;
        cout << "Want to try a bonus question for double points? (yes/no): ";
        cin >> confirm;

        if (confirm == "yes") {
            string answer;
            cout << "What's the result of 10 + 15? ";
            cin >> answer;

            if (answer == "25") {
                cout << "🔥 Nailed it! Doubling your score.\n";
                player.addScore(player.getScore()); // double score
            } else {
                cout << "🪦 Oof. You lose it all.\n";
                player.addScore(-player.getScore()); // reset to 0
            }
        }
    };

    bonusRound();

    cout << "\n👋 Thanks for playing, " << player.getName() << "! Final score: ";
    player.showScore();

    return 0;
}
