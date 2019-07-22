/*
 * Copyright (C) 2019 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "HiggsThObservables.h"
#include "NPbase.h"

muggH::muggH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggH called with a class whose parent is not NPbase");
}

double muggH::computeThValue()
{
    return myNPbase->muggH(sqrt_s);
}

muVBF::muVBF(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBF called with a class whose parent is not NPbase");

}

double muVBF::computeThValue()
{
    return myNPbase->muVBF(sqrt_s);
}

muVBFgamma::muVBFgamma(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFgamma called with a class whose parent is not NPbase");

}

double muVBFgamma::computeThValue()
{
    return myNPbase->muVBFgamma(sqrt_s);
}

mueeWBF::mueeWBF(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBF called with a class whose parent is not NPbase");

}

double mueeWBF::computeThValue()
{
    return myNPbase->mueeWBF(sqrt_s);
}

mueeWBFPol::mueeWBFPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFPol called with a class whose parent is not NPbase");
}

double mueeWBFPol::computeThValue()
{
    return myNPbase->mueeWBFPol(sqrt_s, Pol_em, Pol_ep);
}

mueeHvv::mueeHvv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvv called with a class whose parent is not NPbase");
}

double mueeHvv::computeThValue()
{
    return myNPbase->mueeHvv(sqrt_s);
}

mueeHvvPol::mueeHvvPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvPol called with a class whose parent is not NPbase");
}

double mueeHvvPol::computeThValue()
{
    return myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep);
}

mueeZBF::mueeZBF(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZBF called with a class whose parent is not NPbase");

}

double mueeZBF::computeThValue()
{
    return myNPbase->mueeZBF(sqrt_s);
}

mueeZBFPol::mueeZBFPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZBFPol called with a class whose parent is not NPbase");
}

double mueeZBFPol::computeThValue()
{
    return myNPbase->mueeZBFPol(sqrt_s, Pol_em, Pol_ep);
}

muepWBF::muepWBF(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBF called with a class whose parent is not NPbase");

}

double muepWBF::computeThValue()
{
    return myNPbase->muepWBF(sqrt_s);
}

muWH::muWH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWH called with a class whose parent is not NPbase");
}

muepZBF::muepZBF(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBF called with a class whose parent is not NPbase");

}

double muepZBF::computeThValue()
{
    return myNPbase->muepZBF(sqrt_s);
}

double muWH::computeThValue()
{
    return myNPbase->muWH(sqrt_s);
}

muZH::muZH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZH called with a class whose parent is not NPbase");
}

double muZH::computeThValue()
{
    return myNPbase->muZH(sqrt_s);
}

mueeZH::mueeZH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZH called with a class whose parent is not NPbase");
}

double mueeZH::computeThValue()
{
    return myNPbase->mueeZH(sqrt_s);
}

mueeZHPol::mueeZHPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHPol called with a class whose parent is not NPbase");
}

double mueeZHPol::computeThValue()
{
    return myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep);
}

mueeZllH::mueeZllH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZllH called with a class whose parent is not NPbase");
}

double mueeZllH::computeThValue()
{
    return myNPbase->mueeZllH(sqrt_s);
}

mueeZllHPol::mueeZllHPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZllHPol called with a class whose parent is not NPbase");
}

double mueeZllHPol::computeThValue()
{
    return myNPbase->mueeZllHPol(sqrt_s, Pol_em, Pol_ep);
}

mueeZqqH::mueeZqqH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZqqH called with a class whose parent is not NPbase");
}

double mueeZqqH::computeThValue()
{
    return myNPbase->mueeZqqH(sqrt_s);
}

mueeZqqHPol::mueeZqqHPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZqqHPol called with a class whose parent is not NPbase");
}

double mueeZqqHPol::computeThValue()
{
    return myNPbase->mueeZqqHPol(sqrt_s, Pol_em, Pol_ep);
}


aPsk::aPsk(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("aPsk called with a class whose parent is not NPbase");
}

double aPsk::computeThValue()
{
    return myNPbase->aPskPol(sqrt_s, Pol_em, Pol_ep);
}


bPsk::bPsk(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("bPsk called with a class whose parent is not NPbase");
}

double bPsk::computeThValue()
{
    return myNPbase->bPskPol(sqrt_s, Pol_em, Pol_ep);
}


muVH::muVH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVH called with a class whose parent is not NPbase");
}

double muVH::computeThValue()
{
    return myNPbase->muVH(sqrt_s);
}

muVBFpVH::muVBFpVH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFpVH called with a class whose parent is not NPbase");
}

double muVBFpVH::computeThValue()
{
    return myNPbase->muVBFpVH(sqrt_s);
}

muttH::muttH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttH called with a class whose parent is not NPbase");
}

double muttH::computeThValue()
{
    return myNPbase->muttH(sqrt_s);
}

mutHq::mutHq(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mutHq called with a class whose parent is not NPbase");
}

double mutHq::computeThValue()
{
    return myNPbase->mutHq(sqrt_s);
}

muggHpttH::muggHpttH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHpttH called with a class whose parent is not NPbase");
}

double muggHpttH::computeThValue()
{
    return myNPbase->muggHpttH(sqrt_s);
}

mueettH::mueettH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueettH called with a class whose parent is not NPbase");

}

double mueettH::computeThValue()
{
    return myNPbase->mueettH(sqrt_s);
}

mueettHPol::mueettHPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueettHPol called with a class whose parent is not NPbase");
}

double mueettHPol::computeThValue()
{
    return myNPbase->mueettHPol(sqrt_s, Pol_em, Pol_ep);
}

mummH::mummH(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mummH called with a class whose parent is not NPbase");
}

double mummH::computeThValue()
{
    return myNPbase->mummH(sqrt_s);
}

GammaHRatio::GammaHRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("GammaHRatio called with a class whose parent is not NPbase");
}

double GammaHRatio::computeThValue()
{
    return myNPbase->computeGammaTotalRatio();
}

BrHtoinvRatio::BrHtoinvRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoinvRatio called with a class whose parent is not NPbase");
}

double BrHtoinvRatio::computeThValue()
{
    return myNPbase->BrHtoinvRatio();
}

BrHinvisible::BrHinvisible(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHinvisible called with a class whose parent is not NPbase");
}

double BrHinvisible::computeThValue()
{
    return myNPbase->Br_H_inv();
}

BrHinvisibleNP::BrHinvisibleNP(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHinvisibleNP called with a class whose parent is not NPbase");
}

double BrHinvisibleNP::computeThValue()
{
    return myNPbase->Br_H_inv_NP();
}

BrHexotic::BrHexotic(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHexotic called with a class whose parent is not NPbase");
}

double BrHexotic::computeThValue()
{
    return myNPbase->Br_H_exo();
}

BrHtovisRatio::BrHtovisRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtovisRatio called with a class whose parent is not NPbase");
}

double BrHtovisRatio::computeThValue()
{
    return myNPbase->BrHvisRatio();
}

BrHtoggRatio::BrHtoggRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoggRatio called with a class whose parent is not NPbase");
}

double BrHtoggRatio::computeThValue()
{
    return myNPbase->BrHggRatio();
}

BrHtoWWRatio::BrHtoWWRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoWWRatio called with a class whose parent is not NPbase");
}

double BrHtoWWRatio::computeThValue()
{
    return myNPbase->BrHWWRatio();
}

BrHtoWW2l2vRatio::BrHtoWW2l2vRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoWW2l2vRatio called with a class whose parent is not NPbase");
}

double BrHtoWW2l2vRatio::computeThValue()
{
    return myNPbase->BrHWW2l2vRatio();
}

BrHtoZZRatio::BrHtoZZRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZZRatio called with a class whose parent is not NPbase");
}

double BrHtoZZRatio::computeThValue()
{
    return myNPbase->BrHZZRatio();
}

BrHtoZZ4lRatio::BrHtoZZ4lRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZZ4lRatio called with a class whose parent is not NPbase");
}

double BrHtoZZ4lRatio::computeThValue()
{
    return myNPbase->BrHZZ4lRatio();
}

BrHtoZZ4eRatio::BrHtoZZ4eRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZZ4eRatio called with a class whose parent is not NPbase");
}

double BrHtoZZ4eRatio::computeThValue()
{
    return myNPbase->BrHZZ4eRatio();
}

BrHtoZZ2e2muRatio::BrHtoZZ2e2muRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZZ2e2muRatio called with a class whose parent is not NPbase");
}

double BrHtoZZ2e2muRatio::computeThValue()
{
    return myNPbase->BrHZZ2e2muRatio();
}

BrHtoZZ4muRatio::BrHtoZZ4muRatio(const StandardModel& SM_i)
: ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZZ4muRatio called with a class whose parent is not NPbase");
}

double BrHtoZZ4muRatio::computeThValue()
{
    return myNPbase->BrHZZ4muRatio();
}

BrHtoZgaRatio::BrHtoZgaRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZgaRatio called with a class whose parent is not NPbase");
}

double BrHtoZgaRatio::computeThValue()
{
    return myNPbase->BrHZgaRatio();
}

BrHtoZgallRatio::BrHtoZgallRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZgallRatio called with a class whose parent is not NPbase");
}

double BrHtoZgallRatio::computeThValue()
{
    return myNPbase->BrHZgallRatio();
}

BrHtoZgaeeRatio::BrHtoZgaeeRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZgaeeRatio called with a class whose parent is not NPbase");
}

double BrHtoZgaeeRatio::computeThValue()
{
    return myNPbase->BrHZgaeeRatio();
}

BrHtoZgamumuRatio::BrHtoZgamumuRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZgamumuRatio called with a class whose parent is not NPbase");
}

double BrHtoZgamumuRatio::computeThValue()
{
    return myNPbase->BrHZgamumuRatio();
}

BrHtogagaRatio::BrHtogagaRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtogagaRatio called with a class whose parent is not NPbase");
}

double BrHtogagaRatio::computeThValue()
{
    return myNPbase->BrHgagaRatio();
}

BrHtomumuRatio::BrHtomumuRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtomumuRatio called with a class whose parent is not NPbase");
}

double BrHtomumuRatio::computeThValue()
{
    return myNPbase->BrHmumuRatio();
}

BrHtotautauRatio::BrHtotautauRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtotautauRatio called with a class whose parent is not NPbase");
}

double BrHtotautauRatio::computeThValue()
{
    return myNPbase->BrHtautauRatio();
}

BrHtoccRatio::BrHtoccRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoccRatio called with a class whose parent is not NPbase");
}

double BrHtoccRatio::computeThValue()
{
    return myNPbase->BrHccRatio();
}

BrHtobbRatio::BrHtobbRatio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtobbRatio called with a class whose parent is not NPbase");
}

double BrHtobbRatio::computeThValue()
{
    return myNPbase->BrHbbRatio();
}

BrHtogaga_over_mumu_Ratio::BrHtogaga_over_mumu_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtogaga_over_mumu_Ratio called with a class whose parent is not NPbase");
}

double BrHtogaga_over_mumu_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHgagaRatio()) - (myNPbase->BrHmumuRatio()));
    } else {
        return (myNPbase->BrHgagaRatio()) / (myNPbase->BrHmumuRatio());
    }
}

BrHtoZga_over_mumu_Ratio::BrHtoZga_over_mumu_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZga_over_mumu_Ratio called with a class whose parent is not NPbase");
}

double BrHtoZga_over_mumu_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHZgaRatio()) - (myNPbase->BrHmumuRatio()));
    } else {
        return (myNPbase->BrHZgaRatio()) / (myNPbase->BrHmumuRatio());
    }
}

BrHtoZmumuga_over_mumu_Ratio::BrHtoZmumuga_over_mumu_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZmumuga_over_mumu_Ratio called with a class whose parent is not NPbase");
}

double BrHtoZmumuga_over_mumu_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHZgamumuRatio()) - (myNPbase->BrHmumuRatio()));
    } else {
        return (myNPbase->BrHZgamumuRatio()) / (myNPbase->BrHmumuRatio());
    }
}

BrHtogaga_over_4l_Ratio::BrHtogaga_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtogaga_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHtogaga_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHgagaRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHgagaRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}

BrHtobb_over_4l_Ratio::BrHtobb_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtobb_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHtobb_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHbbRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHbbRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}


BrHto2l2v_over_4l_Ratio::BrHto2l2v_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHto2l2v_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHto2l2v_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHWW2l2vRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHWW2l2vRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}


BrHtotautau_over_4l_Ratio::BrHtotautau_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtotautau_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHtotautau_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHtautauRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHtautauRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}


BrHtogaga_over_2e2mu_Ratio::BrHtogaga_over_2e2mu_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtogaga_over_2e2mu_Ratio called with a class whose parent is not NPbase");
}

double BrHtogaga_over_2e2mu_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHgagaRatio()) - (myNPbase->BrHZZ2e2muRatio()));
    } else {
        return (myNPbase->BrHgagaRatio()) / (myNPbase->BrHZZ2e2muRatio());
    }
}

BrHtoZga_over_4l_Ratio::BrHtoZga_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZga_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHtoZga_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHZgaRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHZgaRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}

BrHtomumu_over_4l_Ratio::BrHtomumu_over_4l_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtomumu_over_4l_Ratio called with a class whose parent is not NPbase");
}

double BrHtomumu_over_4l_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHmumuRatio()) - (myNPbase->BrHZZ4lRatio()));
    } else {
        return (myNPbase->BrHmumuRatio()) / (myNPbase->BrHZZ4lRatio());
    }
}

BrHtomumu_over_4mu_Ratio::BrHtomumu_over_4mu_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtomumu_over_4mu_Ratio called with a class whose parent is not NPbase");
}

double BrHtomumu_over_4mu_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHmumuRatio()) - (myNPbase->BrHZZ4muRatio()));
    } else {
        return (myNPbase->BrHmumuRatio()) / (myNPbase->BrHZZ4muRatio());
    }
}

BrHto4l_over_gaga_Ratio::BrHto4l_over_gaga_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHto4l_over_gaga_Ratio called with a class whose parent is not NPbase");
}

double BrHto4l_over_gaga_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHZZ4lRatio()) - (myNPbase->BrHgagaRatio()));
    } else {
        return (myNPbase->BrHZZ4lRatio()) / (myNPbase->BrHgagaRatio());
    }
}

BrHtoZga_over_gaga_Ratio::BrHtoZga_over_gaga_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtoZga_over_gaga_Ratio called with a class whose parent is not NPbase");
}

double BrHtoZga_over_gaga_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHZgaRatio()) - (myNPbase->BrHgagaRatio()));
    } else {
        return (myNPbase->BrHZgaRatio()) / (myNPbase->BrHgagaRatio());
    }
}

BrHtomumu_over_gaga_Ratio::BrHtomumu_over_gaga_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHtomumu_over_gaga_Ratio called with a class whose parent is not NPbase");
}

double BrHtomumu_over_gaga_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHmumuRatio()) - (myNPbase->BrHgagaRatio()));
    } else {
        return (myNPbase->BrHmumuRatio()) / (myNPbase->BrHgagaRatio());
    }
}

muggHgaga::muggHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHgaga called with a class whose parent is not NPbase");
}

double muggHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muggHgaga(sqrt_s);
    }
}

muggHgagaInt::muggHgagaInt(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHgagaInt called with a class whose parent is not NPbase");
}

double muggHgagaInt::computeThValue()
{
    return (myNPbase->muggHgagaInt(sqrt_s)) / (myNPbase->BrHgagaRatio());
}

muVBFHgaga::muVBFHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHgaga called with a class whose parent is not NPbase");
}

double muVBFHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muVBFHgaga(sqrt_s);
    }
}

muZHgaga::muZHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHgaga called with a class whose parent is not NPbase");
}

double muZHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muZHgaga(sqrt_s);
    }
}

muWHgaga::muWHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHgaga called with a class whose parent is not NPbase");
}

double muWHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muWHgaga(sqrt_s);
    }
}

muVHgaga::muVHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHgaga called with a class whose parent is not NPbase");
}

double muVHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muVHgaga(sqrt_s);
    }
}

muttHgaga::muttHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHgaga called with a class whose parent is not NPbase");
}

double muttHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHgagaRatio()));
    } else {
        return myNPbase->muttHgaga(sqrt_s);
    }
}

muggHZga::muggHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHZga called with a class whose parent is not NPbase");
}

double muggHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muggHZga(sqrt_s);
    }
}

muggHZgamumu::muggHZgamumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHZgamumu called with a class whose parent is not NPbase");
}

double muggHZgamumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHZgamumuRatio()));
    } else {
        return (myNPbase->muggH(sqrt_s))*(myNPbase->BrHZgamumuRatio());
    }
}

muVBFHZga::muVBFHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHZga called with a class whose parent is not NPbase");
}

double muVBFHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muVBFHZga(sqrt_s);
    }
}

muZHZga::muZHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHZga called with a class whose parent is not NPbase");
}

double muZHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muZHZga(sqrt_s);
    }
}

muWHZga::muWHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHZga called with a class whose parent is not NPbase");
}

double muWHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muWHZga(sqrt_s);
    }
}

muVHZga::muVHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHZga called with a class whose parent is not NPbase");
}

double muVHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muVHZga(sqrt_s);
    }
}

muttHZga::muttHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHZga called with a class whose parent is not NPbase");
}

double muttHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHZgaRatio()));
    } else {
        return myNPbase->muttHZga(sqrt_s);
    }
}

muggHZZ::muggHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHZZ called with a class whose parent is not NPbase");
}

double muggHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muggHZZ(sqrt_s);
    }
}

muVBFHZZ::muVBFHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHZZ called with a class whose parent is not NPbase");
}

double muVBFHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muVBFHZZ(sqrt_s);
    }
}

muZHZZ::muZHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHZZ called with a class whose parent is not NPbase");
}

double muZHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muZHZZ(sqrt_s);
    }
}

muWHZZ::muWHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHZZ called with a class whose parent is not NPbase");
}

double muWHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muWHZZ(sqrt_s);
    }
}

muVHZZ::muVHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHZZ called with a class whose parent is not NPbase");
}

double muVHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muVHZZ(sqrt_s);
    }
}

muttHZZ::muttHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHZZ called with a class whose parent is not NPbase");
}

double muttHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHZZRatio()));
    } else {
        return myNPbase->muttHZZ(sqrt_s);
    }
}

muggHZZ4l::muggHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHZZ4l called with a class whose parent is not NPbase");
}

double muggHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muggHZZ4l(sqrt_s);
    }
}

muggHZZ4mu::muggHZZ4mu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHZZ4mu called with a class whose parent is not NPbase");
}

double muggHZZ4mu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHZZ4muRatio()));
    } else {
        return (myNPbase->muggH(sqrt_s))*(myNPbase->BrHZZ4muRatio());
    }
}

muVBFHZZ4l::muVBFHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHZZ4l called with a class whose parent is not NPbase");
}

double muVBFHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muVBFHZZ4l(sqrt_s);
    }
}

muZHZZ4l::muZHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHZZ4l called with a class whose parent is not NPbase");
}

double muZHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muZHZZ4l(sqrt_s);
    }
}

muWHZZ4l::muWHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHZZ4l called with a class whose parent is not NPbase");
}

double muWHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muWHZZ4l(sqrt_s);
    }
}

muVHZZ4l::muVHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHZZ4l called with a class whose parent is not NPbase");
}

double muVHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muVHZZ4l(sqrt_s);
    }
}

muttHZZ4l::muttHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHZZ4l called with a class whose parent is not NPbase");
}

double muttHZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()));
    } else {
        return myNPbase->muttHZZ4l(sqrt_s);
    }
}

muggHWW::muggHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHWW called with a class whose parent is not NPbase");
}

double muggHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muggHWW(sqrt_s);
    }
}

muVBFHWW::muVBFHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHWW called with a class whose parent is not NPbase");
}

double muVBFHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muVBFHWW(sqrt_s);
    }
}

muZHWW::muZHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHWW called with a class whose parent is not NPbase");
}

double muZHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muZHWW(sqrt_s);
    }
}

muWHWW::muWHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHWW called with a class whose parent is not NPbase");
}

double muWHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muWHWW(sqrt_s);
    }
}

muVHWW::muVHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHWW called with a class whose parent is not NPbase");
}

double muVHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muVHWW(sqrt_s);
    }
}

muttHWW::muttHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHWW called with a class whose parent is not NPbase");
}

double muttHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHWWRatio()));
    } else {
        return myNPbase->muttHWW(sqrt_s);
    }
}

muggHWW2l2v::muggHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHWW2l2v called with a class whose parent is not NPbase");
}

double muggHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muggHWW2l2v(sqrt_s);
    }
}

muVBFHWW2l2v::muVBFHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHWW2l2v called with a class whose parent is not NPbase");
}

double muVBFHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muVBFHWW2l2v(sqrt_s);
    }
}

muZHWW2l2v::muZHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHWW2l2v called with a class whose parent is not NPbase");
}

double muZHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muZHWW2l2v(sqrt_s);
    }
}

muWHWW2l2v::muWHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHWW2l2v called with a class whose parent is not NPbase");
}

double muWHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muWHWW2l2v(sqrt_s);
    }
}

muVHWW2l2v::muVHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHWW2l2v called with a class whose parent is not NPbase");
}

double muVHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muVHWW2l2v(sqrt_s);
    }
}

muttHWW2l2v::muttHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHWW2l2v called with a class whose parent is not NPbase");
}

double muttHWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()));
    } else {
        return myNPbase->muttHWW2l2v(sqrt_s);
    }
}

muggHmumu::muggHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHmumu called with a class whose parent is not NPbase");
}

double muggHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muggHmumu(sqrt_s);
    }
}

muVBFHmumu::muVBFHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHmumu called with a class whose parent is not NPbase");
}

double muVBFHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muVBFHmumu(sqrt_s);
    }
}

muZHmumu::muZHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHmumu called with a class whose parent is not NPbase");
}

double muZHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muZHmumu(sqrt_s);
    }
}

muWHmumu::muWHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHmumu called with a class whose parent is not NPbase");
}

double muWHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muWHmumu(sqrt_s);
    }
}

muVHmumu::muVHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHmumu called with a class whose parent is not NPbase");
}

double muVHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muVHmumu(sqrt_s);
    }
}

muttHmumu::muttHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHmumu called with a class whose parent is not NPbase");
}

double muttHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHmumuRatio()));
    } else {
        return myNPbase->muttHmumu(sqrt_s);
    }
}

muggHtautau::muggHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHtautau called with a class whose parent is not NPbase");
}

double muggHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muggHtautau(sqrt_s);
    }
}

muVBFHtautau::muVBFHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHtautau called with a class whose parent is not NPbase");
}

double muVBFHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muVBFHtautau(sqrt_s);
    }
}

muZHtautau::muZHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHtautau called with a class whose parent is not NPbase");
}

double muZHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muZHtautau(sqrt_s);
    }
}

muWHtautau::muWHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHtautau called with a class whose parent is not NPbase");
}

double muWHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muWHtautau(sqrt_s);
    }
}

muVHtautau::muVHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHtautau called with a class whose parent is not NPbase");
}

double muVHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muVHtautau(sqrt_s);
    }
}

muttHtautau::muttHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHtautau called with a class whose parent is not NPbase");
}

double muttHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHtautauRatio()));
    } else {
        return myNPbase->muttHtautau(sqrt_s);
    }
}

muggHbb::muggHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggHbb called with a class whose parent is not NPbase");
}

double muggHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muggH(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muggHbb(sqrt_s);
    }
}

muVBFHbb::muVBFHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHbb called with a class whose parent is not NPbase");
}

double muVBFHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muVBFHbb(sqrt_s);
    }
}

muZHbb::muZHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muZHbb called with a class whose parent is not NPbase");
}

double muZHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muZH(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muZHbb(sqrt_s);
    }
}

muWHbb::muWHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muWHbb called with a class whose parent is not NPbase");
}

double muWHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muWH(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muWHbb(sqrt_s);
    }
}

muVHbb::muVHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHbb called with a class whose parent is not NPbase");
}

double muVHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muVH(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muVHbb(sqrt_s);
    }
}

muttHbb::muttHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHbb called with a class whose parent is not NPbase");
}

double muttHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ( -1.0 + (myNPbase->muttH(sqrt_s)) + (myNPbase->BrHbbRatio()));
    } else {
        return myNPbase->muttHbb(sqrt_s);
    }
}


muVBFBRinv::muVBFBRinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFBRinv called with a class whose parent is not NPbase");
}

double muVBFBRinv::computeThValue()
{

    return (myNPbase->muVBF(sqrt_s))*(myNPbase->Br_H_inv());

}

muVBFHinv::muVBFHinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVBFHinv called with a class whose parent is not NPbase");
}

double muVBFHinv::computeThValue()
{

    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muVBF(sqrt_s)) + (myNPbase->BrHtoinvRatio()) - 1.0);
    } else {
        return (myNPbase->muVBF(sqrt_s))*(myNPbase->BrHtoinvRatio());
    }

}


muVHBRinv::muVHBRinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHBRinv called with a class whose parent is not NPbase");
}

double muVHBRinv::computeThValue()
{

    return (myNPbase->muVH(sqrt_s))*(myNPbase->Br_H_inv());

}

muVHinv::muVHinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muVHinv called with a class whose parent is not NPbase");
}

double muVHinv::computeThValue()
{

    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muVH(sqrt_s)) + (myNPbase->BrHtoinvRatio()) - 1.0);
    } else {
        return (myNPbase->muVH(sqrt_s))*(myNPbase->BrHtoinvRatio());
    }

}


muppHmumu::muppHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muppHmumu called with a class whose parent is not NPbase");
}

double muppHmumu::computeThValue()
{
    return myNPbase->muppHmumu(sqrt_s);
}

muppHZga::muppHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muppHZga called with a class whose parent is not NPbase");
}

double muppHZga::computeThValue()
{
    return myNPbase->muppHZga(sqrt_s);
}

muggHH2ga2b::muggHH2ga2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muggH called with a class whose parent is not NPbase");
}

double muggHH2ga2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (-2.0 + (myNPbase->muggHH(sqrt_s)) + (myNPbase->BrHgagaRatio()) + (myNPbase->BrHbbRatio()));
    } else {
        return (myNPbase->muggHH(sqrt_s))*(myNPbase->BrHgagaRatio())*(myNPbase->BrHbbRatio());
    }
}

muttHZbbboost::muttHZbbboost(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muttHZbbboost called with a class whose parent is not NPbase");
}

double muttHZbbboost::computeThValue()
{
    return (myNPbase->muttHZbbboost(sqrt_s));
}

UpperLimit_ppHZgammaA::UpperLimit_ppHZgammaA(const StandardModel& SM_i, const double sqrt_s_i) : ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("UpperLimit_ppHZgammaA called with a class whose parent is not NPbase");
}

double UpperLimit_ppHZgammaA::computeThValue()
{
    return myNPbase->UpperLimitZgammaA(sqrt_s);
}

UpperLimit_ppHZgammaA13::UpperLimit_ppHZgammaA13(const StandardModel& SM_i, const double sqrt_s_i) : ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("UpperLimit_ppHZgammaA13 called with a class whose parent is not NPbase");
}

double UpperLimit_ppHZgammaA13::computeThValue()
{
    return myNPbase->UpperLimitZgammaA13(sqrt_s);
}

UpperLimit_ppHZgammaC13::UpperLimit_ppHZgammaC13(const StandardModel& SM_i, const double sqrt_s_i) : ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("UpperLimit_ppHZgammaC13 called with a class whose parent is not NPbase");
}

double UpperLimit_ppHZgammaC13::computeThValue()
{
    return myNPbase->UpperLimitZgammaC13(sqrt_s);
}

UpperLimit_ppHZgammaC::UpperLimit_ppHZgammaC(const StandardModel& SM_i, const double sqrt_s_i) : ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("UpperLimit_ppHZgammaC called with a class whose parent is not NPbase");
}

double UpperLimit_ppHZgammaC::computeThValue()
{
    return myNPbase->UpperLimitZgammaC(sqrt_s);
}

cg_plus_ct::cg_plus_ct(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cg_plus_ct called with a class whose parent is not NPbase");
}

double cg_plus_ct::computeThValue()
{
    return myNPbase->cgplusct();
}

cga_plus_ct::cga_plus_ct(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cga_plus_ct called with a class whose parent is not NPbase");
}

double cga_plus_ct::computeThValue()
{
    return myNPbase->cgaplusct();
}

cg_minus_cga::cg_minus_cga(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cg_minus_cga called with a class whose parent is not NPbase");
}

double cg_minus_cga::computeThValue()
{
    return myNPbase->cgminuscga();
}

cV_plus_cb::cV_plus_cb(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cV_plus_cb called with a class whose parent is not NPbase");
}
\
    

double cV_plus_cb::computeThValue()
{
    return myNPbase->cVpluscb();
}

cV_plus_ctau::cV_plus_ctau(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cV_plus_ctau called with a class whose parent is not NPbase");
}

double cV_plus_ctau::computeThValue()
{
    return myNPbase->cVplusctau();
}

cb_minus_cc::cb_minus_cc(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cb_minus_cc called with a class whose parent is not NPbase");
}

double cb_minus_cc::computeThValue()
{
    return myNPbase->cbminuscc();
}

cb_minus_ctau::cb_minus_ctau(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cb_minus_ctau called with a class whose parent is not NPbase");
}

double cb_minus_ctau::computeThValue()
{
    return myNPbase->cbminusctau();
}

cc_minus_ctau::cc_minus_ctau(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("cc_minus_ctau called with a class whose parent is not NPbase");
}

double cc_minus_ctau::computeThValue()
{
    return myNPbase->ccminusctau();
}

mueeZHbb::mueeZHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHbb called with a class whose parent is not NPbase");
}

double mueeZHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

mueeZHcc::mueeZHcc(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHcc called with a class whose parent is not NPbase");
}

double mueeZHcc::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHccRatio());
    }
}

mueeZHgg::mueeZHgg(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHgg called with a class whose parent is not NPbase");
}

double mueeZHgg::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHggRatio());
    }
}

mueeZHWW::mueeZHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHcc called with a class whose parent is not NPbase");
}

double mueeZHWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHWWRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHWWRatio());
    }
}

mueeZHtautau::mueeZHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHtautau called with a class whose parent is not NPbase");
}

double mueeZHtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHtautauRatio());
    }
}

mueeZHZZ::mueeZHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHZZ called with a class whose parent is not NPbase");
}

double mueeZHZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHZZRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHZZRatio());
    }
}

mueeZHZga::mueeZHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHZga called with a class whose parent is not NPbase");
}

double mueeZHZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHZgaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHZgaRatio());
    }
}

mueeZHgaga::mueeZHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHgaga called with a class whose parent is not NPbase");
}

double mueeZHgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHgagaRatio());
    }
}

mueeZHmumu::mueeZHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHmumu called with a class whose parent is not NPbase");
}

double mueeZHmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHmumuRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHmumuRatio());
    }
}

mueeZHBRinv::mueeZHBRinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHBRinv called with a class whose parent is not NPbase");
}

double mueeZHBRinv::computeThValue()
{

    return (myNPbase->mueeZH(sqrt_s))*(myNPbase->Br_H_inv());

}

mueeZHinv::mueeZHinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHinv called with a class whose parent is not NPbase");
}

double mueeZHinv::computeThValue()
{

    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZH(sqrt_s)) + (myNPbase->BrHtoinvRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZH(sqrt_s))*(myNPbase->BrHtoinvRatio());
    }

}

mueeZHbbPol::mueeZHbbPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHbbPol called with a class whose parent is not NPbase");
}

double mueeZHbbPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHbbRatio());
    }
}

mueeZHccPol::mueeZHccPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHccPol called with a class whose parent is not NPbase");
}

double mueeZHccPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHccRatio());
    }
}

mueeZHggPol::mueeZHggPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHggPol called with a class whose parent is not NPbase");
}

double mueeZHggPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHggRatio());
    }
}

mueeZHWWPol::mueeZHWWPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHccPol called with a class whose parent is not NPbase");
}

double mueeZHWWPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHWWRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHWWRatio());
    }
}

mueeZHtautauPol::mueeZHtautauPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHtautauPol called with a class whose parent is not NPbase");
}

double mueeZHtautauPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHtautauRatio());
    }
}

mueeZHZZPol::mueeZHZZPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHZZPol called with a class whose parent is not NPbase");
}

double mueeZHZZPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHZZRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHZZRatio());
    }
}

mueeZHZgaPol::mueeZHZgaPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHZgaPol called with a class whose parent is not NPbase");
}

double mueeZHZgaPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHZgaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHZgaRatio());
    }
}

mueeZHgagaPol::mueeZHgagaPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHgagaPol called with a class whose parent is not NPbase");
}

double mueeZHgagaPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHgagaRatio());
    }
}

mueeZHmumuPol::mueeZHmumuPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHmumuPol called with a class whose parent is not NPbase");
}

double mueeZHmumuPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHmumuRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHmumuRatio());
    }
}

mueeZHBRinvPol::mueeZHBRinvPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHBRinvPol called with a class whose parent is not NPbase");
}

double mueeZHBRinvPol::computeThValue()
{
    return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->Br_H_inv());

}

mueeZHinvPol::mueeZHinvPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZHinvPol called with a class whose parent is not NPbase");
}

double mueeZHinvPol::computeThValue()
{

    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHtoinvRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHtoinvRatio());
    }

}

mueeWBFbb::mueeWBFbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFbb called with a class whose parent is not NPbase");

}

double mueeWBFbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

mueeWBFbbPol::mueeWBFbbPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFbbPol called with a class whose parent is not NPbase");

}

double mueeWBFbbPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBFPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBFPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHbbRatio());
    }
}

mueeWBFcc::mueeWBFcc(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFcc called with a class whose parent is not NPbase");

}

double mueeWBFcc::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHccRatio());
    }
}

mueeWBFgg::mueeWBFgg(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFgg called with a class whose parent is not NPbase");

}

double mueeWBFgg::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHggRatio());
    }
}

mueeWBFWW::mueeWBFWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFWW called with a class whose parent is not NPbase");

}

double mueeWBFWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHWWRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHWWRatio());
    }
}

mueeWBFtautau::mueeWBFtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFtautau called with a class whose parent is not NPbase");

}

double mueeWBFtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHtautauRatio());
    }
}

mueeWBFZZ::mueeWBFZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFZZ called with a class whose parent is not NPbase");

}

double mueeWBFZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHZZRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHZZRatio());
    }
}

mueeWBFZga::mueeWBFZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFZga called with a class whose parent is not NPbase");

}

double mueeWBFZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHZgaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHZgaRatio());
    }
}

mueeWBFgaga::mueeWBFgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFgaga called with a class whose parent is not NPbase");

}

double mueeWBFgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHgagaRatio());
    }
}

mueeWBFmumu::mueeWBFmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeWBFmumu called with a class whose parent is not NPbase");

}

double mueeWBFmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeWBF(sqrt_s)) + (myNPbase->BrHmumuRatio()) - 1.0);
    } else {
        return (myNPbase->mueeWBF(sqrt_s))*(myNPbase->BrHmumuRatio());
    }
}

mueeHvvbb::mueeHvvbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvbb called with a class whose parent is not NPbase");

}

double mueeHvvbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

mueeHvvbbPol::mueeHvvbbPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvbbPol called with a class whose parent is not NPbase");

}

double mueeHvvbbPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHbbRatio());
    }
}

mueeHvvcc::mueeHvvcc(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvcc called with a class whose parent is not NPbase");

}

double mueeHvvcc::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHccRatio());
    }
}

mueeHvvccPol::mueeHvvccPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvccPol called with a class whose parent is not NPbase");

}

double mueeHvvccPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHccRatio());
    }
}

mueeHvvgg::mueeHvvgg(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvgg called with a class whose parent is not NPbase");

}

double mueeHvvgg::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHggRatio());
    }
}

mueeHvvggPol::mueeHvvggPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvggPol called with a class whose parent is not NPbase");

}

double mueeHvvggPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHggRatio());
    }
}

mueeHvvWW::mueeHvvWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvWW called with a class whose parent is not NPbase");

}

double mueeHvvWW::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHWWRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHWWRatio());
    }
}

mueeHvvWWPol::mueeHvvWWPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvWWPol called with a class whose parent is not NPbase");

}

double mueeHvvWWPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHWWRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHWWRatio());
    }
}

mueeHvvtautau::mueeHvvtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvtautau called with a class whose parent is not NPbase");

}

double mueeHvvtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHtautauRatio());
    }
}

mueeHvvtautauPol::mueeHvvtautauPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvtautauPol called with a class whose parent is not NPbase");

}

double mueeHvvtautauPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHtautauRatio());
    }
}

mueeHvvZZ::mueeHvvZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvZZ called with a class whose parent is not NPbase");

}

double mueeHvvZZ::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHZZRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHZZRatio());
    }
}

mueeHvvZZPol::mueeHvvZZPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvZZPol called with a class whose parent is not NPbase");

}

double mueeHvvZZPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHZZRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHZZRatio());
    }
}

mueeHvvZga::mueeHvvZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvZga called with a class whose parent is not NPbase");

}

double mueeHvvZga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHZgaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHZgaRatio());
    }
}

mueeHvvZgaPol::mueeHvvZgaPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvZgaPol called with a class whose parent is not NPbase");

}

double mueeHvvZgaPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHZgaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHZgaRatio());
    }
}

mueeHvvgaga::mueeHvvgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvgaga called with a class whose parent is not NPbase");

}

double mueeHvvgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHgagaRatio());
    }
}

mueeHvvgagaPol::mueeHvvgagaPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvgagaPol called with a class whose parent is not NPbase");

}

double mueeHvvgagaPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHgagaRatio());
    }
}

mueeHvvmumu::mueeHvvmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvmumu called with a class whose parent is not NPbase");

}

double mueeHvvmumu::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvv(sqrt_s)) + (myNPbase->BrHmumuRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvv(sqrt_s))*(myNPbase->BrHmumuRatio());
    }
}

mueeHvvmumuPol::mueeHvvmumuPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeHvvmumuPol called with a class whose parent is not NPbase");

}

double mueeHvvmumuPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHmumuRatio()) - 1.0);
    } else {
        return (myNPbase->mueeHvvPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHmumuRatio());
    }
}

mueeZBFbb::mueeZBFbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZBFbb called with a class whose parent is not NPbase");
}

double mueeZBFbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZBF(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZBF(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

mueeZBFbbPol::mueeZBFbbPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueeZBFbbPol called with a class whose parent is not NPbase");
}

double mueeZBFbbPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueeZBFPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueeZBFPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHbbRatio());
    }
}

mueettHbb::mueettHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueettHbb called with a class whose parent is not NPbase");
}

double mueettHbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueettH(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueettH(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

mueettHbbPol::mueettHbbPol(const StandardModel& SM_i, const double sqrt_s_i, const double Pol_em_i, const double Pol_ep_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i), Pol_em(Pol_em_i), Pol_ep(Pol_ep_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("mueettHbbPol called with a class whose parent is not NPbase");
}

double mueettHbbPol::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->mueettHPol(sqrt_s, Pol_em, Pol_ep)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->mueettHPol(sqrt_s, Pol_em, Pol_ep))*(myNPbase->BrHbbRatio());
    }
}

muepWBFbb::muepWBFbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFbb called with a class whose parent is not NPbase");

}

double muepWBFbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

muepWBFcc::muepWBFcc(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFcc called with a class whose parent is not NPbase");

}

double muepWBFcc::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHccRatio());
    }
}

muepWBFgg::muepWBFgg(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFgg called with a class whose parent is not NPbase");

}

double muepWBFgg::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHggRatio());
    }
}

muepWBFWW2l2v::muepWBFWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFWW2l2v called with a class whose parent is not NPbase");

}

double muepWBFWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHWW2l2vRatio());
    }
}

muepWBFZZ4l::muepWBFZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFZZ4l called with a class whose parent is not NPbase");

}

double muepWBFZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

muepWBFgaga::muepWBFgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFgaga called with a class whose parent is not NPbase");

}

double muepWBFgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHgagaRatio());
    }
}

muepWBFtautau::muepWBFtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepWBFtautau called with a class whose parent is not NPbase");

}

double muepWBFtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepWBF(sqrt_s)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->muepWBF(sqrt_s))*(myNPbase->BrHtautauRatio());
    }
}

muepZBFbb::muepZBFbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFbb called with a class whose parent is not NPbase");

}

double muepZBFbb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

muepZBFcc::muepZBFcc(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFcc called with a class whose parent is not NPbase");

}

double muepZBFcc::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHccRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHccRatio());
    }
}

muepZBFgg::muepZBFgg(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFgg called with a class whose parent is not NPbase");

}

double muepZBFgg::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHggRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHggRatio());
    }
}

muepZBFWW2l2v::muepZBFWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFWW2l2v called with a class whose parent is not NPbase");

}

double muepZBFWW2l2v::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHWW2l2vRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHWW2l2vRatio());
    }
}

muepZBFZZ4l::muepZBFZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFZZ4l called with a class whose parent is not NPbase");

}

double muepZBFZZ4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

muepZBFgaga::muepZBFgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFgaga called with a class whose parent is not NPbase");

}

double muepZBFgaga::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHgagaRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHgagaRatio());
    }
}

muepZBFtautau::muepZBFtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muepZBFtautau called with a class whose parent is not NPbase");

}

double muepZBFtautau::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->muepZBF(sqrt_s)) + (myNPbase->BrHtautauRatio()) - 1.0);
    } else {
        return (myNPbase->muepZBF(sqrt_s))*(myNPbase->BrHtautauRatio());
    }
}


// -----------------------------------------------------------------------------
// STXS bins
// -----------------------------------------------------------------------------

STXSggH_VBFtopo_j3v_4l::STXSggH_VBFtopo_j3v_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH_VBFtopo_j3v_4l called with a class whose parent is not NPbase");

}

double STXSggH_VBFtopo_j3v_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH_VBFtopo_j3v(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH_VBFtopo_j3v(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH_VBFtopo_j3_4l::STXSggH_VBFtopo_j3_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH_VBFtopo_j3_4l called with a class whose parent is not NPbase");

}

double STXSggH_VBFtopo_j3_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH_VBFtopo_j3(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH_VBFtopo_j3(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH0j4l::STXSggH0j4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH0j4l called with a class whose parent is not NPbase");

}

double STXSggH0j4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH0j(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH0j(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSggH1j_pTH_0_60_4l::STXSggH1j_pTH_0_60_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH1j_pTH_0_60_4l called with a class whose parent is not NPbase");

}

double STXSggH1j_pTH_0_60_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH1j_pTH_0_60(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH1j_pTH_0_60(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSggH1j_pTH_60_120_4l::STXSggH1j_pTH_60_120_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH1j_pTH_60_120_4l called with a class whose parent is not NPbase");

}

double STXSggH1j_pTH_60_120_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH1j_pTH_60_120(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH1j_pTH_60_120(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSggH1j_pTH_120_200_4l::STXSggH1j_pTH_120_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH1j_pTH_120_200_4l called with a class whose parent is not NPbase");

}

double STXSggH1j_pTH_120_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH1j_pTH_120_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH1j_pTH_120_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSggH1j_pTH_200_4l::STXSggH1j_pTH_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH1j_pTH_200_4l called with a class whose parent is not NPbase");

}

double STXSggH1j_pTH_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH1j_pTH_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH1j_pTH_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSggH2j_pTH_0_200_4l::STXSggH2j_pTH_0_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH2j_pTH_0_200_4l called with a class whose parent is not NPbase");

}

double STXSggH2j_pTH_0_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH2j_pTH_0_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH2j_pTH_0_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH2j_pTH_0_60_4l::STXSggH2j_pTH_0_60_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH2j_pTH_0_60_4l called with a class whose parent is not NPbase");

}

double STXSggH2j_pTH_0_60_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH2j_pTH_0_60(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH2j_pTH_0_60(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH2j_pTH_60_120_4l::STXSggH2j_pTH_60_120_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH2j_pTH_60_120_4l called with a class whose parent is not NPbase");

}

double STXSggH2j_pTH_60_120_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH2j_pTH_60_120(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH2j_pTH_60_120(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH2j_pTH_120_200_4l::STXSggH2j_pTH_120_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH2j_pTH_120_200_4l called with a class whose parent is not NPbase");

}

double STXSggH2j_pTH_120_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH2j_pTH_120_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH2j_pTH_120_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSggH2j_pTH_200_4l::STXSggH2j_pTH_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSggH2j_pTH_200_4l called with a class whose parent is not NPbase");

}

double STXSggH2j_pTH_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ggH2j_pTH_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ggH2j_pTH_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHqq_VBFtopo_Rest_4l::STXSqqHqq_VBFtopo_Rest_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_VBFtopo_Rest_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_VBFtopo_Rest_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_VBFtopo_Rest(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_VBFtopo_Rest(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHqq_VBFtopo_j3v_4l::STXSqqHqq_VBFtopo_j3v_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_VBFtopo_j3v_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_VBFtopo_j3v_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_VBFtopo_j3v(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_VBFtopo_j3v(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}



STXSqqHqq_VBFtopo_j3_4l::STXSqqHqq_VBFtopo_j3_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_VBFtopo_j3_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_VBFtopo_j3_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_VBFtopo_j3(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_VBFtopo_j3(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}



STXSqqHqq_VHtopo_4l::STXSqqHqq_VHtopo_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_VHtopo_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_VHtopo_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_VHtopo(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_VHtopo(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHqq_Rest_4l::STXSqqHqq_Rest_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_Rest_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_Rest_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_Rest(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_Rest(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHqq_pTj_200_4l::STXSqqHqq_pTj_200_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHqq_pTj_200_4l called with a class whose parent is not NPbase");

}

double STXSqqHqq_pTj_200_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHqq_pTj_200(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHqq_pTj_200(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSqqHlv_pTV_0_250_4l::STXSqqHlv_pTV_0_250_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_0_250_4l called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_0_250_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_0_250(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_0_250(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHlv_pTV_0_150_4l::STXSqqHlv_pTV_0_150_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_0_150_4l called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_0_150_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_0_150(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_0_150(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}



STXSqqHlv_pTV_150_250_0j_4l::STXSqqHlv_pTV_150_250_0j_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_150_250_0j_4l called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_150_250_0j_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_150_250_0j(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_150_250_0j(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}



STXSqqHlv_pTV_150_250_1j_4l::STXSqqHlv_pTV_150_250_1j_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_150_250_1j_4l called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_150_250_1j_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_150_250_1j(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_150_250_1j(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHlv_pTV_250_4l::STXSqqHlv_pTV_250_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_250_4l called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_250_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_250(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_250(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSqqHll_pTV_0_150_4l::STXSqqHll_pTV_0_150_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_0_150_4l called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_0_150_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_0_150(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_0_150(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSqqHll_pTV_150_250_4l::STXSqqHll_pTV_150_250_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_4l called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHll_pTV_150_250_0j_4l::STXSqqHll_pTV_150_250_0j_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_0j_4l called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_0j_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250_0j(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250_0j(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHll_pTV_150_250_1j_4l::STXSqqHll_pTV_150_250_1j_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_1j_4l called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_1j_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250_1j(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250_1j(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHll_pTV_250_4l::STXSqqHll_pTV_250_4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_250_4l called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_250_4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_250(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_250(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}

STXSttHtH4l::STXSttHtH4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSttHtH4l called with a class whose parent is not NPbase");

}

double STXSttHtH4l::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ttHtH(sqrt_s)) + (myNPbase->BrHZZ4lRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ttHtH(sqrt_s))*(myNPbase->BrHZZ4lRatio());
    }
}


STXSqqHlv_pTV_0_250_bb::STXSqqHlv_pTV_0_250_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_0_250_bb called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_0_250_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_0_250(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_0_250(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSqqHlv_pTV_0_150_bb::STXSqqHlv_pTV_0_150_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_0_150_bb called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_0_150_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_0_150(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_0_150(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}



STXSqqHlv_pTV_150_250_0j_bb::STXSqqHlv_pTV_150_250_0j_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_150_250_0j_bb called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_150_250_0j_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_150_250_0j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_150_250_0j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}



STXSqqHlv_pTV_150_250_1j_bb::STXSqqHlv_pTV_150_250_1j_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_150_250_1j_bb called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_150_250_1j_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_150_250_1j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_150_250_1j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSqqHlv_pTV_250_bb::STXSqqHlv_pTV_250_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHlv_pTV_250_bb called with a class whose parent is not NPbase");

}

double STXSqqHlv_pTV_250_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHlv_pTV_250(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHlv_pTV_250(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

STXSqqHll_pTV_0_150_bb::STXSqqHll_pTV_0_150_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_0_150_bb called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_0_150_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_0_150(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_0_150(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}

STXSqqHll_pTV_150_250_bb::STXSqqHll_pTV_150_250_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_bb called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSqqHll_pTV_150_250_0j_bb::STXSqqHll_pTV_150_250_0j_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_0j_bb called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_0j_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250_0j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250_0j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSqqHll_pTV_150_250_1j_bb::STXSqqHll_pTV_150_250_1j_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_150_250_1j_bb called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_150_250_1j_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_150_250_1j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_150_250_1j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSqqHll_pTV_250_bb::STXSqqHll_pTV_250_bb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSqqHll_pTV_250_bb called with a class whose parent is not NPbase");

}

double STXSqqHll_pTV_250_bb::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_qqHll_pTV_250(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_qqHll_pTV_250(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSWHqqHqq_VBFtopo_j3v_2b::STXSWHqqHqq_VBFtopo_j3v_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSWHqqHqq_VBFtopo_j3v_2b called with a class whose parent is not NPbase");

}

double STXSWHqqHqq_VBFtopo_j3v_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_WHqqHqq_VBFtopo_j3v(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_WHqqHqq_VBFtopo_j3v(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSWHqqHqq_VBFtopo_j3_2b::STXSWHqqHqq_VBFtopo_j3_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSWHqqHqq_VBFtopo_j3_2b called with a class whose parent is not NPbase");

}

double STXSWHqqHqq_VBFtopo_j3_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_WHqqHqq_VBFtopo_j3(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_WHqqHqq_VBFtopo_j3(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSWHqqHqq_VH2j_2b::STXSWHqqHqq_VH2j_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSWHqqHqq_VH2j_2b called with a class whose parent is not NPbase");

}

double STXSWHqqHqq_VH2j_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_WHqqHqq_VH2j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_WHqqHqq_VH2j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSWHqqHqq_Rest_2b::STXSWHqqHqq_Rest_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSWHqqHqq_Rest_2b called with a class whose parent is not NPbase");

}

double STXSWHqqHqq_Rest_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_WHqqHqq_Rest(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_WHqqHqq_Rest(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSWHqqHqq_pTj1_200_2b::STXSWHqqHqq_pTj1_200_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSWHqqHqq_pTj1_200_2b called with a class whose parent is not NPbase");

}

double STXSWHqqHqq_pTj1_200_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_WHqqHqq_pTj1_200(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_WHqqHqq_pTj1_200(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSZHqqHqq_VBFtopo_j3v_2b::STXSZHqqHqq_VBFtopo_j3v_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSZHqqHqq_VBFtopo_j3v_2b called with a class whose parent is not NPbase");

}

double STXSZHqqHqq_VBFtopo_j3v_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ZHqqHqq_VBFtopo_j3v(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ZHqqHqq_VBFtopo_j3v(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSZHqqHqq_VBFtopo_j3_2b::STXSZHqqHqq_VBFtopo_j3_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSZHqqHqq_VBFtopo_j3_2b called with a class whose parent is not NPbase");

}

double STXSZHqqHqq_VBFtopo_j3_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ZHqqHqq_VBFtopo_j3(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ZHqqHqq_VBFtopo_j3(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSZHqqHqq_VH2j_2b::STXSZHqqHqq_VH2j_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSZHqqHqq_VH2j_2b called with a class whose parent is not NPbase");

}

double STXSZHqqHqq_VH2j_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ZHqqHqq_VH2j(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ZHqqHqq_VH2j(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSZHqqHqq_Rest_2b::STXSZHqqHqq_Rest_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSZHqqHqq_Rest_2b called with a class whose parent is not NPbase");

}

double STXSZHqqHqq_Rest_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ZHqqHqq_Rest(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ZHqqHqq_Rest(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}


STXSZHqqHqq_pTj1_200_2b::STXSZHqqHqq_pTj1_200_2b(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("STXSZHqqHqq_pTj1_200_2b called with a class whose parent is not NPbase");

}

double STXSZHqqHqq_pTj1_200_2b::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return ((myNPbase->STXS_ZHqqHqq_pTj1_200(sqrt_s)) + (myNPbase->BrHbbRatio()) - 1.0);
    } else {
        return (myNPbase->STXS_ZHqqHqq_pTj1_200(sqrt_s))*(myNPbase->BrHbbRatio());
    }
}



//-----------------------------------------------------------------------------------------
//-- Special Hadron collider signal strengths with separate full TH unc U(prod x decay) ---
//-----------------------------------------------------------------------------------------


muTHUggHgaga::muTHUggHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHgaga called with a class whose parent is not NPbase");
}

double muTHUggHgaga::computeThValue()
{
        return myNPbase->muTHUggHgaga(sqrt_s);
}


muTHUVBFHgaga::muTHUVBFHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHgaga called with a class whose parent is not NPbase");
}

double muTHUVBFHgaga::computeThValue()
{
        return myNPbase->muTHUVBFHgaga(sqrt_s);
}

muTHUZHgaga::muTHUZHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHgaga called with a class whose parent is not NPbase");
}

double muTHUZHgaga::computeThValue()
{
        return myNPbase->muTHUZHgaga(sqrt_s);
}

muTHUWHgaga::muTHUWHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHgaga called with a class whose parent is not NPbase");
}

double muTHUWHgaga::computeThValue()
{
        return myNPbase->muTHUWHgaga(sqrt_s);
}

muTHUVHgaga::muTHUVHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHgaga called with a class whose parent is not NPbase");
}

double muTHUVHgaga::computeThValue()
{
        return myNPbase->muTHUVHgaga(sqrt_s);
}

muTHUttHgaga::muTHUttHgaga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHgaga called with a class whose parent is not NPbase");
}

double muTHUttHgaga::computeThValue()
{
        return myNPbase->muTHUttHgaga(sqrt_s);
}

muTHUggHZga::muTHUggHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHZga called with a class whose parent is not NPbase");
}

double muTHUggHZga::computeThValue()
{
        return myNPbase->muTHUggHZga(sqrt_s);
}

muTHUggHZgamumu::muTHUggHZgamumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHZgamumu called with a class whose parent is not NPbase");
}

double muTHUggHZgamumu::computeThValue()
{
        return (myNPbase->muTHUggHZgamumu(sqrt_s));
}

muTHUVBFHZga::muTHUVBFHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHZga called with a class whose parent is not NPbase");
}

double muTHUVBFHZga::computeThValue()
{

        return myNPbase->muTHUVBFHZga(sqrt_s);
}

muTHUZHZga::muTHUZHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHZga called with a class whose parent is not NPbase");
}

double muTHUZHZga::computeThValue()
{
        return myNPbase->muTHUZHZga(sqrt_s);
}

muTHUWHZga::muTHUWHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHZga called with a class whose parent is not NPbase");
}

double muTHUWHZga::computeThValue()
{
        return myNPbase->muTHUWHZga(sqrt_s);
}

muTHUVHZga::muTHUVHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHZga called with a class whose parent is not NPbase");
}

double muTHUVHZga::computeThValue()
{
        return myNPbase->muTHUVHZga(sqrt_s);
}

muTHUttHZga::muTHUttHZga(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHZga called with a class whose parent is not NPbase");
}

double muTHUttHZga::computeThValue()
{
        return myNPbase->muTHUttHZga(sqrt_s);
}

muTHUggHZZ::muTHUggHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHZZ called with a class whose parent is not NPbase");
}

double muTHUggHZZ::computeThValue()
{
        return myNPbase->muTHUggHZZ(sqrt_s);
}

muTHUVBFHZZ::muTHUVBFHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHZZ called with a class whose parent is not NPbase");
}

double muTHUVBFHZZ::computeThValue()
{
        return myNPbase->muTHUVBFHZZ(sqrt_s);
}

muTHUZHZZ::muTHUZHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHZZ called with a class whose parent is not NPbase");
}

double muTHUZHZZ::computeThValue()
{
        return myNPbase->muTHUZHZZ(sqrt_s);
}

muTHUWHZZ::muTHUWHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHZZ called with a class whose parent is not NPbase");
}

double muTHUWHZZ::computeThValue()
{
        return myNPbase->muTHUWHZZ(sqrt_s);
}

muTHUVHZZ::muTHUVHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHZZ called with a class whose parent is not NPbase");
}

double muTHUVHZZ::computeThValue()
{
        return myNPbase->muTHUVHZZ(sqrt_s);
}

muTHUttHZZ::muTHUttHZZ(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHZZ called with a class whose parent is not NPbase");
}

double muTHUttHZZ::computeThValue()
{
        return myNPbase->muTHUttHZZ(sqrt_s);
}

muTHUggHZZ4l::muTHUggHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHZZ4l called with a class whose parent is not NPbase");
}

double muTHUggHZZ4l::computeThValue()
{
        return myNPbase->muTHUggHZZ4l(sqrt_s);
}

muTHUggHZZ4mu::muTHUggHZZ4mu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHZZ4mu called with a class whose parent is not NPbase");
}

double muTHUggHZZ4mu::computeThValue()
{
        return (myNPbase->muTHUggHZZ4mu(sqrt_s));
}

muTHUVBFHZZ4l::muTHUVBFHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHZZ4l called with a class whose parent is not NPbase");
}

double muTHUVBFHZZ4l::computeThValue()
{
        return myNPbase->muTHUVBFHZZ4l(sqrt_s);
}

muTHUZHZZ4l::muTHUZHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHZZ4l called with a class whose parent is not NPbase");
}

double muTHUZHZZ4l::computeThValue()
{
        return myNPbase->muTHUZHZZ4l(sqrt_s);
}

muTHUWHZZ4l::muTHUWHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHZZ4l called with a class whose parent is not NPbase");
}

double muTHUWHZZ4l::computeThValue()
{
        return myNPbase->muTHUWHZZ4l(sqrt_s);
}

muTHUVHZZ4l::muTHUVHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHZZ4l called with a class whose parent is not NPbase");
}

double muTHUVHZZ4l::computeThValue()
{
        return myNPbase->muTHUVHZZ4l(sqrt_s);
}

muTHUttHZZ4l::muTHUttHZZ4l(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHZZ4l called with a class whose parent is not NPbase");
}

double muTHUttHZZ4l::computeThValue()
{
        return myNPbase->muTHUttHZZ4l(sqrt_s);
}

muTHUggHWW::muTHUggHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHWW called with a class whose parent is not NPbase");
}

double muTHUggHWW::computeThValue()
{
        return myNPbase->muTHUggHWW(sqrt_s);
}

muTHUVBFHWW::muTHUVBFHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHWW called with a class whose parent is not NPbase");
}

double muTHUVBFHWW::computeThValue()
{
        return myNPbase->muTHUVBFHWW(sqrt_s);
}

muTHUZHWW::muTHUZHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHWW called with a class whose parent is not NPbase");
}

double muTHUZHWW::computeThValue()
{
        return myNPbase->muTHUZHWW(sqrt_s);
}

muTHUWHWW::muTHUWHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHWW called with a class whose parent is not NPbase");
}

double muTHUWHWW::computeThValue()
{
        return myNPbase->muTHUWHWW(sqrt_s);
}

muTHUVHWW::muTHUVHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHWW called with a class whose parent is not NPbase");
}

double muTHUVHWW::computeThValue()
{
        return myNPbase->muTHUVHWW(sqrt_s);
}

muTHUttHWW::muTHUttHWW(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHWW called with a class whose parent is not NPbase");
}

double muTHUttHWW::computeThValue()
{
        return myNPbase->muTHUttHWW(sqrt_s);
}

muTHUggHWW2l2v::muTHUggHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUggHWW2l2v::computeThValue()
{
        return myNPbase->muTHUggHWW2l2v(sqrt_s);
}

muTHUVBFHWW2l2v::muTHUVBFHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUVBFHWW2l2v::computeThValue()
{
        return myNPbase->muTHUVBFHWW2l2v(sqrt_s);
}

muTHUZHWW2l2v::muTHUZHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUZHWW2l2v::computeThValue()
{
        return myNPbase->muTHUZHWW2l2v(sqrt_s);
}

muTHUWHWW2l2v::muTHUWHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUWHWW2l2v::computeThValue()
{
        return myNPbase->muTHUWHWW2l2v(sqrt_s);
}

muTHUVHWW2l2v::muTHUVHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUVHWW2l2v::computeThValue()
{
        return myNPbase->muTHUVHWW2l2v(sqrt_s);
}

muTHUttHWW2l2v::muTHUttHWW2l2v(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHWW2l2v called with a class whose parent is not NPbase");
}

double muTHUttHWW2l2v::computeThValue()
{
        return myNPbase->muTHUttHWW2l2v(sqrt_s);
}

muTHUggHmumu::muTHUggHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHmumu called with a class whose parent is not NPbase");
}

double muTHUggHmumu::computeThValue()
{
        return myNPbase->muTHUggHmumu(sqrt_s);
}

muTHUVBFHmumu::muTHUVBFHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHmumu called with a class whose parent is not NPbase");
}

double muTHUVBFHmumu::computeThValue()
{
        return myNPbase->muTHUVBFHmumu(sqrt_s);
}

muTHUZHmumu::muTHUZHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHmumu called with a class whose parent is not NPbase");
}

double muTHUZHmumu::computeThValue()
{
        return myNPbase->muTHUZHmumu(sqrt_s);
}

muTHUWHmumu::muTHUWHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHmumu called with a class whose parent is not NPbase");
}

double muTHUWHmumu::computeThValue()
{
        return myNPbase->muTHUWHmumu(sqrt_s);
}

muTHUVHmumu::muTHUVHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHmumu called with a class whose parent is not NPbase");
}

double muTHUVHmumu::computeThValue()
{
        return myNPbase->muTHUVHmumu(sqrt_s);
}

muTHUttHmumu::muTHUttHmumu(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHmumu called with a class whose parent is not NPbase");
}

double muTHUttHmumu::computeThValue()
{
        return myNPbase->muTHUttHmumu(sqrt_s);
}

muTHUggHtautau::muTHUggHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHtautau called with a class whose parent is not NPbase");
}

double muTHUggHtautau::computeThValue()
{
        return myNPbase->muTHUggHtautau(sqrt_s);
}

muTHUVBFHtautau::muTHUVBFHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHtautau called with a class whose parent is not NPbase");
}

double muTHUVBFHtautau::computeThValue()
{
        return myNPbase->muTHUVBFHtautau(sqrt_s);
}

muTHUZHtautau::muTHUZHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHtautau called with a class whose parent is not NPbase");
}

double muTHUZHtautau::computeThValue()
{
        return myNPbase->muTHUZHtautau(sqrt_s);
}

muTHUWHtautau::muTHUWHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHtautau called with a class whose parent is not NPbase");
}

double muTHUWHtautau::computeThValue()
{
        return myNPbase->muTHUWHtautau(sqrt_s);
}

muTHUVHtautau::muTHUVHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHtautau called with a class whose parent is not NPbase");
}

double muTHUVHtautau::computeThValue()
{
        return myNPbase->muTHUVHtautau(sqrt_s);
}

muTHUttHtautau::muTHUttHtautau(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHtautau called with a class whose parent is not NPbase");
}

double muTHUttHtautau::computeThValue()
{
        return myNPbase->muTHUttHtautau(sqrt_s);
}

muTHUggHbb::muTHUggHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUggHbb called with a class whose parent is not NPbase");
}

double muTHUggHbb::computeThValue()
{
        return myNPbase->muTHUggHbb(sqrt_s);
}

muTHUVBFHbb::muTHUVBFHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHbb called with a class whose parent is not NPbase");
}

double muTHUVBFHbb::computeThValue()
{
        return myNPbase->muTHUVBFHbb(sqrt_s);
}

muTHUZHbb::muTHUZHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUZHbb called with a class whose parent is not NPbase");
}

double muTHUZHbb::computeThValue()
{
        return myNPbase->muTHUZHbb(sqrt_s);
}

muTHUWHbb::muTHUWHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUWHbb called with a class whose parent is not NPbase");
}

double muTHUWHbb::computeThValue()
{
        return myNPbase->muTHUWHbb(sqrt_s);
}

muTHUVHbb::muTHUVHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHbb called with a class whose parent is not NPbase");
}

double muTHUVHbb::computeThValue()
{
        return myNPbase->muTHUVHbb(sqrt_s);
}

muTHUttHbb::muTHUttHbb(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUttHbb called with a class whose parent is not NPbase");
}

double muTHUttHbb::computeThValue()
{
        return myNPbase->muTHUttHbb(sqrt_s);
}


muTHUVBFBRinv::muTHUVBFBRinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFBRinv called with a class whose parent is not NPbase");
}

double muTHUVBFBRinv::computeThValue()
{

    return (myNPbase->muTHUVBFBRinv(sqrt_s));

}

muTHUVBFHinv::muTHUVBFHinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVBFHinv called with a class whose parent is not NPbase");
}

double muTHUVBFHinv::computeThValue()
{

        return (myNPbase->muTHUVBFHinv(sqrt_s));

}


muTHUVHBRinv::muTHUVHBRinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHBRinv called with a class whose parent is not NPbase");
}

double muTHUVHBRinv::computeThValue()
{

    return (myNPbase->muTHUVHBRinv(sqrt_s));

}

muTHUVHinv::muTHUVHinv(const StandardModel& SM_i, const double sqrt_s_i)
: ThObservable(SM_i), sqrt_s(sqrt_s_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("muTHUVHinv called with a class whose parent is not NPbase");
}

double muTHUVHinv::computeThValue()
{
        return (myNPbase->muTHUVHinv(sqrt_s));
}


BrHto2l2v_over_gaga_Ratio::BrHto2l2v_over_gaga_Ratio(const StandardModel& SM_i) : ThObservable(SM_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("BrHto2l2v_over_gaga_Ratio called with a class whose parent is not NPbase");
}

double BrHto2l2v_over_gaga_Ratio::computeThValue()
{
    if ((this->getModel()).isModelLinearized()) {
        return (1.0 + (myNPbase->BrHWW2l2vRatio()) - (myNPbase->BrHgagaRatio()));
    } else {
        return (myNPbase->BrHWW2l2vRatio()) / (myNPbase->BrHgagaRatio());
    }
}