
/*
Implement stack and also which can return the min and max element in the stack
*/

#include <iostream>
#include <vector>
#include<set>
using namespace std;

template<typename T>
class customStack {
    private: 
        vector<T> items;
        set<T> s;
        int max_size;
        
    public:
        customStack(int m):max_size(5) {}
        ~customStack();
        
        void push(T e);
        void pop();
        T top();
        T min();
        T max();
        
        customStack() = delete;
        
        customStack(const customStack&) = delete;
        customStack(customStack&& ) = delete;
        customStack& operator = (const customStack&) = delete;
        customStack& operator = (customStack&&) = delete;
        
};

template<typename T>
customStack<T>::~customStack() {
    cout<<"Destructor is called";
    items.clear();
    s.clear();
}

template<typename T>
void customStack<T>::push(T e) {
    items.emplace_back(e);
    s.insert(e);
}

template<typename T>
void customStack<T>::pop() {
    T i = items.back();
    items.pop_back();
    s.erase(i);
}

template<typename T>
T customStack<T>::top() {
    return items.back();
}

template<typename T>
T customStack<T>::min() {
    return *s.begin();
}

template<typename T>
T customStack<T>::max() {
    return *s.rbegin();
}

int main()
{
    std::cout<<"Jai Shree Ram";
    customStack<int> st(5);
    st.push(3);
    st.push(10);
    st.push(5);
    st.push(15);
    st.push(2);
    cout<<"-----------------"<<endl;
    cout<<"Min "<<st.min()<<endl;
    cout<<"Max "<<st.max()<<endl;
    cout<<"top "<<st.top()<<endl;;
    cout<<"-----------------"<<endl;
    st.pop();
    
    cout<<"Min "<<st.min()<<endl;
    cout<<"Max "<<st.max()<<endl;
    cout<<"top "<<st.top()<<endl;
    cout<<"-----------------"<<endl;
    st.pop();
    
    cout<<"Min "<<st.min()<<endl;
    cout<<"Max "<<st.max()<<endl;
    cout<<"top "<<st.top()<<endl;
    cout<<"-----------------"<<endl;
    st.push(0);
    cout<<"Min "<<st.min()<<endl;
    cout<<"Max "<<st.max()<<endl;
    cout<<"top "<<st.top()<<endl;
    st.push(52);

    cout<<"Min "<<st.min()<<endl;
    cout<<"Max "<<st.max()<<endl;
    cout<<"top "<<st.top()<<endl;
}
/*
Jai Shree Ram-----------------
Min 2
Max 15
top 2
-----------------
Min 3
Max 15
top 15
-----------------
Min 3
Max 10
top 5
-----------------
Min 0
Max 10
top 0
Min 0
Max 52
top 52
Destructor is called
*/
