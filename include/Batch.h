#define BATCH_H
#ifndef ENUMERATIONS_H
#ifndef PROPERTIES_H
#include "Properties.h"
#include "Enumerations.h"
#endif
#endif
#include <vector>

class Batch
{
private:
    
    unsigned long _particles;

    std::vector<double> birth_sites;

    std::vector<double> fission_sites;

    double k_eff;

    double scalar_flux;

    std::vector<double> rand_vec{};
public:
    Batch(std::vector<double> sites, std::vector<double> randoms);

    void run_batch(Properties _props);

    double get_k_eff();

    double get_scalar_flux();

    std::vector<double> get_fission_sites();
    
};