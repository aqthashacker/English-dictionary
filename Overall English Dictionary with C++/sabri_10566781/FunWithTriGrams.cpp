//FunWithTriGrams.cpp -  Create a source file "FunWithTriGrams.cpp"
#include "FunWithTriGrams.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using namespace FUNWITHTRIGRAMS;


void FunWithTriGrams::MainMenu(int optionNo) {
	bool isValidOption = false;

	do {
		cout << "Enter the option number for the corresponding menu options below: " << endl;
		cout << "1. PALINDROMES" << endl;   // printing for task01()
		cout << "2. ANAGRAMS" << endl;     // printing for task02()
		cout << "3. FINDING THE DEFINITION OF A WORD" << endl;  // printing for task03()
		cout << "4. GUESSING A NOUN" << endl;   // printing for task04()
		cout << "5. TRI-GRAMS GENERATOR" << endl;  // printing for task05()
		cout << "6. EDITING DICTIONARY" << endl;
		cout << "Please enter here: ";

		if (!(cin >> optionNo)) {
			// Handle non-numeric input
			cout << "Error: Please enter a valid numeric option." << '\n' << endl;

			cin.clear();  // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
		}
		else if (optionNo < 1 || optionNo > 6) {
			// Handle out-of-range input
			cout << "Error: Please enter a valid option number between 1 and 6." << '\n' << endl;
		}
		else {
			isValidOption = true;
		}

	} while (!isValidOption);

	switch (optionNo) {
	case 1:
		Task_01();
		break;
	case 2:
		Task_02();
		break;
	case 3:
		Task_03();
		break;
	case 4:
		Task_04();
		break;
	case 5:
		Task_05();
		break;
	case 6:
		Task_06();
		break;
	}
	

	SpecifyAnotherTask();
}

void FunWithTriGrams::Task_05()
{
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "TRI-GRAMS GENERATOR" << endl << endl;
	cout << "Instruction:\n1.Enter two letters for trigrams to display 10 words." << endl << endl;
	Task();
}

char FunWithTriGrams::HighestProboability(char letter1, char letter2)//This function checks for highest proability of third letter occutring after previous two letters within the dictionary file.
{
	string word_name;
	char letter_1;
	int totWords=0;//totWords variable to count the number of words after the first two char types in part of every words from WordName vector.
	
	for (int q = 0; q < WordName.size()-1; q++)//This loop counts number of words having first two letters.
	{
		word_name = WordName[q];
		letter_1 = word_name[0];
		char letter_2 = word_name[1];
		if (letter1 == letter_1 and letter2 == letter_2)
		{
			totWords++;
			words.push_back(WordName[q]);//adding words into the vector.
		}
	}

	int letter_count = 0;//letter_count variable for counting the number of letters within the charcaters vector.
	while (letter_count!=characters.size())//This while loop checks for all characters in characters vector for the third letter occuring in every words in the dictionary file.
	{
		int tot_probability = 0;//tot_probability variable for counting the number of letter happening after the first two characters.
		for (int t = 0; t < words.size(); t++)
		{
			string word_name = words[t];
			char third_letter = word_name[2];
			if (characters[letter_count] == third_letter)
			{
				tot_probability++;
			}
		}
		double probability = double(tot_probability) / double(totWords);//calculating probability of the particular letter with total of words happening after the first two characters.
		probability_list.push_back(probability);
		letter_count++;
	}
	int indexOfcharacter=0;
	auto index = find(probability_list.begin(), probability_list.end(), *max_element(probability_list.begin(), probability_list.end()));
	if (index != probability_list.end())
	{
		indexOfcharacter  = index - probability_list.begin();
	}
	probability_list.clear();
	words.clear();
	return characters[indexOfcharacter];
}

char FunWithTriGrams::RandomCharacter()//This procedure generates random character from characters vector.
{
	int random;
	
	for (int l = 0; l < 3; l++)
	{
		random = ((rand() % characters.size()));
	}
	return characters[random];
}

string FunWithTriGrams::WordAvailability(string final_word)//This procedure is for word availability in the WordName vector entirely.
{
	auto searchingForWord = find(WordName.begin(), WordName.end(), final_word);
	if (searchingForWord != WordName.end())
	{
		return "-1";
	}
	else
	{
		return final_word;
	}
}

void FunWithTriGrams::SpecifyAnotherTask()
{
	int optionNo = 0;
	char Option;
	cout << "Want another try(y/n): ";
	cin >> Option;

	if (Option == 'y')
	{
		cout << endl;
		MainMenu(optionNo);
	}
	else
	{
		cout << "Thank you for visiting English Dictionary with C++. I hope you will visit us again. Bye! Bye!";
	}

}
int FunWithTriGrams::Task()
{
	char letter1, letter2;
	// Function to check if the input is a valid letter or space
	auto isValidChar = [](char ch) {
		return (isalpha(ch) && (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')) || ch == '\n';
		};

	do {
		std::cout << "Enter the first letter: ";
		// Read a character, including whitespace
		std::cin >> std::noskipws >> letter1;

		// Clear the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (!isValidChar(letter1)) {
			std::cout << "Error: Please enter a valid letter or space.\n";
		}

		if (letter1 == '\n') {
			continue;
		}
		

	} while (!isValidChar(letter1));

	// Input for the second letter
	do {
		std::cout << "Enter the second letter: ";
		// Read a character, including whitespace
		std::cin >> std::noskipws >> letter2;

		// Clear the input buffer only if a newline character is present
		if (letter2 != '\n') {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (!isValidChar(letter2)) {
			std::cout << "Error: Please enter a valid letter or space.\n";
		}

	} while (!isValidChar(letter2));
	HighestProboability(letter1, letter2);
	srand((unsigned)time(NULL));
	vector<char>word_characters;
	cout << "Here are 10 words you would like to see: " << endl;
	int counter = 1;//counter variable to count number of printed words.
	while(counter<=10)//while loop to print ten words while finding the highest probability for the letter from the previous two letters.
	{
		char random_Character;
	for (int e = 0; e < 2; e++)//This iteration repeats two times to receive the first two random characters from the characters vector.
	{
		random_Character = RandomCharacter();
		word_characters.push_back(random_Character);
	}
	word_characters.push_back(HighestProboability(letter1, letter2));
	char next_letter;
	for (int y = 1; y < 4; y++)//For the word required to be outputted, it needs six characters altogether. This for loop has the condition y<4 because to make a word, the first three characters are generated hence, three more characters to amke it six. 
	{
		next_letter = HighestProboability(word_characters[y], word_characters[y+1]);
		word_characters.push_back(next_letter);
	}
	string final_word(word_characters.begin(), word_characters.end());
	word_characters.clear();
	string result=WordAvailability(final_word);
	if (result != "-1")
	{
		cout<<result<< endl;
		counter++; 
	}
	}
	return 0;
}
