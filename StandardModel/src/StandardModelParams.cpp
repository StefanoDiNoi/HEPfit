/*
 * Copyright (C) 2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#include <stdexcept>
#include "StandardModel.h"
#include "EWSM.h"
#include "StandardModelParams.h"

double StandardModelParams::computeThValue()
{
    if (name.compare("AlsMz") == 0)
        return SM.getAlsMz();
    else if (name.compare("dAle5Mz") == 0)
        return SM.getDAle5Mz();
    else if (name.compare("Mz") == 0)
        return SM.getMz();
    else if (name.compare("mtop") == 0)
        return SM.getMtpole();
    else if (name.compare("mHl") == 0)
        return SM.getMHl();
    else if (name.compare("delMw") == 0)
        return SM.getDelMw();
    else if (name.compare("delSin2th_l") == 0)
        return SM.getDelSin2th_l();
    else if (name.compare("delGammaZ") == 0)
        return SM.getDelGammaZ();
    else if (name.compare("delRhoZ_nu") == 0)
        return SM.getDelRhoZ_nu();
    else if (name.compare("delRhoZ_e") == 0)
        return SM.getDelRhoZ_e();
    else if (name.compare("delRhoZ_u") == 0)
        if (SM.IsFlagTestSubleadingTwoLoopEW())
            return SM.getEWSM()->delRhoZ_q(SM.UP);
        else
            return 0.0;
    else if (name.compare("delRhoZ_d") == 0)
        if (SM.IsFlagTestSubleadingTwoLoopEW())
            return SM.getEWSM()->delRhoZ_q(SM.DOWN);
        else
            return 0.0;
    else if (name.compare("delRhoZ_b") == 0)
        return SM.getDelRhoZ_b();
    else
        throw std::runtime_error("StandardModelParams::computeThValue(): "
                                 + name + " is not defined");
}
