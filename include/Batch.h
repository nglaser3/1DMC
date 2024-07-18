#include "Enumerations.h"
#include <vector>

class Batch
{
private:
    /**
     * Simulation settings
     */
    std::vector<double> fission_sites{};
    double particles{};

    /**
     * Simulation results:
     */
    std::vector<double> interaction_sites{};
    double k_eff{};
    double scalar_flux;
    std::vector<double> flux_vector;
    
public:
    /**
     * Initialize and run
     */
    void settings(double _p, std::vector<double> _site_locs);
    void run(Properties _props);

    /**
     * Getter functions
     */
    std::vector<double> get_interaction_sites();
    double get_k_eff();
    double get_scalar_flux();
    double get_flux_vector();
};