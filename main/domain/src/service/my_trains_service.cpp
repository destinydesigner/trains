// Copyright (c) fangguojian. All rights reserved
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: my_trains_service.cpp
//#include "model/intf_result.h"
//#include "model/null_result.h"
#include "comm/define.h"
#include "comm/log.h"
#include "comm/errno_define.h"
#include "model/path.h"
#include "model/route.h"
#include "algorithm/dijkstra.h"
#include "service/my_trains_service.h"

using namespace assignment::trains::comm;
using assignment::trains::domain::CMyTrainsService;

CMyTrainsService::CMyTrainsService(const ITownsMap& map):
    m_pMap(&map),
    m_pShortestPathAlgorithm(new CDijkstra(*m_pMap)),
    m_pSearchAlgorithm(new CDepthFirstSearch(*m_pMap))
{
}

void CMyTrainsService::setMap(const ITownsMap& map)
{
    m_pMap = &map;
    m_pShortestPathAlgorithm->setMap(map);
    m_pSearchAlgorithm->setMap(map);
}

long CMyTrainsService::minimumDistance(long src, long dest)
{
    return m_pShortestPathAlgorithm->getMinimum(src, dest);
}

long CMyTrainsService::getLength(const CPath& path)
{
    long totalLength = 0;
    long start = path.start().id();
    while(path.hasNext())
    {
        long next = path.next().id();
        long length = m_pMap->getRoute(start, next).getLength();
        MY_LOG->log("from %lu to %lu: length: %lu\n", start, next, length);
        if (length == INFINITE_DISTANCE)
        {
            return INFINITE_DISTANCE;
        }
        totalLength += length;
        start = next;
    }
    return totalLength;
}

long CMyTrainsService::countPath(long src, long dest, long min, long max)
{
    return m_pSearchAlgorithm->countPath(src, dest, min, max);
}

void CMyTrainsService::switchToStop()
{
    CRoute::setRouteType(CRoute::STOP);
}

void CMyTrainsService::switchToDistance()
{
    CRoute::setRouteType(CRoute::DISTANCE);
}

