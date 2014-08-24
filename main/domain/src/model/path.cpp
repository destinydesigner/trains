// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-19
// summary: path.cpp
#include <sstream>
#include "comm/errno_define.h"
#include "model/town.h"
#include "model/path.h"

using assignment::trains::comm::ERR_NO_SUCH_TOWN;
using assignment::trains::domain::CTown;
using assignment::trains::domain::CPath;

CPath::CPath():
    m_steps(),
    m_iter(m_steps.begin())
{
}

void CPath::add(long step)
{
    m_steps.push_back(
        std::shared_ptr<CTown>(new CTown(step)));
}

const CTown& CPath::start() const
{
    m_iter = m_steps.begin();
    return next();
}

bool CPath::hasNext() const
{
    return m_iter != m_steps.end();
}

const CTown& CPath::next() const
{
    if (m_iter == m_steps.end())
    {
        return CTown::NullTown();
    }

    const CTown& step(*(*m_iter));
    m_iter++;
    return step;
}

const std::string CPath::ToString(void) const
{
    std::stringstream ss;
    for(std::vector<std::shared_ptr<CTown> >::const_iterator
        it = m_steps.begin();
        it != m_steps.end();
        it++)
    {
        if (it != m_steps.begin())
        {
            ss << ", ";
        }
        ss << (*it)->id();
    }

    return ss.str();
}
