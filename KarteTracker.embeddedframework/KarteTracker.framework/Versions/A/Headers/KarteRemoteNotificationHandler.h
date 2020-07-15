//
//  KarteRemoteNotificationHandler.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteRemoteNotificationHandler : NSObject
+ (BOOL)handleRemoteNotification:(nullable NSDictionary *)userInfo __attribute__((deprecated("Use -[KRTRemoteNotification handle] instead.")));
+ (BOOL)canHandleRemoteNotification:(nullable NSDictionary *)userInfo __attribute__((deprecated("This method is deprecated. By checking whether the return value of the initializer is nil, you can confirm that the notification is handleable.")));
+ (nullable NSURL *)retrieveURLFromUserInfo:(nullable NSDictionary *)userInfo NS_SWIFT_NAME(retrieveURL(userInfo:)) __attribute__((deprecated("Use -[KRTRemoteNotification url] instead.")));
@end

NS_ASSUME_NONNULL_END
