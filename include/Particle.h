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

    /**
     * Geometry definitions
     */
    vec _bounds{};
    boundaries _bc_type;
public:
    double weight{1.0};
    void initialize(Properties _props, double _x0);
    interaction move(boundaries _bc);
};