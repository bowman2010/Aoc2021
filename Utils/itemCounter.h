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
    unsigned remove(const T &item, unsigned count=1, bool del=false) {
        auto itr = counters.find(item);

        if (itr!=counters.end()) {

            if (itr->second <= count)
                itr->second=0;
                else return itr->second-=count;

            if (del && itr->second==0) {
                counters.erase(item);
                return 0;
            }
        } else return 0; // item not found
    }

    /**
     * @brief removeAll : set the count of item to zero
     * @param item
     * @param del : if true, element is removed from map else set count to zero
     */
    unsigned removeAll(const T &item, bool del=false) {
        auto itr = counters.find(item);
        if (itr!=counters.end()) {
            if (del) counters.erase(item);
            else itr->second = 0;
        }
        return 0;
    }

    /**
     * @brief clear al counters
     * @param del : if true, elements are removed from map else their count are set to zero
     */
    void clear()
    {
        counters.clear();
    }

    /**
     * @brief itemsCount : the number of counters
     */
    unsigned itemsCount()
    {
        return counters.size();
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

//    /**
//     * @brief lowests : lowest items count
//     * @return a vector of pairs of <item,counter>
//     */
//    std::vector<std::pair<T,unsigned>> lowests() const {
//        unsigned low = UINT_MAX;
//        std::vector<std::pair<T&,unsigned>> vec;
//
//        for (auto data: counters) {
//            if (data.second==low) vec.push_back(data);
//            else if(data.second<low) {
//                low=data.second;
//                vec.clear();
//                vec.push_back(std::make_pair(data.first,data.second));
//            }
//        }
//        return vec;
//    }
//
//    /**
//     * @brief high : highest count
//     * @return a vector of pairs of <item,counter>
//     */
//    std::vector<std::pair<T&,unsigned>> highests() const {
//        unsigned high = 0;
//        std::vector<std::pair<T&,unsigned>> vec;
//        for (auto itr=counters.begin(); itr!=counters.end(); itr++)
//        {
//            if (itr->second==high) vec.push_back(*itr);
//            else if(itr->second > high) {
//                high = itr->second;
//                vec.clear();
//                vec.push_back(*itr);
//            }
//        }
//        return vec;
//   }

    /**
     * @brief min : get the minimum count
     * @return an unsigned
     */
    unsigned min() const {
        unsigned min = UINT_MAX;
        if (counters.size()==0) return 0;
        for (auto itr=counters.begin(); itr!=counters.end(); itr++)
            if (itr->second < min) min=itr->second;
        return min;
    }

    /**
     * @brief max : get the maximum count
     * @return an unsigned
     */
    unsigned max() const {
        unsigned max = 0;
        for (auto itr=counters.begin(); itr!=counters.end(); itr++)
            if (itr->second > max) max=itr->second;
        return max;
    }

    unsigned sum() const {
        unsigned sum = 0;
        for (auto itr=counters.begin(); itr!=counters.end(); itr++)
            sum += itr->second;
        return sum;
    }

    /**
     * @brief mean : get the mean of counters
     * @return an unsigned
     */
    double mean() const {
        long total = 0;
        if (counters.size()==0) return 0;
        for (auto d: counters) total+=d.second;
        return total/counters.size();
    }

    /**
     * @brief getCounters : return all counters
     * @return
     */
    const std::map<T, unsigned> getCounters() const
    {
        return counters;
    }
};


} // Eof namespace


#endif // ITEMCOUNTER_H
