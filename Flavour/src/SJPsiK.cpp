/*
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "SJPsiK.h"

double SJPsiK::computeThValue() 
{
    return sin(-AmpBd(FULLNLO).arg());
}
