#include "../include/Particle.h"

void Particle::initialize(Properties _props, double _x0)
{
    _location = _x0;
    _abs = _props.get_absorb_xs();
    _sct = _props.get_scatter_xs();
    _total = _props.get_total_xs();
    _fission_ratio = _props.get_fission_ratio();
    _bounds = _props.get_region_bounds();
    _bc_type = _props.get_bc_type();
};

interaction Particle::move(boundaries _bc)
{
    double _r1{std::rand() / RAND_MAX};
    double _r2{std::rand() / RAND_MAX};
    bool _direction{_r1 < 0.5};
    unsigned int _index{};

    
    for ( int i = 0; i < _bounds.size()-1; i++)
    {
        if (_location < _bounds[i]) 
        {
            _index = i-1;
            break;
        }
    };

    double _distance{std::log(1-_r2)/_total[_index] * (1-2*_direction)};

    unsigned int _index_now{};

    for ( int i = 0; i < _bounds.size(); i++)
    {
        if (_location+_distance < _bounds[i]) 
        {
            _index = i;
            break;
        }
    };


    if (_index_now)


    switch (_bc)
    {
    case white:

        break;
    
    case vacuum:
        break;
    }
}
