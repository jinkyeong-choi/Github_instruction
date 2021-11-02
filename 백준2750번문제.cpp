// 백준 수 정렬하기 -> 2750번 문제 
// 분명 완전하게 잘나오는데 틀렸다고 뜬다!
#include <iostream>
#include <vector>
using namespace std;

vector<int> Calculator(int N);
void Print(vector<int> count);

int main()
{
    int N = 0;

    while (true)
    {
        cin >> N;
        if (1 <= N && N <= 100)
            break;
    }

    vector<int> count(N);
    count = Calculator(N);
    Print(count);
}

vector<int> Calculator(int N)
{
    vector<int> count(N);

    for (int i = 0; i < N; i++)
    {
        bool yesno = true;
        int temp = 0;

        cin >> temp;

        if (!(-1000 <= temp && temp <= 1000))
        {
            i--;
            continue;
        }

        for (int j = 0; j < i; j++)
        {
            if (count[j] == temp)
            {
                yesno = false;
                break;
            }
        }

        if (yesno == false)
        {
            i--;
            continue;
        }

        count[i] = temp;
    }

    return count;
}

void Print(vector<int> count_copy)
{
    vector<int> count = count_copy;

    for (int i = 0; i < count.size()-1; i++)
    {
        //for (int j = 1; j <= i; j++)
        //{
        //    if (count[j - 1] > count[j])
        //    {
        //        int temp = count[j - 1];
        //        count[j - 1] = count[j];
        //        count[j] = temp;
        //    }
        //}


        int min = count[i];

        for (int j = i+1; j < count.size(); j++)
        {
            if (count[i] > count[j])
            {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }

        //cout << count[0] << count[1] << count[2] << count[3] << count[4] << endl;
    }

    for (int i = 0; i < count.size(); i++)
    {
        cout << count[i] << endl;
    }
}
