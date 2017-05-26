#include <VCS_Nl_def.h>

void init_irrigation_types(Irrigation_Types_In_Each_Cell *irrig_type)
{
    for (int i = 0; i < MAX_NUM_CROP_TYPES_FOR_IRRIGATION_DEFINE; i++) {
        irrig_type->crop_code[i]                   = 0;
        irrig_type->irrigation_type[i]             = NO_IRRIGATION;
        irrig_type->full_irrigation[i]             = false;
        irrig_type->fraction_full_irrigation[i]    = 0.0;
    }
}
