#include "../include/Particle.h"

Particle::Particle(Properties _props, double _x0)
:_location{_x0},
_abs{_props.get_absorb_xs()},
_sct{_props.get_scatter_xs()},
_total{_props.get_total_xs()},
_fission_ratio{_props.get_fission_ratio()},
_bounds{_props.get_region_bounds()},
_bc_type{_props.get_bc_type()},
_fis{_props.get_fission_xs()}
{
};

int Particle::where(double _x0)
{
    for ( int i = 0; i < _bounds.size()-1; i++)
    {
        if (_x0 < _bounds[i]) 
        {
            return i-1;
        }
    };

};

double Particle::integrateXS(int index)
{
    double _xs_here{_total[index]*(_bounds[index+1]-_location)};
    for (int i = index+1; i < _bounds.size()-1; i++)
    {
        _xs_here += (_bounds[i+1]-_bounds[i])*_total[i];
    }
    return _xs_here;
    
}
double Particle::sampleDistance(int index)
{
    double _r3{std::rand() / RAND_MAX};
    bool _direction{_r3 < 0.5};
    return -std::log(_r3) / integrateXS(index) * (1.0 - 2.0*_direction);
}

interaction Particle::move()
{
    double _r1{std::rand() / RAND_MAX};
    double _r2{std::rand() / RAND_MAX};
    int _index{where(_location)};

    double _distance{sampleDistance(_index)};

    int _index_now{where(_location+_distance)};
    if (_index_now <0 || _index_now > _bounds.size())
    {
        return interaction::death;
    }
    else
    {
        _location += _distance;
        if (_r1 < _sct[_index_now]/_total[_index_now]) return interaction::scatter;
        
        else
        {
            if (_r2 < _fis[_index_now]/_abs[_index_now]) return interaction::fission;
            else return interaction::absorbtion;
        }
    }
}
