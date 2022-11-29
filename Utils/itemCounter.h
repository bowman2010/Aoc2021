#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <map>
#include <vector>
#include <climits>

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
     * @param count : how many are added
     * @param item
     */
    unsigned add(const T &item, unsigned count=1) {
        auto itr = counters.find(item);
        if (itr==counters.end()) {
            counters.insert(std::make_pair(item,count));
        } else itr->second+=count;
        return itr->second;
    }

    /**
     * @brief remove : decrease the count of item
     * @param item
     * @param count : how many are removed
     * @param del : if true, element is removed from map else count set to zero
     */
    unsigned remove(const T &item, unsigned count=1, bool del=true) {
        auto itr = counters.find(item);
        if (itr!=counters.end()) {
            if (itr->second<=count) {
                if (del) counters.erase(item);
                return 0;
            }
            else {
                itr->second -= count;
                return itr->second;
            }
        }
        return 0;
    }

    /**
     * @brief removeAll : set the count of item to zero
     * @param item
     * @param del : if true, element is removed from map else set count to zero
     */
    unsigned removeAll(const T &item, bool del=true) {
        auto itr = counters.find(item);
        if (itr!=counters.end()) {
            if (del) counters.erase(item);
            else itr->second = 0;
        }
        return 0;
    }

    /**
     * @brief clear al counters
     * @param del : if true, elements areremoved from map else their count are set to zero
     */
    void reset(bool del=true)
    {
        if (!del) {
            counters.clear();
        } else {
            for (auto p = counters.begin(); p<counters.end; p++)
                p->second=0;
        }
    }

    /**
     * @brief count : the count of item
     * @param item
     */
    unsigned count(const T &item) const {
        auto itr = counters.find(item);
        if (itr==counters.end()) return 0;
        return itr->second;
    }

    /**
     * @brief low : lowest items count
     * @return a vector of pairs of <item,counter>
     */
    std::vector<std::pair<T&,unsigned>> lowests() const {
        unsigned low = UINTMAX_MAX;
        std::vector<std::pair<T&,unsigned>> vec;

        for (auto itr=counters.begin(); itr<counters.end(); itr++)
        {
            if (itr->second==low) vec.push_back(*itr);
            else if(itr->second < low) {
                vec.clear();
                vec.push_back(*itr);
            }
        }
        return vec;
    }

    /**
     * @brief high : highest count
     * @return a vector of pairs of <item,counter>
     */
    std::vector<std::pair<T&,unsigned>> highests() const {
        unsigned high = 0;
        std::vector<std::pair<T&,unsigned>> vec;
        for (auto itr=counters.begin(); itr<counters.end(); itr++)
        {
            if (itr->second==high) vec.push_back(*itr);
            else if(itr->second > high) {
                vec.clear();
                vec.push_back(*itr);
            }
        }
        return vec;
   }

    /**
     * @brief low : get the lowest count
     * @return an unsigned
     */
    unsigned low() const {
        unsigned low = UINTMAX_MAX;
        if (counters.size()==0) return 0;
        for (auto itr=counters.begin(); itr<counters.end(); itr++)
            if (itr->second < low) low=itr->second;
        return low;
    }

    /**
     * @brief high : get the highest count
     * @return an unsigned
     */
    unsigned high() const {
        unsigned high = 0;
        if (counters.size()==0) return 0;
        for (auto itr=counters.begin(); itr<counters.end(); itr++)
            if (itr->second > high) high=itr->second;
        return high;
    }
};



} // Eof namespace


#endif // ITEMCOUNTER_H
