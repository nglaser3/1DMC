#include "Enumerations.h"
#include "Properties.h"
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
    double integrateXS(int index);
    int where(double _x0);
    double sampleDistance(int index);
public:
    Particle(Properties _props, double _x0);
    
    interaction move();
};