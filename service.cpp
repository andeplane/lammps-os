#include <service>
#include <library.h>
// #include <mpi.h>
// #include <lammps.h>
// #include <testlib.h>
#include <iostream>
//using namespace LAMMPS_NS;

void Service::start(const std::string& )
{
    // LAMMPS *lmp = new LAMMPS(0, nullptr,MPI_COMM_WORLD);
    void *lammps;
    lammps_open_no_mpi(0, nullptr, &lammps);
    char *script = "log none\nunits    lj\n \
    atom_style    atomic\n \
    lattice        fcc 0.8442\n \
    region        box block 0 20 0 20 0 20\n \
    create_box    1 box\n \
    create_atoms    1 box\n \
    mass        1 1.0\n \
    velocity    all create 1.44 87287\n \
    pair_style    lj/cut 2.5\n \
    pair_coeff    1 1 1.0 1.0 2.5\n \
    neigh_modify every 1 delay 0 check yes\n \
    thermo_style custom step temp ke pe etotal cpuremain\n \
    thermo 10\n \
    fix        1 all nve\n \
    run        100";
    lammps_commands_string(lammps, script);
    // std::cout << foo() << std::endl;
}
