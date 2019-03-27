//
//  KarteIDFADelegate.h
//  KarteTracker
//
//  Created by tomoki.koga on 2019/03/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KarteIDFADelegate <NSObject>
- (nullable NSString *)advertisingIdentifierString;
- (BOOL)isAdvertisingTrackingEnabled;
@end

NS_ASSUME_NONNULL_END
