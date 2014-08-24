// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-23
// summary: null_test.cpp
#include "comm/define.h"
#include "comm/errno_define.h"
#include "model/path.h"
#include "model/route.h"
#include "model/town.h"
#include "model/route_list.h"
#include "model/town_list.h"
#include "model/my_towns_map.h"
#include "gmock/gmock.h"

using namespace assignment::trains::comm;
using assignment::trains::domain::CPath;
using assignment::trains::domain::CRoute;
using assignment::trains::domain::CTown;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CMyTownsMap;

void nullRoute(const CRoute& route)
{
    CRoute::setRouteType(CRoute::STOP);
    ASSERT_EQ(INFINITE_DISTANCE, route.getLength());
    ASSERT_EQ(ERR_NO_SUCH_TOWN, route.getSource().id());
    ASSERT_EQ(ERR_NO_SUCH_TOWN, route.getDestination().id());
}

void nullTown(const ITown& town)
{
    ASSERT_EQ(ERR_NO_SUCH_TOWN, town.id());
    ASSERT_FALSE(town.getAllAdjacentRoutes().getIterator().hasNext());

    CTown anotherTown;
    nullRoute(town.getAdjacentRouteByDestination(anotherTown.id()));
}

void nullRouteList(const CRouteList& list)
{
    nullRoute(list.getRouteByDestination(0));
    ASSERT_FALSE(list.getIterator().hasNext());
    nullRoute(list.getIterator().next());
}

void nullTownList(const CTownList& list)
{
    ASSERT_FALSE(list.getIterator().hasNext());
    nullTown(list.getIterator().next());
}

TEST(CPath, NullPath)
{
    CPath oPath;
    ASSERT_EQ(ERR_NO_SUCH_TOWN, oPath.start().id());
    ASSERT_FALSE(oPath.hasNext());
    ASSERT_EQ(ERR_NO_SUCH_TOWN, oPath.next().id());
}

TEST(CRoute, NullRoute)
{
    CRoute oRoute;
    nullRoute(oRoute);
}

TEST(CTown, NullTown)
{
    CTown oTown;
    nullTown(oTown);
}

TEST(CRouteList, NullRouteList)
{
    CRouteList oList;
    nullRouteList(oList);
}

TEST(CRouteList, NullTownList)
{
    CTownList oList;
    nullTownList(oList);
}

TEST(CMyTownsMap, NullMyTownsMap)
{
    CMyTownsMap oMap;

    nullRoute(oMap.getRoute(1, 203));
    nullRouteList(oMap.getAllAdjacentRoutesBySource(1));
    nullTownList(oMap.getAllTowns());
}

