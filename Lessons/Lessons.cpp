
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "VectorTemplates.h"

using namespace std;
using namespace std::placeholders;

bool isMaxEqual(int x, int max)
{
    return x == max;
}

int rnd()
{
    return rand() % 100;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> i_vec(10);
    /*for (int i = 0; i < 10; ++i) {
    	//i_vec.push_back(rand() % 100);
        i_vec.push_back(i);
    }*/
    generate(i_vec.begin(), i_vec.end(), rnd);

	i_vec.insert(i_vec.begin() + 3, 9);

    PrintVector(i_vec);

    const auto min_iter = min_element(i_vec.begin(), i_vec.end());
    const auto max_iter = max_element(i_vec.begin(), i_vec.end());

    cout << "Min = " << *min_iter << endl;
    cout << "Max = " << *max_iter << endl;
    auto max = *max_iter;
    //const auto removed = remove_if(i_vec.begin(), i_vec.end(), [max](const int x) { return x == max;});
    const auto removed = remove_if(i_vec.begin(), i_vec.end(),bind(isMaxEqual, _1, max));
	i_vec.erase(removed, i_vec.end());

    cout << "After deleting: " << endl;
    for (const int el : i_vec) {
        cout << el << endl;
    }

    cout << "Size: " << i_vec.size() << endl;
    cout << "Cap: " << i_vec.capacity() << endl;
    i_vec.shrink_to_fit();
}

