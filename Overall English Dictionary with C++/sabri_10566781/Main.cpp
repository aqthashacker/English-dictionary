//Main.cpp - - Create a source file "Main.cpp"
#include "FunWithTriGrams.h"//Including FunWithTriGrams header file for main.cpp as it deals with FunWithTriGrams class.
using namespace FUNWITHTRIGRAMS;

int main()//In main(), it consists of optionNo variable with value 0, FunWithTriGrams object, LoadDictionary(), WelcomMessage(), MainMenu(int)
{
	int optionNo=0;
	FunWithTriGrams FunWithTriGramsObj;
	FunWithTriGramsObj.LoadDictionary();
	FunWithTriGramsObj.WelcomMessage();
	FunWithTriGramsObj.MainMenu(optionNo);

}