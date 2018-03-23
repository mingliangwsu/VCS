/******************************************************************************
 * @section DESCRIPTION
 *
 * This routine reads the VIC model global control file, getting values for
 * global parameters, model options, and debugging controls.
 *
 * @section LICENSE
 *
 * The Variable Infiltration Capacity (VIC) macroscale hydrological model
 * Copyright (C) 2016 The Computational Hydrology Group, Department of Civil
 * and Environmental Engineering, University of Washington.
 *
 * The VIC model is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *****************************************************************************/

#include <vic_driver_classic.h>
#include "VCS_user_def.h"
#include "vic_def.h"
#include <vcs_driver_shared_all.h>

/******************************************************************************
 * @brief    Read the VIC model crop related controls.
 *****************************************************************************/
void
get_global_crop_param(FILE *gp)
{
    extern option_struct       options;
    extern global_param_struct global_param;
    extern param_set_struct    param_set;
    extern filenames_struct    filenames;
    extern size_t              NF, NR;

    char                       cmdstr[MAXSTRING];
    char                       optstr[MAXSTRING];
    char                       flgstr[MAXSTRING];
    char                       flgstr2[MAXSTRING];
    size_t                     file_num;
    int                        field;
    int                        i;
    unsigned int               tmpstartdate;
    unsigned int               tmpenddate;
    unsigned short int         lastday[MONTHS_PER_YEAR];
    int                        simulation_years;

    file_num = 0;

    /** Read through global control file to find parameters **/

    fgets(cmdstr, MAXSTRING, gp);

    while (!feof(gp)) {
        if (cmdstr[0] != '#' && cmdstr[0] != '\n' && cmdstr[0] != '\0') {
            sscanf(cmdstr, "%s", optstr);

            /* Handle case of comment line in which '#' is indented */
            if (optstr[0] == '#') {
                fgets(cmdstr, MAXSTRING, gp);
                continue;
            }

            /*************************************
               Get Model Parameters
            *************************************/
            if(strcasecmp("NUMBER_SPINUPS",optstr) == 0) {
              sscanf(cmdstr,"%*s %d",&global_param.VCS.number_spinups_for_soil);
            }
            else if(strcasecmp("SPINUP_PERIOD",optstr) == 0) {
              sscanf(cmdstr,"%*s %d",&global_param.VCS.spinup_years);
            }
            else if(strcasecmp("CLAY_INPUT",optstr) == 0) { //check to see if clay percentage is provided
                sscanf(cmdstr,"%*s %s",flgstr);
                if(strcasecmp("TRUE",flgstr) == 0) options.VCS.clay_input = true;
                else options.VCS.clay_input = false;
            }
            else if( strcasecmp("CROPSYST_WORKING_DIR",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&filenames.VCS.CropSyst_Working_dir);
            }
            else if( strcasecmp("CO2_PPM",optstr) == 0){
                sscanf(cmdstr,"%*s %lf",&options.VCS.CO2_PPM);
            }
            else if(strcasecmp("CO2_TRANSIENT",optstr) == 0) {
                sscanf(cmdstr,"%*s %s",flgstr);
                if(strcasecmp("FALSE",flgstr) == 0) options.VCS.CO2_trans = false;
                else options.VCS.CO2_trans = true;
            }
            else if( strcasecmp("CO2_FILE",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&filenames.VCS.CO2_FILE);
            }
            else if(strcasecmp("CROPCODELIB",optstr) == 0) {
            sscanf(cmdstr,"%*s %s",&filenames.VCS.cropcodelib);
            }
#if (VIC_CROPSYST_VERSION<3)
            else if( strcasecmp("CROPPARAM",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&filenames.VCS.cropparam);
            }
            else if( strcasecmp("CROPLIB",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&filenames.VCS.croplib);
            }
#endif
            else if( strcasecmp("CROP_SPECIFIC_PARAM_DIR",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&options.VCS.crop_specfic_param_dir);
            }
#ifdef USE_IRRIGATION_PARAM_FILE
            else if(strcasecmp("IRRIGPARAM",optstr) == 0) {
                sscanf(cmdstr,"%*s %s",&filenames.VCS.irrig);
            }
#endif
#if (FULL_IRRIGATION==FALSE)
            else if ( strcasecmp("IRRIG_PATTERN",optstr) == 0){
                sscanf(cmdstr,"%*s %s",&filenames.VCS.irrig_fpath_pfx);
            }
#endif
            else if(strcasecmp("RESULT_CROP_OUTPUT_FILE_NAME",optstr) == 0) {
              sscanf(cmdstr,"%*s %s",&filenames.VCS.crop_output_file_name);
            }


            /***********************************
               Unrecognized Crop Parameter Flag
            ***********************************/
            else {
                log_warn("Unrecognized option in the crop parameter file: "
                         "%s is unknown - check your spelling", optstr);
            }
        }
        fgets(cmdstr, MAXSTRING, gp);
    }

    /******************************************
       Check for undefined required parameters
    ******************************************/
    simulation_years = global_param.endyear - global_param.startyear + 1;
    if (global_param.VCS.number_spinups_for_soil > 0
        && global_param.VCS.spinup_years < 1)
        global_param.VCS.spinup_years = 1;
    if (global_param.VCS.spinup_years > simulation_years)
        global_param.VCS.spinup_years = simulation_years;
    if (global_param.VCS.number_spinups_for_soil)
        global_param.VCS.is_spinup_run = 1;

    if ( strcmp ( filenames.VCS.crop_output_file_name, "MISSING" ) == 0 )
      log_err("Crop output file (%s) is not defined.",filenames.VCS.crop_output_file_name);
    if ( strcmp ( filenames.VCS.CropSyst_Working_dir, "MISSING" ) == 0 )
      log_err("Crop working directory is not defined.  Make sure that the global"
              " file defines the CropSyst working directory on the line that "
              " begins with \"CROPSYST_WORKING_DIR\".");
    if ( strcmp ( options.VCS.crop_specfic_param_dir, "MISSING" ) == 0 )
      log_err("Path for crop specific parameter files has NOT been defined."
              " Make sure that the global file defines the path on the line "
              " that begins with \"CROP_SPECIFIC_PARAM_DIR\".");
    if (options.VCS.CO2_trans) {
      if ( strcmp ( filenames.VCS.CO2_FILE, "MISSING" ) == 0 )
      log_err("No CO2 concentration file has been defined.  "
              "Make sure that the global file defines the irrigation pattern "
              "file on the line that begins with \"CO2_PPM\".");
    } else {
    if (options.VCS.CO2_PPM == 0 )
      log_err("CO2 concentration in ppm has NOT been defined.  "
              "Make sure that the global file defines this value on the line"
              " that begins with \"CO2_PPM\".");
    }
#if (FULL_IRRIGATION== FALSE)
    if ( strcmp ( filenames.VCS.irrig_fpath_pfx, "MISSING" ) == 0 )
      log_err("No Irrigation pattern file has been defined.  "
              "Make sure that the global file defines the irrigation pattern "
              "file on the line that begins with \"IRRIG_PATTERN\".");
#endif


    /*********************************
       Output major options
    *********************************/
    display_current_settings_crop(DISP_VERSION);
}
