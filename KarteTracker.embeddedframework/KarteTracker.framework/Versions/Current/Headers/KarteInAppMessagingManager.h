//
//  KarteInAppMessagingManager.h
//  KarteTracker
//
//  Created by tomoki.koga on 2018/10/04.
//

#import <Foundation/Foundation.h>


@interface KarteInAppMessagingManager : NSObject
@property (class, nonatomic, strong, readonly) KarteInAppMessagingManager *sharedManager;
@property (nonatomic, assign, readonly, getter=isPresenting) BOOL presenting;

- (void)dismiss;
@end
