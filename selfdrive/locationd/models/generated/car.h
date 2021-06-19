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
void car_err_fun(double *nom_x, double *delta_x, double *out_7149951749923986916);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4358957463070159273);
void car_H_mod_fun(double *state, double *out_1705823266616191098);
void car_f_fun(double *state, double dt, double *out_3107942913451429060);
void car_F_fun(double *state, double dt, double *out_5119554576570034335);
void car_h_25(double *state, double *unused, double *out_7886620076215782108);
void car_H_25(double *state, double *unused, double *out_4787885258591811532);
void car_h_24(double *state, double *unused, double *out_8291048360233509148);
void car_H_24(double *state, double *unused, double *out_2144643392870800689);
void car_h_30(double *state, double *unused, double *out_2796858740673097067);
void car_H_30(double *state, double *unused, double *out_4044959904168556804);
void car_h_26(double *state, double *unused, double *out_5833644792117429752);
void car_H_26(double *state, double *unused, double *out_6129321392287459084);
void car_h_27(double *state, double *unused, double *out_3557361293700703729);
void car_H_27(double *state, double *unused, double *out_4288651372302925333);
void car_h_29(double *state, double *unused, double *out_3400174625349574584);
void car_H_29(double *state, double *unused, double *out_221161135039724851);
void car_h_28(double *state, double *unused, double *out_1200115212577673866);
void car_H_28(double *state, double *unused, double *out_2238238913967399236);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}