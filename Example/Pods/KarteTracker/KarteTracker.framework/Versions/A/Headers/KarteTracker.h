//
//  Tracker.h
//  Pods
//

#ifndef Tracker_h
#define Tracker_h

#import <Foundation/Foundation.h>
#import "KarteTrackerUtil.h"
#import "KarteTrackerConfig.h"
#import "KarteTrackerUserProfile.h"
#import "KarteTrackerAppProfile.h"
@protocol KarteTrackerDelegate;
@class KarteUIWindow;

@interface KarteTracker : NSObject

#pragma mark - Tracking

@property (nonatomic, strong) KarteTrackerConfig *config;
@property (nonatomic, strong) KarteUIWindow *overlayWindow;
@property (atomic, weak) id<KarteTrackerDelegate> delegate;
+ (nullable instancetype)sharedTrackerWithAppKey:(nonnull NSString *)appKey;
+ (nullable instancetype)sharedTracker;
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey;
+ (nonnull instancetype)setupWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config;

- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey;
- (nonnull instancetype)initWithAppKey:(nonnull NSString *)appKey config:(nullable NSDictionary *)config;

- (void)track:(nonnull NSString *)eventName values:(nullable NSDictionary *)values;
- (void)trackNotification:(nonnull NSDictionary *)userInfo;
- (void)trackUncaughtException:(nonnull NSDictionary *)values;
- (void)identify:(nonnull NSDictionary *)values;
- (void)view:(nonnull NSString *)view_name;
- (void)view:(nonnull NSString *)view_name values:(nullable NSDictionary *)values;
- (void)flush;

#pragma mark - Notification

- (void)registerFCMToken:(nonnull NSString *)token;

@end

#pragma mark - Delegate

@protocol KarteTrackerDelegate <NSObject>
@required
- (void) karteTracker:(KarteTracker *)tracker
     receivedResponse:(NSDictionary *)responseBody;
@end

#endif /* Tracker_h */
