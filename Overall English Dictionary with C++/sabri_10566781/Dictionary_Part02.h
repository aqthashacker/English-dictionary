//Dictionary_Part02.h - Create a header file "Dictionary_Part02.h"
#pragma once
#include "Dictionary_Part01.h"//Including Dictionary_Part01 header file 

using namespace DictionaryPart01;

#ifndef DICTIONARY_PART02_H
#define DICTIONARY_PART02_H

namespace DictionaryPart02
{
class Dictionary_Part02 : public Dictionary_Part01//This class is inheried from Dictionary_Part01 class.
{
public://In public access modifier, there are 10 methods.
    void MainMenu(int);
    void Task_01();
    void Task_02();
    void Task_03();
    void Task_04();
    void Task_05();
    void Task_06();
    void FindWord(string);
    void PrintDefinition(string);
    string SplittingDefinition(string);
    void writeToFile();
    void SpecifyAnotherTask();
    void addNewWord();
    void updateExistingWord();
    void deleteExistingWord();
 
};
}
#endif

