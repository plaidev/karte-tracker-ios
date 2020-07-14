//
//  KRTTracker.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Tracker)
@interface KRTTracker : NSObject
+ (void)track:(NSString *)eventName values:(NSDictionary *)values;
+ (void)identify:(NSDictionary *)values;
+ (void)view:(NSString *)viewName;
+ (void)view:(NSString *)viewName title:(nullable NSString *)title;
+ (void)view:(NSString *)viewName title:(nullable NSString *)title values:(NSDictionary *)values;

- (instancetype)initWithView:(nullable UIView *)view;
- (void)track:(NSString *)eventName values:(NSDictionary *)values;
- (void)identify:(NSDictionary *)values;
- (void)view:(NSString *)viewName;
- (void)view:(NSString *)viewName title:(nullable NSString *)title;
- (void)view:(NSString *)viewName title:(nullable NSString *)title values:(NSDictionary *)values;

+ (void)trackOpenWithVariables:(NSArray *)variables values:(NSDictionary *)values NS_SWIFT_NAME(trackOpen(variables:values:));
+ (void)trackClickWithVariables:(NSArray *)variables values:(NSDictionary *)values NS_SWIFT_NAME(trackClick(variables:values:));

+ (void)trackClickWithUserInfo:(NSDictionary *)userInfo NS_SWIFT_NAME(trackClick(userInfo:));
@end

NS_ASSUME_NONNULL_END
