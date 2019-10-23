/* 
 * Copyright (C) 2017 HEPfit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef THDMWCACHE_H
#define	THDMWCACHE_H

#include <cmath>
#include "THDMW.h"
#include "RunnerTHDMW.h"
#include "PVfunctions.h"
//#include "../../LoopFunctions/src/PVfunctions.h"//Solve this
#include <stdexcept>
#include "gslpp.h"


/**
 * @class THDMWcache
 * @ingroup THDMW
 * @brief A class for the caching of some %THDMW objects.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 */
class THDMWcache {
    
public:

    /**
     * @brief THDMWcache constructor.
     * @details Reads all the tables values and stores them in the memory.
     */
    THDMWcache(const StandardModel& SM_i);

    /**
     * @brief THDMWcache destructor.
     */
    ~THDMWcache();
    
    void updateCache();
    double setOtherParameters();

    double Q_cutoff;
//    double g1_at_Q;
//    double g2_at_Q;
//    double g3_at_Q;
//    double Ytop_at_Q;
//    double Ybottom1_at_Q;
//    double Ybottom2_at_Q;
//    double Ytau1_at_Q;
//    double Ytau2_at_Q;
    double lambda1_at_Q;
    double lambda2_at_Q;
    double lambda3_at_Q;
    double lambda4_at_Q;
    double mu1_at_Q;
    double mu3_at_Q;
    double mu4_at_Q;
    double nu1_at_Q;
    double omega1_at_Q;
    double kappa1_at_Q;
    double nu2_at_Q;
    double omega2_at_Q;
    double kappa2_at_Q;
    double nu4_at_Q;
    double omega4_at_Q;
    double nu3_at_Q;
    double nu5_at_Q;
    double mu2_at_Q;
    double mu5_at_Q;
    double mu6_at_Q;
    double m12sq;
    double m11sq;
    double m22sq;
    double mhsq;
    double mHsq;
    double mAsq;
    double mSRsq;
    double mSIsq;
    double mHpsq;
    double mSpsq;


    

    double pp_Sr_tt_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R}\to t\bar t@f$ at the LHC with 13 TeV. */
    double pp_Srtt_tttt_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R} t t\bar \to t\bar t  t\bar t@f$ at the LHC with 13 TeV. */
    double pp_Sr_jj_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R} \to j j @f$ at the LHC with 13 TeV. */
    double pp_SrSr_jjjj_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R} S_{R} \to j j j j @f$ at the LHC with 13 TeV. */
    double pp_Stb_tbtb_TH13;/**< Cross section times branching ratio for the process @f$pp\to S+ tbar b \to t tbar b bar @f$ at the LHC with 13 TeV. */
    double pp_Sitt_tttt_TH13;/**< Cross section times branching ratio for the process @f$pp\to Si t t\bar \to t\bar t  t\bar t@f$ at the LHC with 13 TeV. */
    double pp_Srbb_bbbb_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R} b b\bar \to b\bar b  b\bar b@f$ at the LHC with 13 TeV. */
    double pp_Srbb_bbbb_TH8;/**< Cross section times branching ratio for the process @f$pp\to S_{R} b b\bar \to b\bar b  b\bar b@f$ at the LHC with 8 TeV. */
    double pp_Sibb_bbbb_TH13;/**< Cross section times branching ratio for the process @f$pp\to Si b b\bar \to b\bar b  b\bar b@f$ at the LHC with 13 TeV. */
    double pp_Sibb_bbbb_TH8;/**< Cross section times branching ratio for the process @f$pp\to Si b b\bar \to b\bar b  b\bar b@f$ at the LHC with 8 TeV. */
    double pp_Sr_bb_TH13;/**< Cross section times branching ratio for the process @f$pp\to S_{R} \to  b\bar b@f$ at the LHC with 13 TeV. */
    double pp_Sr_bb_TH8;/**< Cross section times branching ratio for the process @f$pp\to S_{R} \to  b\bar b@f$ at the LHC with 8 TeV. */
    double pp_Si_bb_TH13;/**< Cross section times branching ratio for the process @f$pp\to Si  \to b\bar b@f$ at the LHC with 13 TeV. */
    double pp_Si_bb_TH8;/**< Cross section times branching ratio for the process @f$pp\to Si  \to b\bar b@f$ at the LHC with 8 TeV. */
    
    double THoEX_pp_Sr_tt;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R}\to t\bar t@f$ at 13 TeV. */
    double THoEX_pp_Srtt_tttt;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R} t\bar t \to t\bar t t\bar t@f$ at 13 TeV. */
    double THoEX_pp_Sr_jj;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R}\to j j@f$ at 13 TeV. */
    double THoEX_pp_SrSr_jjjj;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R} S_{R} \to j j j j@f$ at 13 TeV. */
    double THoEX_pp_Stb_tbtb;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S^{+} t\bar b \to t\bar b b\bar t@f$ at 13 TeV. */
    double THoEX_pp_Sitt_tttt;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{I} t\bar t \to t\bar t t\bar t@f$ at 13 TeV. */
    double THoEX_pp_Srbb_bbbb;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R} b\bar b \to b\bar b b\bar b@f$ at 13 TeV. */
    double THoEX_pp_Srbb_bbbb_8TeV;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R} b\bar b \to b\bar b b\bar b@f$ at 8 TeV. */
    double THoEX_pp_Sibb_bbbb;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{I} b\bar b \to b\bar b b\bar b@f$ at 13 TeV. */
    double THoEX_pp_Sibb_bbbb_8TeV;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{I} b\bar b \to b\bar b b\bar b@f$ at 8 TeV. */
    double THoEX_pp_Sr_bb;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R}\to b\bar b@f$ at 13 TeV. */
    double THoEX_pp_Sr_bb_8TeV;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{R}\to b\bar b@f$ at 8 TeV. */
    double THoEX_pp_Si_bb;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{I}\to b\bar b@f$ at 13 TeV. */
    double THoEX_pp_Si_bb_8TeV;/**< Ratio between the theoretical prediction and the experimental upper limit for the process @f$pp\to S_{I}\to b\bar b@f$ at 8 TeV. */

    
    
    
    
    // Passarino Veltman Functions //
    
    gslpp::complex A0_MZ2_mSp2(const double MZ2, const double mSp2) const;
    gslpp::complex A0_MZ2_mSr2(const double MZ2, const double mSr2) const;
    gslpp::complex A0_MZ2_mSi2(const double MZ2, const double mSr2) const;
    gslpp::complex B0_MZ2_0_mSp2_mSp2(const double MZ2,const double mSp2) const;
    //gslpp::complex B00_MZ2_0_mSr2_mSp2(const double MZ2,const double mSr2 ,const double mSp2) const;
    //gslpp::complex B00_MZ2_0_mSi2_mSp2(const double MZ2,const double mSi2 ,const double mSp2) const;
    //gslpp::complex B00_MZ2_0_mSp2_mSp2(const double MZ2,const double mSp2) const;
    gslpp::complex B00_MZ2_MZ2_mSr2_mSp2(const double MZ2,const double mSr2 ,const double mSp2) const;
    gslpp::complex B00_MZ2_MZ2_mSr2_mSi2(const double MZ2,const double mSr2 ,const double mSi2) const;
    gslpp::complex B00_MZ2_MZ2_mSi2_mSp2(const double MZ2,const double mSi2 ,const double mSp2) const;
    gslpp::complex B00_MZ2_MZ2_mSp2_mSp2(const double MZ2,const double mSp2) const;


     // End Passarino Veltman Functions //
    
    
    double RpepsTHDMW;
    gslpp::vector<gslpp::complex> unitarityeigenvalues;
    gslpp::vector<gslpp::complex> NLOunitarityeigenvalues;

    double rh_QuQu;/**< Squared relative coupling of @f$h@f$ to two up type quarks. This is @f$r^{(h)}_{Q_uQ_u}@f$*/
    double rh_VV;/**< Squared relative coupling of @f$h@f$ to two massive vector bosons. This is @f$r^{(h)}_{WW}=r^{(h)}_{ZZ}@f$*/
    double rh_gg;/**< Squared relative coupling of @f$h@f$ to two gluons. This is @f$r^{(h)}_{gg}@f$.*/
    double rh_QdQd;/**< quared relative coupling of @f$h@f$ to two down type quarks. This is @f$r^{(h)}_{Q_dQ_d}@f$.*/
    double rh_ll;/**< Squared relative coupling of @f$h@f$ to two charged leptons. This is @f$r^{(h)}_{\ell \ell}@f$.*/
    double rh_gaga;/**< Squared relative coupling of @f$h@f$ to two photons. This is @f$r^{(h)}_{\gamma \gamma}@f$. */
    double rh_Zga;/**< Squared relative coupling of @f$h@f$ to a @f$Z@f$ boson and a photon. This is @f$r^{(h)}_{Z\gamma}@f$. */
    
    double sumModBRs; /**< Sum of the modified branching ratios. This is @f$\sum _i r^{(h)}_{i} BR^{\text SM}(h\to i)@f$*/
    double Gamma_h; /**< Total h decay rate in the THDM. This is @f$\Gamma_h@f$*/
    double THDM_BR_h_bb; /**< @f$h@f$ branching ratio to two @f$b@f$ quarks in the %THDM. This is @f$BR^{\text{THDM}}(h\to b \bar b)@f$*/ //This should be changed for THDMW_BR_h_bb
    double THDM_BR_h_gaga; /**< branching ratio to two photons in the %THDM. This is @f$BR^{\text{THDM}}(h\to \gamma \gamma)@f$*/ //This should be changed for THDMW_BR_h_gaga
    double THDM_BR_h_tautau; /**< @f$h@f$ branching ratio to two @f$\tau@f$ leptons in the %THDM. This is @f$BR^{\text{THDM}}(h\to \tau\tau )@f$*/ //This should be changed for THDMW_BR_h_tautau
    double THDM_BR_h_WW;  /**<  @f$h@f$ branching ratio to two @f$W@f$ bosons in the %THDM. This is @f$BR^{\text{THDM}}(h\to WW)@f$*/ //This should be changed for THDMW_BR_h_WW
    double THDM_BR_h_ZZ;/**< @f$h@f$ branching ratio to two @f$Z@f$ bosons in the %THDM. This is @f$BR^{\text{THDM}}(h\to ZZ)@f$*/ //This should be changed for THDMW_BR_h_ZZ
    
protected:

private:

    const THDMW * myTHDMW;
    RunnerTHDMW * myRunnerTHDMW;
    const PVfunctions PV;

    /**
     * @brief Cache size.
     * @details Determines the size of the cache. If it is set to 5, the cache will remember the last five function calls and store their results.
     */
    static const int CacheSize = 5;

    /**
     * @brief Check whether for the latest set of parameters a value is in the cache.
     * @details Takes a complex value.
     */
    int CacheCheck(const gslpp::complex cache[][CacheSize],
                   const int NumPar, const double params[]) const;

    /**
     * @brief Check whether for the latest set of parameters a value is in the cache.
     * @details Takes a real value.
     */
    int CacheCheckReal(const double cache[][CacheSize],
                   const int NumPar, const double params[]) const;

    /**
     * @brief Adds a new result and its parameters into the cache.
     * @details The new values are added on top. The oldest set on the stack is deleted. Takes a complex value.
     */
    void CacheShift(gslpp::complex cache[][CacheSize], const int NumPar,
                    const double params[], const gslpp::complex newResult) const; 

    /**
     * @brief Adds a new result and its parameters into the cache.
     * @details The new values are added on top. The oldest set on the stack is deleted. Takes a real value.
     */
    void CacheShiftReal(double cache[][CacheSize], const int NumPar,
                    const double params[], const double newResult) const; 

    /**
     * @brief Amplitude for the SM Higgs boson decay to diphotons including the up-type quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_h_U(const double mHl2, const double Mu, const double Mc, const double Mt) const;
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to diphotons including the charm and top quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_HH_U(const double mHh2, const double Mc, const double Mt) const;
    
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to diphotons including the charm and top quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_A_U(const double mA2, const double Mc, const double Mt) const;
    
    /**
     * @brief Amplitude for the SM Higgs boson decay to diphotons including the down-type quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_h_D(const double mHl2, const double Md, const double Ms, const double Mb) const;
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to diphotons including the strange and bottom quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_HH_D(const double mHh2, const double Ms, const double Mb) const;
    
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to diphotons including the strange and bottom quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex I_A_D(const double mA2, const double Ms, const double Mb) const;
    
    /**
     * @brief Amplitude for the SM Higgs boson decay to diphotons including the leptons in the loop.
     * @details 
     */
    gslpp::complex I_h_L(const double mHl2, const double Me, const double Mmu, const double Mtau) const;
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to diphotons including muons and taus in the loop.
     * @details
     */
    gslpp::complex I_HH_L(const double mHh2, const double Mmu, const double Mtau) const;
    
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to diphotons including muons and taus in the loop.
     * @details
     */
    gslpp::complex I_A_L(const double mA2, const double Mmu, const double Mtau) const;
    
    /**
     * @brief Amplitude for a CP-even Higgs boson decay to diphotons including the W boson in the loop.
     * @details
     */
    gslpp::complex I_H_W(const double mH, const double MW) const;
    
    /**
     * @brief Amplitude for a CP-even Higgs boson decay to diphotons including the charged Higgs boson in the loop.
     * @details
     */
    gslpp::complex I_H_Hp(const double mHp2, const double mH) const;

    /**
     * @brief Amplitude for the SM Higgs boson decay to a photon and a Z boson including the up-type quarks in the loop.
     * @details
     */
    gslpp::complex A_h_U(const double mHl2, const double cW2, const double Mu, const double Mc, const double Mt, const double MZ) const;
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to a photon and a Z boson including the charm and top quarks in the loop.
     * @details
     */
    gslpp::complex A_HH_U(const double mHh2, const double cW2, const double Mc, const double Mt, const double MZ) const;
    
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to a photon and a Z boson including the charm and top quarks in the loop.
     * @details
     */
    gslpp::complex A_A_U(const double mA2, const double cW2, const double Mc, const double Mt, const double MZ) const;
    
    /**
     * @brief Amplitude for the SM Higgs boson decay to a photon and a Z boson including the down-type quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex A_h_D(const double mHl2, const double cW2, const double Md, const double Ms, const double Mb, const double MZ) const;
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to a photon and a Z boson including the strange and bottom quarks in the loop.
     * @details
     */
    gslpp::complex A_HH_D(const double mHh2, const double cW2, const double Ms, const double Mb, const double MZ) const;
   
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to a photon and a Z boson including the strange and bottom quarks in the loop.
     * @details This function can also be used for the gluon fusion production adding the appropriate factor
     */
    gslpp::complex A_A_D(const double mA2, const double cW2, const double Ms, const double Mb, const double MZ) const;
    
    /**
     * @brief Amplitude for the SM Higgs boson decay to a photon and a Z boson including the leptons in the loop.
     * @details 
     */
    gslpp::complex A_h_L(const double mHl2, const double cW2, const double Me, const double Mmu, const double Mtau, const double MZ) const;
    
    
    /**
     * @brief Amplitude for a heavy CP-even Higgs boson decay to a photon and a Z boson including muons and taus in the loop.
     * @details
     */
    gslpp::complex A_HH_L(const double mHh2, const double cW2, const double Mmu, const double Mtau, const double MZ) const;
    
    /**
     * @brief Amplitude for a CP-odd Higgs boson decay to a photon and a Z boson including muons and taus in the loop.
     * @details
     */
    gslpp::complex A_A_L(const double mA2, const double cW2, const double Mmu, const double Mtau, const double MZ) const;
    
    /**
     * @brief Amplitude for a CP-even Higgs boson decay to a photon and a Z boson including the W boson in the loop.
     * @details
     */
    gslpp::complex A_H_W(const double mH, const double cW2, const double MW, const double MZ) const;
    
    /**
     * @brief Amplitude for a CP-even Higgs boson decay to a photon and a Z boson including the charged Higgs boson in the loop.
     * @details
     */
    gslpp::complex A_H_Hp(const double mHp2, const double mH, const double cW2, const double MZ) const;

    
    void computeHHlimits();
    
    
    mutable gslpp::complex I_h_U_cache[5][CacheSize];
    mutable gslpp::complex I_HH_U_cache[4][CacheSize];
    mutable gslpp::complex I_A_U_cache[4][CacheSize];
    mutable gslpp::complex I_h_D_cache[5][CacheSize];
    mutable gslpp::complex I_HH_D_cache[4][CacheSize];
    mutable gslpp::complex I_A_D_cache[4][CacheSize];
    mutable gslpp::complex I_h_L_cache[5][CacheSize];
    mutable gslpp::complex I_HH_L_cache[4][CacheSize];
    mutable gslpp::complex I_A_L_cache[4][CacheSize];
    mutable gslpp::complex I_H_W_cache[3][CacheSize];
    mutable gslpp::complex I_H_Hp_cache[3][CacheSize];

    mutable gslpp::complex A_h_U_cache[7][CacheSize];
    mutable gslpp::complex A_HH_U_cache[6][CacheSize];
    mutable gslpp::complex A_A_U_cache[6][CacheSize];
    mutable gslpp::complex A_h_D_cache[7][CacheSize];
    mutable gslpp::complex A_HH_D_cache[6][CacheSize];
    mutable gslpp::complex A_A_D_cache[6][CacheSize];
    mutable gslpp::complex A_h_L_cache[7][CacheSize];
    mutable gslpp::complex A_HH_L_cache[6][CacheSize];
    mutable gslpp::complex A_A_L_cache[6][CacheSize];
    mutable gslpp::complex A_H_W_cache[5][CacheSize];
    mutable gslpp::complex A_H_Hp_cache[5][CacheSize];
    
    
    
    
    mutable gslpp::complex A0_MZ2_mSp2_cache[3][CacheSize];
    mutable gslpp::complex A0_MZ2_mSr2_cache[3][CacheSize];
    mutable gslpp::complex A0_MZ2_mSi2_cache[3][CacheSize];
    mutable gslpp::complex B0_MZ2_0_mSp2_mSp2_cache[3][CacheSize];
    //mutable gslpp::complex B00_MZ2_0_mSr2_mSp2_cache[4][CacheSize];
    //mutable gslpp::complex B00_MZ2_0_mSi2_mSp2_cache[4][CacheSize];
    //mutable gslpp::complex B00_MZ2_0_mSp2_mSp2_cache[3][CacheSize];
    mutable gslpp::complex B00_MZ2_MZ2_mSr2_mSp2_cache[4][CacheSize];
    mutable gslpp::complex B00_MZ2_MZ2_mSr2_mSi2_cache[4][CacheSize];
    mutable gslpp::complex B00_MZ2_MZ2_mSi2_mSp2_cache[4][CacheSize];
    mutable gslpp::complex B00_MZ2_MZ2_mSp2_mSp2_cache[3][CacheSize];
    
    
    
    //mutable double logip_th_pp_SrSr_jjjj_cache[5][CacheSize];
    mutable double ip_th_pp_Si_bb_8TeV_cache[4][CacheSize];
    mutable double ip_th_pp_Si_bb_cache[4][CacheSize];
    mutable double ip_th_pp_Sr_bb_8TeV_cache[5][CacheSize];
    mutable double ip_th_pp_Sr_bb_cache[5][CacheSize];
    mutable double ip_th_pp_Sibb_bbbb_cache[4][CacheSize];
    mutable double ip_th_pp_Sibb_bbbb_8TeV_cache[4][CacheSize];
    mutable double ip_th_pp_Srbb_bbbb_cache[5][CacheSize];
    mutable double ip_th_pp_Srbb_bbbb_8TeV_cache[5][CacheSize];
    mutable double ip_th_pp_Sitt_tttt_cache[4][CacheSize];
    mutable double ip_th_pp_Stb_tbtb_cache[4][CacheSize];
    mutable double ip_th_pp_SrSr_jjjj_cache[5][CacheSize];
    mutable double ip_th_pp_Sr_jj_cache[5][CacheSize];
    mutable double ip_th_pp_Srtt_tttt_cache[5][CacheSize];
    mutable double ip_th_pp_Sr_tt_cache[5][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_CMS8_cache_e[2][CacheSize];
    mutable double ip_ex_bb_phi_bb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_bb_CMS8_cache_e[2][CacheSize];
    mutable double ip_ex_gg_phi_tt_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_tt_ATLAS8_cache_e[2][CacheSize];
    mutable double ip_ex_bb_phi_tt_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tt_ATLAS13_cache_e[2][CacheSize];
    mutable double ip_ex_tt_phi_tt_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_tt_phi_tt_ATLAS13_cache_e[2][CacheSize];
    mutable double ip_ex_pp_H_hh_bbbb_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_H_hh_bbbb_ATLAS13_cache_e[2][CacheSize];
    mutable double ip_ex_pp_phi_bb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_bb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_bb_CMS13_cache_e[2][CacheSize];
    mutable double ip_ex_pp_H_hh_bbbb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_H_hh_bbbb_CMS13_cache_e[2][CacheSize];
    mutable double ip_ex_pp_Hpm_tb_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hpm_tb_ATLAS8_cache_e[2][CacheSize];
    mutable double ip_ex_pp_Hp_tb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hp_tb_CMS8_cache_e[2][CacheSize];
    mutable double ip_ex_pp_Hp_tb_ATLAS13_cache[2][CacheSize];
    //mutable double ip_ex_pp_Hp_tb_ATLAS13_1_cache_e[2][CacheSize];
    //mutable double ip_ex_pp_Hp_tb_ATLAS13_2_cache[2][CacheSize];
    //mutable double ip_ex_pp_Hp_tb_ATLAS13_2_cache_e[2][CacheSize];
    mutable double ip_ex_ggF_H_hh_bbbb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_ggF_H_hh_bbbb_CMS13_cache_e[2][CacheSize];
    mutable double ip_ex_pp_Gkk_tt_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_R_gg_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_SS_jjjj_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_H_bb_CMS13_cache[2][CacheSize];

    
    
    
    
        /**
     * @brief Fills all required arrays with the values read from the tables.
     */
    void read();
    
        /**
     * @brief This function reads values from a table and returns them as an array.
     * @return the tabled values
     */
    gslpp::matrix<double> readTable(std::string filename, int rowN, int colN);

    
    
    
    
    gslpp::matrix<double>  ATLAS8_gg_phi_tt;/**< ATLAS observed @f$95\%@f$ upper cross section limits at 8 TeV, depending on the Higgs mass. */
    gslpp::matrix<double>   ATLAS8_gg_phi_tt_e;/**< ATLAS expected @f$95\%@f$ upper cross section limits at 8 TeV, depending on the Higgs mass. */
    gslpp::matrix<double>  CMS8_pp_H_hh_bbbb, CMS8_bb_phi_bb;/**< CMS observed @f$95\%@f$ upper cross section limits at 8 TeV, depending on the Higgs mass. */
    gslpp::matrix<double>  Dummy;/**< This will be deleted by Scientific Linux */
    gslpp::matrix<double>  CMS8_pp_H_hh_bbbb_e, CMS8_bb_phi_bb_e;/**< CMS expected @f$95\%@f$ upper cross section limits at 8 TeV, depending on the Higgs mass. */
//    gslpp::matrix<double> CMS_ggF_phi_gaga_ep2, CMS_ggF_phi_gaga_em2;
    gslpp::matrix<double> ATLAS13_bb_phi_tt, ATLAS13_tt_phi_tt, ATLAS13_pp_H_hh_bbbb;/**< ATLAS observed @f$95\%@f$ upper cross section limits at 13 TeV, depending on the Higgs mass. */
    gslpp::matrix<double> ATLAS13_bb_phi_tt_e, ATLAS13_tt_phi_tt_e, ATLAS13_pp_H_hh_bbbb_e;/**< ATLAS expected @f$95\%@f$ upper cross section limits at 13 TeV, depending on the Higgs mass. */
    gslpp::matrix<double> CMS13_pp_phi_bb, CMS13_pp_H_hh_bbbb, CMS13_ggF_H_hh_bbbb;/**< CMS observed @f$95\%@f$ upper cross section limits at 13 TeV, depending on the Higgs mass. */
    gslpp::matrix<double> CMS8_pp_phi_bb;/**< CMS observed @f$95\%@f$ upper cross section limits at 8 TeV, depending on the Higgs mass. */
    gslpp::matrix<double> CMS13_pp_phi_bb_e, CMS13_pp_H_hh_bbbb_e, CMS13_ggF_H_hh_bbbb_e;/**< CMS expected @f$95\%@f$ upper cross section limits at 13 TeV, depending on the Higgs mass. */
    gslpp::matrix<double> CMS13_pp_R_gg;/**< CMS observed @f$95\%@f$ upper cross section limits at 13 TeV for resonances decaying to two gluons. */
    gslpp::matrix<double> ATLAS8_pp_Hpm_tb;/**< ATLAS observed @f$95\%@f$ upper cross section limits at 8 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> ATLAS8_pp_Hpm_tb_e;/**< ATLAS expected @f$95\%@f$ upper cross section limits at 8 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> CMS8_pp_Hp_tb;/**< CMS observed @f$95\%@f$ upper cross section limits at 8 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> CMS8_pp_Hp_tb_e;/**< CMS expected @f$95\%@f$ upper cross section limits at 8 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> CMS13_bb_H_bb;/**< CMS observed @f$95\%@f$ upper cross section limits at 13 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> ATLAS13_pp_Hp_tb;/**< ATLAS observed @f$95\%@f$ upper cross section limits at 13 TeV, depending on the charged Higgs mass. */
//    gslpp::matrix<double> ATLAS13_pp_Hp_tb1, ATLAS13_pp_Hp_tb2;/**< ATLAS observed @f$95\%@f$ upper cross section limits at 13 TeV, depending on the charged Higgs mass. */
//    gslpp::matrix<double> ATLAS13_pp_Hp_tb1_e, ATLAS13_pp_Hp_tb2_e;/**< @brief ATLAS expected @f$95\%@f$ upper cross section limits at 13 TeV, depending on the charged Higgs mass. */
    gslpp::matrix<double> ATLAS13_pp_Gkk_tt;/**< ATLAS expected @f$95\%@f$ upper cross section limits at 13 TeV, depending on the Kaluza-Klein Graviton mass. Process @f$pp\to G_{kk}  \to t\bar t @f$. */
    gslpp::matrix<double> ATLAS13_pp_SS_jjjj;/**< ATLAS expected @f$95\%@f$ upper cross section limits at 13 TeV, depending on the scalar gluon mass. Process @f$pp\to \rho \rho  \to  j j j j @f$. */
    gslpp::matrix<double> MadGraph_pp_Sr_tt;/**< Table for cross section for @f$pp\to S_{R}  \to  t\bar t@f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Srtt_tttt;/**< Table for cross section for @f$pp\to S_{R} t\bar t  \to  t\bar t t\bar t@f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Sr_jj;/**< Table for cross section for @f$pp\to S_{R}  \to  j j @f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_SrSr_jjjj;/**< Table for cross section ratio for @f$pp\to S_{R} S_{R}  \to  j j j j @f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Stb_tbtb;/**< Table for cross section for @f$pp\to S^+ t\bar b  \to  t\bar b t b\bar  @f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Sitt_tttt;/**< Table for cross section for @f$pp\to S_{I} t\bar t  \to  t\bar t t\bar t@f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Srbb_bbbb;/**< Table for cross section for @f$pp\to S_{R} b\bar b  \to  b\bar b b\bar b@f$ generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Srbb_bbbb_8TeV;/**< Table for cross section for @f$pp\to S_{R} b\bar b  \to  b\bar b b\bar b@f$  generated with Madgraph5 at 8 TeV */
    gslpp::matrix<double> MadGraph_pp_Sibb_bbbb;/**< Table for cross section for @f$pp\to S_{I} b\bar b  \to  b\bar b b\bar b@f$  generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Sibb_bbbb_8TeV;/**< Table for cross section ratio for @f$pp\to S_{I} b\bar b  \to  b\bar b b\bar b@f$  generated with Madgraph5 at 8 TeV. */
    gslpp::matrix<double> MadGraph_pp_Si_bb;/**< Table for cross section for @f$pp\to S_{I}  \to b\bar b@f$  generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Si_bb_8TeV;/**< Table for cross section for @f$pp\to S_{I}  \to b\bar b@f$  generated with Madgraph5 at 8 TeV. */
    gslpp::matrix<double> MadGraph_pp_Sr_bb;/**< Table for cross section for @f$pp\to S_{R}  \to b\bar b@f$  generated with Madgraph5 at 13 TeV. */
    gslpp::matrix<double> MadGraph_pp_Sr_bb_8TeV;/**< Table for cross section for @f$pp\to S_{R}  \to b\bar b@f$  generated with Madgraph5 at 8 TeV. */
    gslpp::matrix<double> arraybsgamma;/**< @f$b\to s \gamma@f$ table, depending on logtb and the logarithm of the charged Higgs mass. */
    
    
    
    
        /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to two bottom quark pairs.
     * @return @f$[\sigma_{gg\to \phi}\cdot BR(\phi\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1503.04114, Figure 5, left @cite Khachatryan:2015yea.
     */
    double ip_ex_pp_phi_hh_bbbb_CMS8(double mass);
    
        /**
     * @brief Interpolating function for the expected CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to two bottom quark pairs.
     * @return @f$[\sigma_{gg\to \phi}\cdot BR(\phi\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1503.04114, Figure 5, left @cite Khachatryan:2015yea.
     */
    double ip_ex_pp_phi_hh_bbbb_CMS8_e(double mass);
    
        /**
     * @brief Interpolating function for the observed CMS upper limit on a bottom quark produced scalar resonance decaying to two bottom quarks.
     * @return @f$[\sigma_{bb\to \phi}\cdot BR(\phi\to b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-HIG-14-017, Figure 6 @cite Khachatryan:2015tra.
     */
    double ip_ex_bb_phi_bb_CMS8(double mass);

    /**
     * @brief Interpolating function for the expected CMS upper limit on a bottom quark produced scalar resonance decaying to two bottom quarks.
     * @return @f$[\sigma_{bb\to \phi}\cdot BR(\phi\to b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-HIG-14-017, Figure 6 @cite Khachatryan:2015tra.
     */
    double ip_ex_bb_phi_bb_CMS8_e(double mass);
    
    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a gluon-gluon produced scalar resonance decaying to a top quark pair.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1505.07018, Figure 11d @cite Aad:2015fna.
     */
    double ip_ex_gg_phi_tt_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a gluon-gluon produced scalar resonance decaying to a top quark pair.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1505.07018, Figure 11d @cite Aad:2015fna.
     */
    double ip_ex_gg_phi_tt_ATLAS8_e(double mass);

        /**
     * @brief Interpolating function for the observed ATLAS upper limit on a bb associated scalar resonance decaying to t quarks.
     * @return @f$[\sigma_{bb\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 21 @cite TheATLAScollaboration:2016loc.
     */
    double ip_ex_bb_phi_tt_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a bb associated scalar resonance decaying to t quarks.
     * @return @f$[\sigma_{bb\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 21 @cite TheATLAScollaboration:2016loc.
     */
    double ip_ex_bb_phi_tt_ATLAS13_e(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a tt associated scalar resonance decaying to t quarks.
     * @return @f$[\sigma_{tt\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 22 @cite TheATLAScollaboration:2016loc.
     */
    double ip_ex_tt_phi_tt_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a tt associated scalar resonance decaying to t quarks.
     * @return @f$[\sigma_{tt\to \phi}\cdot BR(\phi\to t\bar t)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 22 @cite TheATLAScollaboration:2016loc.
     */
    double ip_ex_tt_phi_tt_ATLAS13_e(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a spin-2 resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-049, Figure 11 @cite ATLAS:2016ixk.
     */
    double ip_ex_pp_H_hh_bbbb_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a spin-2 resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-049, Figure 11 @cite ATLAS:2016ixk.
     */
    double ip_ex_pp_H_hh_bbbb_ATLAS13_e(double mass);
    
    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to a b quark pair.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi \to b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-HIG-16-025, Figure 5 @cite CMS:2016ncz.
     */
    double ip_ex_pp_phi_bb_CMS13(double mass);
    
    
    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to a b quark pair.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi \to b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from 180206149.
     */
    double ip_ex_pp_phi_bb_CMS8(double mass);

    /**
     * @brief Interpolating function for the expected CMS upper limit on a scalar resonance decaying to a b quark pair.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi \to b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-HIG-16-025, Figure 5 @cite CMS:2016ncz.
     */
    double ip_ex_pp_phi_bb_CMS13_e(double mass);

       /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-HIG-16-002, Figure 7 @cite CMS:2016tlj.
     */
    double ip_ex_pp_H_hh_bbbb_CMS13(double mass);

    /**
     * @brief Interpolating function for the expected CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-HIG-16-002, Figure 7 @cite CMS:2016tlj.
     */
    double ip_ex_pp_H_hh_bbbb_CMS13_e(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[2\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1512.03704, Figure 6 @cite Aad:2015typ.
     */
    double ip_ex_pp_Hpm_tb_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[2\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1512.03704, Figure 6 @cite Aad:2015typ.
     */
    double ip_ex_pp_Hpm_tb_ATLAS8_e(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1508.07774, Table 11 @cite Khachatryan:2015qxa.
     */
    double ip_ex_pp_Hp_tb_CMS8(double mass);

    /**
     * @brief Interpolating function for the expected CMS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1508.07774, Table 11 @cite Khachatryan:2015qxa.
     */
    double ip_ex_pp_Hp_tb_CMS8_e(double mass);
    
    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-089, Figure 12 @cite ATLAS:2016qiq.
     */
    double ip_ex_pp_Hp_tb_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-089, Figure 12 @cite ATLAS:2016qiq.
     */
    //double ip_ex_pp_Hp_tb_ATLAS13_1_e(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 23 @cite ATLAS:2016btu.
     */
    //double ip_ex_pp_Hp_tb_ATLAS13_2(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a singly charged scalar resonance decaying to a @f$t@f$ quark and a @f$b@f$ quark.
     * @return @f$[\sigma_{pp\to H^+}\cdot BR(H^+\to tb)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from ATLAS-CONF-2016-104, Figure 23 @cite ATLAS:2016btu.
     */
    //double ip_ex_pp_Hp_tb_ATLAS13_2_e(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{gg\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-B2G-16-026, Figure 9 left @cite CMS:2017gxe.
     */
    double ip_ex_ggF_H_hh_bbbb_CMS13(double mass);

    /**
     * @brief Interpolating function for the expected CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{gg\to H}\cdot BR(H\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from CMS-PAS-B2G-16-026, Figure 9 left @cite CMS:2017gxe.
     */
    double ip_ex_ggF_H_hh_bbbb_CMS13_e(double mass);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on pp -> Gkk (Kaluza-Klein graviton) -> t tbar
     * @return xsection times branching ratio
     * @details ATLAS arXiv:1804.01939, Fig. 16, 36.1 fb^-1, 13 TeV
     */
    double ip_ex_pp_Gkk_tt_ATLAS13(double mass);    
    
    /**
     * @brief Interpolating function for the expected CMS upper limit for resonances decaying to gluons
     * @return xsection times branching ratio
     * @details CMS CMS-CR-2018-204, Fig. 3 right green,  27 & 36  fb^-1, 13 TeV
     */
    double ip_ex_pp_R_gg_CMS13(double mass);    
    
    /**
     * @brief Interpolating function for the expected ATLAS upper limit on pp -> coloron coloron  -> j j j j 
     * @return xsection times branching ratio
     * @details # ATLAS arXiv:171007171, Fig. 9c,  36.7 fb^-1, 13 TeV
     */
    double ip_ex_pp_SS_jjjj_ATLAS13(double mass);  
    
    /**
     * @brief Interpolating function for the expected CMS upper limit on pp -> H b bbar  -> b bbar b bbar 
     * @return xsection times branching ratio
     * @details CMS arXiv:1805.12191, Fig. 6
     */
    double ip_ex_bb_H_bb_CMS13(double mass);  
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr -> t tbar
     * @return xsection times branching ratio of pp -> Sr -> t tbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sr_tt(double etaD, double etaU, double Lambda4, double mSr);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr t tbar -> t tbar t tbar
     * @return xsection times branching ratio of pp -> Sr t tbar-> t tbar t tbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Srtt_tttt(double etaD, double etaU, double Lambda4, double mSr);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr   -> j j 
     * @return xsection times branching ratio of pp -> Sr -> j j
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sr_jj(double etaD, double etaU, double Lambda4, double mSr);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr  Sr ->j j j j 
     * @return xsection times branching ratio of pp -> Sr Sr -> j j j j
     * @details Generated with MadGraph
     */
    double ip_th_pp_SrSr_jjjj(double etaD, double etaU, double Lambda4, double mSr);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> S+ tbar b -> t bbar tbar b 
     * @return xsection times branching ratio of p p -> S+ tbar b -> t bbar tbar b 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Stb_tbtb(double etaD, double etaU, double mS);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Si tbar t -> t tbar tbar t 
     * @return xsection times branching ratio of p p -> Si tbar t -> t tbar tbar t 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sitt_tttt(double etaD, double etaU, double mS);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr b bbar -> b bbar b bbar
     * @return xsection times branching ratio of pp -> Sr b bbar-> b bbar b bbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Srbb_bbbb(double etaD, double etaU, double Lambda4, double mSr);
    
        /**
     * @brief Interpolating function for the theoretical value of p p -> Sr b bbar -> b bbar b bbar
     * @return xsection times branching ratio of pp -> Sr b bbar-> b bbar b bbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Srbb_bbbb_8TeV(double etaD, double etaU, double Lambda4, double mSr);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Si bbar b -> b bbar bbar b 
     * @return xsection times branching ratio of p p -> Si bbar b -> b bbar bbar b 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sibb_bbbb(double etaD, double etaU, double mS);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Si bbar b -> b bbar bbar b 
     * @return xsection times branching ratio of p p -> Si bbar b -> b bbar bbar b 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sibb_bbbb_8TeV(double etaD, double etaU, double mS);
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr  ->  b bbar
     * @return xsection times branching ratio of pp -> Sr -> b bbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sr_bb(double etaD, double etaU, double Lambda4, double mSr);
    
        
    /**
     * @brief Interpolating function for the theoretical value of p p -> Sr  ->  b bbar at 8 TeV
     * @return xsection times branching ratio of pp -> Sr -> b bbar
     * @details Generated with MadGraph
     */
    double ip_th_pp_Sr_bb_8TeV(double etaD, double etaU, double Lambda4, double mSr);
    
    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Si -> b bbar 
     * @return xsection times branching ratio of p p -> Si  -> b bbar 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Si_bb(double etaD, double etaU, double mS);

    
    /**
     * @brief Interpolating function for the theoretical value of p p -> Si -> b bbar 
     * @return xsection times branching ratio of p p -> Si  -> b bbar 
     * @details Generated with MadGraph
     */
    double ip_th_pp_Si_bb_8TeV(double etaD, double etaU, double mS);
    
    
    /**
     * @brief loginterpolating function for the theoretical value of p p -> Sr  Sr ->j j j j 
     * @return xsection times branching ratio of pp -> Sr Sr -> j j j j
     * @details Generated with MadGraph
     */
    //double logip_th_pp_SrSr_jjjj(double etaD, double etaU, double Lambda4, double mass);
    
    
    

    gslpp::complex f_func(const double x) const;
    gslpp::complex g_func(const double x) const;

    gslpp::complex Int1(const double tau, const double lambda) const;
    gslpp::complex Int2(const double tau, const double lambda) const;

    void runTHDMWparameters();

    void computeUnitarity();
    gslpp::vector<gslpp::complex> betaeigenvalues;

    void computeSignalStrengthQuantities();

    std::string THDMWmodel;
    double Q_THDMW;
    double MZ;
    double vev;
    double tanb;
    double sinb;
    double cosb;
    double bma;
    double sina;
    double cosa;
    double lambda1;
    double lambda2;
    double lambda3;
    double lambda4;
    double lambda5;
    double mSsq;
    double mu1;
    double mu2;
    double mu3;
    double mu4;
    double mu5;
    double mu6;
    double nu1;
    double nu2;
    double nu3;
    double nu4;
    double nu5;
    double omega1;
    double omega2;
    double omega3;
    double omega4;
    double kappa1;
    double kappa2;
    double kappa3;
    double etaU;
    double etaD;
    double rho_b;
    double S_b;
    
    
     /**
     * @brief Linearly interpolates a table with one parameter dimension.
     * @return the interpolated value
     */
    double interpolate (gslpp::matrix<double> arrayTab, double x);
    
    /**
     * @brief Linearly interpolates a table with three parameter dimensions.
     * @return the interpolated value
     */
    double interpolate3D (gslpp::matrix<double> arrayTab, double x, double y, double z);
        
    /**
     * @brief Linearly interpolates a table with four parameter dimensions.
     * @return the interpolated value
     */
    double interpolate4D (gslpp::matrix<double> arrayTab, double x, double y, double z, double v);
   
    
    /**
     * @brief Linearly interpolates the logarithm in base 10 of a table with four parameter dimensions. The log is only taken 
     * on the values, not on the parameters.
     * @return the interpolated value
     */
    /*
    double loginterpolate4D (gslpp::matrix<double> arrayTab, double x, double y, double z, double v);
    */
    
    /**
     * @brief Interpolating function for the H production cross section via gluon-gluon fusion at 8 TeV.
     * @return @f$\sigma(gg\to H)@f$
     */
    double ip_cs_ppto2Sto4t_13(double etaD, double etaU, double THDMW_nu4, double mSR);
    
    
};

#endif	/* THDMWCACHE_H */
