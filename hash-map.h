#include <list>
#include <vector>
#include <iostream>
#include <typeindex>
#include <cmath>
#define ull unsigned long long
#define maxCoef 2.0

template <typename K, typename V, typename Hash = std::hash<K>>
class HashMap
{
private:
    Hash hash;
    ull size;
    ull amountElements;
    std::vector<std::list<std::pair<K, V>>> array;

    void rehash(ull newSize)
    {
        if ((double)amountElements / (double)newSize > maxCoef){
            newSize = ceil(amountElements/maxCoef); 
        }
        std::vector<std::list<std::pair<K, V>>> temp(newSize);
        for (int i = 0; i < array.size(); i++)
        {
            for (auto j : array[i])
            {
                temp[hash(j.first) % newSize].push_front(j);
            }
            array[i].clear();
        }
        size = newSize;
        array = temp;
    }

public:
    V &operator[](K key)
    {
        ull temp = hash(key) % size;
        for(auto it = array[temp].begin(); it != array[temp].end(); it++){
            if((*it).first == key){
                return (*it).second;
            }
        }
        return array[0].front().second;
    }

    HashMap()
    {
        size = 0;
        amountElements = 0;
    }

    void insert(K key, V data)
    {
        amountElements++;
        if (size > 0)
        {
            if (((double)amountElements / (double)size) > maxCoef)
            {
                rehash(2 * size + 1);
            }
        } else {
            rehash(1);
        }
        array[hash(key) % size].push_front(std::make_pair(key, data));
    }

    void del(K key){
        ull temp = hash(key) % size;
        for(auto it = array[temp].begin(); it != array[temp].end(); it++){
            if((*it).first == key){
                array[temp].erase(it);
                amountElements--;
                break;
            }
        }
    }

    double getCoef(){
        return (double)amountElements / (double)size;; 
    }

    void clear(){
        array.clear();
    }

    void setCoef(double newCoef){
        if(newCoef <= 0.0){
            return; 
        }  
        rehash(ceil((double)amountElements/newCoef)); 
    }

    ull getSize(){
        return amountElements; 
    }

    void print(){
        // for(auto i : array){
        //     for(auto j : i){
        //         std::cout << "["<<j.first << ", " << j.second << "] ";
        //     }
        //     std::cout << std::endl;
        // }
        std::cout << "vector size = " << size << "\n";
    }
};