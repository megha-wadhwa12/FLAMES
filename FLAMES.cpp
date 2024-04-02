#include <iostream>
#include <string>

using namespace std;

// Function prototypes
string getInput(string prompt);
string findCommonLetters(const string& name1, const string& name2);
string removeCommonLetters(const string& name, const string& lettersToRemove);
char calculateFLAMES(const string& remainingLetters);
string getStatusLabel(char relationshipStatus);
void displayResult(char relationshipStatus);

int main() {
    // Input
    string firstName = getInput("Enter the first name: ");
    string secondName = getInput("Enter the second name: ");

    // Process
    string commonLetters = findCommonLetters(firstName, secondName);
    string remainingLetters = removeCommonLetters(firstName, commonLetters);
    char relationshipStatus = calculateFLAMES(remainingLetters);

    // Output
    displayResult(relationshipStatus);

    return 0;
}

string getInput(string prompt) {
    // Get user input
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

string findCommonLetters(const string& name1, const string& name2) {
    // Find common letters in the names
    string commonLetters = "";
    for (char letter : name1) {
        if (name2.find(letter) != string::npos && commonLetters.find(letter) == string::npos) {
            commonLetters += letter;
        }
    }
    return commonLetters;
}

string removeCommonLetters(const string& name, const string& lettersToRemove) {
    // Remove common letters from the name
    string cleanedName = "";
    for (char letter : name) {
        if (lettersToRemove.find(letter) == string::npos) {
            cleanedName += letter;
        }
    }
    return cleanedName;
}

char calculateFLAMES(const string& remainingLetters) {
    // Use the FLAMES acronym to determine relationship status
    string flamesWord = "FLAMES";
    int count = remainingLetters.length();
    int index = (count - 1) % flamesWord.length();
    return flamesWord[index];
}

string getStatusLabel(char relationshipStatus) {
    // Get the label for the relationship status
    switch (relationshipStatus) {
        case 'F': return "Friendship";
        case 'L': return "Love";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
        default: return "Unknown";
    }
}

void displayResult(char relationshipStatus) {
    // Display the result to the user
    cout << "Relationship Status: " << getStatusLabel(relationshipStatus) << endl;
}