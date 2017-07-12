#include <vic_driver_classic.h>

/** Generating daily met for CropSyst**/

void generate_daily_forcing(force_data_struct *force)
{
    extern global_param_struct global_param;
    extern size_t              NR;
    size_t rec;
    const double tmp_max = -9999;
    const double tmp_min =  9999;
    int mspd        = global_param.model_steps_per_day;
    double fmspd    = double(mspd);
    if (mspd == 1) {
        log_err("For running CropSyst, the time_step for the model simulation "
                "& the forcing data should be sub-daily! "
                "\nThe current model_steps_per_day is (%zu) "
                , mspd);
    }
    for (rec = 0; rec < global_param.nrecs; rec+=mspd) {
        double tmax         = tmp_max;                                           //(C)
        double tmin         = tmp_min;                                           //(C)
        double tavg         = 0;                                                 //(C)
        double rhum_min     = tmp_min;                                           //(%)
        double rhum_max     = tmp_max;                                           //(%)
        double rhum_avg     = 0;                                                 //(%)
        double wind_avg     = 0;                                                 //(m/s)
        double pressure_avg = 0;                                                 //(kPa)
        double prec_sum     = 0;                                                 //(mm)
        double sw_rad_sum   = 0;                                                 //(MJ/m2)
        double vpd_avg      = 0;                                                 //(kPa)
        for (int ts = 0; ts < mspd; ts++) {
            force_data_struct &forcerec = force[rec + ts];
            if (forcerec.air_temp[NR] > tmax) tmax = forcerec.air_temp[NR];
            if (forcerec.air_temp[NR] < tmin) tmin = forcerec.air_temp[NR];
            if (forcerec.VCS.relative_humidity[NR] > rhum_max)
                rhum_max = forcerec.VCS.relative_humidity[NR];
            if (forcerec.VCS.relative_humidity[NR] < rhum_min)
                rhum_min = forcerec.VCS.relative_humidity[NR];
            tavg            += forcerec.air_temp[NR] / fmspd;
            rhum_avg        += forcerec.VCS.relative_humidity[NR] / fmspd;
            wind_avg        += forcerec.wind[NR] / fmspd;
            pressure_avg    += forcerec.pressure[NR] / fmspd;
            prec_sum        += forcerec.prec[NR];
            sw_rad_sum      += forcerec.shortwave[NR] * global_param.dt / 1.0e6; //W/m2 to MJ/m2
            vpd_avg         += forcerec.vpd[NR] / fmspd;
        } // ts
        for (int ts = 0; ts < mspd; ts++) {
            VCS_atmos_data_struct &force_vcs = force[rec + ts].VCS;
            force_vcs.tavg                      = tavg;
            force_vcs.tmax                      = tmax;
            force_vcs.tmin                      = tmin;
            force_vcs.relative_humidity_avg     = rhum_avg;
            force_vcs.relative_humidity_max     = rhum_max;
            force_vcs.relative_humidity_min     = rhum_min;
            force_vcs.pressure_avg              = pressure_avg;
            force_vcs.prec_sum                  = prec_sum;
            force_vcs.sortwave_radiation_sum    = sw_rad_sum;
            force_vcs.vpd_avg                   = vpd_avg;
            force_vcs.wind_avg                  = wind_avg;
        }
    } // rec
}
