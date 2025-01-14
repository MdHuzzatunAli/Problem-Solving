#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class RandomizedSet {
    vector<int> vct;
public:
    RandomizedSet() {
        cout << "Randomized set initialized\n";
    }
    
    bool insert(int val) {
        int index = findIndex(val);
        if(index == -1){
            vct.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        int index = findIndex(val);
        if(index != -1){
            vct.erase(vct.begin()+index);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int min = 0;
        int max = vct.size()-1;
    
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> distrib(min, max);
        int random_num = distrib(gen); 

        return vct[random_num];
    }

    int findIndex(int num) {
        auto it = find(vct.begin(), vct.end(), num);
        if(it != vct.end())   return (it - vct.begin());
        return -1;
    }

    void showSet() {
        for(int i=0; i<vct.size(); i++) cout << vct[i] << "  ";
        cout << "\n";
    }
};

int main()
{
   RandomizedSet *obj = new RandomizedSet;
   cout << obj->insert(1) << "\n";
   cout << obj->remove(2) << "\n";
   cout << obj->insert(2) << "\n";
   obj->showSet();
   cout << obj->getRandom() << "\n";
   cout << obj->remove(1) << "\n";
   cout << obj->insert(2) << "\n";
   obj->showSet();
   cout << obj->getRandom() << "\n";
}



/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */