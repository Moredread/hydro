#ifndef __SCHEME_HPP
#define __SCHEME_HPP

#include <iterator>


namespace hydro {

/**
 * Abstract base class for an iteration scheme.
 */
template <class Algorithm, class Domain, class Time>
class Scheme
{

public:
    virtual void advance(Domain &domain, const Time delta) = 0;

};


/**
 * A generic template function that calculates the state transitions for two
 * cells and a given transition scheme.
 */
template <class Algorithm, class Domain, class Cell, class Transition, class Time>
class PseudoScheme
{

public:
    explicit PseudoScheme(Algorithm algorithm) {
        this->algorithm = algorithm;
    }

    /**
     * Advance a domain using this iteration scheme by a time interval.
     */
    void advance(Domain &domain, const Time delta)
    {
        // Setup vectors
        std::vector<Cell> &cells = domain.get_cells();
        if (cells.empty())
            return;
        std::vector<Transition> trans(cells.size());
        // Compute transitions
        for (auto cell_it = cells.begin(), trans_it = trans.begin();
            std::next(cell_it) != cells.end() && std::next(trans_it) != trans.end();
            ++cell_it, ++trans_it)
        {
            algorithm.compute_transitions(*cell_it, *std::next(cell_it), *trans_it, *std::next(trans_it));
        }
        // Apply transitions
        for (auto cell_it = cells.begin(), trans_it = trans.begin();
            cell_it != cells.end() && trans_it != trans.end();
            ++cell_it, ++trans_it)
        {
            trans_it->apply(*cell_it);
        }
    }

private:
    Algorithm algorithm;

};

}

#endif
