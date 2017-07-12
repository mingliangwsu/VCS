#include "VCS_Nl_def.h"
#include <stdio.h>
#include <stdlib.h>

CropCodeLib *read_cropcodelib(FILE *cropcodelib, int &account)
{
    CropCodeLib *temp;
    char   str[50];
    rewind(cropcodelib);
    account = 0;
    while(fgets(str,MAXSTRING,cropcodelib)) {
      if (str[0] >= '0' and str[0] <= '9') account++;
    }
    rewind(cropcodelib);
    temp = (CropCodeLib *)calloc(account,sizeof(CropCodeLib));
    fgets(str,MAXSTRING,cropcodelib);
    int i=0;
    while (i < account) {
          fscanf(cropcodelib, "%d %[^\t\r\n]",&temp[i].code, &temp[i].cropname);
          //std::clog << "i:" << i << " cropname:" << "\"" << temp[i].cropname << "\"" << " code: " << temp[i].code << std::endl;
          i++;
    }
    return temp;
}
