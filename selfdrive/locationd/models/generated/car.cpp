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
void err_fun(double *nom_x, double *delta_x, double *out_7149951749923986916) {
   out_7149951749923986916[0] = delta_x[0] + nom_x[0];
   out_7149951749923986916[1] = delta_x[1] + nom_x[1];
   out_7149951749923986916[2] = delta_x[2] + nom_x[2];
   out_7149951749923986916[3] = delta_x[3] + nom_x[3];
   out_7149951749923986916[4] = delta_x[4] + nom_x[4];
   out_7149951749923986916[5] = delta_x[5] + nom_x[5];
   out_7149951749923986916[6] = delta_x[6] + nom_x[6];
   out_7149951749923986916[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4358957463070159273) {
   out_4358957463070159273[0] = -nom_x[0] + true_x[0];
   out_4358957463070159273[1] = -nom_x[1] + true_x[1];
   out_4358957463070159273[2] = -nom_x[2] + true_x[2];
   out_4358957463070159273[3] = -nom_x[3] + true_x[3];
   out_4358957463070159273[4] = -nom_x[4] + true_x[4];
   out_4358957463070159273[5] = -nom_x[5] + true_x[5];
   out_4358957463070159273[6] = -nom_x[6] + true_x[6];
   out_4358957463070159273[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_1705823266616191098) {
   out_1705823266616191098[0] = 1.0;
   out_1705823266616191098[1] = 0.0;
   out_1705823266616191098[2] = 0.0;
   out_1705823266616191098[3] = 0.0;
   out_1705823266616191098[4] = 0.0;
   out_1705823266616191098[5] = 0.0;
   out_1705823266616191098[6] = 0.0;
   out_1705823266616191098[7] = 0.0;
   out_1705823266616191098[8] = 0.0;
   out_1705823266616191098[9] = 1.0;
   out_1705823266616191098[10] = 0.0;
   out_1705823266616191098[11] = 0.0;
   out_1705823266616191098[12] = 0.0;
   out_1705823266616191098[13] = 0.0;
   out_1705823266616191098[14] = 0.0;
   out_1705823266616191098[15] = 0.0;
   out_1705823266616191098[16] = 0.0;
   out_1705823266616191098[17] = 0.0;
   out_1705823266616191098[18] = 1.0;
   out_1705823266616191098[19] = 0.0;
   out_1705823266616191098[20] = 0.0;
   out_1705823266616191098[21] = 0.0;
   out_1705823266616191098[22] = 0.0;
   out_1705823266616191098[23] = 0.0;
   out_1705823266616191098[24] = 0.0;
   out_1705823266616191098[25] = 0.0;
   out_1705823266616191098[26] = 0.0;
   out_1705823266616191098[27] = 1.0;
   out_1705823266616191098[28] = 0.0;
   out_1705823266616191098[29] = 0.0;
   out_1705823266616191098[30] = 0.0;
   out_1705823266616191098[31] = 0.0;
   out_1705823266616191098[32] = 0.0;
   out_1705823266616191098[33] = 0.0;
   out_1705823266616191098[34] = 0.0;
   out_1705823266616191098[35] = 0.0;
   out_1705823266616191098[36] = 1.0;
   out_1705823266616191098[37] = 0.0;
   out_1705823266616191098[38] = 0.0;
   out_1705823266616191098[39] = 0.0;
   out_1705823266616191098[40] = 0.0;
   out_1705823266616191098[41] = 0.0;
   out_1705823266616191098[42] = 0.0;
   out_1705823266616191098[43] = 0.0;
   out_1705823266616191098[44] = 0.0;
   out_1705823266616191098[45] = 1.0;
   out_1705823266616191098[46] = 0.0;
   out_1705823266616191098[47] = 0.0;
   out_1705823266616191098[48] = 0.0;
   out_1705823266616191098[49] = 0.0;
   out_1705823266616191098[50] = 0.0;
   out_1705823266616191098[51] = 0.0;
   out_1705823266616191098[52] = 0.0;
   out_1705823266616191098[53] = 0.0;
   out_1705823266616191098[54] = 1.0;
   out_1705823266616191098[55] = 0.0;
   out_1705823266616191098[56] = 0.0;
   out_1705823266616191098[57] = 0.0;
   out_1705823266616191098[58] = 0.0;
   out_1705823266616191098[59] = 0.0;
   out_1705823266616191098[60] = 0.0;
   out_1705823266616191098[61] = 0.0;
   out_1705823266616191098[62] = 0.0;
   out_1705823266616191098[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_3107942913451429060) {
   out_3107942913451429060[0] = state[0];
   out_3107942913451429060[1] = state[1];
   out_3107942913451429060[2] = state[2];
   out_3107942913451429060[3] = state[3];
   out_3107942913451429060[4] = state[4];
   out_3107942913451429060[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3107942913451429060[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3107942913451429060[7] = state[7];
}
void F_fun(double *state, double dt, double *out_5119554576570034335) {
   out_5119554576570034335[0] = 1;
   out_5119554576570034335[1] = 0;
   out_5119554576570034335[2] = 0;
   out_5119554576570034335[3] = 0;
   out_5119554576570034335[4] = 0;
   out_5119554576570034335[5] = 0;
   out_5119554576570034335[6] = 0;
   out_5119554576570034335[7] = 0;
   out_5119554576570034335[8] = 0;
   out_5119554576570034335[9] = 1;
   out_5119554576570034335[10] = 0;
   out_5119554576570034335[11] = 0;
   out_5119554576570034335[12] = 0;
   out_5119554576570034335[13] = 0;
   out_5119554576570034335[14] = 0;
   out_5119554576570034335[15] = 0;
   out_5119554576570034335[16] = 0;
   out_5119554576570034335[17] = 0;
   out_5119554576570034335[18] = 1;
   out_5119554576570034335[19] = 0;
   out_5119554576570034335[20] = 0;
   out_5119554576570034335[21] = 0;
   out_5119554576570034335[22] = 0;
   out_5119554576570034335[23] = 0;
   out_5119554576570034335[24] = 0;
   out_5119554576570034335[25] = 0;
   out_5119554576570034335[26] = 0;
   out_5119554576570034335[27] = 1;
   out_5119554576570034335[28] = 0;
   out_5119554576570034335[29] = 0;
   out_5119554576570034335[30] = 0;
   out_5119554576570034335[31] = 0;
   out_5119554576570034335[32] = 0;
   out_5119554576570034335[33] = 0;
   out_5119554576570034335[34] = 0;
   out_5119554576570034335[35] = 0;
   out_5119554576570034335[36] = 1;
   out_5119554576570034335[37] = 0;
   out_5119554576570034335[38] = 0;
   out_5119554576570034335[39] = 0;
   out_5119554576570034335[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5119554576570034335[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5119554576570034335[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5119554576570034335[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5119554576570034335[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5119554576570034335[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5119554576570034335[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5119554576570034335[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5119554576570034335[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5119554576570034335[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5119554576570034335[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5119554576570034335[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5119554576570034335[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5119554576570034335[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5119554576570034335[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5119554576570034335[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5119554576570034335[56] = 0;
   out_5119554576570034335[57] = 0;
   out_5119554576570034335[58] = 0;
   out_5119554576570034335[59] = 0;
   out_5119554576570034335[60] = 0;
   out_5119554576570034335[61] = 0;
   out_5119554576570034335[62] = 0;
   out_5119554576570034335[63] = 1;
}
void h_25(double *state, double *unused, double *out_7886620076215782108) {
   out_7886620076215782108[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4787885258591811532) {
   out_4787885258591811532[0] = 0;
   out_4787885258591811532[1] = 0;
   out_4787885258591811532[2] = 0;
   out_4787885258591811532[3] = 0;
   out_4787885258591811532[4] = 0;
   out_4787885258591811532[5] = 0;
   out_4787885258591811532[6] = 1;
   out_4787885258591811532[7] = 0;
}
void h_24(double *state, double *unused, double *out_8291048360233509148) {
   out_8291048360233509148[0] = state[4];
   out_8291048360233509148[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2144643392870800689) {
   out_2144643392870800689[0] = 0;
   out_2144643392870800689[1] = 0;
   out_2144643392870800689[2] = 0;
   out_2144643392870800689[3] = 0;
   out_2144643392870800689[4] = 1;
   out_2144643392870800689[5] = 0;
   out_2144643392870800689[6] = 0;
   out_2144643392870800689[7] = 0;
   out_2144643392870800689[8] = 0;
   out_2144643392870800689[9] = 0;
   out_2144643392870800689[10] = 0;
   out_2144643392870800689[11] = 0;
   out_2144643392870800689[12] = 0;
   out_2144643392870800689[13] = 1;
   out_2144643392870800689[14] = 0;
   out_2144643392870800689[15] = 0;
}
void h_30(double *state, double *unused, double *out_2796858740673097067) {
   out_2796858740673097067[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4044959904168556804) {
   out_4044959904168556804[0] = 0;
   out_4044959904168556804[1] = 0;
   out_4044959904168556804[2] = 0;
   out_4044959904168556804[3] = 0;
   out_4044959904168556804[4] = 1;
   out_4044959904168556804[5] = 0;
   out_4044959904168556804[6] = 0;
   out_4044959904168556804[7] = 0;
}
void h_26(double *state, double *unused, double *out_5833644792117429752) {
   out_5833644792117429752[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6129321392287459084) {
   out_6129321392287459084[0] = 0;
   out_6129321392287459084[1] = 0;
   out_6129321392287459084[2] = 0;
   out_6129321392287459084[3] = 0;
   out_6129321392287459084[4] = 0;
   out_6129321392287459084[5] = 0;
   out_6129321392287459084[6] = 0;
   out_6129321392287459084[7] = 1;
}
void h_27(double *state, double *unused, double *out_3557361293700703729) {
   out_3557361293700703729[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4288651372302925333) {
   out_4288651372302925333[0] = 0;
   out_4288651372302925333[1] = 0;
   out_4288651372302925333[2] = 0;
   out_4288651372302925333[3] = 1;
   out_4288651372302925333[4] = 0;
   out_4288651372302925333[5] = 0;
   out_4288651372302925333[6] = 0;
   out_4288651372302925333[7] = 0;
}
void h_29(double *state, double *unused, double *out_3400174625349574584) {
   out_3400174625349574584[0] = state[1];
}
void H_29(double *state, double *unused, double *out_221161135039724851) {
   out_221161135039724851[0] = 0;
   out_221161135039724851[1] = 1;
   out_221161135039724851[2] = 0;
   out_221161135039724851[3] = 0;
   out_221161135039724851[4] = 0;
   out_221161135039724851[5] = 0;
   out_221161135039724851[6] = 0;
   out_221161135039724851[7] = 0;
}
void h_28(double *state, double *unused, double *out_1200115212577673866) {
   out_1200115212577673866[0] = state[5];
   out_1200115212577673866[1] = state[6];
}
void H_28(double *state, double *unused, double *out_2238238913967399236) {
   out_2238238913967399236[0] = 0;
   out_2238238913967399236[1] = 0;
   out_2238238913967399236[2] = 0;
   out_2238238913967399236[3] = 0;
   out_2238238913967399236[4] = 0;
   out_2238238913967399236[5] = 1;
   out_2238238913967399236[6] = 0;
   out_2238238913967399236[7] = 0;
   out_2238238913967399236[8] = 0;
   out_2238238913967399236[9] = 0;
   out_2238238913967399236[10] = 0;
   out_2238238913967399236[11] = 0;
   out_2238238913967399236[12] = 0;
   out_2238238913967399236[13] = 0;
   out_2238238913967399236[14] = 1;
   out_2238238913967399236[15] = 0;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7149951749923986916) {
  err_fun(nom_x, delta_x, out_7149951749923986916);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4358957463070159273) {
  inv_err_fun(nom_x, true_x, out_4358957463070159273);
}
void car_H_mod_fun(double *state, double *out_1705823266616191098) {
  H_mod_fun(state, out_1705823266616191098);
}
void car_f_fun(double *state, double dt, double *out_3107942913451429060) {
  f_fun(state,  dt, out_3107942913451429060);
}
void car_F_fun(double *state, double dt, double *out_5119554576570034335) {
  F_fun(state,  dt, out_5119554576570034335);
}
void car_h_25(double *state, double *unused, double *out_7886620076215782108) {
  h_25(state, unused, out_7886620076215782108);
}
void car_H_25(double *state, double *unused, double *out_4787885258591811532) {
  H_25(state, unused, out_4787885258591811532);
}
void car_h_24(double *state, double *unused, double *out_8291048360233509148) {
  h_24(state, unused, out_8291048360233509148);
}
void car_H_24(double *state, double *unused, double *out_2144643392870800689) {
  H_24(state, unused, out_2144643392870800689);
}
void car_h_30(double *state, double *unused, double *out_2796858740673097067) {
  h_30(state, unused, out_2796858740673097067);
}
void car_H_30(double *state, double *unused, double *out_4044959904168556804) {
  H_30(state, unused, out_4044959904168556804);
}
void car_h_26(double *state, double *unused, double *out_5833644792117429752) {
  h_26(state, unused, out_5833644792117429752);
}
void car_H_26(double *state, double *unused, double *out_6129321392287459084) {
  H_26(state, unused, out_6129321392287459084);
}
void car_h_27(double *state, double *unused, double *out_3557361293700703729) {
  h_27(state, unused, out_3557361293700703729);
}
void car_H_27(double *state, double *unused, double *out_4288651372302925333) {
  H_27(state, unused, out_4288651372302925333);
}
void car_h_29(double *state, double *unused, double *out_3400174625349574584) {
  h_29(state, unused, out_3400174625349574584);
}
void car_H_29(double *state, double *unused, double *out_221161135039724851) {
  H_29(state, unused, out_221161135039724851);
}
void car_h_28(double *state, double *unused, double *out_1200115212577673866) {
  h_28(state, unused, out_1200115212577673866);
}
void car_H_28(double *state, double *unused, double *out_2238238913967399236) {
  H_28(state, unused, out_2238238913967399236);
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
};

ekf_init(car);
