/*
 *AUTHOR: Ron Sider
 *
 * Date: March 2020
 *
 */

#include "PhoneticFinder.hpp"
#include <iostream>

#include <string>
using namespace std;

namespace phonetic
{
/* this fucntion will return the word according to exresice paramters */

string find(string text, string word)
{

    if (word.length() == 0 || word == " ")
        throw runtime_error("Did not find the word: '" + word );

    int i = 0,
        j = 0;
    string ans = "";

    while (i <= text.length())
    {
        if ((j == word.length()) && ((i == text.length()) || (text.at(i) == ' ')))
        {
            return ans;
        }
        else if (i == text.length())
            break;

        if ((j < word.length()) && (upperlower(text.at(i), word.at(j))))
        {
            ans += text.at(i);
            i++;
            j++;
        }
        else if ((j < word.length()) && (criteria(text.at(i), word.at(j))))
        {
            ans += text.at(i);
            i++;
            j++;
        }
        else
        {
            ans = "";
            j = 0;
            while ((i < text.length()) && (text.at(i) != ' '))
            {
                i++;
            }
            while ((i < text.length()) && (text.at(i) == ' '))
            {
                i++;
            }
        }
    }

    throw runtime_error("Did not find the word: '" + word );

} 

/* doesnt matter if lower or uppercase*/

bool upperlower(char a, char b)
{
    a = tolower(a);
    b = tolower(b);

    if (a == b)

        return true;

    else
        return false;
}

/* although missplleing its ok*/

bool criteria(char a, char b)
{

    bool condition = false;
    a = tolower(a);
    b = tolower(b);

    
    if ((a == 'v' || a == 'w') && (b == 'v' || b == 'w')) 
        condition = true;
    if ((a == 'b' || a == 'f' || a == 'p') && (b == 'b' || b == 'f' || b == 'p')) 
        condition = true;
    if ((a == 'g' || a == 'j') && (b == 'g' || b == 'j')) 
        condition = true;
    if ((a == 'c' || a == 'k' || a == 'q') && (b == 'c' || b == 'k' || b == 'q')) 
        condition = true;
    if ((a == 's' || a == 'z') && (b == 's' || b == 'z')) 
        condition = true;
    if ((a == 'd' || a == 't') && (b == 'd' || b == 't')) 
        condition = true;
    if ((a == 'o' || a == 'u') && (b == 'o' || b == 'u')) 
        condition = true;
    if ((a == 'i' || a == 'y') && (b == 'i' || b == 'y')) 
        condition = true;

    return condition;
}

} 