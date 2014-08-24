// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-22
// summary: my_trains_service_test.cpp
#include <stdio.h>
#include "gmock/gmock.h"
#include "comm/log.h"
#include "comm/define.h"
#include "comm/errno_define.h"
#include "model/route.h"
#include "model/route_list.h"
#include "model/town_list.h"
#include "model/path.h"
#include "model/my_towns_map.h"
#include "service/my_trains_service.h"

using namespace assignment::trains::comm;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CRouteList;
using assignment::trains::domain::CPath;
using assignment::trains::domain::CMyTownsMap;
using assignment::trains::domain::CMyTrainsService;


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

TEST(CMyTrainsService, countPath)
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

    CMyTrainsService oService(map);
    oService.switchToStop();
    ASSERT_EQ(2, oService.countPath(3, 3, 1, 3));
}

TEST(CMyTrainsService, noTown)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(3, 4, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(INFINITE_DISTANCE, oService.minimumDistance(1, 8));
}

TEST(CMyTrainsService, noPath)
{
    CMyTownsMap map;
    map.addRoute(1, 2, 1);
    map.addRoute(2, 3, 1);
    map.addRoute(4, 5, 1);
    map.addRoute(5, 6, 1);
    map.addRoute(6, 7, 1);

    CMyTrainsService oService(map);
    ASSERT_EQ(INFINITE_DISTANCE, oService.minimumDistance(1, 7));
}

TEST(CMyTrainsService, walkThroughPathABC)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(2);
    oPath.add(3);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(9, oService.getLength(oPath));
}

TEST(CMyTrainsService, walkThroughPathAD)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(4);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(5, oService.getLength(oPath));
}

TEST(CMyTrainsService, walkThroughPathADC)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(4);
    oPath.add(3);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(13, oService.getLength(oPath));
}

TEST(CMyTrainsService, walkThroughPathAEBCD)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(5);
    oPath.add(2);
    oPath.add(3);
    oPath.add(4);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(22, oService.getLength(oPath));
}

TEST(CMyTrainsService, walkThroughPathAED)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(5);
    oPath.add(4);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(INFINITE_DISTANCE, oService.getLength(oPath));
}

TEST(CMyTrainsService, walkThroughPathAC)
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

    CPath oPath;
    oPath.add(1);
    oPath.add(3);

    CMyTrainsService oService(map);
    oService.switchToDistance();
    ASSERT_EQ(INFINITE_DISTANCE, oService.getLength(oPath));
}
