#include <openvdb/openvdb.h>

template<class GridType>
void populateGrid(GridType& posgrid,float t)
{
    using ValueT = typename GridType::ValueType;
    typename GridType::Accessor posaccessor = posgrid.getAccessor();

    const int dim = 100;
    const float a = 1.8;
    
    openvdb::Coord xyz;
    int& x = xyz[0];
    int& y = xyz[1];
    int& z = xyz[2];

    for (x = -dim; x <= dim; x++) {
        const float x2 = x*x;
        for (y = -dim; y <= dim; y++) {
            const float x2y2 = y*y + x2;
            for (z = -dim; z <= dim; z++) {
                if ((x == 0) && (y==0) && (z==0)) {
                    continue;
                }
                const float r2 = x2y2 + z*z;
                const float r = std::sqrt(r2);
                const float costheta = float(z)/r;

                const float A = 5*(192*a*a*a-144*a*a*r+24*a*r*r-r*r*r);
                const float B = 6.71*r*(80*a*a-20*a*r+r*r)*costheta;
                const float prob = std::exp(-r/(2*a)) * (A*A + B*B + A*B*2*std::cos(t));

                ValueT out = ValueT(prob);
                posaccessor.setValue(xyz, out);
            }
        }
    }
}


int main()
{
    const int steps = 20;
    const float inc = 6.283/steps;
    int i = 0;
    float t = 0;
    for (i = 0; i < steps; i++) {
    openvdb::initialize();
    openvdb::FloatGrid::Ptr posgrid = openvdb::FloatGrid::create(0.0);
    populateGrid(*posgrid, t);
    posgrid->setGridClass(openvdb::GRID_FOG_VOLUME);
    posgrid->setName("density");
    std::string filename = "qm" + std::to_string(i) + ".vdb";
    openvdb::io::File file(filename);
    openvdb::GridPtrVec grids;
    grids.push_back(posgrid);
    file.write(grids);
    file.close();
    t+=inc;
    }
}