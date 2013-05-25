/* 
 * Copyright (C) 2012 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#include "EvolDF2.h"
#include <stdexcept>

EvolDF2::EvolDF2(unsigned int dim, schemes scheme, orders order, const StandardModel& model) :
        model(model),
        RGEvolutor(dim, scheme, order)
{
    double Nc = model.getNc();
    matrix<double> v(5, 5, 0.);
    vector<double> e(5, 0.);

    // Magic numbers in the basis of Gabbiani et al. (There is no magic in these numbers. They are just the eigensystem of the LO ADM.)
    
    e(0) = 6. / Nc;
    e(1) = 6. * (-1. + Nc) / Nc;
    e(2) = -6. * (-1. + Nc * Nc) / Nc;
    e(3) = (2. * (Nc + 3. * Nc * Nc - Nc * Nc * Nc + sqrt(Nc * Nc * (16. -
            11. * Nc * Nc + 4. * Nc * Nc * Nc * Nc)))) / (Nc * Nc);
    e(4) = (-2. * (-Nc - 3. * Nc * Nc + Nc * Nc * Nc + sqrt(Nc * Nc * (16. -
            11. * Nc * Nc + 4. * Nc * Nc * Nc * Nc)))) / (Nc * Nc);
    v(0, 1) = 1.;
    v(1, 3) = -(-Nc * Nc + 2. * Nc * Nc * Nc - sqrt(Nc * Nc * (16. -
            11. * Nc * Nc + 4. * Nc * Nc * Nc * Nc))) / (2. * (-2. + Nc) * Nc);
    v(1, 4) = -(-Nc * Nc + 2. * Nc * Nc * Nc + sqrt(Nc * Nc * (16. -
            11. * Nc * Nc + 4. * Nc * Nc * Nc * Nc))) / (2. * (-2. + Nc) * Nc);
    v(2, 3) = 1.;
    v(2, 4) = 1.;
    v(3, 0) = -1. / Nc;
    v(3, 2) = 1.;
    v(4, 0) = 1.;

    matrix<double> vi = v.inverse();
//***//    double bb[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                a[k] = e(k);
                b[i][j][k] = v(i, k) * vi(k, j);
//***//                bb[i][j] += b[i][j][k] * pow(0.5, a[k] / 2. / model.Beta0(5));
            }
//***//            std::cout << bb[i][j]  << "  ";
        }
    }
    
    
//***//    std::cout<< "   " << std::endl;
    
//***//    for (int k = 0; k < 5; k++) {
//***//       for (int i = 3; i <=6; ++i) {
//***//            std::cout << a[k] / 2. / model.Beta0(i) << "  ";
//***//        }
//***//        std::cout << std::endl;
//***//    }
    
    matrix<double> h(5, 5, 0.);
    for (int l = 0; l < 3; l++) {
        matrix<double> gg = vi * (AnomalousDimension(NLO, 6 - l).transpose()) * v;
        double b0 = model.Beta0(6 - l);
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                h(i, j) = (i == j) * e(i) * model.Beta1(6 - l) / (2. * b0 * b0) -
                gg(i, j) / (2. * b0 + e(i) - e(j));
        matrix<double> j = v * h * vi;
        matrix<double> jv = j*v;
        matrix<double> vij = vi*j;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 5; k++) {
                    c[l][i][j][k] = jv(i, k) * vi(k, j);
                    d[l][i][j][k] = -v(i, k) * vij(k, j);
                }
    }

}

EvolDF2::~EvolDF2() {
}

matrix<double> EvolDF2::AnomalousDimension(orders order, unsigned int nf) const {
    matrix<double> ad(5, 5, 0.);
    double Nc = model.getNc();
    switch (order) {
        case LO:
            ad(0, 0) = (6. * Nc - 6.) / Nc;
            ad(1, 1) = -(6. * Nc * Nc - 8. * Nc - 2.) / Nc;
            ad(1, 2) = (4. * Nc - 8.) / Nc;
            ad(2, 1) = (4. * Nc * Nc - 4. * Nc - 8.) / Nc;
            ad(2, 2) = (2. * Nc * Nc + 4. * Nc + 2.) / Nc;
            ad(3, 3) = -(6. * Nc * Nc - 6.) / Nc;
            ad(4, 3) = -6.;
            ad(4, 4) = 6. / Nc;
            break;
        case NLO:
            
            // MSbar-NDR scheme with evanescent operators of Buras, Misiak & Urban
            
            if (!(nf == 3 || nf == 4 || nf == 5 || nf == 6))
                throw std::runtime_error("EvolDF2::AnomalousDimension(): wrong number of flavours"); 
            ad(0, 0) = -(-1. + Nc)*(-171. + 19. * Nc * Nc + Nc * (63. - 4. * nf)) / (6. * Nc * Nc);
            ad(1, 1) = (-1251. - 609. * Nc * Nc * Nc * Nc + Nc * (432. - 52. * nf) - 8. * Nc * Nc * (-71 + 2. * nf) +
                    20. * Nc * Nc * Nc * (32. + 3. * nf)) / (18. * Nc * Nc);
            ad(1, 2) = -(2. * (-2. + Nc)*(-72. + Nc * Nc + 2. * Nc * (63. + nf))) / (9. * Nc * Nc);
            ad(2, 1) = 2. * (119. * Nc * Nc * Nc + 8. * (-9. + 5. * nf) + 2. * Nc * (-125. + 7. * nf) -
                    Nc * Nc * (101. + 14. * nf)) / (9. * Nc);
            ad(2, 2) = (477. + 343. * Nc * Nc * Nc * Nc + Nc * Nc * Nc * (380. - 52. * nf) - 4. * Nc * (-36. + nf) -
                    8. * Nc * Nc * (16. + 13. * nf)) / (18. * Nc * Nc);
            ad(3, 3) = (45. + 479. * Nc * Nc - 203. * Nc * Nc * Nc * Nc - 44. * Nc * nf + 20. * Nc * Nc * Nc * nf) /
                    (6. * Nc * Nc);
            ad(3, 4) = -(18. / Nc)-(71. * Nc) / 2. + 4. * nf;
            ad(4, 3) = 3. / Nc - (100. * Nc) / 3. + (22. * nf) / 3.;
            ad(4, 4) = (45. + 137. * Nc * Nc - 44. * Nc * nf) / (6. * Nc * Nc);
            break;
        default:
            throw std::runtime_error("EvolDF2::AnomalousDimension(): order not implemented"); 
    }
    return (ad);
}

matrix<double> EvolDF2::AnomalousDimensionBuras(orders order, unsigned int nf) const {
    matrix<double> adB(5, 5, 0.);
    double Nc = model.getNc();
    switch (order) {
        case LO:
            adB(0, 0) = 6. - 6. / Nc;
            adB(1, 1) = 6. / Nc;
            adB(1, 2) = 12. ;
            adB(2, 2) = 6. / Nc - 6. * Nc;
            adB(3, 3) = 6. + 6. / Nc - 6. * Nc;
            adB(3, 4) = 1. / 2. - 1. / Nc;
            adB(4, 3) = -24. - 48. / Nc;
            adB(4, 4) = 6. - 2. / Nc + 2. * Nc;
            break;
        case NLO:
            
            // MSbar-NDR scheme with evanescent operators of Buras, Misiak & Urban
            
            if (!(nf == 3 || nf == 4 || nf == 5 || nf == 6))
                throw std::runtime_error("EvolDF2::AnomalousDimensionBuras(): wrong number of flavours");
            adB(0, 0) = -22. / 3. - 57. / (2. * Nc * Nc) + 39. / Nc - (19. * Nc) / 6.  + (2. * nf) / 3. - (2. * nf) / 3. / Nc;
            adB(1, 1) = 137. / 6. + 15. / (2 * Nc * Nc) - (22 * nf) / (3 * Nc);
            adB(1, 2) = -(6. / Nc) + (200. * Nc) / 3. - (44 * nf) / 3.;
            adB(2, 1) = 9. / Nc + (71. * Nc) / 4. - 2. * nf;
            adB(2, 2) = 479. / 6. + 15. / (2. * Nc * Nc) - (203. * Nc * Nc) / 6. - (22. * nf) / (3. * Nc) + (10. * Nc * nf) / 3.;
            adB(3, 3) = 136. / 3. - 107. / (2. * Nc * Nc) - 12. / Nc + (107. * Nc) / 3. - (203. * Nc * Nc) / 6. - (2. * nf) / 3. - (10. * nf) / (3. * Nc) + (10. * Nc * nf) / 3.;
            adB(3, 4) = -31. / 9. - 4. / (Nc * Nc) + 9. / Nc - Nc / 36. - nf / 18. + nf / (9 * Nc);
            adB(4, 3) = -704. / 3. - 320. / (Nc * Nc) - 208. / Nc - (364. * Nc) / 3. + (136. * nf) / 3. + (176. * nf) / (3. * Nc);
            adB(4, 4) = -188. / 9. + 21. / (2. * Nc * Nc) + 44. / Nc + 21. * Nc + (343. * Nc * Nc) / 18. - 6. * nf + (2. * nf) / (9. * Nc) - (26. * Nc * nf) / 9.;
            break;
        default:
            throw std::runtime_error("EvolDF2::AnomalousDimensionBuras(): order not implemented");
    }
    return (adB);
}

matrix<double>& EvolDF2::Df2Evol(double mu, double M, orders order, schemes scheme) {
    switch (scheme) {
        case NDR:
            break;
        case LRI:
        case HV:
        default:
            std::stringstream out;
            out << scheme;
            throw std::runtime_error("EvolDF2::Df2Evol(): scheme " + out.str() + " not implemented "); 
    }

    if (mu == this->mu && M == this->M && scheme == this->scheme)
        return (*Evol(order));

    if (M < mu) {
        std::stringstream out;
        out << "M = " << M << " < mu = " << mu;
        throw out.str();
    }

    setScales(mu, M); // also assign evol to identity

    double m_down = mu;
    double m_up = model.AboveTh(m_down);
    double nf = model.Nf(m_down);

    while (m_up < M) {
        Df2Evol(m_down, m_up, nf, scheme);
        m_down = m_up;
        m_up = model.AboveTh(m_down);
        nf += 1.;
    }
    Df2Evol(m_down, M, nf, scheme);
    return (*Evol(order));
}

void EvolDF2::Df2Evol(double mu, double M, double nf, schemes scheme) {

    matrix<double> resLO(5, 0.), resNLO(5, 0.), resNNLO(5, 0.);

    int l = 6 - (int) nf;
    double alsM = model.Als(M) / 4. / M_PI;
    double alsmu = model.Als(mu) / 4. / M_PI;

    double eta = alsM / alsmu;

    for (int k = 0; k < 5; k++) {
        double etap = pow(eta, a[k] / 2. / model.Beta0(nf));
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                resNNLO(i, j) += 0.;
                resNLO(i, j) += c[l][i][j][k] * etap * alsmu;
                resNLO(i, j) += d[l][i][j][k] * etap * alsM;
                resLO(i, j) += b[i][j][k] * etap;
        }
    }
    switch(order) {
        case NNLO:
            *elem[NNLO] = 0.; // Marco can implement it if he wishes to!
        case NLO:
            *elem[NLO] = (*elem[LO]) * resNLO + (*elem[NLO]) * resLO;
        case LO:
            *elem[LO] = (*elem[LO]) * resLO;
            break;
        case FULLNNLO:
        case FULLNLO:
        default:
            throw std::runtime_error("Error in EvolDF2::Df2Evol()");
    }
}

double EvolDF2::etacc(double  mu) const{
    double N = model.getNc();
    double gamma0[2] = {0.}, gamma1[2][4] = {0.}, d[2][4] = {0.}, 
           J[2][4] = {0.}, dd[2][2][4] = {0.}, JJ[2][2][4] = {0.}, 
           B[2] = {0.}; // 0 = + ; 1 = - ;
    double tau[2][2] = {0.}, K[2][2] = {0.}, b[2][2] = {0.};
    
    gamma0[0] = 6.*(N-1.)/N;
    gamma0[1] = -6.*(N+1.)/N;
    
    gamma1[0][0]=((N-1.)/(2.*N)) * ( -21. + 57./N - 19./3.*N + 4./3.*3.);
    gamma1[1][0]=((N+1.)/(2.*N)) * ( -21. - 57./N + 19./3.*N - 4./3.*3.);
    gamma1[0][1]=((N-1.)/(2.*N)) * ( -21. + 57./N - 19./3.*N + 4./3.*4.);
    gamma1[1][1]=((N+1.)/(2.*N)) * ( -21. - 57./N + 19./3.*N - 4./3.*4.);
    gamma1[0][2]=((N-1.)/(2.*N)) * ( -21. + 57./N - 19./3.*N + 4./3.*5.);
    gamma1[1][2]=((N+1.)/(2.*N)) * ( -21. - 57./N + 19./3.*N - 4./3.*5.);
    gamma1[0][3]=((N-1.)/(2.*N)) * ( -21. + 57./N - 19./3.*N + 4./3.*6.);
    gamma1[1][3]=((N+1.)/(2.*N)) * ( -21. - 57./N + 19./3.*N - 4./3.*6.);
    
    for (int i=0; i<2; i++){
        for (int j=0; j<4; j++){
            d[i][j] = gamma0[i]/2./model.Beta0(j+3);
            J[i][j] = d[i][j]/model.Beta0(j+3)*model.Beta1(j+3) - 
                      gamma1[i][j]/2./model.Beta0(j+3) ;
        }
    
    }
    
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            for (int k=0; k<4; k++){
                dd[i][j][k] = d[i][k] + d[j][k];
                JJ[i][j][k] = J[i][k] + J[j][k];
            }
        }
    }
    
    tau[0][0] = (N+3.)/4.;
    tau[1][0] = -(N-1.)/4.; tau[0][1] = tau[1][0];
    tau[1][1] = (N-1.)/4.;
    
    K[0][0] = 3.*(N-1.)*tau[0][0];
    K[1][0] = 3.*(N+1.)*tau[0][1]; K[0][1] = K[1][0];
    K[1][1] = 3.*(N+3.)*tau[1][1];
    
    b[0][0] = (1.-N)*( M_PI*M_PI*(N*N-6.)/(12.*N) + 3.*(-N*N+2.*N+13.)/(4.*N) );
    b[1][0] = (1.-N)*( M_PI*M_PI*(-N*N+2.*N-2.)/(12.*N) + (3.*N*N+13.)/(4.*N) );
    b[0][1] = b[1][0];
    b[1][1] = (1.-N)*( M_PI*M_PI*(N*N-4.*N+2)/(12.*N) - (3.*N*N+10.*N+13.)/(4.*N) );
    
    double eta = 0.;

    for(int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            eta += pow((model.Als(model.getMub())/model.Als(model.getMuc())),dd[i][j][1])*
                   pow((model.Als(model.getMuw())/model.Als(model.getMub())),dd[i][j][2])*
                   ( tau[i][j] + model.Als(model.getMuc())/ 4. /M_PI * (2. * K[i][j]*
                   log(model.getMuc() / model.getQuarks(QCD::CHARM).getMass()) +
                   tau[i][j] * (JJ[i][j][1] - J[0][0]) + b[i][j]) + 
                   tau[i][j]*(model.Als(model.getMub()) / 4. /M_PI * (JJ[i][j][2] - JJ[i][j][1])+
                   model.Als(model.getMuw()) / 4. / M_PI * (B[i] + B[j] - JJ[i][j][2])));
        }
    }
    
    eta *= pow(model.Als(model.getMuc()), d[0][0]);
    eta *= pow(model.Als(mu, FULLNLO), -2./9.);

    return (eta * (1. + model.Als(mu, FULLNLO)/4./M_PI*J[0][0]));
}

double EvolDF2::etact(double mu) const{
    
    double K = model.Als(model.getMuw())/model.Als(model.getMuc());
    double Kpp = pow(K, 12./25.);
    double Kpm = pow(K, -6./25.);
    double Kmm = pow(K, -24./25.);
    double K7 = pow(K, 1./5.);                                                                 
    double xt = model.GetMyMatching()->x_t(model.getMut());
    double xc = model.GetMyMatching()->x_c(model.getMuc());
    double J3 = 6.*(3.-1.)/3./2./model.Beta0(3)/model.Beta0(3)*model.Beta1(3) - 
                ((3.-1.)/(2.*3.)) * ( -21. + 57./3. - 19. + 4.)/2./model.Beta0(3) ;
    
    
    double eta = 0.;
    double AlsC = model.Als(model.getMuc());
    
    eta = ( M_PI / AlsC * (-18. / 7. * Kpp - 12. / 11. * Kpm + 6. / 29. * Kmm + 7716. / 2233. * K7) *
            (1. - AlsC / 4. / M_PI * 307. / 162.) + (log(model.getMuc() /
            model.getQuarks(QCD::CHARM).getMass()) - 0.25) * (3. * Kpp - 2. * Kpm + Kmm) +
            262497. / 35000. * Kpp - 123. / 625. * Kpm + 1108657. / 1305000. * Kmm - 277133. / 50750. * K7 +
            K * (-21093. / 8750. * Kpp + 13331. / 13750. * Kpm - 10181. / 18125. * Kmm - 1731104. / 2512125. * K7)+
            (log(xt) - (3. * xt) / (4. - 4. * xt) - log(xt)*(3. * xt * xt) / 4. / (1.-xt) / (1.-xt) + 0.5) * K * K7 )
            * xc / (xc * (log(xt / xc) - (3. * xt) / (4. - 4. * xt) - log(xt) * (3. * xt * xt) /4. / (1.-xt) / (1.-xt))) *
            pow(AlsC, 2. / 9.);
    
    return (eta * (1. + model.Als(mu, FULLNLO)/4./M_PI*J3) * 
            pow(model.Als(mu, FULLNLO),-2./9.));
}

double EvolDF2::etatt(double m) const {
    double N = model.getNc();
    double J3 = 6.*(N - 1.)/N * (model.Beta1(3)/2./model.Beta0(3)/model.Beta0(3)) - 
           (N - 1.)/(2.*N) * (-21. + 57./N - 19./3.*N + 4.)/2./model.Beta0(3);
    
    return (S1tt() * (1. + model.Als(m, FULLNLO)/4./M_PI*J3) *
            pow(model.Als(m, FULLNLO), -2./9.));
}

double EvolDF2::S1tt() const {
    double N = model.getNc();
    double x = model.GetMyMatching()->x_t(model.getMut());
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x3 * x;
    double xm2 = (1 - x) * (1 - x);
    double xm3 = xm2 * (1 - x);
    double xm4 = xm3 * (1 - x);
    double logx = log(x);
    double Li2 = gsl_sf_dilog(1-x);
    
    double S0tt = (4. * x - 11. * x2 + x3) / 4. / xm2 -
                  3. * x3 / (2. * xm3) * logx;
   
    double Bt = 5. * (N - 1.) / 2. / N + 3. * (N * N - 1.) / 2. / N;
    
    double gamma0 = 6. * (N - 1.) / N;
    
    double gamma1[4] = {0.}, J[4] = {0.};
    
    for(int i = 0; i < 4; ++i){
        gamma1[i] = (N - 1.)/(2. * N) * (-21. + 57./N - 19./3. * N + 4./3. * (i + 3.));
    }
    
    for(int k = 0; k < 4; ++k){
        J[k] = gamma0 * model.Beta1(3 + k) / 2. / model.Beta0(3 + k) / model.Beta0(3 + k)
               - gamma1[k] / 2. / model.Beta0(3 + k);
    }
        
    double b = (4. - 22. * x + 15. * x2 + 2. * x3 + x4 - 18. * x2 * logx)
               / ((-1. + x) * (-2. + 15. * x - 12. * x2 + x3 + 6. * x2 * logx));
    double AlsT = model.Als(model.getMut());
    double AlsB = model.Als(model.getMub());
    double AlsC = model.Als(model.getMuc());
    
    return (pow(model.Als(model.getMuc()), 6./27.) *
            pow(model.Als(model.getMub())/model.Als(model.getMuc()), 6./25.) *
            pow(model.Als(model.getMut())/model.Als(model.getMub()), 6./23.) *
            (1. + model.Als(model.getMuc())/4./M_PI * (J[1]-J[0]) +
            model.Als(model.getMub())/4./M_PI * (J[2]-J[1])
            + model.Als(model.getMut())/4./M_PI * (model.GetMyMatching()->S1(x)/S0tt
            + Bt - J[2] + gamma0*log(model.getMut()/model.getMuw())
            + 12.*(3./2.-1./6.)*log(model.getMut()/model.getMuw())*b)));
}