// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: my_towns_map.cpp
#include <memory>
#include <sstream>
#include "comm/log.h"
#include "model/route.h"
#include "model/route_list.h"
#include "model/town_list.h"
#include "model/my_towns_map.h"

using assignment::trains::comm::CLog;
using assignment::trains::domain::CRoute;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CMyTownsMap;

CMyTownsMap::CMyTownsMap() :
    m_oAllTowns(new CTownList())
{
}

const CRoute& CMyTownsMap::getRoute(long src, long dest) const
{
    return getAllAdjacentRoutesBySource(src).getRouteByDestination(dest);
}

void CMyTownsMap::addRoute(
    const std::shared_ptr<CTown> src,
    const std::shared_ptr<CTown> dest,
    long distance)
{
    MY_LOG->log("add(%lu, %lu, %lu)\n", src->id(), dest->id(), distance);
    m_oAllTowns->addIfNotExist(src);
    m_oAllTowns->addIfNotExist(dest);
    m_oAllTowns->getById(src->id()).addAdjacentRoute(
        std::shared_ptr<CRoute>(
            new CRoute(src, dest, distance)));
}

void CMyTownsMap::addRoute(long src, long dest, long distance)
{
    MY_LOG->log("add(%lu, %lu, %lu)\n", src, dest, distance);
    m_oAllTowns->addIfNotExist(std::shared_ptr<CTown>(new CTown(src)));
    m_oAllTowns->addIfNotExist(std::shared_ptr<CTown>(new CTown(dest)));
    getAllAdjacentRoutesBySource(src).add(
        std::shared_ptr<CRoute>(
            new CRoute(src, dest, distance)));
}

CRouteList& CMyTownsMap::getAllAdjacentRoutesBySource(long src) const
{
    return m_oAllTowns->getById(src).getAllAdjacentRoutes();
}

const CTownList& CMyTownsMap::getAllTowns(void) const
{
    return *m_oAllTowns;
}

const std::string CMyTownsMap::ToString()
{
    std::stringstream ss;
    CTownIterator iter = m_oAllTowns->getIterator();
    while(iter.hasNext())
    {
        ss << iter.next().ToString();
    }
    return ss.str();
}
