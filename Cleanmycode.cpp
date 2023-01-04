#include <bits/stdc++.h>

using namespace std;


int main()
{
    string cleanthiscode;
    bool multicomment = 0;
    while (getline(cin, cleanthiscode))
    {
        bool notcomment = false;
        if (cleanthiscode.size() == 0 || cleanthiscode == " ")
        {
            continue;
        }

        for (int i = 0; i < cleanthiscode.size(); i++)
        {
            if (cleanthiscode[i] == '/' && cleanthiscode[i + 1] == '/' && !multicomment)
            {
                break;
            }
            else if (cleanthiscode[i] == '/' && cleanthiscode[i + 1] == '*')
            {
                i++;
                multicomment = true;
            }
            else if (cleanthiscode[i] == '*' && cleanthiscode[i + 1] == '/' && multicomment)
            {
                i++;
                multicomment = false;
            }
            else if (!multicomment)
            {

                cout << cleanthiscode[i];
                notcomment = true;
            }
        }

        if (notcomment && !multicomment)
            cout << endl;
    }
}