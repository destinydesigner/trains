// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: depth_first_search_test.cpp
#include "algorithm/depth_first_search.h"
#include "model/my_towns_map.h"
#include "model/route.h"
#include "gmock/gmock.h"

using assignment::trains::domain::CRoute;
using assignment::trains::domain::CMyTownsMap;
using assignment::trains::domain::CDepthFirstSearch;

TEST(CDepthFirstSearch, test)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CDepthFirstSearch oDFS(map);

    CRoute::setRouteType(CRoute::STOP);
    ASSERT_EQ(1, oDFS.countPath(1, 7, 0, 9));
}

TEST(CDepthFirstSearch, noPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CDepthFirstSearch oDFS(map);

    CRoute::setRouteType(CRoute::STOP);
    ASSERT_EQ(0, oDFS.countPath(1, 7, 0, 5));
}

TEST(CDepthFirstSearch, actuallyHaveAPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CDepthFirstSearch oDFS(map);

    CRoute::setRouteType(CRoute::STOP);
    ASSERT_EQ(1, oDFS.countPath(1, 7, 0, 6));
}

TEST(CDepthFirstSearch, countPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 5);
    map.addRoute(2, 3, 4);
    map.addRoute(3, 4, 8);
    map.addRoute(4, 3, 8);
    map.addRoute(4, 5, 6);
    map.addRoute(1, 4, 5);
    map.addRoute(3, 5, 2);
    map.addRoute(5, 2, 3);
    map.addRoute(1, 5, 7);

    CDepthFirstSearch oDFS(map);

    CRoute::setRouteType(CRoute::DISTANCE);
    ASSERT_EQ(7, oDFS.countPath(3, 3, 1, 29));
}

TEST(CDepthFirstSearch, loop)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 5);
    map.addRoute(2, 1, 7);

    CDepthFirstSearch oDFS(map);

    CRoute::setRouteType(CRoute::DISTANCE);
    ASSERT_EQ(4, oDFS.countPath(1, 1, 1, 48));
    CRoute::setRouteType(CRoute::STOP);
    ASSERT_EQ(24, oDFS.countPath(1, 1, 1, 48));
}
