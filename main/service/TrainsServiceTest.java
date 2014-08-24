package service;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import domain.Path;
import domain.TownsMap;
import comm.AddStepException;
import comm.Define;

public class TrainsServiceTest {
    private TrainsService service;
    @Before
    public void setUp() throws Exception {
        TownsMap map = new TownsMap();
		map.addRoute(1, 2, 5);
		map.addRoute(2, 3, 4);
		map.addRoute(3, 4, 8);
		map.addRoute(4, 3, 8);
		map.addRoute(4, 5, 6);
		map.addRoute(1, 4, 5);
		map.addRoute(3, 5, 2);
		map.addRoute(5, 2, 3);
		map.addRoute(1, 5, 7);
        service = new TrainsService(map);
    }

    @After
    public void tearDown() throws Exception {
    }

    @Test
    public void testWalkThroughPathABC() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 2);
    		path.addStep(2, 3);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	//1. The distance of the route A-B-C.
    	//Output #1: 9
    	assertEquals(service.walkThroughPath(path), 9);
    }
    
    @Test
    public void testWalkThroughPathAD() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 4);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	//2. The distance of the route A-D.
    	//Output #2: 5
    	assertEquals(service.walkThroughPath(path), 5);
    }
    
    @Test
    public void testWalkThroughPathADC() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 4);
    		path.addStep(4, 3);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	//3. The distance of the route A-D-C.
    	//Output #3: 13
    	assertEquals(service.walkThroughPath(path), 13);
    }
    
    @Test
    public void testWalkThroughPathAEBCD() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 5);
    		path.addStep(5, 2);
    		path.addStep(2, 3);
    		path.addStep(3, 4);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	//4. The distance of the route A-E-B-C-D.
    	//Output #4: 22
    	assertEquals(service.walkThroughPath(path), 22);
    }
    
    @Test
    public void testWalkThroughPathAED() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 5);
    		path.addStep(5, 4);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	//5. The distance of the route A-E-D.
    	//Output #5: NO SUCH ROUTE
    	assertEquals(service.walkThroughPath(path), "NO SUCH ROUTE");
    }
    
    @Test
    public void testWalkThroughPathNotExist() {
    	Path path = new Path();
    	try {
    		path.addStep(1, 3);
    	}
    	catch (AddStepException e)
    	{
    	}
    	path.start();
    	assertEquals(service.walkThroughPath(path), "NO SUCH ROUTE");
    }

    @Test
    public void testSearchStops() {
    	//6. The number of trips starting at C and ending at C with a maximum of 3 stops.
    	//Output #6: 2
    	assertEquals(2, service.searchStops(3, 3, 1, 3));
    	
    	//6. The number of trips starting at C and ending at C with a maximum of 3 stops.
    	// Include standing on the C;
    	assertEquals(3, service.searchStops(3, 3, 0, 3));
    	
    	//7. The number of trips starting at A and ending at C with exactly 4 stops.
    	//Output #7: 3
    	assertEquals(3, service.searchStops(1, 3, 4, 4));
    }
    
    @Test
    public void testMinimumDistance() {
    	//8. The length of the shortest route (in terms of distance to travel) from A to C.
    	//Output #8: 9
    	assertEquals(9, service.minimumDistance(1, 3));
    	
    	//9. The length of the shortest route (in terms of distance to travel) from B to B.
    	//Output #9: 9
    	assertEquals(9, service.minimumDistance(2, 2));
        //fail("Not yet implemented");
    }
    
    @Test
    public void testSearchDistance() {
        //fail("Not yet implemented");
    	assertEquals(7, service.searchDistance(3, 3, 1, 29));
    }
    
    @Test
    public void testSameTownMinimumDistance() {
    	assertTrue(Define.INFINITE_DISTANCE.equals(service.minimumDistance(1, 1)));
    	assertEquals(9, service.minimumDistance(2, 2)); // Cycle;
    	assertEquals(9, service.minimumDistance(3, 3));
    	assertEquals(16, service.minimumDistance(4, 4));
    	assertEquals(9, service.minimumDistance(5, 5));
        //fail("Not yet implemented");
    }
}
