#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_3(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_19(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_308962912849910417);
void live_err_fun(double *nom_x, double *delta_x, double *out_3752222109732568852);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2689811853463818113);
void live_H_mod_fun(double *state, double *out_7444513227488068757);
void live_f_fun(double *state, double dt, double *out_5185949218516742942);
void live_F_fun(double *state, double dt, double *out_1043013476035030683);
void live_h_3(double *state, double *unused, double *out_2345013922980096237);
void live_H_3(double *state, double *unused, double *out_6361024363989608575);
void live_h_4(double *state, double *unused, double *out_4185385736519085316);
void live_H_4(double *state, double *unused, double *out_1197661997788284489);
void live_h_9(double *state, double *unused, double *out_3221296746929078341);
void live_H_9(double *state, double *unused, double *out_5877513856007755182);
void live_h_10(double *state, double *unused, double *out_9055066725885081608);
void live_H_10(double *state, double *unused, double *out_1646237611563522501);
void live_h_12(double *state, double *unused, double *out_668963084071596404);
void live_H_12(double *state, double *unused, double *out_5307250896935293208);
void live_h_31(double *state, double *unused, double *out_2073798829201540176);
void live_H_31(double *state, double *unused, double *out_2632161121791873387);
void live_h_32(double *state, double *unused, double *out_4184026125448841534);
void live_H_32(double *state, double *unused, double *out_681659400144121740);
void live_h_13(double *state, double *unused, double *out_1780775751453709096);
void live_H_13(double *state, double *unused, double *out_8483862250287810165);
void live_h_14(double *state, double *unused, double *out_3221296746929078341);
void live_H_14(double *state, double *unused, double *out_5877513856007755182);
void live_h_19(double *state, double *unused, double *out_7542665183633693230);
void live_H_19(double *state, double *unused, double *out_1444834004905324001);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}