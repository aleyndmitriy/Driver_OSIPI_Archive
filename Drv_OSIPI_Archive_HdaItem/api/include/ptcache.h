/*-----------------------------------------------------------------------------

$Archive: /pi/clients/piapi/ptcache.h $

--------------------------------------------------------------------------------
Copyright (c) 2006-2017 OSIsoft, LLC. All rights reserved.
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
--------------------------------------------------------------------------------

Description:

          This file contains header information for point caching functions
          accessible outside of the piapi32.dll

-------------------------------------------------------------------------------

$Log: /pi/clients/piapi/ptcache.h $

39    9/28/11 2:06p Driddell

38    9/28/11 11:16a Driddell

37    2/23/11 6:58a Driddell
Add some code comments

36    1/31/11 12:38p Driddell
Changes to disconnected startup. Removed "servername" from picm_
function calls.

35    12/16/10 8:32a Driddell
Changes made to make the PI API backward compatible with older
applicaitons that use disconnected startup and have been built against
PI API versions prior to 1.6.4.5.

34    12/11/10 12:15p Driddell
Add picm_getpointrecord() and struct SPointRecord

33    12/09/10 2:25p Driddell
Added NO_MORE_PT_UPDATES -61. Remove commented errorneous return
values.

32    12/07/10 1:44p Driddell
Added sorting option to picm_pointlist() and supported functions.

31    11/30/10 9:52a Driddell
Modify picm_pointcount() and picm_pointlist()

30    11/29/10 3:15p Driddell
Added picm_pointcount() and picm_pointlist().

29    11/24/10 2:11p Driddell
Changes made during testing. Also add picm_removepoint() function.

28    11/16/10 1:26p Driddell
Add PI_CM_FILENOTFOUND code to CACHERROR enum. Modify status of
RenameCacheFile() and set return status to calls to remove()

27    11/12/10 12:09p Driddell
Added cache error codes. Modify picm_iscachevalid() and related
functions.

26    11/10/10 12:53p Driddell
Modifications to caching. Added IsCacheValid function. Rename functions
to be more readable.

25    11/09/10 12:58p Driddell
Rename and reorganize members.

24    11/08/10 2:19p Driddell
Changes to cache file initialization process.

23    11/05/10 10:08a Driddell
Changes for disconnected startup initialization and cache closing
functions.

22    11/04/10 2:54p Driddell
Disconnected startup changes.

21    10/29/10 1:52p Driddell
Modifications for multi-server caching

20    10/29/10 12:14p Driddell
multi-server disconnected startup changes

19    10/28/10 2:01p Driddell
Modifications for multi-server caching

18    10/27/10 1:46p Driddell
Modifications to support multi-server disconnected startup.

17    10/25/10 2:05p Driddell
Modifications to handle old and new version of PI API.

16    10/13/10 4:19p Driddell
Removed NOT_SUPPORTED from enum eSYNCHSTATUS.

15    9/10/10 12:39p Driddell
Add picm_initializemultiserver() to ptcache.h. Initialize iterator.

14    9/09/10 1:30p Driddell
Disconnected Startup work for PLI#20322OSI8, PLI#22757OSI8,
PLI#22756OSI8, PLI#19377OSI8, PLI#13731OSI8

12    4/11/07 11:04a Tcantele

10    2/23/07 9:50a Ken
Update copyight symbol and company name.  [13799OSI8]

9     10/04/06 8:26a Driddell
Updated for version  API 1.6.1.2

7     9/25/06 11:20a Driddell
Point caching modifications

6     9/08/06 2:09p Driddell

5     9/07/06 12:08p Driddell
Modified point caching functions

4     9/05/06 2:56p Driddell
Point caching work

3     8/31/06 3:39p Driddell
Changes to handle point cache synchronization

2     8/29/06 2:21p Driddell
More modifications for point caching

1     8/25/06 12:00p Driddell
Files added for Point Caching

History:

08/25/2006  DPR     written
-----------------------------------------------------------------------------*/

#ifndef __PICA_CACHE_H__
#define __PICA_CACHE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "piapix.h"

#define NO_MORE_POINTS  0
#define MORE_POINTS     1
#define UNKNWN_ERROR    2
#define CACHE_INVALID   3

#define NO_MORE_PT_UPDATES          -61         /* No more point updates available */
#define PTATTR_BUFF_LEN             1024        /* Maximum point attribute length */
#define DIG_STRING_LEN              80          /* Maximum digital state string length */

typedef enum eCACHEERRORS
{
   PI_CM_ADDPOINT                  = -20000,   /* Failed to add point to cache */
   PI_CM_ALREADYINITIALIZED        = -20001,   /* Cache already initialized */
   PI_CM_APPNAMEMISMATCH           = -20002,   /* Application name in file does not match configuration application name */
   PI_CM_BADALLOC                  = -20003,   /* Bad memory allocation */
   PI_CM_BADPOINTER                = -20004,   /* Bad or NULL pointer */
   PI_CM_BUILDSTATNOTFOUND         = -20005,   /* Build status not found in cache */
   PI_CM_CACHEPOINT                = -20006,   /* Unable to cache point */
   PI_CM_CACHEPTRNULL              = -20007,   /* Point and DigitaSet cache pointer is NULL */
   PI_CM_CACHETOOMANYERRORS        = -20008,   /* Too many errors found in cache */
   PI_CM_FILEALREADYOPEN           = -20009,   /* Cache file is already open */
   PI_CM_FILEDOESNOTEXIST          = -20010,   /* Cache file does not exist */
   PI_CM_FILEINCOMPLETE            = -20011,   /* Incomplete cache file */
   PI_CM_FILENOTFOUND              = -20012,   /* File not found */
   PI_CM_FILESETTOINVALID          = -20013,   /* Opened file has been set to invalid */
   PI_CM_FILEVALIDNOTFOUND         = -20014,   /* File validity variable not found in cache */
   PI_CM_HOSTALREADYOPEN           = -20015,   /* Host server already open and initialized */
   PI_CM_HOSTMISMATCH              = -20016,   /* Hostname in file does not match configuration hostname */
   PI_CM_HOSTNOTREACHABLE          = -20017,   /* Host server not reachable during call to piut_setservernode (invalid name or communication error) */
   PI_CM_IDMISMATCH                = -20018,   /* Id in file does not match configuraiton id */
   PI_CM_INVALIDCACHEFILE          = -20019,   /* Invalid cache file */
   PI_CM_NOCACHEFORHOST            = -20020,   /* No cache file for passed host server */
   PI_CM_NODATAFORPOINT            = -20021,   /* Not data found in cache for point */
   PI_CM_NOTINITIALIZED            = -20022,   /* Cache not initialized */
   PI_CM_NOTSUPPORTED              = -20023,   /* Function not supported */
   PI_CM_POINTNOTFOUND             = -20024,   /* Point not found in cache */
   PI_CM_POINTSOURCEMISMATCH       = -20025,   /* Pointsource in file does not match configuration pointsource */
   PI_CM_SETEXTATTRIBUTES          = -20026,   /* Failed to set extended attributes */
   PI_CM_SYNCHDIGITALSET           = -20027,   /* DigitalSet cache synchronization error */
   PI_CM_SYSTEMERROR               = -20028,   /* System Error (typically communications error) */
   PI_CM_VERSIONMISMATCH           = -20029,   /* Point cache version in file not match code version */
   PI_CM_DUMP_INFILE_NULL          = -20030,   /* Input cache file is not set (NULL) */
   PI_CM_DUMP_OUTFILE_OPEN         = -20031,   /* Unable to open output file because file already open or read only */
   PI_CM_DUMP_OUTFILE_NOCREATE     = -20032,   /* Unable to create output file */
   PI_CM_DUMP_INFILE_INVALIDNAME   = -20033,   /* Input file does not contain a valid cache file name */
   PI_CM_DUMP_INFILE_POINTLIST     = -20034,   /* Unable to retrieve point list from point cache file */
   PI_CM_LAST                      = -20099
} CACHEERROR;

typedef enum eSYNCHTYPE /* 09-Sep-2010 DPR> PLI#20322OSI8. Require API version 1.6.8.3 or later */
{
   SYNCH_NONE,			          /* No cache synchronization. No updates made available*/
   SYNCH_USE_PIPT_UPDATES,       /* Point synchronization with cache. Updates available via pipt_updates. */
   SYNCH_USE_PICM_UPDATES, 	  /* Point synchronization with cache. Updates available via picm_serverupdates. */
   SYNCH_CACHE_ONLY              /* Point synchronization with cache only. No updates made available*/
} SYNCHTYPE;


typedef enum eCACHEINITOPTIONS
{
   CACHE_OPEN,                   /* Open existing cache only. Return error if cache does not exist or is invalid. */
   CACHE_OPEN_CREATE,            /* Open existing cache. Create if cache does not exist or is invalid. */
   CACHE_RENAME_CREATE,          /* Rename existing cache if one exists. Create new cache. */
   CACHE_DELETE_CREATE,          /* Delete existing cache if one exists. Create new cache. */
   CACHE_RENAME_INCOMPLETE,      /* Rename and create new if cache is incomplete. Create new if not exists or is invalid. */
   CACHE_DELETE_INCOMPLETE       /* Delete and create new if cache is incomplete. Create new if not exists or is invalid. */
} CACHEINITOPTION;

typedef enum eCACHESTATES
{
   CACHE_NEW,                    /* New cache file was created. Required connection to PI Server. */
   CACHE_COMPLETE,               /* Cache file found valid and marked complete. */
   CACHE_INCOMPLETE,             /* Cache file found valid, but not marked as complete. */
   CACHE_ERROR                   /* Cache error. No cache available. */
} CACHESTATE;

struct SCacheConfig    /* 09-Sep-2010 DPR> PLI#20322OSI8. Require API version 1.6.8.3 or later */
{
   char            m_szFilepath[1024];         /* Path where cache files are to be located. Directory must exist. */
   char            m_szExecutableName[1024];   /* Executable name (no .exe suffix). */
   char            m_szHostnameAndPort[1024];  /* Hostname:Port. The :Port is optional. */
   char            m_szId[1024];               /* Numerical Id. */
   char            m_szProcessName[1024];      /* Process name. */
   char*           m_aPointSources[100];       /* Pointer(s) to point sources to be caches. User manage memory allocation. */
   SYNCHTYPE       m_eSynchType;               /* Syncrhonization type. */
   CACHEINITOPTION m_eInitOption;              /* Initialization type. */
   pibool          m_bNoDigitalStateStrings;   /* No digital state string values cached. */
};

struct SPointRecord
{
   int32   m_arrLocation[5];

   char    m_cPointType;

   float   m_fConvers;
   float   m_fTypicalvalue;
   float   m_fSpan;
   float   m_fUserReal1;
   float   m_fUserReal2;
   float   m_fZero;

   short   m_nArchiving;
   int32   m_nChangeDate;
   short   m_nCompDev;
   int32   m_nCompMax;
   int32   m_nCompMin;
   short   m_nCompressing;
   int32   m_nCreationDate;
   short   m_nDisplayDigits;
   short   m_nEngUnits;
   short   m_nExcDev;
   short   m_nExcMax;
   short   m_nExcMin;
   short   m_nFilterCode;
   int32   m_nPointId;
   int32   m_nPointTypeX;
   short   m_nScan;
   int32   m_nSourcePoint;
   short   m_nSquareroot;
   short   m_nTotalCode;
   int32   m_nUserInt1;
   int32   m_nUserInt2;

   char    m_szChanger[8];
   char    m_szCreator[8];
   char    m_szDescriptor[PTATTR_BUFF_LEN+1];
   char    m_szExDesc[PTATTR_BUFF_LEN+1];
   char    m_szInstrumentTag[PTATTR_BUFF_LEN +1];
   char    m_szPointsource[PTATTR_BUFF_LEN + 1];
   char    m_szTagname[PTATTR_BUFF_LEN+1];
};

/* Developer functions */
/* 09-Sep-2010 DPR> PLI#20322OSI8. Require API version 1.6.8.3 or later */
PIINT32 picm_cachedump(char* pszCacheFileIn, char* pszCSVFileOut);
PIINT32 picm_closecache(void);
PIINT32 picm_deletecache(void);
PIINT32 picm_getcachefilename(char* pszPtCache, int32 nPtCacheLen, char* pszDgtlCache, int32 nDgtlCacheLen);
PIINT32 picm_getpointrecord(int32 nPointId, struct SPointRecord* pRecord);
PIBOOL  picm_iscachebuildcomplete(void);
PIBOOL  picm_iscachevalid(pibool* pbPtCacheValid, pibool* pbDgCacheValid);
PIBOOL  picm_isconnectedtoserver(void);
PIINT32 picm_opencache(struct SCacheConfig* pConfig, int32* pnPtCacheState, int32* pnDgCacheState);
PIINT32 picm_pointcount(int32* pnPointCount);
PIINT32 picm_pointlist(int32 pList[], uint32 nListSize, uint32* pnPointCount, pibool bSorted);
PIINT32 picm_removepoint(int32 nPointId);
PIINT32 picm_serverupdates(int32 *pt, char PIPTR *tagname, int32 len, int32 PIPTR *mode);
PIINT32 picm_setcachebuildcomplete(void);
PIINT32 picm_synchronizecache(pibool bRestart);

#ifdef __cplusplus
}
#endif

#endif /*  __PICA_CACHE_H__ */
