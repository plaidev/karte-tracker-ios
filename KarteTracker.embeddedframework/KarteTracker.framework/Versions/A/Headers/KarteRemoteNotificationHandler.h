//
//  KarteRemoteNotificationHandler.h
//  KarteTracker
//
//  Created by tomoki.koga on 2018/04/23.
//

#import <Foundation/Foundation.h>

extern const NSString * KarteNotificationKey;

@interface KarteRemoteNotificationHandler : NSObject
+ (BOOL)handleRemoteNotification:(nullable NSDictionary *)userInfo;
+ (BOOL)canHandleRemoteNotification:(nullable NSDictionary *)userInfo;
@end
