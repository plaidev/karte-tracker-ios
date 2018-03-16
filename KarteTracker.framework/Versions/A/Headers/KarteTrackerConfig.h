//
//  KarteTrackerConfig.h
//  Pods
//

#ifndef KarteTrackerConfig_h
#define KarteTrackerConfig_h

#import <Foundation/Foundation.h>

@interface KarteTrackerConfig : NSObject

- (instancetype)initWithConfig:(NSDictionary *)config;

- (BOOL)enabledTrackingAppLifecycle;
- (NSString *)getViewEventName;
- (NSString *)getEndpoint;
- (NSString *)getOverlayViewUrl;
- (BOOL)enabledTrackingCrashError;
- (BOOL)enableFCMTokenResend;

@end

#endif /* KarteTrackerConfig_h */
