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
void err_fun(double *nom_x, double *delta_x, double *out_5871393781681893243) {
   out_5871393781681893243[0] = delta_x[0] + nom_x[0];
   out_5871393781681893243[1] = delta_x[1] + nom_x[1];
   out_5871393781681893243[2] = delta_x[2] + nom_x[2];
   out_5871393781681893243[3] = delta_x[3] + nom_x[3];
   out_5871393781681893243[4] = delta_x[4] + nom_x[4];
   out_5871393781681893243[5] = delta_x[5] + nom_x[5];
   out_5871393781681893243[6] = delta_x[6] + nom_x[6];
   out_5871393781681893243[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8284221484306314985) {
   out_8284221484306314985[0] = -nom_x[0] + true_x[0];
   out_8284221484306314985[1] = -nom_x[1] + true_x[1];
   out_8284221484306314985[2] = -nom_x[2] + true_x[2];
   out_8284221484306314985[3] = -nom_x[3] + true_x[3];
   out_8284221484306314985[4] = -nom_x[4] + true_x[4];
   out_8284221484306314985[5] = -nom_x[5] + true_x[5];
   out_8284221484306314985[6] = -nom_x[6] + true_x[6];
   out_8284221484306314985[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_7944382865300486346) {
   out_7944382865300486346[0] = 1.0;
   out_7944382865300486346[1] = 0.0;
   out_7944382865300486346[2] = 0.0;
   out_7944382865300486346[3] = 0.0;
   out_7944382865300486346[4] = 0.0;
   out_7944382865300486346[5] = 0.0;
   out_7944382865300486346[6] = 0.0;
   out_7944382865300486346[7] = 0.0;
   out_7944382865300486346[8] = 0.0;
   out_7944382865300486346[9] = 1.0;
   out_7944382865300486346[10] = 0.0;
   out_7944382865300486346[11] = 0.0;
   out_7944382865300486346[12] = 0.0;
   out_7944382865300486346[13] = 0.0;
   out_7944382865300486346[14] = 0.0;
   out_7944382865300486346[15] = 0.0;
   out_7944382865300486346[16] = 0.0;
   out_7944382865300486346[17] = 0.0;
   out_7944382865300486346[18] = 1.0;
   out_7944382865300486346[19] = 0.0;
   out_7944382865300486346[20] = 0.0;
   out_7944382865300486346[21] = 0.0;
   out_7944382865300486346[22] = 0.0;
   out_7944382865300486346[23] = 0.0;
   out_7944382865300486346[24] = 0.0;
   out_7944382865300486346[25] = 0.0;
   out_7944382865300486346[26] = 0.0;
   out_7944382865300486346[27] = 1.0;
   out_7944382865300486346[28] = 0.0;
   out_7944382865300486346[29] = 0.0;
   out_7944382865300486346[30] = 0.0;
   out_7944382865300486346[31] = 0.0;
   out_7944382865300486346[32] = 0.0;
   out_7944382865300486346[33] = 0.0;
   out_7944382865300486346[34] = 0.0;
   out_7944382865300486346[35] = 0.0;
   out_7944382865300486346[36] = 1.0;
   out_7944382865300486346[37] = 0.0;
   out_7944382865300486346[38] = 0.0;
   out_7944382865300486346[39] = 0.0;
   out_7944382865300486346[40] = 0.0;
   out_7944382865300486346[41] = 0.0;
   out_7944382865300486346[42] = 0.0;
   out_7944382865300486346[43] = 0.0;
   out_7944382865300486346[44] = 0.0;
   out_7944382865300486346[45] = 1.0;
   out_7944382865300486346[46] = 0.0;
   out_7944382865300486346[47] = 0.0;
   out_7944382865300486346[48] = 0.0;
   out_7944382865300486346[49] = 0.0;
   out_7944382865300486346[50] = 0.0;
   out_7944382865300486346[51] = 0.0;
   out_7944382865300486346[52] = 0.0;
   out_7944382865300486346[53] = 0.0;
   out_7944382865300486346[54] = 1.0;
   out_7944382865300486346[55] = 0.0;
   out_7944382865300486346[56] = 0.0;
   out_7944382865300486346[57] = 0.0;
   out_7944382865300486346[58] = 0.0;
   out_7944382865300486346[59] = 0.0;
   out_7944382865300486346[60] = 0.0;
   out_7944382865300486346[61] = 0.0;
   out_7944382865300486346[62] = 0.0;
   out_7944382865300486346[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_6781441984645342126) {
   out_6781441984645342126[0] = state[0];
   out_6781441984645342126[1] = state[1];
   out_6781441984645342126[2] = state[2];
   out_6781441984645342126[3] = state[3];
   out_6781441984645342126[4] = state[4];
   out_6781441984645342126[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6781441984645342126[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6781441984645342126[7] = state[7];
}
void F_fun(double *state, double dt, double *out_5189593092005031373) {
   out_5189593092005031373[0] = 1;
   out_5189593092005031373[1] = 0;
   out_5189593092005031373[2] = 0;
   out_5189593092005031373[3] = 0;
   out_5189593092005031373[4] = 0;
   out_5189593092005031373[5] = 0;
   out_5189593092005031373[6] = 0;
   out_5189593092005031373[7] = 0;
   out_5189593092005031373[8] = 0;
   out_5189593092005031373[9] = 1;
   out_5189593092005031373[10] = 0;
   out_5189593092005031373[11] = 0;
   out_5189593092005031373[12] = 0;
   out_5189593092005031373[13] = 0;
   out_5189593092005031373[14] = 0;
   out_5189593092005031373[15] = 0;
   out_5189593092005031373[16] = 0;
   out_5189593092005031373[17] = 0;
   out_5189593092005031373[18] = 1;
   out_5189593092005031373[19] = 0;
   out_5189593092005031373[20] = 0;
   out_5189593092005031373[21] = 0;
   out_5189593092005031373[22] = 0;
   out_5189593092005031373[23] = 0;
   out_5189593092005031373[24] = 0;
   out_5189593092005031373[25] = 0;
   out_5189593092005031373[26] = 0;
   out_5189593092005031373[27] = 1;
   out_5189593092005031373[28] = 0;
   out_5189593092005031373[29] = 0;
   out_5189593092005031373[30] = 0;
   out_5189593092005031373[31] = 0;
   out_5189593092005031373[32] = 0;
   out_5189593092005031373[33] = 0;
   out_5189593092005031373[34] = 0;
   out_5189593092005031373[35] = 0;
   out_5189593092005031373[36] = 1;
   out_5189593092005031373[37] = 0;
   out_5189593092005031373[38] = 0;
   out_5189593092005031373[39] = 0;
   out_5189593092005031373[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5189593092005031373[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5189593092005031373[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5189593092005031373[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5189593092005031373[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5189593092005031373[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5189593092005031373[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5189593092005031373[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5189593092005031373[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5189593092005031373[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5189593092005031373[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5189593092005031373[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5189593092005031373[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5189593092005031373[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5189593092005031373[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5189593092005031373[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5189593092005031373[56] = 0;
   out_5189593092005031373[57] = 0;
   out_5189593092005031373[58] = 0;
   out_5189593092005031373[59] = 0;
   out_5189593092005031373[60] = 0;
   out_5189593092005031373[61] = 0;
   out_5189593092005031373[62] = 0;
   out_5189593092005031373[63] = 1;
}
void h_25(double *state, double *unused, double *out_4883216662656602646) {
   out_4883216662656602646[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3491575996171757049) {
   out_3491575996171757049[0] = 0;
   out_3491575996171757049[1] = 0;
   out_3491575996171757049[2] = 0;
   out_3491575996171757049[3] = 0;
   out_3491575996171757049[4] = 0;
   out_3491575996171757049[5] = 0;
   out_3491575996171757049[6] = 1;
   out_3491575996171757049[7] = 0;
}
void h_24(double *state, double *unused, double *out_2642892073469964299) {
   out_2642892073469964299[0] = state[4];
   out_2642892073469964299[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2229186931976016917) {
   out_2229186931976016917[0] = 0;
   out_2229186931976016917[1] = 0;
   out_2229186931976016917[2] = 0;
   out_2229186931976016917[3] = 0;
   out_2229186931976016917[4] = 1;
   out_2229186931976016917[5] = 0;
   out_2229186931976016917[6] = 0;
   out_2229186931976016917[7] = 0;
   out_2229186931976016917[8] = 0;
   out_2229186931976016917[9] = 0;
   out_2229186931976016917[10] = 0;
   out_2229186931976016917[11] = 0;
   out_2229186931976016917[12] = 0;
   out_2229186931976016917[13] = 1;
   out_2229186931976016917[14] = 0;
   out_2229186931976016917[15] = 0;
}
void h_30(double *state, double *unused, double *out_3363244810572768934) {
   out_3363244810572768934[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5341269166588611287) {
   out_5341269166588611287[0] = 0;
   out_5341269166588611287[1] = 0;
   out_5341269166588611287[2] = 0;
   out_5341269166588611287[3] = 0;
   out_5341269166588611287[4] = 1;
   out_5341269166588611287[5] = 0;
   out_5341269166588611287[6] = 0;
   out_5341269166588611287[7] = 0;
}
void h_26(double *state, double *unused, double *out_1599135187108524298) {
   out_1599135187108524298[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2213017158767452224) {
   out_2213017158767452224[0] = 0;
   out_2213017158767452224[1] = 0;
   out_2213017158767452224[2] = 0;
   out_2213017158767452224[3] = 0;
   out_2213017158767452224[4] = 0;
   out_2213017158767452224[5] = 0;
   out_2213017158767452224[6] = 0;
   out_2213017158767452224[7] = 1;
}
void h_27(double *state, double *unused, double *out_7805542497059211014) {
   out_7805542497059211014[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4053687178751985975) {
   out_4053687178751985975[0] = 0;
   out_4053687178751985975[1] = 0;
   out_4053687178751985975[2] = 0;
   out_4053687178751985975[3] = 1;
   out_4053687178751985975[4] = 0;
   out_4053687178751985975[5] = 0;
   out_4053687178751985975[6] = 0;
   out_4053687178751985975[7] = 0;
}
void h_29(double *state, double *unused, double *out_3980140081432744651) {
   out_3980140081432744651[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5915827780444147462) {
   out_5915827780444147462[0] = 0;
   out_5915827780444147462[1] = 1;
   out_5915827780444147462[2] = 0;
   out_5915827780444147462[3] = 0;
   out_5915827780444147462[4] = 0;
   out_5915827780444147462[5] = 0;
   out_5915827780444147462[6] = 0;
   out_5915827780444147462[7] = 0;
}
void h_28(double *state, double *unused, double *out_8150244692828410161) {
   out_8150244692828410161[0] = state[5];
   out_8150244692828410161[1] = state[6];
}
void H_28(double *state, double *unused, double *out_4788645546260477949) {
   out_4788645546260477949[0] = 0;
   out_4788645546260477949[1] = 0;
   out_4788645546260477949[2] = 0;
   out_4788645546260477949[3] = 0;
   out_4788645546260477949[4] = 0;
   out_4788645546260477949[5] = 1;
   out_4788645546260477949[6] = 0;
   out_4788645546260477949[7] = 0;
   out_4788645546260477949[8] = 0;
   out_4788645546260477949[9] = 0;
   out_4788645546260477949[10] = 0;
   out_4788645546260477949[11] = 0;
   out_4788645546260477949[12] = 0;
   out_4788645546260477949[13] = 0;
   out_4788645546260477949[14] = 1;
   out_4788645546260477949[15] = 0;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5871393781681893243) {
  err_fun(nom_x, delta_x, out_5871393781681893243);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8284221484306314985) {
  inv_err_fun(nom_x, true_x, out_8284221484306314985);
}
void car_H_mod_fun(double *state, double *out_7944382865300486346) {
  H_mod_fun(state, out_7944382865300486346);
}
void car_f_fun(double *state, double dt, double *out_6781441984645342126) {
  f_fun(state,  dt, out_6781441984645342126);
}
void car_F_fun(double *state, double dt, double *out_5189593092005031373) {
  F_fun(state,  dt, out_5189593092005031373);
}
void car_h_25(double *state, double *unused, double *out_4883216662656602646) {
  h_25(state, unused, out_4883216662656602646);
}
void car_H_25(double *state, double *unused, double *out_3491575996171757049) {
  H_25(state, unused, out_3491575996171757049);
}
void car_h_24(double *state, double *unused, double *out_2642892073469964299) {
  h_24(state, unused, out_2642892073469964299);
}
void car_H_24(double *state, double *unused, double *out_2229186931976016917) {
  H_24(state, unused, out_2229186931976016917);
}
void car_h_30(double *state, double *unused, double *out_3363244810572768934) {
  h_30(state, unused, out_3363244810572768934);
}
void car_H_30(double *state, double *unused, double *out_5341269166588611287) {
  H_30(state, unused, out_5341269166588611287);
}
void car_h_26(double *state, double *unused, double *out_1599135187108524298) {
  h_26(state, unused, out_1599135187108524298);
}
void car_H_26(double *state, double *unused, double *out_2213017158767452224) {
  H_26(state, unused, out_2213017158767452224);
}
void car_h_27(double *state, double *unused, double *out_7805542497059211014) {
  h_27(state, unused, out_7805542497059211014);
}
void car_H_27(double *state, double *unused, double *out_4053687178751985975) {
  H_27(state, unused, out_4053687178751985975);
}
void car_h_29(double *state, double *unused, double *out_3980140081432744651) {
  h_29(state, unused, out_3980140081432744651);
}
void car_H_29(double *state, double *unused, double *out_5915827780444147462) {
  H_29(state, unused, out_5915827780444147462);
}
void car_h_28(double *state, double *unused, double *out_8150244692828410161) {
  h_28(state, unused, out_8150244692828410161);
}
void car_H_28(double *state, double *unused, double *out_4788645546260477949) {
  H_28(state, unused, out_4788645546260477949);
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
