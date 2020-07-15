//
//  KRTInAppMessaging.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KRTInAppMessagingDelegate;

NS_SWIFT_NAME(InAppMessaging)
@interface KRTInAppMessaging : NSObject
@property (nonatomic, class, strong, readonly) KRTInAppMessaging *shared;
@property (nonatomic, assign, readonly, getter=isPresenting) BOOL presenting NS_SWIFT_NAME(isPresenting);
@property (nonatomic, weak) id<KRTInAppMessagingDelegate> delegate;

- (void)dismiss;
- (void)suppress;
- (void)unsuppress;
@end

NS_SWIFT_NAME(InAppMessagingDelegate)
@protocol KRTInAppMessagingDelegate <NSObject>
@optional
- (BOOL)inAppMessaging:(KRTInAppMessaging *)inAppMessaging shouldOpenURL:(NSURL *)url NS_SWIFT_NAME(inAppMessaging(_:shouldOpenURL:));
@end

NS_ASSUME_NONNULL_END
