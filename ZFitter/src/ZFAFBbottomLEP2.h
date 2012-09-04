/* 
 * File:   ZFAFBbottomLEP2.h
 * Author: mishima
 */

#ifndef ZFAFBBOTTOMLEP2_H
#define	ZFAFBBOTTOMLEP2_H

#include <ThObservable.h>
#include <StandardModel.h>
#include "ZFitter.h"


class ZFAFBbottomLEP2 : public ThObservable {
public:

    /**
     * @brief ZFAFBbottomLEP2 constructor
     * @param[in] ZF_i an object of ZFitter class
     * @param[in] sqrt_s_i \sqrt{s} of the e+ e- pair in the initial state
     */
    ZFAFBbottomLEP2(const ZFitter& ZF_i, const double sqrt_s_i) : ThObservable(ZF_i), 
            myZF(ZF_i), sqrt_s(sqrt_s_i) {};

    /**
     * @return the forward-backward asymmetry of the b-bar channel at sqrt_s
     */
    double getThValue();
    
private:
    const ZFitter& myZF;
    const double sqrt_s;
};

#endif	/* ZFAFBBOTTOMLEP2_H */

