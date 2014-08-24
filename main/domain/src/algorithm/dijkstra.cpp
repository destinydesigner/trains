// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: dijkstra.cpp
#include <algorithm>
#include <vector>
#include <map>
#include "comm/define.h"
#include "comm/log.h"
#include "model/town.h"
#include "model/town_list.h"
#include "model/route.h"
#include "model/route_list.h"
#include "algorithm/dijkstra.h"

using assignment::trains::comm::CLog;
using assignment::trains::comm::INFINITE_DISTANCE;
using assignment::trains::domain::CTown;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CTownIterator;
using assignment::trains::domain::CDistanceFromSrc;
using assignment::trains::domain::CDijkstra;

CDistanceFromSrc::CDistanceFromSrc(long dest, long distance):
    m_dest(dest),
    m_distance(distance)
{
}

long CDistanceFromSrc::getDistance() const
{
    return m_distance;
}

long CDistanceFromSrc::getDest() const
{
    return m_dest;
}

bool CDistanceFromSrc::operator<(const CDistanceFromSrc& node) const
{
    return m_distance > node.getDistance();
}

CDijkstra::CDijkstra(const ITownsMap& map):
    m_pTownMap(&map)
{
}

void CDijkstra::setMap(const ITownsMap& map)
{
    m_pTownMap = &map;
}

long CDijkstra::getMinimum(long src, long dest)
{
    MY_LOG->log("%s. src: %ld, dest: %ld\n", __FUNCTION__, src, dest);
    std::vector<CDistanceFromSrc> nodeQueue;
    std::map<long, long> distanceFromSrcTo;
    std::map<long, bool> visitFlag;

    CTownIterator townIter = m_pTownMap->getAllTowns().getIterator();
    MY_LOG->log("begin town:\n");
    while(townIter.hasNext())
    {
        const ITown& town = townIter.next();
        distanceFromSrcTo[town.id()] = INFINITE_DISTANCE;
        visitFlag[town.id()] = false;
        MY_LOG->log("%ld\n", town.id());
    }
    MY_LOG->log("end town:\n");

    CDistanceFromSrc oDistanceFromSrc(src, 0);
    nodeQueue.push_back(oDistanceFromSrc);
    std::make_heap(nodeQueue.begin(), nodeQueue.end());
    distanceFromSrcTo[src] = 0;

    bool resetSrcFlag = false;
    while(nodeQueue.size() > 0)
    {
        long currentNode = nodeQueue[0].getDest();
        MY_LOG->log("current: %lu\n", currentNode);
        std::pop_heap(nodeQueue.begin(), nodeQueue.end());
        nodeQueue.pop_back();

        MY_LOG->log(
            "current adjacent: %s\n",
            m_pTownMap->getAllAdjacentRoutesBySource(currentNode)
            .ToString().c_str());
        CRouteIterator
            oRouteIter = m_pTownMap->getAllAdjacentRoutesBySource(currentNode)
            .getIterator();
        while(oRouteIter.hasNext())
        {
            CRoute oRoute = oRouteIter.next();
            long nextNode = oRoute.getDestination().id();
            MY_LOG->log("next: %lu\n", nextNode);
            if(distanceFromSrcTo[currentNode] + oRoute.getLength()
               < distanceFromSrcTo[nextNode])
            {
                distanceFromSrcTo[nextNode]
                    = distanceFromSrcTo[currentNode] + oRoute.getLength();
                nodeQueue.push_back(
                    CDistanceFromSrc(nextNode, distanceFromSrcTo[nextNode]));
                std::push_heap(nodeQueue.begin(), nodeQueue.end());
                MY_LOG->log(
                    "after  [%lu, %lu] => %lu\n",
                    currentNode, nextNode, distanceFromSrcTo[nextNode]);
            }
        }

        if (currentNode == src && !resetSrcFlag)
        {
            distanceFromSrcTo[src] = INFINITE_DISTANCE;
            resetSrcFlag = true;
        }
    }

    if (distanceFromSrcTo.find(dest) != distanceFromSrcTo.end()
        && distanceFromSrcTo[dest] != INFINITE_DISTANCE)
    {
        return distanceFromSrcTo[dest];
    }

    return INFINITE_DISTANCE;
}

