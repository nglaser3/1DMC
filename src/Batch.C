#ifndef PARTICLE_H
#include "../include/Particle.h"
#endif
#include "../include/Batch.h"
#include <vector>

Batch::Batch(std::vector<double> sites, std::vector<double> randoms, SetInputs inputs)
:_particles{inputs.particles},
birth_sites{sites},
rand_vec{randoms},
k_eff{0.0},
scalar_flux{0.0}
{
};

void Batch::run_batch(Properties _props)
{
    for (unsigned long i = 0; i < _particles; i++)
    {
        Particle p(_props,birth_sites[i%birth_sites.size()]);
        interaction inter_type{interaction::scatter};
        while (inter_type == interaction::scatter)
        {
            interaction _type = p.move(
                rand_vec[i%rand_vec.size()],
                rand_vec[(i+1)%rand_vec.size()],
                rand_vec[(i+2)%rand_vec.size()]);
            switch (_type)
            {
            case interaction::fission:
                fission_sites.push_back(p.get_loc());
                k_eff += 2.4;
                break;
            default:
                break;
            }
            inter_type = _type;
        }
        
    }
    k_eff /= _particles;
};

double Batch::get_k_eff()
{
    return k_eff;
};

double Batch::get_scalar_flux()
{
    return scalar_flux;
};

std::vector<double> Batch::get_fission_sites()
{
    return fission_sites;
};