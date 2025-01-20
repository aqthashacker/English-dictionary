//Dictionary_Part01.cpp- Create a source file "Dictionary_Part01.cpp"
#include<iostream>//including iostream library header
#include<string>//including string library header
#include<vector>//including vector library header
#include<fstream>//including fstream library header
#include<algorithm>//including algorithm library header
#include "Dictionary_Part01.h"//including Dictionary_Part01 header file.
#include "Word.h"//including Word header file.

using namespace std;//Calling namespace std, word from Word class, and DictionaryPart01 from Dictionary_Part01 class
using namespace word;
using namespace DictionaryPart01;

void Dictionary_Part01::WelcomMessage()//WelcomMessage() method to print the welcoming message for this program.
{
	//printing for the introduction to users
	cout << " ENGLISH DICTIONARY WITH C++" << endl;
	cout << "-----------------------------" << endl << endl;
	cout << "Hi guys, welcome to ENGLISH DICTIONARY WITH C++. This application provides options to look for the definition of new words and search and collect some words you want to learn. Let's go!!" << endl << endl;
}

void Dictionary_Part01::LoadDictionary()//LoadDictionary() method for Dictionary_Part01()
{
	Word WordObj; // creating a Word object
	string type, name, definition, star;
	WordObj.SetWordType(type); // applying type, name, definition to all setter methods
	WordObj.SetWordName(name);
	WordObj.SetWordDefinition(definition);
	ifstream file("dictionary2022_S0.txt");//opening the file called dictionary2022_S0.txt
	if (!file.is_open())//checking if the dictionary file is open or not.
	{
		cout << "Dictionary file can not be opened!!!";
	}
	
	while (!file.eof()) //here all the file contents get read and stored inside every vector containers accordingly.
	{
		getline(file, type);
		getline(file, name);
		getline(file, definition);
		getline(file, star);

		WordType.push_back(type);
		WordName.push_back(name);
		WordDefinition.push_back(definition);
	}
	file.close();//closing the file
}

void Dictionary_Part01::MainMenu()
{
	int optionNo;
	cout << "Enter the option number for the corresponding menu options below: " << endl;
	cout << "1. FINDING THE DEFINITION OF A WORD" << endl;//printing for task01()
	cout << "2. WORD DETECTOR" << endl;//printing for task02()
	cout << "3. WORD COLLECTOR" << endl;//printing for task03()
	cout << "Please enter here: ";
	cin >> optionNo;
	
		switch (optionNo)//checking the condition for optionNo variable using switch statement.
	{
		case 1://ckeck if optionNo is equal to 1.
			Task01();
			break;
		case 2:
			Task02();//ckeck if optionNo is equal to 2.
			break;
		case 3:
			Task03();//ckeck if optionNo is equal to 3.
			break;
	}
}
void Dictionary_Part01::Task01()
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

	cout << "3. But typing the word that does not exist in the dictionary will print the error message.\n" << endl;
	cout << "Enter the word you want to look for: ";//prompting the user for the word
	cin.ignore();
	getline(cin, Word_Name);
	FindWord(Word_Name);//calling the FindWord function
	if (find(WordName.begin(), WordName.end(), Word_Name) != WordName.end())//checking whether that word is existed in WordName vector.
	{
		PrintDefinition(Word_Name);//Calling PrintDefinition(Word_Name) function
	}
	else
	{
		cout << "Word not found" << endl;
	}
	cout << endl;
	SpecifyAnotherTask();//calling SpecifyAnotherTask()
}

void Dictionary_Part01::FindWord(string Word_Name)//FindWord function for the Word_Name.
{
	int LengthOfWord = Word_Name.length();//assigning LengthOfWord as length of word.
	for (int f = 0; f < LengthOfWord; f++)
	{
		if (ispunct(Word_Name[f]) and Word_Name[f] != '-')//checking if Word_Name contains any punctuation marks and no hyphens
		{
			Word_Name.erase(f--, 1);//erasing the available punctuation marks or hyphen
			LengthOfWord = Word_Name.size();//assigning the length of LengthOfWord
		}
	}

	for (int b = 0; b < LengthOfWord; b++)//this for loop checks whether Word_Name contains whitespace.
	{
		if (Word_Name[b] == ' ')
		{
			Word_Name[b] = '-';
		}
	}

}
void Dictionary_Part01::PrintDefinition(string Word_Name)//PrintDefinition(Word_Name) method to print the definition, word type and word name.
{
	cout << endl;
	int index;
	auto searching = find(WordName.begin(), WordName.end(), Word_Name);// auto searching to search the index of the Word_Name
	if (searching != WordName.end())
	{
		index = searching - WordName.begin();//index variable to get the index of WordName variable
	}
	if (WordType[index] == "n")
	{
		cout << WordName[index] << "(n.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "v")
	{
		cout << WordName[index] << "(v.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "adv")
	{
		cout << WordName[index] << "(adv.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "adj")
	{
		cout << WordName[index] << "(adj.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "prep")
	{
		cout << WordName[index] << "(prep.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "pn")
	{
		cout << WordName[index] << "(pn.)-" << WordDefinition[index] << endl;
	}
	else if (WordType[index] == "n_and_v")
	{
		cout << WordName[index] << "(n.v.)-" << WordDefinition[index] << endl;
	}
	else
    {
    	cout << WordName[index] << "(misc.)-" << WordDefinition[index] << endl;
    }
}

void Dictionary_Part01::SpecifyAnotherTask()//SpecifyAnotherTask() method to ask the user whether the user wants to specify another task or not.
{
	char Option;
	cout << "Want another try(y/n): ";
	cin >> Option;
	
	if (Option == 'y')
	{
		MainMenu();//Calling MainMenu() function
	}
	else
	{
		cout << "Thank you for visiting Dictionary with C++. I hope you will visit us again. Bye! Bye!";
	}
}

void Dictionary_Part01::Task03()
{
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "WORD COLLECTOR" << endl << endl;
	cout << "Here, this task will list all the words that have q without u." << endl;
	for (int i = 0; i < WordName.size(); i++)
	{
		char finding_q = WordName[i].find('q');//finding_q variable to search q letter from WordName.
		char finding_u = WordName[i].find('u');//finding_q variable to search u letter from WordName.

		if (finding_q != string::npos and finding_u == string::npos)//checking whether the WordName contains q without u.
		{
			cout << WordName[i] << endl;
		}
	}
	cout << endl;
	SpecifyAnotherTask();//Calling SpecifyAnotherTask() function
}

void Dictionary_Part01::Task02()
{
	char letter;
	int MinimumNoOfTimes;
	cout << endl;

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "WORD DETECTOR" << endl << endl;
	cout << "Instruction:\nType the letter and the number of times that letter has to occur to obtain a list of words that contain a given character more than a given number of times. " << endl << endl;
	cout << "Enter the letter that needs to be there in the word: ";
	cin >> letter;

	cout << "Enter the minimum number of times that letter has to occur: ";
	cin >> MinimumNoOfTimes;

	for (int i = 0; i < WordName.size(); i++)//For loop to find the letter.
	{
		char SearchingLetter = WordName[i].find(letter);//SearchingLetter variable to search letter you entered the letter.
		int MinOccurences = count(WordName[i].begin(), WordName[i].end(), letter);//count method to count number of times that letter is available 
		if (SearchingLetter != string::npos and MinOccurences >= MinimumNoOfTimes)//checking whether SearchingLetter contains that letter as well as minimum occurences of that letter is greater than MinimumNoOfTimes
		{
			cout << WordName[i] << endl;
		}
	}
	cout << endl;
	SpecifyAnotherTask();//Calling SpecifyAnotherTask() function
}
//int main()
//{
//	string type, name, definition;
//	Dictionary_Part01 d;
//	d.LoadDictionary();
//	d.WelcomMessage();
//	
//}

