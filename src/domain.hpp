#ifndef __DOMAIN_HPP
#define __DOMAIN_HPP

#include <vector>


namespace hydro {


/**
 * Abstract base class for simulation domains.
 */
template <class Cell>
class Domain
{

public:
    virtual std::vector<Cell> &get_cells() = 0;
    virtual Cell &add_cell(const Cell &cell) = 0;
    virtual ~Domain();
};


template <class Cell>
class CartesianDomain1D
{

public:
    CartesianDomain1D(std::vector<Cell> &&cells)
        : cells(cells)
    {
    }

    CartesianDomain1D() {}

    std::vector<Cell>& get_cells()
    {
        return cells;
    }

    void add_cell(Cell &&cell)
    {
        cells.push_back(cell);
    }

private:
    std::vector<Cell> cells;

};

}

#endif
