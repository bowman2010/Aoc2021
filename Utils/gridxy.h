#ifndef GRIDXY_H
#define GRIDXY_H

#include <vector>
#include <tuple>

namespace bml {

/**
 * Defines a gridTuple (coordinates x and y and the value at that position)
 */
template<typename T>
using GridXYTuple = std::tuple<std::size_t,std::size_t,T>;

/**
 * @brief The GridXY class : represent a resizable XY grid
 */
template <class T>
class GridXY {
protected:
    std::vector<std::vector<T>> _grid;
    std::size_t _width;
    std::size_t _height;
public:
    GridXY() {}

    /**
     * @brief GridXY : construct an XY Grid with specified dimensions
     * @param width
     * @param height
     */
    GridXY(std::size_t width, std::size_t height)
    {
        resize(width,height);
    }

    /**
     * @brief resize : resize the grid with specified dimensions
     * @param width
     * @param height
     */
    void resize(std::size_t width, std::size_t height)
    {
        _grid.resize(height);
        for (auto &r: _grid) r.resize(width);
        _width = width; _height=height;
    }

    /**
     * @brief fill the grid with specified value
     * @param value
     */
    void fill(T value)
    {
        for (auto row: _grid) {
            for (auto d: row) {
                d = value;
            }
        }
    }

    /**
     * @brief data : direct access to data
     * @return
     */
    std::vector<std::vector<T>> data() { return _grid; }

    /**
     * @brief width : return the grid width
     * @return
     */
    std::size_t width()  const { return  _width; }

    /**
     * @brief height : return the grid height
     * @return
     */
    std::size_t height() const { return _height; }

    /**
     * @brief validPos : check if coordinates are inside the grid
     * @param x
     * @param y
     * @return
     */
    bool validPos(std::size_t x, std::size_t y) { return (x<_width && y<_height); }

    /**
     * @brief at : return a reference to the item at position x,y
     * @param x
     * @param y
     * @return
     */
    T& at(std::size_t x, std::size_t y) { return _grid[y][x]; }

    /**
     * @brief set : set the value of item at position x,y
     * @param x
     * @param y
     * @param val
     */
    void set(std::size_t x, std::size_t y, const T val) { _grid[y][x] = val; }

    /**
     * @brief columnValues : a vector of values in column x
     * @param x
     * @return
     */
    std::vector<T> columnValues(std::size_t x)
    {
        std::vector<T> col;
        for (size_t i=0; i<_height; i++) col.push_back(_grid[i][x]);
        return col;
    }

    /**
     * @brief column : a vector of GridXYTuples for column x
     * @param x
     * @return
     */
    std::vector<GridXYTuple<T>> column(std::size_t x)
    {
        std::vector<std::tuple<size_t,size_t,T>> col;
        for (size_t i=0; i<_height; i++)
            col.push_back(std::make_tuple(x,i,_grid[i][x]));
        return col;
    }

    /**
     * @brief rowValues : return a vector of values in row y
     * @param y
     * @return
     */
    std::vector<T> rowValues(std::size_t y)
    {
        std::vector<T> row;
        for (size_t i=0; i<_width; i++) row.push_back(_grid[y][i]);
        return row;
    }

    /**
     * @brief row: a vector of GridXYTuples for row y
     * @param x
     * @return
     */
    std::vector<GridXYTuple<T>> row(std::size_t y)
    {
        std::vector<GridXYTuple<T>> col;
        for (size_t i=0; i<height(); i++)
            col.push_back(std::make_tuple(i,y,_grid[y][i]));
        return col;
    }

    /**
     * @brief adjacents4 : a vector GridXYTuples of cardinal adjacents
     * @param x
     * @param y
     * @return
     */
    std::vector<GridXYTuple<T>> adjacents4(std::size_t x, std::size_t y)
    {
        std::vector<GridXYTuple<T>> adj;
        if (y>0)            adj.push_back(std::make_tuple(x,y-1,_grid[y-1][x]));
        if (y<_height-1)    adj.push_back(std::make_tuple(x,y+1,_grid[y+1][x]));
        if (x>0)            adj.push_back(std::make_tuple(x-1,y,_grid[y][x-1]));
        if (x<_width-1)     adj.push_back(std::make_tuple(x+1,y,_grid[y][x+1]));
        return adj;
    }

    /**
     * @brief adjacents8 : a vector GridXYTuples of all adjacents
     * @param x
     * @param y
     * @return
     */
    std::vector<GridXYTuple<T>> adjacents8(std::size_t x, std::size_t y)
    {
        std::vector<GridXYTuple<T>> adj = adjacents4(x,y);
        if (y>0) {
            if (x>0)        adj.push_back(std::make_tuple(x-1,y-1,_grid[y-1][x-1]));
            if (x<_width-1) adj.push_back(std::make_tuple(x+1,y-1,_grid[y-1][x+1]));
        }
        if (y<_height-1) {
            if (x>0)        adj.push_back(std::make_tuple(x-1,y+1,_grid[y+1][x-1]));
            if (x<_width-1) adj.push_back(std::make_tuple(x+1,y+1,_grid[y+1][x+1]));
        }
        return adj;
    }
};

} // eof namespace
#endif // GRIDXY_H
