#include <vector>
#include "Enumerations.h"
#include "Inputs.h"
#include <string>

using vec = std::vector<double>;
class Properties
{
private:
    /**
     * Material Properties
     */
    vec abs_xs{};
    vec sct_xs{};
    vec fis_xs{};
    vec total_xs{};
    // ratio of fissions occuring in each region, used for source
    vec fission_ratio{};

    /**
     * Geometry definitions
     */
    vec region_bounds{};
    boundaries bc_type;
public:
    /**
     * Initialize properties
     */
    Properties();

    /**
    * Getter Functions
    */
    vec get_absorb_xs();
    vec get_scatter_xs();
    vec get_fission_xs();
    vec get_total_xs();
    vec get_fission_ratio();
    vec get_region_bounds();
    boundaries get_bc_type();

};

