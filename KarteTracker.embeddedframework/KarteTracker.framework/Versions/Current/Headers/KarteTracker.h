//
//  KarteTracker.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteConstants.h"
#import "KarteIDFADelegate.h"
#import "KarteInAppMessagingManager.h"
#import "KarteLogger.h"
#import "KarteRemoteNotificationHandler.h"
#import "KarteTrackerConfig.h"
#import "KarteTrackerConfigBuilder.h"
#import "KarteTrackerJsUtil.h"
#import "KarteTrackerUtil.h"
#import "KarteVariable.h"
#import "KarteVariables.h"

@protocol KarteTrackerDelegate;
@class KarteTrackerAppProfile;
@class KarteTrackerUserProfile;


@interface KarteTracker : NSObject
@property (nonatomic, class, strong, readonly, nonnull) KarteTracker *sharedTracker;

@property (nonatomic, copy, readonly) NSString *appKey;
@property (nonatomic, strong, readonly) KarteTrackerConfig *config;
@property (nonatomic, copy, readonly, nonnull) NSString *visitorId;

+ (nonnull instancetype)sharedTrackerWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(shared(appKey:));
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(setup(appKey:));
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey withConfig:(nonnull KarteTrackerConfig *)config NS_SWIFT_NAME(setup(appKey:config:));

- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey NS_SWIFT_NAME(init(appKey:));
- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey withConfig:(nonnull KarteTrackerConfig *)config NS_SWIFT_NAME(init(appKey:config:));

@end


@interface KarteTracker (Track)
- (void)track:(nonnull NSString *)eventName values:(nullable NSDictionary *)values;
- (void)trackNotification:(nonnull NSDictionary *)userInfo;
- (void)trackUncaughtException:(nonnull NSDictionary *)values;
- (void)identify:(nonnull NSDictionary *)values;
- (void)view:(nonnull NSString *)viewName;
- (void)view:(nonnull NSString *)viewName title:(nonnull NSString *)title;
- (void)view:(nonnull NSString *)viewName title:(nonnull NSString *)title values:(nullable NSDictionary *)values;
- (void)view:(nonnull NSString *)viewName values:(nullable NSDictionary *)values;

- (void)logoutWithCompletionBlock:(nonnull void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(logout(_:)) __attribute__((deprecated("Use -[KarteTracker logout]. since v1.5.3")));
;
- (void)logout;
@end


@interface KarteTracker (FirebaseCloudMessaging)
- (void)registerFCMToken:(nonnull NSString *)token;
- (void)handleFCMRemoteMessage:(nonnull NSDictionary *)data;
@end
