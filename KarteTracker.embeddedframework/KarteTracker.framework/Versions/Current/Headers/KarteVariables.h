//
//  KarteVariables.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KarteVariable.h"

NS_ASSUME_NONNULL_BEGIN


@interface KarteVariables : NSObject
@property (class, strong, readonly) KarteVariables *variables __attribute__((deprecated));

- (instancetype)initWithAppKey:(NSString *)appKey NS_SWIFT_NAME(init(appKey:)) __attribute__((deprecated));
+ (instancetype)variablesWithAppKey:(NSString *)appKey NS_SWIFT_NAME(variables(appKey:)) __attribute__((deprecated));

- (void)fetch __attribute__((deprecated("Use +[KRTVariables fetch] instead.")));
+ (void)fetch __attribute__((deprecated("Use +[KRTVariables fetch] instead.")));
- (void)fetchWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:)) __attribute__((deprecated("Use +[KRTVariables fetchWithCompletion:] instead.")));
+ (void)fetchWithCompletionBlock:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(_:)) __attribute__((deprecated("Use +[KRTVariables fetchWithCompletion:] instead.")));

- (KarteVariable *)variableForKey:(NSString *)key NS_SWIFT_NAME(variable(forKey:)) __attribute__((deprecated("Use +[KRTVariables variableForKey:] instead.")));
+ (KarteVariable *)variableForKey:(NSString *)key NS_SWIFT_NAME(variable(forKey:)) __attribute__((deprecated("Use +[KRTVariables variableForKey:] instead.")));

- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:)) __attribute__((deprecated("Use +[KRTTracker trackOpenWithVariables:values:] or +[KRTTracker trackClickWithVariables:values:] instead.")));
- (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:)) __attribute__((deprecated("Use +[KRTTracker trackOpenWithVariables:values:] or +[KRTTracker trackClickWithVariables:values:] instead.")));

+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName NS_SWIFT_NAME(track(variables:eventName:)) __attribute__((deprecated("Use +[KRTTracker trackOpenWithVariables:values:] or +[KRTTracker trackClickWithVariables:values:] instead.")));
+ (void)trackWithVariables:(NSArray *)variables withEventName:(NSString *)eventName withValues:(nullable NSDictionary *)values NS_SWIFT_NAME(track(variables:eventName:values:)) __attribute__((deprecated("Use +[KRTTracker trackOpenWithVariables:values:] or +[KRTTracker trackClickWithVariables:values:] instead.")));

@end

NS_ASSUME_NONNULL_END
