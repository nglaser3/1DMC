#define INPUT_H
#ifndef ENUMERATIONS_H
#include "Enumerations.h"
#endif
#include <vector>
using vec = std::vector<double>;
namespace Inputs
{
    const vec absorbtion_xs{0.12,0.1};
    const vec scatter_xs{0.05,0.05};
    const vec fission_xs{0.15,0.12};
    const vec region_boundaries{0,50,100};
    const boundaries boundary_condition{boundaries::white};
    const unsigned random_seed{10};
    const unsigned long particles{10000};
    const unsigned batches{20};
}