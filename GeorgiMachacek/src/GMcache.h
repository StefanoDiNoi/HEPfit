/* 
 * Copyright (C) 2017 HEPfit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef GMCACHE_H
#define	GMCACHE_H

#include "GeorgiMachacek.h"
//#include "RunnerGM.h"
#include <cmath>
#include <stdexcept>

/**
 * @class GMcache
 * @ingroup GeorgiMachacek
 * @brief A class for the caching of %GeorgiMachacek objects.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 */
class GMcache {
    
public:

    /**
     * @brief GMcache constructor.
     * @details Reads all the tables values and stores them in the memory.
     */
    GMcache(const StandardModel& SM_i);

    /**
     * @brief GMcache destructor.
     */
    ~GMcache();

    /**
     * @brief This function reads values from a table and returns them as an array.
     * @return the tabled values
     */
    void readTable(gslpp::matrix<double>& arrayTab, std::string filename, int rowN, int colN);

    /**
     * @brief Linearly interpolates a table with one parameter dimension.
     * @return the interpolated value
     */
    double interpolate (gslpp::matrix<double>& arrayTab, double x);

    /**
     * @brief Linearly interpolates a table with two parameter dimensions.
     * @return the interpolated value
     */
    double interpolate2D (gslpp::matrix<double>& arrayTab, double x, double y);

    /**
     * @brief Fills all required arrays with the values read from the tables.
     */
    void read();


    gslpp::matrix<double> br_aa, br_tt, br_bb, br_tautau, br_cc, br_mumu, br_ZZ, br_WW; /**< SM Higgs branching ratio tables (obtained with HDECAY 6.10), depending on the Higgs mass. */


    gslpp::matrix<double> GammaHtot_SM; /**< Total SM decay width (obtained with HDECAY 6.10), depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ggH_8, log_cs_VBF_8, log_cs_WH_8, log_cs_ZH_8; /**< SM Higgs production cross section tables at 8 TeV from the LHC Higgs Cross Section Working Group, depending on the Higgs mass. */

    
    gslpp::matrix<double> log_cs_ggH_13, log_cs_VBF_13, log_cs_WH_13, log_cs_ZH_13; /**< SM Higgs production cross section tables at 13 TeV from the LHC Higgs Cross Section Working Group, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ttH_8; /**< SM Higgs production cross section table at 8 TeV obtained with MadGraph 5, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ttH_13; /**< SM Higgs production cross section table at 13 TeV obtained with MadGraph 5, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_bbH_8; /**< SM Higgs production cross section table at 8 TeV obtained with SusHi 1.5, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_bbH_13; /**< SM Higgs production cross section table at 13 TeV obtained with SusHi 1.5, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ggA_8, log_cs_ttA_8, log_cs_bbA_8; /**< CP-odd Higgs production cross section tables at 8 TeV obtained with HIGLU 4.34, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ggA_13, log_cs_ttA_13, log_cs_bbA_13; /**< CP-odd Higgs production cross section tables at 13 TeV obtained with HIGLU 4.34, depending on the Higgs mass. */


    gslpp::matrix<double> log_cs_ggHp_8; /**< Charged Higgs production cross section table at 8 TeV from LHCHXSWGMSSMCharged, depending on the charged Higgs mass and logtb. */


    gslpp::matrix<double> log_cs_ggHp_13; /**< Charged Higgs production cross section table at 13 TeV from LHCHXSWGMSSMCharged, depending on the charged Higgs mass and logtb. */

    gslpp::matrix<double> log_cs_ppH5ppH5mm_8, log_cs_ppH5ppH5mm_13, log_cs_VBFH5_8, log_cs_VBFH5_13;
    gslpp::matrix<double> log_cs_VBFH5m_8, log_cs_VBFH5m_13, log_cs_VBFH5mm_8, log_cs_VBFH5mm_13;
    gslpp::matrix<double> log_cs_VBFH5p_8, log_cs_VBFH5p_13, log_cs_VBFH5pp_8, log_cs_VBFH5pp_13;
    gslpp::matrix<double> log_cs_VHH5_8, log_cs_VHH5_13;
    gslpp::matrix<double> log_cs_VHH5mm_8, log_cs_VHH5mm_13, log_cs_VHH5pp_8, log_cs_VHH5pp_13;


    gslpp::matrix<double> ATLAS13_tt_phi_tt, ATLAS13_bb_phi_tt,
        CMS8_bb_phi_bb, CMS8_gg_phi_bb, CMS13_pp_phi_bb, CMS13_bb_phi_bb,
        ATLAS8_gg_phi_tautau, CMS8_gg_phi_tautau, ATLAS8_bb_phi_tautau, CMS8_bb_phi_tautau,
        ATLAS13_gg_phi_tautau, CMS13_gg_phi_tautau, ATLAS13_bb_phi_tautau, CMS13_bb_phi_tautau,
        ATLAS8_gg_phi_gaga, ATLAS13_pp_phi_gaga, CMS13_gg_phi_gaga,
        ATLAS8_pp_phi_Zga_llga, CMS8_pp_phi_Zga_llga, ATLAS13_gg_phi_Zga_llga, ATLAS13_gg_phi_Zga_qqga, CMS13_gg_phi_Zga,
        ATLAS8_gg_phi_ZZ, ATLAS8_VV_phi_ZZ, ATLAS13_gg_phi_ZZ_llllnunu, ATLAS13_VV_phi_ZZ_llllnunu,
        ATLAS13_gg_phi_ZZ_qqllnunu, ATLAS13_VV_phi_ZZ_qqllnunu, CMS13_pp_phi_ZZ_llqqnunull, CMS13_VV_phi_ZZ_llqqnunull, CMS13_pp_phi_ZZ_qqnunu,
        ATLAS8_gg_phi_WW, ATLAS8_VV_phi_WW, ATLAS13_gg_phi_WW_enumunu, ATLAS13_VV_phi_WW_enumunu,
        ATLAS13_gg_phi_WW_lnuqq, ATLAS13_VV_phi_WW_lnuqq, CMS13_ggVV_phi_WW_lnulnu, CMS13_pp_phi_WW_lnuqq,
        CMS8_mu_pp_phi_VV, ATLAS13_pp_phi_VV_qqqq,
        ATLAS8_gg_phi_hh, CMS8_pp_phi_hh_bbbb, CMS8_pp_phi_hh_gagabb, CMS8_gg_phi_hh_bbtautau, CMS8_pp_phi_hh_bbtautau,
        ATLAS13_pp_phi_hh_bbbb, CMS13_pp_phi_hh_bbbb_1, CMS13_pp_phi_hh_bbbb_2, CMS13_gg_phi_hh_bbbb, ATLAS13_pp_phi_hh_gagabb,
        CMS13_pp_phi_hh_gagabb, ATLAS13_pp_phi_hh_bbtautau, CMS13_pp_phi_hh_bbtautau_1, CMS13_pp_phi_hh_bbtautau_2, CMS13_pp_phi_hh_bblnulnu, ATLAS13_gg_phi_hh_gagaWW,
        ATLAS8_gg_A_hZ_bbZ, CMS8_gg_A_hZ_bbll, ATLAS8_gg_A_hZ_tautauZ, CMS8_gg_A_hZ_tautaull,
        ATLAS13_gg_A_Zh_Zbb, ATLAS13_bb_A_Zh_Zbb, CMS13_gg_A_Zh_Zbb_1, CMS13_bb_A_Zh_Zbb_1, CMS13_gg_A_Zh_Zbb_2, CMS13_bb_A_Zh_Zbb_2,
        CMS8_pp_A_phiZ_bbll, CMS8_pp_phi_AZ_bbll, ATLAS13_gg_A_phiZ_bbll, ATLAS13_bb_A_phiZ_bbll,
        ATLAS8_pp_Hpm_taunu, CMS8_pp_Hp_taunu, ATLAS13_pp_Hpm_taunu, CMS13_pp_Hpm_taunu,
        ATLAS8_pp_Hpm_tb, CMS8_pp_Hp_tb, ATLAS13_pp_Hpm_tb,
        ATLAS8_WZ_H5pm_WZ_qqll, ATLAS13_WZ_H5pm_WZ_lnull, CMS13_WZ_H5pm_WZ_lnull_1, CMS13_WZ_H5pm_WZ_lnull_2,
        ATLAS8_pp_H5ppmmH5mmpp_eeee, ATLAS8_pp_H5ppmmH5mmpp_emuemu, ATLAS8_pp_H5ppmmH5mmpp_mumumumu,
        ATLAS13_pp_H5ppmmH5mmpp_llll, ATLAS13_pp_H5ppmmH5mmpp_WWWW, CMS8_VV_H5ppmm_WW_jjll, CMS13_VV_H5ppmm_WW_jjll; /**< Observed @f$95\%@f$ upper cross section limits, depending on the invariant mass. */


    gslpp::matrix<double> ATLAS13_WZ_H5pm_WZ_lnull_e; /**< Expected @f$95\%@f$ upper cross section limits, depending on the invariant mass. */

    /**
     * @brief Interpolating function for the SM branching ratio to two top quarks.
     * @return @f$BR^{\text{SM}}(H\to t\bar t)@f$
     */
    double ip_Br_HPtott(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two bottom quarks.
     * @return @f$BR^{\text{SM}}(H\to b\bar b)@f$
     */
    double ip_Br_HPtobb(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two tau leptons.
     * @return @f$BR^{\text{SM}}(H\to \tau\tau)@f$
     */
    double ip_Br_HPtotautau(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two charm quarks.
     * @return @f$BR^{\text{SM}}(H\to c\bar c)@f$
     */
    double ip_Br_HPtocc(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two muons.
     * @return @f$BR^{\text{SM}}(H\to \mu \mu)@f$
     */
    double ip_Br_HPtomumu(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two @f$Z@f$ bosons.
     * @return @f$BR^{\text{SM}}(H\to ZZ)@f$
     */
    double ip_Br_HPtoZZ(double mass);

    /**
     * @brief Interpolating function for the SM branching ratio to two @f$W@f$ bosons.
     * @return @f$BR^{\text{SM}}(H\to WW)@f$
     */
    double ip_Br_HPtoWW(double mass);

    /**
     * @brief Interpolating function for the total SM Higgs decay width.
     * @return @f$\Gamma^{\text{tot}}_H@f$
     */
    double ip_GammaHPtotSM(double mass);

    /**
     * @brief Interpolating function for the H production cross section via gluon-gluon fusion at 8 TeV.
     * @return @f$\sigma(gg\to H)@f$
     */
    double ip_cs_ggtoH_8(double mass);

    /**
     * @brief Interpolating function for the H production cross section via gluon-gluon fusion at 13 TeV.
     * @return @f$\sigma(gg\to H)@f$
     */
    double ip_cs_ggtoH_13(double mass);

    /**
     * @brief Interpolating function for the H production cross section via vector boson fusion at 8 TeV.
     * @return @f$\sigma(VV\to H)@f$
     */
    double ip_cs_VBFtoH_8(double mass);

    /**
     * @brief Interpolating function for the H production cross section via vector boson fusion at 13 TeV.
     * @return @f$\sigma(VV\to H)@f$
     */
    double ip_cs_VBFtoH_13(double mass);

    /**
     * @brief Interpolating function for the W associated H production cross section at 8 TeV.
     * @return @f$\sigma(W\to WH)@f$
     */
    double ip_cs_WtoWH_8(double mass);

    /**
     * @brief Interpolating function for the W associated H production cross section at 13 TeV.
     * @return @f$\sigma(W\to WH)@f$
     */
    double ip_cs_WtoWH_13(double mass);

    /**
     * @brief Interpolating function for the Z associated H production cross section at 8 TeV.
     * @return @f$\sigma(Z\to ZH)@f$
     */
    double ip_cs_ZtoZH_8(double mass);

    /**
     * @brief Interpolating function for the Z associated H production cross section at 13 TeV.
     * @return @f$\sigma(Z\to ZH)@f$
     */
    double ip_cs_ZtoZH_13(double mass);

    /**
     * @brief Interpolating function for the top associated H production cross section at 8 TeV.
     * @return @f$\sigma(pp\to t \bar t H)@f$
     */
    double ip_cs_pptottH_8(double mass);

    /**
     * @brief Interpolating function for the top associated H production cross section at 13 TeV.
     * @return @f$\sigma(pp\to t \bar t H)@f$
     */
    double ip_cs_pptottH_13(double mass);

    /**
     * @brief Interpolating function for the bottom associated H production cross section at 8 TeV.
     * @return @f$\sigma(pp\to b \bar b H)@f$
     */
    double ip_cs_pptobbH_8(double mass);

    /**
     * @brief Interpolating function for the bottom associated H production cross section at 13 TeV.
     * @return @f$\sigma(pp\to b \bar b H)@f$
     */
    double ip_cs_pptobbH_13(double mass);

    /**
     * @brief Interpolating function for the A production cross section via gluon-gluon fusion at 8 TeV.
     * @return @f$\sigma(gg\to A)@f$
     */
    double ip_cs_ggtoA_8(double mass);

    /**
     * @brief Interpolating function for the A production cross section via gluon-gluon fusion at 13 TeV.
     * @return @f$\sigma(gg\to A)@f$
     */
    double ip_cs_ggtoA_13(double mass);

    /**
     * @brief Interpolating function for the top associated A production cross section at 8 TeV.
     * @return @f$\sigma(pp\to t \bar t A)@f$
     */
    double ip_cs_pptottA_8(double mass);

    /**
     * @brief Interpolating function for the top associated A production cross section at 13 TeV.
     * @return @f$\sigma(pp\to t \bar t A)@f$
     */
    double ip_cs_pptottA_13(double mass);

    /**
     * @brief Interpolating function for the bottom associated A production cross section at 8 TeV.
     * @return @f$\sigma(pp\to b \bar b A)@f$
     */
    double ip_cs_pptobbA_8(double mass);

    /**
     * @brief Interpolating function for the bottom associated A production cross section at 13 TeV.
     * @return @f$\sigma(pp\to b \bar b A)@f$
     */
    double ip_cs_pptobbA_13(double mass);

    /**
     * @brief Interpolating function for the H+ production cross section from two gluons at 8 TeV.
     * @return @f$\sigma(gg\to H^+)@f$
     */
    double ip_cs_ggtoHp_8(double mHp, double logtb);

    /**
     * @brief Interpolating function for the H+ production cross section from two gluons at 13 TeV.
     * @return @f$\sigma(gg\to H^+)@f$
     */
    double ip_cs_ggtoHp_13(double mHp, double logtb);


    double ip_cs_ppH5ppH5mm_8(double mass);
    double ip_cs_ppH5ppH5mm_13(double mass);
    double ip_cs_VBFH5_8(double mass);
    double ip_cs_VBFH5_13(double mass);
    double ip_cs_VBFH5m_8(double mass);
    double ip_cs_VBFH5m_13(double mass);
    double ip_cs_VBFH5mm_8(double mass);
    double ip_cs_VBFH5mm_13(double mass);
    double ip_cs_VBFH5p_8(double mass);
    double ip_cs_VBFH5p_13(double mass);
    double ip_cs_VBFH5pp_8(double mass);
    double ip_cs_VBFH5pp_13(double mass);
    double ip_cs_VHH5_8(double mass);
    double ip_cs_VHH5_13(double mass);
    double ip_cs_VHH5mm_8(double mass);
    double ip_cs_VHH5mm_13(double mass);
    double ip_cs_VHH5pp_8(double mass);
    double ip_cs_VHH5pp_13(double mass);


    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from 1807.11883.
     */
    double ip_ex_tt_phi_tt_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from ATLAS-CONF-2016-104.
     */
    double ip_ex_bb_phi_tt_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1506.08329.
     */
    double ip_ex_bb_phi_bb_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1802.06149.
     */
    double ip_ex_gg_phi_bb_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-16-025.
     */
    double ip_ex_pp_phi_bb_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1805.12191.
     */
    double ip_ex_bb_phi_bb_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a gluon-gluon produced scalar resonance decaying to two tau leptons.
     * @return @f$[\sigma_{gg\to \phi}\cdot BR(\phi\to \tau \tau)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1409.6064, Figure 11a @cite Aad:2014vgg.
     */
    double ip_ex_gg_phi_tautau_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-14-029.
     */
    double ip_ex_gg_phi_tautau_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a bottom quark produced scalar resonance decaying to two tau leptons.
     * @return @f$[\sigma_{bb\to \phi}\cdot BR(\phi\to \tau \tau)]_{\text{ATLAS,95\%}}@f$
     * @details Taken from arXiv:1409.6064, Figure 11b @cite Aad:2014vgg.
     */
    double ip_ex_bb_phi_tautau_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-14-029.
     */
    double ip_ex_bb_phi_tautau_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from ATLAS-CONF-2017-050.
     */
    double ip_ex_gg_phi_tautau_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1803.06553.
     */
    double ip_ex_gg_phi_tautau_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from ATLAS-CONF-2017-050.
     */
    double ip_ex_bb_phi_tautau_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1803.06553.
     */
    double ip_ex_bb_phi_tautau_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1407.6583.
     */
    double ip_ex_gg_phi_gaga_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1707.04147.
     */
    double ip_ex_pp_phi_gaga_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1609.02507.
     */
    double ip_ex_gg_phi_gaga_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1407.8150.
     */
    double ip_ex_pp_phi_Zga_llga_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-16-014.
     */
    double ip_ex_pp_phi_Zga_llga_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1708.00212.
     */
    double ip_ex_gg_phi_Zga_llga_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1805.01908.
     */
    double ip_ex_gg_phi_Zga_qqga_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1712.03143.
     */
    double ip_ex_gg_phi_Zga_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1507.05930.
     */
    double ip_ex_gg_phi_ZZ_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1507.05930.
     */
    double ip_ex_VV_phi_ZZ_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1712.06386.
     */
    double ip_ex_gg_phi_ZZ_llllnunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1712.06386.
     */
    double ip_ex_VV_phi_ZZ_llllnunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1708.09638.
     */
    double ip_ex_gg_phi_ZZ_qqllnunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1708.09638.
     */
    double ip_ex_VV_phi_ZZ_qqllnunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1804.01939.
     */
    double ip_ex_pp_phi_ZZ_llqqnunull_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1804.01939.
     */
    double ip_ex_VV_phi_ZZ_llqqnunull_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1803.03838.
     */
    double ip_ex_pp_phi_ZZ_qqnunu_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1509.00389.
     */
    double ip_ex_gg_phi_WW_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1509.00389.
     */
    double ip_ex_VV_phi_WW_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.01123.
     */
    double ip_ex_gg_phi_WW_enumunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.01123.
     */
    double ip_ex_VV_phi_WW_enumunu_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.07235.
     */
    double ip_ex_gg_phi_WW_lnuqq_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.07235.
     */
    double ip_ex_VV_phi_WW_lnuqq_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-16-023.
     */
    double ip_ex_ggVV_phi_WW_lnulnu_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1802.09407.
     */
    double ip_ex_pp_phi_WW_lnuqq_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1504.00936.
     */
    double ip_ex_mu_pp_phi_VV_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1708.04445.
     */
    double ip_ex_pp_phi_VV_qqqq_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1509.04670.
     */
    double ip_ex_gg_phi_hh_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1503.04114.
     */
    double ip_ex_pp_phi_hh_bbbb_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1603.06896.
     */
    double ip_ex_pp_phi_hh_gagabb_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1510.01181.
     */
    double ip_ex_gg_phi_hh_bbtautau_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1707.00350.
     */
    double ip_ex_pp_phi_hh_bbtautau_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from 1804.06174.
     */
    double ip_ex_pp_phi_hh_bbbb_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1806.03548.
     */
    double ip_ex_pp_phi_hh_bbbb_1_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance decaying to two @f$h@f$ bosons which further decay to four b quarks.
     * @return @f$[\sigma_{pp\to \phi}\cdot BR(\phi\to hh\to b\bar b b\bar b)]_{\text{CMS,95\%}}@f$
     * @details Taken from arXiv:1808.01473.
     */
    double ip_ex_pp_phi_hh_bbbb_2_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.04960.
     */
    double ip_ex_gg_phi_hh_bbbb_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from 1807.04873.
     */
    double ip_ex_pp_phi_hh_gagabb_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-17-008.
     */
    double ip_ex_pp_phi_hh_gagabb_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1808.00336.
     */
    double ip_ex_pp_phi_hh_bbtautau_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1707.02909.
     */
    double ip_ex_pp_phi_hh_bbtautau_1_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1808.01365.
     */
    double ip_ex_pp_phi_hh_bbtautau_2_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1708.04188.
     */
    double ip_ex_pp_phi_hh_bblnulnu_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1807.08567.
     */
    double ip_ex_gg_phi_hh_gagaWW_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1502.04478.
     */
    double ip_ex_gg_A_hZ_bbZ_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1504.04710.
     */
    double ip_ex_gg_A_hZ_bbll_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1502.04478.
     */
    double ip_ex_gg_A_hZ_tautauZ_ATLAS8(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1510.01181.
     */
    double ip_ex_gg_A_hZ_tautaull_CMS8(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1712.06518.
     */
    double ip_ex_gg_A_hZ_bbZ_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1712.06518.
     */
    double ip_ex_bb_A_hZ_bbZ_ATLAS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-18-005.
     */
    double ip_ex_gg_A_hZ_bbZ_1_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-18-005.
     */
    double ip_ex_bb_A_hZ_bbZ_1_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1807.02826.
     */
    double ip_ex_gg_A_hZ_bbZ_2_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1807.02826.
     */
    double ip_ex_bb_A_hZ_bbZ_2_CMS13(double mass);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1603.02991.
     */
    double ip_ex_pp_A_phiZ_bbll_CMS8(double mA, double mH);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1603.02991.
     */
    double ip_ex_pp_phi_AZ_bbll_CMS8(double mH, double mA);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1804.01126.
     */
    double ip_ex_gg_A_phiZ_bbll_ATLAS13(double mA, double mH);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1804.01126.
     */
    double ip_ex_bb_A_phiZ_bbll_ATLAS13(double mA, double mH);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1412.6663.
     */
    double ip_ex_pp_Hpm_taunu_ATLAS8(double mHp);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1508.07774.
     */
    double ip_ex_pp_Hp_taunu_CMS8(double mHp);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from 1807.07915.
     */
    double ip_ex_pp_Hpm_taunu_ATLAS13(double mHp);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from CMS-PAS-HIG-16-031.
     */
    double ip_ex_pp_Hpm_taunu_CMS13(double mHp);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1512.03704.
     */
    double ip_ex_pp_Hpm_tb_ATLAS8(double mHp);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1508.07774.
     */
    double ip_ex_pp_Hp_tb_CMS8(double mHp);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1808.03599.
     */
    double ip_ex_pp_Hpm_tb_ATLAS13(double mHp);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1503.04233.
     */
    double ip_ex_WZ_H5pm_WZ_qqll_ATLAS8(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1806.01532.
     */
    double ip_ex_WZ_H5pm_WZ_lnull_ATLAS13(double mH5);

    /**
     * @brief Interpolating function for the expected ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1806.01532.
     */
    double ip_ex_WZ_H5pm_WZ_lnull_ATLAS13_e(double mH5);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1705.02942.
     */
    double ip_ex_WZ_H5pm_WZ_lnull_1_CMS13(double mH5);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:CMS-PAS-SMP-18-001.
     */
    double ip_ex_WZ_H5pm_WZ_lnull_2_CMS13(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1412.0237.
     */
    double ip_ex_pp_H5ppmmH5mmpp_eeee_ATLAS8(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1412.0237.
     */
    double ip_ex_pp_H5ppmmH5mmpp_emuemu_ATLAS8(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1412.0237.
     */
    double ip_ex_pp_H5ppmmH5mmpp_mumumumu_ATLAS8(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1710.09748.
     */
    double ip_ex_pp_H5ppmmH5mmpp_llll_ATLAS13(double mH5);

    /**
     * @brief Interpolating function for the observed ATLAS upper limit on a scalar resonance
     * @details Taken from arXiv:1808.01899.
     */
    double ip_ex_pp_H5ppmmH5mmpp_WWWW_ATLAS13(double mH5);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1410.6315.
     */
    double ip_ex_VV_H5ppmm_WW_jjll_CMS8(double mH5);

    /**
     * @brief Interpolating function for the observed CMS upper limit on a scalar resonance
     * @details Taken from arXiv:1709.05822.
     */
    double ip_ex_VV_H5ppmm_WW_jjll_CMS13(double mH5);


    double updateCache();

//    double Q_cutoff;
//    double g1_at_Q;
//    double g2_at_Q;
//    double g3_at_Q;
//    double Ytop_at_Q;
//    double Ybottom1_at_Q;
//    double Ybottom2_at_Q;
//    double Ytau1_at_Q;
//    double Ytau2_at_Q;
//    double lambda1_at_Q;
//    double lambda2_at_Q;
//    double lambda3_at_Q;
//    double lambda4_at_Q;
//    double mu1_at_Q;
//    double mu3_at_Q;
//    double mu4_at_Q;
//    double nu1_at_Q;
//    double omega1_at_Q;
//    double kappa1_at_Q;
//    double nu2_at_Q;
//    double omega2_at_Q;
//    double kappa2_at_Q;
//    double nu4_at_Q;
//    double omega4_at_Q;
//    double m12sq;
//    double m11sq;
//    double m22sq;
//    double mhsq;
//    double mHsq;
//    double mAsq;
//    double mSRsq;
//    double mSIsq;
//    double mHpsq;
//    double mSpsq;

//    double RpepsGM;
    gslpp::vector<gslpp::complex> unitarityeigenvalues;
//    gslpp::vector<gslpp::complex> NLOunitarityeigenvalues;

    double rh_ff, rh_VV, rh_gg, rh_gaga, rh_Zga;
    double rHH_ff, rHH_VV, rHH_gg, rHH_gaga, rHH_Zga;
    double sumModBRs, Gamma_h, GM_Br_h_bb, GM_Br_h_gaga, GM_Br_h_tautau, GM_Br_h_WW, GM_Br_h_ZZ;
    double Br_Htott, Br_Htobb, Br_Htotautau, Br_HtoWW, Br_HtoZZ, Br_Htogaga, Br_HtoZga, Br_HtoAZ, Br_HtoHpW, 
           Br_Htohh, Br_HtoAA, Br_HtoHpHm, Br_HtoH5H5, Br_HtoH5pH5m, Br_HtoH5ppH5mm;
    double Br_Atott, Br_Atobb, Br_Atotautau, Br_Atogaga, Br_AtoZga, Br_AtohZ, Br_AtoHZ, Br_AtoH5Z, Br_AtoH5pW;
    double Br_Hptotaunu, Br_Hptotb, Br_HptohW, Br_HptoHW, Br_HptoH5pZ, Br_HptoH5W, Br_HptoH5ppW;
    double Br_H5toWW, Br_H5toZZ, Br_H5togaga, Br_H5toZga, Br_H5toAZ, Br_H5toHpW, Br_H5toHpHm, Br_H5toAA;
    double BrRatioVV5;
    double Br_H5ptoWZ, Br_H5ptoAW, Br_H5ptoHpZ, Br_H5ptoHpA;
    double Br_H5pptoWW, Br_H5pptoHpW, Br_H5pptoHpHp;
    double THoEX_tt_H_tt_ATLAS13, THoEX_bb_H_tt_ATLAS13;
    double THoEX_tt_A_tt_ATLAS13, THoEX_bb_A_tt_ATLAS13;
    double THoEX_bb_H_bb_CMS8, THoEX_gg_H_bb_CMS8, THoEX_pp_H_bb_CMS13, THoEX_bb_H_bb_CMS13;
    double THoEX_bb_A_bb_CMS8, THoEX_gg_A_bb_CMS8, THoEX_pp_A_bb_CMS13, THoEX_bb_A_bb_CMS13;
    double THoEX_gg_H_tautau_ATLAS8, THoEX_gg_H_tautau_CMS8, THoEX_bb_H_tautau_ATLAS8, THoEX_bb_H_tautau_CMS8;
    double THoEX_gg_H_tautau_ATLAS13, THoEX_gg_H_tautau_CMS13, THoEX_bb_H_tautau_ATLAS13, THoEX_bb_H_tautau_CMS13;
    double THoEX_gg_A_tautau_ATLAS8, THoEX_gg_A_tautau_CMS8, THoEX_bb_A_tautau_ATLAS8, THoEX_bb_A_tautau_CMS8; 
    double THoEX_gg_A_tautau_ATLAS13, THoEX_gg_A_tautau_CMS13, THoEX_bb_A_tautau_ATLAS13, THoEX_bb_A_tautau_CMS13;
    double THoEX_gg_H_gaga_ATLAS8, THoEX_pp_H_gaga_ATLAS13, THoEX_gg_H_gaga_CMS13;
    double THoEX_gg_A_gaga_ATLAS8, THoEX_pp_A_gaga_ATLAS13, THoEX_gg_A_gaga_CMS13;
    double THoEX_gg_H5_gaga_ATLAS8, THoEX_pp_H5_gaga_ATLAS13, THoEX_gg_H5_gaga_CMS13;    
    double THoEX_pp_H_Zga_llga_ATLAS8, THoEX_pp_H_Zga_llga_CMS8, THoEX_gg_H_Zga_llga_ATLAS13, THoEX_gg_H_Zga_qqga_ATLAS13, THoEX_gg_H_Zga_CMS13;
    double THoEX_pp_A_Zga_llga_ATLAS8, THoEX_pp_A_Zga_llga_CMS8, THoEX_gg_A_Zga_llga_ATLAS13, THoEX_gg_A_Zga_qqga_ATLAS13, THoEX_gg_A_Zga_CMS13;
    double THoEX_pp_H5_Zga_llga_ATLAS8, THoEX_pp_H5_Zga_llga_CMS8, THoEX_gg_H5_Zga_llga_ATLAS13, THoEX_gg_H5_Zga_CMS13;
    double THoEX_gg_H_ZZ_ATLAS8, THoEX_VV_H_ZZ_ATLAS8, THoEX_gg_H_ZZ_llllnunu_ATLAS13, THoEX_VV_H_ZZ_llllnunu_ATLAS13;
    double THoEX_gg_H_ZZ_qqllnunu_ATLAS13, THoEX_VV_H_ZZ_qqllnunu_ATLAS13, THoEX_pp_H_ZZ_llqqnunull_CMS13;
    double THoEX_VV_H_ZZ_llqqnunull_CMS13, THoEX_pp_H_ZZ_qqnunu_CMS13;
    double THoEX_gg_H5_ZZ_ATLAS8, THoEX_VV_H5_ZZ_ATLAS8, THoEX_gg_H5_ZZ_llllnunu_ATLAS13, THoEX_VV_H5_ZZ_llllnunu_ATLAS13;
    double THoEX_gg_H5_ZZ_qqllnunu_ATLAS13, THoEX_VV_H5_ZZ_qqllnunu_ATLAS13, THoEX_pp_H5_ZZ_llqqnunull_CMS13;
    double THoEX_VV_H5_ZZ_llqqnunull_CMS13, THoEX_pp_H5_ZZ_qqnunu_CMS13;
    double THoEX_gg_H_WW_ATLAS8, THoEX_VV_H_WW_ATLAS8, THoEX_gg_H_WW_enumunu_ATLAS13, THoEX_VV_H_WW_enumunu_ATLAS13;
    double THoEX_gg_H_WW_lnuqq_ATLAS13, THoEX_VV_H_WW_lnuqq_ATLAS13, THoEX_ggVV_H_WW_lnulnu_CMS13, THoEX_pp_H_WW_lnuqq_CMS13;
    double THoEX_gg_H5_WW_ATLAS8, THoEX_VV_H5_WW_ATLAS8, THoEX_gg_H5_WW_enumunu_ATLAS13, THoEX_VV_H5_WW_enumunu_ATLAS13;
    double THoEX_gg_H5_WW_lnuqq_ATLAS13, THoEX_VV_H5_WW_lnuqq_ATLAS13, THoEX_ggVV_H5_WW_lnulnu_CMS13, THoEX_pp_H5_WW_lnuqq_CMS13;
    double THoEX_mu_pp_H_VV_CMS8, THoEX_pp_H_VV_qqqq_ATLAS13;
    double THoEX_mu_pp_H5_VV_CMS8, THoEX_pp_H5_VV_qqqq_ATLAS13;
    double THoEX_gg_H_hh_ATLAS8, THoEX_pp_H_hh_bbbb_CMS8, THoEX_pp_H_hh_gagabb_CMS8;
    double THoEX_gg_H_hh_bbtautau_CMS8, THoEX_pp_H_hh_bbtautau_CMS8, THoEX_pp_H_hh_bbbb_ATLAS13;
    double THoEX_pp_H_hh_bbbb_1_CMS13, THoEX_pp_H_hh_bbbb_2_CMS13, THoEX_gg_H_hh_bbbb_CMS13, THoEX_pp_H_hh_gagabb_ATLAS13, THoEX_pp_H_hh_gagabb_CMS13;
    double THoEX_pp_H_hh_bbtautau_ATLAS13, THoEX_pp_H_hh_bbtautau_1_CMS13, THoEX_pp_H_hh_bbtautau_2_CMS13, THoEX_pp_H_hh_bblnulnu_CMS13, THoEX_gg_H_hh_gagaWW_ATLAS13;
    double THoEX_gg_H5_hh_ATLAS8, THoEX_pp_H5_hh_bbbb_CMS8, THoEX_pp_H5_hh_gagabb_CMS8;
    double THoEX_gg_H5_hh_bbtautau_CMS8, THoEX_pp_H5_hh_bbtautau_CMS8, THoEX_pp_H5_hh_bbbb_ATLAS13;
    double THoEX_pp_H5_hh_bbbb_CMS13, THoEX_gg_H5_hh_bbbb_CMS13, THoEX_pp_H5_hh_gagabb_ATLAS13, THoEX_pp_H5_hh_gagabb_CMS13;
    double THoEX_pp_H5_hh_bbtautau_CMS13, THoEX_pp_H5_hh_bblnulnu_CMS13, THoEX_gg_H5_hh_gagaWW_ATLAS13;
    double THoEX_gg_A_hZ_bbZ_ATLAS8, THoEX_gg_A_hZ_bbll_CMS8, THoEX_gg_A_hZ_tautauZ_ATLAS8, THoEX_gg_A_hZ_tautaull_CMS8;
    double THoEX_gg_A_hZ_bbZ_ATLAS13, THoEX_bb_A_hZ_bbZ_ATLAS13;
    double THoEX_gg_A_hZ_bbZ_1_CMS13, THoEX_bb_A_hZ_bbZ_1_CMS13, THoEX_gg_A_hZ_bbZ_2_CMS13, THoEX_bb_A_hZ_bbZ_2_CMS13;
    double THoEX_pp_A_HZ_bbll_CMS8, THoEX_pp_A_H5Z_bbll_CMS8;
    double THoEX_gg_A_HZ_bbll_ATLAS13, THoEX_bb_A_HZ_bbll_ATLAS13;
    double THoEX_pp_H_AZ_bbll_CMS8, THoEX_pp_H5_AZ_bbll_CMS8;
    double THoEX_pp_Hpm_taunu_ATLAS8, THoEX_pp_Hp_taunu_CMS8;
    double THoEX_pp_Hpm_taunu_ATLAS13, THoEX_pp_Hpm_taunu_CMS13;
    double THoEX_pp_Hpm_tb_ATLAS8, THoEX_pp_Hp_tb_CMS8;
    double THoEX_pp_Hpm_tb_ATLAS13;
    double THoEX_WZ_H5pm_WZ_qqll_ATLAS8, THoEX_WZ_H5pm_WZ_lnull_ATLAS13, THoEX_WZ_H5pm_WZ_lnull_1_CMS13, THoEX_WZ_H5pm_WZ_lnull_2_CMS13;
    double THoEX_pp_H5ppmmH5mmpp_eeee_ATLAS8, THoEX_pp_H5ppmmH5mmpp_emuemu_ATLAS8, THoEX_pp_H5ppmmH5mmpp_mumumumu_ATLAS8;
    double THoEX_pp_H5ppmmH5mmpp_llll_ATLAS13, THoEX_pp_H5ppmmH5mmpp_WWWW_ATLAS13, THoEX_VV_H5ppmm_WW_jjll_CMS8, THoEX_VV_H5ppmm_WW_jjll_CMS13;

    double R_WZ_H5pm_WZ_lnull_ATLAS13;
    
    double lambda1, lambda2, lambda3, lambda4, lambda5;
    double cosb, sinb, tanb;
    double vPhi;

    double ghhh;
    double ghhH;
    double ghHH;
    double gHHH;
    double ghH3H3;
    double gHH3H3;
    double ghH3pH3m;
    double gHH3pH3m;
    double ghH5H5;
    double gHH5H5;
    double ghH5pH5m;
    double gHH5pH5m;
    double ghH5ppH5mm;
    double gHH5ppH5mm;
    double gH3H3H5;
    double gH5H5H5;
    gslpp::complex gH3H3pH5m;
    double gH5H3pH3m;
    double gH5H5pH5m;
    double gH5H5ppH5mm;
    double gH5ppH3mH3m;
    double gH5ppH5mH5m;

    double tt_H_tt_TH13, bb_H_tt_TH13;
    double tt_A_tt_TH13, bb_A_tt_TH13;
    double bb_H_bb_TH8, gg_H_bb_TH8, pp_H_bb_TH13, bb_H_bb_TH13;
    double bb_A_bb_TH8, gg_A_bb_TH8, pp_A_bb_TH13, bb_A_bb_TH13;

    /**
     * @brief Cross section times branching ratio for the process @f$gg\to H\to \tau\tau@f$ at the LHC with 8 TeV.
     * @return @f$\sigma^{\text{GM}}_{gg\to H}\cdot BR^{\text{GM}}(H\to \tau\tau)@f$
     */
    double gg_H_tautau_TH8;

    /**
     * @brief Cross section times branching ratio for the process @f$b\bar b\to H\to \tau\tau@f$ at the LHC with 8 TeV.
     * @return @f$\sigma^{\text{GM}}_{b\bar b\to H}\cdot BR^{\text{GM}}(H\to \tau\tau)@f$
     */
    double bb_H_tautau_TH8;

    double gg_H_tautau_TH13, bb_H_tautau_TH13; 
    double gg_A_tautau_TH8, bb_A_tautau_TH8, gg_A_tautau_TH13, bb_A_tautau_TH13; 
    double gg_H_gaga_TH8, pp_H_gaga_TH13, gg_H_gaga_TH13;
    double gg_A_gaga_TH8, pp_A_gaga_TH13, gg_A_gaga_TH13;
    double gg_H5_gaga_TH8, pp_H5_gaga_TH13, gg_H5_gaga_TH13;
    double pp_H_Zga_llga_TH8, gg_H_Zga_TH13;
    double pp_A_Zga_llga_TH8, gg_A_Zga_TH13;
    double pp_H5_Zga_llga_TH8, gg_H5_Zga_TH13, gg_H5_Zga_llga_TH13;
    double gg_H_ZZ_TH8, VV_H_ZZ_TH8, gg_H_ZZ_TH13, VV_H_ZZ_TH13, pp_H_ZZ_TH13;
    double gg_H5_ZZ_TH8, VV_H5_ZZ_TH8, gg_H5_ZZ_TH13, VV_H5_ZZ_TH13, pp_H5_ZZ_TH13;
    double gg_H_WW_TH8, VV_H_WW_TH8, gg_H_WW_TH13, VV_H_WW_TH13, ggVV_H_WW_lnulnu_TH13, pp_H_WW_TH13;
    double gg_H5_WW_TH8, VV_H5_WW_TH8, gg_H5_WW_TH13, VV_H5_WW_TH13, ggVV_H5_WW_lnulnu_TH13, pp_H5_WW_TH13;
    double pp_H_VV_TH8, mu_pp_H_VV_TH8, pp_H_VV_TH13;
    double pp_H5_VV_TH8, mu_pp_H5_VV_TH8, pp_H5_VV_TH13;
    double gg_H_hh_TH8, pp_H_hh_bbbb_TH8, pp_H_hh_gagabb_TH8, gg_H_hh_bbtautau_TH8, pp_H_hh_TH8;
    double gg_H5_hh_TH8, pp_H5_hh_bbbb_TH8, pp_H5_hh_gagabb_TH8, pp_H5_hh_TH8;

    /**
     * @brief Cross section times branching ratio for the process @f$pp\to H\to hh\to b\bar b b\bar b@f$ at the LHC with 13 TeV.
     * @return @f$\sigma^{\text{THDM}}_{pp\to H}\cdot BR^{\text{THDM}}(H\to hh\to b\bar b b\bar b)@f$
     */
    double pp_H_hh_bbbb_TH13;

    double gg_H_hh_bbbb_TH13, pp_H_hh_TH13, pp_H_hh_gagabb_TH13, pp_H_hh_bbtautau_TH13, pp_H_hh_bblnulnu_TH13, gg_H_hh_gagaWW_TH13, gg_H_hh_TH13;
    double pp_H5_hh_bbbb_TH13, gg_H5_hh_bbbb_TH13, pp_H5_hh_TH13, pp_H5_hh_gagabb_TH13, pp_H5_hh_bbtautau_TH13, pp_H5_hh_bblnulnu_TH13, gg_H5_hh_TH13;
    double gg_A_hZ_bbZ_TH8, gg_A_hZ_bbll_TH8, gg_A_hZ_tautauZ_TH8, gg_A_hZ_tautaull_TH8, gg_A_hZ_bbZ_TH13, bb_A_hZ_bbZ_TH13;
    double pp_A_HZ_bbll_TH8, pp_A_H5Z_bbll_TH8, pp_H_AZ_bbll_TH8, pp_H5_AZ_bbll_TH8;
    double gg_A_HZ_bbZ_TH13, bb_A_HZ_bbZ_TH13;
    double pp_Hpm_taunu_TH8, pp_Hp_taunu_TH8,pp_Hpm_taunu_TH13;
    double pp_Hpm_tb_TH8, pp_Hp_tb_TH8, pp_Hpm_tb_TH13;
    double WZ_H5pm_WZ_TH8, WZ_H5pm_WZ_TH13;
    double pp_H5ppmmH5mmpp_TH8, pp_H5ppmmH5mmpp_TH13, pp_H5ppmmH5mmpp_WWWW_TH13;
    double VV_H5ppmm_WW_TH8, VV_H5ppmm_WW_TH13;

    /**
     * @brief Total decay width of the CP-even Higgs @f$H_1@f$.
     * @return @f$\Gamma_{H_1}@f$
     */
    double GammaH1tot;

    /**
     * @brief Total decay width of the CP-odd Higgs @f$H_3^0@f$.
     * @return @f$\Gamma_{H_3}@f$
     */
    double GammaH3tot;

    /**
     * @brief Total decay width of the charged Higgs @f$H_3^+@f$.
     * @return @f$\Gamma_{H_3^+}@f$
     */
    double GammaH3ptot;

    /**
     * @brief Total decay width of the CP-even Higgs @f$H_5^0@f$.
     * @return @f$\Gamma_{H_5}@f$
     */
    double GammaH5tot;

    /**
     * @brief Total decay width of the charged Higgs @f$H_5^+@f$.
     * @return @f$\Gamma_{H_5^+}@f$
     */
    double GammaH5ptot;

    /**
     * @brief Total decay width of the doubly charged Higgs @f$H_5^{++}@f$.
     * @return @f$\Gamma_{H_5^{++}}@f$
     */
    double GammaH5pptot;

protected:

private:

    const GeorgiMachacek * myGM;
//    RunnerGM * myRunnerGM;

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

    /**
     * @brief Kaellen function
     * @return @f$\kappa(a,b,c)=\frac{1}{2a}\sqrt{a^2+b^a+c^2-2ab-2ac-2bc}@f$
     */
    double KaellenFunction(const double a2, const double b2, const double c2) const;

    double OffShellFunction(const double k) const;

    double cW2_GM(const double c02) const;

    gslpp::complex f_func(const double x) const;
    gslpp::complex g_func(const double x) const;

    gslpp::complex Int1(const double tau, const double lambda) const;
    gslpp::complex Int2(const double tau, const double lambda) const;

//    void runGMparameters();

    void computeUnitarity();
//    gslpp::vector<gslpp::complex> betaeigenvalues;

    void computeSignalStrengthQuantities();
    void computeOtherHiggsProperties();
    void computeDirectSearchQuantities();

    double cW2GM(const double c02) const;
    double MWGM(const double MW) const;

    /**
     * @brief SM branching ratio of @f$h\to b \bar b@f$.
     * @return @f$BR{\text SM}(h\to b \bar b)@f$
     */
//    double BrSM_htobb;

    /**
     * @brief SM branching ratio of @f$h\to \gamma \gamma@f$.
     * @return @f$BR{\text SM}(h\to \gamma \gamma)@f$
     */
//    double BrSM_htogaga;

    /**
     * @brief SM branching ratio of @f$h\to \tau \tau@f$.
     * @return @f$BR{\text SM}(h\to \tau \tau)@f$
     */
//    double BrSM_htotautau;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two down type quarks.
     * @return @f$r^{(h)}_{Q_dQ_d}@f$
     * @details Depends on the type of @f$Z_2@f$ symmetry.
     */
//    double rh_QdQd;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two massive vector bosons.
     * @return @f$r^{(h)}_{WW}=r^{(h)}_{ZZ}@f$
     */
//    double rh_VV;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two charged leptons.
     * @return @f$r^{(h)}_{\ell \ell}@f$
     * @details Depends on the type of @f$Z_2@f$ symmetry.
     */
//    double rh_ll;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two photons.
     * @return @f$r^{(h)}_{\gamma \gamma}@f$
     * @details Depends on the type of @f$Z_2@f$ symmetry.
     */
//    double rh_gaga;

    /**
     * @brief Squared relative coupling of @f$h@f$ to a @f$Z@f$ boson and a photon.
     * @return @f$r^{(h)}_{Z\gamma}@f$
     * @details Depends on the type of @f$Z_2@f$ symmetry.
     */
//    double rh_Zga;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two gluons.
     * @return @f$r^{(h)}_{gg}@f$
     * @details Depends on the type of @f$Z_2@f$ symmetry.
     */
//    double rh_gg;

    /**
     * @brief Ratio of GM and SM cross sections for ggF and tth production of h at 8 TeV.
     * @return @f$\sigma^{\text GM}_{\text ggF+tth}/\sigma^{\text SM}_{\text ggF+tth}@f$
     */
//    double ggF_tth8;

    /**
     * @brief Ratio of GM and SM cross sections for ggF and tth production of h at 13 TeV.
     * @return @f$\sigma^{\text GM}_{\text ggF+tth}/\sigma^{\text SM}_{\text ggF+tth}@f$
     */
//    double ggF_tth13;

    /**
     * @brief Ratio of GM and SM cross sections for the production of h at 13 TeV.
     * @return @f$\sigma^{\text GM}_{\text ggF+VBF+Vh+tth}/\sigma^{\text SM}_{\text ggF+VBF+Vh+tth}@f$
     */
//    double pph13;

    /**
     * @brief Ratio of GM and SM cross sections for VBF and Vh production of h.
     * @return @f$\sigma^{\text GM}_{\text VBF+Vh}/\sigma^{\text SM}_{\text VBF+Vh}@f$
     */
//    double VBF_Vh;

    /**
     * @brief Sum of the modified branching ratios.
     * @return @f$\sum _i r^{(h)}_{i} BR^{\text SM}(h\to i)@f$
     */
//    double sumModBRs;

    /**
     * @brief Total h decay rate in the GM.
     * @return @f$\Gamma_h@f$
     */
//    double Gamma_h;

    /**
     * @brief Squared relative coupling of @f$h@f$ to two up type quarks.
     * @return @f$r^{(h)}_{Q_uQ_u}@f$
     */
//    double rh_QuQu;

    /**
     * @brief @f$h@f$ branching ratio to two @f$b@f$ quarks in the %GM.
     * @return @f$BR^{\text{GM}}(h\to b \bar b)@f$
     */
//    double GM_BR_h_bb;

    /**
     * @brief @f$h@f$ branching ratio to two photons in the %GM.
     * @return @f$BR^{\text{GM}}(h\to \gamma \gamma)@f$
     */
//    double GM_BR_h_gaga;

    /**
     * @brief @f$h@f$ branching ratio to two @f$\tau@f$ leptons in the %GM.
     * @return @f$BR^{\text{GM}}(h\to \tau\tau )@f$
     */
//    double GM_BR_h_tautau;

    /**
     * @brief @f$h@f$ branching ratio to two @f$W@f$ bosons in the %GM.
     * @return @f$BR^{\text{GM}}(h\to WW)@f$
     */
//    double GM_BR_h_WW;

    /**
     * @brief @f$h@f$ branching ratio to two @f$Z@f$ bosons in the %GM.
     * @return @f$BR^{\text{GM}}(h\to ZZ)@f$
     */
//    double GM_BR_h_ZZ;

    /**
     * @brief @f$h@f$ branching ratio to two gluons in the %GM.
     * @return @f$BR^{\text{GM}}(h\to gg)@f$
     */
//    double GM_BR_h_gg;

    /**
     * @brief @f$h@f$ branching ratio to two @f$c@f$ quarks in the %GM.
     * @return @f$BR^{\text{GM}}(h\to c\bar c)@f$
     */
//    double GM_BR_h_cc;

    double SigmaSumH8;
    double SigmaSumA8;
    double SigmaSumH58;
    double SigmaTotSM_H8;
    double SigmaTotSM_H58;
    double SigmaggF_H8;
    double SigmaggF_A8;
    double SigmabbF_H8;
    double SigmabbF_A8;
    double SigmaVBF_H8;
    double SigmaVBF_H58;
    double SigmaSumH13;
    double SigmaSumA13;
    double SigmaSumH513;
    double SigmaggF_H13;
    double SigmaggF_A13;
    double SigmattF_H13;
    double SigmattF_A13;
    double SigmabbF_H13;
    double SigmabbF_A13;
    double SigmaVBF_H13;
    double SigmaVBF_H513;
    double SigmaVH_H13;
    double SigmaVH_H513;
    double SigmaHp8, SigmaHp58, SigmaHppHmm58, SigmaHpp58, SigmaHp13, SigmaHp513, SigmaHppHmm513, SigmaHpp513;
//    double Br_Htotautau;
//    double Br_Atotautau;
//    double Br_Htogaga;
//    double Br_Atogaga;
//    double Br_H5togaga;
//    double Br_HtoZga;
//    double Br_AtoZga;
//    double Br_H5toZga;
//    double Br_HtoZZ;
//    double Br_H5toZZ;
//    double Br_HtoWW;
//    double Br_H5toWW;
//    double Br_Htott;
//    double Br_Atott;
//    double Br_Htobb;
//    double Br_Atobb;
    double GammaHtotSM;
    double GammaAtotSM;
    double GammaH5totSM;

    double Q_GM;
    double GF;
    double Ale;
    double MZ;
    double cW2;
    double MW;
    double vev;
    double mHl;
    double mHl2;
    double vDelta;
    double sina;
    double cosa;
    double mH1sq;
    double mAsq;
    double mH5sq;
    double Mu1;
    double Mu2;
    double M1sq;
    double M2sq;

    /**
     * @brief Heaviside @f$\Theta@f$ function
     * @return @f$\Theta(x)@f$
     * @details Gives 1 for @f$x\geq 0@f$ and 0 for @f$x<0@f$.
     */
    double HSTheta (const double x) const;

    mutable double ip_Br_HPtott_cache[2][CacheSize];
    mutable double ip_Br_HPtobb_cache[2][CacheSize];
    mutable double ip_Br_HPtotautau_cache[2][CacheSize];
    mutable double ip_Br_HPtocc_cache[2][CacheSize];
    mutable double ip_Br_HPtomumu_cache[2][CacheSize];
    mutable double ip_Br_HPtoZZ_cache[2][CacheSize];
    mutable double ip_Br_HPtoWW_cache[2][CacheSize];
    mutable double ip_GammaHPtotSM_cache[2][CacheSize];
    mutable double ip_cs_ggtoH_8_cache[2][CacheSize];
    mutable double ip_cs_ggtoH_13_cache[2][CacheSize];
    mutable double ip_cs_VBFtoH_8_cache[2][CacheSize];
    mutable double ip_cs_VBFtoH_13_cache[2][CacheSize];
    mutable double ip_cs_WtoWH_8_cache[2][CacheSize];
    mutable double ip_cs_WtoWH_13_cache[2][CacheSize];
    mutable double ip_cs_ZtoZH_8_cache[2][CacheSize];
    mutable double ip_cs_ZtoZH_13_cache[2][CacheSize];
    mutable double ip_cs_pptottH_8_cache[2][CacheSize];
    mutable double ip_cs_pptottH_13_cache[2][CacheSize];
    mutable double ip_cs_pptobbH_8_cache[2][CacheSize];
    mutable double ip_cs_pptobbH_13_cache[2][CacheSize];
    mutable double ip_cs_ggtoA_8_cache[2][CacheSize];
    mutable double ip_cs_ggtoA_13_cache[2][CacheSize];
    mutable double ip_cs_pptottA_8_cache[2][CacheSize];
    mutable double ip_cs_pptottA_13_cache[2][CacheSize];
    mutable double ip_cs_pptobbA_8_cache[2][CacheSize];
    mutable double ip_cs_pptobbA_13_cache[2][CacheSize];
    mutable double ip_cs_ggtoHp_8_cache[3][CacheSize];
    mutable double ip_cs_ggtoHp_13_cache[3][CacheSize];
    mutable double ip_cs_ppH5ppH5mm_8_cache[2][CacheSize];
    mutable double ip_cs_ppH5ppH5mm_13_cache[2][CacheSize];
    mutable double ip_cs_VBFH5_8_cache[2][CacheSize];
    mutable double ip_cs_VBFH5_13_cache[2][CacheSize];
    mutable double ip_cs_VBFH5m_8_cache[2][CacheSize];
    mutable double ip_cs_VBFH5m_13_cache[2][CacheSize];
    mutable double ip_cs_VBFH5mm_8_cache[2][CacheSize];
    mutable double ip_cs_VBFH5mm_13_cache[2][CacheSize];
    mutable double ip_cs_VBFH5p_8_cache[2][CacheSize];
    mutable double ip_cs_VBFH5p_13_cache[2][CacheSize];
    mutable double ip_cs_VBFH5pp_8_cache[2][CacheSize];
    mutable double ip_cs_VBFH5pp_13_cache[2][CacheSize];
    mutable double ip_cs_VHH5_8_cache[2][CacheSize];
    mutable double ip_cs_VHH5_13_cache[2][CacheSize];
    mutable double ip_cs_VHH5mm_8_cache[2][CacheSize];
    mutable double ip_cs_VHH5mm_13_cache[2][CacheSize];
    mutable double ip_cs_VHH5pp_8_cache[2][CacheSize];
    mutable double ip_cs_VHH5pp_13_cache[2][CacheSize];
    mutable double ip_ex_tt_phi_tt_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tt_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_bb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_bb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_bb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_bb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_tautau_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_tautau_CMS8_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tautau_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tautau_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_tautau_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_tautau_CMS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tautau_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_phi_tautau_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_gaga_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_gaga_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_gaga_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_Zga_llga_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_Zga_llga_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_Zga_llga_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_Zga_qqga_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_Zga_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_ZZ_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_ZZ_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_ZZ_llllnunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_ZZ_llllnunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_ZZ_qqllnunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_ZZ_qqllnunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_ZZ_llqqnunull_CMS13_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_ZZ_llqqnunull_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_ZZ_qqnunu_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_WW_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_WW_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_WW_enumunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_WW_enumunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_WW_lnuqq_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_VV_phi_WW_lnuqq_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_ggVV_phi_WW_lnulnu_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_WW_lnuqq_CMS13_cache[2][CacheSize];
    mutable double ip_ex_mu_pp_phi_VV_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_VV_qqqq_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_hh_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_gagabb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_hh_bbtautau_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbtautau_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_1_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbbb_2_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_hh_bbbb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_gagabb_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_gagabb_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbtautau_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbtautau_1_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bbtautau_2_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_phi_hh_bblnulnu_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_phi_hh_gagaWW_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_bbZ_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_bbll_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_tautauZ_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_tautaull_CMS8_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_bbZ_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_bb_A_hZ_bbZ_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_bbZ_1_CMS13_cache[2][CacheSize];
    mutable double ip_ex_bb_A_hZ_bbZ_1_CMS13_cache[2][CacheSize];
    mutable double ip_ex_gg_A_hZ_bbZ_2_CMS13_cache[2][CacheSize];
    mutable double ip_ex_bb_A_hZ_bbZ_2_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_A_phiZ_bbll_CMS8_cache[3][CacheSize];
    mutable double ip_ex_pp_phi_AZ_bbll_CMS8_cache[3][CacheSize];
    mutable double ip_ex_gg_A_phiZ_bbll_ATLAS13_cache[3][CacheSize];
    mutable double ip_ex_bb_A_phiZ_bbll_ATLAS13_cache[3][CacheSize];
    mutable double ip_ex_pp_Hpm_taunu_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hp_taunu_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hpm_taunu_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_Hpm_taunu_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_Hpm_tb_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hp_tb_CMS8_cache[2][CacheSize];
    mutable double ip_ex_pp_Hpm_tb_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_WZ_H5pm_WZ_qqll_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_WZ_H5pm_WZ_lnull_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_WZ_H5pm_WZ_lnull_ATLAS13_e_cache[2][CacheSize];
    mutable double ip_ex_WZ_H5pm_WZ_lnull_1_CMS13_cache[2][CacheSize];
    mutable double ip_ex_WZ_H5pm_WZ_lnull_2_CMS13_cache[2][CacheSize];
    mutable double ip_ex_pp_H5ppmmH5mmpp_eeee_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_H5ppmmH5mmpp_emuemu_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_H5ppmmH5mmpp_mumumumu_ATLAS8_cache[2][CacheSize];
    mutable double ip_ex_pp_H5ppmmH5mmpp_llll_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_pp_H5ppmmH5mmpp_WWWW_ATLAS13_cache[2][CacheSize];
    mutable double ip_ex_VV_H5ppmm_WW_jjll_CMS8_cache[2][CacheSize];
    mutable double ip_ex_VV_H5ppmm_WW_jjll_CMS13_cache[2][CacheSize];
    mutable double KaellenFunction_cache[4][CacheSize];
    mutable double OffShellFunction_cache[1][CacheSize];

};

#endif	/* GMCACHE_H */
