//
//  KRTConfiguration.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>
#import "KRTIDFADelegate.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Configuration)
@interface KRTConfiguration : NSObject
@property (nonatomic, class, copy, readonly) KRTConfiguration *defaultConfiguration;
@property (nonatomic, strong) NSURL *baseURL;
@property (nonatomic, strong) NSURL *overlayBaseURL;
@property (nonatomic, assign) BOOL isOptOut;
@property (nonatomic, assign) BOOL isDryRun;
@property (nonatomic, weak) id<KRTIDFADelegate> idfaDelegate;

- (instancetype)initWithConfigurator:(void (^)(KRTConfiguration *configuration))configurator;
+ (instancetype)configWithConfigurator:(void (^)(KRTConfiguration *configuration))configurator;
@end

NS_ASSUME_NONNULL_END
