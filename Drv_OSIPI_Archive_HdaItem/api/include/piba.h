/*------------------------------------------------------------------------

$Archive: /pi/clients/piapi/piba.h $

--------------------------------------------------------------------------
Copyright (c) 1996-2017 OSIsoft, LLC. All rights reserved.
Unpublished - rights reserved under the copyright law of the United States.

USE OF A COPYRIGHT NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
OR DISCLOSURE.

THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE SECRETS OF
OSIsoft, LLC. USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT
THE PRIOR EXPRESSED WRITTEN PERMISSION OF OSIsoft, LLC.
 
RESTRICTED RIGHTS LEGEND
Use, duplication, or disclosure by the Government is subject to restrictions
as set forth in subparagraph (c)(1)(ii) of the Rights in Technical Data and
Computer Software clause at DFARS 252.227.7013.

OSIsoft, LLC
1600 Alvarado Street, San Leandro CA, 94577
--------------------------------------------------------------------------

Description:  PI batch access functions.

------------------------------------------------------------------------*/
/*  PI Batch API Header File   */
#ifndef _PIBA_H
#define _PIBA_H
#include "pidefs.h"
#ifdef __cplusplus
extern "C"
{
#endif

int32 PIPROC piba_findaliaspoint ( char PIPTR *unit, char PIPTR *alias,
                                   int32 PIPTR *point, char PIPTR *tagname, int32 len );
int32 PIPROC piba_getunit ( char PIPTR *unit, int32 len, int32 index,
                            int32 PIPTR *number );
int32 PIPROC piba_getunitswalias ( char PIPTR *alias, char PIPTR *unit, int32 len,
                                   int32 index, int32 PIPTR *number );
int32 PIPROC piba_getaliaswunit ( char PIPTR *unit, char PIPTR *alias, int32 len,
                                  int32 index, int32 PIPTR *number );
int32 PIPROC piba_search ( char PIPTR *batchid, int32 len0, char PIPTR *unit, int32 len1,
                           char PIPTR *product, int32 len2, int32 PIPTR *startime, int32 PIPTR *endtime,
                           int32 searchflag, int32 timeout );

#ifdef __cplusplus
}
#endif


#endif



