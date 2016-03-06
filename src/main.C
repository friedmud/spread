#include "Moose.h"

#include "libmesh/libmesh.h"
#include "libmesh/mesh.h"

// Create a performance log
PerfLog Moose::perf_log("Spread");

// Begin the main program.
int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    std::cout<<"Usage: ./spread-opt input.e output.nem"<<std::endl;
    return 1;
  }

  LibMeshInit init (argc, argv);

  Mesh mesh(init.comm());

  mesh.read(argv[1]);

  mesh.print_info();

  mesh.write(argv[2]);

  return 0;
}
