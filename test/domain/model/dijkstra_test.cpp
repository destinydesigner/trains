// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: dijkstra_test.cpp
#include "algorithm/dijkstra.h"
#include "model/my_towns_map.h"
#include "gmock/gmock.h"

using assignment::trains::domain::CMyTownsMap;
using assignment::trains::domain::CDijkstra;

TEST(CDijkstra, OneLine)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CDijkstra oDijkstra(map);
    ASSERT_EQ(6, oDijkstra.getMinimum(1, 7));
}

TEST(CDijkstra, Cycle)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 1, 1);

    CDijkstra oDijkstra(map);
    ASSERT_EQ(2, oDijkstra.getMinimum(1, 1));
}
