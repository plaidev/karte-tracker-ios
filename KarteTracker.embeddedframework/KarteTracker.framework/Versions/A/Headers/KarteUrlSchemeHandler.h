//
//  KarteUrlSchemeHandler.h
//  KarteTracker
//
//  Copyright (c) 2019 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteUrlSchemeHandler : NSObject
+ (BOOL)handle:(nullable NSURL *)url __attribute__((deprecated("Use +[KRTApp application:openURL:] instead.")));
@end

NS_ASSUME_NONNULL_END
