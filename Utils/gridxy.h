#ifndef GRIDXY_H
#define GRIDXY_H

#include <vector>
#include <tuple>

namespace bml {

template<typename T>
using GridXYTuple = std::tuple<std::size_t,std::size_t,T>;

template <class T>
class GridXY {
protected:
    std::vector<std::vector<T>> _grid;
    std::size_t _width;
    std::size_t _height;
public:
    GridXY() {}

    GridXY(std::size_t width, std::size_t height)
    {
        resize(width,height);
    }

    void resize(std::size_t width, std::size_t height)
    {
        _grid.resize(height);
        for (auto &r: _grid) r.resize(width);
        _width = width; _height=height;
    }

    std::vector<std::vector<T>> data() { return _grid; }

    std::size_t width()  const { return  _width; }

    std::size_t height() const { return _height; }

    bool validPos(std::size_t x, std::size_t y) { return (x<_width && y<_height); }

    T& at(std::size_t x, std::size_t y) { return _grid[y][x]; }

    void set(std::size_t x, std::size_t y, const T val) { _grid[y][x] = val; }

    std::vector<T> columnValues(std::size_t x)
    {
        std::vector<T> col;
        for (size_t i=0; i<_height; i++) col.push_back(_grid[i][x]);
        return col;
    }

    std::vector<GridXYTuple<T>> column(std::size_t x)
    {
        std::vector<std::tuple<size_t,size_t,T>> col;
        for (size_t i=0; i<_height; i++)
            col.push_back(std::make_tuple(x,i,_grid[i][x]));
        return col;
    }

    std::vector<T> rowValues(std::size_t y)
    {
        std::vector<T> row;
        for (size_t i=0; i<_width; i++) row.push_back(_grid[y][i]);
        return row;
    }

    std::vector<GridXYTuple<T>> row(std::size_t y)
    {
        std::vector<GridXYTuple<T>> col;
        for (size_t i=0; i<height(); i++)
            col.push_back(std::make_tuple(i,y,_grid[y][i]));
        return col;
    }

    std::vector<GridXYTuple<T>> adjacents4(std::size_t x, std::size_t y)
    {
        std::vector<GridXYTuple<T>> adj;
        if (y>0)            adj.push_back(std::make_tuple(x,y-1,_grid[y-1][x]));
        if (y<_height-1)    adj.push_back(std::make_tuple(x,y+1,_grid[y+1][x]));
        if (x>0)            adj.push_back(std::make_tuple(x-1,y,_grid[y][x-1]));
        if (x<_width-1)     adj.push_back(std::make_tuple(x+1,y,_grid[y][x+1]));
        return adj;
    }

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
