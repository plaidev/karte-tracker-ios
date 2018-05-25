//
//  KarteTracker.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KarteTrackerUtil.h"
#import "KarteRemoteNotificationHandler.h"
#import "KarteTrackerJsUtil.h"

@protocol KarteTrackerDelegate;
@class KarteTrackerConfig;
@class KarteTrackerUserProfile;
@class KarteTrackerAppProfile;
@class KarteUIWindow;

@interface KarteTracker : NSObject

#pragma mark - Tracking

@property (nonatomic, strong) KarteTrackerConfig *config;
@property (nonatomic, strong) KarteUIWindow *overlayWindow;
@property (nonatomic, weak) id<KarteTrackerDelegate> delegate;
@property (nonatomic, strong) KarteTrackerUserProfile *userProfile;
@property (nonatomic, strong) KarteTrackerAppProfile *appProfile;

+ (nullable instancetype)sharedTrackerWithAppKey:(nonnull NSString *)appKey;
+ (nullable instancetype)sharedTracker;
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey;
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config;

- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey;
- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config;

- (void)track:(nonnull NSString *)eventName values:(nullable NSDictionary *)values;
- (void)trackUncaughtException:(nonnull NSDictionary *)values;
- (void)identify:(nonnull NSDictionary *)values;
- (void)view:(nonnull NSString *)viewName;
- (void)view:(nonnull NSString *)viewName values:(nullable NSDictionary *)values;
- (void)flush;

#pragma mark - Notification
- (void)registerFCMToken:(nonnull NSString *)token;
- (void)trackNotification:(nonnull NSDictionary *)userInfo;

@end

#pragma mark - Delegate
@protocol KarteTrackerDelegate <NSObject>
@required
- (void)karteTracker:(KarteTracker *)tracker receivedResponse:(NSDictionary *)responseBody;
@end
