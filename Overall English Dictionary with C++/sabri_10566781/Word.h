//Word.h - Creating a header file called "Word.h"
#pragma once

#include<iostream>//including iostream library header

using namespace std;//Calling namespace std

#ifndef WORD_H //#ifndef, #define and #endif is used in every header files here therefore every source files can use header files easily.
#define WORD_H
namespace word//creating the namespace word.
{
	class Word //creating Word class
	{
	private:
		string type, name, definition; // In private access modifiers, I named three variables (type, name and definition) to keep them private therefore they will not be accessed by outside classes.
	public://This public access modifier has six methods.
		void SetWordType(string);
		void SetWordName(string);
		void SetWordDefinition(string);
		string GetWordType();
		string GetWordName();
		string GetWordDefinition();
		
	};
}
//In public access modifier, setter and getter methods are available to call type, name and definition variables.

#endif
