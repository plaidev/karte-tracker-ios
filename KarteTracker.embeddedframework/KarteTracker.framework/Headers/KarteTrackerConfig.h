//
//  KarteTrackerConfig.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteTrackerConfigBuilder.h"
#import "KarteIDFADelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerConfig : NSObject
@property (nonatomic, class, strong, readonly) KarteTrackerConfig *configure __attribute__((deprecated("Use +[KRTConfiguration defaultConfiguration] instead.")));

@property (nonatomic, copy, readonly) NSString *trackEndpoint __attribute__((deprecated));
@property (nonatomic, copy, readonly) NSString *overlayEndpoint __attribute__((deprecated));

@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppLifecycle) BOOL enabledTrackingAppLifecycle NS_SWIFT_NAME(isEnabledTrackingAppLifecycle) __attribute__((deprecated));
@property (nonatomic, assign, readonly, getter=isEnabledTrackingAppOpen) BOOL enabledTrackingAppOpen NS_SWIFT_NAME(isEnabledTrackingAppOpen) __attribute__((deprecated));
@property (nonatomic, assign, readonly, getter=isEnabledTrackingCrashError) BOOL enabledTrackingCrashError NS_SWIFT_NAME(isEnabledTrackingCrashError) __attribute__((deprecated));
@property (nonatomic, assign, readonly, getter=isEnabledFCMTokenResend) BOOL enabledFCMTokenResend NS_SWIFT_NAME(isEnabledFCMTokenResend) __attribute__((deprecated));
@property (nonatomic, assign, readonly, getter=isEnabledOptOutDefault) BOOL enabledOptOutDefault NS_SWIFT_NAME(isEnabledOptOutDefault) __attribute__((deprecated("Use -[KRTConfiguration isOptOut] instead.")));
@property (nonatomic, assign, readonly, getter=isDryRun) BOOL dryRun NS_SWIFT_NAME(isDryRun) __attribute__((deprecated("Use -[KRTConfiguration isDryRun] instead.")));
@property (nonatomic, assign, readonly, getter=isEnabledVisualTracking) BOOL enabledVisualTracking NS_SWIFT_NAME(isEnabledVisualTracking) __attribute__((deprecated));
@property (nonatomic, weak, readonly) id<KarteIDFADelegate> IDFADelegate __attribute__((deprecated("Use -[KRTConfiguration idfaDelegate] instead.")));

- (instancetype)initWithBuilder:(KarteTrackerConfigBuilder *)builder NS_SWIFT_NAME(init(_:)) __attribute__((deprecated("Use -[KRTConfiguration init] instead.")));
+ (instancetype)configureWithBuilder:(void (^)(KarteTrackerConfigBuilder *builder))closure NS_SWIFT_NAME(configure(_:)) __attribute__((deprecated("Use -[KRTConfiguration init] instead.")));

@end

NS_ASSUME_NONNULL_END
