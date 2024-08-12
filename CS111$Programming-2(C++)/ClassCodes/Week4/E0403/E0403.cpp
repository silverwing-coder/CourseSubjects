#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class StringCount
{
private:
    string search_text;

public:
    StringCount()
    {
        search_text = "";
    }
    StringCount(string ntext)
    {
        search_text = ntext;
    }
    void addInputText(string ntext)
    {
        // cout << "Append text: " << ntext << endl;
        search_text.append(ntext);
    }
    string getText()
    {
        return search_text;
    }

    static int getNumberOfWords(string ntext)
    {

        int num_words = 0;
        stringstream sstream(ntext);
        string word;
        while (!sstream.eof())
        {
            sstream >> word;
            // cout << word << endl;
            num_words += 1;
        }
        return num_words;
    }

    static int getNumberOfDigits(string ntext)
    {

        int num_digits = 0;
        int sz = ntext.size();

        for (int i = 0; i < sz; i++)
        {
            if (isdigit((int)ntext.at(i)))
            {
                num_digits++;
            }
        }

        return num_digits;
    }

    static int getNumberOfCapitals(string ntext)
    {

        int num_capitals = 0;
        int sz = ntext.size();

        for (int i = 0; i < sz; i++)
        {
            if (ntext.at(i) >= 'A' && ntext.at(i) <= 'Z')
            {
                num_capitals++;
            }
        }

        return num_capitals;
    }

    static int getNumberOfConsonents(string ntext)
    {

        int num_consonents = 0;
        int sz = ntext.size();

        for (int i = 0; i < sz; i++)
        {
            if (tolower(ntext.at(i)) == 'a' || tolower(ntext.at(i)) == 'e' || tolower(ntext.at(i)) == 'i' 
            || tolower(ntext.at(i)) == 'o' || tolower(ntext.at(i)) == 'u')
            {
                num_consonents++;
            }
        }

        return num_consonents;
    }

    static int wordExist(string nword, string ntext){
        int num_words = 0;
        stringstream sstream(ntext);
        string word;
        while (!sstream.eof())
        {
            sstream >> word;
            // cout << word << endl;
            if(nword.compare(word) == 0)
                num_words += 1;
        }
        return num_words;

    }
};

int main()
{
    string ntext;
    StringCount sms;
    cout << "========================================================" << endl;
    cout << "The text you enter will be appended to the search text.\nIf you finish adding text, type \"q\"." << endl;
    cout << "--------------------------------------------------------" << endl;
    while (true)
    {

        cout << "Enter Appending Text: " << endl;
        getline(cin, ntext);
        // cout << "ntext: " << ntext << endl;

        if (ntext == "q")
        {
            break;
        }
        else
        {
            sms.addInputText(ntext + '\n');
        }
    }

    // cout << sms.getText();
    cout << "\n==============================================================" << endl;
    // cout << "There are " << (StringCount::getNumberOfWords(sms.getText())) - 1 << " words." << endl;
    // cout << "There are " << (StringCount::getNumberOfDigits(sms.getText())) << " digits." << endl;
    // cout << "There are " << (StringCount::getNumberOfCapitals(sms.getText())) << " capitals." << endl;
    // cout << "There are " << (StringCount::getNumberOfConsonents(sms.getText())) << " consonents." << endl;
    cout << "There are " << (StringCount::wordExist("This", sms.getText())) << " consonents." << endl;
    cout << "--------------------------------------------------------------" << endl;

    return 0;
}