/* ====================================================================== *
 * Copyright (c) 2010-2018 ZFFramework
 * Github repo: https://github.com/ZFFramework/ZFFramework
 * Home page: http://ZFFramework.com
 * Blog: http://zsaber.com
 * Contact: master@zsaber.com (Chinese and English only)
 * Distributed under MIT license:
 *   https://github.com/ZFFramework/ZFFramework/blob/master/LICENSE
 * ====================================================================== */
#include "ZFLog.h"
#include "ZFLog_StackTrace.h"
#include "ZFImplOutput.h"
#include "ZFString.h"

ZF_NAMESPACE_GLOBAL_BEGIN

// ============================================================
static void _ZFP_ZFLog_ZFCoreLogExt(ZF_IN const ZFCallerInfo &callerInfo)
{
    if(zfLogStackTraceAvailable())
    {
        zfCoreLogTrim(zfLogStackTrace(zfnull, 2).cString());
    }
}

ZF_GLOBAL_INITIALIZER_INIT_WITH_LEVEL(ZFLog_ZFCoreLogExt, ZFLevelZFFrameworkEssential)
{
    zfCoreCriticalErrorCallbackAdd(_ZFP_ZFLog_ZFCoreLogExt);
}
ZF_GLOBAL_INITIALIZER_DESTROY(ZFLog_ZFCoreLogExt)
{
    zfCoreCriticalErrorCallbackRemove(_ZFP_ZFLog_ZFCoreLogExt);
}
ZF_GLOBAL_INITIALIZER_END(ZFLog_ZFCoreLogExt)

ZF_NAMESPACE_GLOBAL_END

