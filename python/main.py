import pyopenvdb as vdb

grid = vdb.FloatGrid()
grid.name = 'density'
accessor = grid.getAccessor()

for i in range(-5,6):
    for j in range(-5,6):
        for k in range(-5,6):
            accessor.setValueOn((i,j,k), 0.125)

vdb.write('mygrid.vdb', grids=[grid])