package service;

import java.util.*;
import java.util.Map.Entry;

import comm.Define;
import algorithm.DepthFirstSearch;
import algorithm.Dijkstra;
import domain.*;

public class TrainsService {
    public TrainsService() {
        setTownsMap(new TownsMap());
        reset();
    }

    public TrainsService(TownsMap map) {
        setTownsMap(map);
        reset();
    }
    
    public void reset() {
    	if (dirty) {
	        getShortPathAlgorithm().setMap(getTownsMap());
	        getSearchAlgorithm().setMap(getTownsMap());
	        dirty = false;
    	}
    }
    
    // 遍历给定的路径。若存在，则输出路径总长度；若不存在，则输出字符串"NO SUCH ROUTE"
    public Object walkThroughPath(Path path) {
    	int sum = 0;
    	while(path.hasNextStep())
    	{
    		Step step = path.nextStep();
    		try {
    			sum += getTownsMap().getDistance(step.getSrc(), step.getDest());
    		}
    		catch (NullPointerException e)
    		{
    			return "NO SUCH ROUTE";
    		}
    	}
    	return sum;
    }

    // 按照给定的距离区间[minDistance, maxDistance]，查找从src到dest满足条件的路径数量；
    public int searchDistance(int src, int dest, int minDistance, int maxDistance) {
        return getSearchAlgorithm().searchDistance(src, dest, minDistance, maxDistance);
    }
    
    // 按照给定的转乘区间[min, max]，查找从src到dest满足条件的路径数量；
    public int searchStops(int src, int dest, int min, int max) {
        return getSearchAlgorithm().searchDepth(src, dest, min, max);
    }

    // 获取从src到dest的最短路径
    public int minimumDistance(int src, int dest) {
    	return getShortPathAlgorithm().calculate(src, dest);
    }
    
    public TownsMap getTownsMap() {
    	if (townsMap == null) {
    		townsMap = new TownsMap();
    	}
		return townsMap;
	}

	public void setTownsMap(TownsMap trainMap) {
		this.townsMap = trainMap;
		dirty = true;
	}
	
	private Dijkstra getShortPathAlgorithm() {
		if (shortPathAlgorithm == null) {
			shortPathAlgorithm = new Dijkstra();
		}
		return shortPathAlgorithm;
	}

	private void setShortPathAlgorithm(Dijkstra shortPathAlgorithm) {
		this.shortPathAlgorithm = shortPathAlgorithm;
		getShortPathAlgorithm().setMap(getTownsMap());
	}
	
	private DepthFirstSearch getSearchAlgorithm() {
		if (searchAlgorithm == null) {
			searchAlgorithm = new DepthFirstSearch(getTownsMap());
		}
		return searchAlgorithm;
	}

	private void setSearchAlgorithm(DepthFirstSearch searchAlgorithm) {
		this.searchAlgorithm = searchAlgorithm;
		getSearchAlgorithm().setMap(getTownsMap());
	}
	
	private TownsMap townsMap;
	private Dijkstra shortPathAlgorithm;
	private DepthFirstSearch searchAlgorithm;
	private boolean dirty;
}