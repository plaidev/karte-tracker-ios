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
#import "KarteUrlSchemeHandler.h"

#import "KRTApp.h"
#import "KRTConfiguration.h"
#import "KRTIDFADelegate.h"
#import "KRTInAppMessaging.h"
#import "KRTRemoteNotification.h"
#import "KRTTracker.h"
#import "KRTVariable.h"
#import "KRTVariables.h"
#import "KRTUserSync.h"
#import "KRTLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol KarteTrackerDelegate;
@protocol KarteVisualTrackDelegate;
@class KarteTrackerAppProfile;
@class KarteTrackerUserProfile;


@interface KarteTracker : NSObject
@property (nonatomic, class, strong, readonly) KarteTracker *sharedTracker;

@property (nonatomic, copy, readonly) NSString *appKey __attribute__((deprecated("Use +[KRTApp appKey] instead.")));
@property (nonatomic, copy, readonly) NSString *visitorId __attribute__((deprecated("Use +[KRTApp visitorId] instead.")));
@property (nonatomic, strong, readonly) KarteTrackerConfig *config __attribute__((deprecated("Use +[KRTApp configuration] instead.")));

+ (instancetype)sharedTrackerWithAppKey:(NSString *)appKey NS_SWIFT_NAME(shared(appKey:)) __attribute__((deprecated("This method is deprecated. Support for multiple application keys will be removed in a future version.")));
+ (instancetype)setupWithAppKey:(NSString *)appKey NS_SWIFT_NAME(setup(appKey:)) __attribute__((deprecated("Use +[KRTApp setupWithAppKey:] instead.")));
+ (instancetype)setupWithAppKey:(NSString *)appKey withConfig:(KarteTrackerConfig *)config NS_SWIFT_NAME(setup(appKey:config:)) __attribute__((deprecated("Use +[KRTApp setupWithAppKey:configuration:] instead.")));

- (instancetype)initWithAppKey:(NSString *)appKey NS_SWIFT_NAME(init(appKey:)) __attribute__((deprecated("Use +[KRTApp setupWithAppKey:] instead.")));
- (instancetype)initWithAppKey:(NSString *)appKey withConfig:(KarteTrackerConfig *)config NS_SWIFT_NAME(init(appKey:config:)) __attribute__((deprecated("Use +[KRTApp setupWithAppKey:configuration:] instead.")));

- (void)optOut __attribute__((deprecated("Use +[KRTApp optOut] instead.")));
- (void)optIn __attribute__((deprecated("Use +[KRTApp optIn] instead.")));

@end


@interface KarteTracker (Track)
- (void)track:(NSString *)eventName values:(nullable NSDictionary *)values __attribute__((deprecated("Use +[KRTTracker track:values:] instead.")));
- (void)track:(NSString *)eventName values:(nullable NSDictionary *)values view:(nullable UIView *)view __attribute__((deprecated("Use -[KRTTracker initWithView] and -[KRTTracker track:values:] instead.")))API_AVAILABLE(ios(13.0));
;
- (void)trackNotification:(NSDictionary *)userInfo __attribute__((deprecated));
- (void)trackUncaughtException:(NSDictionary *)values __attribute__((deprecated));
- (void)identify:(NSDictionary *)values __attribute__((deprecated("Use +[KRTTracker identify:] instead.")));
- (void)identify:(NSDictionary *)values view:(nullable UIView *)view __attribute__((deprecated("Use -[KRTTracker initWithView:] and -[KRTTracker identify:] instead.")))API_AVAILABLE(ios(13.0));
;
- (void)view:(NSString *)viewName __attribute__((deprecated("Use +[KRTTracker view:] instead.")));
- (void)view:(NSString *)viewName title:(NSString *)title __attribute__((deprecated("Use +[KRTTracker view:title:] instead.")));
- (void)view:(NSString *)viewName title:(NSString *)title values:(nullable NSDictionary *)values __attribute__((deprecated("Use +[KRTTracker view:title:values:] instead.")));
- (void)view:(NSString *)viewName title:(NSString *)title values:(nullable NSDictionary *)values view:(nullable UIView *)view __attribute__((deprecated("Use -[KRTTracker initWithView:] and -[KRTTracker view:title:values:] instead.")))API_AVAILABLE(ios(13.0));
- (void)view:(NSString *)viewName values:(nullable NSDictionary *)values __attribute__((deprecated("Use +[KRTTracker view:title:values:] instead.")));

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (void)logoutWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(logout(_:)) __attribute__((deprecated("Use -[KarteTracker renewVisitorId]. since v1.5.3")));
;
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (void)logout __attribute__((deprecated("Use -[KarteTracker renewVisitorId]. since v1.5.9")));
#pragma clang diagnostic pop

- (void)renewVisitorId __attribute__((deprecated("Use +[KRTApp renewVisitorId] instead.")));
@end


@interface KarteTracker (FirebaseCloudMessaging)
- (void)registerFCMToken:(NSString *)token __attribute__((deprecated("Use +[KRTApp registerFCMToken:] instead.")));
- (void)handleFCMRemoteMessage:(NSDictionary *)data __attribute__((deprecated));
@end

NS_ASSUME_NONNULL_END
