#ifndef PARTICLE_H
#include "../include/Particle.h"
#endif
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
        else return _bounds.size();
    };
    return _bounds.size();
};

double Particle::integrateXS(int index, bool direction)
{
    
    if (direction)
    {
        double _xs_here{_total[index]*(_location-_bounds[index])};
        for (int i = index; i > 0; i--)
        {
            _xs_here += (_bounds[index]-_bounds[index-1])*_total[index-1];
        }
        return _xs_here;///(_bounds.back() - _bounds.front());
        
    }
    else
    {
        double _xs_here{_total[index]*(_bounds[index+1]-_location)};
        for (int i = index+1; i < _bounds.size()-1; i++)
        {
            _xs_here += (_bounds[i+1]-_bounds[i])*_total[i];
        }
        return _xs_here;///(_bounds.back() - _bounds.front());
    }
}
double Particle::sampleDistance(int index, double _rand_num)
{
    bool _direction{_rand_num < 0.5};
    return -std::log(.01 / integrateXS(index,_direction)) * (1.0 - 2.0*_direction);
}

interaction Particle::move(double _r1,double _r2, double _r3)
{
    int _index{where(_location)};

    double _distance{sampleDistance(_index,_r1)};

    int _index_now{where(_location+_distance)};
    if (_index_now <0 || _index_now > _bounds.size()-1)
    {
        return interaction::death;
    }
    else
    {
        _location += _distance;
        if (_r2 < _sct[_index_now]/_total[_index_now]) return interaction::scatter;
        
        else
        {
            if (_r3 < _fis[_index_now]/_abs[_index_now]) return interaction::fission;
            else return interaction::absorbtion;
        }
    }
}

double Particle::get_loc()
{
    return _location;
}
