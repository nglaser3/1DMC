#include "Properties.C"
#include "Particle.C"
#include "Batch.C"
#include <iostream>
#include <vector>

double rand_d()
{
    double val= std::rand();
    double rand_max = RAND_MAX;
    return val/rand_max;
}

int main()
{
    std::vector<double> k_eff_vector{};
    std::vector<double> flux_vector{};
    unsigned _batches{Inputs::batches};
    Properties props;
    std::vector<double> bounds{props.get_region_bounds()};

// Making the Random inputs
    std::srand(props.get_seed());
    std::vector<double> random_input{};
    std::vector<double> births{};
    for (long i = 0; i < 1000; i++)
    {
        random_input.push_back(rand_d());
        births.push_back
        (
        rand_d()*(bounds.back() - bounds.front()) + bounds.front()
        );
    }
    std::cout<<"Starting Simulation"<<std::endl;
// Running Simulation
    for (int i = 0; i < _batches; i++)
    {
        std::cout<<"Starting Batch: "<<i+1<<". ";
        Batch _batch(births,random_input);
        k_eff_vector.push_back(_batch.get_k_eff());
        flux_vector.push_back(_batch.get_scalar_flux());
        std::vector<double> new_sites{_batch.get_fission_sites()};
        if (new_sites.size()>0)
        {
            births = new_sites;
        }
        std::cout<<"K: " << k_eff_vector[i]<<", Flux: "<<flux_vector[i]<<std::endl;
    }
    std::cout<<"Done"<<std::endl;
//
    return 0;
}