//Dictionary_Part02.cpp - - Create a source file "Dictionary_Part02.cpp"
#include "Dictionary_Part02.h"
#include <fstream>
#include<iostream>
#include<algorithm>//including algorithm header file
#include<vector>
#include<string>
#include <sstream>
#include <cctype>//including cctype header file
using namespace std;
using namespace DictionaryPart02;


void Dictionary_Part02::MainMenu(int optionNo)//This function is overloaded from void Dictionary_Part01::MainMenu() to apply operators to your data types.
{
	cout << "Enter the option number for the corresponding menu options below: " << endl;
	cout << "1. PALINDROMES" << endl;//printing for task01()
	cout << "2. ANAGRAMS" << endl;//printing for task02()
	cout << "3. FINDING THE DEFINITION OF A WORD" << endl;//printing for task03()
	cout << "4. GUESSING A NOUN" << endl;//printing for task04()
	cout << "5. TRI-GRAMS GENERATOR" << endl;//printing for task05()
	cout << "Please enter here: ";
	cin >> optionNo;

	switch (optionNo)//checking the condition for optionNo variable using switch statement.
	{
	case 1://checking if optionNo is equal to 1.
		Task_01();
		SpecifyAnotherTask();
		break;
	case 2://checking if optionNo is equal to 2.
		Task_02();
		SpecifyAnotherTask();
		break;
	case 3://checking if optionNo is equal to 3.
		Task_03();
		SpecifyAnotherTask();
		break;
	case 4://checking if optionNo is equal to 4.
		Task_04();
		SpecifyAnotherTask();
		break;
	case 5://checking if optionNo is equal to 5.
		Task_05();
		SpecifyAnotherTask();
		break;
	}
}
	
void Dictionary_Part02::Task_01()//This function prints all words that are palindromes
{
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "PALINDROMES" << endl << endl;
	cout << "Here, this task will print all words that are palindromes. " << endl << endl;
	
	for (int w = 0; w < WordName.size(); w++)
	{
		string word = WordName[w];
		reverse(word.begin(), word.end());//this function reverses all characters of word.
		if (word == WordName[w])//Checking if word is exactly equal to WordName[w]
		{
			cout << word << endl;
		}
	}
}

void Dictionary_Part02::Task_02()//This method checks all words that are anagrams to the word you prompted.
{
	string word;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "ANAGRAMS" << endl << endl;
	cout << "Instruction: Type the word to find the list of words that are anagrams to the word you typed"<<endl<<endl;
	cout << "Enter the word: ";
	cin.ignore();
	getline(cin, word);
	cout << endl;
	cout << "Words that are anagrams to your typed word are: " << endl;
	for (int i = 0; i < WordName.size(); i++)
	{
		
	string word1 = word;
	string word2 = WordName[i];
		
		sort(word1.begin(), word1.end());//This function sort all characters of both word1 and word2 in ascending order.
		sort(word2.begin(), word2.end());
		if (word1 == word2 and word != WordName[i])//Finding out for word1 == word2 and word not equal to the prompted input.
		{
			cout << WordName[i] << endl;

		}

	}
	cout << endl;
	cout << "That's all that word has."<< endl;
}
void Dictionary_Part02::SpecifyAnotherTask()
{
	int optionNo=0;
	char Option;
	cout << "Want another try(y/n): ";
	cin >> Option;

	if (Option == 'y')
	{
		MainMenu(optionNo);
	}
	else
	{
		cout << "Thank you for visiting English Dictionary with C++. I hope you will visit us again. Bye! Bye!";//printing for Option != 'y'
	}
}

void Dictionary_Part02::Task_03()//This task looks like Task01() in Dictionary_Part01 class. The differences are prompting the word is not case sensitive, a proper noun's first letter is uppercase, and multiple definitions are split with a line break and numberings.
{
	string Word_Name;
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "FINDING THE DEFINITION OF A WORD" << endl << endl;
	cout << "Instructions:\n1.Type the word you want to look for word type and its definition\n2.Word type for a word in brackets is abbreviated as follows: " << endl << endl;
	cout << "  Word type       |  Meaning" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "  v.              |  verb       " << endl;
	cout << "  n.              |  noun        " << endl;                            //Here it indicates this method prints the table for Word Type and their meaning for the user to understand the representation of them.
	cout << "  adv.            |  adverb " << endl;
	cout << "  adj.            |  adjective" << endl;
	cout << "  prep.           |  preposition" << endl;
	cout << "  pn.             |  pronoun" << endl;
	cout << "  n.v.            |  noun and verb" << endl;
	cout << "  misc.           |  other words and prefix" << endl << endl;

	cout << "3. You can type the word either in uppercase or lowercase." << endl;
	cout << "4. Mulitple definitions will be numbered for the particular word you typed." << endl;
	cout << "5.Proper noun's first letter will be in uppercase" << endl;
	cout << "6. But typing the word that does not exist in the dictionary will print the error message.\n" << endl;
	cout << "Enter the word you want to look for: ";//prompting the user for the word
	cin.ignore();
	getline(cin, Word_Name);
	FindWord(Word_Name);//calling the FindWord function
}

void Dictionary_Part02::Task_04()//This task creates a guessing game to guess a noun with the definition, length of the noun and its structure.
{
	
	vector<int>NounIndexes;
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "GUESSING A NOUN" << endl << endl;
	cout << "Instructions:\n1.Type the correct noun for the given random definition.\n2.You can have three guesses to type the correct noun. Or else, this task will be over and print the correct word.\n3.The length of the word and astericks, which show the structure of the word, are also be displayed next to the definition.\n4.If you guess the wrong noun for the first time, the first letter from the asterick structure will be revealed.\n5.If you guess the wrong noun for the second time, the first and second letters from the asterick structure will be revealed." << endl << endl;
	int random, tries = 3;
	
	for (int i = 0; i < WordType.size(); i++)
	{
		if (WordType[i] == "n")
		{
			NounIndexes.push_back(i);			
		}
	}
	srand((unsigned)time(NULL));
	random_shuffle(NounIndexes.begin(), NounIndexes.end());
	random = NounIndexes[0];
	string WordSearch = WordName[random];
	while (WordSearch.length() < 2)
	{
		if (WordSearch.length() < 2)
		{
			random_shuffle(NounIndexes.begin(), NounIndexes.end());
			random = NounIndexes[0];
		}
	}
	//cout << random << endl;
	string word, WordSeacrh = WordName[random], asterick = WordName[random];
	for (char& c : asterick)//This loop checks for character by character in asterick.
	{
		if (c == '-')
		{
			c = '-';
		}
		else
		{
			c = '*';
		}
	}
	cout << WordDefinition[random] << "  (Length of the word: " << WordName[random].size() << ")       " <<  asterick << endl;
	cin.ignore();
	for (int t = tries;t>0;t--)//This loops until tries becomes 0.
	{	
		if (tries == 1)
		{
			cout << "You have " << tries << " guess remaining." << endl;
		}
		else
		{
			cout << "You have " << tries << " guesses remaining." << endl;
		}
		
		cout << "Please type here: ";
		getline(cin, word);		
		if (word != WordSeacrh)
		{
			tries--;
			asterick[0] = WordSeacrh[0];
			if (tries == 0)
			{
				cout << "You failed to guess the word. Better next time. The correct word is " << WordSeacrh << endl;
				break;
			}
			else if (tries == 1)
			{
				asterick[1] = WordSeacrh[1];
			}
			
			cout <<"Here is the clue for the word: "<< asterick << endl;
		}
		else 
		{
			cout << "Congratulation!!! For guessing the correct word. The correct word is " << WordSeacrh << endl;
			break;
		}
	}
	NounIndexes.clear();
}
	

void Dictionary_Part02::FindWord(string Word_Name)
{
	int LengthOfWord = Word_Name.length();//assigning LengthOfWord as length of word.
	for (int f = 0; f < LengthOfWord; f++)
	{
		if (ispunct(Word_Name[f]) and Word_Name[f] != '-')
		{
			Word_Name.erase(f--, 1);
			LengthOfWord = Word_Name.size();
		}
		else if (Word_Name[f] == ' ')
		{
			Word_Name[f] = '-';
		}
		if (isupper(Word_Name[f]))//finding out uppercase letters in Word_Name.
		{
			Word_Name[f] = tolower(Word_Name[f]);
		}
		
	}
		if (find(WordName.begin(), WordName.end(), Word_Name) != WordName.end())//checking whether that word is existed in WordName vector.
		{
			PrintDefinition(Word_Name);
		}
		else
		{
			cout << "Word not found" << endl;
		}
		cout << endl;
}

void Dictionary_Part02::PrintDefinition(string Word_Name)
{
	cout << endl;
	int index=0;
	auto searching = find(WordName.begin(), WordName.end(), Word_Name);
	if (searching != WordName.end())
	{
		index = searching - WordName.begin();
	}
	string definition = WordDefinition[index];

	if (WordType[index] == "n")
	{	
		cout << WordName[index] << "(n.)-" << endl;
		cout<< SplittingDefinition(definition);
	}
	else if (WordType[index] == "v")
	{
		cout << WordName[index] << "(v.)-" << endl;
		cout << SplittingDefinition(definition);
	}
	else if (WordType[index] == "adv")
	{
		cout << WordName[index] << "(adv.)-"<< endl;
		cout << SplittingDefinition(definition);
	}
	else if (WordType[index] == "adj")
	{
		cout << WordName[index] << "(adj.)-" << endl;
		cout << SplittingDefinition(definition);
	}
	else if (WordType[index] == "prep")
	{
		cout << WordName[index] << "(prep.)-"  << endl;
		cout << SplittingDefinition(definition);
	}
	else if (WordType[index] == "pn")
	{
		string ProperNoun = WordName[index];
		for (int i = 0; i < ProperNoun.length(); i++)
		{
			if (i == 0)
			{
				ProperNoun[0] = toupper(ProperNoun[0]);
			}
			cout << ProperNoun[i];
		}
		cout <<  "(pn.)-" << endl;
		cout << SplittingDefinition(definition);
	}
	else if (WordType[index] == "n_and_v")
	{
		cout << WordName[index] << "(n.v.)-"  << endl;
		cout << SplittingDefinition(definition);
	}
	else
	{
		cout << WordName[index] << "(misc.)-"  << endl;
		cout << SplittingDefinition(definition);
	}
}

string Dictionary_Part02::SplittingDefinition(string definition)//This procedure splits multiple definitions with a line break.
{
	int numbering = 1;//numbering for the definitions.
	string delimiter = ";  ";//delimiter for the string to be removed from the word definition.
	size_t pos = 0;
	string token;
	while ((pos = definition.find(delimiter)) != string::npos) {
		token = definition.substr(0, pos);
		if (islower(token[0]))
		{
			token[0] = toupper(token[0]);
		}
		cout << numbering<<") " << token << endl;
		definition.erase(0, pos + delimiter.length());
		
		numbering++;
	}
	cout << numbering << ") " << definition << endl;
	return " ";
}
void Dictionary_Part02::writeToFile() {
	ofstream file("dictionary2022_S0.txt");
	if (!file) {
		cerr << "Unable to open file for writing" << endl;
		exit(1); // Exit with error code
	}

	for (size_t i = 0; i < WordName.size(); ++i) {
		file << WordType[i] << "\n" << WordName[i] << "\n" << WordDefinition[i] << "\n" << "**\n";
	}

	file.close();
}

void Dictionary_Part02::addNewWord() {
	string wordType, word, definition;

	// Get input for the new word
	bool isWordUnique = false;
	do {
		cout << "Enter word: ";
		cin >> word;

		// Check if the word already exists in WordName vector
		if (find(WordName.begin(), WordName.end(), word) != WordName.end()) {
			cout << "Error: Word already exists in the dictionary. Please enter a different word." << endl;
		}
		else {
			isWordUnique = true; // Set the condition to exit the loop
		}
	} while (!isWordUnique);

	bool validWordType = false;
	// Get input for the new word type
	do {
		cout << "Enter word type (v., n., adv., adj., prep., pn., n.v., misc.): ";
		cin >> wordType;

		// Check if the word type is valid
		if (wordType != "v." && wordType != "n." && wordType != "adv." && wordType != "adj."
			&& wordType != "prep." && wordType != "pn." && wordType != "n.v." && wordType != "misc.") {
			cout << "Error: Invalid word type." << endl;
		}
		else {
			validWordType = true; // Set the condition to exit the loop
		}
	} while (!validWordType);

	bool isDefinitionUnique = false;
	// Continue the loop until a unique definition is provided
	do {
		cout << "Enter definition: ";
		cin.ignore(); // Clear the newline character from the buffer
		getline(cin, definition);

		// Check if the definition already exists in WordDefinition vector
		if (find(WordDefinition.begin(), WordDefinition.end(), definition) != WordDefinition.end()) {
			cout << "Error: Definition already exists in the dictionary. Please enter a different definition." << endl;
		}
		else {
			isDefinitionUnique = true; // Set the condition to exit the loop
		}
	} while (!isDefinitionUnique);

	// Insert the new entry into the vectors
	auto it = lower_bound(WordName.begin(), WordName.end(), word);
	size_t index = distance(WordName.begin(), it);

	WordName.insert(WordName.begin() + index, word);
	WordType.insert(WordType.begin() + index, wordType);
	WordDefinition.insert(WordDefinition.begin() + index, definition);

	// Write the updated vectors back to the file
	writeToFile();

	cout << "Noun inserted and file updated successfully." << endl;
}
void Dictionary_Part02::updateExistingWord() {
	string word, wordType, definition;

	// Get input for the word to be updated
	cout << "Enter word to update: ";
	cin >> word;

	// Check if the word exists in WordName vector
	auto it = find(WordName.begin(), WordName.end(), word);
	if (it == WordName.end()) {
		cout << "Error: Word does not exist in the dictionary." << endl;
		return;
	}

	// Get the index of the word
	size_t index = distance(WordName.begin(), it);

	// Get new type and definition for the word
	cout << "Enter new word type (v., n., adv., adj., prep., pn., n.v., misc.): ";
	cin >> wordType;
	cout << "Enter new definition: ";
	cin.ignore(); // Clear the newline character from the buffer
	getline(cin, definition);

	// Update the vectors
	WordType[index] = wordType;
	WordDefinition[index] = definition;
	WordName[index] = word;

	// Write the updated vectors back to the file
	writeToFile();

	cout << "Word updated successfully." << endl;
}
void Dictionary_Part02::deleteExistingWord() {
	string word;

	// Get input for the word to be deleted
	cout << "Enter word to delete: ";
	cin >> word;

	// Check if the word exists in WordName vector
	auto it = find(WordName.begin(), WordName.end(), word);
	if (it == WordName.end()) {
		cout << "Error: Word does not exist in the dictionary." << endl;
		return;
	}

	// Get the index of the word
	size_t index = distance(WordName.begin(), it);

	// Erase the word, type, and definition from the vectors
	WordName.erase(WordName.begin() + index);
	WordType.erase(WordType.begin() + index);
	WordDefinition.erase(WordDefinition.begin() + index);

	// Write the updated vectors back to the file
	writeToFile();

	cout << "Word deleted successfully." << endl;
}
void Dictionary_Part02::Task_06()
{
	bool isValidOption = false;
	int optionNo;
	do {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "EDITING DICTIONARY" << endl << endl;
	cout << "Choose the option to modify the dictionary file." << endl << endl;
	cout << "1. ADD NEW WORD"<<endl;
	cout << "2. UPDATE THE EXISTING WORD" << endl;
	cout << "3. DELETE THE EXISTING WORD" << endl;
	cout << "Please enter here:";
	//cin >> optionNo;

	if (!(cin >> optionNo)) {
		// Handle non-numeric input
		cout << "Error: Please enter a valid numeric option." << '\n' << endl;

		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
	}
	else if (optionNo < 1 || optionNo > 3) {
		// Handle out-of-range input
		cout << "Error: Please enter a valid option number between 1 and 3." << '\n' << endl;
	}
	else {
		isValidOption = true;
	}

	} while (!isValidOption);
	switch (optionNo) {
	case 1:
		addNewWord();
		break;
	case 2:
		updateExistingWord();
		break;
	case 3:
		deleteExistingWord();
		break;
	default:
		cout << "Invalid option." << endl;
	}
}


void Dictionary_Part02::Task_05()
{
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "TRI-GRAMS" << endl << endl;

}

//int main()
//{
//	int optionNo = 0;
//	Dictionary_Part02 d;
//	d.LoadDictionary();
//	d.WelcomMessage();
//	d.MainMenu(optionNo);
//}
