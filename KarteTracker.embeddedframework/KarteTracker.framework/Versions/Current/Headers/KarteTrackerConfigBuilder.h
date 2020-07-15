//
//  KarteTrackerConfigBuilder.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteLogger.h"
#import "KarteIDFADelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerConfigBuilder : NSObject
@property (nonatomic, copy) NSString *trackEndpoint;
@property (nonatomic, copy) NSString *overlayEndpoint;

@property (nonatomic, assign, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle __attribute__((deprecated));
@property (nonatomic, assign, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen __attribute__((deprecated));
@property (nonatomic, assign, getter=isEnabledTrackingIdfa) BOOL enabledTrackingIdfa __attribute__((deprecated("Use -[KarteTrackerConfigBuilder IDFADelegate]. since v1.5.5")));
@property (nonatomic, assign, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError __attribute__((deprecated));
@property (nonatomic, assign, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend __attribute__((deprecated));
@property (nonatomic, assign, getter=isEnabledVisualTracking) BOOL enabledVisualTracking __attribute__((deprecated));
@property (nonatomic, assign, getter=isEnabledOptOutDefault) BOOL enabledOptOutDefault __attribute__((deprecated("Use -[KRTConfiguration isOptOutEnabled] instead.")));
@property (nonatomic, assign, getter=isDryRun) BOOL dryRun __attribute__((deprecated("Use -[KRTConfiguration isDryRun] instead.")));
@property (nonatomic, weak) id<KarteIDFADelegate> IDFADelegate __attribute__((deprecated("Use -[KRTConfiguration idfaDelegate] instead.")));
@end

NS_ASSUME_NONNULL_END
