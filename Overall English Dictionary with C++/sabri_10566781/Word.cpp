//Word.cpp - - Create a source file "Word.cpp"
#include<iostream>//including iostream library header
#include<string>//including string library header
#include "Word.h"//including Word header file.

using namespace std;//Calling namespace std

using namespace word;//Calling namespace word


//creating setter methods
void Word::SetWordType(string Set_Word_Type)
{
	type = Set_Word_Type; ///assigning type is equal to Set_Word_Type
}

void Word::SetWordName(string Set_Word_Name)
{
	name = Set_Word_Name; ///assigning name is equal to Set_Word_Name
}

void Word::SetWordDefinition(string Set_Word_Definition)
{
	definition = Set_Word_Definition; ///assigning definition is equal to Set_Word_Definition
}

//creating getter methods- return values(type,name,definition)
string Word::GetWordType()
{
	return type;
}

string Word::GetWordName()
{
	return name;
}

string Word::GetWordDefinition()
{
	return definition;
}



