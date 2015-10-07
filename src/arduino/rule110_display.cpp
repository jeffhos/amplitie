///////////////////////////////////////////////////////////////////////////////
// rule110_display.cpp
//
// Copyright (c) 2015 Jeffrey P. Hoskinson
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include "rule110_display.h"

Rule110Display::Rule110Display(Strand* strandP)
  : m_strandP(strandP),
    m_cells(strandP->getLength())
{
  m_cycle = 0;
}

void Rule110Display::init() 
{
  // Set up a random initial state
  int cutoff = RAND_MAX / 2;
  for (int i = 0; i < m_cells.size(); i++) {
    if (rand() > cutoff) {
      m_cells[i] = true;
    } else {
      m_cells[i] = false;
    }
  }
}

void Rule110Display::update()
{
  if (m_cycle == 0) {
    int cutoff = RAND_MAX / 2;
    for (int i = 0; i < m_cells.size(); i++) {
      if (rand() > cutoff) {
        m_cells[i] = true;
        m_strandP->setColor(i, Color::wheel(0));
      } else {
        m_cells[i] = false;
        m_strandP->setColor(i, Color(0, 0, 0));
      }
    }
  } else {
    std::vector<bool> nextGeneration(m_cells.size());
    Color generationColor = Color::wheel((m_cycle * 4) % Color::WHEEL_MAX);
    for (int i = 0; i < m_cells.size(); i++) {
      bool a = getCell(i - 1), b = getCell(i), c = getCell(i + 1);

      // 111 -> 0
      if (a && b && c) {
        nextGeneration[i] = false;
        m_strandP->setColor(i, m_strandP->getColor(i).darkenBy(DARKEN_BY));
      
      // 110 -> 1
      } else if (a && b && !c) {
        nextGeneration[i] = true;

      // 101 -> 1
      } else if (a && !b && c) {
        nextGeneration[i] = true;
        m_strandP->setColor(i, generationColor);

      // 100 -> 0
      } else if (a && !b && !c) {
        nextGeneration[i] = false;
        m_strandP->setColor(i, m_strandP->getColor(i).darkenBy(DARKEN_BY));

      // 011 -> 1
      } else if (!a && b && c) {
        nextGeneration[i] = true;

      // 010 -> 1
      } else if (!a && b && !c) {
        nextGeneration[i] = true;

      // 001 -> 1
      } else if (!a && !b && c) {
        nextGeneration[i] = true;
        m_strandP->setColor(i, generationColor);

      // 000 -> 0
      } else if (!a && !b && !c) {
        nextGeneration[i] = false;
        m_strandP->setColor(i, m_strandP->getColor(i).darkenBy(DARKEN_BY));
      }
    }

    m_cells = nextGeneration;
  }
  m_strandP->show();
  m_cycle++;
  if (m_cycle >= RESET_CYCLES) {
    m_cycle = 0;
  }
}

long Rule110Display::updateTime()
{
  return UPDATE_TIME;
}

bool Rule110Display::getCell(int n)
{
  if (n >= 0 && n < m_cells.size()) {
    return m_cells[n];
  } else {
    // This particular automata is more interesting if we consider the cells off the ends of the board to be alive
    return true;
  }
}