//
//  KarteTrackerUtil.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString *const kCrashInfoFileName;

void KarteTrackerShowLog(BOOL showLog);
void KarteTrackerLog(NSString *format, ...);
void KarteTrackerExceptionHandler(NSException *exception);

NSString * GetTrackerSerializeFilePath(NSString *filename);
NSString * GetBundleID(void);
NSString * GetDeviceName(void);
NSString * GetIdfa(void);
