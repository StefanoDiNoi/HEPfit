/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "DmBs.h"

double  DmBs::computeThValue() 
{
    return(2. * AmpBs(FULLNLO).abs());
}