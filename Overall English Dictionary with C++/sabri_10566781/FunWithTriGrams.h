//FunWithTriGrams.h - Creating a header file called "FunWithTriGrams.h"
#pragma once
#include "Dictionary_Part02.h"

using namespace DictionaryPart02;

#ifndef FUNWITHTRIGRAMS_H
#define FUNWITHTRIGRAMS_H

namespace FUNWITHTRIGRAMS
{
	class FunWithTriGrams : public Dictionary_Part02//This class is inherited from Dictionary_Part02 class
	{
		public://In public access modifier, it contains three vectors and seven methods.
			vector<char>characters = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' '};//This vector consists of 26 letters and a space.
			vector<string>words;
			vector<double>probability_list;
			void MainMenu(int);
			char HighestProboability(char, char);
			char RandomCharacter();
			string WordAvailability(string);
			void Task_05();
			void SpecifyAnotherTask();
			int Task();
	};
}
#endif