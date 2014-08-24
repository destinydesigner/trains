package algorithm;

import java.util.*;
import java.util.Map.Entry;

import comm.Define;

import domain.TownsMap;

public class DepthFirstSearch {
    private TownsMap map;

    public DepthFirstSearch() {}

    public DepthFirstSearch(TownsMap map) {
        setMap(map);
    }

    public int searchDepth(int src, int dest, int min, int max) {
        return countStopAgreed(src, dest, min, max, 0);
    }

    public int searchDistance(int src, int dest, int min, int max) {
        return countDistanceAgreed(src, dest, min, max, 0);
    }

    private int countStopAgreed(
            int current, int dest, int minUnit, int maxUnit, int currentUnit) {
        int count = 0;
        if (current == dest && currentUnit >= minUnit && currentUnit <= maxUnit)
            count += 1;
        if (currentUnit > maxUnit)
            return 0;

        Map<Integer, Integer> adjacent = getMap().getAdjacentOf(current);
        for(Entry<Integer, Integer> entry : adjacent.entrySet()) {
            count += countStopAgreed(entry.getKey(), dest, minUnit, maxUnit, currentUnit + 1);
        }
        return count;
            }

    private int countDistanceAgreed(
            int current, int dest, int minDistance, int maxDistance, int currentDistance) {
        int count = 0;
        if (current == dest && currentDistance >= minDistance && currentDistance <= maxDistance)
            count += 1;
        if (currentDistance > maxDistance)
            return 0;

        Map<Integer, Integer> adjacent = getMap().getAdjacentOf(current);
        for(Entry<Integer, Integer> entry : adjacent.entrySet()) {
            count += countDistanceAgreed(
                    entry.getKey(), dest, minDistance, maxDistance, currentDistance + entry.getValue());
        }
        return count;
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
