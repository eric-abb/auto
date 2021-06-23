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
void live_H(double *in_vec, double *out_2811332515993457942);
void live_err_fun(double *nom_x, double *delta_x, double *out_8823247670557876432);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5656353621262644632);
void live_H_mod_fun(double *state, double *out_7976488566062190887);
void live_f_fun(double *state, double dt, double *out_2814849615030551677);
void live_F_fun(double *state, double dt, double *out_5039691800764052261);
void live_h_3(double *state, double *unused, double *out_3664692667127371730);
void live_H_3(double *state, double *unused, double *out_3766881063486533812);
void live_h_4(double *state, double *unused, double *out_3883602739174136325);
void live_H_4(double *state, double *unused, double *out_1580847652296542477);
void live_h_9(double *state, double *unused, double *out_3164720381097686905);
void live_H_9(double *state, double *unused, double *out_5140015274558681621);
void live_h_10(double *state, double *unused, double *out_6834022281533783562);
void live_H_10(double *state, double *unused, double *out_9073830245799032054);
void live_h_12(double *state, double *unused, double *out_4288385701620642965);
void live_H_12(double *state, double *unused, double *out_4924065242427035220);
void live_h_31(double *state, double *unused, double *out_1722768878312840027);
void live_H_31(double *state, double *unused, double *out_2248975467283615399);
void live_h_32(double *state, double *unused, double *out_7598129179982326711);
void live_H_32(double *state, double *unused, double *out_4051390276976785787);
void live_h_13(double *state, double *unused, double *out_3993222505802934479);
void live_H_13(double *state, double *unused, double *out_441449736002151950);
void live_h_14(double *state, double *unused, double *out_3164720381097686905);
void live_H_14(double *state, double *unused, double *out_5140015274558681621);
void live_h_19(double *state, double *unused, double *out_6282971430789600940);
void live_H_19(double *state, double *unused, double *out_8874048948048438814);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}