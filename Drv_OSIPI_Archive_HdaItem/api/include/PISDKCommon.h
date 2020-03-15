

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for PISDKCommon.idl:
    Oicf, W2, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __PISDKCommon_h__
#define __PISDKCommon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INameResolver_FWD_DEFINED__
#define __INameResolver_FWD_DEFINED__
typedef interface INameResolver INameResolver;

#endif 	/* __INameResolver_FWD_DEFINED__ */


#ifndef __IRefresh_FWD_DEFINED__
#define __IRefresh_FWD_DEFINED__
typedef interface IRefresh IRefresh;

#endif 	/* __IRefresh_FWD_DEFINED__ */


#ifndef __ISlimFast_FWD_DEFINED__
#define __ISlimFast_FWD_DEFINED__
typedef interface ISlimFast ISlimFast;

#endif 	/* __ISlimFast_FWD_DEFINED__ */


#ifndef __ITraverse_FWD_DEFINED__
#define __ITraverse_FWD_DEFINED__
typedef interface ITraverse ITraverse;

#endif 	/* __ITraverse_FWD_DEFINED__ */


#ifndef ___EnumNamedValue_FWD_DEFINED__
#define ___EnumNamedValue_FWD_DEFINED__
typedef interface _EnumNamedValue _EnumNamedValue;

#endif 	/* ___EnumNamedValue_FWD_DEFINED__ */


#ifndef ___NamedValues_FWD_DEFINED__
#define ___NamedValues_FWD_DEFINED__
typedef interface _NamedValues _NamedValues;

#endif 	/* ___NamedValues_FWD_DEFINED__ */


#ifndef __INamedValues2_FWD_DEFINED__
#define __INamedValues2_FWD_DEFINED__
typedef interface INamedValues2 INamedValues2;

#endif 	/* __INamedValues2_FWD_DEFINED__ */


#ifndef __NamedValue_FWD_DEFINED__
#define __NamedValue_FWD_DEFINED__
typedef interface NamedValue NamedValue;

#endif 	/* __NamedValue_FWD_DEFINED__ */


#ifndef __INamedValue2_FWD_DEFINED__
#define __INamedValue2_FWD_DEFINED__
typedef interface INamedValue2 INamedValue2;

#endif 	/* __INamedValue2_FWD_DEFINED__ */


#ifndef ___EnumMTNV_FWD_DEFINED__
#define ___EnumMTNV_FWD_DEFINED__
typedef interface _EnumMTNV _EnumMTNV;

#endif 	/* ___EnumMTNV_FWD_DEFINED__ */


#ifndef ___MTNVS_FWD_DEFINED__
#define ___MTNVS_FWD_DEFINED__
typedef interface _MTNVS _MTNVS;

#endif 	/* ___MTNVS_FWD_DEFINED__ */


#ifndef ___MTNV_FWD_DEFINED__
#define ___MTNV_FWD_DEFINED__
typedef interface _MTNV _MTNV;

#endif 	/* ___MTNV_FWD_DEFINED__ */


#ifndef ___PIErrors_FWD_DEFINED__
#define ___PIErrors_FWD_DEFINED__
typedef interface _PIErrors _PIErrors;

#endif 	/* ___PIErrors_FWD_DEFINED__ */


#ifndef ___PIError_FWD_DEFINED__
#define ___PIError_FWD_DEFINED__
typedef interface _PIError _PIError;

#endif 	/* ___PIError_FWD_DEFINED__ */


#ifndef ___PIAsynchStatus_FWD_DEFINED__
#define ___PIAsynchStatus_FWD_DEFINED__
typedef interface _PIAsynchStatus _PIAsynchStatus;

#endif 	/* ___PIAsynchStatus_FWD_DEFINED__ */


#ifndef __IPIAsynchStatus2_FWD_DEFINED__
#define __IPIAsynchStatus2_FWD_DEFINED__
typedef interface IPIAsynchStatus2 IPIAsynchStatus2;

#endif 	/* __IPIAsynchStatus2_FWD_DEFINED__ */


#ifndef __IPIAsynchStatus3_FWD_DEFINED__
#define __IPIAsynchStatus3_FWD_DEFINED__
typedef interface IPIAsynchStatus3 IPIAsynchStatus3;

#endif 	/* __IPIAsynchStatus3_FWD_DEFINED__ */


#ifndef __IPIAsynchStatusInt_FWD_DEFINED__
#define __IPIAsynchStatusInt_FWD_DEFINED__
typedef interface IPIAsynchStatusInt IPIAsynchStatusInt;

#endif 	/* __IPIAsynchStatusInt_FWD_DEFINED__ */


#ifndef ___PIGlobalRestorer_FWD_DEFINED__
#define ___PIGlobalRestorer_FWD_DEFINED__
typedef interface _PIGlobalRestorer _PIGlobalRestorer;

#endif 	/* ___PIGlobalRestorer_FWD_DEFINED__ */


#ifndef __NamedValues_FWD_DEFINED__
#define __NamedValues_FWD_DEFINED__

#ifdef __cplusplus
typedef class NamedValues NamedValues;
#else
typedef struct NamedValues NamedValues;
#endif /* __cplusplus */

#endif 	/* __NamedValues_FWD_DEFINED__ */


#ifndef __NamedValue2_FWD_DEFINED__
#define __NamedValue2_FWD_DEFINED__

#ifdef __cplusplus
typedef class NamedValue2 NamedValue2;
#else
typedef struct NamedValue2 NamedValue2;
#endif /* __cplusplus */

#endif 	/* __NamedValue2_FWD_DEFINED__ */


#ifndef __MTNV_FWD_DEFINED__
#define __MTNV_FWD_DEFINED__

#ifdef __cplusplus
typedef class MTNV MTNV;
#else
typedef struct MTNV MTNV;
#endif /* __cplusplus */

#endif 	/* __MTNV_FWD_DEFINED__ */


#ifndef __MTNVS_FWD_DEFINED__
#define __MTNVS_FWD_DEFINED__

#ifdef __cplusplus
typedef class MTNVS MTNVS;
#else
typedef struct MTNVS MTNVS;
#endif /* __cplusplus */

#endif 	/* __MTNVS_FWD_DEFINED__ */


#ifndef __PIErrors_FWD_DEFINED__
#define __PIErrors_FWD_DEFINED__

#ifdef __cplusplus
typedef class PIErrors PIErrors;
#else
typedef struct PIErrors PIErrors;
#endif /* __cplusplus */

#endif 	/* __PIErrors_FWD_DEFINED__ */


#ifndef __PIError_FWD_DEFINED__
#define __PIError_FWD_DEFINED__

#ifdef __cplusplus
typedef class PIError PIError;
#else
typedef struct PIError PIError;
#endif /* __cplusplus */

#endif 	/* __PIError_FWD_DEFINED__ */


#ifndef ___PIAsynchStatusEvents_FWD_DEFINED__
#define ___PIAsynchStatusEvents_FWD_DEFINED__
typedef interface _PIAsynchStatusEvents _PIAsynchStatusEvents;

#endif 	/* ___PIAsynchStatusEvents_FWD_DEFINED__ */


#ifndef __PIAsynchStatus_FWD_DEFINED__
#define __PIAsynchStatus_FWD_DEFINED__

#ifdef __cplusplus
typedef class PIAsynchStatus PIAsynchStatus;
#else
typedef struct PIAsynchStatus PIAsynchStatus;
#endif /* __cplusplus */

#endif 	/* __PIAsynchStatus_FWD_DEFINED__ */


#ifndef __IPIReset_FWD_DEFINED__
#define __IPIReset_FWD_DEFINED__
typedef interface IPIReset IPIReset;

#endif 	/* __IPIReset_FWD_DEFINED__ */


#ifndef __PIGlobalRestorer_FWD_DEFINED__
#define __PIGlobalRestorer_FWD_DEFINED__

#ifdef __cplusplus
typedef class PIGlobalRestorer PIGlobalRestorer;
#else
typedef struct PIGlobalRestorer PIGlobalRestorer;
#endif /* __cplusplus */

#endif 	/* __PIGlobalRestorer_FWD_DEFINED__ */


#ifndef __IPIRestorer_FWD_DEFINED__
#define __IPIRestorer_FWD_DEFINED__
typedef interface IPIRestorer IPIRestorer;

#endif 	/* __IPIRestorer_FWD_DEFINED__ */


#ifndef __IPIPersist_FWD_DEFINED__
#define __IPIPersist_FWD_DEFINED__
typedef interface IPIPersist IPIPersist;

#endif 	/* __IPIPersist_FWD_DEFINED__ */


#ifndef __IPIServers_FWD_DEFINED__
#define __IPIServers_FWD_DEFINED__
typedef interface IPIServers IPIServers;

#endif 	/* __IPIServers_FWD_DEFINED__ */


#ifndef __IRefresh_FWD_DEFINED__
#define __IRefresh_FWD_DEFINED__
typedef interface IRefresh IRefresh;

#endif 	/* __IRefresh_FWD_DEFINED__ */


#ifndef __IRefresh2_FWD_DEFINED__
#define __IRefresh2_FWD_DEFINED__
typedef interface IRefresh2 IRefresh2;

#endif 	/* __IRefresh2_FWD_DEFINED__ */


#ifndef __IPITransaction_FWD_DEFINED__
#define __IPITransaction_FWD_DEFINED__
typedef interface IPITransaction IPITransaction;

#endif 	/* __IPITransaction_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_PISDKCommon_0000_0000 */
/* [local] */ 

#pragma once









extern RPC_IF_HANDLE __MIDL_itf_PISDKCommon_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PISDKCommon_0000_0000_v0_0_s_ifspec;

#ifndef __INameResolver_INTERFACE_DEFINED__
#define __INameResolver_INTERFACE_DEFINED__

/* interface INameResolver */
/* [unique][helpcontext][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_INameResolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("289040A1-599F-11d2-8118-00A0240B7FDC")
    INameResolver : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Resolve( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INameResolverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INameResolver * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INameResolver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INameResolver * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            INameResolver * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *pVal);
        
        END_INTERFACE
    } INameResolverVtbl;

    interface INameResolver
    {
        CONST_VTBL struct INameResolverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INameResolver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INameResolver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INameResolver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INameResolver_Resolve(This,Name,pVal)	\
    ( (This)->lpVtbl -> Resolve(This,Name,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INameResolver_INTERFACE_DEFINED__ */


#ifndef __IRefresh_INTERFACE_DEFINED__
#define __IRefresh_INTERFACE_DEFINED__

/* interface IRefresh */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IRefresh;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8AEB9C1-5227-11d2-BEFA-0060B0290178")
    IRefresh : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRefreshVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRefresh * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRefresh * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRefresh * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IRefresh * This);
        
        END_INTERFACE
    } IRefreshVtbl;

    interface IRefresh
    {
        CONST_VTBL struct IRefreshVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRefresh_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRefresh_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRefresh_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRefresh_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRefresh_INTERFACE_DEFINED__ */


#ifndef __ISlimFast_INTERFACE_DEFINED__
#define __ISlimFast_INTERFACE_DEFINED__

/* interface ISlimFast */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ISlimFast;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE619C61-1793-11d2-80EE-00A0240B7FDC")
    ISlimFast : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SlimFast( 
            /* [defaultvalue][in] */ long Reserved = 0) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISlimFastVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISlimFast * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISlimFast * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISlimFast * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SlimFast )( 
            ISlimFast * This,
            /* [defaultvalue][in] */ long Reserved);
        
        END_INTERFACE
    } ISlimFastVtbl;

    interface ISlimFast
    {
        CONST_VTBL struct ISlimFastVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISlimFast_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISlimFast_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISlimFast_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISlimFast_SlimFast(This,Reserved)	\
    ( (This)->lpVtbl -> SlimFast(This,Reserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISlimFast_INTERFACE_DEFINED__ */


#ifndef __ITraverse_INTERFACE_DEFINED__
#define __ITraverse_INTERFACE_DEFINED__

/* interface ITraverse */
/* [unique][helpstring][helpcontext][hidden][local][uuid][object] */ 

typedef /* [helpcontext][helpstring] */ 
enum pitrStyleFlags
    {
        pitrNoOptions	= 0,
        pitrSorted	= 1,
        pitrUnsorted	= 2
    } 	pitrStyleFlags;


EXTERN_C const IID IID_ITraverse;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB1D5986-8A3F-11d2-BD40-00C04F779EB2")
    ITraverse : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Traverse( 
            /* [in] */ void *pCallback,
            /* [defaultvalue][in] */ void *pPassThru = 0,
            /* [defaultvalue][in] */ pitrStyleFlags Style = pitrNoOptions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITraverseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITraverse * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITraverse * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITraverse * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Traverse )( 
            ITraverse * This,
            /* [in] */ void *pCallback,
            /* [defaultvalue][in] */ void *pPassThru,
            /* [defaultvalue][in] */ pitrStyleFlags Style);
        
        END_INTERFACE
    } ITraverseVtbl;

    interface ITraverse
    {
        CONST_VTBL struct ITraverseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITraverse_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITraverse_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITraverse_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITraverse_Traverse(This,pCallback,pPassThru,Style)	\
    ( (This)->lpVtbl -> Traverse(This,pCallback,pPassThru,Style) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITraverse_INTERFACE_DEFINED__ */


#ifndef ___EnumNamedValue_INTERFACE_DEFINED__
#define ___EnumNamedValue_INTERFACE_DEFINED__

/* interface _EnumNamedValue */
/* [unique][oleautomation][hidden][uuid][object] */ 


EXTERN_C const IID IID__EnumNamedValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A5AC971-5D60-11d1-808B-00A0240B7FDC")
    _EnumNamedValue : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [retval][out] */ NamedValue **pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _EnumNamedValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _EnumNamedValue * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _EnumNamedValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _EnumNamedValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            _EnumNamedValue * This,
            /* [retval][out] */ NamedValue **pVal);
        
        END_INTERFACE
    } _EnumNamedValueVtbl;

    interface _EnumNamedValue
    {
        CONST_VTBL struct _EnumNamedValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _EnumNamedValue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _EnumNamedValue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _EnumNamedValue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _EnumNamedValue_Next(This,pVal)	\
    ( (This)->lpVtbl -> Next(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___EnumNamedValue_INTERFACE_DEFINED__ */


#ifndef ___NamedValues_INTERFACE_DEFINED__
#define ___NamedValues_INTERFACE_DEFINED__

/* interface _NamedValues */
/* [unique][helpstring][helpcontext][hidden][nonextensible][dual][uuid][object] */ 

typedef /* [helpcontext][helpstring] */ 
enum pinvRegistryKeyConstants
    {
        pinvHKEY_CLASSES_ROOT	= 0x80000000,
        pinvHKEY_CURRENT_USER	= 0x80000001,
        pinvHKEY_LOCAL_MACHINE	= 0x80000002,
        pinvHKEY_USERS	= 0x80000003,
        pinvHKEY_PERFORMANCE_DATA	= 0x80000004,
        pinvHKEY_CURRENT_CONFIG	= 0x80000005,
        pinvHKEY_DYN_DATA	= 0x80000006
    } 	pinvRegistryKeyConstants;

typedef /* [helpcontext][helpstring] */ 
enum pinvRegistryOptions
    {
        pinvNoOptions	= 0,
        pinvIncludeSubkeys	= 1,
        pinvDoNotCreate	= 2,
        pinvKeyMustNotExist	= 4
    } 	pinvRegistryOptions;

typedef /* [helpcontext][helpstring] */ 
enum pinvStyleConstants
    {
        pinvCaseSensitive	= 1,
        pinvLocaleSensitive	= 2,
        pinvAllowLeadingSpace	= 4,
        pinvAllowTrailingSpace	= 8
    } 	pinvStyleConstants;


EXTERN_C const IID IID__NamedValues;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("010F0970-5A49-11D1-8088-00A0240B7FDC")
    _NamedValues : public IDispatch
    {
    public:
        virtual /* [helpstring][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ LPUNKNOWN *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT *Index,
            /* [retval][out] */ NamedValue **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT *Value,
            /* [retval][out] */ NamedValue **pval) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ NamedValue *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates,
            /* [retval][out] */ NamedValue **pval) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ _NamedValues *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates = -1) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__MemberEnum( 
            /* [retval][out] */ _EnumNamedValue **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ long NewSize) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE LoadFromString( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE DumpToString( 
            /* [retval][out] */ BSTR *pStr) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE Freeze( void) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE LoadFromRegistry( 
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt = pinvNoOptions) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE DumpToRegistry( 
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt = pinvNoOptions) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_Style( 
            /* [retval][out] */ pinvStyleConstants *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_Style( 
            /* [in] */ pinvStyleConstants newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sorted( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sorted( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _NamedValuesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _NamedValues * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _NamedValues * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _NamedValues * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _NamedValues * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _NamedValues * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _NamedValues * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _NamedValues * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            _NamedValues * This,
            /* [retval][out] */ LPUNKNOWN *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            _NamedValues * This,
            /* [in] */ VARIANT *Index,
            /* [retval][out] */ NamedValue **pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            _NamedValues * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            _NamedValues * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT *Value,
            /* [retval][out] */ NamedValue **pval);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            _NamedValues * This,
            /* [in] */ NamedValue *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates,
            /* [retval][out] */ NamedValue **pval);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Merge )( 
            _NamedValues * This,
            /* [in] */ _NamedValues *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MemberEnum )( 
            _NamedValues * This,
            /* [retval][out] */ _EnumNamedValue **pVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            _NamedValues * This,
            /* [in] */ long NewSize);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromString )( 
            _NamedValues * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *DumpToString )( 
            _NamedValues * This,
            /* [retval][out] */ BSTR *pStr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            _NamedValues * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            _NamedValues * This);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromRegistry )( 
            _NamedValues * This,
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *DumpToRegistry )( 
            _NamedValues * This,
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt);
        
        /* [helpstring][helpcontext][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            _NamedValues * This,
            /* [retval][out] */ pinvStyleConstants *pVal);
        
        /* [helpstring][helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Style )( 
            _NamedValues * This,
            /* [in] */ pinvStyleConstants newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sorted )( 
            _NamedValues * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sorted )( 
            _NamedValues * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } _NamedValuesVtbl;

    interface _NamedValues
    {
        CONST_VTBL struct _NamedValuesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _NamedValues_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _NamedValues_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _NamedValues_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _NamedValues_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _NamedValues_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _NamedValues_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _NamedValues_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _NamedValues_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define _NamedValues_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define _NamedValues_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define _NamedValues_Add(This,Name,Value,pval)	\
    ( (This)->lpVtbl -> Add(This,Name,Value,pval) ) 

#define _NamedValues_Copy(This,pnvSource,ReplaceDuplicates,pval)	\
    ( (This)->lpVtbl -> Copy(This,pnvSource,ReplaceDuplicates,pval) ) 

#define _NamedValues_Merge(This,pnvSource,ReplaceDuplicates)	\
    ( (This)->lpVtbl -> Merge(This,pnvSource,ReplaceDuplicates) ) 

#define _NamedValues_get__MemberEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__MemberEnum(This,pVal) ) 

#define _NamedValues_SetSize(This,NewSize)	\
    ( (This)->lpVtbl -> SetSize(This,NewSize) ) 

#define _NamedValues_LoadFromString(This,str)	\
    ( (This)->lpVtbl -> LoadFromString(This,str) ) 

#define _NamedValues_DumpToString(This,pStr)	\
    ( (This)->lpVtbl -> DumpToString(This,pStr) ) 

#define _NamedValues_get_ReadOnly(This,pVal)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,pVal) ) 

#define _NamedValues_Freeze(This)	\
    ( (This)->lpVtbl -> Freeze(This) ) 

#define _NamedValues_LoadFromRegistry(This,RootKey,SubKey,Opt)	\
    ( (This)->lpVtbl -> LoadFromRegistry(This,RootKey,SubKey,Opt) ) 

#define _NamedValues_DumpToRegistry(This,RootKey,SubKey,Opt)	\
    ( (This)->lpVtbl -> DumpToRegistry(This,RootKey,SubKey,Opt) ) 

#define _NamedValues_get_Style(This,pVal)	\
    ( (This)->lpVtbl -> get_Style(This,pVal) ) 

#define _NamedValues_put_Style(This,newVal)	\
    ( (This)->lpVtbl -> put_Style(This,newVal) ) 

#define _NamedValues_get_Sorted(This,pVal)	\
    ( (This)->lpVtbl -> get_Sorted(This,pVal) ) 

#define _NamedValues_put_Sorted(This,newVal)	\
    ( (This)->lpVtbl -> put_Sorted(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___NamedValues_INTERFACE_DEFINED__ */


#ifndef __INamedValues2_INTERFACE_DEFINED__
#define __INamedValues2_INTERFACE_DEFINED__

/* interface INamedValues2 */
/* [unique][helpcontext][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INamedValues2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5546F22-EF21-11d3-BDC7-00C04F779EB2")
    INamedValues2 : public _NamedValues
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR OldName,
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ INamedValues2 **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ NamedValue *toInsert) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INamedValues2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INamedValues2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INamedValues2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INamedValues2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INamedValues2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INamedValues2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INamedValues2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INamedValues2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INamedValues2 * This,
            /* [retval][out] */ LPUNKNOWN *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            INamedValues2 * This,
            /* [in] */ VARIANT *Index,
            /* [retval][out] */ NamedValue **pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INamedValues2 * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            INamedValues2 * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT *Value,
            /* [retval][out] */ NamedValue **pval);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            INamedValues2 * This,
            /* [in] */ NamedValue *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates,
            /* [retval][out] */ NamedValue **pval);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Merge )( 
            INamedValues2 * This,
            /* [in] */ _NamedValues *pnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL ReplaceDuplicates);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MemberEnum )( 
            INamedValues2 * This,
            /* [retval][out] */ _EnumNamedValue **pVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            INamedValues2 * This,
            /* [in] */ long NewSize);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromString )( 
            INamedValues2 * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *DumpToString )( 
            INamedValues2 * This,
            /* [retval][out] */ BSTR *pStr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            INamedValues2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            INamedValues2 * This);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromRegistry )( 
            INamedValues2 * This,
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *DumpToRegistry )( 
            INamedValues2 * This,
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt);
        
        /* [helpstring][helpcontext][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Style )( 
            INamedValues2 * This,
            /* [retval][out] */ pinvStyleConstants *pVal);
        
        /* [helpstring][helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Style )( 
            INamedValues2 * This,
            /* [in] */ pinvStyleConstants newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sorted )( 
            INamedValues2 * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sorted )( 
            INamedValues2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            INamedValues2 * This,
            /* [in] */ BSTR OldName,
            /* [in] */ BSTR NewName);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            INamedValues2 * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            INamedValues2 * This);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            INamedValues2 * This,
            /* [retval][out] */ INamedValues2 **pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Insert )( 
            INamedValues2 * This,
            /* [in] */ NamedValue *toInsert);
        
        END_INTERFACE
    } INamedValues2Vtbl;

    interface INamedValues2
    {
        CONST_VTBL struct INamedValues2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INamedValues2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INamedValues2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INamedValues2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INamedValues2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INamedValues2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INamedValues2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INamedValues2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INamedValues2_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define INamedValues2_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define INamedValues2_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define INamedValues2_Add(This,Name,Value,pval)	\
    ( (This)->lpVtbl -> Add(This,Name,Value,pval) ) 

#define INamedValues2_Copy(This,pnvSource,ReplaceDuplicates,pval)	\
    ( (This)->lpVtbl -> Copy(This,pnvSource,ReplaceDuplicates,pval) ) 

#define INamedValues2_Merge(This,pnvSource,ReplaceDuplicates)	\
    ( (This)->lpVtbl -> Merge(This,pnvSource,ReplaceDuplicates) ) 

#define INamedValues2_get__MemberEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__MemberEnum(This,pVal) ) 

#define INamedValues2_SetSize(This,NewSize)	\
    ( (This)->lpVtbl -> SetSize(This,NewSize) ) 

#define INamedValues2_LoadFromString(This,str)	\
    ( (This)->lpVtbl -> LoadFromString(This,str) ) 

#define INamedValues2_DumpToString(This,pStr)	\
    ( (This)->lpVtbl -> DumpToString(This,pStr) ) 

#define INamedValues2_get_ReadOnly(This,pVal)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,pVal) ) 

#define INamedValues2_Freeze(This)	\
    ( (This)->lpVtbl -> Freeze(This) ) 

#define INamedValues2_LoadFromRegistry(This,RootKey,SubKey,Opt)	\
    ( (This)->lpVtbl -> LoadFromRegistry(This,RootKey,SubKey,Opt) ) 

#define INamedValues2_DumpToRegistry(This,RootKey,SubKey,Opt)	\
    ( (This)->lpVtbl -> DumpToRegistry(This,RootKey,SubKey,Opt) ) 

#define INamedValues2_get_Style(This,pVal)	\
    ( (This)->lpVtbl -> get_Style(This,pVal) ) 

#define INamedValues2_put_Style(This,newVal)	\
    ( (This)->lpVtbl -> put_Style(This,newVal) ) 

#define INamedValues2_get_Sorted(This,pVal)	\
    ( (This)->lpVtbl -> get_Sorted(This,pVal) ) 

#define INamedValues2_put_Sorted(This,newVal)	\
    ( (This)->lpVtbl -> put_Sorted(This,newVal) ) 


#define INamedValues2_Rename(This,OldName,NewName)	\
    ( (This)->lpVtbl -> Rename(This,OldName,NewName) ) 

#define INamedValues2_Remove(This,Name)	\
    ( (This)->lpVtbl -> Remove(This,Name) ) 

#define INamedValues2_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define INamedValues2_Clone(This,pVal)	\
    ( (This)->lpVtbl -> Clone(This,pVal) ) 

#define INamedValues2_Insert(This,toInsert)	\
    ( (This)->lpVtbl -> Insert(This,toInsert) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INamedValues2_INTERFACE_DEFINED__ */


#ifndef __NamedValue_INTERFACE_DEFINED__
#define __NamedValue_INTERFACE_DEFINED__

/* interface NamedValue */
/* [unique][helpcontext][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_NamedValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("444DBB11-5A50-11d1-8088-00A0240B7FDC")
    NamedValue : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ _NamedValues **pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct NamedValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            NamedValue * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            NamedValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            NamedValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            NamedValue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            NamedValue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            NamedValue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            NamedValue * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            NamedValue * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            NamedValue * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            NamedValue * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            NamedValue * This,
            /* [retval][out] */ _NamedValues **pVal);
        
        END_INTERFACE
    } NamedValueVtbl;

    interface NamedValue
    {
        CONST_VTBL struct NamedValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define NamedValue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define NamedValue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define NamedValue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define NamedValue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define NamedValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define NamedValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define NamedValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define NamedValue_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define NamedValue_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define NamedValue_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define NamedValue_get_Parent(This,pVal)	\
    ( (This)->lpVtbl -> get_Parent(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __NamedValue_INTERFACE_DEFINED__ */


#ifndef __INamedValue2_INTERFACE_DEFINED__
#define __INamedValue2_INTERFACE_DEFINED__

/* interface INamedValue2 */
/* [unique][helpcontext][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INamedValue2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5546F21-EF21-11d3-BDC7-00C04F779EB2")
    INamedValue2 : public NamedValue
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Detach( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INamedValue2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INamedValue2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INamedValue2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INamedValue2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INamedValue2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INamedValue2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INamedValue2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INamedValue2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INamedValue2 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            INamedValue2 * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            INamedValue2 * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            INamedValue2 * This,
            /* [retval][out] */ _NamedValues **pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            INamedValue2 * This,
            /* [in] */ BSTR NewName);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Detach )( 
            INamedValue2 * This);
        
        END_INTERFACE
    } INamedValue2Vtbl;

    interface INamedValue2
    {
        CONST_VTBL struct INamedValue2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INamedValue2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INamedValue2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INamedValue2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INamedValue2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INamedValue2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INamedValue2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INamedValue2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INamedValue2_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define INamedValue2_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define INamedValue2_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define INamedValue2_get_Parent(This,pVal)	\
    ( (This)->lpVtbl -> get_Parent(This,pVal) ) 


#define INamedValue2_Rename(This,NewName)	\
    ( (This)->lpVtbl -> Rename(This,NewName) ) 

#define INamedValue2_Detach(This)	\
    ( (This)->lpVtbl -> Detach(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INamedValue2_INTERFACE_DEFINED__ */


#ifndef ___EnumMTNV_INTERFACE_DEFINED__
#define ___EnumMTNV_INTERFACE_DEFINED__

/* interface _EnumMTNV */
/* [unique][oleautomation][hidden][uuid][object] */ 


EXTERN_C const IID IID__EnumMTNV;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6555F7F0-036A-4df5-8378-2A042BA80665")
    _EnumMTNV : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MTNext( 
            /* [retval][out] */ _MTNV **hVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _EnumMTNVVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _EnumMTNV * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _EnumMTNV * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _EnumMTNV * This);
        
        HRESULT ( STDMETHODCALLTYPE *MTNext )( 
            _EnumMTNV * This,
            /* [retval][out] */ _MTNV **hVal);
        
        END_INTERFACE
    } _EnumMTNVVtbl;

    interface _EnumMTNV
    {
        CONST_VTBL struct _EnumMTNVVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _EnumMTNV_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _EnumMTNV_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _EnumMTNV_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _EnumMTNV_MTNext(This,hVal)	\
    ( (This)->lpVtbl -> MTNext(This,hVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___EnumMTNV_INTERFACE_DEFINED__ */


#ifndef ___MTNVS_INTERFACE_DEFINED__
#define ___MTNVS_INTERFACE_DEFINED__

/* interface _MTNVS */
/* [unique][helpcontext][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID__MTNVS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF4A4267-5948-4C1E-944B-1B4408009B0E")
    _MTNVS : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_NVS( 
            /* [retval][out] */ _NamedValues **hNVS) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_INVS2( 
            /* [retval][out] */ INamedValues2 **hINVS2) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTItem( 
            /* [in] */ VARIANT *index,
            /* [retval][out] */ _MTNV **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTAdd( 
            /* [in] */ BSTR name,
            /* [in] */ VARIANT *value,
            /* [retval][out] */ _MTNV **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTCopy( 
            /* [in] */ _MTNV *pmtnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL replaceDuplicates,
            /* [retval][out] */ _MTNV **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTMerge( 
            /* [in] */ _MTNVS *pmtnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL replaceDuplicates = -1) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__MTMemberEnum( 
            /* [retval][out] */ _EnumMTNV **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE MTSetSize( 
            /* [in] */ long newSize) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTLoadFromString( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTDumpToString( 
            /* [retval][out] */ BSTR *pStr) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE MTFreeze( void) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTLoadFromRegistry( 
            /* [in] */ pinvRegistryKeyConstants rootKey,
            /* [in] */ BSTR subKey,
            /* [defaultvalue][in] */ pinvRegistryOptions opt = pinvNoOptions) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE MTDumpToRegistry( 
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt = pinvNoOptions) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTStyle( 
            /* [retval][out] */ pinvStyleConstants *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_MTStyle( 
            /* [in] */ pinvStyleConstants newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTSorted( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_MTSorted( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTRename( 
            /* [in] */ BSTR oldName,
            /* [in] */ BSTR newName) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTRemove( 
            /* [in] */ BSTR name) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTClear( void) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTClone( 
            /* [retval][out] */ _MTNVS **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTInsert( 
            /* [in] */ _MTNV *toInsert) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _MTNVSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _MTNVS * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _MTNVS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _MTNVS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _MTNVS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _MTNVS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _MTNVS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _MTNVS * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NVS )( 
            _MTNVS * This,
            /* [retval][out] */ _NamedValues **hNVS);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_INVS2 )( 
            _MTNVS * This,
            /* [retval][out] */ INamedValues2 **hINVS2);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTItem )( 
            _MTNVS * This,
            /* [in] */ VARIANT *index,
            /* [retval][out] */ _MTNV **hVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTCount )( 
            _MTNVS * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTAdd )( 
            _MTNVS * This,
            /* [in] */ BSTR name,
            /* [in] */ VARIANT *value,
            /* [retval][out] */ _MTNV **hVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTCopy )( 
            _MTNVS * This,
            /* [in] */ _MTNV *pmtnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL replaceDuplicates,
            /* [retval][out] */ _MTNV **hVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTMerge )( 
            _MTNVS * This,
            /* [in] */ _MTNVS *pmtnvSource,
            /* [defaultvalue][in] */ VARIANT_BOOL replaceDuplicates);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MTMemberEnum )( 
            _MTNVS * This,
            /* [retval][out] */ _EnumMTNV **hVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *MTSetSize )( 
            _MTNVS * This,
            /* [in] */ long newSize);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTLoadFromString )( 
            _MTNVS * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTDumpToString )( 
            _MTNVS * This,
            /* [retval][out] */ BSTR *pStr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTReadOnly )( 
            _MTNVS * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *MTFreeze )( 
            _MTNVS * This);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTLoadFromRegistry )( 
            _MTNVS * This,
            /* [in] */ pinvRegistryKeyConstants rootKey,
            /* [in] */ BSTR subKey,
            /* [defaultvalue][in] */ pinvRegistryOptions opt);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *MTDumpToRegistry )( 
            _MTNVS * This,
            /* [in] */ pinvRegistryKeyConstants RootKey,
            /* [in] */ BSTR SubKey,
            /* [defaultvalue][in] */ pinvRegistryOptions Opt);
        
        /* [helpstring][helpcontext][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTStyle )( 
            _MTNVS * This,
            /* [retval][out] */ pinvStyleConstants *pVal);
        
        /* [helpstring][helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MTStyle )( 
            _MTNVS * This,
            /* [in] */ pinvStyleConstants newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTSorted )( 
            _MTNVS * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MTSorted )( 
            _MTNVS * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTRename )( 
            _MTNVS * This,
            /* [in] */ BSTR oldName,
            /* [in] */ BSTR newName);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTRemove )( 
            _MTNVS * This,
            /* [in] */ BSTR name);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTClear )( 
            _MTNVS * This);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTClone )( 
            _MTNVS * This,
            /* [retval][out] */ _MTNVS **hVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTInsert )( 
            _MTNVS * This,
            /* [in] */ _MTNV *toInsert);
        
        END_INTERFACE
    } _MTNVSVtbl;

    interface _MTNVS
    {
        CONST_VTBL struct _MTNVSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _MTNVS_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _MTNVS_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _MTNVS_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _MTNVS_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _MTNVS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _MTNVS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _MTNVS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _MTNVS_get_NVS(This,hNVS)	\
    ( (This)->lpVtbl -> get_NVS(This,hNVS) ) 

#define _MTNVS_get_INVS2(This,hINVS2)	\
    ( (This)->lpVtbl -> get_INVS2(This,hINVS2) ) 

#define _MTNVS_get_MTItem(This,index,hVal)	\
    ( (This)->lpVtbl -> get_MTItem(This,index,hVal) ) 

#define _MTNVS_get_MTCount(This,pVal)	\
    ( (This)->lpVtbl -> get_MTCount(This,pVal) ) 

#define _MTNVS_MTAdd(This,name,value,hVal)	\
    ( (This)->lpVtbl -> MTAdd(This,name,value,hVal) ) 

#define _MTNVS_MTCopy(This,pmtnvSource,replaceDuplicates,hVal)	\
    ( (This)->lpVtbl -> MTCopy(This,pmtnvSource,replaceDuplicates,hVal) ) 

#define _MTNVS_MTMerge(This,pmtnvSource,replaceDuplicates)	\
    ( (This)->lpVtbl -> MTMerge(This,pmtnvSource,replaceDuplicates) ) 

#define _MTNVS_get__MTMemberEnum(This,hVal)	\
    ( (This)->lpVtbl -> get__MTMemberEnum(This,hVal) ) 

#define _MTNVS_MTSetSize(This,newSize)	\
    ( (This)->lpVtbl -> MTSetSize(This,newSize) ) 

#define _MTNVS_MTLoadFromString(This,str)	\
    ( (This)->lpVtbl -> MTLoadFromString(This,str) ) 

#define _MTNVS_MTDumpToString(This,pStr)	\
    ( (This)->lpVtbl -> MTDumpToString(This,pStr) ) 

#define _MTNVS_get_MTReadOnly(This,pVal)	\
    ( (This)->lpVtbl -> get_MTReadOnly(This,pVal) ) 

#define _MTNVS_MTFreeze(This)	\
    ( (This)->lpVtbl -> MTFreeze(This) ) 

#define _MTNVS_MTLoadFromRegistry(This,rootKey,subKey,opt)	\
    ( (This)->lpVtbl -> MTLoadFromRegistry(This,rootKey,subKey,opt) ) 

#define _MTNVS_MTDumpToRegistry(This,RootKey,SubKey,Opt)	\
    ( (This)->lpVtbl -> MTDumpToRegistry(This,RootKey,SubKey,Opt) ) 

#define _MTNVS_get_MTStyle(This,pVal)	\
    ( (This)->lpVtbl -> get_MTStyle(This,pVal) ) 

#define _MTNVS_put_MTStyle(This,newVal)	\
    ( (This)->lpVtbl -> put_MTStyle(This,newVal) ) 

#define _MTNVS_get_MTSorted(This,pVal)	\
    ( (This)->lpVtbl -> get_MTSorted(This,pVal) ) 

#define _MTNVS_put_MTSorted(This,newVal)	\
    ( (This)->lpVtbl -> put_MTSorted(This,newVal) ) 

#define _MTNVS_MTRename(This,oldName,newName)	\
    ( (This)->lpVtbl -> MTRename(This,oldName,newName) ) 

#define _MTNVS_MTRemove(This,name)	\
    ( (This)->lpVtbl -> MTRemove(This,name) ) 

#define _MTNVS_MTClear(This)	\
    ( (This)->lpVtbl -> MTClear(This) ) 

#define _MTNVS_MTClone(This,hVal)	\
    ( (This)->lpVtbl -> MTClone(This,hVal) ) 

#define _MTNVS_MTInsert(This,toInsert)	\
    ( (This)->lpVtbl -> MTInsert(This,toInsert) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___MTNVS_INTERFACE_DEFINED__ */


#ifndef ___MTNV_INTERFACE_DEFINED__
#define ___MTNV_INTERFACE_DEFINED__

/* interface _MTNV */
/* [unique][helpcontext][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID__MTNV;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("85681420-C2E8-4765-ADCD-56B40CE2A5F1")
    _MTNV : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_NV( 
            /* [retval][out] */ NamedValue **hNV) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_INV2( 
            /* [retval][out] */ INamedValue2 **hNV2) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTValue( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_MTValue( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_MTParent( 
            /* [retval][out] */ _MTNVS **hVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTRename( 
            /* [in] */ BSTR newName) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE MTDetach( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _MTNVVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _MTNV * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _MTNV * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _MTNV * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _MTNV * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _MTNV * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _MTNV * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _MTNV * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NV )( 
            _MTNV * This,
            /* [retval][out] */ NamedValue **hNV);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_INV2 )( 
            _MTNV * This,
            /* [retval][out] */ INamedValue2 **hNV2);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTName )( 
            _MTNV * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTValue )( 
            _MTNV * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MTValue )( 
            _MTNV * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MTParent )( 
            _MTNV * This,
            /* [retval][out] */ _MTNVS **hVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTRename )( 
            _MTNV * This,
            /* [in] */ BSTR newName);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *MTDetach )( 
            _MTNV * This);
        
        END_INTERFACE
    } _MTNVVtbl;

    interface _MTNV
    {
        CONST_VTBL struct _MTNVVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _MTNV_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _MTNV_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _MTNV_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _MTNV_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _MTNV_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _MTNV_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _MTNV_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _MTNV_get_NV(This,hNV)	\
    ( (This)->lpVtbl -> get_NV(This,hNV) ) 

#define _MTNV_get_INV2(This,hNV2)	\
    ( (This)->lpVtbl -> get_INV2(This,hNV2) ) 

#define _MTNV_get_MTName(This,pVal)	\
    ( (This)->lpVtbl -> get_MTName(This,pVal) ) 

#define _MTNV_get_MTValue(This,pVal)	\
    ( (This)->lpVtbl -> get_MTValue(This,pVal) ) 

#define _MTNV_put_MTValue(This,newVal)	\
    ( (This)->lpVtbl -> put_MTValue(This,newVal) ) 

#define _MTNV_get_MTParent(This,hVal)	\
    ( (This)->lpVtbl -> get_MTParent(This,hVal) ) 

#define _MTNV_MTRename(This,newName)	\
    ( (This)->lpVtbl -> MTRename(This,newName) ) 

#define _MTNV_MTDetach(This)	\
    ( (This)->lpVtbl -> MTDetach(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___MTNV_INTERFACE_DEFINED__ */


#ifndef ___PIErrors_INTERFACE_DEFINED__
#define ___PIErrors_INTERFACE_DEFINED__

/* interface _PIErrors */
/* [unique][helpstring][helpcontext][hidden][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID__PIErrors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21CC3DE6-EF1F-11D3-BDC7-00C04F779EB2")
    _PIErrors : public IDispatch
    {
    public:
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ _PIError **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ long Number,
            /* [in] */ BSTR bstrDescription,
            /* [defaultvalue][in] */ BSTR bstrSource,
            /* [defaultvalue][in] */ BSTR bstrHelpFile,
            /* [defaultvalue][in] */ long helpContext,
            /* [optional][in] */ VARIANT cause,
            /* [retval][out] */ _PIError **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE AddErrorInfo( 
            /* [in] */ long Number,
            /* [defaultvalue][in] */ IUnknown *punkErrInfo,
            /* [optional][in] */ VARIANT Cause,
            /* [retval][out] */ _PIError **pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][hidden][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Freeze( void) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ long NewSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _PIErrorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _PIErrors * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _PIErrors * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _PIErrors * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _PIErrors * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _PIErrors * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _PIErrors * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _PIErrors * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            _PIErrors * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            _PIErrors * This,
            /* [in] */ long Index,
            /* [retval][out] */ _PIError **pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            _PIErrors * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            _PIErrors * This,
            /* [in] */ long Number,
            /* [in] */ BSTR bstrDescription,
            /* [defaultvalue][in] */ BSTR bstrSource,
            /* [defaultvalue][in] */ BSTR bstrHelpFile,
            /* [defaultvalue][in] */ long helpContext,
            /* [optional][in] */ VARIANT cause,
            /* [retval][out] */ _PIError **pVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *AddErrorInfo )( 
            _PIErrors * This,
            /* [in] */ long Number,
            /* [defaultvalue][in] */ IUnknown *punkErrInfo,
            /* [optional][in] */ VARIANT Cause,
            /* [retval][out] */ _PIError **pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            _PIErrors * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][hidden][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Freeze )( 
            _PIErrors * This);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            _PIErrors * This,
            /* [in] */ long NewSize);
        
        END_INTERFACE
    } _PIErrorsVtbl;

    interface _PIErrors
    {
        CONST_VTBL struct _PIErrorsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _PIErrors_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _PIErrors_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _PIErrors_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _PIErrors_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _PIErrors_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _PIErrors_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _PIErrors_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _PIErrors_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define _PIErrors_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define _PIErrors_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define _PIErrors_Add(This,Number,bstrDescription,bstrSource,bstrHelpFile,helpContext,cause,pVal)	\
    ( (This)->lpVtbl -> Add(This,Number,bstrDescription,bstrSource,bstrHelpFile,helpContext,cause,pVal) ) 

#define _PIErrors_AddErrorInfo(This,Number,punkErrInfo,Cause,pVal)	\
    ( (This)->lpVtbl -> AddErrorInfo(This,Number,punkErrInfo,Cause,pVal) ) 

#define _PIErrors_get_ReadOnly(This,pVal)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,pVal) ) 

#define _PIErrors_Freeze(This)	\
    ( (This)->lpVtbl -> Freeze(This) ) 

#define _PIErrors_SetSize(This,NewSize)	\
    ( (This)->lpVtbl -> SetSize(This,NewSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___PIErrors_INTERFACE_DEFINED__ */


#ifndef ___PIError_INTERFACE_DEFINED__
#define ___PIError_INTERFACE_DEFINED__

/* interface _PIError */
/* [unique][helpstring][helpcontext][hidden][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID__PIError;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21CC3DE8-EF1F-11D3-BDC7-00C04F779EB2")
    _PIError : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cause( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpContext( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _PIErrorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _PIError * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _PIError * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _PIError * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _PIError * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _PIError * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _PIError * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _PIError * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Number )( 
            _PIError * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cause )( 
            _PIError * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            _PIError * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpContext )( 
            _PIError * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFile )( 
            _PIError * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Source )( 
            _PIError * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } _PIErrorVtbl;

    interface _PIError
    {
        CONST_VTBL struct _PIErrorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _PIError_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _PIError_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _PIError_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _PIError_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _PIError_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _PIError_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _PIError_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _PIError_get_Number(This,pVal)	\
    ( (This)->lpVtbl -> get_Number(This,pVal) ) 

#define _PIError_get_Cause(This,pVal)	\
    ( (This)->lpVtbl -> get_Cause(This,pVal) ) 

#define _PIError_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define _PIError_get_HelpContext(This,pVal)	\
    ( (This)->lpVtbl -> get_HelpContext(This,pVal) ) 

#define _PIError_get_HelpFile(This,pVal)	\
    ( (This)->lpVtbl -> get_HelpFile(This,pVal) ) 

#define _PIError_get_Source(This,pVal)	\
    ( (This)->lpVtbl -> get_Source(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___PIError_INTERFACE_DEFINED__ */


#ifndef ___PIAsynchStatus_INTERFACE_DEFINED__
#define ___PIAsynchStatus_INTERFACE_DEFINED__

/* interface _PIAsynchStatus */
/* [unique][helpstring][helpcontext][nonextensible][dual][uuid][object] */ 

typedef /* [helpcontext][helpstring] */ 
enum CallStatusConstants
    {
        csInitial	= 0,
        csInProgress	= 1,
        csComplete	= 2,
        csHasErrors	= 4,
        csInProgressWithErrors	= 5,
        csCompleteWithErrors	= 6,
        csCancelFlag	= 8,
        csCancelPending	= 9,
        csCancelComplete	= 10,
        csCancelHasErrors	= 12,
        csCancelCompleteWithErrors	= 14,
        csFailedToComplete	= 16
    } 	CallStatusConstants;


EXTERN_C const IID IID__PIAsynchStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36FC9461-5334-11d2-BEFA-0060B0290178")
    _PIAsynchStatus : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgressPercent( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpcontext][hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgressPercent( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ CallStatusConstants *pVal) = 0;
        
        virtual /* [helpcontext][hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_Status( 
            /* [in] */ CallStatusConstants newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE SetComplete( void) = 0;
        
        virtual /* [helpstring][helpcontext][hidden][id] */ HRESULT STDMETHODCALLTYPE SetErrors( void) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpcontext][hidden][id][propput] */ HRESULT STDMETHODCALLTYPE put_Result( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _PIAsynchStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _PIAsynchStatus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _PIAsynchStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _PIAsynchStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _PIAsynchStatus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _PIAsynchStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _PIAsynchStatus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _PIAsynchStatus * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgressPercent )( 
            _PIAsynchStatus * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProgressPercent )( 
            _PIAsynchStatus * This,
            /* [in] */ double newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            _PIAsynchStatus * This,
            /* [retval][out] */ CallStatusConstants *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Status )( 
            _PIAsynchStatus * This,
            /* [in] */ CallStatusConstants newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            _PIAsynchStatus * This);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetComplete )( 
            _PIAsynchStatus * This);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetErrors )( 
            _PIAsynchStatus * This);
        
        /* [helpcontext][helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            _PIAsynchStatus * This);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Result )( 
            _PIAsynchStatus * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Result )( 
            _PIAsynchStatus * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } _PIAsynchStatusVtbl;

    interface _PIAsynchStatus
    {
        CONST_VTBL struct _PIAsynchStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _PIAsynchStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _PIAsynchStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _PIAsynchStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _PIAsynchStatus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _PIAsynchStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _PIAsynchStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _PIAsynchStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _PIAsynchStatus_get_ProgressPercent(This,pVal)	\
    ( (This)->lpVtbl -> get_ProgressPercent(This,pVal) ) 

#define _PIAsynchStatus_put_ProgressPercent(This,newVal)	\
    ( (This)->lpVtbl -> put_ProgressPercent(This,newVal) ) 

#define _PIAsynchStatus_get_Status(This,pVal)	\
    ( (This)->lpVtbl -> get_Status(This,pVal) ) 

#define _PIAsynchStatus_put_Status(This,newVal)	\
    ( (This)->lpVtbl -> put_Status(This,newVal) ) 

#define _PIAsynchStatus_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define _PIAsynchStatus_SetComplete(This)	\
    ( (This)->lpVtbl -> SetComplete(This) ) 

#define _PIAsynchStatus_SetErrors(This)	\
    ( (This)->lpVtbl -> SetErrors(This) ) 

#define _PIAsynchStatus_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define _PIAsynchStatus_get_Result(This,pVal)	\
    ( (This)->lpVtbl -> get_Result(This,pVal) ) 

#define _PIAsynchStatus_put_Result(This,newVal)	\
    ( (This)->lpVtbl -> put_Result(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___PIAsynchStatus_INTERFACE_DEFINED__ */


#ifndef __IPIAsynchStatus2_INTERFACE_DEFINED__
#define __IPIAsynchStatus2_INTERFACE_DEFINED__

/* interface IPIAsynchStatus2 */
/* [unique][helpstring][helpcontext][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPIAsynchStatus2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECA80073-B652-478a-B191-E87A924EB723")
    IPIAsynchStatus2 : public IUnknown
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallCompleteEvent( 
            /* [retval][out] */ long *pHandle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIAsynchStatus2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIAsynchStatus2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIAsynchStatus2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIAsynchStatus2 * This);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallCompleteEvent )( 
            IPIAsynchStatus2 * This,
            /* [retval][out] */ long *pHandle);
        
        END_INTERFACE
    } IPIAsynchStatus2Vtbl;

    interface IPIAsynchStatus2
    {
        CONST_VTBL struct IPIAsynchStatus2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIAsynchStatus2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIAsynchStatus2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIAsynchStatus2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIAsynchStatus2_get_CallCompleteEvent(This,pHandle)	\
    ( (This)->lpVtbl -> get_CallCompleteEvent(This,pHandle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIAsynchStatus2_INTERFACE_DEFINED__ */


#ifndef __IPIAsynchStatus3_INTERFACE_DEFINED__
#define __IPIAsynchStatus3_INTERFACE_DEFINED__

/* interface IPIAsynchStatus3 */
/* [unique][helpstring][helpcontext][nonextensible][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IPIAsynchStatus3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0F59452F-829A-4b99-86E7-941C629EDCA6")
    IPIAsynchStatus3 : public _PIAsynchStatus
    {
    public:
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Timeout( 
            /* [in] */ long seconds) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Timeout( 
            /* [retval][out] */ long *pSeconds) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_CallCompleteEvent2( 
            /* [retval][out] */ HANDLE_PTR *pHandle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIAsynchStatus3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIAsynchStatus3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIAsynchStatus3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIAsynchStatus3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPIAsynchStatus3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPIAsynchStatus3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPIAsynchStatus3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPIAsynchStatus3 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgressPercent )( 
            IPIAsynchStatus3 * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProgressPercent )( 
            IPIAsynchStatus3 * This,
            /* [in] */ double newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IPIAsynchStatus3 * This,
            /* [retval][out] */ CallStatusConstants *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Status )( 
            IPIAsynchStatus3 * This,
            /* [in] */ CallStatusConstants newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPIAsynchStatus3 * This);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetComplete )( 
            IPIAsynchStatus3 * This);
        
        /* [helpstring][helpcontext][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SetErrors )( 
            IPIAsynchStatus3 * This);
        
        /* [helpcontext][helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IPIAsynchStatus3 * This);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Result )( 
            IPIAsynchStatus3 * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpcontext][hidden][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Result )( 
            IPIAsynchStatus3 * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Timeout )( 
            IPIAsynchStatus3 * This,
            /* [in] */ long seconds);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Timeout )( 
            IPIAsynchStatus3 * This,
            /* [retval][out] */ long *pSeconds);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CallCompleteEvent2 )( 
            IPIAsynchStatus3 * This,
            /* [retval][out] */ HANDLE_PTR *pHandle);
        
        END_INTERFACE
    } IPIAsynchStatus3Vtbl;

    interface IPIAsynchStatus3
    {
        CONST_VTBL struct IPIAsynchStatus3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIAsynchStatus3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIAsynchStatus3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIAsynchStatus3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIAsynchStatus3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPIAsynchStatus3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPIAsynchStatus3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPIAsynchStatus3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPIAsynchStatus3_get_ProgressPercent(This,pVal)	\
    ( (This)->lpVtbl -> get_ProgressPercent(This,pVal) ) 

#define IPIAsynchStatus3_put_ProgressPercent(This,newVal)	\
    ( (This)->lpVtbl -> put_ProgressPercent(This,newVal) ) 

#define IPIAsynchStatus3_get_Status(This,pVal)	\
    ( (This)->lpVtbl -> get_Status(This,pVal) ) 

#define IPIAsynchStatus3_put_Status(This,newVal)	\
    ( (This)->lpVtbl -> put_Status(This,newVal) ) 

#define IPIAsynchStatus3_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPIAsynchStatus3_SetComplete(This)	\
    ( (This)->lpVtbl -> SetComplete(This) ) 

#define IPIAsynchStatus3_SetErrors(This)	\
    ( (This)->lpVtbl -> SetErrors(This) ) 

#define IPIAsynchStatus3_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IPIAsynchStatus3_get_Result(This,pVal)	\
    ( (This)->lpVtbl -> get_Result(This,pVal) ) 

#define IPIAsynchStatus3_put_Result(This,newVal)	\
    ( (This)->lpVtbl -> put_Result(This,newVal) ) 


#define IPIAsynchStatus3_put_Timeout(This,seconds)	\
    ( (This)->lpVtbl -> put_Timeout(This,seconds) ) 

#define IPIAsynchStatus3_get_Timeout(This,pSeconds)	\
    ( (This)->lpVtbl -> get_Timeout(This,pSeconds) ) 

#define IPIAsynchStatus3_get_CallCompleteEvent2(This,pHandle)	\
    ( (This)->lpVtbl -> get_CallCompleteEvent2(This,pHandle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIAsynchStatus3_INTERFACE_DEFINED__ */


#ifndef __IPIAsynchStatusInt_INTERFACE_DEFINED__
#define __IPIAsynchStatusInt_INTERFACE_DEFINED__

/* interface IPIAsynchStatusInt */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPIAsynchStatusInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B60B668-4AAC-489a-BB5F-39B1EEEE7CEA")
    IPIAsynchStatusInt : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NextAsynchItem( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NextAsynchItem( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InternalReturnItem( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_InternalReturnItem( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachInternalResult( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreatorThreadID( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIAsynchStatusIntVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIAsynchStatusInt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIAsynchStatusInt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIAsynchStatusInt * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NextAsynchItem )( 
            IPIAsynchStatusInt * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NextAsynchItem )( 
            IPIAsynchStatusInt * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InternalReturnItem )( 
            IPIAsynchStatusInt * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_InternalReturnItem )( 
            IPIAsynchStatusInt * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachInternalResult )( 
            IPIAsynchStatusInt * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreatorThreadID )( 
            IPIAsynchStatusInt * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IPIAsynchStatusIntVtbl;

    interface IPIAsynchStatusInt
    {
        CONST_VTBL struct IPIAsynchStatusIntVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIAsynchStatusInt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIAsynchStatusInt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIAsynchStatusInt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIAsynchStatusInt_get_NextAsynchItem(This,pVal)	\
    ( (This)->lpVtbl -> get_NextAsynchItem(This,pVal) ) 

#define IPIAsynchStatusInt_put_NextAsynchItem(This,newVal)	\
    ( (This)->lpVtbl -> put_NextAsynchItem(This,newVal) ) 

#define IPIAsynchStatusInt_get_InternalReturnItem(This,pVal)	\
    ( (This)->lpVtbl -> get_InternalReturnItem(This,pVal) ) 

#define IPIAsynchStatusInt_put_InternalReturnItem(This,newVal)	\
    ( (This)->lpVtbl -> put_InternalReturnItem(This,newVal) ) 

#define IPIAsynchStatusInt_AttachInternalResult(This,newVal)	\
    ( (This)->lpVtbl -> AttachInternalResult(This,newVal) ) 

#define IPIAsynchStatusInt_get_CreatorThreadID(This,pVal)	\
    ( (This)->lpVtbl -> get_CreatorThreadID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIAsynchStatusInt_INTERFACE_DEFINED__ */


#ifndef ___PIGlobalRestorer_INTERFACE_DEFINED__
#define ___PIGlobalRestorer_INTERFACE_DEFINED__

/* interface _PIGlobalRestorer */
/* [unique][helpstring][helpcontext][hidden][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID__PIGlobalRestorer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("908DDF80-EA77-11D3-BDC5-00C04F779EB2")
    _PIGlobalRestorer : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreObject( 
            /* [in] */ BSTR persistenceData,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ IUnknown **hObject) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreServers( 
            /* [in] */ BSTR persistenceData,
            /* [out] */ _PIErrors **hErrors,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ _NamedValues **hServers) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _PIGlobalRestorerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _PIGlobalRestorer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _PIGlobalRestorer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _PIGlobalRestorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _PIGlobalRestorer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _PIGlobalRestorer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _PIGlobalRestorer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _PIGlobalRestorer * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreObject )( 
            _PIGlobalRestorer * This,
            /* [in] */ BSTR persistenceData,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ IUnknown **hObject);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreServers )( 
            _PIGlobalRestorer * This,
            /* [in] */ BSTR persistenceData,
            /* [out] */ _PIErrors **hErrors,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ _NamedValues **hServers);
        
        END_INTERFACE
    } _PIGlobalRestorerVtbl;

    interface _PIGlobalRestorer
    {
        CONST_VTBL struct _PIGlobalRestorerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _PIGlobalRestorer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _PIGlobalRestorer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _PIGlobalRestorer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _PIGlobalRestorer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _PIGlobalRestorer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _PIGlobalRestorer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _PIGlobalRestorer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _PIGlobalRestorer_RestoreObject(This,persistenceData,pnvsContext,hObject)	\
    ( (This)->lpVtbl -> RestoreObject(This,persistenceData,pnvsContext,hObject) ) 

#define _PIGlobalRestorer_RestoreServers(This,persistenceData,hErrors,pnvsContext,hServers)	\
    ( (This)->lpVtbl -> RestoreServers(This,persistenceData,hErrors,pnvsContext,hServers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___PIGlobalRestorer_INTERFACE_DEFINED__ */



#ifndef __PISDKCommon_LIBRARY_DEFINED__
#define __PISDKCommon_LIBRARY_DEFINED__

/* library PISDKCommon */
/* [helpstring][helpfile][version][uuid] */ 

#pragma once
typedef /* [helpstring] */ 
enum cmeErrorConstants
    {
        cmeINVALIDOPTIONS	= 0x800404a1,
        cmeOPENINGREGKEY	= 0x800404a2,
        cmeREGKEYEXISTS	= 0x800404a3,
        cmeUNKNOWNREGTYPE	= 0x80040481,
        cmeUNSUPPORTEDREGTYPE	= 0x80040482,
        cmeNVNOTORPHAN	= 0x800405d7,
        cmeRESTOREOBJECT	= 0x800405e7,
        cmePIERRORSCREATE	= 0x800405e5,
        cmeRESTORESERVERS	= 0x800405e6,
        cmeW32EVENTCREATE	= 0x80040799,
        cmeASYNCHTIMEOUT	= 0x8004077b,
        cmeASYNCHINPROGRESS	= 0x80040766,
        cmeASYNCHCOMPLETE	= 0x8004079c,
        cmeASYNCHNOTINPROGRESS	= 0x8004079d,
        cmeNAMEDVALUES	= 0x800407bf,
        cmeMTNVS	= 0x8004300f,
        cmeMTNV	= 0x80043018,
        cmeMTNVSLOCKWAITFOREVERTIMEOUT	= 0x80043019,
        cmeMTNVEXCEEDPARENTLOCKATTEMPTMAX	= 0x8004301a
    } 	cmeErrorConstants;


EXTERN_C const IID LIBID_PISDKCommon;

EXTERN_C const CLSID CLSID_NamedValues;

#ifdef __cplusplus

class DECLSPEC_UUID("010F0971-5A49-11D1-8088-00A0240B7FDC")
NamedValues;
#endif

EXTERN_C const CLSID CLSID_NamedValue2;

#ifdef __cplusplus

class DECLSPEC_UUID("A6CCC641-5F6C-11d4-BDF9-00C04F779EB2")
NamedValue2;
#endif

EXTERN_C const CLSID CLSID_MTNV;

#ifdef __cplusplus

class DECLSPEC_UUID("720D4195-D484-4140-B2DD-3BB083B34188")
MTNV;
#endif

EXTERN_C const CLSID CLSID_MTNVS;

#ifdef __cplusplus

class DECLSPEC_UUID("A95A7C8E-E3A8-4FF9-97D0-434467B715FD")
MTNVS;
#endif

EXTERN_C const CLSID CLSID_PIErrors;

#ifdef __cplusplus

class DECLSPEC_UUID("21CC3DE7-EF1F-11D3-BDC7-00C04F779EB2")
PIErrors;
#endif

EXTERN_C const CLSID CLSID_PIError;

#ifdef __cplusplus

class DECLSPEC_UUID("21CC3DE9-EF1F-11D3-BDC7-00C04F779EB2")
PIError;
#endif

#ifndef ___PIAsynchStatusEvents_DISPINTERFACE_DEFINED__
#define ___PIAsynchStatusEvents_DISPINTERFACE_DEFINED__

/* dispinterface _PIAsynchStatusEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__PIAsynchStatusEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("36FC9462-5334-11d2-BEFA-0060B0290178")
    _PIAsynchStatusEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _PIAsynchStatusEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _PIAsynchStatusEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _PIAsynchStatusEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _PIAsynchStatusEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _PIAsynchStatusEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _PIAsynchStatusEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _PIAsynchStatusEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _PIAsynchStatusEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _PIAsynchStatusEventsVtbl;

    interface _PIAsynchStatusEvents
    {
        CONST_VTBL struct _PIAsynchStatusEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _PIAsynchStatusEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _PIAsynchStatusEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _PIAsynchStatusEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _PIAsynchStatusEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _PIAsynchStatusEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _PIAsynchStatusEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _PIAsynchStatusEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___PIAsynchStatusEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PIAsynchStatus;

#ifdef __cplusplus

class DECLSPEC_UUID("36FC9463-5334-11d2-BEFA-0060B0290178")
PIAsynchStatus;
#endif

#ifndef __IPIReset_INTERFACE_DEFINED__
#define __IPIReset_INTERFACE_DEFINED__

/* interface IPIReset */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IPIReset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F6A05E85-DBA5-441d-9788-CE8E75EC3693")
    IPIReset : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIResetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIReset * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIReset * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIReset * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IPIReset * This);
        
        END_INTERFACE
    } IPIResetVtbl;

    interface IPIReset
    {
        CONST_VTBL struct IPIResetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIReset_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIReset_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIReset_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIReset_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIReset_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PIGlobalRestorer;

#ifdef __cplusplus

class DECLSPEC_UUID("908DDF81-EA77-11D3-BDC5-00C04F779EB2")
PIGlobalRestorer;
#endif

#ifndef __IPIRestorer_INTERFACE_DEFINED__
#define __IPIRestorer_INTERFACE_DEFINED__

/* interface IPIRestorer */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPIRestorer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA451DA2-EA7F-11d3-BDC5-00C04F779EB2")
    IPIRestorer : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreObject( 
            /* [in] */ BSTR PersistenceData,
            /* [in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ IUnknown **hObject) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreServers( 
            /* [in] */ BSTR persistenceData,
            /* [in] */ _PIErrors *pErrors,
            /* [in] */ _NamedValues *pnvsContext,
            /* [in] */ _NamedValues *pServers) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIRestorerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIRestorer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIRestorer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIRestorer * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreObject )( 
            IPIRestorer * This,
            /* [in] */ BSTR PersistenceData,
            /* [in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ IUnknown **hObject);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreServers )( 
            IPIRestorer * This,
            /* [in] */ BSTR persistenceData,
            /* [in] */ _PIErrors *pErrors,
            /* [in] */ _NamedValues *pnvsContext,
            /* [in] */ _NamedValues *pServers);
        
        END_INTERFACE
    } IPIRestorerVtbl;

    interface IPIRestorer
    {
        CONST_VTBL struct IPIRestorerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIRestorer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIRestorer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIRestorer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIRestorer_RestoreObject(This,PersistenceData,pnvsContext,hObject)	\
    ( (This)->lpVtbl -> RestoreObject(This,PersistenceData,pnvsContext,hObject) ) 

#define IPIRestorer_RestoreServers(This,persistenceData,pErrors,pnvsContext,pServers)	\
    ( (This)->lpVtbl -> RestoreServers(This,persistenceData,pErrors,pnvsContext,pServers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIRestorer_INTERFACE_DEFINED__ */


#ifndef __IPIPersist_INTERFACE_DEFINED__
#define __IPIPersist_INTERFACE_DEFINED__

/* interface IPIPersist */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPIPersist;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA451DA1-EA7F-11d3-BDC5-00C04F779EB2")
    IPIPersist : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Persist( 
            /* [retval][out] */ BSTR *pPersistenceData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIPersistVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIPersist * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIPersist * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIPersist * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Persist )( 
            IPIPersist * This,
            /* [retval][out] */ BSTR *pPersistenceData);
        
        END_INTERFACE
    } IPIPersistVtbl;

    interface IPIPersist
    {
        CONST_VTBL struct IPIPersistVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIPersist_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIPersist_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIPersist_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIPersist_Persist(This,pPersistenceData)	\
    ( (This)->lpVtbl -> Persist(This,pPersistenceData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIPersist_INTERFACE_DEFINED__ */


#ifndef __IPIServers_INTERFACE_DEFINED__
#define __IPIServers_INTERFACE_DEFINED__

/* interface IPIServers */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPIServers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE71F984-4B6F-4FF4-A429-2EBD6E2F6C99")
    IPIServers : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetObjServers( 
            /* [out] */ _PIErrors **hErrors,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ _NamedValues **hServers) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPIServersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPIServers * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPIServers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPIServers * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetObjServers )( 
            IPIServers * This,
            /* [out] */ _PIErrors **hErrors,
            /* [defaultvalue][in] */ _NamedValues *pnvsContext,
            /* [retval][out] */ _NamedValues **hServers);
        
        END_INTERFACE
    } IPIServersVtbl;

    interface IPIServers
    {
        CONST_VTBL struct IPIServersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPIServers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPIServers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPIServers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPIServers_GetObjServers(This,hErrors,pnvsContext,hServers)	\
    ( (This)->lpVtbl -> GetObjServers(This,hErrors,pnvsContext,hServers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPIServers_INTERFACE_DEFINED__ */


#ifndef __IRefresh2_INTERFACE_DEFINED__
#define __IRefresh2_INTERFACE_DEFINED__

/* interface IRefresh2 */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IRefresh2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C0B5B31-E883-48e2-B62F-F8DA1D9ED201")
    IRefresh2 : public IRefresh
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE RefreshToDepth( 
            /* [in] */ int depth) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRefresh2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRefresh2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRefresh2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRefresh2 * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IRefresh2 * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RefreshToDepth )( 
            IRefresh2 * This,
            /* [in] */ int depth);
        
        END_INTERFACE
    } IRefresh2Vtbl;

    interface IRefresh2
    {
        CONST_VTBL struct IRefresh2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRefresh2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRefresh2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRefresh2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRefresh2_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 


#define IRefresh2_RefreshToDepth(This,depth)	\
    ( (This)->lpVtbl -> RefreshToDepth(This,depth) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRefresh2_INTERFACE_DEFINED__ */


#ifndef __IPITransaction_INTERFACE_DEFINED__
#define __IPITransaction_INTERFACE_DEFINED__

/* interface IPITransaction */
/* [unique][helpstring][helpcontext][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IPITransaction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8CEC04CE-F919-4da3-BC37-685897762575")
    IPITransaction : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Begin( 
            /* [retval][out] */ VARIANT *pvarTransactionID) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Rollback( 
            /* [in] */ VARIANT varTransactionID) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDirty( 
            /* [retval][out] */ VARIANT_BOOL *pIsDirty) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPITransactionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPITransaction * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPITransaction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPITransaction * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IPITransaction * This,
            /* [retval][out] */ VARIANT *pvarTransactionID);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IPITransaction * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPITransaction * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rollback )( 
            IPITransaction * This,
            /* [in] */ VARIANT varTransactionID);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDirty )( 
            IPITransaction * This,
            /* [retval][out] */ VARIANT_BOOL *pIsDirty);
        
        END_INTERFACE
    } IPITransactionVtbl;

    interface IPITransaction
    {
        CONST_VTBL struct IPITransactionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPITransaction_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPITransaction_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPITransaction_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPITransaction_Begin(This,pvarTransactionID)	\
    ( (This)->lpVtbl -> Begin(This,pvarTransactionID) ) 

#define IPITransaction_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#define IPITransaction_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPITransaction_Rollback(This,varTransactionID)	\
    ( (This)->lpVtbl -> Rollback(This,varTransactionID) ) 

#define IPITransaction_get_IsDirty(This,pIsDirty)	\
    ( (This)->lpVtbl -> get_IsDirty(This,pIsDirty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPITransaction_INTERFACE_DEFINED__ */

#endif /* __PISDKCommon_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


