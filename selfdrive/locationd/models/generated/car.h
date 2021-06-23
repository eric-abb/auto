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
void car_err_fun(double *nom_x, double *delta_x, double *out_5871393781681893243);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8284221484306314985);
void car_H_mod_fun(double *state, double *out_7944382865300486346);
void car_f_fun(double *state, double dt, double *out_6781441984645342126);
void car_F_fun(double *state, double dt, double *out_5189593092005031373);
void car_h_25(double *state, double *unused, double *out_4883216662656602646);
void car_H_25(double *state, double *unused, double *out_3491575996171757049);
void car_h_24(double *state, double *unused, double *out_2642892073469964299);
void car_H_24(double *state, double *unused, double *out_2229186931976016917);
void car_h_30(double *state, double *unused, double *out_3363244810572768934);
void car_H_30(double *state, double *unused, double *out_5341269166588611287);
void car_h_26(double *state, double *unused, double *out_1599135187108524298);
void car_H_26(double *state, double *unused, double *out_2213017158767452224);
void car_h_27(double *state, double *unused, double *out_7805542497059211014);
void car_H_27(double *state, double *unused, double *out_4053687178751985975);
void car_h_29(double *state, double *unused, double *out_3980140081432744651);
void car_H_29(double *state, double *unused, double *out_5915827780444147462);
void car_h_28(double *state, double *unused, double *out_8150244692828410161);
void car_H_28(double *state, double *unused, double *out_4788645546260477949);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}