/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "alpha_2a.h"

double Alpha_2a::computeThValue() 
{ 
    double twoa = (SM.computeAlpha()-SM.getPhiBd())/M_PI*180.;
    return(90. + remainder(twoa,180.));
}
