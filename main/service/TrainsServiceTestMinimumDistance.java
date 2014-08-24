package service;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import domain.TownsMap;

public class TrainsServiceTestMinimumDistance {
    private TrainsService service;
    
	@Before
	public void setUp() throws Exception {
        TownsMap map = new TownsMap();
		map.addRoute(1, 2, 100);
		map.addRoute(1, 3, 1);
		map.addRoute(3, 4, 1);
		map.addRoute(4, 5, 1);
		map.addRoute(5, 6, 1);
		map.addRoute(6, 7, 1);
		map.addRoute(7, 8, 1);
		map.addRoute(8, 9, 1);
		map.addRoute(9, 2, 1);
        service = new TrainsService(map);
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testMinimumDistance() {
		assertEquals(8, service.minimumDistance(1, 2));
		//fail("Not yet implemented");
	}

}
