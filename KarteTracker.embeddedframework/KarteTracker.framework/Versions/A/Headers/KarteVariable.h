//
//  KarteVariable.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteVariable : NSObject
@property (nonatomic, copy, nullable, readonly) NSString *campaignId __attribute__((deprecated("Use -[KRTVariable campaignId] instead.")));
@property (nonatomic, copy, nullable, readonly) NSString *shortenId __attribute__((deprecated("Use +[KRTVariables shortenId] instead.")));
@property (nonatomic, assign, readonly) BOOL isDefined __attribute__((deprecated));

@property (nonatomic, copy, readonly, nullable) NSString *string __attribute__((deprecated("Use -[KRTVariable string] instead.")));
@property (nonatomic, copy, readonly, nullable) NSArray *array __attribute__((deprecated("Use -[KRTVariable array] instead.")));
@property (nonatomic, copy, readonly, nullable) NSDictionary *dictionary __attribute__((deprecated("Use -[KRTVariable dictionary] instead.")));

- (NSString *)stringWithDefaultValue:(NSString *)defaultValue NS_SWIFT_NAME(string(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable string] instead.")));
- (NSInteger)integerWithDefaultValue:(NSInteger)defaultValue NS_SWIFT_NAME(integer(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable integerWithDefaultValue:] instead.")));
- (double)doubleWithDefaultValue:(double)defaultValue NS_SWIFT_NAME(double(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable doubleWithDefaultValue:] instead.")));
- (BOOL)boolWithDefaultValue:(BOOL)defaultValue NS_SWIFT_NAME(boolean(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable boolWithDefaultValue:] instead.")));
- (NSArray *)arrayWithDefaultValue:(NSArray *)defaultValue NS_SWIFT_NAME(array(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable arrayWithDefaultValue:] instead.")));
- (NSDictionary *)dictionaryWithDefaultValue:(NSDictionary *)defaultValue NS_SWIFT_NAME(dictionary(defaultValue:)) __attribute__((deprecated("Use -[KRTVariable dictionaryWithDefaultValue:] instead.")));
@end

NS_ASSUME_NONNULL_END
