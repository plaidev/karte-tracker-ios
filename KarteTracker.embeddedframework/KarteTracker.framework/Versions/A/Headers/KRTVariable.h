//
//  KRTVariable.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Variable)
@interface KRTVariable : NSObject
@property (nonatomic, copy, readonly, nullable) NSString *campaignId;
@property (nonatomic, copy, readonly, nullable) NSString *shortenId;
@property (nonatomic, copy, readonly, nullable) NSString *string;
@property (nonatomic, copy, readonly, nullable) NSArray *array;
@property (nonatomic, copy, readonly, nullable) NSDictionary *dictionary;
@property (nonatomic, assign, readonly, getter=isDefined) BOOL defined NS_SWIFT_NAME(isDefined);

- (NSString *)stringWithDefaultValue:(NSString *)defaultValue NS_SWIFT_NAME(string(default:));
- (NSInteger)integerWithDefaultValue:(NSInteger)defaultValue NS_SWIFT_NAME(integer(default:));
- (double)doubleWithDefaultValue:(double)defaultValue NS_SWIFT_NAME(double(default:));
- (BOOL)boolWithDefaultValue:(BOOL)defaultValue NS_SWIFT_NAME(bool(default:));
- (NSArray *)arrayWithDefaultValue:(NSArray *)defaultValue NS_SWIFT_NAME(array(default:));
- (NSDictionary *)dictionaryWithDefaultValue:(NSDictionary *)defaultValue NS_SWIFT_NAME(dictionary(default:));
@end

NS_ASSUME_NONNULL_END
