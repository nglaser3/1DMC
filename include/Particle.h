#define PARTICLE_H
#ifndef ENUMERATIONS_H
#ifndef PROPERTIES_H
#include "Enumerations.h"
#include "Properties.h"
#endif
#endif
class Particle
{
private:
    double _location{};
    interaction _interaction{};
    vec _abs{};
    vec _sct{};
    vec _total{};
    // ratio of fissions occuring in each region, used for source
    vec _fission_ratio{};
    vec _fis{};

    /**
     * Geometry definitions
     */
    vec _bounds{};
    boundaries _bc_type;
    double integrateXS(int index, bool direction);
    int where(double _x0);
    double sampleDistance(int index, double _rand_num);
public:
    Particle(Properties _props, double _x0);
    
    interaction move(double _r1,double _r2, double _r3);

    double get_loc();
};
