/* 
 * Copyright (C) 2018 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "THDMWdirectsearches.h"
#include "StandardModel.h"



Hobs_pp_Sr_tt_ATLAS13::Hobs_pp_Sr_tt_ATLAS13(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDMW(static_cast<const THDMW&> (SM_i))
{}

double Hobs_pp_Sr_tt_ATLAS13::computeThValue()
{
    return myTHDMW.getMyTHDMWCache()->THoEX_pp_Sr_tt;
}


log10_pp_Sr_tt_TH13::log10_pp_Sr_tt_TH13(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDMW(static_cast<const THDMW&> (SM_i))
{}

double log10_pp_Sr_tt_TH13::computeThValue()
{
    return log10(myTHDMW.getMyTHDMWCache()->pp_Sr_tt_TH13);
}