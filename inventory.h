#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Item{
    string name_;
    int price_;
    void PrintInfo() const{
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
    int GetPrice() const {return price_;}
};

template <typename U>
inline bool compareItemsByPrice(const U& a, const U& b) {
    return a.GetPrice() < b.GetPrice();
}

template <typename T>
class Inventory{
private:
    T* pItems;
    int capacity;
    int size_;
public:
    Inventory(int cap = 10) : pItems(nullptr), capacity(cap<=0?1:cap),size_(0){
        pItems = new T[capacity];
    };

    ~Inventory(){
        delete[] pItems;
        pItems = nullptr;
    };

    Inventory(const Inventory<T>& other) {
        capacity = other.capacity;
        size_ = other.size_;
        pItems = new T[capacity];
        for (int i = 0; i < size_; ++i) {
            pItems[i] = other.pItems[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }
    
    void Assign(const Inventory<T>& other){
        delete[] pItems;
        capacity = other.capacity;
        size_ = other.size_;
        pItems = new T[capacity];
        for (int i = 0; i < size_; ++i) {
            pItems[i] = other.pItems[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }
   
    
    void AddItem(const T& item){
        if(capacity<=size_) Resize(capacity*2);
        pItems[size_++] = item;
    }

    void Resize(int newCapacity){
        // resize는 용량 변경
        // 용량 커지게 된다면 새로운 배열을 선언하여 사이즈만큼 카피해서 넣으면 되고
        // 용량이 작아진다면 새로운 배열에 용량만큼 카피해서 넣으면 된다.
        int cap = (newCapacity<1?1:newCapacity);
            if(capacity == cap) return;
        
        T* newArr = new T[cap];
        int toCopy = (size_<cap?size_:cap);
        for(int i = 0 ; i < toCopy; i++) newArr[i] = pItems[i];

        delete[] pItems;
        pItems = newArr;
        capacity = cap;
        if(size_>cap) size_ = cap;
    }

    void SortItems(){
        sort(pItems, pItems+size_, compareItemsByPrice<T>);
    }
    
    void RemoveLastItem(){
        if(size_>0) --size_;
        else cout << "인벤토리가 비어있습니다." ;
    }
    
    int GetSize() const {return size_;}
    
    int GetCapacity() const {return capacity;}
    
    void const PrintAllItems(){
        if(size_==0) {cout << "비어있음\n"; return;}
        for(int i = 0; i < size_; i++){
            pItems[i].PrintInfo();
        }
    }


};


