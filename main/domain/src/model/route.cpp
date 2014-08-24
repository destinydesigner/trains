// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: route.cpp
#include <memory>
#include <sstream>
#include <string>
#include "comm/define.h"
#include "model/route.h"
#include "model/town.h"

using assignment::trains::comm::INFINITE_DISTANCE;
using assignment::trains::domain::CTown;
using assignment::trains::domain::CRoute;

CRoute::ERouteType CRoute::m_routeType = DISTANCE;

CRoute::CRoute():
    m_distance(INFINITE_DISTANCE),
    m_pSource(new CTown(0)),
    m_pDestination(new CTown(0))
{
}

CRoute::CRoute(long src, long dest, long dist)
{
    m_pSource = std::shared_ptr<CTown>(new CTown(src));
    m_pDestination = std::shared_ptr<CTown>(new CTown(dest));
    this->m_distance = dist;
}

CRoute::CRoute(
    const std::shared_ptr<CTown> src,
    const std::shared_ptr<CTown> dest,
    long distance)
{
    m_pSource = src;
    m_pDestination = dest;
    m_distance = distance;
}

const CRoute& CRoute::NullRoute()
{
    /* allocate the object on heap.
     * avoid exit-time destructor
     */
    static CRoute *NullRoute = new CRoute(0, 0, INFINITE_DISTANCE);
    return *NullRoute;
}

void CRoute::setRouteType(enum ERouteType e)
{
    m_routeType = e;
}

long CRoute::getLength(void) const
{
    if (m_distance == INFINITE_DISTANCE)
    {
        return INFINITE_DISTANCE;
    }

    if (m_routeType == CRoute::STOP)
    {
        return 1;
    }

    return m_distance;
}

const CTown& CRoute::getSource(void) const
{
    return (*m_pSource);
}

const CTown& CRoute::getDestination(void) const
{
    return (*m_pDestination);
}

const std::string CRoute::ToString(void) const
{
    std::stringstream ss;
    ss << "(" << m_pSource->id()
        << ", " << m_pDestination->id()
        << ", " << this->m_distance
        << ") ";
    return ss.str();
}
