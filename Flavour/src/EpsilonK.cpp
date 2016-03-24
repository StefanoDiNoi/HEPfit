/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "EpsilonK.h"

double EpsilonK::computeThValue()
{
    return(1. / SM.getDeltaMK() * AmpDK(FULLNLO).imag() * SM.getKbarEpsK() * 
            sin(SM.getphiEpsK() * M_PI / 180.));
}