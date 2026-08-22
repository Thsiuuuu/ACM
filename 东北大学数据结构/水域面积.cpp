#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#define endl "\n"
using namespace std;

struct region
{
    int start;
    int width;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<int> left; 
    vector<region> areas;

    string str;
    cin >> str;

    int totalArea = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\\')
        {
            left.push(i);
        }
        else if (str[i] == '/' && !left.empty())
        {
            int leftIndex = left.top();
            left.pop();
            int width = i - leftIndex;
            totalArea += width;

            while (!areas.empty() && areas.back().start > leftIndex)
            {
                width += areas.back().width;
                areas.pop_back();
            }

            areas.push_back({leftIndex, width});
        }
    }

    cout << totalArea << endl;

    cout << areas.size() << ' ';
    for (const auto &i : areas)
    {
        cout << i.width << ' ';
    }
    cout << endl;

    return 0;
}