#ifndef HASH_MAP_H
#define HASH_MAP_H
using namespace std;
template<typename T>
class Pair
{
public:
    T val;
    int key;
    Pair<T>* next;
    Pair(T x, int y) :val(x), key(y), next(nullptr) {}
};
template<typename T>
class HashMap
{
    Pair<T>** list;
    int Hashing(int key);
public:
    HashMap();
    void put(int key, T value);
    T get(int key);
    void remove(int key);
    bool contains(int key);
};
#endif