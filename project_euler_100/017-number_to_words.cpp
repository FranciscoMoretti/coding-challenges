#include <bits/stdc++.h>

using namespace std;

void add_to_words(string &words, string number)
{
    words += words.size() > 0 ? " " : "";
    number[0] = toupper(number[0]);
    words += number;
}

string three_digits_to_words(string number)
{

    int len = number.size(); // Get number of digits in given number
    string words;
    if (len == 0)
    {
        cout << "empty string" << endl;
        return "";
    }
    else if (len > 3)
    {
        cout << "Length more than 3 is not supported" << endl;
        return "";
    }
    vector<string> single_digits = {"", "one", "two",
                                    "three", "four", "five",
                                    "six", "seven", "eight", "nine"};
    vector<string> two_digits = {"ten", "eleven", "twelve",
                                 "thirteen", "fourteen",
                                 "fifteen", "sixteen",
                                 "seventeen", "eighteen", "nineteen"};
    vector<string> tens_multiple = {"", "", "twenty", "thirty", "forty", "fifty",
                                    "sixty", "seventy", "eighty", "ninety"};
    string r_number = number;
    reverse(r_number.begin(), r_number.end());
    for (int i = r_number.size() - 1; i >= 0; i--)
    {
        char digit = r_number[i];
        if (digit == '0')
        {
            continue;
        }
        char nextDigit = i > 0 ? r_number[i - 1] : 'F';
        switch (i)
        {
        case 2:
            add_to_words(words, single_digits[digit - '0']);
            add_to_words(words, "hundred");
            break;
        case 1:
            if (digit == '1')
            {
                int second = nextDigit - '0';
                add_to_words(words, two_digits[second]);
                i--;
            }
            else
            {
                add_to_words(words, tens_multiple[digit - '0']);
            }
            break;
        case 0:
            add_to_words(words, single_digits[digit - '0']);
            break;
        default:
            assert(0 && "should never reach this line");
            break;
        }
    }
    return words;
}

string number_to_words(string number)
{
    int len = number.size(); // Get number of digits in given number
    string words;

    /* Base cases */
    if (len == 0)
    {
        cout << "empty string" << endl;
        return "";
    }
    else if (len > 14)
    {
        cout << "Length more than 14 is not supported" << endl;
        return "";
    }
    else if (len == 1 && number[0] == '0')
    {
        add_to_words(words, "zero");
        return words;
    }

    vector<string> thousand_power = {"", "thousand", "million", "billion", "trillion"};

    while (len > 0)
    {
        int digits = len % 3 > 0 ? len % 3 : 3;
        string portion = three_digits_to_words(number.substr(0, digits));
        len -= digits;
        number = number.substr(digits, len);
        if (portion.size() > 0)
        {
            add_to_words(words, portion);
            if (len / 3 > 0)
            {
                add_to_words(words, thousand_power[len / 3]);
            }
        }
    }
    return words;
}

int main()
{
    int t;
    cin >> t;
    string number;
    for (int i = 0; i < t; ++i)
    {
        cin >> number;
        string words = number_to_words(number);
        cout << words << endl;
    }
    return 0;
}