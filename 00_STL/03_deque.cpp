#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    d.pop_front();
    d.pop_back();
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "first index element " << d.at(0) << endl;
    cout << "element at front " << d.front() << endl;
    cout << "element at back " << d.back() << endl;
    cout << "empty or not " << d.empty() << endl;
    cout << "before erase " << d.size() << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    d.erase(d.begin(), d.begin() + 1);
    cout << "after erase " << d.size() << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}