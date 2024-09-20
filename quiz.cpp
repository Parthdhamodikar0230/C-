#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string text;
    string options[4];
    char answer;
};

class Quiz {
public:
    Quiz() {
        // Initialize questions
        Question q1 = {"What is the capital of France?", {"A. Berlin", "B. Paris", "C. Rome", "D. Madrid"}, 'B'};
        Question q2 = {"Which planet is known as the Red Planet?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"}, 'B'};
        Question q3 = {"Who wrote 'Hamlet'?", {"A. Charles Dickens", "B. Mark Twain", "C. William Shakespeare", "D. Leo Tolstoy"}, 'C'};
        Question q4 = {"What is the largest ocean on Earth?", {"A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"}, 'D'};
        Question q5 = {"Which gas do plants absorb?", {"A. Oxygen", "B. Nitrogen", "C. Carbon Dioxide", "D. Helium"}, 'C'};
        Question q6 = {"What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'};
        Question q7 = {"What is the smallest prime number?", {"A. 0", "B. 1", "C. 2", "D. 3"}, 'C'};
        Question q8 = {"Which element has the symbol 'O'?", {"A. Gold", "B. Oxygen", "C. Silver", "D. Iron"}, 'B'};
        Question q9 = {"What year did the Titanic sink?", {"A. 1905", "B. 1912", "C. 1918", "D. 1920"}, 'B'};
        Question q10 = {"Who painted the Mona Lisa?", {"A. Van Gogh", "B. Picasso", "C. Da Vinci", "D. Monet"}, 'C'};

        questions.push_back(q1);
        questions.push_back(q2);
        questions.push_back(q3);
        questions.push_back(q4);
        questions.push_back(q5);
        questions.push_back(q6);
        questions.push_back(q7);
        questions.push_back(q8);
        questions.push_back(q9);
        questions.push_back(q10);
    }

    void takeQuiz() {
        cout << "Enter your name: ";
        cin>>name;  
        cout << "Enter your email: ";
        cin>>email; 

        char answer;
        for (size_t i = 0; i < questions.size(); ++i) {
            const Question& q = questions[i];
            cout << q.text << endl;
            for (int j = 0; j < 4; ++j) {
                cout << q.options[j] << endl;
            }
            cout << "Your answer: ";
            cin >> answer;
            cin.ignore(); 
            if (toupper(answer) == q.answer) score++;
            cout << endl;
        }
    }

    void saveResults(const string& filename) {
        ofstream file(filename.c_str());
        if (file) {
            file << "Name: " << name << endl;
            file << "Email: " << email << endl;
            file << "Score: " << score << "/" << questions.size() << endl;
            cout << "Results saved to " << filename << endl;
        } else {
            cout << "Error saving results." << endl;
        }
    }

private:
    vector<Question> questions;
    int score = 0;
    string name;
    string email;
};

int main() {
    Quiz quiz;
    quiz.takeQuiz();
    quiz.saveResults("results.txt");
    return 0;
}

