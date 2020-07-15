//
//  KarteInAppMessagingManager.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KarteInAppMessagingManagerDelegate;


@interface KarteInAppMessagingManager : NSObject
@property (class, nonatomic, strong, readonly) KarteInAppMessagingManager *sharedManager __attribute__((deprecated("Use +[KRTInAppMessaging shared] instead.")));
@property (nonatomic, assign, readonly, getter=isPresenting) BOOL presenting __attribute__((deprecated("Use -[KRTInAppMessaging isPresenting] instead.")));
@property (nonatomic, weak) id<KarteInAppMessagingManagerDelegate> delegate __attribute__((deprecated("Use -[KRTInAppMessaging delegate] instead.")));
- (void)dismiss __attribute__((deprecated("Use -[KRTInAppMessaging dismiss] instead.")));
- (void)suppress __attribute__((deprecated("Use -[KRTInAppMessaging suppress] instead.")));
- (void)unsuppress __attribute__((deprecated("Use -[KRTInAppMessaging unsuppress] instead.")));
@end


@protocol KarteInAppMessagingManagerDelegate <NSObject>
@optional
- (BOOL)inAppMessagingManager:(KarteInAppMessagingManager *)manager shouldOpenURL:(nullable NSURL *)url __attribute__((deprecated("Use -[KRTInAppMessagingDelegate inAppMessaging:shouldOpenURL:] instead.")));
@end

NS_ASSUME_NONNULL_END
