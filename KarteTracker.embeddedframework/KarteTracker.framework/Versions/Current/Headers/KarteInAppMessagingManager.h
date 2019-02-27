//
//  KarteInAppMessagingManager.h
//  KarteTracker
//
//  Created by tomoki.koga on 2018/10/04.
//

#import <Foundation/Foundation.h>

@protocol KarteInAppMessagingManagerDelegate;


@interface KarteInAppMessagingManager : NSObject
@property (class, nonatomic, strong, readonly, nonnull) KarteInAppMessagingManager *sharedManager;
@property (nonatomic, assign, readonly, getter=isPresenting) BOOL presenting;
@property (nonatomic, weak, nullable) id<KarteInAppMessagingManagerDelegate> delegate;

- (void)dismiss;
@end

@protocol KarteInAppMessagingManagerDelegate <NSObject>
@optional
- (BOOL)inAppMessagingManager:(nonnull KarteInAppMessagingManager *)manager shouldOpenURL:(nullable NSURL *)url;
@end
