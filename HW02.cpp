#include <iostream>
using namespace std;

void analyzeText(const char*);
void countSentences(char, int&);
void countWords(char, int&);
void countVowels(char, int*);

int main()
{
    const char paragraph1[] = "Hello, world! I am learning C++. Isn't it exciting?";
    const char paragraph2[] = "Now I am become Death, the destroyer of worlds.";

    analyzeText(paragraph1);
    cout << "-----------------------------------\n";
    analyzeText(paragraph2);

    return 0;
}

void analyzeText(const char* text)
{
    int sentence = 0;
    int word = 1;
    int vowelsList[5] = {};             // {numA, numE, numI, numO, numU}

    for(int i = 0 ; *(text + i) != '\0' ; i++)
    {
        countSentences(*(text + i), sentence);
        countWords(*(text + i), word);
        countVowels(*(text + i), vowelsList);
    }

    cout << sentence << " sentences" << endl;
    cout << "Average " << word / sentence << " words per sentence" << endl;
    cout << *(vowelsList) << " a" << endl;
    cout << *(vowelsList + 1) << " e" << endl;
    cout << *(vowelsList + 2) << " i" << endl;
    cout << *(vowelsList + 3) << " o" << endl;
    cout << *(vowelsList + 4) << " u" << endl;
}

void countSentences(char text, int& sentence)
{
    if(text == '.' || text == '!' || text == '?')
    {
        sentence++;
    }
}

void countWords(char text, int& word)
{
    if(text == ' ')
    {
        word++;
    }
}

void countVowels(char text, int* vowelsList)
{
    if(text == 'A' || text == 'a')
    {
        (*(vowelsList + 0))++;
    }
    else if(text == 'E' || text == 'e')
    {
        (*(vowelsList + 1))++;
    }
    else if(text == 'I' || text == 'i')
    {
        (*(vowelsList + 2))++;
    }
    else if(text == 'O' || text == 'o')
    {
        (*(vowelsList + 3))++;
    }
    else if(text == 'U' || text == 'u')
    {
        (*(vowelsList + 4))++;
    }
}
