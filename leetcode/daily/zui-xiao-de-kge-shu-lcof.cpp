#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vec;
    for (auto i : arr)
        pq.push(i);
    while (k--)
    {
        vec.push_back(pq.top());
        pq.pop();
    }
    return vec;
}

int main()
{
    vector<int> arr{3, 2, 1};
    vector<int> vec = getLeastNumbers(arr, 2);
    for (auto i : vec)
        cout << i << endl;
}