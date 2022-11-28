#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <map>
namespace bml {

template <class T>
class ItemCounter {
protected:
    std::map<T,unsigned> counters;
public:
    unsigned add(const T &item) {
        auto itr = counters.find(item);
        if (itr==counters.end()) {
            counters.insert(std::make_pair(item,1));
        } else itr->second++;
        return itr->second;
    }

    unsigned remove(const T &item) {
        auto itr = counters.find(item);
        if (itr!=counters.end()) {
            itr->second--;
            if (itr->second==0) {
                counters.erase(item);
                return 0;
            } else return itr->second;
        }
        return 0;
    }

    unsigned count(const T &item) {
        auto itr = counters.find(item);
        if (itr==counters.end()) return 0;
        return itr->second;
    }
};



} // Eof namespace


#endif // ITEMCOUNTER_H
