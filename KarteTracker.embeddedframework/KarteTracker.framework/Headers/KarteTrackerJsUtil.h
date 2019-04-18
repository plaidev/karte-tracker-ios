//
//  KarteTrackerJsUtil.h
//  Pods
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerJsUtil : NSObject
+ (NSString *)stringByAppendingUserSyncQueryParameter:(NSString *)appKey withURLString:(NSString *)url NS_SWIFT_NAME(stringByAppendingUserSyncQueryParameter(appKey:url:));
+ (NSURL *)URLByAppendingUserSyncQueryParameter:(NSString *)appKey withURL:(NSURL *)url NS_SWIFT_NAME(URLByAppendingUserSyncQueryParameter(appKey:url:));
+ (nullable NSString *)userSyncQueryParameter:(NSString *)appKey;
@end

NS_ASSUME_NONNULL_END
