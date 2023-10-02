#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

namespace week1
{

void printArray(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl; 
}

void plusMinus(vector<int> arr)
{
    int positiveValues = 0;
    int negativeValues = 0;
    int zeros = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        if(num > 0) 
        {
            positiveValues++;
        }
        else if(num < 0)
        {
            negativeValues++;
        }
        else if(num == 0)
        {
            zeros++;
        }
    }
    
    cout << fixed;
    cout << setprecision(6) << (float) positiveValues / (float) arr.size() << endl;
    cout << setprecision(6) << (float) negativeValues/ (float) arr.size() << endl;
    cout << setprecision(6) << (float) zeros/ (float) arr.size() << endl;
}

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    printArray(arr);
    unsigned int minSum = accumulate(arr.begin(), --arr.end(), 0);
    unsigned int maxSum = accumulate(++arr.begin(), arr.end(), 0);
    cout << minSum << " " << maxSum;
}

void testMinMaxSum()
{
    vector<int> arr(5);
    arr[0] = 256741038;
    arr[1] = 623958417;
    arr[2] = 467905213;
    arr[3] = 714532089;
    arr[4] = 938071625;
    //arr[5] = 1;
    
    week1::miniMaxSum(arr);
}

string timeConversion(string s)
{
    string timeIndicator = s.substr(8,2);
    string militaryTimeFormat = s.substr(0,8);
    string hour = s.substr(0,2);
    string minuteSecond = s.substr(2,6);

    if (timeIndicator == "AM")
    {
        if (hour == "12") return "00" + minuteSecond;
        else return militaryTimeFormat;
    }

    if (timeIndicator == "PM")
    {
        if (hour == "12") return militaryTimeFormat;
        else
        {
            //int hourInt = stoi(hour);
            //return to_string(hourInt + 12) + minuteSecond;
        }
    }

    return "Invalid Time Format";
}

void testTimeConversion()
{
    cout << timeConversion("100:00:00PM") << endl;
}

void camelCase()
{
    string user_input;
    string result;
    cin >> user_input;

    char operation_type = user_input[0];
    char text_type = user_input[2];
    string text = user_input.substr(4);
    const regex pattern("^(?=.*[A-Z])");
    // cout << text;
    if (operation_type == 'S')
    {
        switch (text_type)
        {
            case 'M':
                std::smatch m{};
                regex_search(text, m, pattern);
                cout << m.position();
                break;
        }
        

    }

}

void run()
{
    camelCase();
}

}