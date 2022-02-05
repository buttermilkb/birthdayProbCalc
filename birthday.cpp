#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

float probCalc(int numOfPeople, float prob);
int displayInstruct();

const int NUM_OF_DAYS = 365;
const int MAX_CHAR = 100;

int main() {
	int numOfPeople = 1;
	float prob = 1.0f;
	bool quit = false;
	char input[MAX_CHAR];

	displayInstruct();
		
	while (!quit) {
		cout << "Option: ";
		cin >> input;
		for (int i = 0; i < strlen(input); i++) {
			input[i] = toupper(input[i]);
		}

		if (strcmp(input, "1") == 0) {
			prob = probCalc(numOfPeople, prob);
		}
		else if (strcmp(input, "2") == 0) {
			prob = 1 - probCalc(numOfPeople, prob);
		}
		else if (strcmp(input, "HELP") == 0) {
			displayInstruct();
		}
		else if (strcmp(input, "QUIT") == 0) {
			quit = true;
		}
		else {
			cout << "Please enter 1, 2, or QUIT";
		}
		cout << "Probability that there are no one shares ";
		cout << "a birthday: " << prob << endl;
	}
	return 0;
}

float probCalc(int numOfPeople, float prob) {
	cout << "Enter the number of people in the room: ";
	cin >> numOfPeople;
	for (float i = NUM_OF_DAYS; i > NUM_OF_DAYS - numOfPeople; i--) {
		prob *= i/NUM_OF_DAYS;
	}
	return prob;
}

int displayInstruct() {
	cout << "Welcome to the birthday probability calculator!" << endl;
	cout << "There are two options in this calculator..." << endl;
	cout << "1. Probability of there being an overlapping birthday";
	cout << " given a certain number of people in a room." << endl;
	cout << "2. Probability of there being no shared birthdays";
	cout << " given a certain number of people in a room." << endl;
	cout << "Type \"1\" with no quotation marks for option 1." << endl;
	cout << "Type \"2\" with no quotation marks for option 2." << endl;
	cout << "Type \"QUIT\" with no quotation marks to exit." << endl;
	cout << "Type \"HELP\" with no quotation marks for help." << endl;
	cout << "Happy calculating!" << endl;
}
