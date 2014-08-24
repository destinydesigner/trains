// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-24
// summary: trains_service_on_null_map_test.cpp
#include "comm/define.h"
#include "comm/errno_define.h"
#include "model/path.h"
#include "model/my_towns_map.h"
#include "service/my_trains_service.h"
#include "gmock/gmock.h"

using namespace assignment::trains::comm;
using assignment::trains::domain::CPath;
using assignment::trains::domain::CMyTownsMap;
using assignment::trains::domain::CMyTrainsService;

TEST(CMyTrainsServiceOnNullMap, test)
{
    CMyTownsMap oMap;
    CMyTrainsService oService(oMap);

    ASSERT_EQ(INFINITE_DISTANCE, oService.minimumDistance(1, 2));

    CPath oPath;
    ASSERT_EQ(0, oService.getLength(oPath));

    oPath.add(1);
    ASSERT_EQ(0, oService.getLength(oPath));

    oPath.add(2);
    ASSERT_EQ(INFINITE_DISTANCE, oService.getLength(oPath));

    ASSERT_EQ(0, oService.countPath(1, 2, 3, 3));
}
