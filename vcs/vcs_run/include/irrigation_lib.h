
/***********************************************************
this library was created for VIC-CropSyst coupling to consider
the effect of different irrigation systems
it used to be under surface_fluxes.c and  store some information
about irrigation systems and efficiencies

2011-sep library was created                             KJC
2012-Nov-14 seperate irrigation library was created and
            moved from from surface_fluxes.c              KM

***********************************************************/
#ifndef IRRIGATION_LIB_H
#define IRRIGATION_LIB_H
//160504LML #define IRRIGATION_TYPES    40
#ifdef VIC_CROPSYST_VERSION
#if (VIC_CROPSYST_VERSION>=3)
typedef struct Irrigation_Efficiency
{
    double time_irrig;                                                           //(hrs)
    double uniformity;                                                           //
    double presumed_efficiency;                                                  //(fraction)
    double table_irrigation_efficiency;
    double table_irrigation_runoff_loss;                                         //(fraction)
    double table_irrigation_evap_loss;                                           //(fraction)
    double table_irrigation_deep_percolation_loss;                               //(fraction)
    double maximum_capacity;                                                     //(mm H2O/hour)
} Irrigation_Efficiency;
//______________________________________________________________________________
typedef struct Irrigation_Facility_Charactor
{
    double Runoff;
    double D;                   //(mm) average droplet size
    double h_op;                //(kg/cm2) irrigation system operating pressure
    double H;                   //(m)
    double cd;                  //nuzzle coeficient
    double y0_spk;              //(m) height of the irrigation sprinkler from ground
    double x_dm_spk;            //(m) diameter of sprinkler
    double Q;                   //
    double q_nuzzle;            //angle of the nuzzle
    double v;                   //(m/sec)
    double A_Ap;                //fraction of area which is covered by irrigation system at a time
    double tirrig;              //(hr) time of irrig
    double actual_droplet_size;
} Irrigation_Facility_Charactor;
//______________________________________________________________________________
typedef enum General_Irrigation_Type{
    GENERAL_NO_IRRIGATION            = 0,                                         //LML 150501
    CENTER_PIVOT                    = 1,
    BIG_GUN                         = 2,
    SOLID_SET                       = 3,
    WHEEL_LINE                      = 4,
    DRIP                            = 5,
    FLOOD                           = 6,
    RILL                            = 7,
    FURROW                          = 8,
    GENERAL_IRRIGATION_TYPE_ACCOUNTS
} General_Irrigation_Type;
//______________________________________________________________________________
typedef enum Irrigation_Type {
    NO_IRRIGATION                               = 0,                             //LML 150501
    IrrigTP_CP_impact_14VH_RainBird             = 1,
    IrrigTP_CP_impact_M20VH_PM_RainBird         = 2,
    IrrigTP_CP_impact_65PJ_RainBird             = 3,
    IrrigTP_CP_impact_30FH_30FWH_RainBird       = 4,
    IrrigTP_CP_impact_L36H_L36AH_RainBird_1     = 5,
    IrrigTP_CP_impact_L36H_L36AH_RainBird_2     = 6,
    IrrigTP_CP_impact_85EHD_RainBird_1          = 7,
    IrrigTP_CP_impact_85EHD_RainBird_2          = 8,
    IrrigTP_CP_impact_85EHD_RainBird_3          = 9,
    IrrigTP_CP_impact_85EHD_LA_RainBird_1       = 10,
    IrrigTP_CP_impact_85EHD_LA_RainBird_2       = 11,
    IrrigTP_CP_impact_85EHD_LA_RainBird_3       = 12,
    IrrigTP_CP_spray_S3000_Nelson               = 21,
    IrrigTP_CP_spray_O3000_Nelson               = 22,
    IrrigTP_CP_spray_R3000_Nelson_1             = 23,
    IrrigTP_CP_spray_R3000_Nelson_2             = 24,
    IrrigTP_CP_spray_A3000_Nelson_1             = 25,
    IrrigTP_CP_spray_A3000_Nelson_2             = 26,
    DEFAULT_CENTER_PIVOT                        = 30,                            //170830LML

    IrrigTP_Big_Gun_75TR_Nelson_1               = 31,
    IrrigTP_Big_Gun_75TR_Nelson_2               = 32,
    IrrigTP_Big_Gun_75TR_Nelson_3               = 33,
    IrrigTP_Big_Gun_150TB_Nelson_1              = 34,
    IrrigTP_Big_Gun_150TB_Nelson_2              = 35,
    IrrigTP_Big_Gun_150TB_Nelson_3              = 36,
    IrrigTP_Big_Gun_200TB_Nelson_1              = 37,
    IrrigTP_Big_Gun_200TB_Nelson_2              = 38,
    IrrigTP_Big_Gun_200TB_Nelson_3              = 39,
    DEFAULT_BIG_GUN                             = 40,                            //170830LML

    IrrigTP_Solid_set_R5_POP_UP_Nelson          = 41,
    IrrigTP_Solid_set_R2000WF_6_Nelson_1        = 42,
    IrrigTP_Solid_set_R2000WF_6_Nelson_2        = 43,
    IrrigTP_Solid_set_R2000WF_6_Nelson_3        = 44,
    IrrigTP_Solid_set_R33_Nelson                = 45,
    DEFAULT_SOLID_SET                           = 50,                            //170830LML

    IrrigTP_Moving_wheel_R2000WF_6_Nelson_1     = 51,
    IrrigTP_Moving_wheel_R2000WF_6_Nelson_2     = 52,
    IrrigTP_Moving_wheel_R2000WF_6_Nelson_3     = 53,
    DEFAULT_MOVING_WHEEL                        = 60,                            //170830LML

    IrrigTP_drip_0_0                            = 61,
    IrrigTP_Sub_surf_drip_0_0                   = 62,
    DEFAULT_DRIP                                = 70,                            //170830LML

    IrrigTP_flood_0_0                           = 71,
    DEFAULT_FLOOD                               = 71,                            //170830LML

    IrrigTP_rill_0_0                            = 72,
    DEFAULT_RILL                                = 72,                            //170830LML

    IrrigTP_furrow_0_0                          = 73,
    DEFAULT_FURROW                              = 73,                            //170830LML
    IRRIGATION_TYPE_ACCOUNTS
} Irrigation_Type;
#endif //VIC_CROPSYST_VERSION>=3
//______________________________________________________________________________
typedef struct VIC_Irrigation_library
{
    #if (VIC_CROPSYST_VERSION>=3)
    Irrigation_Type IrrigationType_code;
    Irrigation_Facility_Charactor irrigation_facility_charactor;
    Irrigation_Efficiency irrigation_efficiency;
    #else
    int IrrigationType_code;
    float irrigation_efficiency[13];
    #endif
} VIC_Irrigation_library;
extern VIC_Irrigation_library Irrigation_library[IRRIGATION_TYPE_ACCOUNTS/*160504LML IRRIGATION_TYPES*/];
#endif //VIC_CROPSYST_VERSION
#endif
