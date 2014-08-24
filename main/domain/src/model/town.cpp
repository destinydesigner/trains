// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: town.cpp
#include <sstream>
#include "model/town.h"
#include "model/route.h"
#include "model/route_list.h"

using assignment::trains::domain::CRoute;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CTown;

CTown::CTown():
    m_id(0),
    m_name(""),
    m_adjacent(new CRouteList())
{
}

CTown::CTown(long id) :
    m_id(id),
    m_name(""),
    m_adjacent(new CRouteList())
{
}

CTown::CTown(long id, const std::string name) :
    m_id(id),
    m_name(name),
    m_adjacent(new CRouteList())
{
}

CTown::CTown(const CTown& town)
{
    m_id = town.id();
    m_name = town.name();
    m_adjacent = std::shared_ptr<CRouteList>(
        new CRouteList(town.getAllAdjacentRoutes()));
}

const CTown& CTown::NullTown(void)
{
    static CTown* pNullTown = new CTown();
    return *pNullTown;
}

long CTown::id(void) const
{
    return m_id;
}

const std::string CTown::name(void) const
{
    return m_name;
}

void CTown::addAdjacentRoute(const std::shared_ptr<CRoute> route)
{
    m_adjacent->add(route);
}

CRouteList& CTown::getAllAdjacentRoutes() const
{
    return *m_adjacent;
}

const CRoute& CTown::getAdjacentRouteByDestination(long dest) const
{
    CRouteIterator iter = m_adjacent->getIterator();
    while (iter.hasNext())
    {
        const CRoute& oRoute(iter.next());
        if (oRoute.getDestination().id() == dest)
            return oRoute;
    }
    return CRoute::NullRoute();
}

const std::string CTown::ToString(void) const
{
    std::stringstream ss;
    ss << "(" << m_id << ", " << m_name << ")";
    return ss.str();
}
