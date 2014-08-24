// Copyright (c) fangguojian. All rights reserved.
// author: fangguojian (destinydesigner@qq.com)
// date: 2014-08-21
// summary: town_list.cpp
#include <sstream>
#include "model/null_town.h"
#include "model/town_list.h"

using assignment::trains::domain::CTownIterator;
using assignment::trains::domain::CTownList;
using assignment::trains::domain::CNullTown;

CTownIterator::CTownIterator(
    const std::map<long, std::shared_ptr<ITown> >& map):
    m_rTownMap(map)
{
    m_oIter = m_rTownMap.begin();
}

bool CTownIterator::hasNext(void) const
{
    return m_oIter != m_rTownMap.end();
}

const ITown& CTownIterator::next(void) const
{
    if (m_oIter == m_rTownMap.end())
    {
        return CNullTown::NullTown();
    }
    const ITown& oTown(*m_oIter->second);
    m_oIter++;
    return oTown;
}

void CTownList::addIfNotExist(const std::shared_ptr<ITown> town)
{
    if (m_oTownMap.find(town->id()) != m_oTownMap.end())
    {
        return;
    }
    m_oTownMap[town->id()] = town;
}

ITown& CTownList::getById(long id) const
{
    if (m_oTownMap.find(id) == m_oTownMap.end())
    {
        return CNullTown::NullTown();
    }
    return *m_oTownMap[id];
}

CTownIterator CTownList::getIterator(void) const
{
    CTownIterator oTownIterator(m_oTownMap);
    return oTownIterator;
}

const std::string CTownList::ToString() const
{
    std::stringstream ss;
    for (std::map<long, std::shared_ptr<ITown> >::const_iterator
         it = m_oTownMap.begin();
         it != m_oTownMap.end();
         it++)
    {
        if (it != m_oTownMap.begin())
        {
            ss << ", ";
        }
        ss << it->first;
    }
    return ss.str();
}
