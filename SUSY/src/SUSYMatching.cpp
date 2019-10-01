/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "SUSYMatching.h"
#include "SUSY.h"
//#include <math.h>
#include <gsl/gsl_integration.h>
#include <stdexcept>

SUSYMatching::SUSYMatching(const SUSY & SUSY_i) :

    StandardModelMatching(SUSY_i),
    mySUSY(SUSY_i),
    Polylogs(),
    PV(true),
        
    mcDLij(2, NDR, LO),
    mcDLi3j(20, NDR, LO),
    mcmueconv(8, NDR, LO),
    mcgminus2mu(2, NDR, LO),
        
    mym_su_sq(6, 0.),
    mym_sd_sq(6, 0.),
    mym_se_sq(6, 0.),
    mym_sn_sq(6, 0.),
    myRu(6, 6, 0.),
    myRd(6, 6, 0.),
    myRl(6, 6, 0.),
    myRn(6, 6, 0.),
    MChi(2, 0.),
    myV(2, 2, 0.),
    myU(2, 2, 0.),
    MChi0(4, 0.),
    MNeig(4, 0.),
    myN(4, 4, 0.),
    ON(4, 4, 0.),

    Lepty(4, 6, 0.),
    Leptz(2, 3, 0.),
    Leptfa1(4, 6, 0.),
    Leptfa2(2, 3, 0.),
    Leptf1(4, 6, 0.),
    Leptf2(4, 6, 0.),
    Leptf3(2, 3, 0.),
    Leptf4(2, 3, 0.),
    CRlE(2, 3, 0.),
    CRlMU(2, 3, 0.),
    CRlTAU(2, 3, 0.),
    CRqUP(2, 6, 0.),
    CRqDOWN(2, 6, 0.),
    CLlE(2, 3, 0.),
    CLlMU(2, 3, 0.),
    CLlTAU(2, 3, 0.),
    CLqUP(2, 6, 0.),
    CLqDOWN(2, 6, 0.),
    NRlE(4, 6, 0.),
    NRlMU(4, 6, 0.),
    NRlTAU(4, 6, 0.),
    NRqUP(4, 6, 0.),
    NRqDOWN(4, 6, 0.),
    NLlE(4, 6, 0.),
    NLlMU(4, 6, 0.),
    NLlTAU(4, 6, 0.),
    NLqUP(4, 6, 0.),
    NLqDOWN(4, 6, 0.),
    AmpA1LN(4, 6, 0.),
    AmpA1RN(4, 6, 0.),
    AmpA1LC(2, 3, 0.),
    AmpA1RC(2, 3, 0.),
    AmpTauA1LN(4, 6, 0.),
    AmpTauA1RN(4, 6, 0.),
    AmpTauA1LC(2, 3, 0.),
    AmpTauA1RC(2, 3, 0.),
    AmpTEA1LN(4, 6, 0.),
    AmpTEA1RN(4, 6, 0.),
    AmpTEA1LC(2, 3, 0.),
    AmpTEA1RC(2, 3, 0.),
    AmpALN(4, 6, 0.),
    AmpARN(4, 6, 0.),
    AmpALC(2, 3, 0.),
    AmpARC(2, 3, 0.),
    AmpTauALN(4, 6, 0.),
    AmpTauARN(4, 6, 0.),
    AmpTauALC(2, 3, 0.),
    AmpTauARC(2, 3, 0.),
    AmpTEALN(4, 6, 0.),
    AmpTEARN(4, 6, 0.),
    AmpTEALC(2, 3, 0.),
    AmpTEARC(2, 3, 0.),
    TUhat(3, 3, 0.),
    TDhat(3, 3, 0.),
    TEhat(3, 3, 0.),
        
    upQmassM(3,3,0.),
    downQmassM(3,3,0.),
    mySUSYMQ(6, 0.)

{
}


void SUSYMatching::updateSUSYParameters()
{
    myRu = mySUSY.getRu();
    myRd = mySUSY.getRd();
    myRl = mySUSY.getRl();
    myRn = mySUSY.getRn();
    mym_su_sq = mySUSY.getMsu2();
    mym_sd_sq = mySUSY.getMsd2();
    mym_sn_sq = mySUSY.getMsn2();
    mym_se_sq = mySUSY.getMse2();
    Q_S = mySUSY.getQ_SUSY();
    mu2R = Q_S * Q_S;
    tanb = mySUSY.getTanb();
    sinb = mySUSY.getSinb();
    cosb = mySUSY.getCosb();
    Als = mySUSY.Als(Q_S);
    Mg = mySUSY.getMGl();
    MChi0 = mySUSY.getMneu();
    MChi = mySUSY.getMch();
    MHpm = mySUSY.getMHp();
    v = mySUSY.v();
    v1 = mySUSY.v1();
    v2 = mySUSY.v2();
    gW = sqrt(8. * mySUSY.getGF() / sqrt(2.)) * mySUSY.Mw_tree();
    myN = mySUSY.getN();
    myV = mySUSY.getV();
    myU = mySUSY.getU();
    
    mW = mySUSY.Mw_tree();
    sinthetaW = sqrt(mySUSY.StandardModel::sW2(mW));

    upQmassM.assign(0,0,mySUSY.Mq_Q(mySUSY.UP));
    upQmassM.assign(1,1,mySUSY.Mq_Q(mySUSY.CHARM));
    upQmassM.assign(2,2,mySUSY.Mq_Q(mySUSY.TOP));

    downQmassM.assign(0,0,mySUSY.Mq_Q(mySUSY.DOWN));
    downQmassM.assign(1,1,mySUSY.Mq_Q(mySUSY.STRANGE));
    downQmassM.assign(2,2,mySUSY.Mq_Q(mySUSY.BOTTOM));

}

/* LEPTON FLAVOUR */

void SUSYMatching::NeutralinoRemixing() {

    gslpp::matrix<gslpp::complex> MN_tmp(4, 4, 0.);
    gslpp::matrix<gslpp::complex> Mdiag(4, 4, 0.);
    for (int a=0;a<4;a++) {
        Mdiag.assign(a,a,MChi0(a));
    }
    MN_tmp = myN.transpose() * Mdiag * myN;
    gslpp::matrix<gslpp::complex> cmplxONT(4, 4, 0.);
    MN_tmp.eigensystem(cmplxONT, MNeig);
    for (int a=0;a<4;a++) {
        for (int b=0;b<4;b++) {
            ON.assign(a,b,cmplxONT(b,a).real());
        }
    }
}

    gslpp::vector<gslpp::complex> SUSYMatching::AFunctions(int li_to_lj) {
        //gamma penguin contributions

    NeutralinoRemixing();

    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double piconst = 1.0/(32.0 * pi * pi);
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mTAU = mySUSY.getLeptons(StandardModel::TAU).getMass();
    sinb = mySUSY.getSinb();
    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);

    gslpp::vector<gslpp::complex> AFunctions(4, 0.);

    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlE.assign(a, x, - (g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 0) + (mE/cdenn)*ON(a, 2)*myRl(x, 3)));
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            NRlTAU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 2) + (mTAU/cdenn)*ON(a, 2)*myRl(x, 5)));
            //     RL + RR TYPE MI
            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2)*myRl(x, 0) + 2.0*ON(a, 0)*ttw*myRl(x, 3)));
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2)*myRl(x, 2) + 2.0*ON(a, 0)*ttw*myRl(x, 5)));
//    Commented expressions might be useful for complex neutralino mixing matrices
//            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2).conjugate()*myRl(x, 0) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 3)));
//            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2).conjugate()*myRl(x, 1) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 4)));
//            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2).conjugate()*myRl(x, 2) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 5)));
        }
    }

    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlE.assign(a, x, - (g2*myV(a, 0)*myRn(x, 0)));
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            CRlTAU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 2)));
            //     LR-TYPE
            CLlE.assign(a, x, g2*mE/cdenc*myU(a, 1).conjugate()*myRn(x, 0));
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
            CLlTAU.assign(a, x, g2*mTAU/cdenc*myU(a, 1).conjugate()*myRn(x, 2));
        }
    }

    //     Definition of y and z - remember they are dimensionless quantities.
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            Lepty.assign(a, x, MNeig(a) * MNeig(a) / mym_se_sq(x) );
        }
    }

    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            Leptz.assign(a, x, MChi(a) * MChi(a) / mym_sn_sq(x) );
        }
    }

    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            if (fabs(1.0 - Lepty(a, x)) > 0.01) {
                Leptfa1.assign(a, x, (1.0/mym_se_sq(x))*(1.0/pow((1.0 - Lepty(a, x)),4.0))*
                                (2.0 - 9.0*Lepty(a, x) + 18.0*pow(Lepty(a, x),2.0) - 11.0*pow(Lepty(a, x),3.0)
                                + 6.0*pow(Lepty(a, x),3.0)*log(Lepty(a, x))) );
                Leptf1.assign(a, x, ((1.0 - 6.0*Lepty(a, x) + 3.0 * pow(Lepty(a, x),2.0) + 
                                      2.0*pow(Lepty(a, x),3.0) - 6.0*pow(Lepty(a,x),2.0)*log(Lepty(a, x))))/
                                    (6.0 * pow((1.0 - Lepty(a,x)),4.0)) );
                Leptf2.assign(a, x, (1.0 - pow(Lepty(a, x),2.0) +  2.0 * Lepty(a, x) * log(Lepty(a, x)))/
                                    (pow((1.0-Lepty(a, x)),3.0)));
            }
            else {
                Leptfa1.assign(a, x, (3.0/2.0)*(1.0/mym_se_sq(x)));
                Leptf1.assign(a, x, 1.0/12.0 - (Lepty(a, x) - 1.0)/30.0);
                Leptf2.assign(a, x, 1.0/3.0 - (Lepty(a, x) - 1.0)/6.0);
            }
        }
    }

    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            if(fabs(1.0-Leptz(a, x)) > 0.01) {
                Leptfa2.assign(a, x, (1.0/mym_sn_sq(x))*(1.0/pow(1.0 - Leptz(a,x),4.0))*
                                (16.0 - 45.0*Leptz(a,x) + 36.0*pow(Leptz(a,x),2.0) - 7.0*pow(Leptz(a,x),3.0)
                                + 6.0*(2.0 - 3.0*Leptz(a,x))*log(Leptz(a,x))) );
                Leptf3.assign(a, x, ((2.0 + 3.0*Leptz(a, x) - 6.0*pow(Leptz(a, x),2.0) 
                                      + pow(Leptz(a, x),3.0) + 6.0*Leptz(a, x)*log(Leptz(a, x)))/
		                     (6.0*pow((1.0 - Leptz(a, x)),4.0))) );
                Leptf4.assign(a, x, ((-3.0 + 4.0*Leptz(a, x) - pow(Leptz(a, x),2.0)
                                      - 2.0*log(Leptz(a, x)))/
                                     pow((1.0 - Leptz(a, x)),3.0)) );
            }
            else {
                Leptfa2.assign(a, x, (-9.0/2.0)*(1.0/mym_sn_sq(x)) );
                Leptf3.assign(a, x, 1.0/12.0 - (Leptz(a, x) - 1.0)/20.0 );
                Leptf4.assign(a, x, 2.0/3.0 - (Leptz(a, x) - 1.0)/2.0 );
            }
        }
    }

    if (li_to_lj == 1) // mu -> (3)e
    {
        //      Neutralino contributions
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                AmpA1RN.assign(a, x, (piconst/18.0)*NLlE(a,x)*NLlMU(a,x).conjugate()*Leptfa1(a,x) );
                AmpA1LN.assign(a, x, (piconst/18.0)*NRlE(a,x)*NRlMU(a,x).conjugate()*Leptfa1(a,x) );
                AmpARN.assign(a, x, piconst*(NRlE(a, x) * NRlMU(a, x).conjugate() * Leptf1(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                             + NLlE(a, x) * NLlMU(a, x).conjugate() * (mE/mMU) * Leptf1(a, x)
//...until here
                                             + NRlE(a, x) * NLlMU(a, x).conjugate() * (MNeig(a)/mMU) * Leptf2(a, x)) /mym_se_sq(x) );
                AmpALN.assign(a, x, piconst*(NLlE(a, x) * NLlMU(a, x).conjugate() * Leptf1(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                             + NRlE(a, x) * NRlMU(a, x).conjugate() * (mE/mMU) * Leptf1(a, x)
//...until here
                                             + NLlE(a, x) * NRlMU(a, x).conjugate() * (MNeig(a)/mMU) * Leptf2(a, x)) /mym_se_sq(x) );
            }
        }
        gslpp::complex A1RN = 0.0;
        gslpp::complex A1LN = 0.0;
        gslpp::complex ARN = 0.0;
        gslpp::complex ALN = 0.0;
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                A1RN = A1RN + AmpA1RN(a,x);
                A1LN = A1LN + AmpA1LN(a,x);
                ARN = ARN + AmpARN(a,x);
                ALN = ALN + AmpALN(a,x);
            }
        }
        //      Chargino contributions
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                AmpA1RC.assign(a, x, -(piconst/18.0)*CLlE(a,x)*CLlMU(a,x).conjugate()*Leptfa2(a,x) );
                AmpA1LC.assign(a, x, -(piconst/18.0)*CRlE(a,x)*CRlMU(a,x).conjugate()*Leptfa2(a,x) );
                AmpARC.assign(a, x, -(piconst/mym_sn_sq(x)) * (CRlE(a, x)*CRlMU(a, x).conjugate() * Leptf3(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                               + CLlE(a, x) * CLlMU(a, x).conjugate() * (mE/mMU) * Leptf3(a, x)
//...until here
                                                               + CRlE(a, x) * CLlMU(a, x).conjugate() * (MChi(a)/mMU) * Leptf4(a, x)) );
                AmpALC.assign(a, x, -(piconst/mym_sn_sq(x)) * (CLlE(a, x) * CLlMU(a, x).conjugate() * Leptf3(a, x) 
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                               + CRlE(a, x) * CRlMU(a, x).conjugate() * (mE/mMU) * Leptf3(a, x)
//...until here
                                                               + CLlE(a, x) * CRlMU(a, x).conjugate() * (MChi(a)/mMU) * Leptf4(a, x)) );
            }
        }
        gslpp::complex A1RC = 0.0;
        gslpp::complex A1LC = 0.0;
        gslpp::complex ARC = 0.0;
        gslpp::complex ALC = 0.0;
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                A1RC = A1RC + AmpA1RC(a,x);
                A1LC = A1LC + AmpA1LC(a,x);
                ARC = ARC + AmpARC(a,x);
                ALC = ALC + AmpALC(a,x);
            }
        }
        //     write AR and AL into a vector for mu->(3)e
        AFunctions.assign(0, A1RN + A1RC );
        AFunctions.assign(1, A1LN + A1LC );
        AFunctions.assign(2, ARN + ARC );
        AFunctions.assign(3, ALN + ALC );

    }

    if (li_to_lj == 2) // tau -> (3)mu
    {
        //      Neutralino contributions
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                AmpTauA1RN.assign(a, x, (piconst/18.0)*NLlMU(a,x)*NLlTAU(a,x).conjugate()*Leptfa1(a,x) );
                AmpTauA1LN.assign(a, x, (piconst/18.0)*NRlMU(a,x)*NRlTAU(a,x).conjugate()*Leptfa1(a,x) );
                AmpTauARN.assign(a, x, piconst * (NRlMU(a, x) * NRlTAU(a, x).conjugate() * Leptf1(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                  + NLlMU(a, x) * NLlTAU(a, x).conjugate() * (mMU/mTAU) * Leptf1(a, x)
//...until here
                                                  + NRlMU(a, x) * NLlTAU(a, x).conjugate() * (MNeig(a)/mTAU) * Leptf2(a, x)) /mym_se_sq(x) );
                AmpTauALN.assign(a, x, piconst * (NLlMU(a, x) * NLlTAU(a, x).conjugate() * Leptf1(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                  + NRlMU(a, x) * NRlTAU(a, x).conjugate() * (mMU/mTAU) * Leptf1(a, x)
//...until here
                                                  + NLlMU(a, x) * NRlTAU(a, x).conjugate() * (MNeig(a)/mTAU) * Leptf2(a, x)) /mym_se_sq(x) );
            }
        }
        gslpp::complex TauA1RN = 0.0;
        gslpp::complex TauA1LN = 0.0;
        gslpp::complex TauARN = 0.0;
        gslpp::complex TauALN = 0.0;
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                TauA1RN = TauA1RN + AmpTauA1RN(a,x);
                TauA1LN = TauA1LN + AmpTauA1LN(a,x);
                TauARN = TauARN + AmpTauARN(a,x);
                TauALN = TauALN + AmpTauALN(a,x);
            }
        }
        //      Chargino contributions
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                AmpTauA1RC.assign(a, x, -(piconst/18.0)*CLlMU(a,x)*CLlTAU(a,x).conjugate()*Leptfa2(a,x) );
                AmpTauA1LC.assign(a, x, -(piconst/18.0)*CRlMU(a,x)*CRlTAU(a,x).conjugate()*Leptfa2(a,x) );
                AmpTauARC.assign(a, x, -piconst / mym_sn_sq(x) * (CRlMU(a, x) * CRlTAU(a, x).conjugate() * Leptf3(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                                  + CLlMU(a, x) * CLlTAU(a, x).conjugate() * (mMU/mTAU) * Leptf3(a, x)
//...until here
                                                                  + CRlMU(a, x) * CLlTAU(a, x).conjugate() * (MChi(a)/mTAU) * Leptf4(a, x)) );
                AmpTauALC.assign(a, x, -piconst / mym_sn_sq(x) * (CLlMU(a, x) * CLlTAU(a, x).conjugate() * Leptf3(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                                  + CRlMU(a, x) * CRlTAU(a, x).conjugate() * (mMU/mTAU) * Leptf3(a, x)
//...until here
                                                                  + CLlMU(a, x) * CRlTAU(a, x).conjugate() * (MChi(a)/mTAU) * Leptf4(a, x)) );
            }
        }
        gslpp::complex TauA1RC = 0.0;
        gslpp::complex TauA1LC = 0.0;
        gslpp::complex TauARC = 0.0;
        gslpp::complex TauALC = 0.0;
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                TauA1RC = TauA1RC + AmpTauA1RC(a,x);
                TauA1LC = TauA1LC + AmpTauA1LC(a,x);
                TauARC = TauARC + AmpTauARC(a,x);
                TauALC = TauALC + AmpTauALC(a,x);
            }
        }
        //     write AR and AL into a vector for tau->(3)mu
        AFunctions.assign(0, TauA1RC + TauA1RN );
        AFunctions.assign(1, TauA1LC + TauA1LN );
        AFunctions.assign(2, TauARC + TauARN );
        AFunctions.assign(3, TauALC + TauALN );
    }

    if (li_to_lj == 3) // tau -> (3)e
    {
        //      Neutralino contributions
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                AmpTEA1RN.assign(a, x, (piconst/18.0)*NLlE(a,x)*NLlTAU(a,x).conjugate()*Leptfa1(a,x) );
                AmpTEA1LN.assign(a, x, (piconst/18.0)*NRlE(a,x)*NRlTAU(a,x).conjugate()*Leptfa1(a,x) );
                AmpTEARN.assign(a, x, piconst * (NRlE(a, x) * NRlTAU(a, x).conjugate() * Leptf1(a,x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                 + NLlE(a, x) * NLlTAU(a, x).conjugate() * (mE/mTAU) * Leptf1(a,x)
//...until here
                                                 + NRlE(a, x) * NLlTAU(a, x).conjugate() * (MNeig(a)/mTAU) * Leptf2(a, x)) / mym_se_sq(x) );
                AmpTEALN.assign(a, x, piconst * (NLlE(a, x) * NLlTAU(a, x).conjugate() * Leptf1(a, x) 
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                 + NRlE(a, x) * NRlTAU(a, x).conjugate() * (mE/mTAU) * Leptf1(a, x)
//...until here
                                                 + NLlE(a, x) * NRlTAU(a, x).conjugate() * (MNeig(a)/mTAU) * Leptf2(a, x)) / mym_se_sq(x) );
            }
        }
        gslpp::complex TEA1RN = 0.0;
        gslpp::complex TEA1LN = 0.0;
        gslpp::complex TEARN = 0.0;
        gslpp::complex TEALN = 0.0;
        for (int a=0;a<4;a++) {
            for (int x=0;x<6;x++) {
                TEA1RN = TEA1RN + AmpTEA1RN(a,x);
                TEA1LN = TEA1LN + AmpTEA1LN(a,x);
                TEARN = TEARN + AmpTEARN(a,x);
                TEALN = TEALN + AmpTEALN(a,x);
            }
        }
        //      Chargino contributions
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                AmpTEA1RC.assign(a, x, -(piconst/18.0)*CLlE(a,x)*CLlTAU(a,x).conjugate()*Leptfa2(a,x) );
                AmpTEA1LC.assign(a, x, -(piconst/18.0)*CRlE(a,x)*CRlTAU(a,x).conjugate()*Leptfa2(a,x) );
                AmpTEARC.assign(a, x, -piconst / mym_sn_sq(x) * (CRlE(a, x) * CRlTAU(a, x).conjugate() * Leptf3(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                                 + CLlE(a, x) * CLlTAU(a, x).conjugate() * (mE/mTAU) * Leptf3(a, x)
//...until here
                                                                 + CRlE(a, x) * CLlTAU(a, x).conjugate() *(MChi(a)/mTAU) * Leptf4(a, x)) );
                AmpTEALC.assign(a, x, -piconst / mym_sn_sq(x) * (CLlE(a, x) * CLlTAU(a, x).conjugate() * Leptf3(a, x)
// The following contribution is absent in PRD 53.2442 (Hisano et al.), but appears in PRD 73.055003 (Arganda & Herrero)...
                                                                 + CRlE(a, x) * CRlTAU(a, x).conjugate() * (mE/mTAU) * Leptf3(a, x)
//...until here
                                                                 + CLlE(a, x) * CRlTAU(a, x).conjugate() * (MChi(a)/mTAU) * Leptf4(a, x)) );
            }
        }
        gslpp::complex TEA1RC = 0.0;
        gslpp::complex TEA1LC = 0.0;
        gslpp::complex TEARC = 0.0;
        gslpp::complex TEALC = 0.0;
        for (int a=0;a<2;a++) {
            for (int x=0;x<3;x++) {
                TEA1RC = TEA1RC + AmpTEA1RC(a, x);
                TEA1LC = TEA1LC + AmpTEA1LC(a,x);
                TEARC = TEARC + AmpTEARC(a,x);
                TEALC = TEALC + AmpTEALC(a,x);
            }
        }
        //     write AR and AL into a vector for tau->(3)e
        AFunctions.assign(0, TEA1RC + TEA1RN );
        AFunctions.assign(1, TEA1LC + TEA1LN );
        AFunctions.assign(2, TEARC + TEARN );
        AFunctions.assign(3, TEALC + TEALN );

    }

    return(AFunctions);
}

gslpp::vector<gslpp::complex> SUSYMatching::BFunctions(int li_to_lj) {
        //box diagram contributions

    NeutralinoRemixing();

    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mTAU = mySUSY.getLeptons(StandardModel::TAU).getMass();

    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);
    double alph = mySUSY.getAle();

    gslpp::vector<gslpp::complex> BFunctions(8, 0.);

    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlE.assign(a, x, - (g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 0) + (mE/cdenn)*ON(a, 2)*myRl(x, 3)));
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            NRlTAU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 2) + (mTAU/cdenn)*ON(a, 2)*myRl(x, 5)));
            //     RL + RR TYPE MI
            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2)*myRl(x, 0) + 2.0*ON(a, 0)*ttw*myRl(x, 3)));
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2)*myRl(x, 2) + 2.0*ON(a, 0)*ttw*myRl(x, 5)));
//    Commented expressions might be useful for complex neutralino mixing matrices
//            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2).conjugate()*myRl(x, 0) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 3)));
//            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2).conjugate()*myRl(x, 1) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 4)));
//            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2).conjugate()*myRl(x, 2) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 5)));
        }
    }

    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlE.assign(a, x, - (g2*myV(a, 0)*myRn(x, 0)));
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            CRlTAU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 2)));
            //     LR-TYPE
            CLlE.assign(a, x, g2*mE/cdenc*myU(a, 1).conjugate()*myRn(x, 0));
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
            CLlTAU.assign(a, x, g2*mTAU/cdenc*myU(a, 1).conjugate()*myRn(x, 2));
        }
    }

    if (li_to_lj == 1) // mu -> 3e
    {
        //      Neutralino contributions
//    J4n(a,b,x,t)=/*J4n(a,b,x,t)*/
//                                                                    *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
//    I4n(a,b,x,t)=/*I4n(a,b,x,t)*/
//                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi)
        gslpp::complex B1nRMu3E = 0.0;
        gslpp::complex B2nRMu3E = 0.0;
        gslpp::complex B3nRMu3E = 0.0;
        gslpp::complex B4nRMu3E = 0.0;
        gslpp::complex B1nLMu3E = 0.0;
        gslpp::complex B2nLMu3E = 0.0;
        gslpp::complex B3nLMu3E = 0.0;
        gslpp::complex B4nLMu3E = 0.0;
        for (int a=0;a<4;a++) {
            for (int b=0;b<4;b++) {
                for (int x=0;x<6;x++) {
                    for (int t=0;t<6;t++) {
                        B1nRMu3E = B1nRMu3E + (1.0/(4.0*pi*alph))*(0.5*NLlMU(a,x)*NLlE(a,t)*NLlE(b,t)*NLlE(b,x)/*J4n(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                   +MNeig(a)*MNeig(b)*NLlMU(a,x)*NLlE(a,t)*NLlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nRMu3E = B2nRMu3E + (1.0/(4.0*pi*alph))*(0.25*(NLlMU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x)
                                                                         +NLlMU(a,x)*NRlE(a,t)*NLlE(b,t)*NRlE(b,x)
                                                                         -NLlMU(a,x)*NRlE(a,t)*NRlE(b,t)*NLlE(b,x))/*J4n(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                   -0.5*MNeig(a)*MNeig(b)*NLlMU(a,x)*NRlE(a,t)*NRlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nRMu3E = B3nRMu3E + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NLlMU(a,x)*NRlE(a,t)*NLlE(b,t)*NRlE(b,x)
                                                                                     +0.5*NLlMU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x))/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nRMu3E = B4nRMu3E + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NLlMU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B1nLMu3E = B1nLMu3E + (1.0/(4.0*pi*alph))*(0.5*NRlMU(a,x)*NRlE(a,t)*NRlE(b,t)*NRlE(b,x)/*J4n(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                   +MNeig(a)*MNeig(b)*NRlMU(a,x)*NRlE(a,t)*NRlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nLMu3E = B2nLMu3E + (1.0/(4.0*pi*alph))*(0.25*(NRlMU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x)
                                                                         +NRlMU(a,x)*NLlE(a,t)*NRlE(b,t)*NLlE(b,x)
                                                                         -NRlMU(a,x)*NLlE(a,t)*NLlE(b,t)*NRlE(b,x))/*J4n(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                   -0.5*MNeig(a)*MNeig(b)*NRlMU(a,x)*NLlE(a,t)*NLlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nLMu3E = B3nLMu3E + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NRlMU(a,x)*NLlE(a,t)*NRlE(b,t)*NLlE(b,x)
                                                                                     +0.5*NRlMU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x))/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nLMu3E = B4nLMu3E + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NRlMU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
        //      Chargino contributions
//    J4c(a,b,x,t)=/*J4c(a,b,x,t)*/
//                                                                    *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
//    I4c(a,b,x,t)=/*I4c(a,b,x,t)*/
//                                                                    *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi)
        gslpp::complex B1cRMu3E = 0.0;
        gslpp::complex B2cRMu3E = 0.0;
        gslpp::complex B3cRMu3E = 0.0;
        gslpp::complex B1cLMu3E = 0.0;
        gslpp::complex B2cLMu3E = 0.0;
        gslpp::complex B3cLMu3E = 0.0;
        for (int a=0;a<2;a++) {
            for (int b=0;b<2;b++) {
                for (int x=0;x<3;x++) {
                    for (int t=0;t<3;t++) {
                        B1cRMu3E = B1cRMu3E + (1.0/(8.0*pi*alph))*CLlMU(a,x)*CLlE(a,t)*CLlE(b,t)*CLlE(b,x)/*J4c(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi);
                        B2cRMu3E = B2cRMu3E + (1.0/(4.0*pi*alph))*(0.25*CLlMU(a,x)*CLlE(a,t)*CRlE(b,t)*CRlE(b,x)/*J4c(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                   -0.5*MChi(a)*MChi(b)*CLlMU(a,x)*CRlE(a,t)*CRlE(b,t)*CLlE(b,x)/*I4c(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cRMu3E = B3cRMu3E + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CLlMU(a,x)*CRlE(a,t)*CLlE(b,t)*CRlE(b,x)/*I4c(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                        B1cLMu3E = B1cLMu3E + (1.0/(8.0*pi*alph))*(CRlMU(a,x)*CRlE(a,t)*CRlE(b,t)*CRlE(b,x)/*J4c(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi));
                        B2cLMu3E = B2cLMu3E + (1.0/(4.0*pi*alph))*(0.25*CRlMU(a,x)*CRlE(a,t)*CLlE(b,t)*CLlE(b,x)/*J4c(a,b,x,t)*/
                                                                    *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                   -0.5*MChi(a)*MChi(b)*CRlMU(a,x)*CLlE(a,t)*CLlE(b,t)*CRlE(b,x)/*I4c(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cLMu3E = B3cLMu3E + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CRlMU(a,x)*CLlE(a,t)*CRlE(b,t)*CLlE(b,x)/*I4c(a,b,x,t)*/
                                                                    *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
                
//     write BR and BL into a vector for mu->3e
        BFunctions.assign(0, B1nRMu3E + B1cRMu3E );
        BFunctions.assign(1, B1nLMu3E + B1cLMu3E );
        BFunctions.assign(2, B2nRMu3E + B2cRMu3E );
        BFunctions.assign(3, B2nLMu3E + B2cLMu3E );
        BFunctions.assign(4, B3nRMu3E + B3cRMu3E );
        BFunctions.assign(5, B3nLMu3E + B3cLMu3E );
        BFunctions.assign(6, B4nRMu3E );
        BFunctions.assign(7, B4nLMu3E );
    }
    if (li_to_lj == 2) // tau -> 3mu
    {
        //      Neutralino contributions
        gslpp::complex B1nRTau3Mu = 0.0;
        gslpp::complex B2nRTau3Mu = 0.0;
        gslpp::complex B3nRTau3Mu = 0.0;
        gslpp::complex B4nRTau3Mu = 0.0;
        gslpp::complex B1nLTau3Mu = 0.0;
        gslpp::complex B2nLTau3Mu = 0.0;
        gslpp::complex B3nLTau3Mu = 0.0;
        gslpp::complex B4nLTau3Mu = 0.0;
        for (int a=0;a<4;a++) {
            for (int b=0;b<4;b++) {
                for (int x=0;x<6;x++) {
                    for (int t=0;t<6;t++) {
                        B1nRTau3Mu = B1nRTau3Mu + (1.0/(4.0*pi*alph))*(0.5*NLlTAU(a,x)*NLlMU(a,t)*NLlMU(b,t)*NLlMU(b,x)/*J4n(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                       +MNeig(a)*MNeig(b)*NLlTAU(a,x)*NLlMU(a,t)*NLlMU(b,t)*NLlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nRTau3Mu = B2nRTau3Mu + (1.0/(4.0*pi*alph))*(0.25*(NLlTAU(a,x)*NLlMU(a,t)*NRlMU(b,t)*NRlMU(b,x)
                                                                             +NLlTAU(a,x)*NRlMU(a,t)*NLlMU(b,t)*NRlMU(b,x)
                                                                             -NLlTAU(a,x)*NRlMU(a,t)*NRlMU(b,t)*NLlMU(b,x))/*J4n(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                       -0.5*MNeig(a)*MNeig(b)*NLlTAU(a,x)*NRlMU(a,t)*NRlMU(b,t)*NLlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nRTau3Mu = B3nRTau3Mu + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NLlTAU(a,x)*NRlMU(a,t)*NLlMU(b,t)*NRlMU(b,x)
                                                                                         +0.5*NLlTAU(a,x)*NLlMU(a,t)*NRlMU(b,t)*NRlMU(b,x))/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nRTau3Mu = B4nRTau3Mu + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NLlTAU(a,x)*NLlMU(a,t)*NRlMU(b,t)*NRlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B1nLTau3Mu = B1nLTau3Mu + (1.0/(4.0*pi*alph))*(0.5*NRlTAU(a,x)*NRlMU(a,t)*NRlMU(b,t)*NRlMU(b,x)/*J4n(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                       +MNeig(a)*MNeig(b)*NRlTAU(a,x)*NRlMU(a,t)*NRlMU(b,t)*NRlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nLTau3Mu = B2nLTau3Mu + (1.0/(4.0*pi*alph))*(0.25*(NRlTAU(a,x)*NRlMU(a,t)*NLlMU(b,t)*NLlMU(b,x)
                                                                           +NRlTAU(a,x)*NLlMU(a,t)*NRlMU(b,t)*NLlMU(b,x)
                                                                           -NRlTAU(a,x)*NLlMU(a,t)*NLlMU(b,t)*NRlMU(b,x))/*J4n(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                     -0.5*MNeig(a)*MNeig(b)*NRlTAU(a,x)*NLlMU(a,t)*NLlMU(b,t)*NRlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nLTau3Mu = B3nLTau3Mu + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NRlTAU(a,x)*NLlMU(a,t)*NRlMU(b,t)*NLlMU(b,x)
                                                                                       +0.5*NRlTAU(a,x)*NRlMU(a,t)*NLlMU(b,t)*NLlMU(b,x))/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nLTau3Mu = B4nLTau3Mu + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NRlTAU(a,x)*NRlMU(a,t)*NLlMU(b,t)*NLlMU(b,x)/*I4n(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
        //      Chargino contributions
        gslpp::complex B1cRTau3Mu = 0.0;
        gslpp::complex B2cRTau3Mu = 0.0;
        gslpp::complex B3cRTau3Mu = 0.0;
        gslpp::complex B1cLTau3Mu = 0.0;
        gslpp::complex B2cLTau3Mu = 0.0;
        gslpp::complex B3cLTau3Mu = 0.0;
        for (int a=0;a<2;a++) {
            for (int b=0;b<2;b++) {
                for (int x=0;x<3;x++) {
                    for (int t=0;t<3;t++) {
                        B1cRTau3Mu = B1cRTau3Mu + (1.0/(8.0*pi*alph))*CLlTAU(a,x)*CLlMU(a,t)*CLlMU(b,t)*CLlMU(b,x)/*J4c(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi);
                        B2cRTau3Mu = B2cRTau3Mu + (1.0/(4.0*pi*alph))*(0.25*CLlTAU(a,x)*CLlMU(a,t)*CRlMU(b,t)*CRlMU(b,x)/*J4c(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                       -0.5*MChi(a)*MChi(b)*CLlTAU(a,x)*CRlMU(a,t)*CRlMU(b,t)*CLlMU(b,x)/*I4c(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cRTau3Mu = B3cRTau3Mu + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CLlTAU(a,x)*CRlMU(a,t)*CLlMU(b,t)*CRlMU(b,x)/*I4c(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                        B1cLTau3Mu = B1cLTau3Mu + (1.0/(8.0*pi*alph))*CRlTAU(a,x)*CRlMU(a,t)*CRlMU(b,t)*CRlMU(b,x)/*J4c(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi);
                        B2cLTau3Mu = B2cLTau3Mu + (1.0/(4.0*pi*alph))*(0.25*CRlTAU(a,x)*CRlMU(a,t)*CLlMU(b,t)*CLlMU(b,x)/*J4c(a,b,x,t)*/
                                                                        *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                       -0.5*MChi(a)*MChi(b)*CRlTAU(a,x)*CLlMU(a,t)*CLlMU(b,t)*CRlMU(b,x)/*I4c(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cLTau3Mu = B3cLTau3Mu + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CRlTAU(a,x)*CLlMU(a,t)*CRlMU(b,t)*CLlMU(b,x)/*I4c(a,b,x,t)*/
                                                                        *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
        //     write BR and BL into a vector for tau->3mu
        BFunctions.assign(0, B1nRTau3Mu + B1cRTau3Mu );
        BFunctions.assign(1, B1nLTau3Mu + B1cLTau3Mu );
        BFunctions.assign(2, B2nRTau3Mu + B2cRTau3Mu );
        BFunctions.assign(3, B2nLTau3Mu + B2cLTau3Mu );
        BFunctions.assign(4, B3nRTau3Mu + B3cRTau3Mu );
        BFunctions.assign(5, B3nLTau3Mu + B3cLTau3Mu );
        BFunctions.assign(6, B4nRTau3Mu );
        BFunctions.assign(7, B4nLTau3Mu );
    }
    if (li_to_lj == 3) // tau -> 3e
    {
        //      Neutralino contributions
        gslpp::complex B1nRTau3E = 0.0;
        gslpp::complex B2nRTau3E = 0.0;
        gslpp::complex B3nRTau3E = 0.0;
        gslpp::complex B4nRTau3E = 0.0;
        gslpp::complex B1nLTau3E = 0.0;
        gslpp::complex B2nLTau3E = 0.0;
        gslpp::complex B3nLTau3E = 0.0;
        gslpp::complex B4nLTau3E = 0.0;
        for (int a=0;a<4;a++) {
            for (int b=0;b<4;b++) {
                for (int x=0;x<6;x++) {
                    for (int t=0;t<6;t++) {
                        B1nRTau3E = B1nRTau3E + (1.0/(4.0*pi*alph))*(0.5*NLlTAU(a,x)*NLlE(a,t)*NLlE(b,t)*NLlE(b,x)/*J4n(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                     +MNeig(a)*MNeig(b)*NLlTAU(a,x)*NLlE(a,t)*NLlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nRTau3E = B2nRTau3E + (1.0/(4.0*pi*alph))*(0.25*(NLlTAU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x)
                                                                           +NLlTAU(a,x)*NRlE(a,t)*NLlE(b,t)*NRlE(b,x)
                                                                           -NLlTAU(a,x)*NRlE(a,t)*NRlE(b,t)*NLlE(b,x))/*J4n(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                     -0.5*MNeig(a)*MNeig(b)*NLlTAU(a,x)*NRlE(a,t)*NRlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nRTau3E = B3nRTau3E + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NLlTAU(a,x)*NRlE(a,t)*NLlE(b,t)*NRlE(b,x)
                                                                                       +0.5*NLlTAU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x))/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nRTau3E = B4nRTau3E + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NLlTAU(a,x)*NLlE(a,t)*NRlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B1nLTau3E = B1nLTau3E + (1.0/(4.0*pi*alph))*(0.5*NRlTAU(a,x)*NRlE(a,t)*NRlE(b,t)*NRlE(b,x)/*J4n(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                     +MNeig(a)*MNeig(b)*NRlTAU(a,x)*NRlE(a,t)*NRlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B2nLTau3E = B2nLTau3E + (1.0/(4.0*pi*alph))*(0.25*(NRlTAU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x)
                                                                           +NRlTAU(a,x)*NLlE(a,t)*NRlE(b,t)*NLlE(b,x)
                                                                           -NRlTAU(a,x)*NLlE(a,t)*NLlE(b,t)*NRlE(b,x))/*J4n(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(4.0*pi*pi)
                                                                     -0.5*MNeig(a)*MNeig(b)*NRlTAU(a,x)*NLlE(a,t)*NLlE(b,t)*NRlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi));
                        B3nLTau3E = B3nLTau3E + (1.0/(4.0*pi*alph))*MNeig(a)*MNeig(b)*(NRlTAU(a,x)*NLlE(a,t)*NRlE(b,t)*NLlE(b,x)
                                                                                       +0.5*NRlTAU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x))/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                        B4nLTau3E = B4nLTau3E + (1.0/(32.0*pi*alph))*MNeig(a)*MNeig(b)*NRlTAU(a,x)*NRlE(a,t)*NLlE(b,t)*NLlE(b,x)/*I4n(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_se_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
        //      Chargino contributions
        gslpp::complex B1cRTau3E = 0.0;
        gslpp::complex B2cRTau3E = 0.0;
        gslpp::complex B3cRTau3E = 0.0;
        gslpp::complex B1cLTau3E = 0.0;
        gslpp::complex B2cLTau3E = 0.0;
        gslpp::complex B3cLTau3E = 0.0;
        for (int a=0;a<2;a++) {
            for (int b=0;b<2;b++) {
                for (int x=0;x<3;x++) {
                    for (int t=0;t<3;t++) {
                        B1cRTau3E = B1cRTau3E + (1.0/(8.0*pi*alph))*CLlTAU(a,x)*CLlE(a,t)*CLlE(b,t)*CLlE(b,x)/*J4c(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi);
                        B2cRTau3E = B2cRTau3E + (1.0/(4.0*pi*alph))*(0.25*CLlTAU(a,x)*CLlE(a,t)*CRlE(b,t)*CRlE(b,x)/*J4c(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                     -0.5*MChi(a)*MChi(b)*CLlTAU(a,x)*CRlE(a,t)*CRlE(b,t)*CLlE(b,x)/*I4c(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cRTau3E = B3cRTau3E + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CLlTAU(a,x)*CRlE(a,t)*CLlE(b,t)*CRlE(b,x)/*I4c(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                        B1cLTau3E = B1cLTau3E + (1.0/(8.0*pi*alph))*CRlTAU(a,x)*CRlE(a,t)*CRlE(b,t)*CRlE(b,x)/*J4c(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi);
                        B2cLTau3E = B2cLTau3E + (1.0/(4.0*pi*alph))*(0.25*CRlTAU(a,x)*CRlE(a,t)*CLlE(b,t)*CLlE(b,x)/*J4c(a,b,x,t)*/
                                                                      *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(4.0*pi*pi)
                                                                     -0.5*MChi(a)*MChi(b)*CRlTAU(a,x)*CLlE(a,t)*CLlE(b,t)*CRlE(b,x)/*I4c(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi));
                        B3cLTau3E = B3cLTau3E + (1.0/(4.0*pi*alph))*MChi(a)*MChi(b)*CRlTAU(a,x)*CLlE(a,t)*CRlE(b,t)*CLlE(b,x)/*I4c(a,b,x,t)*/
                                                                      *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sn_sq(t))/(16.0*pi*pi);
                    }
                }
            }
        }
        //     write BR and BL into a vector for tau->3e
        BFunctions.assign(0, B1nRTau3E + B1cRTau3E );
        BFunctions.assign(1, B1nLTau3E + B1cLTau3E );
        BFunctions.assign(2, B2nRTau3E + B2cRTau3E );
        BFunctions.assign(3, B2nLTau3E + B2cLTau3E );
        BFunctions.assign(4, B3nRTau3E + B3cRTau3E );
        BFunctions.assign(5, B3nLTau3E + B3cLTau3E );
        BFunctions.assign(6, B4nRTau3E );
        BFunctions.assign(7, B4nLTau3E );
    }

    return(BFunctions);
}

int SUSYMatching::delta_ab(int a, int b) {
    if(a == b) return 1;
    else return 0;
}

gslpp::vector<gslpp::complex> SUSYMatching::BHFunctions(int li_to_lj) {
        //Higgs penguin contributions from PhysRevD.73.055003


    // To do:
    // Are the trilinear couplings from (A24) correct?
    // Should we update the missing parameters in the update function (sinalpha, A_l, ...)?

    NeutralinoRemixing();

    double MZ = mySUSY.getMz();
    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double piconst = 1.0/(32.0 * pi * pi);
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mTAU = mySUSY.getLeptons(StandardModel::TAU).getMass();
    double cos2b = 2.0*cosb*cosb-1.0;
    gslpp::complex sina = mySUSY.getSaeff();
    gslpp::complex cosa = sqrt(1.0-sina*sina);
    gslpp::complex sinapb = sina*cosb+cosa*sinb;
    gslpp::complex cosapb = cosa*cosb-sina*sinb;
    gslpp::complex cosbma = cosb*cosa+sinb*sina;
    gslpp::complex sinbma = sinb*cosa-cosb*sina;
    double mh = mySUSY.getMHl();
    double mH = mySUSY.getMHh();
    double mA = mySUSY.getMHa();
    gslpp::complex M1 = mySUSY.getM1();
    gslpp::complex M2 = mySUSY.getM2();
    gslpp::complex muH = mySUSY.getMuH();
    TEhat = mySUSY.getTEhat();

    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);
    double alph = mySUSY.getAle();

    gslpp::vector<gslpp::complex> BHFunctions(4, 0.);


    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlE.assign(a, x, - (g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 0) + (mE/cdenn)*ON(a, 2)*myRl(x, 3)));
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            NRlTAU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 2) + (mTAU/cdenn)*ON(a, 2)*myRl(x, 5)));
            //     RL + RR TYPE MI
            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2)*myRl(x, 0) + 2.0*ON(a, 0)*ttw*myRl(x, 3)));
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2)*myRl(x, 2) + 2.0*ON(a, 0)*ttw*myRl(x, 5)));
//    Commented expressions might be useful for complex neutralino mixing matrices
//            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2).conjugate()*myRl(x, 0) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 3)));
//            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2).conjugate()*myRl(x, 1) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 4)));
//            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2).conjugate()*myRl(x, 2) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 5)));
        }
    }

    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlE.assign(a, x, - (g2*myV(a, 0)*myRn(x, 0)));
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            CRlTAU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 2)));
            //     LR-TYPE
            CLlE.assign(a, x, g2*mE/cdenc*myU(a, 1).conjugate()*myRn(x, 0));
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
            CLlTAU.assign(a, x, g2*mTAU/cdenc*myU(a, 1).conjugate()*myRn(x, 2));
        }
    }

    gslpp::vector<gslpp::complex> sigma1(3, 0.);
    gslpp::vector<gslpp::complex> sigma2(3, 0.);
    gslpp::vector<gslpp::complex> sigma3(3, 0.);
    gslpp::vector<gslpp::complex> sigma4(3, 0.);
    gslpp::vector<gslpp::complex> sigma5(3, 0.);
    sigma1.assign(0, sina);
    sigma1.assign(1, -cosa);
    sigma1.assign(2, sinb*gslpp::complex::i());
    sigma2.assign(0, cosa);
    sigma2.assign(1, sina);
    sigma2.assign(2, -cosb*gslpp::complex::i());
    sigma3.assign(0, sinapb);
    sigma3.assign(1, -cosapb);
    sigma3.assign(2, 0.);
    sigma4.assign(0, -sina);
    sigma4.assign(1, cosa);
    sigma4.assign(2, 0.);
    sigma5.assign(0, -cosbma);
    sigma5.assign(1, sinbma);
    sigma5.assign(2, cos2b*gslpp::complex::i());

    gslpp::matrix<gslpp::complex> Qpp(4, 4, 0.), Rpp(4, 4, 0.);
    gslpp::matrix<gslpp::complex> DL0(4, 4, 0.), DR0(4, 4, 0.), DL1(4, 4, 0.), DR1(4, 4, 0.), DL2(4, 4, 0.), DR2(4, 4, 0.);
    for (int a=0;a<4;a++) {
        for (int b=0;b<4;b++) {
            Qpp.assign(a, b, 0.5*(ON(a,2)*(ON(b,1)-ttw*ON(b,0))+ON(b,2)*(ON(a,1)-ttw*ON(a,0))) );
            Rpp.assign(a, b, (M2.conjugate()*ON(a,1)*ON(b,1) +M1.conjugate()*ON(a,0)*ON(b,0) -muH.conjugate()*(ON(a,2)*ON(b,3)+ON(a,3)*ON(b,2)))/(2.0*MW) );
            DL0.assign(b, a, -g2/sinb * (Qpp(a,b).conjugate()*sigma5(0) -Rpp(a,b).conjugate()*sigma2(0) +MNeig(a)/(2.0*MW)*sigma2(0)*delta_ab(a,b)) );
            DR0.assign(b, a, DL0(b,a).conjugate() );
            DL1.assign(b, a, -g2/sinb * (Qpp(a,b).conjugate()*sigma5(1) -Rpp(a,b).conjugate()*sigma2(1) +MNeig(a)/(2.0*MW)*sigma2(1)*delta_ab(a,b)) );
            DR1.assign(b, a, DL1(b,a).conjugate() );
            DL2.assign(b, a, -g2/sinb * (Qpp(a,b).conjugate()*sigma5(2) -Rpp(a,b).conjugate()*sigma2(2) +MNeig(a)/(2.0*MW)*sigma2(2)*delta_ab(a,b)) );
            DR2.assign(b, a, DL2(b,a).conjugate() );
        }
    }

    gslpp::matrix<gslpp::complex> Qch(2, 2, 0.), Rch(2, 2, 0.);
    gslpp::matrix<gslpp::complex> WL0(2, 2, 0.), WR0(2, 2, 0.), WL1(2, 2, 0.), WR1(2, 2, 0.), WL2(2, 2, 0.), WR2(2, 2, 0.);
    for (int a=0;a<2;a++) {
        for (int b=0;b<2;b++) {
            Qch.assign(a, b, myU(a,1)*myV(b,0)/sqrt(2.0) );
            Rch.assign(a, b, (M2.conjugate()*myU(a,0)*myV(b,0) +muH.conjugate()*myU(a,1)*myV(b,1))/(2.0*MW) );
            WR0.assign(a, b, -g2/sinb * (Qch(a,b)*sigma5(0).conjugate() -Rch(a,b)*sigma2(0).conjugate() +MChi(a)/(2.0*MW)*sigma2(0).conjugate()*delta_ab(a,b)) );
            WL0.assign(b, a, WR0(a,b).conjugate() );
            WR1.assign(a, b, -g2/sinb * (Qch(a,b)*sigma5(1).conjugate() -Rch(a,b)*sigma2(1).conjugate() +MChi(a)/(2.0*MW)*sigma2(1).conjugate()*delta_ab(a,b)) );
            WL1.assign(b, a, WR1(a,b).conjugate() );
            WR2.assign(a, b, -g2/sinb * (Qch(a,b)*sigma5(2).conjugate() -Rch(a,b)*sigma2(2).conjugate() +MChi(a)/(2.0*MW)*sigma2(2).conjugate()*delta_ab(a,b)) );
            WL2.assign(b, a, WR2(a,b).conjugate() );
        }
    }

    gslpp::vector<gslpp::complex> gLLE(3, 0.), gRRE(3, 0.), gLRE(3, 0.), gRLE(3, 0.);
    gslpp::vector<gslpp::complex> gLLMU(3, 0.), gRRMU(3, 0.), gLRMU(3, 0.), gRLMU(3, 0.);
    gslpp::vector<gslpp::complex> gLLTAU(3, 0.), gRRTAU(3, 0.), gLRTAU(3, 0.), gRLTAU(3, 0.);
    gslpp::vector<gslpp::complex> gLLNU(3, 0.);
    for (int p=0;p<3;p++) {
        gLLE.assign(p, MZ/ctw*sigma3(p)*(0.5-sw2) + mE*mE/(MW*cosb)*sigma4(p));
        gLLMU.assign(p, MZ/ctw*sigma3(p)*(0.5-sw2) + mMU*mMU/(MW*cosb)*sigma4(p));
        gLLTAU.assign(p, MZ/ctw*sigma3(p)*(0.5-sw2) + mTAU*mTAU/(MW*cosb)*sigma4(p));
        gRRE.assign(p, MZ/ctw*sigma3(p)*sw2 + mE*mE/(MW*cosb)*sigma4(p));
        gRRMU.assign(p, MZ/ctw*sigma3(p)*sw2 + mMU*mMU/(MW*cosb)*sigma4(p));
        gRRTAU.assign(p, MZ/ctw*sigma3(p)*sw2 + mTAU*mTAU/(MW*cosb)*sigma4(p));
        gLRE.assign(p, (-sigma1(p)*TEhat(0,0)/mE*v1/sqrt(2.0)-sigma2(p).conjugate()*muH)*mE/(2.0*MW*cosb));
        gLRMU.assign(p, (-sigma1(p)*TEhat(1,1)/mMU*v1/sqrt(2.0)-sigma2(p).conjugate()*muH)*mMU/(2.0*MW*cosb));
        gLRTAU.assign(p, (-sigma1(p)*TEhat(2,2)/mTAU*v1/sqrt(2.0)-sigma2(p).conjugate()*muH)*mTAU/(2.0*MW*cosb));
        gRLE.assign(p, gLRE(p).conjugate());
        gRLMU.assign(p, gLRMU(p).conjugate());
        gRLTAU.assign(p, gLRTAU(p).conjugate());
        gLLNU.assign(p, -0.5*MZ/ctw*sigma3(p));
    }

    //Note that the dependence on the Rl and Rn elements here is different than the one in PhysRevD.73.055003
    //due to the different choice of flavour basis.
    //The replacement rules are:
    //AH basis (PhysRevD.73.055003) -> SLHA basis
    //  (from 1 to 6)               -> (from 0 to 5)
    //  Rl(x,1)                     -> Rl(0,x)
    //  Rl(x,2)                     -> Rl(3,x)
    //  Rl(x,3)                     -> Rl(1,x)
    //  Rl(x,4)                     -> Rl(4,x)
    //  Rl(x,5)                     -> Rl(2,x)
    //  Rl(x,6)                     -> Rl(5,x)
    //For Rn, the indices have to be swapped.

    gslpp::matrix<gslpp::complex> Gl0(6, 6, 0.), Gl1(6, 6, 0.), Gl2(6, 6, 0.);
    for (int x=0;x<6;x++) {
        for (int y=0;y<6;y++) {
            Gl0.assign(x, y, -g2*( gLLE(0)*myRl(x,0).conjugate()*myRl(y,0) +gRRE(0)*myRl(x,3).conjugate()*myRl(y,3) +gLRE(0)*myRl(x,0).conjugate()*myRl(y,3) +gRLE(0)*myRl(x,3).conjugate()*myRl(y,0)
                                  +gLLMU(0)*myRl(x,1).conjugate()*myRl(y,1) +gRRMU(0)*myRl(x,4).conjugate()*myRl(y,4) +gLRMU(0)*myRl(x,1).conjugate()*myRl(y,4) +gRLMU(0)*myRl(x,4).conjugate()*myRl(y,1)
                                  +gLLTAU(0)*myRl(x,2).conjugate()*myRl(y,2) +gRRTAU(0)*myRl(x,5).conjugate()*myRl(y,5) +gLRTAU(0)*myRl(x,2).conjugate()*myRl(y,5) +gRLTAU(0)*myRl(x,5).conjugate()*myRl(y,2)));
            Gl1.assign(x, y, -g2*( gLLE(1)*myRl(x,0).conjugate()*myRl(y,0) +gRRE(1)*myRl(x,3).conjugate()*myRl(y,3) +gLRE(1)*myRl(x,0).conjugate()*myRl(y,3) +gRLE(1)*myRl(x,3).conjugate()*myRl(y,0)
                                  +gLLMU(1)*myRl(x,1).conjugate()*myRl(y,1) +gRRMU(1)*myRl(x,4).conjugate()*myRl(y,4) +gLRMU(1)*myRl(x,1).conjugate()*myRl(y,4) +gRLMU(1)*myRl(x,4).conjugate()*myRl(y,1)
                                  +gLLTAU(1)*myRl(x,2).conjugate()*myRl(y,2) +gRRTAU(1)*myRl(x,5).conjugate()*myRl(y,5) +gLRTAU(1)*myRl(x,2).conjugate()*myRl(y,5) +gRLTAU(1)*myRl(x,5).conjugate()*myRl(y,2)));
            Gl2.assign(x, y, -g2*( gLLE(2)*myRl(x,0).conjugate()*myRl(y,0) +gRRE(2)*myRl(x,3).conjugate()*myRl(y,3) +gLRE(2)*myRl(x,0).conjugate()*myRl(y,3) +gRLE(2)*myRl(x,3).conjugate()*myRl(y,0)
                                  +gLLMU(2)*myRl(x,1).conjugate()*myRl(y,1) +gRRMU(2)*myRl(x,4).conjugate()*myRl(y,4) +gLRMU(2)*myRl(x,1).conjugate()*myRl(y,4) +gRLMU(2)*myRl(x,4).conjugate()*myRl(y,1)
                                  +gLLTAU(2)*myRl(x,2).conjugate()*myRl(y,2) +gRRTAU(2)*myRl(x,5).conjugate()*myRl(y,5) +gLRTAU(2)*myRl(x,2).conjugate()*myRl(y,5) +gRLTAU(2)*myRl(x,5).conjugate()*myRl(y,2)));
        }
    }

    gslpp::matrix<gslpp::complex> Gnu0(3, 3, 0.), Gnu1(3, 3, 0.), Gnu2(3, 3, 0.);
    for (int x=0;x<3;x++) {
        Gnu0.assign(x, x, -g2*gLLNU(0) );
        Gnu1.assign(x, x, -g2*gLLNU(1) );
        Gnu2.assign(x, x, -g2*gLLNU(2) );
    }

    gslpp::vector<gslpp::complex> SRE(3, 0.), SLE(3, 0.), SRMU(3, 0.), SLMU(3, 0.), SRTAU(3, 0.), SLTAU(3, 0.);
    for (int p=0;p<3;p++) {
        SRE.assign(p, g2*mE/(2.0*MW*cosb) * sigma1(p));
        SLE.assign(p, g2*mE/(2.0*MW*cosb) * sigma1(p).conjugate());
        SRMU.assign(p, g2*mMU/(2.0*MW*cosb) * sigma1(p));
        SLMU.assign(p, g2*mMU/(2.0*MW*cosb) * sigma1(p).conjugate());
        SRTAU.assign(p, g2*mTAU/(2.0*MW*cosb) * sigma1(p));
        SLTAU.assign(p, g2*mTAU/(2.0*MW*cosb) * sigma1(p).conjugate());
    }

    if (li_to_lj == 1) // mu -> 3e
    {
        //     Neutralino contributions
        gslpp::complex HpengMuEEENR0 = 0.0;
        gslpp::complex HpengMuEEENL0 = 0.0;
        gslpp::complex HpengMuEEENR1 = 0.0;
        gslpp::complex HpengMuEEENL1 = 0.0;
        gslpp::complex HpengMuEEENR2 = 0.0;
        gslpp::complex HpengMuEEENL2 = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    //     h R contribution
                    HpengMuEEENR0 = HpengMuEEENR0 - 2.0*piconst*(NRlE(a,x)*DL0(a,b)*NLlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR0(a,b)*NRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR0(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL0(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL0(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR0(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR0(a,b)*NLlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     h L contribution
                    HpengMuEEENL0 = HpengMuEEENL0 - 2.0*piconst*(NLlE(a,x)*DR0(a,b)*NRlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL0(a,b)*NLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL0(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR0(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR0(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL0(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL0(a,b)*NRlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H R contribution
                    HpengMuEEENR1 = HpengMuEEENR1 - 2.0*piconst*(NRlE(a,x)*DL1(a,b)*NLlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR1(a,b)*NRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR1(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL1(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL1(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR1(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR1(a,b)*NLlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H L contribution
                    HpengMuEEENL1 = HpengMuEEENL1 - 2.0*piconst*(NLlE(a,x)*DR1(a,b)*NRlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL1(a,b)*NLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL1(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR1(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR1(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL1(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL1(a,b)*NRlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A R contribution
                    HpengMuEEENR2 = HpengMuEEENR2 - 2.0*piconst*(NRlE(a,x)*DL2(a,b)*NLlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR2(a,b)*NRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR2(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL2(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL2(a,b)*NLlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR2(a,b)*NRlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR2(a,b)*NLlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A L contribution
                    HpengMuEEENL2 = HpengMuEEENL2 - 2.0*piconst*(NLlE(a,x)*DR2(a,b)*NRlMU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL2(a,b)*NLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL2(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR2(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR2(a,b)*NRlMU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL2(a,b)*NLlMU(b,x).conjugate()*mMU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL2(a,b)*NRlMU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                }
                for (int y=0;y<6;y++) {
                    //     h R contribution
                    HpengMuEEENR0 = HpengMuEEENR0 - 2.0*piconst*Gl0(x,y)*(-NLlE(a,x)*NLlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     h L contribution
                    HpengMuEEENL0 = HpengMuEEENL0 - 2.0*piconst*Gl0(x,y)*(-NRlE(a,x)*NRlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H R contribution
                    HpengMuEEENR1 = HpengMuEEENR1 - 2.0*piconst*Gl1(x,y)*(-NLlE(a,x)*NLlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H L contribution
                    HpengMuEEENL1 = HpengMuEEENL1 - 2.0*piconst*Gl1(x,y)*(-NRlE(a,x)*NRlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A R contribution
                    HpengMuEEENR2 = HpengMuEEENR2 - 2.0*piconst*Gl2(x,y)*(-NLlE(a,x)*NLlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A L contribution
                    HpengMuEEENL2 = HpengMuEEENL2 - 2.0*piconst*Gl2(x,y)*(-NRlE(a,x)*NRlMU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlMU(a,y).conjugate()*mMU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlMU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                }
                //     h R contribution
                HpengMuEEENR0 = HpengMuEEENR0 - 2.0*piconst*(SRMU(0)/(mE*mE-mMU*mMU)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(0)/(mMU*mMU-mE*mE)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     h L contribution
                HpengMuEEENL0 = HpengMuEEENL0 - 2.0*piconst*(SLMU(0)/(mE*mE-mMU*mMU)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(0)/(mMU*mMU-mE*mE)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H R contribution
                HpengMuEEENR1 = HpengMuEEENR1 - 2.0*piconst*(SRMU(1)/(mE*mE-mMU*mMU)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(1)/(mMU*mMU-mE*mE)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H L contribution
                HpengMuEEENL1 = HpengMuEEENL1 - 2.0*piconst*(SLMU(1)/(mE*mE-mMU*mMU)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(1)/(mMU*mMU-mE*mE)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A R contribution
                HpengMuEEENR2 = HpengMuEEENR2 - 2.0*piconst*(SRMU(2)/(mE*mE-mMU*mMU)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(2)/(mMU*mMU-mE*mE)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A L contribution
                HpengMuEEENL2 = HpengMuEEENL2 - 2.0*piconst*(SLMU(2)/(mE*mE-mMU*mMU)*(-NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(2)/(mMU*mMU-mE*mE)*(-NRlE(a,x)*NRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlMU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlMU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
            }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggsnR = (-0.5*HpengMuEEENR0*SLE(0)/(mh*mh)-0.5*HpengMuEEENR1*SLE(1)/(mH*mH)-0.5*HpengMuEEENR2*SLE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggsnL = (-0.5*HpengMuEEENL0*SRE(0)/(mh*mh)-0.5*HpengMuEEENL1*SRE(1)/(mH*mH)-0.5*HpengMuEEENL2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnR = (HpengMuEEENR0*SRE(0)/(mh*mh)+HpengMuEEENR1*SRE(1)/(mH*mH)+HpengMuEEENR2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnL = (HpengMuEEENL0*SLE(0)/(mh*mh)+HpengMuEEENL1*SLE(1)/(mH*mH)+HpengMuEEENL2*SLE(2)/(mA*mA))/(4.0*pi*alph);

        //     Chargino contributions
        gslpp::complex HpengMuEEECR0 = 0.0;
        gslpp::complex HpengMuEEECL0 = 0.0;
        gslpp::complex HpengMuEEECR1 = 0.0;
        gslpp::complex HpengMuEEECL1 = 0.0;
        gslpp::complex HpengMuEEECR2 = 0.0;
        gslpp::complex HpengMuEEECL2 = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    //     h R contribution
                    HpengMuEEECR0 = HpengMuEEECR0 - 2.0*piconst*(CRlE(a,x)*WL0(a,b)*CLlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR0(a,b)*CRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR0(a,b)*CLlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL0(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL0(a,b)*CLlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR0(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR0(a,b)*CLlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     h L contribution
                    HpengMuEEECL0 = HpengMuEEECL0 - 2.0*piconst*(CLlE(a,x)*WR0(a,b)*CRlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL0(a,b)*CLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL0(a,b)*CRlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR0(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR0(a,b)*CRlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL0(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL0(a,b)*CRlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H R contribution
                    HpengMuEEECR1 = HpengMuEEECR1 - 2.0*piconst*(CRlE(a,x)*WL1(a,b)*CLlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR1(a,b)*CRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR1(a,b)*CLlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL1(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL1(a,b)*CLlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR1(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR1(a,b)*CLlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H L contribution
                    HpengMuEEECL1 = HpengMuEEECL1 - 2.0*piconst*(CLlE(a,x)*WR1(a,b)*CRlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL1(a,b)*CLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL1(a,b)*CRlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR1(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR1(a,b)*CRlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL1(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL1(a,b)*CRlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A R contribution
                    HpengMuEEECR2 = HpengMuEEECR2 - 2.0*piconst*(CRlE(a,x)*WL2(a,b)*CLlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR2(a,b)*CRlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR2(a,b)*CLlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL2(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL2(a,b)*CLlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR2(a,b)*CRlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR2(a,b)*CLlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A L contribution
                    HpengMuEEECL2 = HpengMuEEECL2 - 2.0*piconst*(CLlE(a,x)*WR2(a,b)*CRlMU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL2(a,b)*CLlMU(b,x).conjugate()*mMU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL2(a,b)*CRlMU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR2(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR2(a,b)*CRlMU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL2(a,b)*CLlMU(b,x).conjugate()*mMU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL2(a,b)*CRlMU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                }
                for (int y=0;y<3;y++) {
                    //     h R contribution
                    HpengMuEEECR0 = HpengMuEEECR0 - 2.0*piconst*Gnu0(x,y)*(-CLlE(a,x)*CLlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     h L contribution
                    HpengMuEEECL0 = HpengMuEEECL0 - 2.0*piconst*Gnu0(x,y)*(-CRlE(a,x)*CRlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H R contribution
                    HpengMuEEECR1 = HpengMuEEECR1 - 2.0*piconst*Gnu1(x,y)*(-CLlE(a,x)*CLlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H L contribution
                    HpengMuEEECL1 = HpengMuEEECL1 - 2.0*piconst*Gnu1(x,y)*(-CRlE(a,x)*CRlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A R contribution
                    HpengMuEEECR2 = HpengMuEEECR2 - 2.0*piconst*Gnu2(x,y)*(-CLlE(a,x)*CLlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A L contribution
                    HpengMuEEECL2 = HpengMuEEECL2 - 2.0*piconst*Gnu2(x,y)*(-CRlE(a,x)*CRlMU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlMU(a,y).conjugate()*mMU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlMU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                }
                //     h R contribution
                HpengMuEEECR0 = HpengMuEEECR0 - 2.0*piconst*(SRMU(0)/(mE*mE-mMU*mMU)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(0)/(mMU*mMU-mE*mE)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     h L contribution
                HpengMuEEECL0 = HpengMuEEECL0 - 2.0*piconst*(SLMU(0)/(mE*mE-mMU*mMU)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(0)/(mMU*mMU-mE*mE)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H R contribution
                HpengMuEEECR1 = HpengMuEEECR1 - 2.0*piconst*(SRMU(1)/(mE*mE-mMU*mMU)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(1)/(mMU*mMU-mE*mE)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H L contribution
                HpengMuEEECL1 = HpengMuEEECL1 - 2.0*piconst*(SLMU(1)/(mE*mE-mMU*mMU)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(1)/(mMU*mMU-mE*mE)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A R contribution
                HpengMuEEECR2 = HpengMuEEECR2 - 2.0*piconst*(SRMU(2)/(mE*mE-mMU*mMU)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(2)/(mMU*mMU-mE*mE)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A L contribution
                HpengMuEEECL2 = HpengMuEEECL2 - 2.0*piconst*(SLMU(2)/(mE*mE-mMU*mMU)*(-CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(2)/(mMU*mMU-mE*mE)*(-CRlE(a,x)*CRlMU(a,x).conjugate()*mMU*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlMU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlMU(a,x).conjugate()*mE*mMU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlMU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
           }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggscR = (-0.5*HpengMuEEECR0*SLE(0)/(mh*mh)-0.5*HpengMuEEECR1*SLE(1)/(mH*mH)-0.5*HpengMuEEECR2*SLE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggscL = (-0.5*HpengMuEEECL0*SRE(0)/(mh*mh)-0.5*HpengMuEEECL1*SRE(1)/(mH*mH)-0.5*HpengMuEEECL2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscR = (HpengMuEEECR0*SRE(0)/(mh*mh)+HpengMuEEECR1*SRE(1)/(mH*mH)+HpengMuEEECR2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscL = (HpengMuEEECL0*SLE(0)/(mh*mh)+HpengMuEEECL1*SLE(1)/(mH*mH)+HpengMuEEECL2*SLE(2)/(mA*mA))/(4.0*pi*alph);

        //     write B2H and B3H into a vector for mu->3e
        BHFunctions.assign(0, B2HiggsnR+B2HiggscR );
        BHFunctions.assign(1, B2HiggsnL+B2HiggscL );
        BHFunctions.assign(2, B3HiggsnR+B3HiggscR );
        BHFunctions.assign(3, B3HiggsnL+B3HiggscL );
    }

    if (li_to_lj == 2) // tau -> 3mu
    {
        //     Neutralino contributions
        gslpp::complex HpengTauMUMUMUNR0 = 0.0;
        gslpp::complex HpengTauMUMUMUNL0 = 0.0;
        gslpp::complex HpengTauMUMUMUNR1 = 0.0;
        gslpp::complex HpengTauMUMUMUNL1 = 0.0;
        gslpp::complex HpengTauMUMUMUNR2 = 0.0;
        gslpp::complex HpengTauMUMUMUNL2 = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    //     h R contribution
                    HpengTauMUMUMUNR0 = HpengTauMUMUMUNR0 - 2.0*piconst*(NRlMU(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlMU(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlMU(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     h L contribution
                    HpengTauMUMUMUNL0 = HpengTauMUMUMUNL0 - 2.0*piconst*(NLlMU(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlMU(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlMU(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H R contribution
                    HpengTauMUMUMUNR1 = HpengTauMUMUMUNR1 - 2.0*piconst*(NRlMU(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlMU(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlMU(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H L contribution
                    HpengTauMUMUMUNL1 = HpengTauMUMUMUNL1 - 2.0*piconst*(NLlMU(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlMU(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlMU(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A R contribution
                    HpengTauMUMUMUNR2 = HpengTauMUMUMUNR2 - 2.0*piconst*(NRlMU(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlMU(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlMU(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A L contribution
                    HpengTauMUMUMUNL2 = HpengTauMUMUMUNL2 - 2.0*piconst*(NLlMU(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlMU(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlMU(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlMU(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mMU*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlMU(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                }
                for (int y=0;y<6;y++) {
                    //     h R contribution
                    HpengTauMUMUMUNR0 = HpengTauMUMUMUNR0 - 2.0*piconst*Gl0(x,y)*(-NLlMU(a,x)*NLlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlMU(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlMU(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     h L contribution
                    HpengTauMUMUMUNL0 = HpengTauMUMUMUNL0 - 2.0*piconst*Gl0(x,y)*(-NRlMU(a,x)*NRlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlMU(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlMU(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H R contribution
                    HpengTauMUMUMUNR1 = HpengTauMUMUMUNR1 - 2.0*piconst*Gl1(x,y)*(-NLlMU(a,x)*NLlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlMU(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlMU(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H L contribution
                    HpengTauMUMUMUNL1 = HpengTauMUMUMUNL1 - 2.0*piconst*Gl1(x,y)*(-NRlMU(a,x)*NRlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlMU(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlMU(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A R contribution
                    HpengTauMUMUMUNR2 = HpengTauMUMUMUNR2 - 2.0*piconst*Gl2(x,y)*(-NLlMU(a,x)*NLlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlMU(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlMU(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A L contribution
                    HpengTauMUMUMUNL2 = HpengTauMUMUMUNL2 - 2.0*piconst*Gl2(x,y)*(-NRlMU(a,x)*NRlTAU(a,y).conjugate()*mMU*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlMU(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlMU(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                }
                //     h R contribution
                HpengTauMUMUMUNR0 = HpengTauMUMUMUNR0 - 2.0*piconst*(SRTAU(0)/(mMU*mMU-mTAU*mTAU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRMU(0)/(mTAU*mTAU-mMU*mMU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     h L contribution
                HpengTauMUMUMUNL0 = HpengTauMUMUMUNL0 - 2.0*piconst*(SLTAU(0)/(mMU*mMU-mTAU*mTAU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLMU(0)/(mTAU*mTAU-mMU*mMU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H R contribution
                HpengTauMUMUMUNR1 = HpengTauMUMUMUNR1 - 2.0*piconst*(SRTAU(1)/(mMU*mMU-mTAU*mTAU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRMU(1)/(mTAU*mTAU-mMU*mMU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H L contribution
                HpengTauMUMUMUNL1 = HpengTauMUMUMUNL1 - 2.0*piconst*(SLTAU(1)/(mMU*mMU-mTAU*mTAU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLMU(1)/(mTAU*mTAU-mMU*mMU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A R contribution
                HpengTauMUMUMUNR2 = HpengTauMUMUMUNR2 - 2.0*piconst*(SRTAU(2)/(mMU*mMU-mTAU*mTAU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRMU(2)/(mTAU*mTAU-mMU*mMU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A L contribution
                HpengTauMUMUMUNL2 = HpengTauMUMUMUNL2 - 2.0*piconst*(SLTAU(2)/(mMU*mMU-mTAU*mTAU)*(-NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLMU(2)/(mTAU*mTAU-mMU*mMU)*(-NRlMU(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlMU(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlMU(a,x)*NLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlMU(a,x)*NRlTAU(a,x).conjugate()*mMU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
            }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggsnRtm = (-0.5*HpengTauMUMUMUNR0*SLMU(0)/(mh*mh)-0.5*HpengTauMUMUMUNR1*SLMU(1)/(mH*mH)-0.5*HpengTauMUMUMUNR2*SLMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggsnLtm = (-0.5*HpengTauMUMUMUNL0*SRMU(0)/(mh*mh)-0.5*HpengTauMUMUMUNL1*SRMU(1)/(mH*mH)-0.5*HpengTauMUMUMUNL2*SRMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnRtm = (HpengTauMUMUMUNR0*SRMU(0)/(mh*mh)+HpengTauMUMUMUNR1*SRMU(1)/(mH*mH)+HpengTauMUMUMUNR2*SRMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnLtm = (HpengTauMUMUMUNL0*SLMU(0)/(mh*mh)+HpengTauMUMUMUNL1*SLMU(1)/(mH*mH)+HpengTauMUMUMUNL2*SLMU(2)/(mA*mA))/(4.0*pi*alph);

        //     Chargino contributions
        gslpp::complex HpengTauMUMUMUCR0 = 0.0;
        gslpp::complex HpengTauMUMUMUCL0 = 0.0;
        gslpp::complex HpengTauMUMUMUCR1 = 0.0;
        gslpp::complex HpengTauMUMUMUCL1 = 0.0;
        gslpp::complex HpengTauMUMUMUCR2 = 0.0;
        gslpp::complex HpengTauMUMUMUCL2 = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    //     h R contribution
                    HpengTauMUMUMUCR0 = HpengTauMUMUMUCR0 - 2.0*piconst*(CRlMU(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlMU(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlMU(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     h L contribution
                    HpengTauMUMUMUCL0 = HpengTauMUMUMUCL0 - 2.0*piconst*(CLlMU(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlMU(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlMU(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H R contribution
                    HpengTauMUMUMUCR1 = HpengTauMUMUMUCR1 - 2.0*piconst*(CRlMU(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlMU(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlMU(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H L contribution
                    HpengTauMUMUMUCL1 = HpengTauMUMUMUCL1 - 2.0*piconst*(CLlMU(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlMU(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlMU(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A R contribution
                    HpengTauMUMUMUCR2 = HpengTauMUMUMUCR2 - 2.0*piconst*(CRlMU(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlMU(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlMU(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A L contribution
                    HpengTauMUMUMUCL2 = HpengTauMUMUMUCL2 - 2.0*piconst*(CLlMU(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mMU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlMU(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mTAU*mMU*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlMU(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlMU(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mMU*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlMU(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                }
                for (int y=0;y<3;y++) {
                    //     h R contribution
                    HpengTauMUMUMUCR0 = HpengTauMUMUMUCR0 - 2.0*piconst*Gnu0(x,y)*(-CLlMU(a,x)*CLlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlMU(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlMU(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     h L contribution
                    HpengTauMUMUMUCL0 = HpengTauMUMUMUCL0 - 2.0*piconst*Gnu0(x,y)*(-CRlMU(a,x)*CRlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlMU(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlMU(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H R contribution
                    HpengTauMUMUMUCR1 = HpengTauMUMUMUCR1 - 2.0*piconst*Gnu1(x,y)*(-CLlMU(a,x)*CLlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlMU(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlMU(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H L contribution
                    HpengTauMUMUMUCL1 = HpengTauMUMUMUCL1 - 2.0*piconst*Gnu1(x,y)*(-CRlMU(a,x)*CRlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlMU(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlMU(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A R contribution
                    HpengTauMUMUMUCR2 = HpengTauMUMUMUCR2 - 2.0*piconst*Gnu2(x,y)*(-CLlMU(a,x)*CLlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlMU(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlMU(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A L contribution
                    HpengTauMUMUMUCL2 = HpengTauMUMUMUCL2 - 2.0*piconst*Gnu2(x,y)*(-CRlMU(a,x)*CRlTAU(a,y).conjugate()*mMU*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlMU(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlMU(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                }
                //     h R contribution
                HpengTauMUMUMUCR0 = HpengTauMUMUMUCR0 - 2.0*piconst*(SRTAU(0)/(mMU*mMU-mTAU*mTAU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRMU(0)/(mTAU*mTAU-mMU*mMU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     h L contribution
                HpengTauMUMUMUCL0 = HpengTauMUMUMUCL0 - 2.0*piconst*(SLTAU(0)/(mMU*mMU-mTAU*mTAU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLMU(0)/(mTAU*mTAU-mMU*mMU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H R contribution
                HpengTauMUMUMUCR1 = HpengTauMUMUMUCR1 - 2.0*piconst*(SRTAU(1)/(mMU*mMU-mTAU*mTAU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRMU(1)/(mTAU*mTAU-mMU*mMU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H L contribution
                HpengTauMUMUMUCL1 = HpengTauMUMUMUCL1 - 2.0*piconst*(SLTAU(1)/(mMU*mMU-mTAU*mTAU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLMU(1)/(mTAU*mTAU-mMU*mMU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A R contribution
                HpengTauMUMUMUCR2 = HpengTauMUMUMUCR2 - 2.0*piconst*(SRTAU(2)/(mMU*mMU-mTAU*mTAU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRMU(2)/(mTAU*mTAU-mMU*mMU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A L contribution
                HpengTauMUMUMUCL2 = HpengTauMUMUMUCL2 - 2.0*piconst*(SLTAU(2)/(mMU*mMU-mTAU*mTAU)*(-CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mMU*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLMU(2)/(mTAU*mTAU-mMU*mMU)*(-CRlMU(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlMU(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlMU(a,x)*CLlTAU(a,x).conjugate()*mMU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlMU(a,x)*CRlTAU(a,x).conjugate()*mMU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
           }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggscRtm = (-0.5*HpengTauMUMUMUCR0*SLMU(0)/(mh*mh)-0.5*HpengTauMUMUMUCR1*SLMU(1)/(mH*mH)-0.5*HpengTauMUMUMUCR2*SLMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggscLtm = (-0.5*HpengTauMUMUMUCL0*SRMU(0)/(mh*mh)-0.5*HpengTauMUMUMUCL1*SRMU(1)/(mH*mH)-0.5*HpengTauMUMUMUCL2*SRMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscRtm = (HpengTauMUMUMUCR0*SRMU(0)/(mh*mh)+HpengTauMUMUMUCR1*SRMU(1)/(mH*mH)+HpengTauMUMUMUCR2*SRMU(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscLtm = (HpengTauMUMUMUCL0*SLMU(0)/(mh*mh)+HpengTauMUMUMUCL1*SLMU(1)/(mH*mH)+HpengTauMUMUMUCL2*SLMU(2)/(mA*mA))/(4.0*pi*alph);

        //     write B2H and B3H into a vector for tau->3mu
        BHFunctions.assign(0, B2HiggsnRtm+B2HiggscRtm );
        BHFunctions.assign(1, B2HiggsnLtm+B2HiggscLtm );
        BHFunctions.assign(2, B3HiggsnRtm+B3HiggscRtm );
        BHFunctions.assign(3, B3HiggsnLtm+B3HiggscLtm );
    }

    if (li_to_lj == 3) // tau -> 3e
    {
        //     Neutralino contributions
        gslpp::complex HpengTauEEENR0 = 0.0;
        gslpp::complex HpengTauEEENL0 = 0.0;
        gslpp::complex HpengTauEEENR1 = 0.0;
        gslpp::complex HpengTauEEENL1 = 0.0;
        gslpp::complex HpengTauEEENR2 = 0.0;
        gslpp::complex HpengTauEEENL2 = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    //     h R contribution
                    HpengTauEEENR0 = HpengTauEEENR0 - 2.0*piconst*(NRlE(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     h L contribution
                    HpengTauEEENL0 = HpengTauEEENL0 - 2.0*piconst*(NLlE(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR0(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR0(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL0(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL0(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H R contribution
                    HpengTauEEENR1 = HpengTauEEENR1 - 2.0*piconst*(NRlE(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     H L contribution
                    HpengTauEEENL1 = HpengTauEEENL1 - 2.0*piconst*(NLlE(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR1(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR1(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL1(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL1(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A R contribution
                    HpengTauEEENR2 = HpengTauEEENR2 - 2.0*piconst*(NRlE(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NLlE(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NLlE(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                    //     A L contribution
                    HpengTauEEENL2 = HpengTauEEENL2 - 2.0*piconst*(NLlE(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            -mym_se_sq(x)*PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                            +mE*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))))
                                                                 +NRlE(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                    -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NRlE(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(b)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DR2(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(b)*PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                 +NRlE(a,x)*DR2(a,b)*NRlTAU(b,x).conjugate()*mE*MNeig(a)*(PV.C11(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                         -PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL2(a,b)*NLlTAU(b,x).conjugate()*mTAU*MNeig(a)*(PV.C12(mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))
                                                                                                                          -PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b)))
                                                                 +NLlE(a,x)*DL2(a,b)*NRlTAU(b,x).conjugate()*MNeig(a)*MNeig(b)*(-PV.C0(0.,mym_se_sq(x),MNeig(a)*MNeig(a),MNeig(b)*MNeig(b))));
                }
                for (int y=0;y<6;y++) {
                    //     h R contribution
                    HpengTauEEENR0 = HpengTauEEENR0 - 2.0*piconst*Gl0(x,y)*(-NLlE(a,x)*NLlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     h L contribution
                    HpengTauEEENL0 = HpengTauEEENL0 - 2.0*piconst*Gl0(x,y)*(-NRlE(a,x)*NRlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H R contribution
                    HpengTauEEENR1 = HpengTauEEENR1 - 2.0*piconst*Gl1(x,y)*(-NLlE(a,x)*NLlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     H L contribution
                    HpengTauEEENL1 = HpengTauEEENL1 - 2.0*piconst*Gl1(x,y)*(-NRlE(a,x)*NRlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A R contribution
                    HpengTauEEENR2 = HpengTauEEENR2 - 2.0*piconst*Gl2(x,y)*(-NLlE(a,x)*NLlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NRlE(a,x)*NRlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NRlE(a,x)*NLlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                    //     A L contribution
                    HpengTauEEENL2 = HpengTauEEENL2 - 2.0*piconst*Gl2(x,y)*(-NRlE(a,x)*NRlTAU(a,y).conjugate()*mE*(PV.C11(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                                                                -PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)))
                                                                          -NLlE(a,x)*NLlTAU(a,y).conjugate()*mTAU*PV.C12(MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y))
                                                                          -NLlE(a,x)*NRlTAU(a,y).conjugate()*MNeig(a)*PV.C0(0.,MNeig(a)*MNeig(a),mym_se_sq(x),mym_se_sq(y)));
                }
                //     h R contribution
                HpengTauEEENR0 = HpengTauEEENR0 - 2.0*piconst*(SRTAU(0)/(mE*mE-mTAU*mTAU)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(0)/(mTAU*mTAU-mE*mE)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     h L contribution
                HpengTauEEENL0 = HpengTauEEENL0 - 2.0*piconst*(SLTAU(0)/(mE*mE-mTAU*mTAU)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(0)/(mTAU*mTAU-mE*mE)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H R contribution
                HpengTauEEENR1 = HpengTauEEENR1 - 2.0*piconst*(SRTAU(1)/(mE*mE-mTAU*mTAU)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(1)/(mTAU*mTAU-mE*mE)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     H L contribution
                HpengTauEEENL1 = HpengTauEEENL1 - 2.0*piconst*(SLTAU(1)/(mE*mE-mTAU*mTAU)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(1)/(mTAU*mTAU-mE*mE)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A R contribution
                HpengTauEEENR2 = HpengTauEEENR2 - 2.0*piconst*(SRTAU(2)/(mE*mE-mTAU*mTAU)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SRE(2)/(mTAU*mTAU-mE*mE)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
                //     A L contribution
                HpengTauEEENL2 = HpengTauEEENL2 - 2.0*piconst*(SLTAU(2)/(mE*mE-mTAU*mTAU)*(-NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NRlE(a,x)*NRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x)))
                                                             +SLE(2)/(mTAU*mTAU-mE*mE)*(-NRlE(a,x)*NRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NRlE(a,x)*NLlTAU(a,x).conjugate()*mTAU*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      -NLlE(a,x)*NLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))
                                                                                      +NLlE(a,x)*NRlTAU(a,x).conjugate()*mE*MNeig(a)*PV.B0(1.,0.,MNeig(a)*MNeig(a),mym_se_sq(x))));
            }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggsnRte = (-0.5*HpengTauEEENR0*SLE(0)/(mh*mh)-0.5*HpengTauEEENR1*SLE(1)/(mH*mH)-0.5*HpengTauEEENR2*SLE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggsnLte = (-0.5*HpengTauEEENL0*SRE(0)/(mh*mh)-0.5*HpengTauEEENL1*SRE(1)/(mH*mH)-0.5*HpengTauEEENL2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnRte = (HpengTauEEENR0*SRE(0)/(mh*mh)+HpengTauEEENR1*SRE(1)/(mH*mH)+HpengTauEEENR2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggsnLte = (HpengTauEEENL0*SLE(0)/(mh*mh)+HpengTauEEENL1*SLE(1)/(mH*mH)+HpengTauEEENL2*SLE(2)/(mA*mA))/(4.0*pi*alph);

        //     Chargino contributions
        gslpp::complex HpengTauEEECR0 = 0.0;
        gslpp::complex HpengTauEEECL0 = 0.0;
        gslpp::complex HpengTauEEECR1 = 0.0;
        gslpp::complex HpengTauEEECL1 = 0.0;
        gslpp::complex HpengTauEEECR2 = 0.0;
        gslpp::complex HpengTauEEECL2 = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    //     h R contribution
                    HpengTauEEECR0 = HpengTauEEECR0 - 2.0*piconst*(CRlE(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     h L contribution
                    HpengTauEEECL0 = HpengTauEEECL0 - 2.0*piconst*(CLlE(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR0(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR0(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL0(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL0(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H R contribution
                    HpengTauEEECR1 = HpengTauEEECR1 - 2.0*piconst*(CRlE(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     H L contribution
                    HpengTauEEECL1 = HpengTauEEECL1 - 2.0*piconst*(CLlE(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR1(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR1(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL1(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL1(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A R contribution
                    HpengTauEEECR2 = HpengTauEEECR2 - 2.0*piconst*(CRlE(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CLlE(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CLlE(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                    //     A L contribution
                    HpengTauEEECL2 = HpengTauEEECL2 - 2.0*piconst*(CLlE(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*(PV.B0(1.,0.,MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            -mym_sn_sq(x)*PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mTAU*mTAU*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                            +mE*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))))
                                                                 +CRlE(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mTAU*mE*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                    -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CRlE(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(b)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WR2(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(b)*PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                 +CRlE(a,x)*WR2(a,b)*CRlTAU(b,x).conjugate()*mE*MChi(a)*(PV.C11(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                        -PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL2(a,b)*CLlTAU(b,x).conjugate()*mTAU*MChi(a)*(PV.C12(mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))
                                                                                                                         -PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b)))
                                                                 +CLlE(a,x)*WL2(a,b)*CRlTAU(b,x).conjugate()*MChi(a)*MChi(b)*(-PV.C0(0.,mym_sn_sq(x),MChi(a)*MChi(a),MChi(b)*MChi(b))));
                }
                for (int y=0;y<3;y++) {
                    //     h R contribution
                    HpengTauEEECR0 = HpengTauEEECR0 - 2.0*piconst*Gnu0(x,y)*(-CLlE(a,x)*CLlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     h L contribution
                    HpengTauEEECL0 = HpengTauEEECL0 - 2.0*piconst*Gnu0(x,y)*(-CRlE(a,x)*CRlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H R contribution
                    HpengTauEEECR1 = HpengTauEEECR1 - 2.0*piconst*Gnu1(x,y)*(-CLlE(a,x)*CLlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     H L contribution
                    HpengTauEEECL1 = HpengTauEEECL1 - 2.0*piconst*Gnu1(x,y)*(-CRlE(a,x)*CRlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A R contribution
                    HpengTauEEECR2 = HpengTauEEECR2 - 2.0*piconst*Gnu2(x,y)*(-CLlE(a,x)*CLlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CRlE(a,x)*CRlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CRlE(a,x)*CLlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                    //     A L contribution
                    HpengTauEEECL2 = HpengTauEEECL2 - 2.0*piconst*Gnu2(x,y)*(-CRlE(a,x)*CRlTAU(a,y).conjugate()*mE*(PV.C11(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                                                                 -PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)))
                                                                           -CLlE(a,x)*CLlTAU(a,y).conjugate()*mTAU*PV.C12(MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y))
                                                                           -CLlE(a,x)*CRlTAU(a,y).conjugate()*MChi(a)*PV.C0(0.,MChi(a)*MChi(a),mym_sn_sq(x),mym_sn_sq(y)));
                }
                //     h R contribution
                HpengTauEEECR0 = HpengTauEEECR0 - 2.0*piconst*(SRTAU(0)/(mE*mE-mTAU*mTAU)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(0)/(mTAU*mTAU-mE*mE)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     h L contribution
                HpengTauEEECL0 = HpengTauEEECL0 - 2.0*piconst*(SLTAU(0)/(mE*mE-mTAU*mTAU)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(0)/(mTAU*mTAU-mE*mE)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H R contribution
                HpengTauEEECR1 = HpengTauEEECR1 - 2.0*piconst*(SRTAU(1)/(mE*mE-mTAU*mTAU)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(1)/(mTAU*mTAU-mE*mE)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     H L contribution
                HpengTauEEECL1 = HpengTauEEECL1 - 2.0*piconst*(SLTAU(1)/(mE*mE-mTAU*mTAU)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(1)/(mTAU*mTAU-mE*mE)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A R contribution
                HpengTauEEECR2 = HpengTauEEECR2 - 2.0*piconst*(SRTAU(2)/(mE*mE-mTAU*mTAU)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SRE(2)/(mTAU*mTAU-mE*mE)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
                //     A L contribution
                HpengTauEEECL2 = HpengTauEEECL2 - 2.0*piconst*(SLTAU(2)/(mE*mE-mTAU*mTAU)*(-CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mE*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CRlE(a,x)*CRlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x)))
                                                             +SLE(2)/(mTAU*mTAU-mE*mE)*(-CRlE(a,x)*CRlTAU(a,x).conjugate()*mTAU*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CRlE(a,x)*CLlTAU(a,x).conjugate()*mTAU*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      -CLlE(a,x)*CLlTAU(a,x).conjugate()*mE*mTAU*PV.B1(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))
                                                                                      +CLlE(a,x)*CRlTAU(a,x).conjugate()*mE*MChi(a)*PV.B0(1.,0.,MChi(a)*MChi(a),mym_sn_sq(x))));
           }
        }

        //     summing up the h (0), H (1) and A (2) parts
        gslpp::complex B2HiggscRte = (-0.5*HpengTauEEECR0*SLE(0)/(mh*mh)-0.5*HpengTauEEECR1*SLE(1)/(mH*mH)-0.5*HpengTauEEECR2*SLE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B2HiggscLte = (-0.5*HpengTauEEECL0*SRE(0)/(mh*mh)-0.5*HpengTauEEECL1*SRE(1)/(mH*mH)-0.5*HpengTauEEECL2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscRte = (HpengTauEEECR0*SRE(0)/(mh*mh)+HpengTauEEECR1*SRE(1)/(mH*mH)+HpengTauEEECR2*SRE(2)/(mA*mA))/(4.0*pi*alph);
        gslpp::complex B3HiggscLte = (HpengTauEEECL0*SLE(0)/(mh*mh)+HpengTauEEECL1*SLE(1)/(mH*mH)+HpengTauEEECL2*SLE(2)/(mA*mA))/(4.0*pi*alph);

        //     write B2H and B3H into a vector for tau->3e
        BHFunctions.assign(0, B2HiggsnRte+B2HiggscRte );
        BHFunctions.assign(1, B2HiggsnLte+B2HiggscLte );
        BHFunctions.assign(2, B3HiggsnRte+B3HiggscRte );
        BHFunctions.assign(3, B3HiggsnLte+B3HiggscLte );
    }

    return(BHFunctions);
}

gslpp::vector<gslpp::complex> SUSYMatching::DFunctions() {
        //box contributions to mu->e conversion

    NeutralinoRemixing();

    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mUP = mySUSY.getQuarks(QCD::UP).getMass();
    double mDOWN = mySUSY.getQuarks(QCD::DOWN).getMass();
    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);
    double alph = mySUSY.getAle();

    gslpp::vector<gslpp::complex> DFunctions(4, 0.);
    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlE.assign(a, x, - (g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 0) + (mE/cdenn)*ON(a, 2)*myRl(x, 3)));
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            NRqUP.assign(a, x, -(g2t)*((ON(a, 1)+ON(a, 0)*ttw/3.0)*myRu(x, 0)+mUP/(MW*sinb)*ON(a, 3)*myRu(x, 3)));
            NRqDOWN.assign(a, x, -(g2t)*((-ON(a, 1)+ON(a, 0)*ttw/3.0)*myRd(x, 0)+mDOWN/(MW*cosb)*ON(a, 2)*myRd(x, 3)));
            //     RL + RR TYPE MI
            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2)*myRl(x, 0) + 2.0*ON(a, 0)*ttw*myRl(x, 3)));
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
            NLqUP.assign(a, x, -(g2t)*(mUP/(MW*sinb)*ON(a, 3)*myRu(x, 0)-4.0*ON(a, 0)*myRu(x, 3)*ttw/3.0));
            NLqDOWN.assign(a, x, -(g2t)*(mDOWN/(MW*cosb)*ON(a, 2)*myRd(x, 0)+2.0*ON(a, 0)*myRd(x, 3)*ttw/3.0));
        }
    }
    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlE.assign(a, x, - (g2*myV(a, 0)*myRn(x, 0)));
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            //     LR-TYPE
            CLlE.assign(a, x, g2*mE/cdenc*myU(a, 1).conjugate()*myRn(x, 0));
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
        }
    }
    for (int a=0;a<2;a++) {
        for (int x=0;x<6;x++) {
            //     LL-TYPE
            CRqUP.assign(a, x, g2*(-myU(a, 0)*myRd(x, 0) + mDOWN/cdenc*myU(a, 1)*myRd(x, 3)));
            CRqDOWN.assign(a, x, g2*(-myV(a, 0)*myRu(x, 0) + mUP/(sqrt(2.0)*MW*sinb)*myV(a, 1)*myRu(x, 3)));
            //     LR-TYPE
            CLqUP.assign(a, x, g2*mUP/(sqrt(2.0)*MW*sinb)*myV(a, 1)*myRd(x, 0));
            CLqDOWN.assign(a, x, g2*mDOWN/cdenc*myU(a, 1)*myRu(x, 0));
        }
    }

    //     Neutralino contributions
    gslpp::complex DunR = 0.0;
    gslpp::complex DunL = 0.0;
    gslpp::complex DdnR = 0.0;
    gslpp::complex DdnL = 0.0;
    for (int a=0;a<4;a++) {
        for (int b=0;b<4;b++) {
            for (int x=0;x<6;x++) {
                for (int y=0;y<6;y++) {
                    DunR = DunR + (0.125*(NLlMU(a,x).conjugate()*NLlE(b,x)*NLqUP(a,y)*NLqUP(b,y).conjugate()
                                          -NLlMU(a,x).conjugate()*NLlE(b,x)*NRqUP(a,y).conjugate()*NRqUP(b,y))
                                         *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_su_sq(y))/(4.0*pi*pi)
                                   -0.25*MNeig(a)*MNeig(b)*(NLlMU(a,x).conjugate()*NLlE(b,x)*NRqUP(a,y)*NRqUP(b,y).conjugate()
                                                            -NLlMU(a,x).conjugate()*NLlE(b,x)*NLqUP(a,y).conjugate()*NLqUP(b,y))
                                                           *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_su_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DunL = DunL + (0.125*(NRlMU(a,x).conjugate()*NRlE(b,x)*NRqUP(a,y)*NRqUP(b,y).conjugate()
                                          -NRlMU(a,x).conjugate()*NRlE(b,x)*NLqUP(a,y).conjugate()*NLqUP(b,y))
                                         *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_su_sq(y))/(4.0*pi*pi)
                                   -0.25*MNeig(a)*MNeig(b)*(NRlMU(a,x).conjugate()*NRlE(b,x)*NLqUP(a,y)*NLqUP(b,y).conjugate()
                                                            -NRlMU(a,x).conjugate()*NRlE(b,x)*NRqUP(a,y).conjugate()*NRqUP(b,y))
                                                           *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_su_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DdnR = DdnR + (0.125*(NLlMU(a,x).conjugate()*NLlE(b,x)*NLqDOWN(a,y)*NLqDOWN(b,y).conjugate()
                                          -NLlMU(a,x).conjugate()*NLlE(b,x)*NRqDOWN(a,y).conjugate()*NRqDOWN(b,y))
                                         *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_sd_sq(y))/(4.0*pi*pi)
                                   -0.25*MNeig(a)*MNeig(b)*(NLlMU(a,x).conjugate()*NLlE(b,x)*NRqDOWN(a,y)*NRqDOWN(b,y).conjugate()
                                                            -NLlMU(a,x).conjugate()*NLlE(b,x)*NLqDOWN(a,y).conjugate()*NLqDOWN(b,y))
                                                           *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_sd_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DdnL = DdnL + (0.125*(NRlMU(a,x).conjugate()*NRlE(b,x)*NRqDOWN(a,y)*NRqDOWN(b,y).conjugate()
                                          -NRlMU(a,x).conjugate()*NRlE(b,x)*NLqDOWN(a,y).conjugate()*NLqDOWN(b,y))
                                         *PV.D00(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_sd_sq(y))/(4.0*pi*pi)
                                   -0.25*MNeig(a)*MNeig(b)*(NRlMU(a,x).conjugate()*NRlE(b,x)*NLqDOWN(a,y)*NLqDOWN(b,y).conjugate()
                                                            -NRlMU(a,x).conjugate()*NRlE(b,x)*NRqDOWN(a,y).conjugate()*NRqDOWN(b,y))
                                                           *PV.D0(0., 0., MNeig(a)*MNeig(a), MNeig(b)*MNeig(b), mym_se_sq(x), mym_sd_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                }
            }
        }
    }

    //     Chargino contributions
    gslpp::complex DucR = 0.0;
    gslpp::complex DucL = 0.0;
    gslpp::complex DdcR = 0.0;
    gslpp::complex DdcL = 0.0;
    for (int a=0;a<2;a++) {
        for (int b=0;b<2;b++) {
            for (int x=0;x<3;x++) {
                for (int y=0;y<6;y++) {
                    DucR = DucR + (-0.125*CLlMU(a,x).conjugate()*CLlE(b,x)*CRqUP(a,y).conjugate()*CRqUP(b,y)
                                   *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sd_sq(y))/(4.0*pi*pi)
                                   +0.25*MChi(a)*MChi(b)*CLlMU(a,x).conjugate()*CLlE(b,x)*CLqUP(a,y).conjugate()*CLqUP(b,y)
                                   *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sd_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DucL = DucL + (-0.125*CRlMU(a,x).conjugate()*CRlE(b,x)*CLqUP(a,y).conjugate()*CLqUP(b,y)
                                   *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sd_sq(y))/(4.0*pi*pi)
                                   +0.25*MChi(a)*MChi(b)*CRlMU(a,x).conjugate()*CRlE(b,x)*CRqUP(a,y).conjugate()*CRqUP(b,y)
                                   *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_sd_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DdcR = DdcR + (0.125*CLlMU(a,x).conjugate()*CLlE(b,x)*CLqDOWN(a,y)*CLqDOWN(b,y).conjugate()
                                   *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_su_sq(y))/(4.0*pi*pi)
                                   -0.25*MChi(a)*MChi(b)*CLlMU(a,x).conjugate()*CLlE(b,x)*CRqDOWN(a,y)*CRqDOWN(b,y).conjugate()
                                   *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_su_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                    DdcL = DdcL + (0.125*CRlMU(a,x).conjugate()*CRlE(b,x)*CRqDOWN(a,y)*CRqDOWN(b,y).conjugate()
                                   *PV.D00(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_su_sq(y))/(4.0*pi*pi)
                                   -0.25*MChi(a)*MChi(b)*CRlMU(a,x).conjugate()*CRlE(b,x)*CLqDOWN(a,y)*CLqDOWN(b,y).conjugate()
                                   *PV.D0(0., 0., MChi(a)*MChi(a), MChi(b)*MChi(b), mym_sn_sq(x), mym_su_sq(y))/(16.0*pi*pi))/(4.0*pi*alph);
                }
            }
        }
    }

    //     write DuR, DuL, DdR and DdL into a vector for mu->e conversion
    DFunctions.assign(0, DunR+DucR );  //DuR
    DFunctions.assign(1, DunL+DucL );  //DuL
    DFunctions.assign(2, DdnR+DdcR );  //DdR
    DFunctions.assign(3, DdnL+DdcL );  //DdL

    return(DFunctions);
}

gslpp::vector<gslpp::complex> SUSYMatching::FFunctions(int li_to_lj) {
        //Z penguin contributions

    NeutralinoRemixing();

    double MZ = mySUSY.getMz();
    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double piconst = 1.0/(32.0 * pi * pi);
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mTAU = mySUSY.getLeptons(StandardModel::TAU).getMass();

    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);

    gslpp::vector<gslpp::complex> FFunctions(4, 0.);
//      Note: Here contributions proportional to the Yukawa couplings are set to 
//      zero. In particular this leads to Right Chargino Contributions to be zero. 

    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlE.assign(a, x, - (g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 0) + (mE/cdenn)*ON(a, 2)*myRl(x, 3)));
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            NRlTAU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 2) + (mTAU/cdenn)*ON(a, 2)*myRl(x, 5)));
            //     RL + RR TYPE MI
            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2)*myRl(x, 0) + 2.0*ON(a, 0)*ttw*myRl(x, 3)));
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2)*myRl(x, 2) + 2.0*ON(a, 0)*ttw*myRl(x, 5)));
//    Commented expressions might be useful for complex neutralino mixing matrices
//            NLlE.assign(a, x, -(g2t)*((mE/cdenn)*ON(a, 2).conjugate()*myRl(x, 0) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 3)));
//            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2).conjugate()*myRl(x, 1) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 4)));
//            NLlTAU.assign(a, x, -(g2t)*((mTAU/cdenn)*ON(a, 2).conjugate()*myRl(x, 2) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 5)));
        }
    }

    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlE.assign(a, x, - (g2*myV(a, 0)*myRn(x, 0)));
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            CRlTAU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 2)));
            //     LR-TYPE
            CLlE.assign(a, x, g2*mE/cdenc*myU(a, 1).conjugate()*myRn(x, 0));
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
            CLlTAU.assign(a, x, g2*mTAU/cdenc*myU(a, 1).conjugate()*myRn(x, 2));
        }
    }

//      Neutralino contributions

    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            Lepty.assign(a, x, ( MNeig(a) * MNeig(a) ) / mym_se_sq(x) );
        }
    }

    for (int x=0;x<6;x++) {
        for (int a=0;a<4;a++) {
            for (int b=0;b<4;b++) {
                if (a != b && std::fabs(Lepty(a,x)-Lepty(b,x)) > 0.01 && std::fabs(1.0-Lepty(a,x)) > 0.01 && std::fabs(1.0-Lepty(b,x)) > 0.01) {
                    Leptfzn[x][a][b] = log(Lepty(a,x)) + 1.0/(Lepty(a,x)-Lepty(b,x))*
                                     ( (Lepty(a,x)*Lepty(a,x)*log(Lepty(a,x)))/(1.0-Lepty(a,x)) - (Lepty(b,x)*Lepty(b,x)*log(Lepty(b,x)))/(1.0-Lepty(b,x)) );
                    Leptgzn[x][a][b] = (MNeig(a)*MNeig(b)/mym_se_sq(x))/(Lepty(a,x)-Lepty(b,x))*
                                     ( (Lepty(a,x)*log(Lepty(a,x)))/(1.0-Lepty(a,x)) - (Lepty(b,x)*log(Lepty(b,x)))/(1.0-Lepty(b,x)) );
                }
                else if (a != b && std::fabs(Lepty(a,x)-Lepty(b,x)) > 0.01 && std::fabs(1.0-Lepty(a,x)) > 0.01 && std::fabs(1.0-Lepty(b,x)) <= 0.01) {
                    Leptfzn[x][a][b] = (-2.0*log(Lepty(a,x))*Lepty(a,x)+log(Lepty(a,x))+Lepty(a,x)-1.0)/(Lepty(a,x)-1.0)/(Lepty(a,x)-1.0);
                    Leptgzn[x][a][b] = -(MNeig(a)*MNeig(b)/mym_se_sq(x))*(log(Lepty(a,x))*Lepty(a,x)-Lepty(a,x)+1.0)/(Lepty(a,x)-1.0)/(Lepty(a,x)-1.0);
                }
                else if (a != b && std::fabs(Lepty(a,x)-Lepty(b,x)) > 0.01 && std::fabs(1.0-Lepty(b,x)) > 0.01 && std::fabs(1.0-Lepty(a,x)) <= 0.01) {
                    Leptfzn[x][a][b] = (-log(Lepty(b,x))*Lepty(b,x)*Lepty(b,x)+Lepty(b,x)-1.0)/(Lepty(b,x)-1.0)/(Lepty(b,x)-1.0); 
                    Leptgzn[x][a][b] = -(MNeig(a)*MNeig(b)/mym_se_sq(x))*(log(Lepty(b,x))*Lepty(b,x)-Lepty(b,x)+1.0)/(Lepty(b,x)-1.0)/(Lepty(b,x)-1.0);
                }
                else if ((a == b || std::fabs(Lepty(a,x)-Lepty(b,x)) <= 0.01) && std::fabs(1.0-Lepty(a,x)) > 0.01 && std::fabs(1.0-Lepty(b,x)) > 0.01) {
                    Leptfzn[x][a][b] = (-Lepty(a,x)*Lepty(a,x)+Lepty(a,x)+log(Lepty(a,x)))/(Lepty(a,x)-1.0)/(Lepty(a,x)-1.0);
                    Leptgzn[x][a][b] = (MNeig(b)*MNeig(b)/mym_se_sq(x))*(-Lepty(a,x)+log(Lepty(a,x))+1.0)/(Lepty(a,x)-1.0)/(Lepty(a,x)-1.0);
                }
                else {
                    Leptfzn[x][a][b] = -3.0/2.0-(Lepty(a,x)-1.0)/3.0;
                    Leptgzn[x][a][b] = -MNeig(a)*MNeig(b)/(2.0*mym_se_sq(x));
                }
            }
        }
    }

//      Chargino contributions
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            Leptz.assign(a, x, MChi(a)*MChi(a)/mym_sn_sq(x) );
        }
    }

    for (int x=0;x<3;x++) {
        for (int a=0;a<2;a++) {
            for (int b=0;b<2;b++) {
                if (a != b && std::fabs(Leptz(a,x)-Leptz(b,x)) > 0.01 && std::fabs(1.0-Leptz(a,x)) > 0.01 && std::fabs(1.0-Leptz(b,x)) > 0.01) {
                    Leptfzc[x][a][b] = log(Leptz(a,x)) + 1.0/(Leptz(a,x)-Leptz(b,x))*
                                     ( (Leptz(a,x)*Leptz(a,x)*log(Leptz(a,x)))/(1.0-Leptz(a,x)) - (Leptz(b,x)*Leptz(b,x)*log(Leptz(b,x)))/(1.0-Leptz(b,x)) );
                    Leptgzc[x][a][b] = (MChi(a)*MChi(b)/mym_sn_sq(x))/(Leptz(a,x)-Leptz(b,x))*
                                     ( (Leptz(a,x)*log(Leptz(a,x)))/(1.0-Leptz(a,x)) - (Leptz(b,x)*log(Leptz(b,x)))/(1.0-Leptz(b,x)) );
                }
                else if (a != b && std::fabs(Leptz(a,x)-Leptz(b,x)) > 0.01 && std::fabs(1.0-Leptz(a,x)) > 0.01 && std::fabs(1.0-Leptz(b,x)) <= 0.01) {
                    Leptfzc[x][a][b] = (-2.0*log(Leptz(a,x))*Leptz(a,x)+Leptz(a,x)+log(Leptz(a,x))-1.0)/(Leptz(a,x)-1.0)/(Leptz(a,x)-1.0);
                    Leptgzc[x][a][b] = -(MChi(a)*MChi(b)/mym_sn_sq(x))*(log(Leptz(a,x))*Leptz(a,x)-Leptz(a,x)+1.0)/(Leptz(a,x)-1.0)/(Leptz(a,x)-1.0);
                }
                else if (a != b && std::fabs(Leptz(a,x)-Leptz(b,x)) > 0.01 && std::fabs(1.0-Leptz(b,x)) > 0.01 && std::fabs(1.0-Leptz(a,x)) <= 0.01) {
                    Leptfzc[x][a][b] = (-log(Leptz(b,x))*Leptz(b,x)*Leptz(b,x)+Leptz(b,x)-1.0)/(Leptz(b,x)-1.0)/(Leptz(b,x)-1.0);
                    Leptgzc[x][a][b] = -(MChi(a)*MChi(b)/mym_sn_sq(x))*(log(Leptz(b,x))*Leptz(b,x)-Leptz(b,x)+1.0)/(Leptz(b,x)-1.0)/(Leptz(b,x)-1.0);
                }
                else if ((a == b || std::fabs(Leptz(a,x)-Leptz(b,x)) <= 0.01) && std::fabs(1.0-Leptz(a,x)) > 0.01 && std::fabs(1.0-Leptz(b,x)) > 0.01) {
                    Leptfzc[x][a][b] = (-Leptz(a,x)*Leptz(a,x)+Leptz(a,x)+log(Leptz(a,x)))/(Leptz(a,x)-1.0)/(Leptz(a,x)-1.0);
                    Leptgzc[x][a][b] = (MChi(b)*MChi(b)/mym_sn_sq(x))*((-Leptz(a,x)+log(Leptz(a,x))+1.0))/(Leptz(a,x)-1.0)/(Leptz(a,x)-1.0);
                }
                else {
                    Leptfzc[x][a][b] = -3.0/2.0-(Leptz(a,x)-1.0)/3.0;
                    Leptgzc[x][a][b] = -MChi(a)*MChi(b)/(2.0*mym_sn_sq(x));
                }
            }
        }
    }

    if (li_to_lj == 1) // mu -> 3e
    {
        //     Neutralino contributions
        gslpp::complex ZpengMuEEENR = 0.0;
        gslpp::complex ZpengMuEEENL = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    ZpengMuEEENR = ZpengMuEEENR - NLlE(a,x)*NLlMU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                    ZpengMuEEENL = ZpengMuEEENL + NRlE(a,x)*NRlMU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                }
            }
        }
        //     Chargino contributions
        gslpp::complex ZpengMuEEEC = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    ZpengMuEEEC = ZpengMuEEEC + CRlE(a,x)*CRlMU(b,x)*piconst*
                                                    (myU(a,1)*myU(b,1)*gslpp::complex(std::real(Leptgzc[x][a][b]),std::imag(Leptgzc[x][a][b]))
                                                     -myV(a,1)*myV(b,1)*gslpp::complex(std::real(Leptfzc[x][a][b]),std::imag(Leptfzc[x][a][b]))/2.0);
                }
            }
        }
        //     write FRR, FRL, FLR and FLL into a vector for mu->3e
        FFunctions.assign(0, ZpengMuEEENR/(MZ*MZ*ctw*ctw) );                                 //FRR
        FFunctions.assign(1, ZpengMuEEENR*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );                  //FRL
        FFunctions.assign(2, (ZpengMuEEENL + ZpengMuEEEC)/(MZ*MZ*ctw*ctw) );                 //FLR
        FFunctions.assign(3, (ZpengMuEEENL + ZpengMuEEEC)*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );  //FLL
    }
    if (li_to_lj == 2) // tau -> 3mu
    {
        //     Neutralino contributions
        gslpp::complex ZpengTauMuMuMuNR = 0.0;
        gslpp::complex ZpengTauMuMuMuNL = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    ZpengTauMuMuMuNR = ZpengTauMuMuMuNR - NLlMU(a,x)*NLlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                    ZpengTauMuMuMuNL = ZpengTauMuMuMuNL + NRlMU(a,x)*NRlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                }
            }
        }
        //     Chargino contributions
        gslpp::complex ZpengTauMuMuMuC = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    ZpengTauMuMuMuC = ZpengTauMuMuMuC + CRlMU(a,x)*CRlTAU(b,x)*piconst*
                                                    (myU(a,1)*myU(b,1)*gslpp::complex(std::real(Leptgzc[x][a][b]),std::imag(Leptgzc[x][a][b]))
                                                     -myV(a,1)*myV(b,1)*gslpp::complex(std::real(Leptfzc[x][a][b]),std::imag(Leptfzc[x][a][b]))/2.0);
                }
            }
        }
        //     write FRR, FRL, FLR and FLL into a vector for tau->3mu
        FFunctions.assign(0, ZpengTauMuMuMuNR/(MZ*MZ*ctw*ctw) );                                     //FRR
        FFunctions.assign(1, ZpengTauMuMuMuNR*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );                      //FRL
        FFunctions.assign(2, (ZpengTauMuMuMuNL + ZpengTauMuMuMuC)/(MZ*MZ*ctw*ctw) );                 //FLR
        FFunctions.assign(3, (ZpengTauMuMuMuNL + ZpengTauMuMuMuC)*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );  //FLL
    }
    if (li_to_lj == 3) // tau -> 3e
    {
        //      Neutralino contributions
        gslpp::complex ZpengTauEEENR = 0.0;
        gslpp::complex ZpengTauEEENL = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    ZpengTauEEENR = ZpengTauEEENR - NLlE(a,x)*NLlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                    ZpengTauEEENL = ZpengTauEEENL + NRlE(a,x)*NRlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                }
            }
        }
        //      Chargino contributions
        gslpp::complex ZpengTauEEEC = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    ZpengTauEEEC = ZpengTauEEEC + CRlE(a,x)*CRlTAU(b,x)*piconst*
                                                    (myU(a,1)*myU(b,1)*gslpp::complex(std::real(Leptgzc[x][a][b]),std::imag(Leptgzc[x][a][b]))
                                                     -myV(a,1)*myV(b,1)*gslpp::complex(std::real(Leptfzc[x][a][b]),std::imag(Leptfzc[x][a][b]))/2.0);
                }
            }
        }
        //     write FRR, FRL, FLR and FLL into a vector for tau->3e
        FFunctions.assign(0, ZpengTauEEENR/(MZ*MZ*ctw*ctw) );                                  //FRR
        FFunctions.assign(1, ZpengTauEEENR*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );                   //FRL
        FFunctions.assign(2, (ZpengTauEEENL + ZpengTauEEEC)/(MZ*MZ*ctw*ctw) );                 //FLR
        FFunctions.assign(3, (ZpengTauEEENL + ZpengTauEEEC)*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );  //FLL
    }
    if (li_to_lj == 4) // tau -> muee
    {
        //     Neutralino contributions
        gslpp::complex ZpengTauMuEENR = 0.0;
        gslpp::complex ZpengTauMuEENL = 0.0;
        for (int x=0;x<6;x++) {
            for (int a=0;a<4;a++) {
                for (int b=0;b<4;b++) {
                    ZpengTauMuEENR = ZpengTauMuEENR - NLlMU(a,x)*NLlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                    ZpengTauMuEENL = ZpengTauMuEENL + NRlMU(a,x)*NRlTAU(b,x)*piconst*
                                                    (ON(a,2)*ON(b,2)-ON(a,3)*ON(b,3))*gslpp::complex(std::real(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]),std::imag(Leptfzn[x][a][b]+2.0*Leptgzn[x][a][b]));
                }
            }
        }
        //     Chargino contributions
        gslpp::complex ZpengTauMuEEC = 0.0;
        for (int x=0;x<3;x++) {
            for (int a=0;a<2;a++) {
                for (int b=0;b<2;b++) {
                    ZpengTauMuEEC = ZpengTauMuEEC + CRlMU(a,x)*CRlTAU(b,x)*piconst*
                                                    (myU(a,1)*myU(b,1)*gslpp::complex(std::real(Leptgzc[x][a][b]),std::imag(Leptgzc[x][a][b]))
                                                     -myV(a,1)*myV(b,1)*gslpp::complex(std::real(Leptfzc[x][a][b]),std::imag(Leptfzc[x][a][b]))/2.0);
                }
            }
        }
        //     write FRR, FRL, FLR and FLL into a vector for tau->muee
        FFunctions.assign(0, ZpengTauMuEENR/(MZ*MZ*ctw*ctw) );                                   //FRR
        FFunctions.assign(1, ZpengTauMuEENR*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );                    //FRL
        FFunctions.assign(2, (ZpengTauMuEENL + ZpengTauMuEEC)/(MZ*MZ*ctw*ctw) );                 //FLR
        FFunctions.assign(3, (ZpengTauMuEENL + ZpengTauMuEEC)*(-0.5+sw2)/(MZ*MZ*sw2*ctw*ctw) );  //FLL
    }

    return(FFunctions);
}

gslpp::vector<gslpp::complex> SUSYMatching::gminus2mu() {

    NeutralinoRemixing();

    double MW = mySUSY.Mw_tree();
    double pi = M_PI;
    double piconst = 1.0/(32.0 * pi * pi);
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double stw = sqrt(sw2);
    double ctw = sqrt(1.0 - sw2);
    double ttw = stw/ctw;
    double mMU = mySUSY.getLeptons(StandardModel::MU).getMass();

    double cdenc = sqrt(2.0)*MW*cosb;
    double cdenn = MW*cosb;
    double g2 = gW;
    double g2t = g2/sqrt(2.0);

    gslpp::vector<gslpp::complex> gminus2mu(2, 0.);

    //     Neutralino-Fermion-Sfermion couplings
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            //     LL + RL TYPE MI
            NRlMU.assign(a, x, -(g2t)*((-ON(a, 1) - ON(a, 0)*ttw)*myRl(x, 1) + (mMU/cdenn)*ON(a, 2)*myRl(x, 4)));
            //     RL + RR TYPE MI
            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2)*myRl(x, 1) + 2.0*ON(a, 0)*ttw*myRl(x, 4)));
//    Commented expressions might be useful for complex neutralino mixing matrices
//            NLlMU.assign(a, x, -(g2t)*((mMU/cdenn)*ON(a, 2).conjugate()*myRl(x, 1) + 2.0*ON(a, 0).conjugate()*ttw*myRl(x, 4)));
        }
    }

    //     Chargino-Fermion-Sfermion couplings
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            //     LL-TYPE
            CRlMU.assign(a, x, - (g2*myV(a, 0)*myRn(x, 1)));
            //     LR-TYPE
            CLlMU.assign(a, x, g2*mMU/cdenc*myU(a, 1).conjugate()*myRn(x, 1));
        }
    }

    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            Lepty.assign(a, x, MNeig(a) * MNeig(a) / mym_se_sq(x) );
        }
    }

    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            Leptz.assign(a, x, MChi(a) * MChi(a) / mym_sn_sq(x) );
        }
    }

    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            if (fabs(1.0 - Lepty(a, x)) > 0.01) {
                Leptf1.assign(a, x, ((1.0 - 6.0*Lepty(a, x) + 3.0 * pow(Lepty(a, x),2.0) + 
                                      2.0*pow(Lepty(a, x),3.0) - 6.0*pow(Lepty(a,x),2.0)*log(Lepty(a, x))))/
                                    (6.0 * pow((1.0 - Lepty(a,x)),4.0)) );
                Leptf2.assign(a, x, (1.0 - pow(Lepty(a, x),2.0) +  2.0 * Lepty(a, x) * log(Lepty(a, x)))/
                                    (pow((1.0-Lepty(a, x)),3.0)));
            }
            else {
                Leptf1.assign(a, x, 1.0/12.0 - (Lepty(a, x) - 1.0)/30.0);
                Leptf2.assign(a, x, 1.0/3.0 - (Lepty(a, x) - 1.0)/6.0);
            }
        }
    }

    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            if(fabs(1.0-Leptz(a, x)) > 0.01) {
                Leptf3.assign(a, x, ((2.0 + 3.0*Leptz(a, x) - 6.0*pow(Leptz(a, x),2.0) 
                                      + pow(Leptz(a, x),3.0) + 6.0*Leptz(a, x)*log(Leptz(a, x)))/
		                     (6.0*pow((1.0 - Leptz(a, x)),4.0))) );
                Leptf4.assign(a, x, ((-3.0 + 4.0*Leptz(a, x) - pow(Leptz(a, x),2.0)
                                      - 2.0*log(Leptz(a, x)))/
                                     pow((1.0 - Leptz(a, x)),3.0)) );
            }
            else {
                Leptf3.assign(a, x, 1.0/12.0 - (Leptz(a, x) - 1.0)/20.0 );
                Leptf4.assign(a, x, 2.0/3.0 - (Leptz(a, x) - 1.0)/2.0 );
            }
        }
    }

    //      Neutralino contributions
    gslpp::complex g2ARN = 0.0;
    gslpp::complex g2ALN = 0.0;
    for (int a=0;a<4;a++) {
        for (int x=0;x<6;x++) {
            g2ARN = g2ARN -mMU*mMU*piconst*(4.0*NRlMU(a,x)*NRlMU(a,x).conjugate()*Leptf1(a,x)
                                            +2.0*NRlMU(a,x)*NLlMU(a,x).conjugate()*(MNeig(a)/mMU)*Leptf2(a,x))/mym_se_sq(x);
            g2ALN = g2ALN -mMU*mMU*piconst*(4.0*NLlMU(a,x)*NLlMU(a,x).conjugate()*Leptf1(a,x)
                                            +2.0*NLlMU(a,x)*NRlMU(a,x).conjugate()*(MNeig(a)/mMU)*Leptf2(a,x))/mym_se_sq(x);
        }
    }

    //      Chargino contributions
    gslpp::complex g2ARC = 0.0;
    gslpp::complex g2ALC = 0.0;
    for (int a=0;a<2;a++) {
        for (int x=0;x<3;x++) {
            g2ARC = g2ARC +mMU*mMU*piconst*(4.0*CRlMU(a,x)*CRlMU(a,x).conjugate()*Leptf3(a,x)
                                            +2.0*CRlMU(a,x)*CLlMU(a,x).conjugate()*(MChi(a)/mMU)*Leptf4(a,x))/mym_sn_sq(x);
            g2ALC = g2ALC +mMU*mMU*piconst*(4.0*CLlMU(a,x)*CLlMU(a,x).conjugate()*Leptf3(a,x)
                                            +2.0*CLlMU(a,x)*CRlMU(a,x).conjugate()*(MChi(a)/mMU)*Leptf4(a,x))/mym_sn_sq(x);
        }
    }

    //     write R and L contributions to the muon g-2 into a vector
    gminus2mu.assign(0, g2ARN + g2ARC );    //g-2_muR
    gminus2mu.assign(1, g2ALN + g2ALC );    //g-2_muL

//    std::cout<<"g2AN="<<g2ARN+g2ALN <<std::endl;
//    std::cout<<"g2AC="<<g2ARC+g2ALC <<std::endl;

    return(gminus2mu);
}

struct __fPS_params{
  double a;
};

double __fPS_integ(double x, void* p){
  __fPS_params &params= *reinterpret_cast<__fPS_params *>(p);
  double r = params.a*log(x*(1.-x)/params.a) / (x*(1.-x)-params.a);
  return r;
}

double SUSYMatching::fPS(double x){

    __fPS_params params;
    params.a=x;

    double result;
    gsl_integration_glfixed_table * w
        = gsl_integration_glfixed_table_alloc(100);
    gsl_function F;

    F.function = &__fPS_integ;
    F.params = reinterpret_cast<void *>(&params);

    result = gsl_integration_glfixed (&F, 0, 1, w);

    gsl_integration_glfixed_table_free (w);

  return result;
}

double SUSYMatching::fS(double x){

    double r=0;
    r=(2.*x-1.)*fPS(x)-2.*x*(2.+log(x));
    return r;
}

double SUSYMatching::fft(double x){

    double r=0;
    r=x*(2.+log(x)-fPS(x))/2.0;
    return r;
}

double SUSYMatching::It(double a, double b, double c){

    double r=0;
    if (std::fabs(a-b) < 0.0005 && std::fabs(a-c) < 0.0005 && std::fabs(b-c) < 0.0005)
    {
        r=9./(2.*(a+b+c)*(a+b+c));
    }
    else
    {
        if (std::fabs(a-b) < 0.0005)
        {
            if (std::fabs(a-c) < 0.0005)
            {
                r=(-4.*(4.*b*b*c*c*log(b*b/(c*c)) 
                        +((b+c)*(b+c))*(c*c*log((4.*c*c)/((b+c)*(b+c))) 
                            + b*b*log(((b+c)*(b+c))/(4.*b*b)))))
                  /(pow(b-c,3)*(b+c)*(3.*b+c)*(b+3.*c));
            }
            else
            {
                if (std::fabs(b-c) < 0.0005)
                {
                    r=(4.*(pow(a-2.*b+c,2)*(-3.*pow(a,8) - 46.*pow(a,7)*c - 42.*pow(a,6)*c*c + 234.*pow(a,5)*c*c*c
                                            - 234.*a*a*a*pow(c,5) + 42.*a*a*pow(c,6) + 46.*a*pow(c,7) + 3.*pow(c,8)
                                            + 8.*a*a*c*c*(11.*pow(a,4) + 28.*a*a*a*c + 50.*a*a*c*c + 28.*a*c*c*c + 11.*pow(c,4))
                                                *log(c*c/(a*a))
                                            + a*a*(7.*pow(a,6) + 62.*pow(a,5)*c + 265.*pow(a,4)*c*c
                                                   + 356.*a*a*a*c*c*c + 265.*a*a*pow(c,4) + 62.*a*pow(c,5) + 7.*pow(c,6))
                                                *log((4.*a*a)/((a+c)*(a+c)))
                                            + 7.*pow(a,6)*c*c*log(((a+c)*(a+c))/(4.*c*c))
                                            + 62.*pow(a,5)*c*c*c*log(((a+c)*(a+c))/(4.*c*c))
                                            + 265.*pow(a,4)*pow(c,4)*log(((a+c)*(a+c))/(4.*c*c))
                                            + 356.*a*a*a*pow(c,5)*log(((a+c)*(a+c))/(4.*c*c))
                                            + 265.*a*a*pow(c,6)*log(((a+c)*(a+c))/(4.*c*c))
                                            + 62.*a*pow(c,7)*log(((a+c)*(a+c))/(4.*c*c))
                                            + 7.*pow(c,8)*log(((a+c)*(a+c))/(4.*c*c)))
                           +((a-c)*(a-c))*pow(3.*a+c,2)*pow(a+3.*c,2)
                            *(4.*a*a*c*c*log((c*c)/(a*a))
                              +((a+c)*(a+c))*(a*a*log((4.*a*a)/((a+c)*(a+c))) + c*c*log(((a+c)*(a+c))/(4.*c*c))))))
                      /(pow(a-c,5)*(a+c)*pow(3.*a+c,3)*pow(a+3.*c,3));
                }
                else
                {
                    r=((b*b) - (c*c) - (c*c)*log((b*b)/(c*c)))/pow((b*b) - (c*c),2) + 
   ((a - b)*(-pow(b,4) + pow(c,4) + 2*(b*b)*(c*c)*log((b*b)/(c*c))))/(b*pow((b*b) - (c*c),3));
                }
            }
        }
        else
        {
            if (std::fabs(b-c) < 0.0005)
            {
                if (std::fabs(a-c) < 0.0005)
                {
                    r=(-4*(4*(a*a)*(b*b)*log((a*a)/(b*b)) + ((a+b)*(a+b))*((b*b)*log((4*(b*b))/((a+b)*(a+b))) + (a*a)*log(((a+b)*(a+b))/(4.*(a*a))))))/
(pow(a - b,3)*(a + b)*(3*a + b)*(a + 3*b));
                }
                else
                {
                    r=(-(a*a) + (c*c) - (a*a)*log((c*c)/(a*a)))/pow((a*a) - (c*c),2) + 
((b - c)*(pow(a,4) - pow(c,4) + 2*(a*a)*(c*c)*log((c*c)/(a*a))))/(c*pow(-(a*a) + (c*c),3));
                }
            }   
            else
            {
                if (std::fabs(a-c) < 0.0005)
                {
                    r=(-(b*b) + (c*c) + (b*b)*log((b*b)/(c*c)))/pow((b*b) - (c*c),2) + 
   ((a - c)*(pow(b,4) - pow(c,4) - 2*(b*b)*(c*c)*log((b*b)/(c*c))))/(c*pow(-(b*b) + (c*c),3));
                }
                else
                {
                    r=( a*a*b*b*log(a*a/(b*b))+b*b*c*c*log(b*b/(c*c))+c*c*a*a*log(c*c/(a*a)) )
                /( (a*a-b*b)*(b*b-c*c)*(a*a-c*c) );
                }
            }
        }

            
            
            
            
            
    }
    return r;
}

double SUSYMatching::F3C(double x){

    double r=0;
    if (std::fabs(x-1.) < 0.005)
    {
        r=1. + (1059.*(x-1.))/1175.;
    }
    else
    {
        r=(1. - x) * (151. * x*x - 335. * x + 592.)
          + 6. * (21. * x*x*x - 108. * x*x - 93. * x + 50.) * log(x)
          - 54. * x * (x*x - 2. * x - 2.) * pow(log(x),2)
          - 108. * x * (x*x - 2. * x + 12.) * Polylogs.Li2(1.- x).real() ;
        r*=4./(141.*pow(1. - x,4));
    }
    return r;
}

double SUSYMatching::F4C(double x){

    double r=0;
    if (std::fabs(x-1.) < 0.005)
    {
        r=1. - (45.*(x-1.))/122.;
    }
    else
    {
        r=8.*(x*x-3.*x+2.)+(11.*x*x-40.*x+5.)*log(x)
          -2.*(x*x-2.*x-2.)*log(x)*log(x)
          -4.*(x*x-2.*x+9.)*Polylogs.Li2(1.-x).real();
        r=r*(-9.)/(122.*pow(1-x,3));
    }
    return r;
}

double SUSYMatching::F3N(double x){

    double r=0;
    if (std::fabs(x-1.) < 0.005)
    {
        r=1. + (76.*(x-1.))/875.;
    }
    else
    {
        r=(1-x)*(-97.*x*x-529.*x+2.)+6.*x*x*(13.*x+81.)*log(x)
          +108.*x*(7.*x+4.)*Polylogs.Li2(1.-x).real();
        r=r*4./(105.*pow(1-x,4));
    }
    return r;
}

double SUSYMatching::F4N(double x){

    double r=0;
    if (std::fabs(x-1.) < 0.005)
    {
        r=1. - (111.*(x-1.)*(x-1.))/800.;
    }
    else
    {
        r=(x+3.)*(x*log(x)+x-1.0)+(6.*x+2.)*Polylogs.Li2(1.-x).real();
        r=r*(-9.)/(4.*pow(1-x,3));
    }
    return r;
}

double SUSYMatching::Fa(double x, double y){

    double r=0;
    if (std::fabs(x-y) < 0.005)
    {
        if (std::fabs(y-1.) < 0.005)
        {
            r=(49. - 22.*x - 22.*y + 10.*x*y)/60.;
        }
        else
        {
            r=(2. + 3.*x - 6.*x*x + x*x*x + 6.*x*log(x))/(4.*pow(x-1.,4)*x)
              +(2. + 3.*y - 6.*y*y + y*y*y + 6.*y*log(y))/(4.*pow(y-1.,4)*y);
        }
    }
    else
    {
        if (std::fabs(x-1.) < 0.005)
        {
            r=((x-1.)*(-25. + 48.*y - 36.*y*y + 16.*y*y*y - 3.*y*y*y*y - 12.*log(y)))/(12.*pow(y-1.,5))
                    + (-11. + 18.*y - 9.*y*y + 2.*y*y*y - 6.*log(y))/(6.*pow(y-1.,4));
        }
        else if (std::fabs(y-1.) < 0.005)
        {
            r=((y-1.)*(-25. + 48.*x - 36.*x*x + 16.*x*x*x - 3.*x*x*x*x - 12.*log(x)))/(12.*pow(x-1.,5))
                    + (-11. + 18.*x - 9.*x*x + 2.*x*x*x - 6.*log(x))/(6.*pow(x-1.,4));
        }
        else
        {
            double G3x, G3y;
            G3x=(1./(2.*pow(x-1,3))) *( (x-1)*(x-3)+2.*log(x) );
            G3y=(1./(2.*pow(y-1,3))) *( (y-1)*(y-3)+2.*log(y) );
            r=-(G3x-G3y)/(x-y);
        }
    }
    return r;
}

double SUSYMatching::Fb(double x, double y){

    double r=0;
    if (std::fabs(x-y) < 0.005)
    {
        if (std::fabs(y-1.) < 0.005)
        {
            r=(13. - 5.*x - 5.*y + 2.*x*y)/60.;
        }
        else
        {
            r=((2. + 3.*x - 6.*x*x + x*x*x + 6.*x*log(x))/pow(x-1.,4) 
               + (2. + 3.*y - 6.*y*y + y*y*y + 6.*y*log(y))/pow(y-1.,4))/12.;
        }
    }
    else
    {
        if (std::fabs(x-1.) < 0.005)
        {
            r=(2. + 3.*y - 6.*y*y + y*y*y + 6.*y*log(y))/(6.*pow(y-1.,4))
                    + ((x-1.)*(3. + 10.*y - 18.*y*y + 6.*y*y*y - y*y*y*y + 12.*y*log(y)))/(12.*pow(y-1.,5));
        }
        else if (std::fabs(y-1.) < 0.005)
        {
            r=(2. + 3.*x - 6.*x*x + x*x*x + 6.*x*log(x))/(6.*pow(x-1.,4))
                    + ((y-1.)*(3. + 10.*x - 18.*x*x + 6.*x*x*x - x*x*x*x + 12.*x*log(x)))/(12.*pow(x-1.,5));
        }
        else
        {
            double G4x, G4y;
            G4x=(1./(2.*pow(x-1,3))) *( (x-1)*(x+1) -2.*x*log(x) );
            G4y=(1./(2.*pow(y-1,3))) *( (y-1)*(y+1) -2.*y*log(y) );
            r=-(G4x-G4y)/(x-y);
        }
    }
    return r;
}

double SUSYMatching::gminus2muNLO() {

    updateSUSYParameters();

    double pi = M_PI;
    double MZ = mySUSY.getMz();
//    double g1atMZ = sqrt(4.0*pi*mySUSY.getAle());
//    double g2atMZ = gW;
    double g1atMZ = 0.357456;
    double g2atMZ = 0.651721;
    double g3atMZ = sqrt(4.0*pi*mySUSY.getAlsMz());
    double mh = mySUSY.getMHl();
    double mhh = mySUSY.getMHh();
    double ma = mySUSY.getMHa();
    gslpp::complex sa = mySUSY.getSaeff();
    gslpp::complex ca = sqrt(1.0-sa*sa);
    gslpp::complex s2a = 2.0*ca*sa;
    gslpp::complex c2a = ca*ca-sa*sa;
    double vew = v/sqrt(2.);
//    double mE = mySUSY.getLeptons(StandardModel::ELECTRON).getMass();
    double mmu = mySUSY.getLeptons(StandardModel::MU).getMass();
    double mTAU = mySUSY.getLeptons(StandardModel::TAU).getMass();
    double mt = mySUSY.getQuarks(mySUSY.TOP).getMass();
    double mb = mySUSY.getQuarks(mySUSY.BOTTOM).getMass();
    gslpp::complex M1 = mySUSY.getM1();
    gslpp::complex M2 = mySUSY.getM2();

    gslpp::complex muH = mySUSY.getMuH();
    TUhat = mySUSY.getTUhat();
    TDhat = mySUSY.getTDhat();
    TEhat = mySUSY.getTEhat();
    gslpp::complex a3t = TUhat(2,2)*mySUSY.v2()/sqrt(2.0)/mt;
    gslpp::complex a3b = TDhat(2,2)*mySUSY.v1()/sqrt(2.0)/mb;
    gslpp::complex a3tau = TEhat(2,2)*mySUSY.v1()/sqrt(2.0)/mTAU;

    gslpp::matrix<gslpp::complex> MsQhat2(3,3,0);
    gslpp::matrix<gslpp::complex> MsUhat2(3,3,0);
    gslpp::matrix<gslpp::complex> MsDhat2(3,3,0);
    gslpp::matrix<gslpp::complex> MsLhat2(3,3,0);
    gslpp::matrix<gslpp::complex> MsEhat2(3,3,0);
    MsQhat2 = mySUSY.getMsQhat2();
    MsUhat2 = mySUSY.getMsUhat2();
    MsDhat2 = mySUSY.getMsDhat2();
    MsLhat2 = mySUSY.getMsLhat2();
    MsEhat2 = mySUSY.getMsEhat2();
    double msq1L = MsQhat2(0,0).real();
    double msq2L = MsQhat2(1,1).real();
    double msq3L = MsQhat2(2,2).real();
    double msuR = MsUhat2(0,0).real();
    double mscR = MsUhat2(1,1).real();
    double mstR = MsUhat2(2,2).real();
    double msdR = MsDhat2(0,0).real();
    double mssR = MsDhat2(1,1).real();
    double msbR = MsDhat2(2,2).real();
    double mseL = MsLhat2(0,0).real();
    double msmuL = MsLhat2(1,1).real();
    double mstauL = MsLhat2(2,2).real();
    double mseR = MsEhat2(0,0).real();
    double msmuR = MsEhat2(1,1).real();
    double mstauR = MsEhat2(2,2).real();

    int k;
    double b1[3];
    double gi[3];
    double g1, g2, g3;
    double res_g;
    b1[0]=41./6., b1[1]=-19./6., b1[2]=-7.;
    gi[0]=g1atMZ, gi[1]=g2atMZ, gi[2]=g3atMZ;
    for(k=0; k<3; k++){
        res_g=1./gi[k]/gi[k] -b1[k]/(8.*pi*pi)*log(sqrt(msmuL)/MZ);
        gi[k]=sqrt(1/res_g);
    }
    g1=gi[0], g2=gi[1], g3=gi[2];

    double alp = (g1*g1*g2*g2/(g1*g1+g2*g2))/(4.0*pi);
//    double s2b = 2.0*cosb*sinb;
    double c2b = cosb*cosb-sinb*sinb;
    double mzq = sqrt( 0.5*(g1*g1+g2*g2)*vew*vew );
    double mwq = sqrt( 0.5*(g2*g2)*vew*vew );
    double sw2 = g1*g1/(g1*g1+g2*g2);
    gslpp::complex lh1 = -sa/cosb;
    gslpp::complex lh2 = ca/cosb;
    double lA = tanb;
    double msneu2 = msmuL+0.5*mzq*mzq*c2b;

        TEhat.assign(1,1, 0.);
//     a3t = 0.;
//     a3b = 0.;
//     a3tau = 0.;

    
    gslpp::matrix<gslpp::complex> Rsmu(2,2,0.), Xm(2,2,0.);
    gslpp::vector<double> msmu2(2,0.);
    Rsmu.assign(0,0, msmuL+mmu*mmu+c2b*mzq*mzq*(-1.0/2.0+sw2) );
    Rsmu.assign(0,1, mySUSY.v1()/sqrt(2.0)*TEhat(1,1).conjugate()-muH*mmu*tanb);
    Rsmu.assign(1,0, mySUSY.v1()/sqrt(2.0)*TEhat(1,1)-muH.conjugate()*mmu*tanb);
    Rsmu.assign(1,1, msmuR+mmu*mmu-c2b*mzq*mzq*sw2);
    Rsmu.eigensystem(Xm,msmu2); //in the 1,2 basis now!

    gslpp::vector<gslpp::complex> gminus2muvector=gminus2mu();
//    std::cout<<"gminus2muvector"<<gminus2muvector<<std::endl;
//    double gm21loop = (gminus2muvector(0)+gminus2muvector(1)).abs();
//    std::cout<<"gm21loop="<<gm21loop<<std::endl;


    double gm21loop = 1.06978e-9;
    mh=125.;
    alp = 0.00729927;
    mt=173.34;

    
    double res,res1;            //the two Barr-Zee contributions
    double gm2cor, res2, res3;  //muon mass correction, photonic two-loop and corrected smuon-muon-chargino/neutralino couplings
    double res01, res02;
    double gminus2muNLO;

    ///////////////////////////////////////////////////////////////
    //two-loop corrections to SM one-loop diagrams
    ///////////////////////////////////////////////////////////////

    // Barr-Zee diagrams (photonic)
    // chargino-loop
    gslpp::vector<gslpp::complex> lxh1(2,0);
    gslpp::vector<gslpp::complex> lxh2(2,0);
    gslpp::vector<gslpp::complex> lxA(2,0);

    double tmp1;
    for(int i=0; i<2; i++){
        tmp1=sqrt(2.0)*mwq/MChi(i);
        lxh1.assign(i, tmp1*( myU(i,0)*myV(i,1)*ca    + myU(i,1)*myV(i,0)*(-sa) ) );
        lxh2.assign(i, tmp1*( myU(i,0)*myV(i,1)*sa    + myU(i,1)*myV(i,0)*( ca) ) );
        lxA.assign(i,  tmp1*( myU(i,0)*myV(i,1)*(-cosb) + myU(i,1)*myV(i,0)*(-sinb) ) );
    }

    res=0;
    double xps, xh1, xh2;
    for(int i=0; i<2; i++){
        xps=MChi(i)*MChi(i)/(ma*ma);
        xh1=MChi(i)*MChi(i)/(mh*mh);
        xh2=MChi(i)*MChi(i)/(mhh*mhh);

        res += (lA*lxA(i)).real()*fPS(xps) + (lh1*lxh1(i)).real()*fS(xh1)
               +(lh2*lxh2(i)).real()*fS(xh2);
    }
    res *= alp*alp * mmu*mmu / (8.*pi*pi*mwq*mwq*sw2);

    // Barr-Zee diagrams (photonic)
    // sfermion-loop
    gslpp::matrix<gslpp::complex> stauM(2,2,0), sbottomM(2,2,0), stopM(2,2,0);
    gslpp::vector<double> mstau2(2,0), msbottom2(2,0), mstop2(2,0);
    gslpp::matrix<gslpp::complex> Ustau(2,2,0), Usbottom(2,2,0), Ustop(2,2,0);

    stauM.assign(0,0, mstauL+mTAU*mTAU + mzq*mzq*c2b*(0.5-(-1.)*sw2) );
    stauM.assign(1,1, mstauR+mTAU*mTAU + mzq*mzq*c2b*(-1.)*sw2);
    stauM.assign(0,1, mTAU*(a3tau-muH*tanb));
    stauM.assign(1,0, mTAU*(a3tau-muH*tanb));

    sbottomM.assign(0,0, msq3L+mb*mb + mzq*mzq*c2b*(0.5-(-1./3.)*sw2) );
    sbottomM.assign(1,1, msbR+mb*mb + mzq*mzq*c2b*(-1./3.)*sw2);
    sbottomM.assign(0,1, mb*(a3b-muH*tanb));
    sbottomM.assign(1,0, mb*(a3b-muH*tanb));

    stopM.assign(0,0, msq3L+mt*mt + mzq*mzq*c2b*(0.5-(2./3.)*sw2) );
    stopM.assign(1,1, mstR+mt*mt + mzq*mzq*c2b*(2./3.)*sw2);
    stopM.assign(0,1, mt*(a3t-muH/tanb));
    stopM.assign(1,0, mt*(a3t-muH/tanb));

    stauM.eigensystem(Ustau,mstau2);
    sbottomM.eigensystem(Usbottom,msbottom2);
    stopM.eigensystem(Ustop,mstop2);

    Ustau=Ustau.hconjugate();
    Usbottom=Usbottom.hconjugate();
    Ustop=Ustop.hconjugate();

    gslpp::vector<gslpp::complex> lstauh1(2,0);
    gslpp::vector<gslpp::complex> lstauh2(2,0);
    gslpp::vector<gslpp::complex> lsbottomh1(2,0);
    gslpp::vector<gslpp::complex> lsbottomh2(2,0);
    gslpp::vector<gslpp::complex> lstoph1(2,0);
    gslpp::vector<gslpp::complex> lstoph2(2,0);

    gslpp::complex rr;
    for(int i=0; i<2; i++){
        
        rr=2.*mTAU/(cosb*mstau2(i)) * Ustau(i,0).conjugate() * Ustau(i,1);
        lstauh1.assign(i,rr*(-muH*ca + a3tau*(-sa)) );
        lstauh2.assign(i,rr*(-muH*sa + a3tau*(ca)) );
        
        rr=2.*mb/(cosb*msbottom2(i)) * Usbottom(i,0).conjugate() * Usbottom(i,1);
        lsbottomh1.assign(i,rr*(-muH*ca + a3b*(-sa)) );
        lsbottomh2.assign(i,rr*(-muH*sa + a3b*(ca)) );

        rr=2.*mt/(cosb*mstop2(i)) * Ustop(i,0).conjugate() * Ustop(i,1);
        lstoph1.assign(i,rr*(-muH*sa + a3t*(ca)) );
        lstoph2.assign(i,rr*(-muH*(-ca) + a3t*(sa)) );
    }
//    std::cout<<"mh="<<mh<<std::endl;
//    std::cout<<"mhh="<<mhh<<std::endl;
//    std::cout<<"ma="<<ma<<std::endl;

    res1=0;
    double qe2;
    double xx1,xx2;
    for(int i=0;i<2;i++){
        xx1=mstau2(i)/(mh*mh);
        xx2=mstau2(i)/(mhh*mhh);
        res1 += (lh1*lstauh1(i)).real()*fft(xx1)
                +(lh2*lstauh2(i)).real()*fft(xx2);
//    std::cout<<"mstau2="<<mstau2<<std::endl;
    
        qe2=1./3.0;
        xx1=msbottom2(i)/(mh*mh);
        xx2=msbottom2(i)/(mhh*mhh);
        res1 += (lh1*lsbottomh1(i)).real()*qe2*fft(xx1)
                +(lh2*lsbottomh2(i)).real()*qe2*fft(xx2);
//    std::cout<<"msbottom2="<<msbottom2<<std::endl;

        qe2=4./3.0;
        xx1=mstop2(i)/(mh*mh);
        xx2=mstop2(i)/(mhh*mhh);
        res1 += (lh1*lstoph1(i)).real()*qe2*fft(xx1)
                +(lh2*lstoph2(i)).real()*qe2*fft(xx2);
//    std::cout<<"mstop2="<<mstop2<<std::endl;
    }  
    res1 *= alp*alp * mmu*mmu / (8.*pi*pi*mwq*mwq*sw2);

    //adding up the photonic Barr-Zee contributions
    res02=res+res1;

//    std::cout<<"res="<<res<<std::endl;
//    std::cout<<"res1="<<res1<<std::endl;

    ///////////////////////////////////////////////////////////////
    //two-loop corrections to MSSM one-loop diagrams
    ///////////////////////////////////////////////////////////////

    gm2cor=0, res2=0, res3=0;

    /////////////////////////////////////////////////////////////////////////////
    //
    //   tanb enhanced correction from SUSY one-loop correction to the muon mass
    //   (ref. arXiv:0808.1530 )
    //
    /////////////////////////////////////////////////////////////////////////////

    double dmu=0;
//    double I=0;
    double x0, x1a, x2a, xL, xR;
    double tmp2, tmp3;

    x0=sqrt(std::fabs(msneu2));
    xL=sqrt( msmuL-mzq*mzq*(sw2-0.5) );
    xR=sqrt( msmuR +mzq*mzq*sw2 );

    tmp2=M2.abs2()+muH.abs2() +2.*mwq*mwq;
    tmp3= tmp2*tmp2 -4.*M2.abs2()*muH.abs2();
    x1a=sqrt( 0.5*( tmp2-sqrt(tmp3) ) );
    x2a=sqrt( 0.5*( tmp2+sqrt(tmp3) ) );

    dmu=-muH.real()*tanb*g2*g2*M2.real()/(16.*pi*pi)*(It(x1a,x2a,x0) + 0.5*It(x1a,x2a,xL))
        -muH.real()*tanb*g1*g1*M1.real()/(16.*pi*pi)*(It(muH.real(),M1.real(),xR) - 0.5*It(muH.real(),M1.real(),xL) - It(M1.real(),xL,xR));

    // corrected one-loop result
    gm2cor=gm21loop/(1+dmu);

    ////////////////////////////////////////////////////////////////
    //
    // photonic two-loop (arXiv:1003.5820)
    //
    ////////////////////////////////////////////////////////////////

    // leading part is simple, which is enhanced by log(mmu/msmu)
    res2=gm2cor*alp/(4.*pi)*16.*log(mmu/sqrt(msmuL));

    // non-logarithmic corrections, which are usually small
    double amch=0;
    double amne=0;

    // switch of the sub-leading contribution to reduce the computation time
    int sub_leading=1;

            if (sub_leading==1){
                /////////////////////////////////////////////////
                // for the corrections to the chargino diagrams
                /////////////////////////////////////////////////
                gslpp::vector<gslpp::complex> ckL(2,0), ckR(2,0);
                double ymu=mmu/(vew*cosb);

                ckR.assign(0, ymu*myU(0,1));
                ckR.assign(1, ymu*myU(1,1));

                // gauge couplings are defined at the smuon mass scale msmuL
                ckL.assign(0, -g2*myV(0,0));
                ckL.assign(1, -g2*myV(1,0));

                double xk=0;
                for(int i=0; i<2; i++){
                    xk=MChi(i)*MChi(i)/msneu2;
                    amch=amch -(47.*mmu/(12.*msneu2))*( (ckL(i).abs()*ckL(i).abs() + ckR(i).abs()*ckR(i).abs())*F3C(xk) );
                    amch=amch -(122.*MChi(i)/(9.*msneu2))*F4C(xk)*( (ckL(i)*ckR(i)).real() );
                }
                amch=(1./(1+dmu))*amch*mmu/(16.*pi*pi)*alp/(4.*pi);

                /////////////////////////////////////////////////
                // for the corrections to the neutralino diagrams
                /////////////////////////////////////////////////
                gslpp::vector<gslpp::complex> nR1(4,0), nR2(4,0), nL1(4,0), nL2(4,0);

                for(int i=0; i<4; i++){
                    nR1.assign(i, sqrt(2.)*g1*myN(i,0)*Xm(0,1) + ymu*myN(i,2)*Xm(0,0));
                    nR2.assign(i, sqrt(2.)*g1*myN(i,0)*Xm(1,1) + ymu*myN(i,2)*Xm(1,0));
                    nL1.assign(i, (1./sqrt(2.))*(g2*myN(i,1) + g1*myN(i,0))*Xm(0,0).conjugate() -ymu*myN(i,2)*Xm(0,1).conjugate());
                    nL2.assign(i, (1./sqrt(2.))*(g2*myN(i,1) + g1*myN(i,0))*Xm(1,0).conjugate() -ymu*myN(i,2)*Xm(1,1).conjugate());
                }

                double tmp4, tmp5;
                double xi1, xi2;
                double r1, r2;
                for(int i=0; i<4; i++){
                    xi1=MChi0(i)*MChi0(i)/msmu2(0);
                    xi2=MChi0(i)*MChi0(i)/msmu2(1);
                    tmp4=nL1(i).abs2() + nR1(i).abs2();
                    tmp5=nL2(i).abs2() + nR2(i).abs2();
                    r1=35.*mmu/(72.*msmu2(0))*F3N(xi1)*tmp4 - 16.*MChi0(i)/(9.*msmu2(0))*F4N(xi1)*( (nL1(i)*nR1(i)).real() );
                    r2=35.*mmu/(72.*msmu2(1))*F3N(xi2)*tmp5 - 16.*MChi0(i)/(9.*msmu2(1))*F4N(xi2)*( (nL2(i)*nR2(i)).real() );
                    amne=amne+r1+r2;
                }

                amne*=(1./(1.+dmu))*mmu/(16.*pi*pi)*alp/(4.*pi);
            }// end of the subleading term

    //adding leading log correction and sub-leading terms
    res2=res2+amch+amne;
//    std::cout<<"res2="<<res2<<std::endl;

    ///////////////////////////////////////////////////////////////////////
    //
    //   Deviation of the smuon-muon-chargino/neutralino couplings 
    //   from gauge/Yukawa couplings due to the breaking of SUSY relations
    //   ref. arXiv:1311.1775
    //
    ///////////////////////////////////////////////////////////////////////
  
    // approximate one-loop corrections
    // usually awhn and ablr are dominant contribution 
    double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    double awhn=mmu*mmu*muH.real()*tanb/(1+dmu);
    double awhl=awhn;
    double abhl=awhn;
    double abhr=awhn;
    double ablr=awhn;

    //wino-Higgsino-sneutrino
    x1=M2.abs2()/msneu2;
    y1=muH.abs2()/msneu2;
    awhn *= g2*g2*M2.real()/(8.*pi*pi*msneu2*msneu2)*Fa(x1,y1);

    //wino-Higgsino-L-smuon
    x2=M2.abs2()/msmuL;
    y2=muH.abs2()/msmuL;
    awhl *= -g2*g2*M2.real()/(16.*pi*pi*pow(msmuL,2))*Fb(x2,y2);

    //bino-higgsino-L-smuon
    x3=M1.abs2()/msmuL;
    y3=muH.abs2()/msmuL;
    abhl *= g1*g1*M1.real()/(16.*pi*pi*pow(msmuL,2))*Fb(x3,y3);

    ///bino-higgsino-R-smuon
    x4=M1.abs2()/msmuR;
    y4=muH.abs2()/msmuR;
    abhr *= -g1*g1*M1.real()/(8.*pi*pi*pow(msmuR,2))*Fb(x4,y4);

    //bino-L-smuon-R-smuon
    x5=msmuL/(M1.abs2());
    y5=msmuR/(M1.abs2());
    ablr *= g1*g1/(8.*pi*pi*pow(M1.real(),3))*Fb(x5,y5);

    double dg2, dg1, dh, dwh, dbh, dtb;
    double msusy=sqrt(msmuL);

    dg1=g1*g1/(16.*pi*pi)*(4./3.)
        *(4./3.*log(sqrt(msuR)/msusy) + 4./3.*log(sqrt(mscR)/msusy) + 4./3.*log(sqrt(mstR)/msusy)
          + 2./3.*log(sqrt(msdR)/msusy) + 2./3.*log(sqrt(mssR)/msusy) + 2./3.*log(sqrt(msbR)/msusy)
          + 1./3.*log(sqrt(msq1L)/msusy) + 1./3.*log(sqrt(msq2L)/msusy) + 1./3.*log(sqrt(msq3L)/msusy)
          + log(sqrt(mseR)/msusy) + log(sqrt(mstauR)/msusy)
          + 1./2.*log(sqrt(mseL)/msusy) + 1./2.*log(sqrt(mstauL)/msusy) );

    dg2=g2*g2/(16.*pi*pi)*(4./3.)
        *(3./2.*log(sqrt(msq1L)/msusy) + 3./2.*log(sqrt(msq2L)/msusy) + 3./2.*log(sqrt(msq3L)/msusy)
          + 1./2.*log(sqrt(mseL)/msusy) + 1./2.*log(sqrt(mstauL)/msusy) );

    // corrections involving Yukawa couplings
    double yb, ytau, yt;
    double as_mt, delta_mt;

    // a_s(msmuL)
    as_mt=1/(g3*g3);
    //running down to mt
    as_mt=as_mt - (-7.)*log(mt/sqrt(msmuL))/(8.*pi*pi);
    as_mt=(1./as_mt)/(4.*pi);

    delta_mt=-4./3.*(as_mt/pi)-9.1*pow( (as_mt/pi), 2)-80.*pow((as_mt/pi),3);

    yb=mb/(vew*cosb);
    yt=mt/(vew*sinb)*(1+delta_mt); //neglecting small EW correction
    ytau=mTAU/(vew*cosb);

    // to the DR bar scheme
    yt=yt*(1+as_mt/(8.*pi)*(-4./3.));
    yb=yb*(1+as_mt/(8.*pi)*(-4./3.));

    dh=0.5/(16.*pi*pi)*(3.*yt*yt*log(sqrt(mstR)/msusy) +3.*yb*yb*log(sqrt(msbR)/msusy)
                        +3.*(yt*yt+yb*yb)*log(sqrt(msq3L)/msusy)
                        +ytau*ytau*log(sqrt(mstauR)/msusy) +ytau*ytau*log(sqrt(mstauL)/msusy));

    dwh=yt*yt/(16.*pi*pi)*(-6.*log(sqrt(msq3L)/msusy));

    dbh=yt*yt/(16.*pi*pi)*( 2.*log(sqrt(msq3L)/msusy)-8.*log(sqrt(mstR)/msusy) );

    Q_S=msusy;
    
    dtb=1./(16.*pi*pi)*( 3.*yb*yb -3.*yt*yt +ytau*ytau)*log(Q_S/msusy);

    // summing sfermion/fermion contributions
    res3= awhn*(dg2 + dh + dwh + dtb)
          + awhl*(dg2 + dh + dwh + dtb)
          + abhl*(dg1 + dh + dbh + dtb)
          + abhr*(dg1 + dh + dbh + dtb)
          + ablr*(dg1 + dtb);
//    std::cout<<"awhn="<<awhn<<std::endl;
//    std::cout<<"awhl="<<awhl <<std::endl;
//    std::cout<<"abhl="<<abhl <<std::endl;
//    std::cout<<"abhr="<<abhr<<std::endl;
//    std::cout<<"ablr="<<ablr<<std::endl;

//    std::cout<<"res3="<<res3<<std::endl;
//    std::cout<<"gm2cor="<<gm2cor<<std::endl;
    res01=gm2cor+res2+res3-gm21loop;

//    std::cout<<"res01="<<res01<<std::endl;
//    std::cout<<"res02="<<res02<<std::endl;

    gminus2muNLO=res01+res02;
    
//    std::cout<<"gm2NLO="<<gminus2muNLO<<std::endl;
    return(gminus2muNLO);
}

gslpp::vector<gslpp::complex> SUSYMatching::C7_Lepton(int li_to_lj) {

    gslpp::vector<gslpp::complex> C7(2, 0.);

    //     write C7 and C7' into a vector
    C7.assign(0, -0.5*AFunctions(li_to_lj)(2) );
    C7.assign(1, -0.5*AFunctions(li_to_lj)(3) );
    return(C7);
}

gslpp::vector<gslpp::complex> SUSYMatching::C9_Lepton(int li_to_lj) {

    double MZ = mySUSY.getMz();
    double MW = mySUSY.Mw_tree();
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double cw2 = 1.0 - sw2;

    gslpp::vector<gslpp::complex> C9(2, 0.);

        //     write C9 and C9' into a vector
        C9.assign(0, AFunctions(li_to_lj)(1)
                     + (1.0-1.0/(4.0*sw2))/(cw2*MZ*MZ)*FFunctions(li_to_lj)(1)
                     + (BFunctions(li_to_lj)(1)+BFunctions(li_to_lj)(3))/2.0 );
        C9.assign(1, AFunctions(li_to_lj)(0)
                     + (1.0-1.0/(4.0*sw2))/(cw2*MZ*MZ)*FFunctions(li_to_lj)(0)
                     + (BFunctions(li_to_lj)(0)+BFunctions(li_to_lj)(2))/2.0 );

    return(C9);
}

gslpp::vector<gslpp::complex> SUSYMatching::C10_Lepton(int li_to_lj) {

    double MZ = mySUSY.getMz();
    double MW = mySUSY.Mw_tree();
    double sw2 = mySUSY.StandardModel::sW2(MW);
    double cw2 = 1.0 - sw2;

    gslpp::vector<gslpp::complex> C10(2, 0.);

        //     write C10 and C10' into a vector
        C10.assign(0, 1.0/(4.0*sw2*cw2*MZ*MZ)*FFunctions(li_to_lj)(1)
                     + (BFunctions(li_to_lj)(3)-BFunctions(li_to_lj)(1))/2.0 );
        C10.assign(1, 1.0/(4.0*sw2*cw2*MZ*MZ)*FFunctions(li_to_lj)(0)
                     + (BFunctions(li_to_lj)(0)-BFunctions(li_to_lj)(2))/2.0 );

    return(C10);
}

gslpp::vector<gslpp::complex> SUSYMatching::CS_Lepton(int li_to_lj) {

    gslpp::vector<gslpp::complex> CS(2, 0.);

        //     write CS and CS' into a vector
        CS.assign(0, BFunctions(li_to_lj)(4)/2.0 );
        CS.assign(1, BFunctions(li_to_lj)(5)/2.0 );

    return(CS);
}

gslpp::vector<gslpp::complex> SUSYMatching::CP_Lepton(int li_to_lj) {

    gslpp::vector<gslpp::complex> CP(2, 0.);

        //     write CP and CP' into a vector
        CP.assign(0, BFunctions(li_to_lj)(4)/2.0 );
        CP.assign(1, -BFunctions(li_to_lj)(5)/2.0 );

    return(CP);
}

gslpp::vector<gslpp::complex> SUSYMatching::CT_Lepton(int li_to_lj) {

    gslpp::vector<gslpp::complex> CT(2, 0.);

        //     write CT and CT5 into a vector
        CT.assign(0, (BFunctions(li_to_lj)(6)+BFunctions(li_to_lj)(7))/2.0 );
        CT.assign(1, (BFunctions(li_to_lj)(6)+BFunctions(li_to_lj)(7))/2.0 );

    return(CT);
}

std::vector<WilsonCoefficient>& SUSYMatching::CMDLij(int li_lj) {

    vmcDLij = StandardModelMatching::CMDLij(li_lj);

    gslpp::vector<gslpp::complex> C7vector=C7_Lepton(li_lj);
    switch (mcDLij.getOrder()) {
        case LO:
            mcDLij.setCoeff(0, C7vector(0), LO);
            mcDLij.setCoeff(1, C7vector(1), LO);
            break;
        case NNLO:
        case NLO:
        default:
            std::stringstream out;
            out << mcDLij.getOrder();
            throw std::runtime_error("SUSYMatching::CMDLij(): order " + out.str() + " not implemented.\nFor lepton flavour violating observables only Leading Order (LO) necessary.");
    }

    vmcDLij.push_back(mcDLij);
    return(vmcDLij);

}

std::vector<WilsonCoefficient>& SUSYMatching::CMDLi3j(int li_lj) {

    vmcDLi3j = StandardModelMatching::CMDLi3j(li_lj);

    gslpp::vector<gslpp::complex> Avector=AFunctions(li_lj);
    gslpp::vector<gslpp::complex> Bvector=BFunctions(li_lj);
    gslpp::vector<gslpp::complex> BHvector=BHFunctions(li_lj);
    gslpp::vector<gslpp::complex> Fvector=FFunctions(li_lj);
    switch (mcDLi3j.getOrder()) {
        case LO:
//            mcDLi3j.setCoeff(0, C7_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(1, C7_Lepton(li_lj)(1), LO);
//            mcDLi3j.setCoeff(2, C9_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(3, C9_Lepton(li_lj)(1), LO);
//            mcDLi3j.setCoeff(4, C10_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(5, C10_Lepton(li_lj)(1), LO);
//            mcDLi3j.setCoeff(6, CS_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(7, CS_Lepton(li_lj)(1), LO);
//            mcDLi3j.setCoeff(8, CP_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(9, CP_Lepton(li_lj)(1), LO);
//            mcDLi3j.setCoeff(10, CT_Lepton(li_lj)(0), LO);
//            mcDLi3j.setCoeff(11, CT_Lepton(li_lj)(1), LO);
            mcDLi3j.setCoeff(0, Avector(0), LO);      //A1R
            mcDLi3j.setCoeff(1, Avector(1), LO);      //A1L
            mcDLi3j.setCoeff(2, Avector(2), LO);      //A2R
            mcDLi3j.setCoeff(3, Avector(3), LO);      //A2L
            mcDLi3j.setCoeff(4, Bvector(0), LO);      //B1R
            mcDLi3j.setCoeff(5, Bvector(1), LO);      //B1L
            mcDLi3j.setCoeff(6, Bvector(2), LO);      //B2R
            mcDLi3j.setCoeff(7, Bvector(3), LO);      //B2L
            mcDLi3j.setCoeff(8, Bvector(4), LO);      //B3R
            mcDLi3j.setCoeff(9, Bvector(5), LO);      //B3L
            mcDLi3j.setCoeff(10, Bvector(6), LO);     //B4R
            mcDLi3j.setCoeff(11, Bvector(7), LO);     //B4L
            mcDLi3j.setCoeff(12, BHvector(0), LO);    //BH2R
            mcDLi3j.setCoeff(13, BHvector(1), LO);    //BH2L
            mcDLi3j.setCoeff(14, BHvector(2), LO);    //BH3R
            mcDLi3j.setCoeff(15, BHvector(3), LO);    //BH3L
            mcDLi3j.setCoeff(16, Fvector(0), LO);     //FRR
            mcDLi3j.setCoeff(17, Fvector(1), LO);     //FRL
            mcDLi3j.setCoeff(18, Fvector(2), LO);     //FLR
            mcDLi3j.setCoeff(19, Fvector(3), LO);     //FLL
            break;
        case NNLO:
        case NLO:
        default:
            std::stringstream out;
            out << mcDLi3j.getOrder();
            throw std::runtime_error("SUSYMatching::CMDLi3j(): order " + out.str() + " not implemented.\nFor lepton flavour violating observables only Leading Order (LO) necessary.");
    }

    vmcDLi3j.push_back(mcDLi3j);
    return(vmcDLi3j);

}

std::vector<WilsonCoefficient>& SUSYMatching::CMmueconv() {

    double MW = mySUSY.Mw_tree();
    double sw2 = mySUSY.StandardModel::sW2(MW);

    vmcmueconv = StandardModelMatching::CMmueconv();

    gslpp::vector<gslpp::complex> Avector=AFunctions(1);
    gslpp::vector<gslpp::complex> Dvector=DFunctions();
    gslpp::vector<gslpp::complex> Fvector=FFunctions(1);
    switch (mcmueconv.getOrder()) {
        case LO:
            mcmueconv.setCoeff(0, Avector(0), LO);                                        //A1R
            mcmueconv.setCoeff(1, Avector(1), LO);                                        //A1L
            mcmueconv.setCoeff(2, Avector(2), LO);                                        //A2R
            mcmueconv.setCoeff(3, Avector(3), LO);                                        //A2L
            mcmueconv.setCoeff(4, Dvector(0)+(1.0/(4.0*sw2)-2.0/3.0)*Fvector(0), LO);     //DbaruR
            mcmueconv.setCoeff(5, Dvector(1)+(1.0/(4.0*sw2)-2.0/3.0)*Fvector(2), LO);     //DbaruL
            mcmueconv.setCoeff(6, Dvector(2)+(-1.0/(4.0*sw2)+1.0/3.0)*Fvector(0), LO);    //DbardR
            mcmueconv.setCoeff(7, Dvector(3)+(-1.0/(4.0*sw2)+1.0/3.0)*Fvector(2), LO);    //DbardL
            break;
        case NNLO:
        case NLO:
        default:
            std::stringstream out;
            out << mcmueconv.getOrder();
            throw std::runtime_error("SUSYMatching::CMmueconv(): order " + out.str() + " not implemented.\nFor lepton flavour violating observables only Leading Order (LO) necessary.");
    }

    vmcmueconv.push_back(mcmueconv);
    return(vmcmueconv);

}

std::vector<WilsonCoefficient>& SUSYMatching::CMgminus2mu() {

    vmcgminus2mu = StandardModelMatching::CMgminus2mu();

    gslpp::vector<gslpp::complex> gminus2muvector=gminus2mu();
//    std::cout<<"gminus2muvector in the Wilson coeff"<<gminus2muvector<<std::endl;
    double gminus2muvectorNLO=gminus2muNLO();
    switch (mcgminus2mu.getOrder()) {
        case LO:
            mcgminus2mu.setCoeff(0, gminus2muvector(0), LO);  //g-2_muR
            mcgminus2mu.setCoeff(1, gminus2muvector(1), LO);  //g-2_muL
            break;
        case NLO:
            mcgminus2mu.setCoeff(0, gminus2muvectorNLO, NLO);  //g-2_muR
            mcgminus2mu.setCoeff(1, 0., NLO);  //g-2_muL
            break;
        case NNLO:
        default:
            std::stringstream out;
            out << mcgminus2mu.getOrder();
            throw std::runtime_error("SUSYMatching::CMgminus2mu(): order " + out.str() + " not implemented.\nFor lepton flavour violating observables only Leading Order (LO) necessary.");
    }

    vmcgminus2mu.push_back(mcgminus2mu);
    return(vmcgminus2mu);

}
