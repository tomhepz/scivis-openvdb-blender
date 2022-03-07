import pyopenvdb as vdb
import math

exact = vdb.FloatGrid()
exact.name = 'exact'
exactAccessor = exact.getAccessor()

paraxial = vdb.FloatGrid()
paraxial.name = 'paraxial'
paraxialAccessor = paraxial.getAccessor()


for x in range(-400,400):
    for y in range(0,1):
        for z in range(-300,700):
            if (z == 0):
                continue
            rho2 = x**2 + y**2
            r2 = rho2 + z**2
            r = math.sqrt(r2)
            rho = math.sqrt(rho2)
            
            exactPhase = math.cos(r/15)
            paraxialPhase = math.cos((z+(rho2)/(2*z))/15)
            
            exactAccessor.setValueOn((x,y,z), exactPhase)
            paraxialAccessor.setValueOn((x,y,z), paraxialPhase)

vdb.write('optics.vdb', grids=[exact, paraxial])