//
//  KRTIDFADelegate.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(IDFADelegate)
@protocol KRTIDFADelegate <NSObject>
- (nullable NSString *)advertisingIdentifierString;
- (BOOL)isAdvertisingTrackingEnabled;
@end

NS_ASSUME_NONNULL_END
