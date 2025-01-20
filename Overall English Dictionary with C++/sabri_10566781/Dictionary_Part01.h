//Dictionary_Part01.h - Create a header file "Dictionary_Part01.h"
#pragma once

#include<iostream>//including iostream library header
#include<vector>//including vector library header

using namespace std;

#ifndef DICTIONARY_PART01_H
#define DICTIONARY_PART01_H

namespace DictionaryPart01//Calling namespace DictionaryPart01
{

	class Dictionary_Part01//Creating Dictionary_Part01 class
	{
		
	public://In public access modifier, there are three vectors, nine methods.
		vector<string>WordType;//creating three vector for Word objects
		vector<string>WordName;
		vector<string>WordDefinition;
		void LoadDictionary();//this function is used to load dictionary file into the array of Word objects.
		void WelcomMessage();//display the welcome message to the user about this program
		void MainMenu();//tell the user to prompt the menu option for different task.
		void Task01();//For Task01() method 
		void Task02();//For Task02() method
		void Task03();//For Task03() method
		void FindWord(string);//arrange the word you have entered before searching it from the vector.
		void PrintDefinition(string);//print the word's definition
		void SpecifyAnotherTask();//ask the user to specify another task or whether he/she wants to continue this program.
	};
}
#endif
