#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <map>
namespace bml {

/**
 * @brief A class that counts items
 *
 */
template <class T>
class ItemCounter {
protected:
    std::map<T,unsigned> counters;
public:
    /**
     * @brief add : add or increase the counter of item
     * @param item
     */
    unsigned add(const T &item) {
        auto itr = counters.find(item);
        if (itr==counters.end()) {
            counters.insert(std::make_pair(item,1));
        } else itr->second++;
        return itr->second;
    }

    /**
     * @brief remove : decrease the count of item
     * @param item
     */
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

    /**
     * @brief removeAll : set the count of item to zero
     * @param item
     */
    unsigned removeAll(const T &item) {
        counters.erase(item);
        return 0;
    }

    /**
     * @brief count : the count of item
     * @param item
     */
    unsigned count(const T &item) {
        auto itr = counters.find(item);
        if (itr==counters.end()) return 0;
        return itr->second;
    }

    /**
     * @brief clear al counters
     */
    void clear()
    {
        counters.clear();
    }
};



} // Eof namespace


#endif // ITEMCOUNTER_H
