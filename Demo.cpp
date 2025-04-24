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
        cout << "[LOG] Player created: " << name << endl;
    }

    ~Player() {
        delete score; // free memory
        cout << "[LOG] Player object destroyed: " << name << endl;
    }

    void addScore(int points) {
        *score += points;
        cout << "[LOG] Score updated: " << *score << " points" << endl;
    }

    void showScore() const {
        cout << "[LOG] Displaying score for " << name << ": " << *score << endl;
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
    cout << "\n[LOG] Asking question: " << question << endl;

    string userAnswer;
    cout << question << " ";
    cin >> userAnswer;

    cout << "[LOG] User answered: " << userAnswer << endl;

    if (userAnswer == answer) {
        cout << "✅ Correct!" << endl;
        player.addScore(10);
    } else {
        cout << "❌ Wrong. The answer was: " << answer << endl;
    }

    player.showScore();
}

int main() {
    cout << "[LOG] Application started\n";
    cout << "🎮 Welcome to the C++ Console Quiz!\nWhat's your name? ";

    string name;
    cin >> name;

    Player player(name);

    askQuestion(player, "What is 5 * 5?", "25");
    askQuestion(player, "What programming language are we using?", "C++");

    cout << "\n[LOG] Starting Bonus Round" << endl;

    // Lambda function for bonus question
    auto bonusRound = [&player]() {
        cout << "\n🎁 Bonus Round: Double or Nothing!" << endl;
        string confirm;
        cout << "Want to try a bonus question for double points? (yes/no): ";
        cin >> confirm;

        cout << "[LOG] Bonus round choice: " << confirm << endl;

        if (confirm == "yes") {
            string answer;
            cout << "What's the result of 10 + 15? ";
            cin >> answer;

            cout << "[LOG] Bonus round answer: " << answer << endl;

            if (answer == "25") {
                cout << "🔥 Nailed it! Doubling your score.\n";
                player.addScore(player.getScore()); // double score
            } else {
                cout << "🪦 Oof. You lose it all.\n";
                player.addScore(-player.getScore()); // reset to 0
            }
        } else {
            cout << "[LOG] Skipped bonus round." << endl;
        }
    };

    bonusRound();

    cout << "\n👋 Thanks for playing, " << player.getName() << "! Final score: ";
    player.showScore();
    cout << "[LOG] Application ended\n";

    return 0;
}
