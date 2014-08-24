// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: depth_first_search.cpp
#include "comm/log.h"
#include "model/route.h"
#include "model/route_list.h"
#include "algorithm/depth_first_search.h"

using assignment::trains::comm::CLog;
using assignment::trains::domain::CRoute;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CRouteIterator;
using assignment::trains::domain::CDepthFirstSearch;

CDepthFirstSearch::CDepthFirstSearch(const ITownsMap& map):
    m_pTownMap(&map)
{
}

void CDepthFirstSearch::setMap(const ITownsMap& map)
{
    m_pTownMap = &map;
}

long CDepthFirstSearch::countPath(long src, long dest, long min, long max)
{
    return countAgreedPath(src, dest, min, max, 0);
}

long CDepthFirstSearch::countAgreedPath(
    long current, long dest, long minUnit, long maxUnit, long currentUnit)
{
    long count = 0;
    MY_LOG->log(
        "countAgreedPath. current: %lu, dest: %lu,"
        " min: %lu, max: %lu, currentUnit: %lu\n",
        current, dest, minUnit, maxUnit, currentUnit);
    if (current == dest && currentUnit >= minUnit && currentUnit <= maxUnit)
        count += 1;
    if (currentUnit > maxUnit)
        return 0;

    CRouteIterator
        iter = m_pTownMap->getAllAdjacentRoutesBySource(current).getIterator();
    while(iter.hasNext())
    {
        CRoute oRoute = iter.next();
        MY_LOG->log(
            "[%lu, %lu] => %lu\n",
            oRoute.getSource().id(), oRoute.getDestination().id(),
            oRoute.getLength());
        count += countAgreedPath(
            oRoute.getDestination().id(), dest,
            minUnit, maxUnit,
            currentUnit + oRoute.getLength());
    }
    return count;
}
