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
void live_err_fun(double *nom_x, double *delta_x, double *out_6681952722314826255);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_922360340689958686);
void live_H_mod_fun(double *state, double *out_5666709602562674581);
void live_f_fun(double *state, double dt, double *out_3213916575171942643);
void live_F_fun(double *state, double dt, double *out_5839785342830623739);
void live_h_3(double *state, double *unused, double *out_4767590102331352519);
void live_H_3(double *state, double *unused, double *out_8958961328985003160);
void live_h_4(double *state, double *unused, double *out_1066455813048029150);
void live_H_4(double *state, double *unused, double *out_7194227069021352181);
void live_h_9(double *state, double *unused, double *out_931319823619027448);
void live_H_9(double *state, double *unused, double *out_473364142166128083);
void live_h_10(double *state, double *unused, double *out_5584505722919807121);
void live_H_10(double *state, double *unused, double *out_8018746901677029655);
void live_h_12(double *state, double *unused, double *out_5229354481090074703);
void live_H_12(double *state, double *unused, double *out_689314174297774484);
void live_h_31(double *state, double *unused, double *out_1877073562015545933);
void live_H_31(double *state, double *unused, double *out_3364403949441194305);
void live_h_32(double *state, double *unused, double *out_5917848915177628015);
void live_H_32(double *state, double *unused, double *out_5314905671088945952);
void live_h_13(double *state, double *unused, double *out_127656884398293636);
void live_H_13(double *state, double *unused, double *out_6897034671766546877);
void live_h_14(double *state, double *unused, double *out_931319823619027448);
void live_H_14(double *state, double *unused, double *out_473364142166128083);
void live_h_19(double *state, double *unused, double *out_8260433503627900087);
void live_H_19(double *state, double *unused, double *out_3959315708936303098);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}