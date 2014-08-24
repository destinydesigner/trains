// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-22
// summary: my_trains_service_test.cpp
#include <stdio.h>
#include "gmock/gmock.h"
#include "comm/log.h"
#include "model/route.h"
#include "model/route_list.h"
#include "model/town_list.h"
#include "model/my_towns_map.h"
#include "service/my_trains_service.h"

using assignment::trains::comm::CLog;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CMyTownsMap;
using assignment::trains::domain::CMyTrainsService;

/*
TEST(CMyTrainsService, test)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(6, oService.minimumDistance(1, 7));
}

TEST(CMyTrainsService, setMap)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(6, oService.minimumDistance(1, 7));

    CMyTownsMap map1;
    map1.addRoute(1, 2, 5);
    map1.addRoute(2, 3, 4);
    map1.addRoute(3, 4, 8);
    map1.addRoute(4, 3, 8);
    map1.addRoute(4, 5, 6);
    map1.addRoute(1, 4, 5);
    map1.addRoute(3, 5, 2);
    map1.addRoute(5, 2, 3);
    map1.addRoute(1, 5, 7);

    oService.setMap(map1);
    oService.switchToDistance();
    ASSERT_EQ(9, oService.minimumDistance(1, 3));
}
*/
TEST(CMyTrainsService, noPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(6, oService.minimumDistance(1, 7));
    MY_LOG->log("noPath test====================begin");
    ASSERT_EQ(-1, oService.minimumDistance(1, 8));
    MY_LOG->log("noPath test====================end");
}
/*
TEST(CMyTrainsService, countPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(6, oService.minimumDistance(1, 7));
}

*/
