//
//  KRTVariables.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/01/31.
//

#import <Foundation/Foundation.h>
#import "KRTVariable.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Variables)
@interface KRTVariables : NSObject
+ (void)fetch;
+ (void)fetchWithCompletion:(void (^)(BOOL isSuccessful))completion NS_SWIFT_NAME(fetch(completion:));
+ (KRTVariable *)variableForKey:(NSString *)key NS_SWIFT_NAME(variable(forKey:));
@end

NS_ASSUME_NONNULL_END
