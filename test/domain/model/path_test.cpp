#include "model/town.h"
#include "model/path.h"
#include "gmock/gmock.h"

using assignment::trains::domain::CTown;
using assignment::trains::domain::CPath;

TEST(CPath, oneStop)
{
    CPath oPath;
    oPath.add(1);

    ASSERT_EQ(1, oPath.start().id());
    ASSERT_FALSE(oPath.hasNext());
}

TEST(CPath, twoStop)
{
    CPath oPath;
    oPath.add(1);
    oPath.add(2);

    ASSERT_EQ(1, oPath.start().id());
    ASSERT_TRUE(oPath.hasNext());
    ASSERT_EQ(2, oPath.next().id());
    ASSERT_FALSE(oPath.hasNext());
}
