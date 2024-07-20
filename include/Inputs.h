#define INPUT_H
#ifndef ENUMERATIONS_H
#include "Enumerations.h"
#endif
#include <vector>
#include <fstream>
#include <iostream>
using vec = std::vector<double>;
class SetInputs
{
public:
    vec absorbtion_xs;
    vec scatter_xs;
    vec fission_xs;
    vec region_boundaries;
    boundaries boundary_condition;
    unsigned random_seed;
    unsigned long particles;
    unsigned batches;
    SetInputs(std::string _file_name);
};

SetInputs::SetInputs(std::string _file_name)
:absorbtion_xs{},
scatter_xs{},
fission_xs{},
region_boundaries{},
boundary_condition{boundaries::white},
random_seed{1},
particles{1},
batches{0}
{
    std::ifstream _in;
    _in.open(_file_name);
    if (_in.fail())
    {
        std::cout<<"Error Reading Input File"<<_file_name;
        throw 1;
    }
    
    std::vector<vec> _it_vec{absorbtion_xs,scatter_xs,fission_xs};
    int _index{0};
    int _regions;
    _in>>_regions;
    double in_val;
    while (_index<_regions)
    {
        for (int i = 0; i < 3; i++)
        {

            _in >> in_val;
            _it_vec[i].push_back(in_val);
        }
        _index+=1;
    }
    for (int i = 0; i < _regions +1; i++)
    {
        _in>>in_val;
        region_boundaries.push_back(in_val);
    };
    _in>>random_seed;
    _in>>particles;
    _in>>batches;
}

