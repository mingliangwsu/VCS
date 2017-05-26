QT       += core
QT       -= gui
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QMAKE_CFLAGS += -std=c99 -fpermissive

#170525LML using g++ to compile
QMAKE_CXX = g++
QMAKE_CC = g++
QMAKE_CXXFLAGS += -fpermissive  -w -g -O0
QMAKE_CXXFLAGS += -Wno-reorder -Wno-unused-parameter -Wno-unused-but-set-parameter

DEFINES += VIC_CROPSYST_VERSION=4 \
           USE_IRRIGATION_PARAM_FILE \
           VCS_V5 \
           CROPSYST_VERSION=5

INCLUDEPATH += ../../../../../VIC/vic/drivers/classic/include \
               ../../../../../VIC/vic/drivers/shared_all/include \
               ../../../../../VIC/vic/vic_run/include \
               ../../../../vcs/vcs_run/include \
               ../../../../vcs/drivers/shared_all/include \
               ../../../../vcs/drivers/classic/include \
               ../../../../../VIC_CropSyst_common \
               ../../../../../VIC_CropSyst \
               ../../../../../CropSyst/source \
               ../../../../../common \
               ../../../../../corn \
               ../../../../../CropSyst \
               ../../../../../

SOURCES += \
    ../../../../../VIC/vic/drivers/classic/src/alloc_atmos.c \
    ../../../../../VIC/vic/drivers/classic/src/alloc_veg_hist.c \
    ../../../../../VIC/vic/drivers/classic/src/check_files.c \
    ../../../../../VIC/vic/drivers/classic/src/check_save_state_flag.c \
    ../../../../../VIC/vic/drivers/classic/src/check_state_file.c \
    ../../../../../VIC/vic/drivers/classic/src/close_files.c \
    ../../../../../VIC/vic/drivers/classic/src/compute_cell_area.c \
    ../../../../../VIC/vic/drivers/classic/src/display_current_settings.c \
    ../../../../../VIC/vic/drivers/classic/src/get_dist.c \
    ../../../../../VIC/vic/drivers/classic/src/get_force_type.c \
    ../../../../../VIC/vic/drivers/classic/src/get_global_param.c \
    ../../../../../VIC/vic/drivers/classic/src/initialize_files.c \
    ../../../../../VIC/vic/drivers/classic/src/initialize_forcing_files.c \
    ../../../../../VIC/vic/drivers/classic/src/make_in_and_outfiles.c \
    ../../../../../VIC/vic/drivers/classic/src/open_state_file.c \
    ../../../../../VIC/vic/drivers/classic/src/parse_output_info.c \
    ../../../../../VIC/vic/drivers/classic/src/print_library_classic.c \
    ../../../../../VIC/vic/drivers/classic/src/read_atmos_data.c \
    ../../../../../VIC/vic/drivers/classic/src/read_forcing_data.c \
    ../../../../../VIC/vic/drivers/classic/src/read_initial_model_state.c \
    ../../../../../VIC/vic/drivers/classic/src/read_lakeparam.c \
    ../../../../../VIC/vic/drivers/classic/src/read_snowband.c \
    ../../../../../VIC/vic/drivers/classic/src/read_soilparam.c \
    ../../../../../VIC/vic/drivers/classic/src/read_veglib.c \
    ../../../../../VIC/vic/drivers/classic/src/read_vegparam.c \
    ../../../../../VIC/vic/drivers/classic/src/vic_classic.c \
    ../../../../../VIC/vic/drivers/classic/src/vic_classic_timing.c \
    ../../../../../VIC/vic/drivers/classic/src/vic_force.c \
    ../../../../../VIC/vic/drivers/classic/src/vic_populate_model_state.c \
    ../../../../../VIC/vic/drivers/classic/src/write_data.c \
    ../../../../../VIC/vic/drivers/classic/src/write_header.c \
    ../../../../../VIC/vic/drivers/classic/src/write_model_state.c \
    ../../../../../VIC/vic/drivers/classic/src/write_output.c \
    ../../../../../VIC/vic/vic_run/src/advected_sensible_heat.c \
    ../../../../../VIC/vic/vic_run/src/alloc_and_free.c \
    ../../../../../VIC/vic/vic_run/src/arno_evap.c \
    ../../../../../VIC/vic/vic_run/src/CalcAerodynamic.c \
    ../../../../../VIC/vic/vic_run/src/calc_atmos_energy_bal.c \
    ../../../../../VIC/vic/vic_run/src/CalcBlowingSnow.c \
    ../../../../../VIC/vic/vic_run/src/calc_Nscale_factors.c \
    ../../../../../VIC/vic/vic_run/src/calc_rainonly.c \
    ../../../../../VIC/vic/vic_run/src/calc_snow_coverage.c \
    ../../../../../VIC/vic/vic_run/src/calc_surf_energy_bal.c \
    ../../../../../VIC/vic/vic_run/src/calc_veg_params.c \
    ../../../../../VIC/vic/vic_run/src/canopy_assimilation.c \
    ../../../../../VIC/vic/vic_run/src/canopy_evap.c \
    ../../../../../VIC/vic/vic_run/src/comparisons.c \
    ../../../../../VIC/vic/vic_run/src/compute_coszen.c \
    ../../../../../VIC/vic/vic_run/src/compute_derived_lake_dimensions.c \
    ../../../../../VIC/vic/vic_run/src/compute_pot_evap.c \
    ../../../../../VIC/vic/vic_run/src/compute_soil_resp.c \
    ../../../../../VIC/vic/vic_run/src/compute_zwt.c \
    ../../../../../VIC/vic/vic_run/src/correct_precip.c \
    ../../../../../VIC/vic/vic_run/src/estimate_T1.c \
    ../../../../../VIC/vic/vic_run/src/faparl.c \
    ../../../../../VIC/vic/vic_run/src/frozen_soil.c \
    ../../../../../VIC/vic/vic_run/src/func_atmos_energy_bal.c \
    ../../../../../VIC/vic/vic_run/src/func_atmos_moist_bal.c \
    ../../../../../VIC/vic/vic_run/src/func_canopy_energy_bal.c \
    ../../../../../VIC/vic/vic_run/src/func_surf_energy_bal.c \
    ../../../../../VIC/vic/vic_run/src/IceEnergyBalance.c \
    ../../../../../VIC/vic/vic_run/src/ice_melt.c \
    ../../../../../VIC/vic/vic_run/src/initialize_lake.c \
    ../../../../../VIC/vic/vic_run/src/interpoloation.c \
    ../../../../../VIC/vic/vic_run/src/lakes.eb.c \
    ../../../../../VIC/vic/vic_run/src/lake_utils.c \
    ../../../../../VIC/vic/vic_run/src/latent_heat_from_snow.c \
    ../../../../../VIC/vic/vic_run/src/massrelease.c \
    ../../../../../VIC/vic/vic_run/src/newt_raph_func_fast.c \
    ../../../../../VIC/vic/vic_run/src/penman.c \
    ../../../../../VIC/vic/vic_run/src/photosynth.c \
    ../../../../../VIC/vic/vic_run/src/physics.c \
    ../../../../../VIC/vic/vic_run/src/prepare_full_energy.c \
    ../../../../../VIC/vic/vic_run/src/root_brent.c \
    ../../../../../VIC/vic/vic_run/src/runoff.c \
    ../../../../../VIC/vic/vic_run/src/snow_intercept.c \
    ../../../../../VIC/vic/vic_run/src/snow_melt.c \
    ../../../../../VIC/vic/vic_run/src/SnowPackEnergyBalance.c \
    ../../../../../VIC/vic/vic_run/src/snow_utility.c \
    ../../../../../VIC/vic/vic_run/src/soil_carbon_balance.c \
    ../../../../../VIC/vic/vic_run/src/soil_conduction.c \
    ../../../../../VIC/vic/vic_run/src/soil_thermal_eqn.c \
    ../../../../../VIC/vic/vic_run/src/solve_snow.c \
    ../../../../../VIC/vic/vic_run/src/StabilityCorrection.c \
    ../../../../../VIC/vic/vic_run/src/surface_fluxes.c \
    ../../../../../VIC/vic/vic_run/src/svp.c \
    ../../../../../VIC/vic/vic_run/src/vic_run.c \
    ../../../../../VIC/vic/vic_run/src/water_energy_balance.c \
    ../../../../../VIC/vic/vic_run/src/water_under_ice.c \
    ../../../../../VIC/vic/vic_run/src/write_layer.c \
    ../../../../../VIC/vic/vic_run/src/write_vegvar.c \
    ../../../../../VIC/vic/drivers/shared_all/src/agg_data.c \
    ../../../../../VIC/vic/drivers/shared_all/src/alarms.c \
    ../../../../../VIC/vic/drivers/shared_all/src/calc_root_fraction.c \
    ../../../../../VIC/vic/drivers/shared_all/src/cmd_proc.c \
    ../../../../../VIC/vic/drivers/shared_all/src/compress_files.c \
    ../../../../../VIC/vic/drivers/shared_all/src/compute_derived_state_vars.c \
    ../../../../../VIC/vic/drivers/shared_all/src/compute_lake_params.c \
    ../../../../../VIC/vic/drivers/shared_all/src/compute_treeline.c \
    ../../../../../VIC/vic/drivers/shared_all/src/forcing_utils.c \
    ../../../../../VIC/vic/drivers/shared_all/src/free_all_vars.c \
    ../../../../../VIC/vic/drivers/shared_all/src/free_vegcon.c \
    ../../../../../VIC/vic/drivers/shared_all/src/generate_default_lake_state.c \
    ../../../../../VIC/vic/drivers/shared_all/src/generate_default_state.c \
    ../../../../../VIC/vic/drivers/shared_all/src/get_parameters.c \
    ../../../../../VIC/vic/drivers/shared_all/src/history_metadata.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_energy.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_global.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_options.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_parameters.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_snow.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_soil.c \
    ../../../../../VIC/vic/drivers/shared_all/src/initialize_veg.c \
    ../../../../../VIC/vic/drivers/shared_all/src/input_tools.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_all_vars.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_cell_data.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_dmy.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_energy_bal.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_snow_data.c \
    ../../../../../VIC/vic/drivers/shared_all/src/make_veg_var.c \
    ../../../../../VIC/vic/drivers/shared_all/src/open_file.c \
    ../../../../../VIC/vic/drivers/shared_all/src/print_library_shared.c \
    ../../../../../VIC/vic/drivers/shared_all/src/put_data.c \
    ../../../../../VIC/vic/drivers/shared_all/src/set_output_defaults.c \
    ../../../../../VIC/vic/drivers/shared_all/src/soil_moisture_from_water_table.c \
    ../../../../../VIC/vic/drivers/shared_all/src/timing.c \
    ../../../../../VIC/vic/drivers/shared_all/src/update_step_vars.c \
    ../../../../../VIC/vic/drivers/shared_all/src/vic_history.c \
    ../../../../../VIC/vic/drivers/shared_all/src/vic_log.c \
    ../../../../../VIC/vic/drivers/shared_all/src/vic_time.c \
    ../../../../../VIC/vic/drivers/shared_all/src/zero_output_list.c \
    ../../../../vcs/drivers/classic/src/get_global_crop_param.c \
    ../../../../vcs/drivers/classic/src/display_current_settings_crop.c \
    ../../../../vcs/drivers/shared_all/src/init_irrigation_types.c \
    ../../../../../VIC_CropSyst_common/VCS_Nl.c

HEADERS += \
    ../../../../../VIC/vic/drivers/classic/include/vic_driver_classic.h \
    ../../../../../VIC/vic/drivers/shared_all/include/vic_driver_shared_all.h \
    ../../../../../VIC/vic/drivers/shared_all/include/vic_version.h \
    ../../../../../VIC/vic/vic_run/include/vic_def.h \
    ../../../../../VIC/vic/vic_run/include/vic_log.h \
    ../../../../../VIC/vic/vic_run/include/vic_physical_constants.h \
    ../../../../../VIC/vic/vic_run/include/vic_run.h \
    ../../../../vcs/vcs_run/include/VCS_Nl_def.h \
    ../../../../vcs/vcs_run/include/VCS_user_def.h \
    ../../../../vcs/drivers/shared_all/include/vcs_driver_shared_all.h \
    ../../../../../VIC_CropSyst_common/VCS_Nl.h
