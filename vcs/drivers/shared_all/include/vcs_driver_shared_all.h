/******************************************************************************
 * @section DESCRIPTION
 *
 * Header file for vcs_driver_shared_all routines
 *
 * @section LICENSE
 *
 *****************************************************************************/
#ifndef VCS_DRIVER_SHARED_H
#define VCS_DRIVER_SHARED_H
#include <VCS_Nl_def.h>
void display_current_settings_crop(int);
void init_irrigation_types(Irrigation_Types_In_Each_Cell*);
void init_vcs_cell(VCS_cell_data_struct *);
void generate_daily_forcing(force_data_struct *force);
#endif
