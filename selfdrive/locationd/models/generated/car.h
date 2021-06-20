#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7582437248947558796);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_458515348946515658);
void car_H_mod_fun(double *state, double *out_5202225996327545638);
void car_f_fun(double *state, double dt, double *out_7570347676507654478);
void car_F_fun(double *state, double dt, double *out_2792396026175338455);
void car_h_25(double *state, double *unused, double *out_6601873018452771829);
void car_H_25(double *state, double *unused, double *out_6863434642336349819);
void car_h_24(double *state, double *unused, double *out_8262887622265338437);
void car_H_24(double *state, double *unused, double *out_5601045578140609687);
void car_h_30(double *state, double *unused, double *out_5624493872409765818);
void car_H_30(double *state, double *unused, double *out_1969410520424018517);
void car_h_26(double *state, double *unused, double *out_3020088551601068167);
void car_H_26(double *state, double *unused, double *out_8204870776031997371);
void car_h_27(double *state, double *unused, double *out_202831501038922683);
void car_H_27(double *state, double *unused, double *out_681828532587393205);
void car_h_29(double *state, double *unused, double *out_7000384455947063287);
void car_H_29(double *state, double *unused, double *out_2543969134279554692);
void car_h_28(double *state, double *unused, double *out_5891950483980975475);
void car_H_28(double *state, double *unused, double *out_5815144283080253307);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}