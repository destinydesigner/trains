package algorithm;

import java.util.AbstractQueue;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Map.Entry;

import comm.Define;
import domain.TownsMap;

public class Dijkstra {
	private TownsMap map;
	
	public Dijkstra() {
		map = new TownsMap();
	}
	
	public Dijkstra(TownsMap m) {
		setMap(m);
	}
	
	private class MinimumDistance {
		public MinimumDistance() {}
		public MinimumDistance(int dest, int distance) {
			this.dest = dest;
			this.distance = distance;
		}
		private Integer dest;
		private Integer distance;
		public Integer getDest() {
			return dest;
		}
		
		public Integer getDistance() {
			return distance;
		}
	}
	
	private class MinimumDistanceComparator implements Comparator<MinimumDistance> {
		@Override
		public int compare(MinimumDistance lhv, MinimumDistance rhv) {
			if (lhv.getDistance() < rhv.getDistance())
				return -1;
			else if (lhv.getDistance() > rhv.getDistance())
				return 1;
			else
				return 0;
		}
	}
	
	public int calculate(int src, int dest) {
		AbstractQueue<MinimumDistance> nodeQueue = new PriorityQueue<MinimumDistance>(
				new MinimumDistanceComparator());
		Map<Integer, Integer> distanceFromSrcTo = new HashMap<Integer, Integer>();
		Map<Integer, Boolean> visitFlag = new HashMap<Integer, Boolean>();
		for(Integer town : getMap().getAllTowns()) {
			distanceFromSrcTo.put(town, Define.INFINITE_DISTANCE);
			visitFlag.put(town, false);
		}
		nodeQueue.add(new MinimumDistance(src, 0));
		distanceFromSrcTo.put(src, 0);
		//System.out.println("Dijkstra: " + src + ", " + dest);
		
		Boolean resetSrcFlag = false;
		while(nodeQueue.size() > 0) {
			Integer currentNode = nodeQueue.poll().getDest();
			//System.out.println(currentNode);
			Map<Integer, Integer> adjacentNodeOfCurrentNode = getMap().getAdjacentOf(currentNode);
			for(Entry<Integer, Integer> entry : adjacentNodeOfCurrentNode.entrySet()) {
				Integer nextNode = entry.getKey();
				//System.out.println("next: " + nextNode);
				if(distanceFromSrcTo.get(currentNode) + entry.getValue() < distanceFromSrcTo.get(nextNode)) {
					distanceFromSrcTo.put(
							nextNode, distanceFromSrcTo.get(currentNode) + entry.getValue());
					nodeQueue.add(
							new MinimumDistance(nextNode, distanceFromSrcTo.get(nextNode)));
					/*System.out.println(
							"[" + currentNode + ", " + nextNode + "] => " + 
							distanceFromSrcTo.get(nextNode));*/
				}
			}
			if (currentNode == src && !resetSrcFlag) {
				distanceFromSrcTo.put(src, Define.INFINITE_DISTANCE);
				resetSrcFlag = true;
			}
		}
		return distanceFromSrcTo.get(dest);
	}
	private TownsMap getMap() {
		if (this.map == null) {
			this.map = new TownsMap();
		}
		return map;
	}
	public void setMap(TownsMap map) {
		this.map = map;
	}
}
