#include "car.h"

namespace {
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 5.991464547107981;

/******************************************************************************
 *                      Code generated with sympy 1.7.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7582437248947558796) {
   out_7582437248947558796[0] = delta_x[0] + nom_x[0];
   out_7582437248947558796[1] = delta_x[1] + nom_x[1];
   out_7582437248947558796[2] = delta_x[2] + nom_x[2];
   out_7582437248947558796[3] = delta_x[3] + nom_x[3];
   out_7582437248947558796[4] = delta_x[4] + nom_x[4];
   out_7582437248947558796[5] = delta_x[5] + nom_x[5];
   out_7582437248947558796[6] = delta_x[6] + nom_x[6];
   out_7582437248947558796[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_458515348946515658) {
   out_458515348946515658[0] = -nom_x[0] + true_x[0];
   out_458515348946515658[1] = -nom_x[1] + true_x[1];
   out_458515348946515658[2] = -nom_x[2] + true_x[2];
   out_458515348946515658[3] = -nom_x[3] + true_x[3];
   out_458515348946515658[4] = -nom_x[4] + true_x[4];
   out_458515348946515658[5] = -nom_x[5] + true_x[5];
   out_458515348946515658[6] = -nom_x[6] + true_x[6];
   out_458515348946515658[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_5202225996327545638) {
   out_5202225996327545638[0] = 1.0;
   out_5202225996327545638[1] = 0.0;
   out_5202225996327545638[2] = 0.0;
   out_5202225996327545638[3] = 0.0;
   out_5202225996327545638[4] = 0.0;
   out_5202225996327545638[5] = 0.0;
   out_5202225996327545638[6] = 0.0;
   out_5202225996327545638[7] = 0.0;
   out_5202225996327545638[8] = 0.0;
   out_5202225996327545638[9] = 1.0;
   out_5202225996327545638[10] = 0.0;
   out_5202225996327545638[11] = 0.0;
   out_5202225996327545638[12] = 0.0;
   out_5202225996327545638[13] = 0.0;
   out_5202225996327545638[14] = 0.0;
   out_5202225996327545638[15] = 0.0;
   out_5202225996327545638[16] = 0.0;
   out_5202225996327545638[17] = 0.0;
   out_5202225996327545638[18] = 1.0;
   out_5202225996327545638[19] = 0.0;
   out_5202225996327545638[20] = 0.0;
   out_5202225996327545638[21] = 0.0;
   out_5202225996327545638[22] = 0.0;
   out_5202225996327545638[23] = 0.0;
   out_5202225996327545638[24] = 0.0;
   out_5202225996327545638[25] = 0.0;
   out_5202225996327545638[26] = 0.0;
   out_5202225996327545638[27] = 1.0;
   out_5202225996327545638[28] = 0.0;
   out_5202225996327545638[29] = 0.0;
   out_5202225996327545638[30] = 0.0;
   out_5202225996327545638[31] = 0.0;
   out_5202225996327545638[32] = 0.0;
   out_5202225996327545638[33] = 0.0;
   out_5202225996327545638[34] = 0.0;
   out_5202225996327545638[35] = 0.0;
   out_5202225996327545638[36] = 1.0;
   out_5202225996327545638[37] = 0.0;
   out_5202225996327545638[38] = 0.0;
   out_5202225996327545638[39] = 0.0;
   out_5202225996327545638[40] = 0.0;
   out_5202225996327545638[41] = 0.0;
   out_5202225996327545638[42] = 0.0;
   out_5202225996327545638[43] = 0.0;
   out_5202225996327545638[44] = 0.0;
   out_5202225996327545638[45] = 1.0;
   out_5202225996327545638[46] = 0.0;
   out_5202225996327545638[47] = 0.0;
   out_5202225996327545638[48] = 0.0;
   out_5202225996327545638[49] = 0.0;
   out_5202225996327545638[50] = 0.0;
   out_5202225996327545638[51] = 0.0;
   out_5202225996327545638[52] = 0.0;
   out_5202225996327545638[53] = 0.0;
   out_5202225996327545638[54] = 1.0;
   out_5202225996327545638[55] = 0.0;
   out_5202225996327545638[56] = 0.0;
   out_5202225996327545638[57] = 0.0;
   out_5202225996327545638[58] = 0.0;
   out_5202225996327545638[59] = 0.0;
   out_5202225996327545638[60] = 0.0;
   out_5202225996327545638[61] = 0.0;
   out_5202225996327545638[62] = 0.0;
   out_5202225996327545638[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_7570347676507654478) {
   out_7570347676507654478[0] = state[0];
   out_7570347676507654478[1] = state[1];
   out_7570347676507654478[2] = state[2];
   out_7570347676507654478[3] = state[3];
   out_7570347676507654478[4] = state[4];
   out_7570347676507654478[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7570347676507654478[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7570347676507654478[7] = state[7];
}
void F_fun(double *state, double dt, double *out_2792396026175338455) {
   out_2792396026175338455[0] = 1;
   out_2792396026175338455[1] = 0;
   out_2792396026175338455[2] = 0;
   out_2792396026175338455[3] = 0;
   out_2792396026175338455[4] = 0;
   out_2792396026175338455[5] = 0;
   out_2792396026175338455[6] = 0;
   out_2792396026175338455[7] = 0;
   out_2792396026175338455[8] = 0;
   out_2792396026175338455[9] = 1;
   out_2792396026175338455[10] = 0;
   out_2792396026175338455[11] = 0;
   out_2792396026175338455[12] = 0;
   out_2792396026175338455[13] = 0;
   out_2792396026175338455[14] = 0;
   out_2792396026175338455[15] = 0;
   out_2792396026175338455[16] = 0;
   out_2792396026175338455[17] = 0;
   out_2792396026175338455[18] = 1;
   out_2792396026175338455[19] = 0;
   out_2792396026175338455[20] = 0;
   out_2792396026175338455[21] = 0;
   out_2792396026175338455[22] = 0;
   out_2792396026175338455[23] = 0;
   out_2792396026175338455[24] = 0;
   out_2792396026175338455[25] = 0;
   out_2792396026175338455[26] = 0;
   out_2792396026175338455[27] = 1;
   out_2792396026175338455[28] = 0;
   out_2792396026175338455[29] = 0;
   out_2792396026175338455[30] = 0;
   out_2792396026175338455[31] = 0;
   out_2792396026175338455[32] = 0;
   out_2792396026175338455[33] = 0;
   out_2792396026175338455[34] = 0;
   out_2792396026175338455[35] = 0;
   out_2792396026175338455[36] = 1;
   out_2792396026175338455[37] = 0;
   out_2792396026175338455[38] = 0;
   out_2792396026175338455[39] = 0;
   out_2792396026175338455[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2792396026175338455[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2792396026175338455[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2792396026175338455[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2792396026175338455[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2792396026175338455[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2792396026175338455[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2792396026175338455[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2792396026175338455[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2792396026175338455[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2792396026175338455[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2792396026175338455[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2792396026175338455[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2792396026175338455[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2792396026175338455[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2792396026175338455[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2792396026175338455[56] = 0;
   out_2792396026175338455[57] = 0;
   out_2792396026175338455[58] = 0;
   out_2792396026175338455[59] = 0;
   out_2792396026175338455[60] = 0;
   out_2792396026175338455[61] = 0;
   out_2792396026175338455[62] = 0;
   out_2792396026175338455[63] = 1;
}
void h_25(double *state, double *unused, double *out_6601873018452771829) {
   out_6601873018452771829[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6863434642336349819) {
   out_6863434642336349819[0] = 0;
   out_6863434642336349819[1] = 0;
   out_6863434642336349819[2] = 0;
   out_6863434642336349819[3] = 0;
   out_6863434642336349819[4] = 0;
   out_6863434642336349819[5] = 0;
   out_6863434642336349819[6] = 1;
   out_6863434642336349819[7] = 0;
}
void h_24(double *state, double *unused, double *out_8262887622265338437) {
   out_8262887622265338437[0] = state[4];
   out_8262887622265338437[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5601045578140609687) {
   out_5601045578140609687[0] = 0;
   out_5601045578140609687[1] = 0;
   out_5601045578140609687[2] = 0;
   out_5601045578140609687[3] = 0;
   out_5601045578140609687[4] = 1;
   out_5601045578140609687[5] = 0;
   out_5601045578140609687[6] = 0;
   out_5601045578140609687[7] = 0;
   out_5601045578140609687[8] = 0;
   out_5601045578140609687[9] = 0;
   out_5601045578140609687[10] = 0;
   out_5601045578140609687[11] = 0;
   out_5601045578140609687[12] = 0;
   out_5601045578140609687[13] = 1;
   out_5601045578140609687[14] = 0;
   out_5601045578140609687[15] = 0;
}
void h_30(double *state, double *unused, double *out_5624493872409765818) {
   out_5624493872409765818[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1969410520424018517) {
   out_1969410520424018517[0] = 0;
   out_1969410520424018517[1] = 0;
   out_1969410520424018517[2] = 0;
   out_1969410520424018517[3] = 0;
   out_1969410520424018517[4] = 1;
   out_1969410520424018517[5] = 0;
   out_1969410520424018517[6] = 0;
   out_1969410520424018517[7] = 0;
}
void h_26(double *state, double *unused, double *out_3020088551601068167) {
   out_3020088551601068167[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8204870776031997371) {
   out_8204870776031997371[0] = 0;
   out_8204870776031997371[1] = 0;
   out_8204870776031997371[2] = 0;
   out_8204870776031997371[3] = 0;
   out_8204870776031997371[4] = 0;
   out_8204870776031997371[5] = 0;
   out_8204870776031997371[6] = 0;
   out_8204870776031997371[7] = 1;
}
void h_27(double *state, double *unused, double *out_202831501038922683) {
   out_202831501038922683[0] = state[3];
}
void H_27(double *state, double *unused, double *out_681828532587393205) {
   out_681828532587393205[0] = 0;
   out_681828532587393205[1] = 0;
   out_681828532587393205[2] = 0;
   out_681828532587393205[3] = 1;
   out_681828532587393205[4] = 0;
   out_681828532587393205[5] = 0;
   out_681828532587393205[6] = 0;
   out_681828532587393205[7] = 0;
}
void h_29(double *state, double *unused, double *out_7000384455947063287) {
   out_7000384455947063287[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2543969134279554692) {
   out_2543969134279554692[0] = 0;
   out_2543969134279554692[1] = 1;
   out_2543969134279554692[2] = 0;
   out_2543969134279554692[3] = 0;
   out_2543969134279554692[4] = 0;
   out_2543969134279554692[5] = 0;
   out_2543969134279554692[6] = 0;
   out_2543969134279554692[7] = 0;
}
void h_28(double *state, double *unused, double *out_5891950483980975475) {
   out_5891950483980975475[0] = state[5];
   out_5891950483980975475[1] = state[6];
}
void H_28(double *state, double *unused, double *out_5815144283080253307) {
   out_5815144283080253307[0] = 0;
   out_5815144283080253307[1] = 0;
   out_5815144283080253307[2] = 0;
   out_5815144283080253307[3] = 0;
   out_5815144283080253307[4] = 0;
   out_5815144283080253307[5] = 1;
   out_5815144283080253307[6] = 0;
   out_5815144283080253307[7] = 0;
   out_5815144283080253307[8] = 0;
   out_5815144283080253307[9] = 0;
   out_5815144283080253307[10] = 0;
   out_5815144283080253307[11] = 0;
   out_5815144283080253307[12] = 0;
   out_5815144283080253307[13] = 0;
   out_5815144283080253307[14] = 1;
   out_5815144283080253307[15] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7582437248947558796) {
  err_fun(nom_x, delta_x, out_7582437248947558796);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_458515348946515658) {
  inv_err_fun(nom_x, true_x, out_458515348946515658);
}
void car_H_mod_fun(double *state, double *out_5202225996327545638) {
  H_mod_fun(state, out_5202225996327545638);
}
void car_f_fun(double *state, double dt, double *out_7570347676507654478) {
  f_fun(state,  dt, out_7570347676507654478);
}
void car_F_fun(double *state, double dt, double *out_2792396026175338455) {
  F_fun(state,  dt, out_2792396026175338455);
}
void car_h_25(double *state, double *unused, double *out_6601873018452771829) {
  h_25(state, unused, out_6601873018452771829);
}
void car_H_25(double *state, double *unused, double *out_6863434642336349819) {
  H_25(state, unused, out_6863434642336349819);
}
void car_h_24(double *state, double *unused, double *out_8262887622265338437) {
  h_24(state, unused, out_8262887622265338437);
}
void car_H_24(double *state, double *unused, double *out_5601045578140609687) {
  H_24(state, unused, out_5601045578140609687);
}
void car_h_30(double *state, double *unused, double *out_5624493872409765818) {
  h_30(state, unused, out_5624493872409765818);
}
void car_H_30(double *state, double *unused, double *out_1969410520424018517) {
  H_30(state, unused, out_1969410520424018517);
}
void car_h_26(double *state, double *unused, double *out_3020088551601068167) {
  h_26(state, unused, out_3020088551601068167);
}
void car_H_26(double *state, double *unused, double *out_8204870776031997371) {
  H_26(state, unused, out_8204870776031997371);
}
void car_h_27(double *state, double *unused, double *out_202831501038922683) {
  h_27(state, unused, out_202831501038922683);
}
void car_H_27(double *state, double *unused, double *out_681828532587393205) {
  H_27(state, unused, out_681828532587393205);
}
void car_h_29(double *state, double *unused, double *out_7000384455947063287) {
  h_29(state, unused, out_7000384455947063287);
}
void car_H_29(double *state, double *unused, double *out_2543969134279554692) {
  H_29(state, unused, out_2543969134279554692);
}
void car_h_28(double *state, double *unused, double *out_5891950483980975475) {
  h_28(state, unused, out_5891950483980975475);
}
void car_H_28(double *state, double *unused, double *out_5815144283080253307) {
  H_28(state, unused, out_5815144283080253307);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
