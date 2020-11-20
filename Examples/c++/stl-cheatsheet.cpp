#include <bits/stdc++.h>
using namespace std;

struct CustomStruct {
    int i = 0;

    bool operator<(const CustomStruct& rhs) const {
        return this->i > rhs.i;
    }
};

int main() {
    /* ARRAY */
    int* arr = new int[5]{0};      // Initialize with 0s
    for (int i = 0; i < 5; i++) {  // Iterate using index
        cout << arr[i] << ' ';
    }

    /* VECTOR */
    auto vec = vector<int>(3, 0);  // Initial size = 3, Initialize with 0s
    vec[0] = 1;
    vec.push_back(6);                 // Append new item
    vec.pop_back();                   // Remove last item
    vec.clear();                      // Remove all elements
    vec.resize(3);                    // Change size
    vec.reserve(5);                   // Change capacity
    int vec_1 = vec[1];               // Access index
    int vec_2 = vec.at(2);            // Access index == vec[2]
    int vec_front = vec.front();      // First item == vec[0]
    int vec_back = vec.back();        // Last item == vec[vec.size() - 1]
    vec.insert(vec.begin() + 2, 42);  // Insert 42 at index 2
    vec.erase(vec.begin() + 2);       // Remove item at index 2

    // Iterate using index
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    // Iterate using iterator (element can be int or int&)
    for (int& element : vec) {
        cout << element << ' ';
    }
    // Iterate using iterator
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << ' ';
    }

    /* STACK */
    stack<int> stk;
    stk.push(5);                // Add new element to top
    int stk_top = stk.top();    // View the top element
    stk.pop();                  // Remove the top element
    int stk_size = stk.size();  // Get the size

    /* QUEUE */
    queue<int> que;
    que.push(5);                  // Add new element to the back
    int que_front = que.front();  // Get the front element
    int que_back = que.back();    // Get the back element
    que.pop();                    // Remove the front element
    que.size();                   // Get the size

    /* DEQUEUE */
    deque<int> dec;
    dec.push_back(1);             // Add element to back
    dec.push_back(2);             // Add element to back
    dec.push_front(0);            // Add element to front
    dec.pop_back();               // Remove element from back
    dec.pop_front();              // Remove element from front
    int dec_front = dec.front();  // Get front element
    int dec_back = dec.back();    // Get back element
    dec.clear();                  // Remove all elements

    /* LIST */
    list<int> lis;
    lis.push_back(1);             // Add element to back
    lis.push_back(2);             // Add element to back
    lis.push_front(0);            // Add element to front
    lis.pop_back();               // Remove element from back
    lis.pop_front();              // Remove element from front
    int lis_front = lis.front();  // Get front element
    int lis_back = lis.back();    // Get back element
    lis.reverse();                // Reverse
    lis.sort();                   // Sort
    lis.clear();                  // Remove all elements

    // Insert element at position 1
    auto insertIndex = lis.begin();
    advance(insertIndex, 1);
    lis.insert(insertIndex, 42);

    // Erase element at position 0
    auto removeIndex = lis.begin();
    advance(removeIndex, 0);
    lis.erase(removeIndex);

    /* HEAP */
    priority_queue<int> pq;
    priority_queue<CustomStruct> pq_custom;  // Use custom compare function
    pq.push(10);                             // Add new element
    int top = pq.top();                      // Peek top
    pq.pop();                                // Pop top
    pq.size();                               // Get size

    /* SET */
    set<int> st;
    set<CustomStruct> st_custom;  // Use custom compare function
    st.insert(1);
    st.insert(2);
    st.insert(42);                       // Add element
    int st_min = *st.begin();            // Get min element
    int st_max = *st.rbegin();           // Get max element
    st.size();                           // Get the size
    st.erase(1);                         // Remove element
    st.erase(st.begin());                // Remove element
    int st_count = st.count(42);         // Count occurrences, always 1 or 0
    auto st_hook = st.find(42);          // Valid iterator to the element if found, otherwise st.end()
    auto st_lower = st.lower_bound(42);  // Iterator to the first element >= 42
    auto st_upper = st.upper_bound(42);  // Iterator to the first element > 42
    st.clear();                          // Remove all elements

    // Iterate set
    for (auto st_el : st) {
        cout << st_el << ' ';
    }

    /* UNORDERED_SET */
    unordered_set<int> ust;
    ust.insert(5);                // Add element
    ust.insert(-1);               // Add element
    ust.erase(-1);                // Remove elemnt
    int ust_5s = ust.count(5);    // Count occurrences, always 1 or 0
    auto ust_five = ust.find(5);  // Iterator to the element if found, otherwise ust.end()
    ust.clear();                  // Remove all elements

    /* UNORDERED_MULTISET */
    unordered_multiset<int> umst;
    umst.insert(5);                 // Add element
    umst.insert(-1);                // Add element
    umst.erase(-1);                 // Remove elemnt
    int umst_5s = umst.count(5);    // Count occurrences
    auto umst_five = umst.find(5);  // Iterator to the element if found, otherwise ust.end()
    umst.clear();                   // Remove all elements

    /* MAP */
    map<int, int> mp;
    mp.insert(pair<int, int>(-1, -100));  // Insert or change with key-value pair
    mp[12] = 144;                         // Insert or change by key
    mp.erase(-1);                         // Remove element by key
    int mp_count5 = mp.count(12);         // Count occurrences of key, always 1 or 0
    auto mp_five = mp.find(5);            // Iterator to the element if found, mp.end() otherwise
    mp.clear();                           // Remove all elements

    // Iterate map where mp_el is (key,value)
    for (auto mp_el : mp) {
        cout << mp_el.first << ": " << mp_el.second << ' ';
    }

    /* MULTIMAP */
    multimap<int, int> mmp;
    mmp.insert(pair<int, int>(5, -100));  // Insert change with key-value pair
    mmp.insert(pair<int, int>(5, -200));  // Insert change with key-value pair
    mmp.erase(5);                         // Removes all occurrences by key
    int mmp_count5 = mmp.count(5);        // Count occurrences of key
    auto mmp_five = mmp.find(5);  // Iterator to the element if found, mp.end() otherwise
    mmp.clear();                  // Remove all elements

    // Iterate multimap where mp_el is (key,value)
    for (auto mmp_el : mmp) {
        cout << mmp_el.first << ": " << mmp_el.second << ' ';
    }

    /* UNORDERED_MAP */
    unordered_map<int, int> ump;
    ump.insert(pair<int, int>(-1, -100));  // Insert or change with key-value pair
    ump[12] = 144;                         // Insert or change by key
    ump.erase(-1);                         // Remove element by key
    int ump_count5 = ump.count(12);        // Count occurrences, always 1 or 0
    auto ump_five = ump.find(5);           // Iterator to the element if found, mp.end() otherwise
    ump.clear();                           // Remove all elements

    /* ALGORITHM */
    int vec_max = *max_element(vec.begin(), vec.end());                                // Get max element
    int vec_min = *min_element(vec.begin(), vec.end());                                // Get min element
    sort(vec.begin(), vec.end());                                                      // Sort
    stable_sort(vec.begin(), vec.end());                                               // Sort
    sort(vec.begin(), vec.end(), [](auto a, auto b) { return a > b; });                // Sort with custom function
    next_permutation(vec.begin(), vec.end());                                          // Get the next permutation
    replace(vec.begin(), vec.end(), 0, 42);                                            // Replace all occurrences of 0 with 42
    auto pivot_it = partition(vec.begin(), vec.end(), [](auto a) { return a < 15; });  // Partition and return iterator to pivot
    nth_element(vec.begin(), vec.begin() + 2, vec.end());                              // Rearrange elements so nth is the pivot
    int count_42s = count(vec.begin(), vec.end(), 42);                                 // Count the occurrences of 42
    auto first_42 = find(vec.begin(), vec.end(), 42);                                  // Iterator to the first occurrence of 42
    auto vec_lower = lower_bound(vec.begin(), vec.end(), 42);                          // Iterator to the first element >= 42
    auto vec_upper = upper_bound(vec.begin(), vec.end(), 42);                          // Iterator to the first element > 42
    bool found_42 = binary_search(vec.begin(), vec.end(), 42);                         // True if 42 exists in the sorted collection
    // Shuffle
    std::random_device dev;
    std::mt19937 g(dev());
    shuffle(vec.begin(), vec.end(), g);  // Shuffle array
}
