#ifndef PROPERTIES_H
#include "../include/Properties.h"
#endif
#include <numeric>
Properties::Properties(SetInputs inputs): 
abs_xs{inputs.absorbtion_xs},
sct_xs{inputs.scatter_xs},
fis_xs{inputs.fission_xs},
region_bounds{inputs.region_boundaries},
bc_type{inputs.boundary_condition},
seed{inputs.random_seed}
{
    for (int i = 0; i != abs_xs.size(); i++)
    {
        total_xs.push_back(abs_xs[i]+sct_xs[i]);
    };

    double _fission_total{std::accumulate(fis_xs.begin(), fis_xs.end(), 0.0)};
    
    for (int i = 0; i != abs_xs.size(); i++)
    {
        fission_ratio.push_back(fis_xs[i]/_fission_total);
    };
};


vec Properties::get_absorb_xs()
{
    return abs_xs;
};

vec Properties::get_scatter_xs()
{
    return sct_xs;
};

vec Properties::get_fission_xs()
{
    return fis_xs;
};

vec Properties::get_total_xs()
{
    return total_xs;
};

vec Properties::get_fission_ratio()
{
    return fission_ratio;
};

vec Properties::get_region_bounds()
{
    return region_bounds;
};

boundaries Properties::get_bc_type()
{
    return bc_type;
};

unsigned Properties::get_seed()
{
    return seed;
};