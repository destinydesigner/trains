// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: route_list.cpp
#include <map>
#include <sstream>
#include <string>
#include "model/route_list.h"
#include "model/route.h"

using assignment::trains::domain::CRoute;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CRouteIterator;

void CRouteList::add(const std::shared_ptr<CRoute> route)
{
    m_oRouteMap[route->getDestination().id()] = route;
}

const CRoute& CRouteList::getRouteByDestination(long dest) const
{
    if (m_oRouteMap.find(dest) == m_oRouteMap.end())
    {
        return CRoute::NullRoute();
    }
    return *(m_oRouteMap.find(dest)->second);
}

CRouteIterator CRouteList::getIterator(void) const
{
    CRouteIterator oRouteIterator(m_oRouteMap);
    return oRouteIterator;
}

const std::string CRouteList::ToString() const
{
    std::stringstream ss;
    for (std::map<long, std::shared_ptr<CRoute> >::const_iterator
         iter = m_oRouteMap.begin();
         iter != m_oRouteMap.end();
         iter++)
    {
        ss << iter->second->ToString();
    }
    return ss.str();
}

CRouteIterator::CRouteIterator(const std::map<long, std::shared_ptr<CRoute> >& map):
    m_rRouteMap(map)
{
    m_oIter = map.begin();
}

bool CRouteIterator::hasNext(void) const
{
    return m_oIter != m_rRouteMap.end();
}

const CRoute& CRouteIterator::next(void) const
{
    if (m_oIter == m_rRouteMap.end())
    {
        return CRoute::NullRoute();
    }

    const CRoute& oRoute(*(m_oIter->second));
    m_oIter++;
    return oRoute;
}

