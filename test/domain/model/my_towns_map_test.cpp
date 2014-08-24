// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-20
// summary: my_towns_map_test.cpp
#include <stdio.h>
#include "gmock/gmock.h"
#include "model/route.h"
#include "model/route_list.h"
#include "model/town_list.h"
#include "model/my_towns_map.h"

using assignment::trains::domain::CTownList;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CMyTownsMap;

TEST(CMyTownsMap, addRoute)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);
}

TEST(CMyTownsMap, getAdjacentBySrc)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);
}

TEST(CMyTownsMap, getNullAdjacent)
{
    CMyTownsMap map;

    ASSERT_STREQ("", map.getAllAdjacentRoutesBySource(1).ToString().c_str());
    ASSERT_STREQ("", map.getAllAdjacentRoutesBySource(2).ToString().c_str());
}

TEST(CMyTownsMap, getAllTowns)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    map.getAllTowns();
}
