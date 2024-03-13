#include <iostream>
#include <list>

using namespace std;

bool customCompare(int a, int b) {
    return a < b;
}

list<int> mergeSortedLists(const list<int>& list1, const list<int>& list2) {
    list<int> mergedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            mergedList.push_back(*it1);
            ++it1;
        }
        else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }

    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }

    return mergedList;
}

void customSort(list<int>& myList) {
    for (auto it1 = myList.begin(); it1 != myList.end(); ++it1) {
        for (auto it2 = next(it1); it2 != myList.end(); ++it2) {
            if (customCompare(*it2, *it1)) {
                swap(*it1, *it2);
            }
        }
    }
}

int main() {
    list<int> myList;


    int num;
    cout << "Enter values for sorting(enter -1 to stop): ";
    while (true) {
        cin >> num;
        if (num == -1)
            break;
        myList.push_back(num);
    }


    customSort(myList);

    cout << "Sorted list: ";
    for (auto num : myList) {
        cout << num << " ";
    }
    cout << endl;
    cout << "*******" << endl;
    list<int> list1, list2;

    cout << "Enter values for the first list (enter -1 to stop): ";
    while (true) {
        cin >> num;
        if (num == -1)
            break;
        list1.push_back(num);
    }
   cout << "Enter values for the second list (enter -1 to stop): ";
    while (true) {
        cin >> num;
        if (num == -1)
            break;
        list2.push_back(num);
    }
list<int> mergedList = mergeSortedLists(list1, list2);

    cout << "Merged list: ";
    for (auto num : mergedList) {
        cout << num << " ";
    }
    cout << endl;
    cout << "*****" << endl;


    return 0;
}