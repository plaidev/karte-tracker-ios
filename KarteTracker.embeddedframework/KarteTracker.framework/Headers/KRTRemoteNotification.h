//
//  KRTRemoteNotification.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(RemoteNotification)
@interface KRTRemoteNotification : NSObject
@property (nonatomic, copy, readonly, nullable) NSURL *url;

- (nullable instancetype)initWithUserInfo:(NSDictionary *)userInfo;
- (BOOL)handle;
@end

NS_ASSUME_NONNULL_END
