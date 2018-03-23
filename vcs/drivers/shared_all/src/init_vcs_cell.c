#include <VCS_Nl_def.h>

void init_vcs_cell(VCS_cell_data_struct *vcs_cell)
{
    vcs_cell->actual_irrigation_reach_ground_amount   = 0.0;
    vcs_cell->total_irrigation_water                  = 0.0;
    vcs_cell->irrigation_runoff                       = 0.0;
    vcs_cell->evap_from_irrigation_syst               = 0.0;
    vcs_cell->evap_from_irrigation_intercept          = 0.0;
    vcs_cell->irrig_canopy_loss                       = 0.0;
    vcs_cell->evap_from_soil                          = 0.0;
    vcs_cell->intercepted_irrigation                  = 0.0;
    vcs_cell->potential_transpir                      = 0.0;
    vcs_cell->infiltration                            = 0.0;
    vcs_cell->irrigation_water                        = 0.0;
    for (int i = 0; i < N_PET_TYPES; i++) {
        for (int j = 0; j < 3; j++)
            vcs_cell->aero_resist_daily[i][j] = 0.0;
    }
#ifndef VCS_V5
    for (int i = 0; i < N_PET_TYPES; i++)
        vcs_cell->pot_evap_daily[i] = 0.0;
#else
    vcs_cell->pot_evap_total_daily    = 0.0;
    vcs_cell->pot_evap_veg_daily      = 0.0;
    vcs_cell->pot_evap_soil_daily     = 0.0;
#endif
    vcs_cell->iscrop                  = 0;
    vcs_cell->infiltration_daily_m    = 0.0;
}
