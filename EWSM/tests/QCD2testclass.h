/*
 * File:   QCD2testclass.h
 * Author: mishima
 */

#ifndef QCD2TESTCLASS_H
#define	QCD2TESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <map>
#include "TwoLoopQCD.h"
using namespace std;


class QCD2testclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(QCD2testclass);
    CPPUNIT_TEST(F1);
    CPPUNIT_TEST(F1_0);
    CPPUNIT_TEST(V1);
    CPPUNIT_TEST(A1);
    CPPUNIT_TEST(A1_0);
    CPPUNIT_TEST(DeltaRho);
    CPPUNIT_TEST(DeltaR_ud);
    CPPUNIT_TEST(DeltaR_tb);
    CPPUNIT_TEST(DeltaR_rem);
    CPPUNIT_TEST(DeltaRho_ud);
    CPPUNIT_TEST(DeltaRho_tb);
    CPPUNIT_TEST(DeltaKappa_ud_real);
    CPPUNIT_TEST(DeltaKappa_tb_real);  
    CPPUNIT_TEST(deltaRho_rem_l_real);
    CPPUNIT_TEST(deltaRho_rem_q_real);    
    CPPUNIT_TEST(deltaKappa_rem_l_real);
    CPPUNIT_TEST(deltaKappa_rem_q_real); 

    
    CPPUNIT_TEST_SUITE_END();

public:
    QCD2testclass();
    virtual ~QCD2testclass();
    void setUp();
    void tearDown();

private:
    StandardModel* mySM;
    EWSMcommon* myEWSMC;
    TwoLoopQCD* myQCD2;
    
    double epsilon;
    double Mw, Mw2, Mz, Mz2, cW2, sW2, Mt;
    double AlsMt_ratio; /* The ratio of alpha_s(Mt) in ZFITTER to the current program */
    
    void setSMparameters(StandardModel& SM_i);

    void F1();
    void F1_0();
    void V1();
    void A1();
    void A1_0();
    
    void DeltaRho();
    void DeltaR_ud();
    void DeltaR_tb();
    void DeltaR_rem();
    
    void DeltaRho_ud();
    void DeltaRho_tb();

    void DeltaKappa_ud_real();
    void DeltaKappa_tb_real();        
    void deltaRho_rem_l_real();
    void deltaRho_rem_q_real();    
    void deltaKappa_rem_l_real();
    void deltaKappa_rem_q_real();    
    
    /* consider later */
    //void DeltaKappa_ud_imag();
    //void DeltaKappa_tb_imag(); 
    //void deltaRho_rem_l_imag();
    //void deltaRho_rem_q_imag();    
    //void deltaKappa_rem_l_imag();
    //void deltaKappa_rem_q_imag();    

    
    
};

#endif	/* QCD2TESTCLASS_H */

