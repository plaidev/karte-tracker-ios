//
//  KRTUserSync.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/02/13.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(UserSync)
@interface KRTUserSync : NSObject
+ (NSString *)appendingQueryParameterWithURLString:(NSString *)url NS_SWIFT_NAME(appendingQueryParameter(_:));
+ (NSURL *)appendingQueryParameterWithURL:(NSURL *)url NS_SWIFT_NAME(appendingQueryParameter(_:));
+ (void)setUserSyncScriptWithWebView:(WKWebView *)webView NS_SWIFT_NAME(setUserSyncScript(_:));
@end

NS_ASSUME_NONNULL_END
