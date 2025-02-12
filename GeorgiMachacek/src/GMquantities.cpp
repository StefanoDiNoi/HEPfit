/* 
 * Copyright (C) 2017 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "GMquantities.h"
#include "GMcache.h"
#include "GeorgiMachacek.h"

tanbetaGM::tanbetaGM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double tanbetaGM::computeThValue()
{
    return myGM.getMyGMCache()->tanb;
}



m1sqGM::m1sqGM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double m1sqGM::computeThValue()
{
    double vPhi = myGM.getMyGMCache()->vPhi;
    double vDelta = myGM.getvDelta();
    double lambda1 = myGM.getMyGMCache()->lambda1;
    double lambda4 = myGM.getMyGMCache()->lambda4;
    double lambda5 = myGM.getMyGMCache()->lambda5;
    double Mu1 = myGM.getMu1();
    return -4.0*lambda1*vPhi*vPhi-(6.0*lambda4+3.0*lambda5)*vDelta*vDelta-1.5*Mu1*vDelta;
}



m2sqGM::m2sqGM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double m2sqGM::computeThValue()
{
    double vPhi = myGM.getMyGMCache()->vPhi;
    double vDelta = myGM.getvDelta();
    double lambda2 = myGM.getMyGMCache()->lambda2;
    double lambda3 = myGM.getMyGMCache()->lambda3;
    double lambda4 = myGM.getMyGMCache()->lambda4;
    double lambda5 = myGM.getMyGMCache()->lambda5;
    double Mu1 = myGM.getMu1();
    double Mu2 = myGM.getMu2();
    return -(12.0*lambda2+4.0*lambda3)*vDelta*vDelta-(2.0*lambda4+lambda5)*vPhi*vPhi-0.25*Mu1*vPhi*vPhi/vDelta-6.0*Mu2*vDelta;
}



lambda1GM::lambda1GM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double lambda1GM::computeThValue()
{
    return myGM.getMyGMCache()->lambda1;
}



lambda2GM::lambda2GM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double lambda2GM::computeThValue()
{
    return myGM.getMyGMCache()->lambda2;
}



lambda3GM::lambda3GM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double lambda3GM::computeThValue()
{
    return myGM.getMyGMCache()->lambda3;
}



lambda4GM::lambda4GM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double lambda4GM::computeThValue()
{
    return myGM.getMyGMCache()->lambda4;
}



lambda5GM::lambda5GM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double lambda5GM::computeThValue()
{
    return myGM.getMyGMCache()->lambda5;
}



vPhiGM::vPhiGM(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double vPhiGM::computeThValue()
{
    return myGM.getMyGMCache()->vPhi;
}



//vDeltaGM::vDeltaGM(const StandardModel& SM_i)
//: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
//{}
//
//double vDeltaGM::computeThValue()
//{
//    return myGM.getMyGMCache()->vDelta;
//}



rh_gaga_GM::rh_gaga_GM(const StandardModel& SM_i)
: ThObservable(SM_i),myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double rh_gaga_GM::computeThValue()
{
    return myGM.getMyGMCache()->rh_gaga;
}



rh_Zga_GM::rh_Zga_GM(const StandardModel& SM_i)
: ThObservable(SM_i),myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double rh_Zga_GM::computeThValue()
{
    return myGM.getMyGMCache()->rh_Zga;
}



GMmassdifference_mHlmmHh::GMmassdifference_mHlmmHh(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHlmmHh::computeThValue()
{
    return sqrt(myGM->getmHl2()) - myGM->getmHh();
}



GMmass_mHh::GMmass_mHh(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmass_mHh::computeThValue()
{
    return myGM->getmHh();
}



GMmass_mA::GMmass_mA(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmass_mA::computeThValue()
{
    return myGM->getmA();
}



GMmass_mH5::GMmass_mH5(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmass_mH5::computeThValue()
{
    return myGM->getmH5();
}



GMmassdifference_mHhmmHl::GMmassdifference_mHhmmHl(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHhmmHl::computeThValue()
{
    return myGM->getmHh() - sqrt(myGM->getmHl2());
}



GMmassdifference_mHlmmA::GMmassdifference_mHlmmA(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHlmmA::computeThValue()
{
    return sqrt(myGM->getmHl2()) - myGM->getmA();
}



GMmassdifference_mAmmHl::GMmassdifference_mAmmHl(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mAmmHl::computeThValue()
{
    return myGM->getmA() - sqrt(myGM->getmHl2());
}



GMmassdifference_mHlmmH5::GMmassdifference_mHlmmH5(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHlmmH5::computeThValue()
{
    return sqrt(myGM->getmHl2()) - myGM->getmH5();
}



GMmassdifference_mH5mmHl::GMmassdifference_mH5mmHl(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mH5mmHl::computeThValue()
{
    return myGM->getmH5() - sqrt(myGM->getmHl2());
}



GMmassdifference_mHhmmA::GMmassdifference_mHhmmA(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHhmmA::computeThValue()
{
    return myGM->getmHh() - myGM->getmA();
}



GMmassdifference_mAmmHh::GMmassdifference_mAmmHh(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mAmmHh::computeThValue()
{
    return myGM->getmA() - myGM->getmHh();
}



GMmassdifference_mHhmmH5::GMmassdifference_mHhmmH5(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mHhmmH5::computeThValue()
{
    return myGM->getmHh() - myGM->getmH5();
}



GMmassdifference_mH5mmHh::GMmassdifference_mH5mmHh(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mH5mmHh::computeThValue()
{
    return myGM->getmH5() - myGM->getmHh();
}



GMmassdifference_mAmmH5::GMmassdifference_mAmmH5(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mAmmH5::computeThValue()
{
    return myGM->getmA() - myGM->getmH5();
}



GMmassdifference_mH5mmA::GMmassdifference_mH5mmA(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek*> (&SM_i))
{}

double GMmassdifference_mH5mmA::computeThValue()
{
    return myGM->getmH5() - myGM->getmA();
}



GMGammah::GMGammah(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammah::computeThValue()
{
    return myGM.getMyGMCache()->Gamma_h;
}



GMGammaH1::GMGammaH1(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH1::computeThValue()
{
    return myGM.getMyGMCache()->GammaH1tot;
}



GMGammaH3::GMGammaH3(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH3::computeThValue()
{
    return myGM.getMyGMCache()->GammaH3tot;
}



GMGammaH3p::GMGammaH3p(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH3p::computeThValue()
{
    return myGM.getMyGMCache()->GammaH3ptot;
}



GMGammaH5::GMGammaH5(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH5::computeThValue()
{
    return myGM.getMyGMCache()->GammaH5tot;
}



GMGammaH5p::GMGammaH5p(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH5p::computeThValue()
{
    return myGM.getMyGMCache()->GammaH5ptot;
}



GMGammaH5pp::GMGammaH5pp(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMGammaH5pp::computeThValue()
{
    return myGM.getMyGMCache()->GammaH5pptot;
}



GMghhh::GMghhh(const StandardModel& SM_i)
: ThObservable(SM_i), myGM(static_cast<const GeorgiMachacek&> (SM_i))
{}

double GMghhh::computeThValue()
{
    return myGM.getMyGMCache()->ghhh;
}
