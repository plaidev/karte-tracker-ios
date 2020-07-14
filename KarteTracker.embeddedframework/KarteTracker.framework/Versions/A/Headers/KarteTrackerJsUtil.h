//
//  KarteTrackerJsUtil.h
//  Pods
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteTrackerJsUtil : NSObject
+ (NSString *)stringByAppendingUserSyncQueryParameter:(NSString *)appKey withURLString:(NSString *)url NS_SWIFT_NAME(stringByAppendingUserSyncQueryParameter(appKey:url:)) __attribute__((deprecated("Use +[KRTUserSync appendingQueryParameterWithURLString:] instead.")));
+ (NSURL *)URLByAppendingUserSyncQueryParameter:(NSString *)appKey withURL:(NSURL *)url NS_SWIFT_NAME(URLByAppendingUserSyncQueryParameter(appKey:url:)) __attribute__((deprecated("Use +[KRTUserSync appendingQueryParameterWithURL:] instead.")));
+ (nullable NSString *)userSyncQueryParameter:(NSString *)appKey __attribute__((deprecated));

+ (void)setUserSyncScriptWithWebView:(WKWebView *)webView NS_SWIFT_NAME(setUserSyncScript(with:)) __attribute__((deprecated("Use +[KRTUserSync setUserSyncScriptWithWebView:] instead.")));
+ (void)setUserSyncScriptWithWebView:(WKWebView *)webView appKey:(NSString *)appKey NS_SWIFT_NAME(setUserSyncScript(with:appKey:)) __attribute__((deprecated("Use +[KRTUserSync setUserSyncScriptWithWebView:] instead.")));
@end

NS_ASSUME_NONNULL_END
