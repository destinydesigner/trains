// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-24
// summary: null_town.cpp
#include <sstream>
#include "model/route.h"
#include "model/route_list.h"
#include "model/null_town.h"

using assignment::trains::domain::CRoute;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CNullTown;

CNullTown::CNullTown():
    m_adjacent(new CRouteList())
{
}

ITown& CNullTown::NullTown(void)
{
    static ITown * pNullTown = new CNullTown();
    return *pNullTown;
}

long CNullTown::id(void) const
{
    return 0;
}

const std::string CNullTown::name(void) const
{
    return "";
}

void CNullTown::addAdjacentRoute(const std::shared_ptr<CRoute> route)
{
    return;
}

CRouteList& CNullTown::getAllAdjacentRoutes() const
{
    return *m_adjacent;
}

const CRoute& CNullTown::getAdjacentRouteByDestination(long dest) const
{
    return CRoute::NullRoute();
}

const std::string CNullTown::ToString(void) const
{
    return "";
}
