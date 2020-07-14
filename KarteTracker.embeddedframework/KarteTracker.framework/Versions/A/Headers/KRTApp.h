//
//  KRTApp.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>
#import "KRTConfiguration.h"
#import "KRTLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(KarteApp)
@interface KRTApp : NSObject
@property (nonatomic, class, copy, readonly) NSString *appKey;
@property (nonatomic, class, copy, readonly) NSString *visitorId;
@property (nonatomic, class, strong, readonly) KRTConfiguration *configuration;

+ (void)setupWithAppKey:(NSString *)appKey NS_SWIFT_NAME(setup(appKey:));
+ (void)setupWithAppKey:(NSString *)appKey configuration:(KRTConfiguration *)configuration NS_SWIFT_NAME(setup(appKey:configuration:));

+ (void)optOut;
+ (void)optIn;

+ (void)registerFCMToken:(nullable NSString *)fcmToken;

+ (void)renewVisitorId;

+ (BOOL)application:(UIApplication *)app openURL:(NSURL *)url NS_SWIFT_NAME(application(_:open:));

+ (void)setLogLevel:(KRTLogLevel)logLevel;
+ (void)setLogEnabled:(BOOL)isEnabled;
@end

NS_ASSUME_NONNULL_END
