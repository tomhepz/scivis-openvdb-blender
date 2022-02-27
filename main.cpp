#include <openvdb/openvdb.h>

template<class GridType>
void populateGrid(GridType& posgrid)
{
    using ValueT = typename GridType::ValueType;
    typename GridType::Accessor posaccessor = posgrid.getAccessor();


    const int dim = 12;
    const float a = 0.5;
    
    openvdb::Coord xyz;
    int& x = xyz[0], & y = xyz[1], & z = xyz[2];
    for (x = -dim; x <= dim; x++) {
        const float x2 = openvdb::math::Pow2(x);
        for (y = -dim; y <= dim; y++) {
            const float x2y2 = openvdb::math::Pow2(y) + x2;
            for (z = -dim; z <= dim; z++) {
                const float r2 = x2y2 + openvdb::math::Pow2(z);
                const float r = openvdb::math::Sqrt(r2);
                ValueT out = ValueT((x2y2 / r2) * openvdb::math::Exp((-2/3)*r) * ((6*r/a)-(r2/(a*a))));
                posaccessor.setValue(xyz, out);
            }
        }
    }
    xyz[0] = 0; xyz[1] = 0; xyz[2] = 0;
    posaccessor.setValue(xyz, 0);
}


int main()
{
    //const int steps = 20;
    //const float inc = 6.283/steps;
    //int i = 0;
    //for (i = 0; i < steps; i++) {
    openvdb::initialize();
    openvdb::FloatGrid::Ptr posgrid = openvdb::FloatGrid::create(0.0);
    populateGrid(*posgrid);
    posgrid->setGridClass(openvdb::GRID_FOG_VOLUME);
    posgrid->setName("density");
    char buff[16] = "qm.vdb";
    std::string buffAsStdStr = buff;
    openvdb::io::File file(buffAsStdStr);
    openvdb::GridPtrVec grids;
    grids.push_back(posgrid);
    file.write(grids);
    file.close();
    //}
}