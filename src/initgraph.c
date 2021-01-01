#include <graphics.h>

/* GGI doesn't use driver files, so we can co-opt the third parameter
 * to initgraph as a pointer to a valid VESA Mode Info Block
 * as described on pages 30-31 (5) - see graphics.h for resources
 * referenced in parentheses
 */

#ifndef NULL
#define NULL 0
#endif

struct ModeInfoBlock * MIB = NULL;
struct status status;


void initgraph(int *graphdriver, int *graphmode, char *pathtodriver)
{
	status.devtyp = 0;
	status.res1[0] = 8;
	status.res1[1] = 8;
	status.res1[2] = 0x90;
	status.res1[3] = 0x90;

	if((*graphdriver == VGA256) || ((*graphdriver == DETECT) && (*pathtodriver == NULL)))
	{
		*graphmode = RES320x200;	
		*graphdriver = VGA256;
		status.xres = 319;
		status.yres = 199;
		status.xefres = 319;
		status.yefres = 199;
		status.xinch = 9000;
		status.yinch = 7000;
		status.aspec = 10000;
		status.scanlinebytes = status.xres;
		status.framebuffer = (char *) 0x000A0000;

		status.stat = grOk;

		return;
	}
	else if(*pathtodriver != NULL)
        {
		MIB = (struct ModeInfoBlock *) pathtodriver;
                if(MIB->ModeAttributes & 7)
                {
                        switch(MIB->XResolution) {
                                case 640:       if(MIB->YResolution == 480) {
                                                        *graphmode = RES640x480;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 800:       if(MIB->YResolution == 600) {
                                                        *graphmode = RES800x600;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 1024:      if(MIB->YResolution == 768) {
                                                        *graphmode = RES1024x768;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                case 1280:      if(MIB->YResolution == 1024) {
                                                        *graphmode = RES1280x1024;
                                                        *graphdriver = VESA256;
                                                        status.stat = grOk;
                                                 }
                                                else
                                                        status.stat = grNotDetected;
                                                break;

                                default:        status.stat = grInvalidDriver;
                                                break;
                        };
			if(status.stat == grOk)
			{
				status.xres = MIB->XResolution - 1;
				status.yres = MIB->YResolution - 1;
				status.xefres = status.xres;
				status.yefres = status.yres;
				status.xinch = 9000;
				status.yinch = 7000;
				status.aspec = 10000;	// Need to find out how to calc this!
				status.scanlinebytes = MIB->BytesPerScanLine;
				status.framebuffer = (char *) MIB->PhysBasePtr;
			}
                }
                else
                        status.stat = grInvalidDriver;
        }
        else
                status.stat = grNotDetected;
}

void detectgraph(int *graphdriver, int *graphmode)
{
	if((*graphdriver == VGA256) || (*graphdriver == DETECT) && (MIB == NULL))
	{
		*graphmode = RES320x200;
		*graphdriver = VGA256;
		status.stat = grOk;
	}
	else if(MIB != NULL)
	{
		if(MIB->ModeAttributes & 7)
		{
			switch(MIB->XResolution) {
				case 640:	if(MIB->YResolution == 480) {
							*graphmode = RES640x480;
							*graphdriver = VESA256;
							status.stat = grOk;
						}
						else
							status.stat = grNotDetected;
						break;
	
				case 800: 	if(MIB->YResolution == 600) {
							*graphmode = RES800x600;
							*graphdriver = VESA256;
							status.stat = grOk;
						}
						else
							status.stat = grNotDetected;
						break;
					  
				case 1024:	if(MIB->YResolution == 768) {
							*graphmode = RES1024x768;
							*graphdriver = VESA256;
							status.stat = grOk;
					  	}
					  	else
							status.stat = grNotDetected;
					  	break;
	
				case 1280: 	if(MIB->YResolution == 1024) {
							*graphmode = RES1280x1024;
							*graphdriver = VESA256;
							status.stat = grOk;
					 	 }
					  	else
							status.stat = grNotDetected;
					 	break;
	
				default: 	status.stat = grNotDetected;
						break;
			};
		}
		else
			status.stat = grNotDetected;
	}
	else
		status.stat = grNotDetected;
}
