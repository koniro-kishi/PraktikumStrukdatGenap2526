#include <bits/stdc++.h>
using namespace std;

vector<int> getValues()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i + 1);

    return v;
}

int main()
{
    vector<int> get;
    get = getValues();

    // Menggunakan iterator untuk mengakses elemen vektor
    vector<int>::iterator it;
    for (it = get.begin(); it != get.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}

// SOLUSI

// int main()
// {
//     vector<int> get;
//     get = getValues();

//     // Menggunakan iterator untuk mengakses elemen vektor
//     vector<int>::iterator it;
//     for (it = get.begin(); it != get.end(); ++it)
//         cout << *it << " ";
//     cout << endl;


//     // solusi pakai pop back

//     // int size = get.end() - get.begin();
//     // // int size = v.size()

//     // for (int i = 0; i < size; i++)
//     // {
//     //     get.pop_back();
//     // }


//     // solusi pakai erase
//     // get.erase(get.begin(), get.end());


//     // solusi pakai clear
//     // get.clear();


//     cout << get.size();

//     return 0;
// }